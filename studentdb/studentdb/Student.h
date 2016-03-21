#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>
using namespace std;

struct Coursetype{
  int courseNum;
  int credits;
  string grade;
};

class Student{


    int studentID;                   // the student's ID number
    int nCourses;                    // the number of courses for this student
    vector <Coursetype> Courses;     // course list for this student
    float gpa;                       // the GPA for this student (from all courses)


  public:

    //Write your own constructor by appropriately initializing class variables
    // parameters: student id and the number of courses
    Student(int, int);

    //Returns the final GPA of the student
    float getGPA();

    //Returns the number of courses taken by the student
    int getNumCourses();

    // Add course info for this student
    // parameters: course number, credits, letter grade (1 or 2 character)
    void addStudentCourseInfo(int, int, char* );

    //returns true or false depending on whether the student took the course or not.
    // parameter: the course number
    bool tookCourse(int courseNumber);

    int getId(void);
    
    //void print();
  };
#endif