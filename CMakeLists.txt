cmake_minimum_required(VERSION 3.30)
project(2425L_30_s33754_AS)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)

FetchContent_MakeAvailable(SFML)


add_executable(bananaTyper
        MainScreen.cpp
        templates.h
        otherScreens/StartMenu.cpp
        settingsAndOptions/SettingMenu.cpp
        settingsAndOptions/OptionMenu.cpp
        otherScreens/CreditsMenu.cpp
        game/Game.cpp
        Fonts.cpp
        Fonts.h
        settingsAndOptions/GlobalStates.cpp
        settingsAndOptions/GlobalStates.h
        myEnums.h
        mouseAndKey.cpp
        mouseAndKey.h
        game/Game.h
        otherScreens/CreditsMenu.h
        fileReader.cpp
        fileReader.h
        otherScreens/GameOver.h
        otherScreens/GameOver.cpp
        settingsAndOptions/OptionMenu.h
        settingsAndOptions/SettingMenu.h
        otherScreens/StartMenu.h
        otherScreens/BestScoreScreen.h
        otherScreens/BestScoreScreen.cpp
        game/gameMouseAndKey.cpp
        settingsAndOptions/settingsMouseAndKey.cpp
        settingsAndOptions/optionMouseAndKey.cpp
        otherScreens/gameOverMouseAndKey.cpp
        otherScreens/otherMouseAndKey.cpp
        game/gameMouseAndKey.h
        settingsAndOptions/settingsMouseAndKey.h
        settingsAndOptions/optionMouseAndKey.h
        otherScreens/gameOverMouseAndKey.h
        otherScreens/otherMouseAndKey.h
        game/GameInit.cpp
)


target_link_libraries(bananaTyper SFML::Graphics SFML::Window SFML::Audio)




