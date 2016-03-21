//
//  Database.cpp
//  StudentDatabase
//
//  Created by Brett Meyer on 2/29/16.
//  Copyright © 2016 BDM. All rights reserved.
//

#include "Database.h"
#include <iostream>

//Constructor
Database::Database(int n)
{
    numStudents = n;
    vector <Student> students;
}

//Parameter Student
//add student to database
void Database::addStudent(Student s)
{
    students.push_back(s);
}

//return number of students in database
int Database::getNumStudents()
{
    return numStudents;
}
//parameters char , int
//handle access to database
void Database::dataProcess(char c, int x)
{
    switch (c) {
        //display options
        case 'h':
            std::cout<<"You can enter the following valid commands:\n";
            std::cout<<"n: Get number of student in the database\n";
            std::cout<<"c num: Get number of students who took course 'num'. Also prints student IDs\n";
            std::cout<<"g student_ID: Get GPA of student student_ID\n";
            std::cout<<"p num: Get number of students with GPA>num. Also print student IDs\n";
            std::cout<<"q: Quit\n";
            break;
        //print number of students in database
        case 'n':
            std::cout<<numStudents<<endl;
            break;
        //print number of students that took course with course number x
        case 'c':
        {
            //check for valid range
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
            //print to screen
            std::cout<<count<< endl;
            if (count > 0) {
                std::cout<<studentIDs<<endl;
            }
            break;
        }
        //print student gpa
        case 'g':
            //check for valid range
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
        //print students with gpa higher than x
        case 'p':
        {
            //check for valid range
            if (x < 0 || x > 4) {
                cout<<"Invalid Input"<<endl;
                break;
            }
            string studentIDs = "";
            int count = 0;
            for (int i = 0; i < students.size(); i++)
            {
                Student s = students.at(i);
                if (s.getGPA() > x ) {
                    count++;
                    studentIDs.append(std::to_string(s.Student::getId()));
                    studentIDs.append(" ");
                }
            }
            //print to screen
            std::cout<<count<< endl;
            if (count > 0) {
                std::cout<<studentIDs<<endl;
            }
            break;
        }
        //quit program
        case 'q':
            exit(0);
            break;
        default:
            break;
    }
}
