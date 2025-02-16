#include "student.h"

Student::Student(string n, int a): name(n), age(a) {}

void Student::setName(string n){
    Student::name = n;
}

void Student::setAge(int a){
    Student::age = a;
}

string Student::getName(void){
    return Student::name;
}

int Student::getAge(void){
    return Student::age;
}

void Student::printStudentInfo(void){
    std::cout << "Student " << Student::getName() << " Age " << Student::getAge() << std::endl;
}
