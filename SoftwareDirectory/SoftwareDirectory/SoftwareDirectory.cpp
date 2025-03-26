#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

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

class User {
public:
    string name;
    User(string n) : name(n) {}
    void addSoftware() { cout << "Добавлено ПО для пользователя: " << name << endl; }
    void deleteSoftware() { cout << "Удалено ПО для пользователя: " << name << endl; }
    void viewSoftware() { cout << "Просмотр ПО пользователя: " << name << endl; }
};

class SoftwareUpdate {
private:
    string version;
    string description;
    time_t releaseDate;
public:
    SoftwareUpdate(string v, string d, time_t r) : version(v), description(d), releaseDate(r) {}
    void displayUpdateInfo() const {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &releaseDate);
        cout << "Версия: " << version << ", Описание: " << description << ", Дата выхода: " << buffer;
    }
    bool isAvailable() const {
        time_t now = time(nullptr);
        return difftime(now, releaseDate) > 0;
    }
};

class Software {
protected:
    string name;
    string manufacturer;
    string category;
    vector<SoftwareUpdate> updates;
public:
    Software(string n, string m, string c) : name(n), manufacturer(m), category(c) {}
    virtual void displayInfo() const = 0;
    virtual bool isAvailable() const = 0;
    virtual ~Software() {}
    void addUpdate(SoftwareUpdate update) {
        updates.push_back(update);
    }
    void showUpdates() const {
        cout << "Обновления для " << name << ":\n";
        for (const auto& update : updates) {
            update.displayUpdateInfo();
        }
    }
};

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

class Shareware : public Software {
private:
    time_t installDate;
    int trialPeriod;
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

class CommercialSoftware : public Software {
private:
    double price;
    time_t installDate;
    int licenseDuration;
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
    softwareDatabase.push_back(new Shareware("WinRAR", "RARLAB", "Архиваторы и утилиты для сжатия данных", now - 10 * 24 * 60 * 60, 30));
    softwareDatabase.push_back(new CommercialSoftware("Adobe Photoshop", "Adobe", "Графические редакторы", 19999.99, now - 50 * 24 * 60 * 60, 365));

    softwareDatabase[2]->addUpdate(SoftwareUpdate("24.1", "Исправления ошибок", now - 5 * 24 * 60 * 60));
    softwareDatabase[2]->addUpdate(SoftwareUpdate("24.2", "Добавлены новые фильтры", now - 1 * 24 * 60 * 60));
    softwareDatabase[2]->showUpdates();

    cout << "Полная информация о программном обеспечении:\n";
    for (const auto& sw : softwareDatabase) {
        sw->displayInfo();
        cout << "Доступно для использования: " << (sw->isAvailable() ? "Да" : "Нет") << endl << endl;
    }

    for (auto& sw : softwareDatabase) {
        delete sw;
    }
    return 0;
}
