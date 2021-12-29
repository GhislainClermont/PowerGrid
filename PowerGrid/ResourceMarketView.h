#pragma once

#include "View.h"
#include "Graphic.h"
#include "Text.h"
#include "Picture.h"
#include "ResourceMarket.h"

class ResourceMarketView : public View {
public:
	ResourceMarketView();
	~ResourceMarketView();
	void update();
	void findAndAttach();
private:
	Text* costs[4];
	Text* remainings[4];
	Text* stock[4];
	Picture* resources[4][3];

	ResourceMarket* market;
};