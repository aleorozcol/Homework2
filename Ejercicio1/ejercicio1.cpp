#include <iostream>
#include <iomanip>
#include <string>
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

class Time {
    private:
        int hour, min, sec;
        bool am_or_pm;

        bool is_it_valid (int h, int m, int s){
            return (h >= 0 && h <= 12) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59);
        }

    public:

        int hour, min, sec;
        bool am_or_pm;

        Time (int h = 0, int m = 0, int s = 0, bool am = true){
            if (!is_it_valid(h,m,s)) {
                throw invalid_argument("Alguno de los argumentos no respeta el rango de valores correspondientes.");
            }
            hour = h;
            min = m;
            sec = s;
            am_or_pm = am;
        } // constructor

        string is_it_am(bool am){
            if (am){
                return "a.m.";
            } else {
                return "p.m.";
            }
        }

        string get_time(){
            cout << "Momento en el tiempo: " << setw(2) << setfill('0') << hour << "h, "
                                             << setw(2) << setfill('0') << min << "m, "
                                             << setw(2) << setfill('0') << sec << "s "
                                             << is_it_am(am_or_pm) << endl;
        }
};


int main() {

}