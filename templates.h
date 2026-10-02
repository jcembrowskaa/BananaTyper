#pragma once
#include <SFML/Graphics.hpp>

template<typename Enum>
void listOptionClick(std::vector<sf::Text *> &items, sf::Vector2f mousePosition, Enum &index, bool &visible) {
    for (auto i = 0; i < items.size(); i++) {
        if (items[i]->getGlobalBounds().contains(mousePosition)) {
            index = static_cast<Enum>(i);
            visible = false;
            break;
        }
    }
};

template<typename Enum>
void scrollUpSettings(Enum &e) {
    int value = static_cast<int>(e);
    int count = static_cast<int>(Enum::Count);
    if (value + 1 < count) {
        e = static_cast<Enum>(value + 1);
    }
}

template<typename Enum>
void scrollDownSettings(Enum &e) {
    int value = static_cast<int>(e);
    int count = static_cast<int>(Enum::Count);
    if (value > 0) {
        e = static_cast<Enum>(value - 1);
    }
}
