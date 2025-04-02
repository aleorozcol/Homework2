#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
    private:
        string full_name;
        int student_id;
        vector<pair<string,float>> list_courses;
        float average;
          
    public:
        Student (string name, const int id, vector<pair<string,float>> courses);
        void calculate_average();
        float get_average();
        string get_full_name();
        int get_id();
};

class Course {
    private:
        string course_name;
        vector<Student*> student_list;
        int current_capacity;
        int max_capacity;
    public:
        Course(string name, vector<Student*> list, int max_students);
        bool find_student(Student mistery_student);
        bool is_it_full();
        void enroll_student(Student new_student);
        void unenroll_student(Student old_student);
        string print_student_list();
};
