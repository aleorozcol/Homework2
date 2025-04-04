#include "source1.cpp"

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

int main() {
    try {
        cout << "----Testing Time----" << endl;
        cout << "Desea ingresar la hora? (1: Si, 0: No): ";
        bool choice1;
        cin >> choice1;
        if (!choice1) {
            Time t1;
            cout << "Momento en el tiempo por defecto: ";
            t1.get_time();
            return 0;
        } 
        cout << "Ingrese la hora (0-12): ";
        int hour;
        cin >> hour;
        cout << "Desea ingresar los minutos? (1: Si, 0: No): ";
        bool choice2;
        cin >> choice2;
        if (!choice2){
            Time t2(hour);
            cout << "Momento en el tiempo: ";
            t2.get_time();
            return 0;
        }
        cout << "Ingrese los minutos (0-59): ";
        int min;
        cin >> min;
        cout << "Desea ingresar los segundos? (1: Si, 0: No): ";
        bool choice3;
        cin >> choice3; 
        if (!choice3){
            Time t3(hour, min);
            cout << "Momento en el tiempo: ";
            t3.get_time();
            return 0;
        }
        cout << "Ingrese los segundos (0-59): ";
        int sec;
        cin >> sec;
        cout << "Desea ingresar AM o PM? (1: Si, 0: No): ";
        bool choice4;
        cin >> choice4; 
        if (!choice4){
            Time t4(hour, min, sec);
            cout << "Momento en el tiempo: ";
            t4.get_time();
            return 0;
        }
        cout << "Ingrese 1 para AM o 0 para PM: ";
        bool am_pm;
        cin >> am_pm;
        Time t5(hour, min, sec, am_pm);
        cout << "Momento en el tiempo: ";
        t5.get_time();
        cout << "Desea ver el formato 24h? (1: Si, 0: No): ";
        bool choice5;
        cin >> choice5;
        if (choice5){
            cout << "Formato 24h: ";
            t5.get_time_24();
        }
        cout << endl;
        cout << "Desea cambiar la hora? (1: Si, 0: No): ";
        bool choice6;
        cin >> choice6;
        if (choice6){
            cout << "Ingrese la nueva hora (0-12): ";
            int new_hour;
            cin >> new_hour;
            t5.set_hour(new_hour);
        }
        cout << "Desea cambiar los minutos? (1: Si, 0: No): ";  
        bool choice7;
        cin >> choice7;
        if (choice7){
            cout << "Ingrese los nuevos minutos (0-59): ";
            int new_min;
            cin >> new_min;
            t5.set_min(new_min);
        }
        cout << "Desea cambiar los segundos? (1: Si, 0: No): ";
        bool choice8;
        cin >> choice8;
        if (choice8){
            cout << "Ingrese los nuevos segundos (0-59): ";
            int new_sec;
            cin >> new_sec;
            t5.set_sec(new_sec);
        }
        cout << "Desea cambiar AM o PM? (1: Si, 0: No): ";
        bool choice9;
        cin >> choice9;
        if (choice9){
            cout << "Ingrese 1 para AM o 0 para PM: ";
            bool new_am_pm;
            cin >> new_am_pm;
            t5.set_am_pm(new_am_pm);
        }
        cout << "Momento en el tiempo actualizado: ";
        t5.get_time();
        cout << "Formato 24h actualizado: ";
        t5.get_time_24();
        cout << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    cout << "----Testing Time Finalizó----" << endl;
    return 0;
}