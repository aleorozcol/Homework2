#include "source2.cpp"

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

int main() {
    cout << "----Test----" << endl;
    cout << "Ingrese el nombre del curso: ";
    string course_name;
    cin.ignore();
    getline(cin, course_name);

    cout << "Ingrese la capacidad máxima: ";
    int max_capacity;
    cin >> max_capacity;

    vector<Student*> initial_list;
    Course myCourse(course_name, initial_list, max_capacity);

    int option;
    do {
        cout << "\n--- Menú ---\n";
        cout << "1. Inscribir alumno\n";
        cout << "2. Desinscribir alumno\n";
        cout << "3. Buscar alumno por legajo\n";
        cout << "4. Verificar si el curso está completo\n";
        cout << "5. Imprimir lista de estudiantes\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> option;

        if(option == 1) {
            string name;
            int id, num_courses;
            cout << "Ingrese el nombre completo del alumno: ";
            cin.ignore();
            getline(cin, name);
            cout << "Ingrese el legajo: ";
            cin >> id;
            cout << "Ingrese la cantidad de cursos a registrar: ";
            cin >> num_courses;
            vector<pair<string, float>> courses;
            for (int i = 0; i < num_courses; i++) {
                string c_name;
                float grade;
                cout << "Nombre del curso " << i+1 << ": ";
                cin >> c_name;
                cout << "Nota final: ";
                cin >> grade;
                courses.push_back(make_pair(c_name, grade));
            }
            Student* newStudent = new Student(name, id, courses);
            newStudent->calculate_average();
            try {
                myCourse.enroll_student(newStudent);
                cout << "Alumno inscripto.\n";
            } catch (runtime_error& e) {
                cout << e.what();
            }
        }
        else if(option == 2) {
            int id;
            cout << "Ingrese el legajo del alumno a desinscribir: ";
            cin >> id;
            try {
                myCourse.unenroll_student(id);
                cout << "Alumno desinscripto.\n";
            } catch(runtime_error& e) {
                cout << e.what();
            }
        }
        else if(option == 3) {
            int id;
            cout << "Ingrese el legajo del alumno a buscar: ";
            cin >> id;
            if(myCourse.find_student(id))
                cout << "El alumno está inscripto en el curso.\n";
            else
                cout << "Alumno no encontrado.\n";
        }
        else if(option == 4) {
            if(myCourse.is_it_full())
                cout << "El curso está completo.\n";
            else
                cout << "El curso no está completo.\n";
        }
        else if(option == 5) {
            myCourse.print_student_list();
        }
    } while(option != 6);

    return 0;
}
