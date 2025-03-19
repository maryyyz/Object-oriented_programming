#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

// Класс Система аутентификации
class AuthenticationSystem {
public:
    bool login(string username, string password) {
        cout << "Пользователь " << username << " вошел в систему." << endl;
        return true;
    }
    void registerUser(string username) {
        cout << "Пользователь " << username << " зарегистрирован." << endl;
    }
};

// Класс Пользователь
class User {
public:
    string name;
    User(string n) : name(n) {}
    void addSoftware() { cout << "Добавлено ПО для пользователя: " << name << endl; }
    void deleteSoftware() { cout << "Удалено ПО для пользователя: " << name << endl; }
    void viewSoftware() { cout << "Просмотр ПО пользователя: " << name << endl; }
};

// Абстрактный класс Программное обеспечение
class Software {
protected:
    string name;
    string manufacturer;
    string category;
public:
    Software(string n, string m, string c) : name(n), manufacturer(m), category(c) {}
    virtual void displayInfo() const = 0;
    virtual bool isAvailable() const = 0;
    virtual ~Software() {}
};

// Класс Свободное ПО
class FreeSoftware : public Software {
public:
    FreeSoftware(string n, string m, string c) : Software(n, m, c) {}
    void displayInfo() const override {
        cout << "Свободное ПО: " << name << ", Производитель: " << manufacturer << ", Категория: " << category << endl;
    }
    bool isAvailable() const override {
        return true;
    }
};

// Класс Условно-бесплатное ПО
class Shareware : public Software {
private:
    time_t installDate;
    int trialPeriod; // в днях
public:
    Shareware(string n, string m, string c, time_t d, int t) : Software(n, m, c), installDate(d), trialPeriod(t) {}
    void displayInfo() const override {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &installDate);
        cout << "Условно-бесплатное ПО: " << name << ", Производитель: " << manufacturer << ", Категория: " << category << ", Дата установки: " << buffer;
    }
    bool isAvailable() const override {
        time_t currentTime = time(nullptr);
        return difftime(currentTime, installDate) / (60 * 60 * 24) < trialPeriod;
    }
};

// Класс Коммерческое ПО
class CommercialSoftware : public Software {
private:
    double price;
    time_t installDate;
    int licenseDuration; // в днях
public:
    CommercialSoftware(string n, string m, string c, double p, time_t d, int l) : Software(n, m, c), price(p), installDate(d), licenseDuration(l) {}
    void displayInfo() const override {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &installDate);
        cout << "Коммерческое ПО: " << name << ", Производитель: " << manufacturer << ", Категория: " << category << ", Цена: " << price << " руб., Дата установки: " << buffer;
    }
    bool isAvailable() const override {
        time_t currentTime = time(nullptr);
        return difftime(currentTime, installDate) / (60 * 60 * 24) < licenseDuration;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    AuthenticationSystem auth;
    User user("Иван Иванов");
    auth.login(user.name, "password123");
    user.addSoftware();
    user.viewSoftware();

    vector<Software*> softwareDatabase;
    time_t now = time(nullptr);

    softwareDatabase.push_back(new FreeSoftware("LibreOffice", "The Document Foundation", "Офисные приложения"));
    softwareDatabase.push_back(new Shareware("WinRAR", "RARLAB", "Архиваторы и утилиты для сжатия данных", now - 10 * 24 * 60 * 60, 30)); // 10 дней назад, срок 30 дней
    softwareDatabase.push_back(new CommercialSoftware("Adobe Photoshop", "Adobe", "Графические редакторы", 19999.99, now - 50 * 24 * 60 * 60, 365)); // 50 дней назад, срок 365 дней

    cout << "Полная информация о программном обеспечении:\n";
    for (const auto& sw : softwareDatabase) {
        sw->displayInfo();
        cout << "Доступно для использования: " << (sw->isAvailable() ? "Да" : "Нет") << endl << endl;
    }

    cout << "ПО, доступное для использования:\n";
    for (const auto& sw : softwareDatabase) {
        if (sw->isAvailable()) {
            sw->displayInfo();
        }
    }

    for (auto& sw : softwareDatabase) {
        delete sw;
    }
    return 0;
}