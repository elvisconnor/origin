#include <iostream>
#include <map>
#include <string>

int main() {

    std::string phrase = "Hello world!";
    std::map<char, int> charFrequency;

    for (char c : phrase) {
        if (charFrequency.find(c) != charFrequency.end()) {
            charFrequency[c] += 1;
        }
        else {
            charFrequency[c] = 1;
        }
    }

    std::map<int, char, std::greater<int>> sortedCharFrequency;

    for (auto const& pair : charFrequency) {
        sortedCharFrequency[pair.second] = pair.first;
    }

    for (auto const& pair : sortedCharFrequency) {
        std::cout << pair.second << ": " << pair.first << std::endl;
    }

    for (auto const& pair : charFrequency) {
        if (pair.second == 1 &&
            sortedCharFrequency.find(pair.first) == sortedCharFrequency.end()) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }

    return 0;
}