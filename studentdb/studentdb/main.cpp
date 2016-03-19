//
//  main.cpp
//  StudentDatabase
//
//  Created by Brett Meyer on 2/29/16.
//  Copyright © 2016 BDM. All rights reserved.
//

#include <iostream>
#include "Student.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Student s = Student::Student(1000,1);
    s.addStudentCourseInfo(302, 3, "AB");
    cout<<"HELLO";
    return 0;
}
