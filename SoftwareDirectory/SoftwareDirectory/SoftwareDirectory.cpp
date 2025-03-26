#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>

class AuthenticationSystem {
public:
    bool login(std::string username, std::string password) {
        std::cout << "Пользователь " << username << " вошел в систему." << std::endl;
        return true;
    }
    void registerUser(std::string username) {
        std::cout << "Пользователь " << username << " зарегистрирован." << std::endl;
    }
};

class User {
public:
    std::string name;
    User(std::string n) : name(n) {}
    void addSoftware() { std::cout << "Добавлено ПО для пользователя: " << name << std::endl; }
    void deleteSoftware() { std::cout << "Удалено ПО для пользователя: " << name << std::endl; }
    void viewSoftware() { std::cout << "Просмотр ПО пользователя: " << name << std::endl; }
};

class SoftwareUpdate {
private:
    std::string version;
    std::string description;
    time_t releaseDate;
public:
    SoftwareUpdate(std::string v, std::string d, time_t r) : version(v), description(d), releaseDate(r) {}
    void displayUpdateInfo() const {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &releaseDate);
        std::cout << "Версия: " << version << ", Описание: " << description << ", Дата выхода: " << buffer;
    }
    bool isAvailable() const {
        time_t now = time(nullptr);
        return difftime(now, releaseDate) > 0;
    }
};

class Software {
protected:
    std::string name;
    std::string manufacturer;
    std::string category;
    std::vector<SoftwareUpdate> updates;
public:
    Software(std::string n, std::string m, std::string c) : name(n), manufacturer(m), category(c) {}
    virtual void displayInfo() const = 0;
    virtual bool isAvailable() const = 0;
    virtual ~Software() {}
    void addUpdate(SoftwareUpdate update) {
        updates.push_back(update);
    }
    void showUpdates() const {
        std::cout << "Обновления для " << name << ":\n";
        for (const auto& update : updates) {
            update.displayUpdateInfo();
        }
    }
};

class FreeSoftware : public Software {
public:
    FreeSoftware(std::string n, std::string m, std::string c) : Software(n, m, c) {}
    void displayInfo() const override {
        std::cout << "Свободное ПО: " << name << ", Производитель: " << manufacturer << ", Категория: " << category << std::endl;
    }
    bool isAvailable() const override {
        return true;
    }
};

class Shareware : public Software {
private:
    time_t installDate;
    int trialPeriod;
public:
    Shareware(std::string n, std::string m, std::string c, time_t d, int t) : Software(n, m, c), installDate(d), trialPeriod(t) {}
    void displayInfo() const override {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &installDate);
        std::cout << "Условно-бесплатное ПО: " << name << ", Производитель: " << manufacturer << ", Категория: " << category << ", Дата установки: " << buffer;
    }
    bool isAvailable() const override {
        time_t currentTime = time(nullptr);
        return difftime(currentTime, installDate) / (60 * 60 * 24) < trialPeriod;
    }
};

class CommercialSoftware : public Software {
private:
    double price;
    time_t installDate;
    int licenseDuration;
public:
    CommercialSoftware(std::string n, std::string m, std::string c, double p, time_t d, int l) : Software(n, m, c), price(p), installDate(d), licenseDuration(l) {}
    void displayInfo() const override {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &installDate);
        std::cout << "Коммерческое ПО: " << name << ", Производитель: " << manufacturer << ", Категория: " << category << ", Цена: " << price << " руб., Дата установки: " << buffer;
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

    std::vector<Software*> softwareDatabase;
    time_t now = time(nullptr);

    softwareDatabase.push_back(new FreeSoftware("LibreOffice", "The Document Foundation", "Офисные приложения"));
    softwareDatabase.push_back(new Shareware("WinRAR", "RARLAB", "Архиваторы и утилиты для сжатия данных", now - 10 * 24 * 60 * 60, 30));
    softwareDatabase.push_back(new CommercialSoftware("Adobe Photoshop", "Adobe", "Графические редакторы", 19999.99, now - 50 * 24 * 60 * 60, 365));

    softwareDatabase[2]->addUpdate(SoftwareUpdate("24.1", "Исправления ошибок", now - 5 * 24 * 60 * 60));
    softwareDatabase[2]->addUpdate(SoftwareUpdate("24.2", "Добавлены новые фильтры", now - 1 * 24 * 60 * 60));
    softwareDatabase[2]->showUpdates();

    std::cout << "Полная информация о программном обеспечении:\n";
    for (const auto& sw : softwareDatabase) {
        sw->displayInfo();
        std::cout << "Доступно для использования: " << (sw->isAvailable() ? "Да" : "Нет") << std::endl << std::endl;
    }

    for (auto& sw : softwareDatabase) {
        delete sw;
    }
    return 0;
}
