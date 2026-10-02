#pragma once
#include <SFML/Graphics.hpp>
#include "../Fonts.h"
#include "../settingsAndOptions/GlobalStates.h"
#include "../myEnums.h"
#include "../fileReader.h"
#include "../otherScreens/GameOver.h"
#include "../settingsAndOptions/SettingMenu.h"



extern sf::Clock gameClock;
extern sf::Clock spawnClock;
extern std::vector<sf::Text> vecOfEnglishWords;

extern float points;
extern int mistakes;

extern void initGame();
extern void updateGame();
extern void refreshSettingsInGame();

extern sf::Text inputText;
extern sf::Text pointsText;
extern sf::Text mistakesText;
extern std::string wordInput;

extern sf::Texture liveTexture;
extern sf::Texture notLiveTexture;
extern sf::Sprite liveSprite1;
extern sf::Sprite liveSprite2;
extern sf::Sprite liveSprite3;
extern sf::Sprite liveSprite4;
extern sf::Sprite liveSprite5;
extern sf::Sprite liveSprite6;
extern sf::Sprite liveSprite7;
extern sf::Sprite liveSprite8;
extern sf::Sprite liveSprite9;
extern sf::Sprite liveSprite10;

extern sf::Color color;

extern bool discoMode;
extern bool highlightMode;
extern std::vector<sf::Sprite> vecOfSprite;
extern int lives;
extern float speedPoints;
extern float frequencyPoints;
extern float livesPoints;
extern int wordLenghtPoints;

extern sf::Color randomColor;

extern int typedCharactersCount;
extern int typedWordsCount;
extern sf::Text cpmText;
extern sf::Text wpmText;
extern sf::Clock statsClock;

extern std::vector<std::string> loadedWords;

extern bool isPaused;

extern sf::Text exitTextInGame;

extern sf::Texture shortCutsTexture;
extern sf::Sprite shortCutsSprite;