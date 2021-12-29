#pragma once
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "Graphic.h"


class Text : public Graphic {
public:
	Text();
	Text(std::string _name, std::string _text);
	Text(std::string _name, std::string _text, int _x, int _y);
	Text(std::string _name, std::string _text, int _x, int _y, int _size);
	~Text();
	void draw();
	bool wasClicked(int _x, int _y);
	void set_text(std::string _text);
	std::string get_text() const;
	void append_text(std::string _text);
	void set_font(std::string file);
	void set_color(float _r, float _g, float _b);
	void set_size(int _size);


private:
	int r;
	int g;
	int b;
	std::string text;
	std::string font_file;
	int font_size;
	ALLEGRO_FONT * font;

};