#include <fstream>
#include "BestScoreScreen.h"
#include <ranges>
#include <iostream>
#include <bits/ranges_algo.h>

#include "../settingsAndOptions/GlobalStates.h"

sf::Text bestPlayersScores(arcadeBoxes, "Top 5!", 70);
std::map<std::string, float> playersScore;

std::string nickName;

sf::Text nicknameInput(machineFont, "", 50);
std::vector<sf::Text> bestScoreTexts;

sf::RectangleShape retangle;

sf::Text exitTextInBestScores(machineFont, "EXIT", 40);

auto loadScores() -> std::map<std::string, float> {

    std::fstream bestScoreFile("../rank/BestPlayersScores.txt");

    std::string nickName;
    float score;

    while (bestScoreFile >> nickName >> score) {
        if (playersScore.contains(nickName)) {
            playersScore[nickName] = std::max(playersScore[nickName], score);
        } else {
            playersScore[nickName] = score;
        }
    }
    return playersScore;
}

void saveBestScores() {
    currentScreen = ScreenState::BestScore;

    sf::RectangleShape rectangle({300, 100});
    rectangle.setFillColor(sf::Color::Magenta);
    rectangle.setPosition(sf::Vector2f(100, 300));


    std::fstream bestScoreFile("../rank/BestPlayersScores.txt", std::ios::out | std::ios::trunc);
    for (auto const &[nickName, playersScore]: playersScore) {
        bestScoreFile << nickName << " " << playersScore << "\n";
    }

    nickName.clear();
    nicknameInput.setFillColor(sf::Color::Magenta);
    nicknameInput.setPosition({200, 300});
}

void initBestScoreScreen() {
    loadScores();

    bestScoreTexts.clear();
    currentScreen = ScreenState::BestScore;
    bestPlayersScores.setPosition({200, 10});
    bestPlayersScores.setFillColor(sf::Color::Magenta);

    std::vector<std::pair<std::string, float> > sortedScores(playersScore.begin(), playersScore.end());

    std::ranges::sort(sortedScores, [](auto const &a, auto const &b) {
        return a.second > b.second;
    });

    if (sortedScores.size() > 5) {
        sortedScores.resize(5);
    }
    float yPos = 100;
    for (auto const &[nickName,playersScore]: sortedScores) {
        std::string text = std::format("{} {:.2f}",nickName,playersScore);
        sf::Text line(machineFont, text, 50);
        line.setPosition({140, yPos});
        line.setFillColor(sf::Color::Magenta);
        bestScoreTexts.push_back(line);
        yPos += 50;
    }
    exitTextInBestScores.setPosition({10, 550});
    exitTextInBestScores.setFillColor(sf::Color::Magenta);
}
