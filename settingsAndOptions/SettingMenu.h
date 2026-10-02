#pragma once

#include <SFML/Graphics.hpp>
#include "../Fonts.h"
#include "GlobalStates.h"
#include "../myEnums.h"
#include "OptionMenu.h"

void initSettingMenu();
void updateSettingMenu(sf::Vector2f mousePos = {-1, -1});
struct listForSettings {
    std::vector<sf::Text *> things;
    int selectedIndex;
    bool visible;
    void highlight();
    void moveUp();
    void moveDown();
    void moveByMouse(sf::Vector2f mousePosition);
};


extern listForSettings speedList;
extern listForSettings fontList;
extern listForSettings wordsLengthList;
extern listForSettings optionList;
extern listForSettings frequencyList;
extern listForSettings sizeList;
extern listForSettings livesList;

extern sf::Text wordLength;
extern sf::Text fontText;
extern sf::Text speedText;
extern sf::Text frequencyText;
extern sf::Text sizeText;
extern sf::Text livesText;

extern sf::Text slothText;
extern sf::Text monkeyText;
extern sf::Text gibbonText;

extern sf::Text machineFontText;
extern sf::Text vintageFontText;
extern sf::Text cartoonsFontText;
extern sf::Text handwrittenFontText;
extern sf::Text futureFontText;

extern sf::Text veryShortWordsText;
extern sf::Text shortWordsText;
extern sf::Text longWordsText;
extern sf::Text veryLongWordsText;

extern sf::Text delugeText;
extern sf::Text stormText;
extern sf::Text showerText;
extern sf::Text dropText;

extern sf::Text miniLettersText;
extern sf::Text midiLettersText;
extern sf::Text maxiLettersText;

extern sf::Texture plusButtonTexture;
extern sf::Texture minusButtonTexture;
extern sf::Sprite plusButton;
extern sf::Sprite minusButton;
extern int lives;
extern int maxLength;
extern sf::Text exitText6;

