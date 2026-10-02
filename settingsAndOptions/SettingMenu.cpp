#include "SettingMenu.h"


listForSettings speedList;
listForSettings fontList;
listForSettings wordsLengthList;
listForSettings optionList;
listForSettings sizeList;
listForSettings frequencyList;

void listForSettings::highlight() {
    for (auto i = 0; i < static_cast<int>(things.size()); i++) {
        things[i]->setFillColor(i == selectedIndex ? sf::Color::Green : sf::Color::Magenta);
    }
}

void listForSettings::moveUp() {
    selectedIndex = (selectedIndex - 1 + things.size()) % things.size();
}

void listForSettings::moveDown() {
    selectedIndex = (selectedIndex + 1) % things.size();
}

void listForSettings::moveByMouse(sf::Vector2f mousePosition) {
    for (auto i = 0; i < static_cast<int>(things.size()); i++) {
        if (things[i]->getGlobalBounds().contains(mousePosition)) {
            selectedIndex = i;
        }
    }
}


sf::Text wordLength(arcadeBoxes, "LENGTH", 60);
sf::Text fontText(arcadeBoxes, "FONT", 60);
sf::Text speedText(arcadeBoxes, "SPEED", 60);
sf::Text sizeText(arcadeBoxes, "SIZE", 60);
sf::Text frequencyText(arcadeBoxes, "FREQUENCY", 60);
sf::Text livesText(arcadeBoxes, "LIVES: " + std::to_string(lives), 60);
sf::Text exitText6(machineFont, "EXIT", 40);

sf::Text slothText(machineFont, "sloth", 30);
sf::Text monkeyText(machineFont, "monkey", 30);
sf::Text gibbonText(machineFont, "gibbon", 30);

sf::Text veryShortWordsText(machineFont, "ant", 30);
sf::Text shortWordsText(machineFont, "earthworm", 30);
sf::Text longWordsText(machineFont, "lizard", 30);
sf::Text veryLongWordsText(machineFont, "snake", 30);

sf::Text delugeText(machineFont, "deluge", 30);
sf::Text stormText(machineFont, "storm", 30);
sf::Text showerText(machineFont, "shower", 30);
sf::Text dropText(machineFont, "drop", 30);

sf::Text miniLettersText(machineFont, "seed", 20);
sf::Text midiLettersText(machineFont, "seedling", 30);
sf::Text maxiLettersText(machineFont, "tree", 40);

sf::Text futureFontText(futureFont, "FutureFont", 30);
sf::Text handwrittenFontText(handwrittenFont, "Handwritten", 30);
sf::Text cartoonsFontText(cartoonFont, "Cartoon", 30);
sf::Text vintageFontText(vintageFont, "Vintage", 30);
sf::Text machineFontText(machineFont, "Machine", 30);

sf::Texture plusButtonTexture("../pics/plus.png");
sf::Sprite plusButton(plusButtonTexture);

sf::Texture minusButtonTexture("../pics/minus.png");
sf::Sprite minusButton(minusButtonTexture);
int lives = 3;


void initSettingMenu() {
    currentScreen = ScreenState::SettingMenu;


    optionList.things = {&wordLength, &fontText, &speedText, &frequencyText, &sizeText, &playText};

    speedList.things = {&slothText, &monkeyText, &gibbonText};
    speedList.selectedIndex = static_cast<int>(selectedSpeed);

    fontList.things = {
        &futureFontText,&machineFontText, &vintageFontText, &cartoonsFontText, &handwrittenFontText
    };
    fontList.selectedIndex = static_cast<int>(selectedFont);

    wordsLengthList.things = {&veryShortWordsText, &shortWordsText, &longWordsText, &veryLongWordsText};
    wordsLengthList.selectedIndex = static_cast<int>(selectedWordLength);

    frequencyList.things = {&delugeText, &stormText, &showerText, &dropText};
    frequencyList.selectedIndex = static_cast<int>(selectedFrequency);

    sizeList.things = {&miniLettersText, &midiLettersText, &maxiLettersText};
    sizeList.selectedIndex = static_cast<int>(selectedSize);

    float xpos1 = 100;
    playText = sf::Text(arcadeBoxes, "PLAY", 80);
    playText.setPosition({xpos1, 80});
    playText.setFillColor(sf::Color::Magenta);

    wordLength.setPosition({xpos1, 180});
    wordLength.setFillColor(sf::Color::Magenta);

    fontText.setPosition({xpos1, 240});
    fontText.setFillColor(sf::Color::Magenta);

    speedText.setPosition({xpos1, 300});
    speedText.setFillColor(sf::Color::Magenta);

    frequencyText.setPosition({xpos1, 360});
    frequencyText.setFillColor(sf::Color::Magenta);

    sizeText.setPosition({xpos1, 420});
    sizeText.setFillColor(sf::Color::Magenta);

    livesText.setPosition({xpos1, 480});
    livesText.setFillColor(sf::Color::Magenta);

    plusButton.setScale({0.045f, 0.045f});
    plusButton.setPosition({xpos1 - 40, 495});
    minusButton.setScale({0.045f, 0.045f});
    minusButton.setPosition({xpos1 - 80, 495});

    exitText6.setPosition({10, 550});
    exitText6.setFillColor(sf::Color::Magenta);

    int textSize = 40;
    float xpos = 500;
    float ypos = 200;

    slothText.setPosition({xpos, ypos});
    slothText.setFillColor(sf::Color::Magenta);

    monkeyText.setPosition({xpos, ypos + 50});
    monkeyText.setFillColor(sf::Color::Magenta);

    gibbonText.setPosition({xpos, ypos + 100});
    gibbonText.setFillColor(sf::Color::Magenta);

    futureFontText.setPosition({xpos, ypos});
    futureFontText.setFillColor(sf::Color::Magenta);

    machineFontText.setPosition({xpos, ypos + 50});
    machineFontText.setFillColor(sf::Color::Magenta);

    vintageFontText.setPosition({xpos, ypos + 100});
    vintageFontText.setFillColor(sf::Color::Magenta);

    cartoonsFontText.setPosition({xpos, ypos + 150});
    cartoonsFontText.setFillColor(sf::Color::Magenta);

    handwrittenFontText.setPosition({xpos, ypos + 200});
    handwrittenFontText.setFillColor(sf::Color::Magenta);

    veryShortWordsText.setPosition({xpos, ypos});
    veryShortWordsText.setFillColor(sf::Color::Magenta);

    shortWordsText.setPosition({xpos, ypos + 50});
    shortWordsText.setFillColor(sf::Color::Magenta);

    longWordsText.setPosition({xpos, ypos + 100});
    longWordsText.setFillColor(sf::Color::Magenta);

    veryLongWordsText.setPosition({xpos, ypos + 150});
    veryLongWordsText.setFillColor(sf::Color::Magenta);

    delugeText.setPosition({xpos, ypos});
    delugeText.setFillColor(sf::Color::Magenta);

    stormText.setPosition({xpos, ypos + 50});
    stormText.setFillColor(sf::Color::Magenta);

    showerText.setPosition({xpos, ypos + 100});
    showerText.setFillColor(sf::Color::Magenta);

    dropText.setPosition({xpos, ypos + 150});
    dropText.setFillColor(sf::Color::Magenta);

    miniLettersText.setPosition({xpos, ypos});
    miniLettersText.setFillColor(sf::Color::Magenta);

    midiLettersText.setPosition({xpos, ypos + 50});
    midiLettersText.setFillColor(sf::Color::Magenta);

    maxiLettersText.setPosition({xpos, ypos + 100});
    maxiLettersText.setFillColor(sf::Color::Magenta);
}


void updateSettingMenu(sf::Vector2f mousePosition) {
    optionList.moveByMouse(mousePosition);
    optionList.highlight();
    if (speedList.visible) {
        speedList.moveByMouse(mousePosition);
        speedList.highlight();
    }
    if (fontList.visible) {
        fontList.moveByMouse(mousePosition);
        fontList.highlight();
    }
    if (wordsLengthList.visible) {
        wordsLengthList.moveByMouse(mousePosition);
        wordsLengthList.highlight();
    }
    if (sizeList.visible) {
        sizeList.moveByMouse(mousePosition);
        sizeList.highlight();
    }
    if (frequencyList.visible) {
        frequencyList.moveByMouse(mousePosition);
        frequencyList.highlight();
    }
}
