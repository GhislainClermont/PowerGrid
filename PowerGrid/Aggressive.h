#pragma once
#include "Strategy.h"

/**
* A concrete Strategy that implements a addition operation */
class Aggressive : public Strategy {
public: 
	string execute(int phaseNumber, vector<FactoryCard*> _currentBuyabaleCards, vector<FactoryCard*> _playerFactories);
};