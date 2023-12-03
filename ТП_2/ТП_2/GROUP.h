#pragma once
#include "STUDENT.h"

class GROUP
{
public:
    int groupNumber;
    double averageGrade;
    vector<STUDENT> students;
    int Math;
    int Rus;

    static int Count;

    GROUP();
    ~GROUP();

    void addStudent(const STUDENT& student);
    void displayStudentsWithGoodGrades();
    

};

