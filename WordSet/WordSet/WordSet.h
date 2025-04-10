#pragma once
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

template <typename T>
class WordSet {
private:
    std::set<T> data;

public:
    void add(const T& value) {
        data.insert(value);
    }

    bool contains(const T& value) const {
        return data.find(value) != data.end();
    }

    size_t size() const {
        return data.size();
    }

    void print() const {
        for (const auto& el : data) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    typename std::set<T>::const_iterator begin() const { return data.begin(); }
    typename std::set<T>::const_iterator end() const { return data.end(); }
};

std::string cleanWord(const std::string& word);
void loadDictionary(const std::string& filename, WordSet<std::string>& dict);
bool isNoun(const std::string& word, const WordSet<std::string>& nounDict);
bool isVerb(const std::string& word, const WordSet<std::string>& verbDict);
