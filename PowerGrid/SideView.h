#pragma once

#include "View.h"
#include "Graphic.h"
#include "Text.h"
#include "Picture.h"
#include <string>
#include "Player.h"

class SideView : public View {
public:
	SideView();
	~SideView();
	void update();
	int buttonClicked(int _x, int _y);
	void findAndAttach();
private:
	Picture* playersButton;
	Picture* mapButton;
	Picture* playerOrderButton;
	Picture* resMarketButton;
	Picture* facMarketButton;
	Text* stepText;
};