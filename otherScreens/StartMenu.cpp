#include "StartMenu.h"



sf::Texture backgroundTexture("../pics/background.png");
sf::Sprite backgroundSprite(backgroundTexture);
sf::RectangleShape backgroundRectangle;
sf::Text titleText(arcadeBoxes, "BANANA TYPER", 80);
sf::Text underTitleText(machineFont, "Press 'space' to start", 30);
void initStartMenu() {

    currentScreen = ScreenState::StartMenu;

    titleText.setPosition({90, 220});
    titleText.setFillColor(sf::Color::Magenta);

    underTitleText.setPosition({190, 300});
    underTitleText.setFillColor(sf::Color::Magenta);

    float scaleX = 800.f / backgroundTexture.getSize().x;
    float scaleY = 600.f / backgroundTexture.getSize().y;

    backgroundSprite.setScale({scaleX, scaleY});

    backgroundRectangle.setPosition({80, 220});
    backgroundRectangle.setSize({600,150});
    backgroundRectangle.setFillColor(sf::Color(255,240,0,150));




}
