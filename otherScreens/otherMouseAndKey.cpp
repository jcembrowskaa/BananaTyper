
#include "otherMouseAndKey.h"
auto keyClickedInOther(sf::Event::KeyPressed const &e) -> void {
    if (e.code == sf::Keyboard::Key::Space) {
        if (currentScreen == ScreenState::StartMenu) {
            initOptionMenu();
        }
    }
    if (currentScreen == ScreenState::CreditsMenu) {
        if (e.code == sf::Keyboard::Key::Escape) {
            initOptionMenu();
        }
    }

    if (currentScreen == ScreenState::BestScore) {
        if (e.code == sf::Keyboard::Key::Escape) {
            initOptionMenu();
        }
        if (e.code == sf::Keyboard::Key::Enter && !nickName.empty() && !hasNicknameBeenEntered) {
            hasNicknameBeenEntered = true;
            playersScore[nickName] = std::max(playersScore[nickName], points);
            saveBestScores();
            initBestScoreScreen();
        }
    }
};

void mouseClickedInOther(const sf::Vector2f &mousePosition) {

    if (currentScreen == ScreenState::CreditsMenu) {
        if (exitTextInCredits.getGlobalBounds().contains(mousePosition)) {
            initOptionMenu();
        }
    }
    if (currentScreen == ScreenState::BestScore) {
        if (exitTextInBestScores.getGlobalBounds().contains(mousePosition)) {
            initOptionMenu();
        }
    }

}