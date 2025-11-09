#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// --- допоміжне: очистити помилковий ввід ---
void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ================== ЗАВДАННЯ 1: If11 ==================
void task_if11() {
    cout << "\nIf11\n";
    int A, B;
    cout << "введiть A i B : ";
    cin >> A >> B;          // вводь через пробіл: 1 2

    if (A != B) {
        int s = A + B;      // якщо різні — обом присвоїти суму
        A = s; B = s;
    } else {
        A = 0; B = 0;       // якщо рівні — обом 0
    }
    cout << "A=" << A << "\n";
    cout << "B=" << B << "\n";
}

// ================== ЗАВДАННЯ 2: If31 ==================
void task_if31() {
    cout << "\nIf31\n";
    double x;
    cout << "введiть x: ";
    cin >> x;

    int g;
    if (x < -1)       g = 1;
    else if (x <= 1)  g = 2;    // [-1;1]
    else              g = 3;

    cout << "g=" << g << "\n";
}

// ========== ЗАВДАННЯ 3: Геометрiя (варiант 9) =========
void task_geo_var9() {
    cout << "\nГеометрiя (варiант 9)\n";
    double X, Y, a;
    cout << "Введiть координати точки (x, y): ";
    cin >> X >> Y;
    cout << "Введiть сторону квадрата a: ";
    cin >> a;

    bool inside = false;

    // 1) Коло у квадраті: центр (a/2, a/2), r = a/2
    double r = a / 2.0;
    double dx = X - r, dy = Y - r;
    double dist2 = dx*dx + dy*dy;
    bool inSquare = (0 <= X && X <= a && 0 <= Y && Y <= a);
    bool inCircle = (dist2 <= r*r);
    if (inSquare && inCircle) inside = true;

    // 2) Трикутник зверху квадрата: висота h = a/2
    if (!inside && Y >= a && Y <= a + a/2.0) {
        double left  = a/2.0 - (Y - a);
        double right = a/2.0 + (Y - a);
        if (X >= left && X <= right) inside = true;
    }

    cout << (inside ? "Точка належить зафарбованiй областi.\n"
                    : "Точка НЕ належить зафарбованiй областi.\n");
}

// ========================= main ========================
int main() {
    while (true) {
        cout << "\n=========== М Е Н Ю ==========\n";
        cout << "1 - If11\n";
        cout << "2 - If31\n";
        cout << "3 - Геометрiя (варiант 9)\n";
        cout << "0 - Вихiд\n";
        cout << "Ваш вибiр: ";

        int choice;
        if (!(cin >> choice)) { clearBadInput(); continue; }

        switch (choice) {
            case 1: task_if11();      break;
            case 2: task_if31();      break;
            case 3: task_geo_var9();  break;
            case 0: cout << "Бувай!\n"; return 0;
            default: cout << "Немає такого пункту.\n"; break;
        }
    }
}