#include "OptionMenu.h"
listForOptions options;
void listForOptions::highlight() {
    for (auto i = 0; i < static_cast<int>(things.size()); i++) {
        things[i]->setFillColor(i == selectedIndex ? sf::Color::Green : sf::Color::Magenta);
    }
}

void listForOptions::moveUp() {
    selectedIndex = (selectedIndex - 1 + things.size()) % things.size();
}

void listForOptions::moveDown() {
    selectedIndex = (selectedIndex + 1) % things.size();
}

void listForOptions::moveByMouse(sf::Vector2f mousePosition) {
    for (auto i = 0; i < static_cast<int>(things.size()); i++) {
        if (things[i]->getGlobalBounds().contains(mousePosition)) {
            selectedIndex = i;
        }
    }
}

sf::Text settingText(arcadeBoxes, "", 40);
sf::Text exitTextInOption(arcadeBoxes, "", 40);
sf::Text playText(arcadeBoxes, "", 40);
sf::Text creditsText(arcadeBoxes, "", 40);
sf::Text scoreText(arcadeBoxes, "", 40);

void initOptionMenu() {
    currentScreen = ScreenState::OptionMenu;

    options.things = {&playText, &settingText, &creditsText,&scoreText, &exitTextInOption };

    float xpos = 100;
    float ypos = 180;
    playText = sf::Text(arcadeBoxes, "PLAY", 80);
    playText.setPosition({xpos, 80});
    playText.setFillColor(sf::Color::Magenta);

    settingText = sf::Text(arcadeBoxes, "SETTINGS", 60);
    settingText.setPosition({xpos, ypos});
    settingText.setFillColor(sf::Color::Magenta);

    creditsText = sf::Text(arcadeBoxes, "CREDITS", 60);
    creditsText.setPosition({xpos, ypos+60});
    creditsText.setFillColor(sf::Color::Magenta);

    scoreText = sf::Text(arcadeBoxes, "SCORE TABLE", 60);
    scoreText.setPosition({xpos, ypos+120});
    scoreText.setFillColor(sf::Color::Magenta);

    exitTextInOption = sf::Text(arcadeBoxes, "EXIT", 60);
    exitTextInOption.setPosition({xpos, ypos+180});
    exitTextInOption.setFillColor(sf::Color::Magenta);
}

void updateOptionMenu(sf::Vector2f mousePosition) {
    options.moveByMouse(mousePosition);
    options.highlight();
}
