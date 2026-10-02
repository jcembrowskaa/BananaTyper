#include "otherScreens/BestScoreScreen.h"
#include "otherScreens/CreditsMenu.h"
#include "mouseAndKey.h"
#include "game/Game.h"
#include "otherScreens/GameOver.h"
#include "otherScreens/StartMenu.h"
#include "settingsAndOptions/OptionMenu.h"
#include "settingsAndOptions/SettingMenu.h"

auto main() -> int {
    auto window = sf::RenderWindow(
        sf::VideoMode({800, 600}), "Banana Typer",
        sf::Style::Default, sf::State::Windowed,
        sf::ContextSettings{.antiAliasingLevel = 8}
    );
    sf::Image icon;
    if (icon.loadFromFile("../pics/logo.png")) {
        sf::Image iconView(icon);
        window.setIcon(iconView);
    }

    initStartMenu();
    myInputs *inputs = new myInputs();
    while (window.isOpen()) {
        while (auto const event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (auto const e = event->getIf<sf::Event::KeyPressed>()) {
                inputs->keyClicked(*e);
            }
            if (auto const m = event->getIf<sf::Event::MouseMoved>()) {
                inputs->mouseMoved({static_cast<float>(m->position.x), static_cast<float>(m->position.y)});
            }
            if (auto const e = event->getIf<sf::Event::MouseButtonPressed>()) {
                inputs->mouseClicked({static_cast<float>(e->position.x), static_cast<float>(e->position.y)});
            }
        }
        if (currentScreen == ScreenState::Game) {
            updateGame();
        }
        window.clear();
        if (currentScreen == ScreenState::StartMenu) {
            window.draw(backgroundSprite);
            window.draw(backgroundRectangle);
            window.draw(titleText);
            window.draw(underTitleText);
        } else if (currentScreen == ScreenState::OptionMenu) {
            updateOptionMenu();
            window.clear(sf::Color::Yellow);
            window.draw(playText);
            window.draw(settingText);
            window.draw(creditsText);
            window.draw(exitTextInOption);
            window.draw(scoreText);
        } else if (currentScreen == ScreenState::CreditsMenu) {
            window.clear(sf::Color::Yellow);
            initCreditsMenu();
            window.draw(authorName);
            window.draw(credits);
            window.draw(exitTextInCredits);
            window.draw(links);
        } else if (currentScreen == ScreenState::Game) {
            window.clear(sf::Color::Yellow);
            window.draw(exitTextInGame);

            for (auto &t: vecOfEnglishWords) {
                std::string wholeWord = t.getString();
                bool isMatching = !wordInput.empty() && wholeWord.find(wordInput) == 0;
                if (highlightMode && isMatching) {
                    auto position = t.getPosition();
                    auto font = t.getFont();
                    auto size = t.getCharacterSize();
                    float xpos = position.x;
                    for (std::size_t i = 0; i < wordInput.size(); i++) {
                        sf::Text letter(font, std::string(1, wholeWord[i]), size);
                        letter.setPosition({xpos, position.y});
                        letter.setFillColor(sf::Color::Green);
                        window.draw(letter);
                        xpos += letter.findCharacterPos(1).x - letter.getPosition().x;
                    }
                    std::string restWord;
                    for (std::size_t i = wordInput.size(); i < wholeWord.size(); i++) {
                        restWord += wholeWord[i];
                    }
                    sf::Text rest(font, restWord, size);
                    rest.setPosition({xpos, position.y});
                    rest.setFillColor(t.getFillColor());
                    window.draw(rest);
                } else {
                    window.draw(t);
                }
            }
            window.draw(inputText);
            window.draw(pointsText);
            window.draw(mistakesText);
            window.draw(wpmText);
            window.draw(cpmText);
            for (int i = 0; i < lives; i++) {
                window.draw(vecOfSprite[i]);
            }
            vecOfSprite[lives - mistakes + 1].setColor({255, 255, 255, 0});
            if (isPaused) {
                shortCutsSprite.setColor({255, 255, 255, 255});
                window.draw(shortCutsSprite);
            }
            if (!isPaused) {
                shortCutsSprite.setColor({255, 255, 255, 0});
            }
        } else if (currentScreen == ScreenState::GameOver) {
            window.clear(sf::Color::Yellow);
            window.draw(gameOverText);
            window.draw(playerPointsText);
            window.draw(saveScoreButton);
            window.draw(saveScoreText);
            window.draw(typeNickName);
            window.draw(nicknameInput);
            window.draw(exitInGameOver);
        } else if (currentScreen == ScreenState::BestScore) {
            window.clear(sf::Color::Yellow);
            window.draw(retangle);
            window.draw(bestPlayersScores);
            loadScores();
            for (auto const &text: bestScoreTexts) {
                window.draw(text);
            }
            window.draw(exitTextInBestScores);
        } else if (currentScreen == ScreenState::SettingMenu) {
            window.clear(sf::Color::Yellow);
            updateSettingMenu();
            window.draw(wordLength);
            window.draw(fontText);
            window.draw(speedText);
            window.draw(frequencyText);
            window.draw(sizeText);
            window.draw(playText);
            window.draw(livesText);
            window.draw(plusButton);
            window.draw(minusButton);
            window.draw(exitText6);
            if (speedList.visible) {
                for (auto *t: speedList.things) {
                    window.draw(*t);
                }
            }
            if (fontList.visible) {
                for (auto *t: fontList.things) {
                    window.draw(*t);
                }
            }
            if (wordsLengthList.visible) {
                for (auto *t: wordsLengthList.things) {
                    window.draw(*t);
                }
            }
            if (sizeList.visible) {
                for (auto *t: sizeList.things) {
                    window.draw(*t);
                }
            }
            if (frequencyList.visible) {
                for (auto *t: frequencyList.things) {
                    window.draw(*t);
                }
            }
        }
        window.display();
    }
}
