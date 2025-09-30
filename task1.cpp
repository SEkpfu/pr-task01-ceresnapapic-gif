#include <iostream>
using namespace std;

int main() {
    int hours;
    double rate, bonus_percent;
    
    cout << "Введите количество отработанных часов: ";
    cin >> hours;
    
    cout << "Введите ставку почасовой оплаты (руб./час): ";
    cin >> rate;
    
    cout << "Введите процент премии: ";
    cin >> bonus_percent;
    
    double base_salary = hours * rate;
    double bonus = base_salary * bonus_percent / 100;
    double total_salary = base_salary + bonus;
    
    cout << "Общая заработанная сумма: " << total_salary << " руб." << endl;
    
    return 0;
}