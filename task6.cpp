#include <iostream>
#include <string>
#include <cstring>
using namespace std;

double calculateNetSalary(int hours, double rate, double bonus_percent = 0) {
    double total_salary = hours * rate;
    double bonus = total_salary * bonus_percent / 100;
    total_salary += bonus;
    return total_salary * 0.87; // минус 13% налог
}

double calculateTax(int hours, double rate, double bonus_percent = 0) {
    double total_salary = hours * rate;
    double bonus = total_salary * bonus_percent / 100;
    total_salary += bonus;
    return total_salary * 0.13;
}

int main() {
    char surname1[21], surname2[21]; // не более 20 символов + '\0'
    int hours1, hours2;
    double rate1, rate2;
    
    // Первый работник
    cout << "Первый работник:" << endl;
    cout << "Введите фамилию: ";
    cin >> surname1;
    cout << "Введите количество часов: ";
    cin >> hours1;
    cout << "Введите ставку оплаты: ";
    cin >> rate1;
    
    // Второй работник
    cout << "Второй работник:" << endl;
    cout << "Введите фамилию: ";
    cin >> surname2;
    cout << "Введите количество часов: ";
    cin >> hours2;
    cout << "Введите ставку оплаты: ";
    cin >> rate2;
    
    double net_salary1 = calculateNetSalary(hours1, rate1);
    double net_salary2 = calculateNetSalary(hours2, rate2);
    double tax1 = calculateTax(hours1, rate1);
    double tax2 = calculateTax(hours2, rate2);
    
    // Фамилии тех, кто получил меньше 1000 руб.
    cout << "Получили меньше 1000 руб.: ";
    if (net_salary1 < 1000) cout << surname1 << " ";
    if (net_salary2 < 1000) cout << surname2;
    cout << endl;
    
    // Первая и последняя буквы для тех, чей налог более 50 руб.
    cout << "Фамилии с дефисом (налог > 50 руб.):" << endl;
    if (tax1 > 50) {
        int len = strlen(surname1);
        cout << surname1 << ": " << surname1[0] << "-" << surname1[len-1] << endl;
    }
    if (tax2 > 50) {
        int len = strlen(surname2);
        cout << surname2 << ": " << surname2[0] << "-" << surname2[len-1] << endl;
    }
    
    return 0;
}