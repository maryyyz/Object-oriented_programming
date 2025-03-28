#pragma once
#include <string>
#include <stdexcept>

class Product {
public:
    virtual std::string getInfo() const = 0;
    virtual ~Product() = default;
};

class ConcreteProduct : public Product {
private:
    std::string name;
    double price;
public:
    ConcreteProduct(const std::string& n, double p);
    std::string getInfo() const override;
};

class StackEmptyException : public std::runtime_error {
public:
    StackEmptyException() : std::runtime_error("Ошибка: Стек пуст!") {}
};

class StackFullException : public std::runtime_error {
public:
    StackFullException() : std::runtime_error("Ошибка: Стек переполнен!") {}
};

class NullProductException : public std::runtime_error {
public:
    NullProductException() : std::runtime_error("Ошибка: Продукт не существует (nullptr)") {}
};

class ProductStack {
private:
    static const int MAX = 5;
    Product* items[MAX];
    int top;
public:
    ProductStack();
    void push(Product* product);
    Product* pop();
    bool isEmpty() const;
    bool isFull() const;
    ~ProductStack();
};

