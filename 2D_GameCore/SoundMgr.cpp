#include "SoundMgr.h"
#include <tchar.h>
bool	Sound::Frame()
{
	if (m_pSound == nullptr || m_pChannel == nullptr) return true;

	unsigned int ms = 0;
	unsigned int size = 0;
	m_pSound->getLength(&size, FMOD_TIMEUNIT_MS);
	m_pChannel->getPosition(&ms, FMOD_TIMEUNIT_MS);

	_stprintf_s(m_szBuffer,
		_T("전체시간[%02d:%02d:%02d]:경과시간[%02d:%02d:%02d]"),
		size / 1000 / 60,
		size / 1000 % 60,
		size / 10 % 60,
		ms / 1000 / 60,
		ms / 1000 % 60,
		ms / 10 % 60);

	return true;
}
void Sound::PlayEffect()
{
	FMOD_RESULT hr = m_pSystem->playSound(m_pSound, nullptr, false, &m_pChannel);
	if (hr != FMOD_OK)
	{
		return;
	}
}
void Sound::Play(bool bLoop)
{
	bool bPlay = false;
	m_pChannel->isPlaying(&bPlay);
	if (bPlay) return;
	FMOD_RESULT hr = m_pSystem->playSound(m_pSound, nullptr, false, &m_pChannel);
	if (hr != FMOD_OK)
	{
		return;
	}
	if (bLoop)
	{
		m_pChannel->setMode(FMOD_LOOP_NORMAL);
	}
	else
	{
		m_pChannel->setMode(FMOD_LOOP_OFF);
	}
	m_pChannel->setVolume(m_fVolume);
}

void Sound::Stop()
{
	if (m_pChannel == nullptr) return;
	//_ASSERT(m_pChannel);
	m_pChannel->stop();
	m_pChannel = nullptr;
}
void Sound::VolumeUp(float fValue)
{
	if (m_pChannel == nullptr) return;
	float fCurrentVolume;
	m_pChannel->getVolume(&fCurrentVolume);
	m_fVolume = fCurrentVolume + fValue;
	m_fVolume = max(0.0f, m_fVolume);
	m_fVolume = min(1.0f, m_fVolume);
	m_pChannel->setVolume(m_fVolume);
}
void Sound::VolumeDown(float fValue)
{
	if (m_pChannel == nullptr) return;
	float fCurrentVolume;
	m_pChannel->getVolume(&fCurrentVolume);
	m_fVolume = fCurrentVolume - fValue;
	m_fVolume = max(0.0f, m_fVolume);
	m_fVolume = min(1.0f, m_fVolume);
	m_pChannel->setVolume(m_fVolume);
}
void Sound::Paused()
{
	if (m_pChannel == nullptr) return;
	//_ASSERT(m_pChannel);
	bool bPlay = false;
	m_pChannel->isPlaying(&bPlay);
	if (bPlay)
	{
		bool paused;
		m_pChannel->getPaused(&paused);
		m_pChannel->setPaused(!paused);
	}
}

bool Sound::Release()
{
	if (m_pSound)
	{
		m_pSound->release();
		m_pSound = nullptr;
	}
	return true;
}
bool Sound::Load(FMOD::System* pSystem, std::string loadfilename)
{
	m_pSystem = pSystem;
	FMOD_RESULT hr = m_pSystem->createSound(loadfilename.c_str(),
		FMOD_DEFAULT, 0, &m_pSound);
	if (hr != FMOD_OK)
	{
		return false;
	}
	return true;
}

bool   SoundMgr::Init()
{
	FMOD_RESULT hr = FMOD::System_Create(&m_pSystem);
	if (hr != FMOD_OK)
	{
		return false;
	}
	hr = m_pSystem->init(32, FMOD_INIT_NORMAL, 0);
	if (hr != FMOD_OK)
	{
		return false;
	}
	return true;
}

Sound* SoundMgr::Load(std::wstring loadfilename)
{
	auto iter = m_list.find(loadfilename);
	if (iter != m_list.end())
	{
		return iter->second.get();
	}
	std::shared_ptr<Sound>  pData = std::make_shared<Sound>();
	if (pData->Load(m_pSystem, to_wm(loadfilename)))
	{
		m_list.insert(std::make_pair(loadfilename, pData));
		return pData.get();
	}
	return nullptr;
}
bool SoundMgr::Frame()
{
	m_pSystem->update();
	return true;
}
bool   SoundMgr::Release()
{
	for (auto data : m_list)
	{
		data.second->Release();
	}
	m_list.clear();

	if (m_pSystem)
	{
		m_pSystem->close();
		m_pSystem->release();
	}
	m_pSystem = nullptr;
	return true;
}
SoundMgr::SoundMgr() {}
SoundMgr::~SoundMgr() {
	Release();
};