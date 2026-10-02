#include "CreditsMenu.h"

sf::Text authorName(arcadeBoxes, "", 30);
sf::Text credits(arcadeBoxes, "", 30);
sf::Text exitTextInCredits(machineFont, "EXIT", 40);
sf::Text links(machineFont, "Fonts: https://tiny.pl/f72prx9f", 35);


void initCreditsMenu() {

    currentScreen = ScreenState::CreditsMenu;

    authorName = sf::Text(arcadeBoxes,
                          "Created by JC ", 60);
    authorName.setPosition({200, 180});
    authorName.setFillColor(sf::Color::Magenta);


    credits = sf::Text(machineFont, "Monkeys were not harmed in the making of this game... probably", 20);
    credits.setPosition({50, 500});
    credits.setFillColor(sf::Color::Magenta);

    links.setPosition({50, 260});
    links.setFillColor(sf::Color::Magenta);

    exitTextInCredits.setPosition({10,550});
    exitTextInCredits.setFillColor(sf::Color::Magenta);


}
