#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <tuple>
#include <locale>

struct Vec3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    int r = 255, g = 255, b = 255;

    bool operator==(const Vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator<(const Vec3& other) const {
        return std::tie(x, y, z) < std::tie(other.x, other.y, other.z);
    }
};

struct Triangle {
    int v1, v2, v3;
};

class Model {
public:
    std::list<Vec3> vertices;
    std::list<Triangle> triangles;

    void loadOBJ(const std::string& filename) {
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

                // Пытаемся прочитать цвет (если есть)
                if (!(iss >> v.r >> v.g >> v.b)) {
                    v.r = v.g = v.b = 255;
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

    void saveOBJ(const std::string& filename) const {
        std::ofstream out(filename);
        if (!out.is_open()) {
            std::cerr << "Не удалось создать файл: " << filename << "\n";
            return;
        }

        for (const auto& v : vertices)
            out << "v " << v.x << " " << v.y << " " << v.z << " "
            << v.r << " " << v.g << " " << v.b << "\n";

        for (const auto& t : triangles)
            out << "f " << t.v1 + 1 << " " << t.v2 + 1 << " " << t.v3 + 1 << "\n";

        std::cout << "Файл \"" << filename << "\" успешно сохранён.\n";
    }

    void print() const {
        std::cout << "\nВершины:\n";
        for (const auto& v : vertices)
            std::cout << "v " << v.x << " " << v.y << " " << v.z
            << " " << v.r << " " << v.g << " " << v.b << "\n";

        std::cout << "\nТреугольники:\n";
        for (const auto& t : triangles)
            std::cout << "f " << t.v1 + 1 << " " << t.v2 + 1 << " " << t.v3 + 1 << "\n";
    }

    void addColor(int r, int g, int b) {
        for (auto& v : vertices) {
            v.r = r;
            v.g = g;
            v.b = b;
        }
    }

    void merge(const Model& other) {
        std::vector<Vec3> currentVec(vertices.begin(), vertices.end());
        std::map<Vec3, int> vertexMap;
        for (size_t i = 0; i < currentVec.size(); ++i)
            vertexMap[currentVec[i]] = static_cast<int>(i);

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

    void removeInternalVertices() {
        std::set<int> usedIndices;
        for (const auto& t : triangles)
            usedIndices.insert({ t.v1, t.v2, t.v3 });

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

    void sortModel() {
        vertices.sort();
        triangles.sort([](const Triangle& a, const Triangle& b) {
            return std::tie(a.v1, a.v2, a.v3) < std::tie(b.v1, b.v2, b.v3);
            });
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Model model1, model2;
    model1.loadOBJ("object1.obj");
    model2.loadOBJ("object2.obj");

    model1.addColor(255, 0, 0);  // Красный
    model2.addColor(0, 255, 0);  // Зелёный

    model1.merge(model2);
    model1.removeInternalVertices();
    model1.sortModel();

    model1.print();
    model1.saveOBJ("object3.obj");

    std::cout << "\nОбработка завершена.\n";
    return 0;
}
