#include "header2.h"
using namespace std;
/*
c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?
La relación entre estos dos objetos es de agregación, ya que un curso "has-a" (tiene)
una lista de estudiantes, pero los estudiantes pueden existir independientemente de los cursos.
Si se destruye un curso, los estudinates siguen existiendo y pueden estar asociados a otros cursos.
En este caso, el todo mantiene una relación con las partes, pero sin una dependencia total: el ciclo de vida de un
objeto no depende del otro.
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


Course::Course(string name, vector<shared_ptr<Student>> list, int max_students){
    course_name = name;
    student_list = list;
    max_capacity = max_students;
    current_capacity = list.size();
}


/*
Utilizo shallow copy porque los cursos comparten punteros a los estudiantes.
Entonces, cada estudiante se mantiene en un único lugar de memoria y varios
objetos curso pueden apuntar a ellos. También, si un estudiante se modifica,
todos los cursos que están relacionados a este verán el cambio.
Si se hace una deep copy, se duplicarían los estudiantes y
se perdería la relación entre los cursos y los estudiantes.
*/
Course::Course(const Course& another_course) {
    course_name = another_course.course_name;
    student_list = another_course.student_list; //shallow copy
    current_capacity = another_course.current_capacity;
    max_capacity = another_course.max_capacity;
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
void Course::enroll_student(shared_ptr<Student> new_student){
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
    for (auto possible_student = student_list.begin(); possible_student != student_list.end(); ++possible_student){
        if ((*possible_student)->get_id() == id){
            student_list.erase(possible_student);
            current_capacity--;
            return;
        }
    }
    throw runtime_error("El alumno no pertenece al curso.\n");
}

void Course::print_student_list() const{
    vector<shared_ptr<Student>> sorted_list = student_list;
    sort(sorted_list.begin(), sorted_list.end(), [](shared_ptr<Student> a, shared_ptr<Student> b) {
        return *a < *b;
    });
    cout << "Lista de estudiantes en " << course_name << ": " << endl;
    for (auto student: sorted_list){
        cout << *student << endl;
    }
}
