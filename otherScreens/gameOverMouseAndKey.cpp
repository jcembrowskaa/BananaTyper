#include "gameOverMouseAndKey.h"

bool hasNicknameBeenEntered = false;

auto keyClickedInGameOver(sf::Event::KeyPressed const &e) -> void {
    if (currentScreen == ScreenState::GameOver) {
        if (e.code == sf::Keyboard::Key::Escape) {
            initOptionMenu();
        }
        if (e.code == sf::Keyboard::Key::Enter && !nickName.empty()) {
            loadScores();
            playersScore[nickName] = std::max(playersScore[nickName], points);
            saveBestScores();
            initBestScoreScreen();
        } else if (e.code == sf::Keyboard::Key::Backspace && !nickName.empty()) {
            nickName.pop_back();
            nicknameInput.setString(nickName);
            nicknameInput.setPosition({250, 370});
            nicknameInput.setFillColor(sf::Color::Magenta);
        } else if (e.code >= sf::Keyboard::Key::A && e.code <= sf::Keyboard::Key::Z) {
            char smallOrHuge = isKeyPressed(sf::Keyboard::Key::LShift) ?'A':'a';
            nickName += static_cast<char>(smallOrHuge + static_cast<int>(e.code));
            nicknameInput.setString(nickName);
            nicknameInput.setPosition({250, 370});
            nicknameInput.setFillColor(sf::Color::Magenta);
        }
    }
}

void mouseClickedInGameOver(const sf::Vector2f &mousePosition) {
    if (currentScreen == ScreenState::GameOver) {
        if (exitInGameOver.getGlobalBounds().contains(mousePosition)) {
            points=0;
            mistakes=0;
            initOptionMenu();
        }
        if (saveScoreButton.getGlobalBounds().contains(mousePosition) && !nickName.empty()) {
            loadScores();
            playersScore[nickName] = std::max(playersScore[nickName], points);
            saveBestScores();
            hasNicknameBeenEntered = true;
            initBestScoreScreen();
        }

    }
}

void mouseMovedInGameOver(const sf::Vector2f &mousePosition) {
    if (currentScreen == ScreenState::GameOver) {
    }
}
