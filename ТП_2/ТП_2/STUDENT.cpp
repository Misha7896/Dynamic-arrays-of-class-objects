#include "STUDENT.h"

ostream& operator<<(ostream& os, const STUDENT& student)
{
    os << "Surname and Initials: " << student.SurnameInitials;
    return os;
}

istream& operator>>(istream& is, STUDENT& student)
{
    cout << "Enter Surname and Initials: ";
    is >> student.SurnameInitials;
    //cout << "Enter scores from 1 to 5 (separated by spaces): ";

    cout << "Enter scores from 1 to 5 in mathematics (separated by a space): ";
    char grade;
    cin >> grade;
    while (int(grade) - 48 < 6 && int(grade) - 48 > 0) {
        student.grades.push_back(int(grade) - 48);
        is >> grade;
    }

    student.grades.push_back(0);

    cout << "Enter scores from 1 to 5 in Russian (separated by a space): ";
    cin >> grade;
    while (int(grade) - 48 < 6 && int(grade) - 48 > 0) {
        student.grades.push_back(int(grade) - 48);
        is >> grade;
    }
    return is;
}

STUDENT::STUDENT()
{
    cout << "STUDENT()" << endl;
}
STUDENT::~STUDENT()
{
    cout << "~STUDENT()" << endl;
}