#pragma once

#include "Graphic.h"
#include <string>
#include <vector>
#include "Observer.h"

class View : public Observer {
public:
	View();
	View(std::string _name);
	View(std::string _name, int _x, int _y);
	virtual ~View();
	void draw();
	void move(int _x, int _y);
	void set_pos(int _x, int _y);
	virtual void update()=0;
	bool wasClicked(int _x, int _y);
	void hide();
	void show();
	bool isHidden() const;
	void set_layer(int _layer);
	int get_layer() const;
	std::vector<Graphic*> get_graphics();


	static View* get_view(std::string name);
	static void add_view(View* view);
	static bool remove_view(std::string name);
	static void drawAll();
	static void deleteAll();

protected:
	int x;
	int y;
	int layer;
	bool hidden;
	std::string name;
	std::vector<Graphic*> graphics;

	void add_graphic(Graphic* graphic);
	void remove_graphic(std::string _name);

private:
	static std::vector<View*> views;

};

