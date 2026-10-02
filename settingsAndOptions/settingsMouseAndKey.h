#pragma once
#include "SFML/Window.hpp"
#include "GlobalStates.h"
#include "OptionMenu.h"
#include "SettingMenu.h"
#include "../templates.h"
#include "../game/Game.h"
#include "../mouseAndKey.h"

extern void mouseMovedInSettings(const sf::Vector2f &mousePosition);
extern void mouseClickedInSettings(const sf::Vector2f &mousePosition);
extern void keyClickedInSettings(sf::Event::KeyPressed const &e);