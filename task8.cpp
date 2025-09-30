#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void calculateSalaryAndTax(int hours, double rate, double bonus_percent, 
                          double &salary, double &tax) {
    salary = hours * rate;
    double bonus = salary * bonus_percent / 100;
    salary += bonus;
    tax = salary * 0.13;
}

int main() {
    int n;
    cout << "Введите количество работников: ";
    cin >> n;
    
    vector<int> hours(n);
    vector<double> rates(n);
    vector<double> salaries(n);
    vector<double> taxes(n);
    
    // Ввод данных
    for (int i = 0; i < n; i++) {
        cout << "Работник " << i+1 << ":" << endl;
        cout << "Введите количество часов: ";
        cin >> hours[i];
        cout << "Введите ставку оплаты: ";
        cin >> rates[i];
    }
    
    // Вычисление зарплат и налогов
    double total_tax = 0;
    for (int i = 0; i < n; i++) {
        calculateSalaryAndTax(hours[i], rates[i], 0, salaries[i], taxes[i]);
        total_tax += taxes[i];
    }
    
    // Поиск минимальной зарплаты
    double min_salary = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < n; i++) {
        if (salaries[i] < min_salary) {
            min_salary = salaries[i];
            min_index = i;
        }
    }
    
    // Поиск максимальной зарплаты
    double max_salary = INT_MIN;
    int max_index = -1;
    for (int i = 0; i < n; i++) {
        if (salaries[i] > max_salary) {
            max_salary = salaries[i];
            max_index = i;
        }
    }
    
    // Работники с зарплатой на руки более 50000
    vector<int> high_salary_workers;
    for (int i = 0; i < n; i++) {
        if (salaries[i] - taxes[i] > 50000) {
            high_salary_workers.push_back(i+1);
        }
    }
    
    // Вывод результатов
    cout << "\nРезультаты:" << endl;
    cout << "Работник с минимальной зарплатой: №" << min_index+1 
         << " (" << min_salary << " руб.)" << endl;
    cout << "Максимальная зарплата: " << max_salary << " руб. (работник №" 
         << max_index+1 << ")" << endl;
    
    cout << "Работники с зарплатой на руки более 50000 руб.: ";
    for (int i : high_salary_workers) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << "Общая сумма налога: " << total_tax << " руб." << endl;
    
    return 0;
}