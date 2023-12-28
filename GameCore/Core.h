#pragma once
#include "Device.h"
#include "TextureMgr.h"
#include "UIobj.h"

class Core : public Device
{
public:
	PlaneShape m_DefaultPlane;

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

