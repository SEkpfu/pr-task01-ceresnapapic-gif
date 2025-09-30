#include <iostream>
using namespace std;

double calculateTotalSalary(int hours, double rate, double bonus_percent = 0) {
    double base_salary = hours * rate;
    double bonus = base_salary * bonus_percent / 100;
    return base_salary + bonus;
}

int main() {
    int hours1, hours2;
    double rate1, rate2;
    
    // Первый работник
    cout << "Первый работник:" << endl;
    cout << "Введите количество часов: ";
    cin >> hours1;
    cout << "Введите ставку оплаты: ";
    cin >> rate1;
    
    // Второй работник
    cout << "Второй работник:" << endl;
    cout << "Введите количество часов: ";
    cin >> hours2;
    cout << "Введите ставку оплаты: ";
    cin >> rate2;
    
    double salary1 = calculateTotalSalary(hours1, rate1);
    double salary2 = calculateTotalSalary(hours2, rate2);
    
    if (salary1 > salary2) {
        cout << "Первый работник заработал больше" << endl;
    } else if (salary2 > salary1) {
        cout << "Второй работник заработал больше" << endl;
    } else {
        cout << "Оба работника заработали одинаково" << endl;
    }
    
    cout << "Общая сумма: " << salary1 + salary2 << " руб." << endl;
    
    return 0;
}