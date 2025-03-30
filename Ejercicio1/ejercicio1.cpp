#include "ejercicio.h"
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

class Time {
    private:
        int hour, min, sec;
        bool am_or_pm;

        bool is_it_valid (int h, int m, int s){
            return (h >= 0 && h <= 12) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59);
        }

        int modified_hour(int h){
            if (am_or_pm){
                return h;
            } else {
                return h+12;
            }
        }

        string is_it_am(bool am){
            if (am){
                return "a.m.";
            } else {
                return "p.m.";
            }
        }

    public:

        Time (int h = 0, int m = 0, int s = 0, bool am = true){
            if (!is_it_valid(h,m,s)) {
                throw invalid_argument("Alguno de los argumentos no respeta el rango de valores correspondientes.\n");
            }
            hour = h;
            min = m;
            sec = s;
            am_or_pm = am;
        } // constructor

        void get_time(){
            cout << "Tiempo: " << setw(2) << setfill('0') << hour << "h, "
                                             << setw(2) << setfill('0') << min << "m, "
                                             << setw(2) << setfill('0') << sec << "s "
                                             << is_it_am(am_or_pm) << endl;
        }

        void get_time_24(){
            cout << "Tiempo (24): " << setw(2) << setfill('0') << modified_hour(hour) << "h, "
                                             << setw(2) << setfill('0') << min << "m, "
                                             << setw(2) << setfill('0') << sec << "s " <<  endl;           
        }

        void set_hour(int h) {
            if (h < 0 || h > 12) throw invalid_argument("El número de horas no es válido.\n");
            hour = h;
        }
        void set_min(int m) {
            if (m < 0 || m > 59) throw invalid_argument("El número de minutos no es válido.\n");
            min = m;
        }
        void set_sec(int s) {
            if (s < 0 || s > 59) throw invalid_argument("El número de segundos no es válido.\n");
            sec = s;
        }
        void set_am_pm(bool am){
            am_or_pm = am;
        }

        int get_hour(){
            return hour;
        }
        int get_min(){
            return min;
        }
        int get_sec(){
            return sec;
        }
};


int main() {
    Time t1;
    cout << "Tiempo por defecto: " << endl;
    t1.get_time();
    t1.get_time_24();

    Time t2(3, 45, 30, false);
    cout << "Algún tiempo: " << endl;
    t2.get_time();
    t2.get_time_24();

    cout << "Tests: " << endl;
    int h, m, s;
    bool am;
    cout << "Ingrese la hora (0-12): ";
    cin >> h;
    cout << "Ingrese los minutos (0-59): ";
    cin >> m;
    cout << "Ingrese los segundos (0-59): ";
    cin >> s; 
    cout << "¿Es AM? (1=SI ; 0=NO): ";
    cin >> am;
    
    Time t3(h,m,s,am);
    cout << "Hora ingresada: " << endl;
    t3.get_time();
    t3.get_time_24();

}