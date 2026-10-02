#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "../Fonts.h"

extern std::map<std::string, float> playersScore;
extern void initBestScoreScreen();
extern std::map<std::string, float> loadScores();
extern void saveBestScores();
extern sf::Text bestPlayersScores;
extern sf::Text nicknameInput;
extern std::string nickName;
extern std::vector<sf::Text> bestScoreTexts;

extern sf::RectangleShape retangle;
extern sf::Text exitTextInBestScores;

extern void centerText();
