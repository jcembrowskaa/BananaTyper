#pragma once
#include "../settingsAndOptions/GlobalStates.h"
#include "../settingsAndOptions/OptionMenu.h"
#include "../settingsAndOptions/SettingMenu.h"
#include "../templates.h"
#include "../game/Game.h"
#include "BestScoreScreen.h"
#include "GameOver.h"

extern void keyClickedInGameOver(const sf::Event::KeyPressed &e);

extern void mouseClickedInGameOver(const sf::Vector2f &mousePosition);

extern bool hasNicknameBeenEntered;
