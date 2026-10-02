#include "Game.h"

sf::Texture liveTexture("../pics/zycie.png");
sf::Sprite liveSprite1(liveTexture);
sf::Sprite liveSprite2(liveTexture);
sf::Sprite liveSprite3(liveTexture);
sf::Sprite liveSprite4(liveTexture);
sf::Sprite liveSprite5(liveTexture);
sf::Sprite liveSprite6(liveTexture);
sf::Sprite liveSprite7(liveTexture);
sf::Sprite liveSprite8(liveTexture);
sf::Sprite liveSprite9(liveTexture);
sf::Sprite liveSprite10(liveTexture);

sf::Text inputText(machineFont, "", 30);
sf::Text pointsText(machineFont, "Points: 0", 30);
sf::Text mistakesText(machineFont, "Mistakes: 0", 30);

sf::Text exitTextInGame(machineFont, "EXIT", 40);
sf::Text cpmText(machineFont, "", 30);
sf::Text wpmText(machineFont, "", 30);


void initGame() {
    currentScreen = ScreenState::Game;
    vecOfEnglishWords.clear();
    vecOfSprite.clear();
    refreshSettingsInGame();
    loadedWords = readFiles();

    spawnClock.restart();
    gameClock.restart();

    wordInput.clear();
    inputText.setString("");
    points = 0;
    mistakes = 0;

    inputText.setPosition({10, 500});
    inputText.setFillColor(sf::Color::Magenta);

    pointsText.setPosition({100, 10});
    pointsText.setFillColor(sf::Color::Magenta);

    mistakesText.setPosition({370, 10});
    mistakesText.setFillColor(sf::Color::Magenta);


    typedCharactersCount = 0;
    typedWordsCount = 0;
    cpmText.setPosition({610, 10});
    cpmText.setFillColor(sf::Color::Magenta);
    wpmText.setPosition({610, 40});
    wpmText.setFillColor(sf::Color::Magenta);

    exitTextInGame.setPosition({10, 550});
    exitTextInGame.setFillColor(sf::Color::Magenta);


    float xpos = 100;
    liveSprite1.setPosition({xpos, 540});
    liveSprite2.setPosition({xpos + 50, 540});
    liveSprite3.setPosition({xpos + 100, 540});
    liveSprite4.setPosition({xpos + 150, 540});
    liveSprite5.setPosition({xpos + 200, 540});
    liveSprite6.setPosition({xpos + 250, 540});
    liveSprite7.setPosition({xpos + 300, 540});
    liveSprite8.setPosition({xpos + 350, 540});
    liveSprite9.setPosition({xpos + 400, 540});
    liveSprite10.setPosition({xpos + 450, 540});

    vecOfSprite.push_back(liveSprite1);
    vecOfSprite.push_back(liveSprite2);
    vecOfSprite.push_back(liveSprite3);
    vecOfSprite.push_back(liveSprite4);
    vecOfSprite.push_back(liveSprite5);
    vecOfSprite.push_back(liveSprite6);
    vecOfSprite.push_back(liveSprite7);
    vecOfSprite.push_back(liveSprite8);
    vecOfSprite.push_back(liveSprite9);
    vecOfSprite.push_back(liveSprite10);

    switch (lives) {
        case 1: livesPoints = 1.6;
            break;
        case 2: livesPoints = 1.3;
            break;
        case 3: livesPoints = 1;
            break;
        case 4: livesPoints = 0.9;
            break;
        case 5: livesPoints = 0.8;
            break;
        case 6: livesPoints = 0.7;
            break;
        case 7: livesPoints = 0.6;
            break;
        case 8: livesPoints = 0.5;
            break;
        case 9: livesPoints = 0.4;
            break;
        case 10: livesPoints = 0.3;
            break;
    }
    pointsText.setString("Points: 0");
    mistakesText.setString("Mistakes: 0");
}
