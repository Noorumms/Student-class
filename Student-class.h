#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H
#include <string>

class Student
{
private:
    std::string name;
    int idNumber;
    int* tests;
    double average;
    char grade;
    bool Student::isIdValid(int idNum);
    bool Student::isTestNumValid(int testNum);

public:
    Student* allocateArray(int&, int&);
    void getInput(Student* arr, int numStudents, int numTests);
    void calcAvgAndGrade(Student* arr, int numStudents, int numTests);
    void displayOneStudent(const Student& st, int numTests);
    void displayStudents(Student* arr, int numStudents, int numTests);
    int getStudentCount(Student* arr, int numStudents, char grade);
    Student* getBestStudent(Student* arr, int numStudents);
    void displayBestStudent(Student* arr, int numStudents, int numTests);
    void deallocateArray(Student*& arr, int numStudents, int numTests);
    void displayClassAverage(Student* arr, int numStudents);
    ~Student();
};

#endif
