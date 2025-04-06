#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
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
        bool operator<(const Student& other) const;
        friend ostream& operator<<(ostream& os, const Student& student); // se usa friend para imprimir atributos privados
};

class Course {
    private:
        string course_name;
        vector<shared_ptr<Student>> student_list;
        int current_capacity;
        int max_capacity;
    public:
        Course(string name, vector<shared_ptr<Student>> list, int max_students);
        // constructor de la copia
        Course(const Course& other);

        bool find_student(int student_id);
        bool is_it_full() const;
        void enroll_student(shared_ptr<Student> new_student);
        void unenroll_student(int student_id);
        void print_student_list() const;
        
};
