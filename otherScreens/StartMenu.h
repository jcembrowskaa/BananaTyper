#pragma once
#include <SFML/Graphics.hpp>
#include "../Fonts.h"
#include "../settingsAndOptions/GlobalStates.h"
#include "../myEnums.h"


void initStartMenu();

extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;
extern sf::RectangleShape backgroundRectangle;

extern sf::Text titleText;
extern sf::Text underTitleText;