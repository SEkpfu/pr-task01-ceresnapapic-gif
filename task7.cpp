#include <iostream>
using namespace std;

double calculateTotalSalary(int hours, double rate, double bonus_percent = 0) {
    double base_salary = hours * rate;
    double bonus = base_salary * bonus_percent / 100;
    return base_salary + bonus;
}

int main() {
    const int WORKERS_COUNT = 5;
    double total_brigade_salary = 0;
    
    for (int i = 1; i <= WORKERS_COUNT; i++) {
        int hours;
        double rate;
        
        cout << "Работник " << i << ":" << endl;
        cout << "Введите количество часов: ";
        cin >> hours;
        cout << "Введите ставку оплаты: ";
        cin >> rate;
        
        double salary = calculateTotalSalary(hours, rate);
        total_brigade_salary += salary;
        
        cout << "Зарплата работника " << i << ": " << salary << " руб." << endl;
    }
    
    double average_salary = total_brigade_salary / WORKERS_COUNT;
    cout << "Средняя зарплата в бригаде: " << average_salary << " руб." << endl;
    
    return 0;
}