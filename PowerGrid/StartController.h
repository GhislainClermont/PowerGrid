#pragma once

#include "Controller.h"
#include "mapLoader.h"
#include "Model.h"
#include <string>
#include "Player.h"
#include "StartView.h"
#include <iostream>

using namespace std;
class StartController : public Controller {
public:
	StartController();
	~StartController();
	void onClick(int _x, int _y);
	void onLoad();
	void onUnload();
	bool phasedEnded();
private:
	vector<Player> players;
	MapLoader* PowerGridLoader;
	StartView* startView;
	string _name;
	int counter = playercount;
	int _maxFactory;
	string _color;
	bool endOfPhase;
	int playercount;
	bool* selection;
	int state;


};