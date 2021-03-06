# PowerGrid
 
This program was written by:
- Ghislain Clermont (40057664)
- Maryam Eskandari (40065716)

This program uses the Allegro 5 Library.
This program was coded on Microsoft Visual Studio 2017.

The pictures of Factory Cards were edited using photos from https://boardgamegeek.com/image/173153/power-grid as their source image.
All other graphics were made by ourselves using Photoshop CS6.

==============================

For testing:

In the Driver, set the testPhase variable (line 30, start of the setupTestModel function) 
to the number of the Phase you wish to test. Setting it to -1 will launch the program normally, 
while going directly to a Phase will initialize a game with 2 players.

As of now, starting from a new game is fully functionnal, and there is no need to skip directly into a phase.

Note: As the Design Patterns are scattered throughout the game, there is no Driver to "demonstrate" each part individually. See the section below on details of each Design Pattern.

==============================

Design Patterns

--Observers (Part 1)--
The Observer design pattern has been implemented on most View and Model classes. Views have either the functions "set_player()" or "findAndAttach()": The first one is to attach a View directly to a player given by the Controller, the second one is to look at the corresponding object inside the Model (it does nothing if the Model has not been instanciated yet). The Model also has a special "attachToModel()" function, as the Model object itself isn't accessible.

List of View->Subject attachments
-FactoryMarketView -> FactoryMarket
-MinimapView -> Mymap
-Phase2View -> Model (also attaches itself to the Current Player, ideally it would need to be split into two Views)
-Phase3View -> Player
-Phase4View -> Mymap
-Phase5View -> Model
-PlayerFactoriesView -> Player
-PlayerInfoView -> Player
-PlayerOrderView -> Model
-ResourceMarketView -> ResourceMarket
-SideView -> Model


--Observers (Part 2)--
As the UI was already designed to use all of the screen to display useful information to the current views, we opted for the ugly solution of increasing the window size to 1800x700. The added 600x700 block on the right is managed using SideController and SideView, and also uses FactoryMarketView, MinimapView, PlayerInfoView, PlayerOrderView and ResourceMarketView. The user can click any of the button to display the desired View, and all of these will update automatically during the game.


--Strategy--
Strategies were implemented with the classes Strategy, Aggressive, Moderate and Environmentalist, then incorporated into the Player class. In Phase 2, they are implemented into the UI itself, and called by Phase2View's update function. However, as we lacked time, Phase 3 and Phase 4 print the Strategy onto the console instead.


--Factory--
The free Design Pattern chosen was the Factory design pattern. It is used to construct Cards (Step3Card and FactoryCard). The class that acts as the Factory is "CardFactory" (don't mix up FactoryCard and CardFactory, we didn't expect that issue back in Assignment 1). Deck, Player and FactoryMarket all make use of the Card Factory.


--Usage of each Design Pattern per phase--
-Side view: Observer (part 2)
-Game initialization: Strategy, Factory
-Phase 1: Observer (part 1)
-Phase 2: Observer (part 1), Strategy
-Phase 3: Observer (part 1), Strategy
-Phase 4: Observer (part 1), Strategy
-Phase 5: Observer (part 1)

==============================

Known Issues / Incomplete Features

-Load Game: Game saving is not fully functionnal (Map does not save the cities), and as such the Load Button is not implemented.

-Region Select: Some of the areas are incorrectly returned as non-adjacent.

-Name input: The Name input was initially intended to be implemented using Allegro Keyboard events. As we lacked time to figure out the way to convert the value passed by Allegro into a character, input is done through the Console instead. When asked for the player name, press Continue, then type the player's name in the console.

-Phase 4: The phase's functionnality was not completed in time. The bare minimum for testing (placing cities on the map) has been set. The map picture could not be edited in time to make text clear.

-libpng warning in console: This message pops up in the Console whenever a PNG file is loaded. This is caused by the PNG files themselves, rather than the code, and does not cause any bug on the program itself.

==============================

Troubleshooting:

If unable to launch, verify the following:

1. Project -> Properties -> Configuration Properties -> General.
Windows SDK Version must be a version installed on the computer.
Our versions at home and at the labs are not the same, and as such, it is necessary to select the one available on the current computer.

2. Project -> Properties -> Allegro 5 -> Add-ons.
Verify that Image, Truetype Font, Font Addons are all activated.
It has been noticed that they were deactivated upon loading the project on the university labs.

If the Allegro 5 section is not available, it may be necessary to reinstall the library. To do so:
Project -> Manage NuGet Packages -> Browse -> Search "Allegro".
Select the package named "Allegro" and install.
Then activate the add-ons as described above.

3. Project -> Properties -> C/C++ -> Preprocessor.
Verify that _CRT_SECURE_NO_WARNINGS is in Preprocessor Definitions.

==============================

Architecture:

The program follows the MVC model in the following methods:

-Driver-
The Driver initializes the Allegro library, all Controllers used in the project, and then enters the Game Loop. Inside of the loop, the Driver goes through all registered Views to print them on the screen, receives Mouse and Keyboard events, and passes these to the Active Controller. It also checks if the Active Controller has declared its phase over so that it can unload it and move on to the next Controller.

-Controller-
The program is separated into 6 Controllers: StartController which takes care of creating a new game or loading the last game, and one Controller for each of the 5 phases of Power Grid. These Controllers initialize the Views needed for their functionning, receive Mouse and Keyboard events from the Driver, and processes these. Every Controller inherit from the Controller class.

-View-
Views are made to be a group of Graphics (Text and Picture). Every View is registered to a static list upon creation. One children View class is created for specific purposes, such as showing a phase-specific UI, or displaying the state of a Model. Their function update() is made to automatically fetch data from the Model, while custom functions can be created to give information not available in the Model (such as phase-specific variables). Every View inherit from the View class.

-Model-
The Model is made to keep all data available from everywhere. It keeps an instance of all game classes from Assignment 1 and takes care of mass saving everything with a single function call. It is initialized in StartController.
