#pragma once

#include "View.h"
#include "Graphic.h"
#include "Text.h"
#include "Picture.h"
#include <string>
#include "Player.h"

class StartView : public View {
public:
	StartView();
	~StartView();
	void update();

	void newGameState();
	bool newGameClicked(int _x, int _y);
	bool loadGameClicked(int _x, int _y);

	void playerCountState();
	int playerCountClicked(int _x, int _y);

	void colorChoiceState();
	std::string colorClicked(int _x, int _y);

	void nameInputState();
	void nameAppend(std::string character);
	void nameBackspace();
	std::string getName();
	bool continueButtonclicked(int _x, int _y);
	
	void regionChoiceState(int _regionCount);
	int regionClicked(int _x, int _y);
	bool* regionConfirmClicked(int _x, int _y);

	void strategyChoiceState();
	int strategyButtonClicked(int _x, int _y);


private:
	Picture* newGame;
	Picture* loadGame;
	Picture* continueButton;
	Picture* colors[6];
	bool chosenColor[6];
	const std::string colorNames[6] = {"Red", "Blue", "Green", "Purple", "Orange", "Black"};
	Text* playerCount[5];

	Picture* mapPreview;
	int regionCount;
	Picture* regions[6];
	Picture* selectedRegions[6];
	const std::string regionColors[6] = { "Brown", "Green", "Red", "Blue", "Purple", "Yellow" };
	const int regionMapping[6] = { 4, 5, 0, 3, 2, 1 };

	Picture* strategyButtons[3];

	Text* nameInput;
	Text* instructionText;
};