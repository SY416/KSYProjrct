#pragma once
#include "Device.h"
#include "TextureMgr.h"

class Core : public Device
{
public:
	TextureMgr m_DefaultTexture;

public:
	virtual bool Init() {
		return true;
	};
	virtual bool Render() {
		return true;
	};
	virtual bool Release() {
		return true;
	};
	virtual bool GameInit() override;
	virtual bool GameRender() override;
	virtual bool GameRelease() override;
};

