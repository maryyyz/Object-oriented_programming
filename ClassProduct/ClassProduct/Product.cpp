#include "Product.h"
#include <sstream>
#include <iomanip>

ConcreteProduct::ConcreteProduct(const std::string& n, double p) : name(n), price(p) {}

std::string ConcreteProduct::getInfo() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << price;
    return "Продукт: " + name + ", Цена: " + oss.str() + " руб.";
}

ProductStack::ProductStack() : top(-1) {}

void ProductStack::push(Product* product) {
    if (product == nullptr) throw NullProductException();
    if (isFull()) throw StackFullException();
    items[++top] = product;
}

Product* ProductStack::pop() {
    if (isEmpty()) throw StackEmptyException();
    return items[top--];
}

bool ProductStack::isEmpty() const {
    return top == -1;
}

bool ProductStack::isFull() const {
    return top == MAX - 1;
}

ProductStack::~ProductStack() {
    for (int i = 0; i <= top; ++i) {
        delete items[i];
    }
}
