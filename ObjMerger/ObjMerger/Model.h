#pragma once
#include <list>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <tuple>

struct Vec3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    int r = 255, g = 255, b = 255;

    bool operator==(const Vec3& other) const;
    bool operator<(const Vec3& other) const;
};

struct Triangle {
    int v1, v2, v3;
};

class Model {
public:
    std::list<Vec3> vertices;
    std::list<Triangle> triangles;

    void loadOBJ(const std::string& filename);
    void saveOBJ(const std::string& filename) const;
    void print() const;
    void addColor(int r, int g, int b);
    void merge(const Model& other);
    void removeInternalVertices();
    void sortModel();
};
