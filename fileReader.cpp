#include <vector>
#include <fstream>

auto readFiles()->std::vector<std::string> {
    auto fileEngWords = std::fstream("../slowa/angielskieSlowa.txt");
    auto engWord = std::string();
    auto engWords = std::vector<std::string>();

    while (fileEngWords>>engWord) {
        engWords.push_back(engWord);
    }
    return engWords;
}
