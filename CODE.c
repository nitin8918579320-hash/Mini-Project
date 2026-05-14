#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cow {
public:
    string name;
    int age;
    double milkProduction; // in liters

    Cow(string n, int a, double mp)
        : name(n), age(a), milkProduction(mp) {}
};

class DairyFarm {
private:
    vector<Cow> cows;

public:
    void addCow(const string& name, int age, double milkProduction) {
        cows.emplace_back(name, age, milkProduction);
        cout << "Cow " << name << " added successfully!" << endl;
    }

    void displayCows() {
        if (cows.empty()) {
            cout << "No cows in the farm." << endl;
            return;
        }

        cout << "\nList of Cows:" << endl;

        for (const auto& cow : cows) {
            cout << "Name: " << cow.name
                 << ", Age: " << cow.age
                 << ", Milk Production: "
                 << cow.milkProduction << " liters" << endl;
        }
    }

    void totalMilkProduction() {
        double total = 0;

        for (const auto& cow : cows) {
            total += cow.milkProduction;
        }

        cout << "Total Milk Production: "
             << total << " liters" << endl;
    }
};

void displayMenu() {
    cout << "\nDairy Management System" << endl;
    cout << "1. Add Cow" << endl;
    cout << "2. Display Cows" << endl;
    cout << "3. Total Milk Production" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    DairyFarm farm;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;
            int age;
            double milkProduction;

            cout << "Enter Cow Name: ";
            cin >> name;

            cout << "Enter Cow Age: ";
            cin >> age;

            cout << "Enter Milk Production (in liters): ";
            cin >> milkProduction;

            farm.addCow(name, age, milkProduction);
            break;
        }

        case 2:
            farm.displayCows();
            break;

        case 3:
            farm.totalMilkProduction();
            break;

        case 4:
            cout << "Exiting the system." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
