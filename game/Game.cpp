#include "Game.h"
sf::Clock gameClock;
sf::Clock spawnClock;
std::vector<sf::Text> vecOfEnglishWords;
std::vector<std::string> loadedWords;
int mistakes = 0;
float points = 0;
std::string wordInput;
bool discoMode = false;
bool highlightMode = true;
float speedPoints = 1;
float frequencyPoints = 1.5;
float livesPoints = 1;
int wordLenghtPoints = 1;
sf::Color randomColor = sf::Color::Magenta;
int maxLength = 6;
sf::Clock statsClock;
extern int lives;
float speed = 100.0f;
float spawnTime = 2.0f;
int fontSize = 30;
sf::Color color = sf::Color::Magenta;
std::vector<sf::Sprite> vecOfSprite;
sf::Texture shortCutsTexture("../pics/skroty.png");
sf::Sprite shortCutsSprite(shortCutsTexture);

sf::Font &getSelectedFont() {
    switch (selectedFont) {
        case FontTypes::futureFont: return futureFont;
        case FontTypes::machineFont: return machineFont;
        case FontTypes::Vintage: return vintageFont;
        case FontTypes::Cartoons: return cartoonFont;
        case FontTypes::MonkeyNotes: return handwrittenFont;
        default: return machineFont;
    }
}

int typedCharactersCount = 0;
int typedWordsCount = 0;

bool isPaused = false;

void updateGame() {
    if (isPaused) {
        gameClock.restart();


        return;
    }
    if (statsClock.getElapsedTime().asMilliseconds() > 1000) {
        float elapsedSeconds = statsClock.getElapsedTime().asSeconds();
        if (elapsedSeconds > 0) {
            float cpm = (typedCharactersCount / elapsedSeconds) * 60.f;
            float wpm = (typedWordsCount / elapsedSeconds) * 60.f;
            cpmText.setString(std::format("CPM: {:.0f}", cpm));
            wpmText.setString(std::format("WPM: {:.0f}", wpm));
        }
    }
    float deltaTime = gameClock.restart().asSeconds();
    if (spawnClock.getElapsedTime().asSeconds() >= spawnTime && !loadedWords.empty()) {
        int randomIndex = std::rand() % loadedWords.size();

        if (loadedWords[randomIndex].size() <= maxLength) {
            const auto &word = loadedWords[randomIndex];
            wordLenghtPoints = loadedWords[randomIndex].size();
            sf::Text text(getSelectedFont(), loadedWords[randomIndex], fontSize);
            if (discoMode) {
                randomColor = sf::Color(rand() % 256, rand() % 180, rand() % 256);
                text.setFillColor(randomColor);
            } else {
                text.setFillColor(sf::Color::Magenta);
            }
            text.setPosition({
                0.f, static_cast<float>(std::rand() % (400 - 80 + 1) + 80)

            });
            vecOfEnglishWords.push_back(text);
            spawnClock.restart();
        }
    }
    for (auto &text: vecOfEnglishWords) {
        text.move(sf::Vector2f(speed * deltaTime, 0.f));
    }
    auto index = vecOfEnglishWords.begin();
    while (index != vecOfEnglishWords.end()) {
        if (index->getPosition().x > 800.f) {
            index = vecOfEnglishWords.erase(index);
            mistakes++;
            if (mistakes > lives - 1) {
                initGameOver();
            }
            mistakesText.setString("Mistakes: " + std::to_string(mistakes));
        } else {
            index++;
        }
    }
}

void refreshSettingsInGame() {
    switch (selectedSpeed) {
        case Speed::sloth:
            speed = 100.f;
            speedPoints = 1;
            break;
        case Speed::monkey:
            speed = 200.f;
            speedPoints = 1.5;
            break;
        case Speed::gibbon:
            speed = 300.f;
            speedPoints = 2;
            break;
    }

    switch (selectedFrequency) {
        case Frequency::deluge:
            spawnTime = 2.0f;
            frequencyPoints = 2.5;
            break;
        case Frequency::storm:
            spawnTime = 1.5f;
            frequencyPoints = 2;
            break;
        case Frequency::shower:
            spawnTime = 1.1f;
            frequencyPoints = 1.5;
            break;
        case Frequency::drop:
            spawnTime = 0.6f;
            frequencyPoints = 1;
            break;
    }

    switch (selectedSize) {
        case size::seed: fontSize = 20;
            break;
        case size::seedling: fontSize = 30;
            break;
        case size::tree: fontSize = 40;
            break;
    }

    switch (selectedWordLength) {
        case wordsLength::ant: maxLength = 3;
            break;
        case wordsLength::earthworm: maxLength = 6;
            break;
        case wordsLength::lizard: maxLength = 10;
            break;
        case wordsLength::snake: maxLength = 15;
            break;
    }
}
