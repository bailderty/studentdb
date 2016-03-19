//
//  Database.cpp
//  StudentDatabase
//
//  Created by Brett Meyer on 2/29/16.
//  Copyright © 2016 BDM. All rights reserved.
//

#include "Database.h"

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
    
}
