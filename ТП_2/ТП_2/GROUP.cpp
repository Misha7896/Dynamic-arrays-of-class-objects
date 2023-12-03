#include "GROUP.h"

GROUP::GROUP()
{
    Count++;
}
GROUP::~GROUP()
{
    
}

void GROUP::addStudent(const STUDENT& student) {
    students.push_back(student);
}

void GROUP::displayStudentsWithGoodGrades()
{
    cout << "\nGroup number: " << groupNumber << endl;
    bool flag = true;
    averageGrade = 0;

    for (const auto& student : students) {
        double sum = 0.0;
        for (int grade : student.grades) {
            sum += grade;
        }
        double average = sum / (student.grades.size() - 1);
        averageGrade += average;
        if (average > 4.0) {
            cout << "Student: " << student.SurnameInitials << endl;
            flag = false;
        }
    }
    cout << "The average score in the group: " << (averageGrade / (students.size() - 0)) << endl;
    if (flag)
        cout << "There are no students in this group whose average score is higher than 4!" << endl;
}