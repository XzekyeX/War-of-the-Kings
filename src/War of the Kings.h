#pragma once
#include "Window.h"
/**
*
* @author Mikko Tekoniemi
*
*/
class WOTK : public Window {
public:
	WOTK();
public:
	void init() override;
	void update() override;
	void render() override;
};
