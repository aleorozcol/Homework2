#include "header1.h"
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
