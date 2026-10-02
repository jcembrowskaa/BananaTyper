#pragma once

#include "CreditsMenu.h"

#include "../game/Game.h"
#include "GameOver.h"
#include "StartMenu.h"
#include "../fileReader.h"
#include "../settingsAndOptions/OptionMenu.h"
#include "../settingsAndOptions/SettingMenu.h"
#include "../templates.h"
#include "BestScoreScreen.h"
#include "gameOverMouseAndKey.h"

extern void keyClickedInOther(const sf::Event::KeyPressed &e);
extern void mouseClickedInOther(const sf::Vector2f &mousePosition);