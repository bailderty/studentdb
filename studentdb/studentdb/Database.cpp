//
//  Database.cpp
//  StudentDatabase
//
//  Created by Brett Meyer on 2/29/16.
//  Copyright © 2016 BDM. All rights reserved.
//

/* 
h: displays list of available commands to the user
n: displays the number of students currently in the database
c num:displays the number of students who took course 'num'. It also prints the student id numbers of those students.
g student_id: displays the GPA of student with student id number given
p num: displays the number of students with a GPA greater than 'num'. It also prints the student id numbers of those students.
q: will exit the program
 */
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
            string studentIDs = "";
            int count = 0;
            for (int i = 0; i < students.size(); i++)
            {
                Student s = students.at(i);
                if (s.tookCourse(x)) {
                    count++;
                    studentIDs.append(std::to_string(s.Student::getId()));
                    studentIDs.append(" ");
                }
            }
            std::cout<<count<< endl;
            std::cout<<studentIDs<<endl;
            break;
        }
        case 'g':
            for (int i = 0; i < students.size(); i++)
            {
                Student s = students.at(i);
                if (s.Student::getId() == x) {
                    std::cout<<s.getGPA();
                    break;
                }
            }
            break;
        case 'p':
        {
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
            std::cout<<studentIDs<<endl;
            break;
        }
        case 'q':
            exit(0);
            break;
        default:
            break;
    }
}
