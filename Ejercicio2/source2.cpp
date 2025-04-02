#include "header2.h"
using namespace std;
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
    average = 0;
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

bool Student::operator<(const Student& other) const{
    return this->full_name < other.full_name;
}

ostream& operator<<(ostream& os, const Student& student){
    os << "Nombre: " << student.full_name
       << ", Legajo: " << student.student_id
       << ", Promedio: " << student.average;
    return os;
}


Course::Course(string name, vector<Student*> list, int max_students){
    course_name = name;
    student_list = list;
    max_capacity = max_students;
    current_capacity = list.size();
}


// Copy constructor: realiza una copia superficial.
// Se copia el nombre, el vector de punteros (compartiendo las mismas instancias de Student),
// el current_capacity y el max_capacity.
Course::Course(const Course& other) {
    course_name = other.course_name;
    student_list = other.student_list; // shallow copy
    current_capacity = other.current_capacity;
    max_capacity = other.max_capacity;
}

bool Course::find_student(int id){
    for (auto student : student_list){
        if (student->get_id() == id){
            return true;
        }
    }
    return false;        
}
bool Course::is_it_full() const{
    if (current_capacity == max_capacity) return true;
    return false;
}
void Course::enroll_student(Student* new_student){
    if (is_it_full()){
        throw runtime_error("El curso está completo. No fue posible inscribir al alumno/a.\n");
    }
    if (find_student(new_student->get_id())){
        throw runtime_error("Ya está inscripto.\n");
    }
    student_list.push_back(new_student);
    current_capacity++;
}
void Course::unenroll_student(int id){
    auto possible_student = student_list.begin();
    for (possible_student; possible_student != student_list.end(); ++possible_student){
        if ((*possible_student)->get_id() == id){
            student_list.erase(possible_student);
            current_capacity--;
            return;
        }
    }
    throw runtime_error("El alumno no pertenece al curso.\n");
}

void Course::print_student_list() const{
    vector<Student*> sorted_list = student_list;
    sort(sorted_list.begin(), sorted_list.end(), [](Student* a, Student* b) {
        return *a < *b;
    });
    cout << "Lista de estudiantes en " << course_name << ": " << endl;
    for (auto student: sorted_list){
        cout << *student << endl;
    }
}
