#include "ejercicio2.h"
/*
2. Escribir una clase denominada Curso que contiene un vector (std::vector) con
punteros a objetos estudiantes. 
a. El objeto estudiante simplemente cuenta con el nombre completo, su legajo
(que es único por alumno), una lista de cursos con su nota final y los métodos
que crea necesarios para obtener los datos del alumno: nombre completo,
legajo y su promedio general. En función de esto, califique todos los atributos
correctamente.
b. Como se mencionó anteriormente, un objeto de la clase Curso contendrá la lista
de estudiantes del curso (el vector conteniendo objetos tipo estudiante). La
clase Curso permite:
i. Inscribir y desinscribir estudiantes al curso.
ii. Ver si un estudiante se encuentra inscripto o no en el curso buscándolo por
su legajo.
iii. Indicar si el curso está completo o no, teniendo en cuenta que el curso tiene
una capacidad de 20 alumnos.
iv. Imprimir la lista de estudiantes en orden alfabético. Para ello, utilice el
algoritmo std::sort() en <algorithm>, el cual requerirá sobreescribir el
operador “<”, y sobreescriba el operador “<<” (del método y clase que
correspondan) para presentar los datos por pantalla.
v. Dado que algunos cursos comparten la mayor parte de los estudiantes, se
desea poder hacer una copia del objeto curso. Justifique su respuesta con
un comentario en el código (esta puede llevar varias líneas), indicando de
que tipo de copia se trata y como la hizo.
c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?
d. Proporcione un menú que permita evaluar lo pedido en este ejercicio. 
*/


Student::Student (string name, const int id, vector<pair<string,float>> courses){
    full_name = name;
    student_id = id;
    list_courses = courses;
}
void Student::calculate_average(){
    if(list_courses.empty()){
        average = 0;
        return;
    }
    float sum_grades = 0;
    for (auto course : list_courses){
        sum_grades += course.second;
    }
    average = sum_grades / list_courses.size();
}
float Student::get_average(){
    return average;
}
string Student::get_full_name(){
    return full_name;
}
int Student::get_id(){
    return student_id;
}


Course::Course(string name, vector<Student*> list, int max_students){
    course_name = name;
    student_list = list;
    max_capacity = max_students;
}
bool Course::find_student(Student mistery_student){
    for (auto student : student_list){
        if (student->get_id() == mistery_student.get_id()){
            return true;
        }
    }
    return false;        
}
bool Course::is_it_full(){
    if (current_capacity == max_capacity) return true;
    return false;
}
void Course::enroll_student(Student new_student){
    if (is_it_full()){
        throw runtime_error("El curso está completo. No fue posible inscribir al alumno/a.\n");
    }
    for (auto student : student_list){
        if (student->get_id() == new_student.get_id()){
            throw runtime_error("Ya está inscripto en el curso.\n");
        }
    }
    student_list.push_back(&new_student);
    current_capacity++;
}
void Course::unenroll_student(Student old_student){
    auto possible_student = student_list.begin();
    for (possible_student; possible_student != student_list.end(); ++possible_student){
        if ((*possible_student)->get_id() == old_student.get_id()){
            student_list.erase(possible_student);
            current_capacity--;
            return;
        }
    }
    throw runtime_error("El alumno no pertenece al curso.\n");
}

string Course::print_student_list(){
    auto each_student = student_list.begin();
    for (each_student; each_student != student_list.end(); ++each_student){
        
    } 
}
