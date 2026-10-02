#include "GameOver.h"

#include "BestScoreScreen.h"
#include "../game/Game.h"
#include "../Fonts.h"
#include "gameOverMouseAndKey.h"

sf::Text gameOverText(arcadeBoxes, "", 100);
sf::Text playerPointsText(machineFont, "", 40);
sf::RectangleShape saveScoreButton;
sf::Text saveScoreText(machineFont, "Save score", 30);
sf::Text typeNickName(machineFont, "Type your Nickname: ", 30);
sf::Text exitInGameOver(machineFont, "EXIT", 40);
void initGameOver() {

    nickName.clear();
    nicknameInput.setString("");
    hasNicknameBeenEntered = false;
    currentScreen = ScreenState::GameOver;

    gameOverText.setString("Game Over");
    gameOverText.setFillColor(sf::Color::Magenta);
    gameOverText.setPosition({130,100});

    playerPointsText.setString(std::format("Points: {:.2f}",points));
    playerPointsText.setFillColor(sf::Color::Magenta);
    playerPointsText.setPosition({200,250});

    saveScoreButton.setSize({200,50});
    saveScoreButton.setFillColor(sf::Color::Magenta);
    saveScoreButton.setPosition({300,450});

    saveScoreText.setString("Save score");
    saveScoreText.setPosition({300,450});
    saveScoreText.setFillColor(sf::Color::Yellow);

    typeNickName.setPosition({200, 300});
    typeNickName.setFillColor(sf::Color::Magenta);

    exitInGameOver.setString("EXIT");
    exitInGameOver.setPosition({10,550});
    exitInGameOver.setFillColor(sf::Color::Magenta);
}
