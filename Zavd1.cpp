#include <iostream>
#include <string>

using namespace std;

// Структура Enterprise, що представляє підприємство
struct Enterprise {
    string name;
    string country;
    string activity;
    double profit;
};

int main() {
    const int numEnterprises = 10; 
    Enterprise enterprises[numEnterprises];

    // Введення даних в масив підприємств за допомогою вказівників на структуру
    for (int i = 0; i < numEnterprises; i++) {
        Enterprise* entPtr = &enterprises[i]; // Вказівник на структуру Enterprise

        cout << "Введіть дані для підприємства " << i + 1 << ":" << endl;
        cout << "Назва: ";
        cin >> entPtr->name;
        cout << "Країна: ";
        cin >> entPtr->country;
        cout << "Вид діяльності: ";
        cin >> entPtr->activity;
        cout << "Річний прибуток: ";
        cin >> entPtr->profit;
    }

    // Впорядкування записів у масиві за спаданням річного прибутку
    for (int i = 0; i < numEnterprises - 1; i++) {
        for (int j = i + 1; j < numEnterprises; j++) {
            if (enterprises[i].profit < enterprises[j].profit) {
                // Обмін елементів місцями за допомогою вказівників
                Enterprise temp = enterprises[i];
                enterprises[i] = enterprises[j];
                enterprises[j] = temp;
            }
        }
    }

    // Виведення впорядкованого списку підприємств
    cout << "Список підприємств після сортування за річним прибутком:" << endl;
    for (int i = 0; i < numEnterprises; i++) {
        cout << "Назва: " << enterprises[i].name << ", Країна: " << enterprises[i].country << ", Вид діяльності: " << enterprises[i].activity << ", Прибуток: " << enterprises[i].profit << " грн" << endl;
    }

    // Виведення даних про всі підприємства легкої промисловості України
    cout << "Виведення даних про підприємства:" << endl;
    bool found = false;
    for (int i = 0; i < numEnterprises; i++) {
        if (enterprises[i].country == "Україна" && enterprises[i].activity == "легка") {
            cout << "Назва: " << enterprises[i].name << ", Країна: " << enterprises[i].country << ", Вид діяльності: " << enterprises[i].activity << ", Прибуток: " << enterprises[i].profit << " грн" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Немає підприємств легкої промисловості України." << endl;
    }

    return 0;
}