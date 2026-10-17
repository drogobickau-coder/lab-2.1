#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cursor
{
private:
    int first;
    int second;

public:
    Cursor();
    Cursor(int x, int y);
    Cursor(const Cursor& c);
    ~Cursor();

    int GetFirst() const { return first; }
    int GetSecond() const { return second; }
    bool SetFirst(int value);
    bool SetSecond(int value);

    void changeX(int newValue);
    void changeY(int newValue);

    Cursor& operator=(const Cursor& c);
    operator string() const;

    Cursor& operator++();
    Cursor& operator--();
    Cursor operator++(int);
    Cursor operator--(int);

    friend ostream& operator<<(ostream& out, const Cursor& c);
    friend istream& operator>>(istream& in, Cursor& c);
};