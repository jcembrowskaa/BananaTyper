#include "mouseAndKey.h"


auto myInputs::keyClicked(sf::Event::KeyPressed const &e) -> void {
    switch (currentScreen) {
        case ScreenState::StartMenu: keyClickedInOther(e);
            break;
        case ScreenState::CreditsMenu: keyClickedInOther(e);
            break;
        case ScreenState::GameOver: keyClickedInGameOver(e);
            break;
        case ScreenState::SettingMenu: keyClickedInSettings(e);
            break;
        case ScreenState::OptionMenu: keyClickedInOptions(e);
            break;
        case ScreenState::Game: keyClickedInGame(e);
            break;
        case ScreenState::BestScore: keyClickedInOther(e);
            break;
        default: break;
    }
};

void myInputs::mouseClicked(const sf::Vector2f &mousePosition) {
    switch (currentScreen) {
        case ScreenState::StartMenu: mouseClickedInOther(mousePosition);
            break;
        case ScreenState::CreditsMenu: mouseClickedInOther(mousePosition);
            break;
        case ScreenState::SettingMenu: mouseClickedInSettings(mousePosition);
            break;
        case ScreenState::OptionMenu: mouseClickedInOptions(mousePosition);
            break;
        case ScreenState::BestScore: mouseClickedInOther(mousePosition);
            break;
        case ScreenState::GameOver: mouseClickedInGameOver(mousePosition);
            break;
        case ScreenState::Game: mouseClickedInGame(mousePosition);
            break;
        default: break;
    }
}

void myInputs::mouseMoved(const sf::Vector2f &mousePosition) {
    switch (currentScreen) {
        case ScreenState::OptionMenu: mouseMovedInOptions(mousePosition);
            break;
        case ScreenState::SettingMenu: mouseMovedInSettings(mousePosition);
            break;
    }
}
