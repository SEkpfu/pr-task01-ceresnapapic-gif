#include <iostream>
using namespace std;

// Функция вычисления всех показателей через out параметры
void calculateAll(int hours, double rate, double bonus_percent, 
                 double &total_salary, double &tax, double &net_salary) {
    total_salary = hours * rate;
    double bonus = total_salary * bonus_percent / 100;
    total_salary += bonus;
    tax = total_salary * 0.13;
    net_salary = total_salary - tax;
}

int main() {
    int hours;
    double rate, bonus_percent;
    
    cout << "Введите количество отработанных часов: ";
    cin >> hours;
    
    cout << "Введите ставку почасовой оплаты (руб./час): ";
    cin >> rate;
    
    cout << "Введите процент премии: ";
    cin >> bonus_percent;
    
    double total_salary, tax, net_salary;
    calculateAll(hours, rate, bonus_percent, total_salary, tax, net_salary);
    
    cout << "Общая зарплата: " << total_salary << " руб." << endl;
    cout << "Подоходный налог (13%): " << tax << " руб." << endl;
    cout << "Сумма на руки: " << net_salary << " руб." << endl;
    
    return 0;
}