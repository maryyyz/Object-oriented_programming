#include <iostream>
#include <fstream>
#include <vector>

struct Vector3 { double x, y, z; };

double dotProduct(const Vector3& v1, const Vector3& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

int main() {
    std::ifstream inputFile("C:\\Users\\pixel\\source\\repos\\Object-oriented_programming\\VectorFilter\\x64\\Debug\\vectors.txt");
    if (!inputFile) { std::cerr << "File opening error" << std::endl; return 1; }

    std::vector<Vector3> vectors, filteredVectors;
    Vector3 temp, givenVector = { 1, 0, 0 };
    while (inputFile >> temp.x >> temp.y >> temp.z)
        if (dotProduct(temp, givenVector) != 0)

            filteredVectors.push_back(temp);
    inputFile.close();


    std::ofstream outputFile("C:\\Users\\pixel\\source\\repos\\Object-oriented_programming\\VectorFilter\\x64\\Debug\\vectors.txt");
    if (!outputFile) { std::cerr << "File recording error" << std::endl; return 1; }
    for (const auto& v : filteredVectors)
        outputFile << v.x << " " << v.y << " " << v.z << std::endl;

    std::cout << "The file has been updated. Orthogonal vectors are removed." << std::endl;
    return 0;
}