#include "../templates.h"
#include "settingsMouseAndKey.h"


void hideAllMenu(listForSettings *active) {
    auto lists = std::vector<listForSettings *>{&fontList, &speedList, &wordsLengthList, &sizeList, &frequencyList};
    for (auto &list: lists) {
        if (list == active) {
            list->visible = true;
        } else {
            list->visible = false;
        }
    }
}
void mouseMovedInSettings(const sf::Vector2f &mousePosition) {
    if (currentScreen == ScreenState::SettingMenu) {
        updateSettingMenu(mousePosition);
    }
    }

    void mouseClickedInSettings(const sf::Vector2f &mousePosition) {
    if (currentScreen == ScreenState::SettingMenu) {
        if (wordLength.getGlobalBounds().contains(mousePosition)) {
            settingOption = Settings::TimeMode;
            hideAllMenu(&wordsLengthList);
        }
        if (speedText.getGlobalBounds().contains(mousePosition)) {
            settingOption = Settings::Speed;
            hideAllMenu(&speedList);
        }
        if (fontText.getGlobalBounds().contains(mousePosition)) {
            settingOption = Settings::Font;
            hideAllMenu(&fontList);
        }
        if (frequencyText.getGlobalBounds().contains(mousePosition)) {
            settingOption = Settings::SignsType;
            hideAllMenu(&frequencyList);
        }
        if (sizeText.getGlobalBounds().contains(mousePosition)) {
            settingOption = Settings::Size;
            hideAllMenu(&sizeList);
        }
        if (exitText6.getGlobalBounds().contains(mousePosition)) {
            initOptionMenu();
        }

        if (plusButton.getGlobalBounds().contains(mousePosition)) {
            if (lives < 10) {
                lives++;
                livesText.setString("LIVES: " + std::to_string(lives));
            }
        }
        if (minusButton.getGlobalBounds().contains(mousePosition)) {
            if (lives > 1) {
                lives--;
                livesText.setString("LIVES: " + std::to_string(lives));
            }
        }

        if (playText.getGlobalBounds().contains(mousePosition)) {
            initGame();
        }
        if (speedList.visible) {
            listOptionClick<Speed>(speedList.things, mousePosition, selectedSpeed, speedList.visible);
        }
        if (fontList.visible) {
            listOptionClick<FontTypes>(fontList.things, mousePosition, selectedFont, fontList.visible);
        }
        if (sizeList.visible) {
            listOptionClick<size>(sizeList.things, mousePosition, selectedSize, sizeList.visible);
        }
        if (wordsLengthList.visible) {
            listOptionClick<wordsLength>(wordsLengthList.things, mousePosition, selectedWordLength,
                                         wordsLengthList.visible);
        }
        if (frequencyList.visible) {
            listOptionClick<Frequency>(frequencyList.things, mousePosition, selectedFrequency, frequencyList.visible);
        }
    }}

template<typename EnumType, typename ListType>
    void smallMenuInput(const sf::Event::KeyPressed &e, ListType &list, EnumType &selectedValue) {
    if (list.visible) {
        if (e.code == sf::Keyboard::Key::Up) {
            list.moveUp();
        }
        if (e.code == sf::Keyboard::Key::Down) {
            list.moveDown();
        }
        if (e.code == sf::Keyboard::Key::Enter) {
            selectedValue = static_cast<EnumType>(list.selectedIndex);
            list.visible = false;
        }
    }
}

auto keyClickedInSettings(sf::Event::KeyPressed const &e) -> void {
if (currentScreen == ScreenState::SettingMenu) {
    if (e.code == sf::Keyboard::Key::Escape) {
        initOptionMenu();
    }
    if (e.code == sf::Keyboard::Key::Enter) {
        if (settingOption == Settings::Speed) {
            speedList.visible = true;
        }
        if (settingOption == Settings::Font) {
            fontList.visible = true;
        }
        if (settingOption == Settings::Size) {
            sizeList.visible = true;
        }
        if (settingOption == Settings::TimeMode) {
            wordsLengthList.visible = true;
        }
        if (settingOption == Settings::SignsType) {
            frequencyList.visible = true;
        }
        if (settingOption == Settings::play) {
            initGame();
        }
    }
    if (e.code == sf::Keyboard::Key::Up) {
        optionList.moveUp();
    }
    if (e.code == sf::Keyboard::Key::Down) {
        optionList.moveDown();
    }


    smallMenuInput<Speed>(e, speedList, selectedSpeed);
    smallMenuInput<FontTypes>(e, fontList, selectedFont);
    smallMenuInput<wordsLength>(e, wordsLengthList, selectedWordLength);
    smallMenuInput<Frequency>(e, frequencyList, selectedFrequency);
    smallMenuInput<size>(e, sizeList, selectedSize);
}}