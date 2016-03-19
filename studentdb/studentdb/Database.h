#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <vector>
#include "Student.h"
using namespace std;

class Database{

  vector <Student> students;
  int numStudents;

 public:

  //Write your own constructor
  //param: number of students (initial size of database)
  Database(int);

  //add a new Student to the database
  //adds Student to end of the database (do not sort)
  void addStudent(Student);

  //returns the number of Students in the database
  int getNumStudents(void);

  //Process query the database for the specified information
  //param: command character
  //param: int value if required for the specified command
  void dataProcess(char, int);

};

#endif