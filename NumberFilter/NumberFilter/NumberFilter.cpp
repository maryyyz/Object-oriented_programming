#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

int main() {
    std::ifstream inputFile("C:\\Users\\pixel\\source\\repos\\NumberFilter\\x64\\Debug\\number.txt");
    if (!inputFile) { std::cerr << "File opening error!" << std::endl; return 1; }

    std::vector<int> sequence, filteredNumbers;
    int num, minValue;

    while (inputFile >> num) {
        if (num == 0) {
            for (int n : sequence) if (n != minValue) filteredNumbers.push_back(n);
            filteredNumbers.push_back(0);
            sequence.clear();
        }
        else {
            if (sequence.empty()) minValue = num;
            minValue = std::min(minValue, num);
            sequence.push_back(num);
        }
    }
    for (int n : sequence) if (n != minValue) filteredNumbers.push_back(n);
    inputFile.close();

    std::ofstream outputFile("C:\\Users\\pixel\\source\\repos\\NumberFilter\\x64\\Debug\\number.txt");
    if (!outputFile) { std::cerr << "File recording error!" << std::endl; return 1; }
    for (int n : filteredNumbers) outputFile << n << " ";

    std::cout << "The file has been updated. The minimum values are removed from each sequence." << std::endl;
    return 0;
}
