#pragma once
#include "std.h"
#include "../../FMod/inc/fmod.hpp"
#include "../../FMod/inc/fmod_errors.h"
#pragma comment(lib, "../../FMod/lib/x64/fmod_vc.lib")

class Sound
{
	FMOD::System* m_pSystem = nullptr;
	FMOD::Sound* m_pSound = nullptr;
	FMOD::Channel* m_pChannel = nullptr;
	float  m_fVolume = 0.5f;
public:
	TCHAR  m_szBuffer[256];
public:
	bool Load(FMOD::System* pSystem, std::string loadfilename);
	void Play(bool bLoop = true);
	void PlayEffect();
	void Stop();
	void VolumeUp(float fValue);
	void VolumeDown(float fValue);
	void Paused();
	bool Frame();
	bool Release();
};
class SoundMgr
{
	FMOD::System* m_pSystem = nullptr;
public:
	static SoundMgr& Get()
	{
		static SoundMgr mgr;
		return mgr;
	}
	std::map<std::wstring, std::shared_ptr<Sound>> m_list;
public:
	Sound* Load(std::wstring loadfilename);
	bool   Init();
	bool   Frame();
	bool   Release();
private:
	SoundMgr();
public:
	~SoundMgr();
};


