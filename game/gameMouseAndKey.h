#pragma once
#include "../settingsAndOptions/GlobalStates.h"
#include "../settingsAndOptions/OptionMenu.h"
#include "../settingsAndOptions/SettingMenu.h"
#include "../templates.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

extern void keyClickedInGame(const sf::Event::KeyPressed &e);

extern void mouseClickedInGame(const sf::Vector2f &mousePosition);
