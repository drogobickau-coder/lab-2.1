#include "Cursor.h"
#include <sstream>
#pragma execution_character_set("utf-8")

const int MAX_X = 1920;
const int MAX_Y = 1080;

bool Cursor::SetFirst(int value)
{
    if (value > 0 && value <= MAX_X) {
        first = value;
        return true;
    }
    first = 1;
    return false;
}

bool Cursor::SetSecond(int value)
{
    if (value > 0 && value <= MAX_Y) {
        second = value;
        return true;
    }
    second = 1;
    return false;
}

Cursor::Cursor()
{
    SetFirst(1);
    SetSecond(1);
}

Cursor::Cursor(int x, int y)
{
    bool xValid = SetFirst(x);
    bool yValid = SetSecond(y);

    if (!xValid || !yValid) {
        cout << "Попередження: Некоректні значення замінено на базові (1)." << endl;
    }
}

Cursor::Cursor(const Cursor& c)
{
    first = c.first;
    second = c.second;
}

Cursor::~Cursor() {}

void Cursor::changeX(int newValue)
{
    if (!SetFirst(newValue)) {
        cout << "Помилка: Вихід за межі екрану по горизонталі!" << endl;
    }
}

void Cursor::changeY(int newValue)
{
    if (!SetSecond(newValue)) {
        cout << "Помилка: Вихід за межі екрану по вертикалі!" << endl;
    }
}

Cursor& Cursor::operator=(const Cursor& c)
{
    if (this != &c) {
        first = c.first;
        second = c.second;
    }
    return *this;
}

Cursor::operator string() const
{
    stringstream ss;
    ss << "X = " << first << ", Y = " << second;
    return ss.str();
}

Cursor& Cursor::operator++()
{
    if (first < MAX_X) first++;
    return *this;
}

Cursor& Cursor::operator--()
{
    if (first > 1) first--;
    return *this;
}

Cursor Cursor::operator++(int)
{
    Cursor temp(*this);
    if (second < MAX_Y) second++;
    return temp;
}

Cursor Cursor::operator--(int)
{
    Cursor temp(*this);
    if (second > 1) second--;
    return temp;
}

ostream& operator<<(ostream& out, const Cursor& c)
{
    out << string(c);
    return out;
}

istream& operator>>(istream& in, Cursor& c)
{
    int x, y;
    cout << "Введіть X (1-" << MAX_X << "): ";
    in >> x;
    cout << "Введіть Y (1-" << MAX_Y << "): ";
    in >> y;
    c.SetFirst(x);
    c.SetSecond(y);
    return in;
}