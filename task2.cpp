#include <iostream>
using namespace std;

// Функция вычисления общей зарплаты
double calculateTotalSalary(int hours, double rate, double bonus_percent) {
    double base_salary = hours * rate;
    double bonus = base_salary * bonus_percent / 100;
    return base_salary + bonus;
}

// Функция вычисления подоходного налога
double calculateIncomeTax(double total_salary) {
    return total_salary * 0.13;
}

// Функция вычисления суммы на руки
double calculateNetSalary(double total_salary) {
    return total_salary - calculateIncomeTax(total_salary);
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
    
    double total_salary = calculateTotalSalary(hours, rate, bonus_percent);
    double tax = calculateIncomeTax(total_salary);
    double net_salary = calculateNetSalary(total_salary);
    
    cout << "Общая зарплата: " << total_salary << " руб." << endl;
    cout << "Подоходный налог (13%): " << tax << " руб." << endl;
    cout << "Сумма на руки: " << net_salary << " руб." << endl;
    
    return 0;
}