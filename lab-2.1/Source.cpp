#include <iostream>
#include <windows.h>
#include "Cursor.h"
#pragma execution_character_set("utf-8")

using namespace std;

#pragma pack(push, 1)
struct PackedCursor {
    int first;
    int second;
};
#pragma pack(pop)

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "--- Демонстрація конструкторів ---" << endl;
    Cursor c1;
    Cursor c2(100, 200);
    Cursor c3 = c2;

    cout << "c1 (умовчання): " << c1 << endl;
    cout << "c2 (ініціалізація): " << c2 << endl;
    cout << "c3 (копія c2): " << c3 << endl;

    cout << "\n--- Введення з клавіатури ---" << endl;
    Cursor c4;
    cin >> c4;
    cout << "Ви ввели: " << c4 << endl;

    cout << "\n--- Перевірка інкрементів/декрементів ---" << endl;
    cout << "Початкове c2: " << c2 << endl;
    cout << "Префіксний ++c2 (X+1): " << ++c2 << endl;
    cout << "Префіксний --c2 (X-1): " << --c2 << endl;
    cout << "Постфіксний c2++ (Y+1): повертає " << c2++ << ", стає " << c2 << endl;
    cout << "Постфіксний c2-- (Y-1): повертає " << c2-- << ", стає " << c2 << endl;

    cout << "\n--- Масив об'єктів ---" << endl;
    Cursor arr[3] = { Cursor(10, 10), Cursor(20, 20), Cursor(30, 30) };
    for (int i = 0; i < 3; i++) {
        cout << "Курсор " << i << ": " << arr[i] << endl;
    }

    cout << "\n--- Перевірка розміру класу ---" << endl;
    cout << "Розмір Cursor без #pragma pack(1): " << sizeof(Cursor) << " байт" << endl;
    cout << "Розмір упакованої структури (#pragma pack(1)): " << sizeof(PackedCursor) << " байт" << endl;

    return 0;
}