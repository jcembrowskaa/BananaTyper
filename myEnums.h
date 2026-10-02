#pragma once
#include <SFML/Graphics.hpp>

enum class ScreenState {
    StartMenu,
    OptionMenu,
    SettingMenu,
    CreditsMenu,
    Game,
    GameOver,
    BestScore,
    Exit
};

enum class Options {
    play, settings, credits,  score, exit,Count
};

enum class Settings {
    Speed, TimeMode, Font, SignsType, Size, play, lives, Count
};

enum class Speed {
    sloth, monkey, gibbon, Count
};

enum class wordsLength {
    ant, earthworm, lizard, snake, Count
};

enum class Frequency {
    drop, shower, storm, deluge, Count
};

enum class size {
    seed, seedling, tree, Count
};
