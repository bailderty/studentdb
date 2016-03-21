//
//  Database.cpp
//  StudentDatabase
//
//  Created by Brett Meyer on 2/29/16.
//  Copyright © 2016 BDM. All rights reserved.
//

#include "Database.h"
#include <iostream>

Database::Database(int n)
{
    numStudents = n;
    vector <Student> students;
}

void Database::addStudent(Student s)
{
    students.push_back(s);
}

int Database::getNumStudents()
{
    return numStudents;
}

void Database::dataProcess(char c, int x)
{
    switch (c) {
        case 'h':
            std::cout<<"You can enter the following valid commands:\n";
            std::cout<<"n: Get number of student in the database\n";
            std::cout<<"c num: Get number of students who took course 'num'. Also prints student IDs\n";
            std::cout<<"g student_ID: Get GPA of student student_ID\n";
            std::cout<<"p num: Get number of students with GPA>num. Also print student IDs\n";
            std::cout<<"q: Quit\n";
            break;
        case 'n':
            std::cout<<numStudents<<endl;
            break;
        case 'c':
        {
            if (x < 100 || x > 999) {
                cout<<"Invalid Input"<<endl;
                break;
            }
            string studentIDs = "";
            int count = 0;
            Student * s = nullptr;
            for (int i = 0; i < students.size(); i++)
            {
                 s = &students.at(i);
                if (s->tookCourse(x)) {
                    count++;
                    studentIDs.append(std::to_string(s->Student::getId()));
                    studentIDs.append(" ");
                }
                s = nullptr;
            }
            std::cout<<count<< endl;
            if (count > 0) {
                std::cout<<studentIDs<<endl;
            }
            break;
        }
        case 'g':
            if (x < 10000 || x > 99999) {
                cout<<"Invalid Input"<<endl;
                break;
            }
            for (int i = 0; i < students.size(); i++)
            {
                Student s = students.at(i);
                if (s.Student::getId() == x) {
                    std::cout<<s.getGPA()<<endl;;
                    break;
                }
            }
            break;
        case 'p':
        {
            if (x < 0 || x > 4) {
                cout<<"Invalid Input"<<endl;
                break;
            }
            string studentIDs = "";
            int count = 0;
            for (int i = 0; i < students.size(); i++)
            {
                Student s = students.at(i);
                if (s.getGPA() >= x ) {
                    count++;
                    studentIDs.append(std::to_string(s.Student::getId()));
                    studentIDs.append(" ");
                }
            }
            std::cout<<count<< endl;
            if (count > 0) {
                std::cout<<studentIDs<<endl;
            }
            break;
        }
        case 'q':
            exit(0);
            break;
        default:
            break;
    }
}
