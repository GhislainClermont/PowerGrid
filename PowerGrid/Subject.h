#pragma once
#include "Observer.h"
#include <list>

class Observer;

class Subject {
public:
	virtual void attach(Observer* o);
	virtual void detach(Observer* o);
	virtual void notify();
	Subject();
	~Subject();
private:
	std::list<Observer*>* _observers;
};
