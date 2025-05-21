#include <iostream>
#include <fstream>
#include <sstream>
#include "WordSet.h"

int main() {
    setlocale(LC_ALL, "Russian");

    WordSet<std::string> nouns;
    WordSet<std::string> verbs;
    WordSet<std::string> others;

    WordSet<std::string> nounDict;
    WordSet<std::string> verbDict;

    loadDictionary("nouns.txt", nounDict);
    loadDictionary("verbs.txt", verbDict);

    std::ifstream file("text.txt");
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл text.txt\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fullText = buffer.str();
    std::cout << "Исходный текст из файла text.txt:\n" << fullText << "\n\n";

    file.clear();
    file.seekg(0, std::ios::beg);

    std::string word;
    while (file >> word) {
        std::string cleaned = cleanWord(word);

        if (cleaned.empty()) {
            continue;
        }

        if (isNoun(cleaned, nounDict)) {
            nouns.add(cleaned);
        }
        else if (isVerb(cleaned, verbDict)) {
            verbs.add(cleaned);
        }
        else {
            others.add(cleaned);
        }
    }

    std::cout << "\nСуществительные:\n";
    nouns.print();

    std::cout << "\nГлаголы:\n";
    verbs.print();

    std::cout << "\nОстальные слова:\n";
    others.print();

    return 0;
}
