#pragma once
#include <string>
#include <iostream>
#include "FactoryCard.h"

using namespace std;
/**
* The classes that implement a concrete strategy should inherit this. * The Calculator class uses this to use a concrete strategy. */
class Strategy {
public: /**
* Method whose implementation varies depending on the strategy adopted. */
	virtual string execute(int phaseNumber , vector<FactoryCard*> _currentBuyabaleCards, vector<FactoryCard*> _playerFactories) = 0;
	string comment;
};