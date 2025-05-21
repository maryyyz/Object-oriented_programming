#include "WordSet.h"

std::string cleanWord(const std::string& word) {
    std::string result;
    for (char c : word) {
        unsigned char uc = static_cast<unsigned char>(c);
        if ((uc >= 128 && uc <= 255) || std::isalpha(uc)) {
            result += std::tolower(uc);
        }
    }
    return result;
}

void loadDictionary(const std::string& filename, WordSet<std::string>& dict) {
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        std::string cleaned = cleanWord(word);
        if (!cleaned.empty()) {
            dict.add(cleaned);
        }
    }
}

bool isNoun(const std::string& word, const WordSet<std::string>& nounDict) {
    return nounDict.contains(word);
}

bool isVerb(const std::string& word, const WordSet<std::string>& verbDict) {
    return verbDict.contains(word);
}
