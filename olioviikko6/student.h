#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student
{
public:
    Student(string, int);
    void setName(string);
    void setAge(int);
    string getName(void);
    int getAge(void);
    void printStudentInfo(void);
private:
    string name;
    int age;
};

#endif // STUDENT_H
