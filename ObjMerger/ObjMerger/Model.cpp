#include "Model.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

bool Vec3::operator==(const Vec3& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Vec3::operator<(const Vec3& other) const {
    return std::tie(x, y, z) < std::tie(other.x, other.y, other.z);
}

void Model::loadOBJ(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << "\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        if (line.substr(0, 2) == "v ") {
            Vec3 v;
            iss.ignore(2);
            iss >> v.x >> v.y >> v.z;
            if (!(iss >> v.r >> v.g >> v.b)) {
                v.r = 255;
                v.g = 255;
                v.b = 255;
            }
            vertices.push_back(v);
        }
        else if (line.substr(0, 2) == "f ") {
            Triangle t;
            iss.ignore(2);
            iss >> t.v1 >> t.v2 >> t.v3;
            t.v1--; t.v2--; t.v3--;
            triangles.push_back(t);
        }
    }

    std::cout << "Файл \"" << filename << "\" успешно загружен.\n";
}

void Model::saveOBJ(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Не удалось создать файл: " << filename << "\n";
        return;
    }

    for (const auto& v : vertices) {
        out << "v " << v.x << " " << v.y << " " << v.z << " "
            << v.r << " " << v.g << " " << v.b << "\n";
    }

    for (const auto& t : triangles) {
        out << "f " << t.v1 + 1 << " " << t.v2 + 1 << " " << t.v3 + 1 << "\n";
    }

    std::cout << "Файл \"" << filename << "\" успешно сохранён.\n";
}

void Model::print() const {
    std::cout << "\nВершины:\n";
    for (const auto& v : vertices) {
        std::cout << "v " << v.x << " " << v.y << " " << v.z
            << " " << v.r << " " << v.g << " " << v.b << "\n";
    }

    std::cout << "\nТреугольники:\n";
    for (const auto& t : triangles) {
        std::cout << "f " << t.v1 + 1 << " " << t.v2 + 1 << " " << t.v3 + 1 << "\n";
    }
}

void Model::addColor(int r, int g, int b) {
    for (auto& v : vertices) {
        v.r = r;
        v.g = g;
        v.b = b;
    }
}

void Model::merge(const Model& other) {
    std::vector<Vec3> currentVec(vertices.begin(), vertices.end());
    std::map<Vec3, int> vertexMap;
    for (size_t i = 0; i < currentVec.size(); ++i) {
        vertexMap[currentVec[i]] = static_cast<int>(i);
    }

    std::vector<Vec3> otherVec(other.vertices.begin(), other.vertices.end());
    for (const auto& v : otherVec) {
        if (vertexMap.find(v) == vertexMap.end()) {
            vertexMap[v] = static_cast<int>(currentVec.size());
            vertices.push_back(v);
            currentVec.push_back(v);
        }
    }

    for (const auto& t : other.triangles) {
        Triangle newT = {
            vertexMap[otherVec[t.v1]],
            vertexMap[otherVec[t.v2]],
            vertexMap[otherVec[t.v3]]
        };
        triangles.push_back(newT);
    }
}

void Model::removeInternalVertices() {
    std::set<int> usedIndices;
    for (const auto& t : triangles) {
        usedIndices.insert({ t.v1, t.v2, t.v3 });
    }

    std::list<Vec3> newVertices;
    std::map<int, int> oldToNew;
    int newIndex = 0;
    int oldIndex = 0;

    for (const auto& v : vertices) {
        if (usedIndices.count(oldIndex)) {
            newVertices.push_back(v);
            oldToNew[oldIndex] = newIndex++;
        }
        ++oldIndex;
    }

    vertices = std::move(newVertices);

    for (auto& t : triangles) {
        t.v1 = oldToNew[t.v1];
        t.v2 = oldToNew[t.v2];
        t.v3 = oldToNew[t.v3];
    }
}

void Model::sortModel() {
    vertices.sort();
    triangles.sort([](const Triangle& a, const Triangle& b) {
        return std::tie(a.v1, a.v2, a.v3) < std::tie(b.v1, b.v2, b.v3);
        });
}
