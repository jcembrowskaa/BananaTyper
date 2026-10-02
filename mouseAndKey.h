#pragma once
#include "SFML/Window.hpp"
#include "otherScreens/CreditsMenu.h"

#include "game/Game.h"
#include "otherScreens/GameOver.h"
#include "otherScreens/StartMenu.h"
#include "fileReader.h"
#include "settingsAndOptions/OptionMenu.h"
#include "settingsAndOptions/SettingMenu.h"
#include "templates.h"
#include "otherScreens/BestScoreScreen.h"
#include "game/gameMouseAndKey.h"
#include "otherScreens/gameOverMouseAndKey.h"
#include "settingsAndOptions/settingsMouseAndKey.h"
#include "settingsAndOptions/optionMouseAndKey.h"
#include "otherScreens/otherMouseAndKey.h"


class myInputs {
public:
    virtual void keyClicked(const sf::Event::KeyPressed &e);

    virtual void mouseClicked(const sf::Vector2f &mousePosition);

    virtual void mouseMoved(const sf::Vector2f &mousePosition);
};
