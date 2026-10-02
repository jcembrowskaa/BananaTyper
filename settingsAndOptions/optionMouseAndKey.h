#pragma once
#include "GlobalStates.h"
#include "OptionMenu.h"
#include "SettingMenu.h"
#include "../templates.h"
#include "../game/Game.h"
#include "../otherScreens/BestScoreScreen.h"
#include "../otherScreens/StartMenu.h"
#include "../otherScreens/CreditsMenu.h"


extern void keyClickedInOptions(const sf::Event::KeyPressed &e);
extern void mouseClickedInOptions(const sf::Vector2f &mousePosition);
extern void mouseMovedInOptions(const sf::Vector2f &mousePosition);