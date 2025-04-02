#include "ejercicio.h"
using namespace std;
/*
1. Programe una clase que permita expresar un determinado momento en el tiempo en
el siguiente formato: HHh, MMm, SSs p.m./a.m. Por ejemplo: “03h, 14m, 42s p.m.”.
Para este ejercicio, puede utilizar la librería iomanip con la funcionalidad provista por
setw y/o setfill.
Deberá ser capaz de:
a. Poder ser inicializada sin parámetros (en cuyo caso el tiempo es 0h, 0m, 0s a.m.)
b. Poder ser inicializada pasándole sólo la hora (en cuyo caso el tiempo es “HHh,
0m, 0s a.m.”).
c. Poder ser inicializada pasándole sólo la hora y los minutos (en cuyo caso el
tiempo es “HHh, MMm, 0s a.m.”)
d. Poder ser inicializada pasándole sólo la hora, los minutos y los segundos (en
cuyo caso el tiempo es “HHh, MMm, SSs a.m.”)
e. Poder ser inicializada pasándole la hora, los minutos, los segundos y
“p.m.”/”a.m.” (en cuyo caso el tiempo es “HHh, MMm, SSs p.m./a.m.”).
f. Agregar funcionalidad a los puntos 1.b-1.e de manera tal que no se introduzcan
valores fuera de los rangos (por ejemplo, es incorrecto introducir MM = 74).
g. Permitir cambiar y leer en forma individual: la hora, los minutos, los segundos y
si se trata de a.m. o p.m. También leer todo junto en el formato pedido.
h. Escribir un método que escriba por pantalla la hora en formato de hora 0 a 24,
donde no se utiliza “p.m.”/”a.m.”, por ejemplo, 13hs p.m. no es válido.
i. Escriba un código que permita verificar cada una de las funcionalidades pedidas
en 1.a-1.g. Para la verificación se deberá pedir que se interactúe con el
programa ingresando los datos por teclado. Por ejemplo, en el caso de ingresar
un valor erróneo, indicar esto por pantalla y permitir ingresar un nuevo valor o
bien permitir salir del programa.
*/
Time::Time() {
    set_hour(0);
    set_min(0);
    set_sec(0);
    set_am_pm(true);     
}
Time::Time (int h) {
    set_hour(h);
    set_min(0);
    set_sec(0);
    set_am_pm(true); 
}
Time::Time (int h, int m) {
    set_hour(h);
    set_min(m);
    set_sec(0);
    set_am_pm(true); 
}
Time::Time (int h, int m, int s) {
    set_hour(h);
    set_min(m);
    set_sec(s);
    set_am_pm(true); 
}
Time::Time(int h, int m, int s, bool am){
    set_hour(h);
    set_min(m);
    set_sec(s);
    set_am_pm(am);    
}

int Time::modified_hour(int h){
    return am_or_pm ? h : (h%12) + 12;
}
string Time::is_it_am(bool am){
    return am ? "a.m." : "p.m.";
}
void Time::get_time(){
    cout << setw(2) << setfill('0') << hour << "h, "
         << setw(2) << setfill('0') << min << "m, "
         << setw(2) << setfill('0') << sec << "s "
         << is_it_am(am_or_pm) << endl;
}

void Time::get_time_24(){
    cout << setw(2) << setfill('0') << modified_hour(hour) << "h, "
         << setw(2) << setfill('0') << min << "m, "
         << setw(2) << setfill('0') << sec << "s " <<  endl;           
}

void Time::set_hour(int h) {
    if (h < 0 || h > 12) throw invalid_argument("El número de horas no es válido.\n");
    hour = h;
}

void Time::set_min(int m) {
    if (m < 0 || m >= 60) throw invalid_argument("El número de minutos no es válido.\n");
    min = m;
}
void Time::set_sec(int s) {
    if (s < 0 || s >= 60) throw invalid_argument("El número de segundos no es válido.\n");
    sec = s;
}
void Time::set_am_pm(bool am){
    am_or_pm = am;
}
int Time::get_hour(){
    return hour;
}
int Time::get_min(){
    return min;
}
int Time::get_sec(){
    return sec;
}
bool Time::is_am() {
    return am_or_pm;
}



int main() {
    try{
        Time t1;
        cout << "Test a: " << endl;
        cout << "Formato 12h: ";
        t1.get_time();
        cout << "Formato 24h: ";
        t1.get_time_24();
        cout << endl; 
    } catch (const std::exception& e) {
        cerr << "Error en caso a: " << e.what() << endl;
    }
    try {
        Time t2(5);
        cout << "Test b: " << endl;
        cout << "Formato 12h: ";
        t2.get_time();
        cout << "Formato 24h: ";
        t2.get_time_24();
        cout << endl; 
    } catch (const std::exception& e) {
        cerr << "Error en caso b: " << e.what() << endl;
    }        
    try {
        Time t3(5, 30);
        cout << "Test c: " << endl;
        cout << "Formato 12h: ";
        t3.get_time();
        cout << "Formato 24h: ";
        t3.get_time_24();
        cout << endl; 
    } catch (const std::exception& e) {
        cerr << "Error en caso c: " << e.what() << endl;
    }
    try {
        Time t4(5, 30, 15);
        cout << "Test d: " << endl;
        cout << "Formato 12h: ";
        t4.get_time();
        cout << "Formato 24h: ";
        t4.get_time_24();
        cout << endl; 
    } catch (const std::exception& e) {
        cerr << "Error en caso d: " << e.what() << endl;
    }
    try {
        Time t5(5, 14, 43, false);
        cout << "Test e: " << endl;
        cout << "Formato 12h: ";
        t5.get_time();
        cout << "Formato 24h: ";
        t5.get_time_24();
        cout << endl; 
    } catch (const std::exception& e) {
        cerr << "Error en caso e: " << e.what() << endl;
    }
    try {
        Time t_errorHora(13, 0, 0); // Hora fuera de rango (0-12)
    } catch (const std::exception& e) {
        cerr << "Caso f) Error de rango en hora: " << e.what() << endl;
    }
    try {
        Time t_errorMin(12, 70, 0); // Minutos fuera de rango (0-59)
    } catch (const std::exception& e) {
        cerr << "Caso f) Error de rango en minuto: " << e.what() << endl;
    }
    try {
        Time t_errorSeg(12, 59, 70); // Segundos fuera de rango (0-59)
    } catch (const std::exception& e) {
        cerr << "Caso f) Error de rango en segundo: " << e.what() << endl;
    }
    cout << endl;
    try {
        Time t6; // Empezamos con 0h, 0m, 0s a.m.
        t6.set_hour(11);
        t6.set_min(59);
        t6.set_sec(10);
        t6.set_am_pm(false); // p.m.
        cout << "Caso g) Después de setear atributos" << endl;
        cout << "Formato 12h: ";
        t6.get_time();
        cout << "Formato 24h: ";
        t6.get_time_24();
        // Leer los valores individualmente
        cout << "Hora: " << t6.get_hour() << endl;
        cout << "Min: " << t6.get_min() << endl;
        cout << "Seg: " << t6.get_sec() << endl;
        cout << "¿AM? " << boolalpha << t6.is_am() << endl;
        cout << endl;
    } catch (const std::exception& e) {
        cerr << "Error en caso g: " << e.what() << endl;
    }
    return 0;
}