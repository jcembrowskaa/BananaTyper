#pragma once
#include <SFML/Graphics.hpp>
#include "../Fonts.h"
#include "GlobalStates.h"
#include "../myEnums.h"


void initOptionMenu();
void updateOptionMenu(sf::Vector2f mousePos = {-1, -1});

struct listForOptions {
    std::vector<sf::Text *> things;
    int selectedIndex;
    void highlight();
    void moveUp();
    void moveDown();
    void moveByMouse(sf::Vector2f mousePosition);
};

extern listForOptions options;

extern sf::Text playText;
extern sf::Text settingText;
extern sf::Text creditsText;
extern sf::Text exitTextInOption;
extern sf::Text scoreText;
