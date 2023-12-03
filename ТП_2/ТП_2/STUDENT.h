#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>

using namespace std;

class STUDENT
{
public:
	string SurnameInitials;
    vector<int> grades;

    STUDENT();
    ~STUDENT();

    friend ostream& operator<<(ostream& os, const STUDENT& student);
    friend istream& operator>>(istream& is, STUDENT& student);

};

