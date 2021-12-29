#pragma once

#include "Controller.h"
#include <vector>
#include <iostream>
#include "Model.h"
#include "Player.h"
#include "PlayerOrderView.h"
#include "ResourceMarketView.h"
#include "FactoryMarketView.h"
#include "Picture.h"
#include "SideView.h"
#include "MinimapView.h"
#include "PlayerInfoView.h"

class SideController : public Controller {
public:
	SideController();
	~SideController();
	void onClick(int _x, int _y);
	void onLoad();
	void onUnload();
	bool phasedEnded();
private:
	SideView* sideView;
	PlayerOrderView* playerOrderView;
	ResourceMarketView* resMarketView;
	FactoryMarketView* facMarketView;
	MinimapView* minimapView;
	PlayerInfoView* playerViews[6];

	int state;


};