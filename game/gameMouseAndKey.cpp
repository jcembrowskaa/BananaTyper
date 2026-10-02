#include "gameMouseAndKey.h"

auto keyClickedInGame(sf::Event::KeyPressed const &e) -> void {
    if (currentScreen == ScreenState::Game) {
        if (e.code == sf::Keyboard::Key::Escape) {
            initOptionMenu();
        }
        if (e.code == sf::Keyboard::Key::D && isKeyPressed(sf::Keyboard::Key::LControl)) {
            discoMode = !discoMode;
        }
        if (e.code == sf::Keyboard::Key::P && isKeyPressed(sf::Keyboard::Key::LControl)) {
            highlightMode = !highlightMode;
        }
        if (e.code == sf::Keyboard::Key::O && isKeyPressed(sf::Keyboard::Key::LControl)) {
            isPaused = !isPaused;
        }
        if (e.code == sf::Keyboard::Key::Up) {
            scrollUpSettings(selectedSpeed);
            refreshSettingsInGame();
        }
        if (e.code == sf::Keyboard::Key::Down) {
            scrollDownSettings(selectedSpeed);
            refreshSettingsInGame();
        }
        if (e.code == sf::Keyboard::Key::Right) {
            scrollUpSettings(selectedFrequency);
            refreshSettingsInGame();
        }
        if (e.code == sf::Keyboard::Key::Left) {
            scrollDownSettings(selectedFrequency);
            refreshSettingsInGame();
        }
        if (e.code == sf::Keyboard::Key::Backspace && !wordInput.empty()) {
            wordInput.pop_back();
            inputText.setString(wordInput);
        } else if (e.code >= sf::Keyboard::Key::A && e.code <= sf::Keyboard::Key::Z) {
            if (!isKeyPressed(sf::Keyboard::Key::LControl) &&
                !isKeyPressed(sf::Keyboard::Key::RControl)) {
                char smallOrHuge = isKeyPressed(sf::Keyboard::Key::LShift) ?'A':'a';
                wordInput += static_cast<char>(smallOrHuge + static_cast<int>(e.code));
                typedCharactersCount++;
                inputText.setString(wordInput);


                auto texting = std::find_if(vecOfEnglishWords.begin(), vecOfEnglishWords.end(), [](const sf::Text &t) {
                    return t.getString() == wordInput;
                });

                if (texting != vecOfEnglishWords.end()) {
                    vecOfEnglishWords.erase(texting);
                    points += wordLenghtPoints * livesPoints * frequencyPoints * speedPoints;
                    typedWordsCount++;
                    pointsText.setString(std::format("Points: {:.2f}", points));
                    wordInput.clear();
                    inputText.setString(wordInput);
                }
            }
        }
    }
};

void mouseClickedInGame(const sf::Vector2f &mousePosition) {
    if (currentScreen == ScreenState::Game) {
        if (exitTextInGame.getGlobalBounds().contains(mousePosition)) {
            vecOfEnglishWords.clear();
            points = 0;
            mistakes = 0;
            wordInput.clear();
            typedWordsCount=0;
            typedCharactersCount=0;
            initOptionMenu();
        }
    }
};
