#include "optionMouseAndKey.h"

void keyClickedInOptions(sf::Event::KeyPressed const &e) {
    if (currentScreen == ScreenState::OptionMenu) {
        if (e.code == sf::Keyboard::Key::Escape) {
            initStartMenu();
        }
        if (e.code == sf::Keyboard::Key::Up) {
            options.moveUp();
        }
        if (e.code == sf::Keyboard::Key::Down) {
            options.moveDown();
        }
        if (e.code == sf::Keyboard::Key::Enter) {
            switch (options.selectedIndex) {
                case 0: initGame();
                    break;
                case 1: initSettingMenu();
                    break;
                case 2: initCreditsMenu();
                    break;
                case 3: initBestScoreScreen();
                    loadScores();
                    break;
                case 4: initStartMenu();
                    break;
            }
        }
    }
}

void mouseClickedInOptions(const sf::Vector2f &mousePosition) {
    if (currentScreen == ScreenState::OptionMenu) {
        if (playText.getGlobalBounds().contains(mousePosition)) {
            points = 0;
            mistakes = 0;
            initGame();
        } else if (settingText.getGlobalBounds().contains(mousePosition)) {
            initSettingMenu();
        } else if (creditsText.getGlobalBounds().contains(mousePosition)) {
            initCreditsMenu();
        } else if (scoreText.getGlobalBounds().contains(mousePosition)) {
            initBestScoreScreen();
            loadScores();
        } else if (exitTextInOption.getGlobalBounds().contains(mousePosition)) {
            initStartMenu();
        }
    }
}

void mouseMovedInOptions(const sf::Vector2f &mousePosition) {
    if (currentScreen == ScreenState::OptionMenu) {
        updateOptionMenu(mousePosition);
    }
}
