//
//  main.cpp
//  studentdb
//
//  Created by Brett Meyer on 3/19/16.
//  Copyright © 2016 BDM. All rights reserved.
//
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Student.h"
#include "Database.h"
using namespace std;

int main (int argc, char* argv[]) {
    //vars
    string line;
    int lineCounter = 0;
    int numStudents = 0;
    Database * db = NULL;
    Student * s = NULL;
    ifstream myfile;
    
    //get input file name
    myfile.open(argv[1]);
    
    //if file was successfully openned
    if (myfile.is_open())
    {
        //while not EOF
        while (getline(myfile,line))
        {
            // vars
            int sid = 0;
            int numCourses = 0;
            int courseid = 0;
            int credits = 0;
            string grade;
            //first line
            if (lineCounter == 0) {
                numStudents = atoi(line.c_str());
                db = new Database(numStudents);
            }
            
            //student id and num courses
            else if (lineCounter % 2 == 1)
            {
                
                stringstream ss(line);
                vector <int> arr;
                int temp;
                while (ss >> temp) {
                    arr.push_back(temp);
                }
                sid = arr.at(0);
                numCourses = arr.at(1);
                s = new Student(sid,numCourses);
            }
            
            //courses in order of course number, credits, grade
            else if (lineCounter % 2 == 0)
            {
                for (int i = 0; i < s->getNumCourses(); i++)
                {
                    stringstream ss(line);
                    vector <string> arr;
                    string temp;
                    while (ss >> temp) {
                        arr.push_back(temp);
                    }
                    for (int i = 0; i < arr.size(); i++) {
                        if (i % 3 == 0)
                        {
                            courseid = atoi(arr.at(i).c_str());
                        }
                        else if (i % 3 == 1)
                        {
                            credits = atoi(arr.at(i).c_str());
                        }
                        else if (i% 3 == 2)
                        {
                            grade = arr.at(i);
                            char *cstr = new char[grade.length() + 1];
                            strcpy(cstr, grade.c_str());
                            s->addStudentCourseInfo(courseid, credits, cstr) ;
                        }
                    }
                }
                //add student to database
                db->Database::addStudent(*s);

            }
            lineCounter = lineCounter + 1;
        }
        //close file
        myfile.close();
    }
    //unable to open file
    else
    {
        cout << "Unable to open file";
    }
    
    //loop ends on q from database
    while (true) {
        //vars
        string mystr;
        char option;
        int x;
        //handle input
        cout << ">";
        getline (cin, mystr);
        stringstream ss(mystr);
        vector <string> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(temp);
        }
        //if 2 values were inputed
        if (arr.size() == 2) {
            option = arr.at(0).at(0);
            option = tolower(option);
            x = atoi(arr.at(1).c_str());
            db->dataProcess(option, x);
        }
        //if 1 value was inputed
        else if (arr.size() == 1){
            option = arr.at(0).at(0);
            db->dataProcess(option, x);
        }
        //else do nothing
    }
    return 0;
}
