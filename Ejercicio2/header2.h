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
        bool operator<(const Student& other) const;
        friend ostream& operator<<(ostream& os, const Student& student); // se usa friend para imprimir atributos privados
};

class Course {
    private:
        string course_name;
        vector<Student*> student_list;
        int current_capacity;
        int max_capacity;
    public:
        Course(string name, vector<Student*> list, int max_students);
        
        // Copy constructor: realizamos una copia superficial.
        // Dado que el curso sólo contiene punteros a objetos Student y estos pueden existir de forma independiente,
        // una copia superficial (shallow copy) es suficiente para compartir la misma instancia de cada estudiante.
        Course(const Course& other);

        bool find_student(int student_id);
        bool is_it_full() const;
        void enroll_student(Student* new_student);
        void unenroll_student(int student_id);
        void print_student_list() const;
        
};
