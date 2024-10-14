#include<iostream>
#include "Student-class.h"
using namespace std;

bool Student::isIdValid(int idNum)
{
    return idNum >= 0;
}

bool Student::isTestNumValid(int testNum) 
{
    return testNum >= 0 && testNum <= 100;  // Test scores should be between 0 and 100
}

Student* Student::allocateArray(int& numStudents, int& numTests)
{
    cout << '\n';
    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << "Enter the number of tests for each student: ";
    cin >> numTests;

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++)
    {
        students[i].tests = new int[numTests];
    }

    return students;
}

bool Student::isIdValid(int idNum) {
    return idNum >= 0;
}

bool Student::isTestNumValid(int testNum) {
    return testNum >= 0 && testNum <= 100;  // Test scores should be between 0 and 100
}

void Student::getInput(Student* arr, int numStudents, int numTests) {
    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> arr[i].name;

        // Validate ID Number
        cout << "ID Number: ";
        cin >> arr[i].idNumber;
        while (!isIdValid(arr[i].idNumber)) {
            cout << "Invalid ID Number. Enter again: ";
            cin >> arr[i].idNumber;
        }

        // Input and validate test scores
        for (int j = 0; j < numTests; j++) {
            cout << "Enter test " << j + 1 << " score: ";
            cin >> arr[i].tests[j];
            while (!isTestNumValid(arr[i].tests[j])) {
                cout << "Invalid score. Enter again (0-100): ";
                cin >> arr[i].tests[j];
            }
        }
    }

    calcAvgAndGrade(arr, numStudents, numTests);
}

void Student::calcAvgAndGrade(Student* arr, int numStudents, int numTests)
{
    for (int i = 0; i < numStudents; i++)
    {
        int totalOfAllTests = 0;

        for (int j = 0; j < numTests; j++)
        {
            totalOfAllTests += arr[i].tests[j];
        }

        arr[i].average = totalOfAllTests / numTests;

        if (arr[i].average >= 90)
        {
            arr[i].grade = 'A';
        }
        else if (arr[i].average >= 80)
        {
            arr[i].grade = 'B';
        }
        else if (arr[i].average >= 70)
        {
            arr[i].grade = 'C';
        }
        else if (arr[i].average >= 60)
        {
            arr[i].grade = 'D';
        }
        else if (arr[i].average >= 50)
        {
            arr[i].grade = 'E';
        }
        else
        {
            arr[i].grade = 'F';
        }
    }
}

void Student::displayOneStudent(const Student& st, int numTests) {
    cout << "\nName: " << st.name;
    cout << "\nID Number: " << st.idNumber;  // Corrected to display ID number

    // Display test scores
    for (int j = 0; j < numTests; j++) {
        cout << "Test " << j + 1 << " : " << st.tests[j] << '\n';
    }

    // Display average and grade
    cout << "Average: " << st.average;
    cout << "\nGrade: " << st.grade << '\n';
}

void Student::displayStudents(Student* arr, int numStudents, int numTests)
{
    for (int i = 0; i < numStudents; ++i)
    {
        cout << "Student no." << i + 1 << " Details:\n";
        displayOneStudent(arr[i], numTests);
        cout << "---------------------------\n"; // Added a separator for clarity
    }
    cout << '\n';
}

int Student::getStudentCount(Student* arr, int numStudents, char grade)
{
    int studentCount = 0;

    for (int i = 0; i < numStudents; ++i)
    {
        if (arr[i].grade == grade)
        {
            studentCount++;
        }
    }
    return studentCount;
}

Student* Student::getBestStudent(Student* arr, int numStudents)
{
    Student* bestStudent = &arr[0];
    for (int i = 1; i < numStudents; ++i)
    {
        if (arr[i].average > bestStudent->average)
        {
            bestStudent = &arr[i];
        }
    }
    return bestStudent;
}  // Added the missing closing bracket here

void Student::displayBestStudent(Student* arr, int numStudents, int numTests)
{
    Student* bestStudent = getBestStudent(arr, numStudents);
    cout << "\nBest Student:\n";
    displayOneStudent(*bestStudent, numTests);
}

void Student::deallocateArray(Student*& arr, int numStudents, int numTests)
{
    for (int i = 0; i < numStudents; ++i)
    {
        delete[] arr[i].tests;
    }
    delete[] arr;
    arr = nullptr;
}
