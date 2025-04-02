#include "source2.cpp"

///////////funciona mal
int main() {
    vector<Student*> initial_list;
    // Se crea un curso con capacidad máxima de 20 estudiantes.
    Course myCourse("Matemáticas", initial_list, 20);
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
                string course_name;
                float grade;
                cout << "Ingrese el nombre del curso " << i+1 << ": ";
                cin >> course_name;
                cout << "Ingrese la nota final: ";
                cin >> grade;
                courses.push_back(make_pair(course_name, grade));
            }
            Student* newStudent = new Student(name, id, courses);
            newStudent->calculate_average();
            try {
                myCourse.enroll_student(newStudent);
                cout << "Alumno inscripto con éxito.\n";
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
                cout << "Alumno desinscripto con éxito.\n";
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
                cout << "Alumno no encontrado en el curso.\n";
        }
        else if(option == 4) {
            if(myCourse.is_it_full())
                cout << "El curso está completo.\n";
            else
                cout << "El curso NO está completo.\n";
        }
        else if(option == 5) {
            myCourse.print_student_list();
        }
    } while(option != 6);
    
    // Liberar memoria de los estudiantes inscriptos (en una aplicación real se debe gestionar la vida de los objetos)
    // NOTA: Dado que el curso no es dueño de los objetos Student, se debe decidir dónde se libera la memoria.
    
    return 0;
}