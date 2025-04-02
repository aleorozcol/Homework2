#include "source1.cpp"


int main() {
    try{
        Time t1;
        cout << "Test a: " << endl;
        cout << "Formato 12h: ";
        t1.get_time();
        cout << "Formato 24h: ";
        t1.get_time_24();
        cout << endl; 
    } catch (const exception& e) {
        cerr << "Error en test a: " << e.what() << endl;
    }
    try {
        Time t2(5);
        cout << "Test b: " << endl;
        cout << "Formato 12h: ";
        t2.get_time();
        cout << "Formato 24h: ";
        t2.get_time_24();
        cout << endl; 
    } catch (const exception& e) {
        cerr << "Error en test b: " << e.what() << endl;
    }        
    try {
        Time t3(5, 30);
        cout << "Test c: " << endl;
        cout << "Formato 12h: ";
        t3.get_time();
        cout << "Formato 24h: ";
        t3.get_time_24();
        cout << endl; 
    } catch (const exception& e) {
        cerr << "Error en test c: " << e.what() << endl;
    }
    try {
        Time t4(5, 30, 15);
        cout << "Test d: " << endl;
        cout << "Formato 12h: ";
        t4.get_time();
        cout << "Formato 24h: ";
        t4.get_time_24();
        cout << endl; 
    } catch (const exception& e) {
        cerr << "Error en test d: " << e.what() << endl;
    }
    try {
        Time t5(5, 14, 43, false);
        cout << "Test e: " << endl;
        cout << "Formato 12h: ";
        t5.get_time();
        cout << "Formato 24h: ";
        t5.get_time_24();
        cout << endl; 
    } catch (const exception& e) {
        cerr << "Error en test e: " << e.what() << endl;
    }
    try {
        Time t_errorHora(13, 0, 0); // Hora fuera de rango (0-12)
    } catch (const exception& e) {
        cerr << "Test f: Error de rango en hora: " << e.what() << endl;
    }
    try {
        Time t_errorMin(12, 70, 0); // Minutos fuera de rango (0-59)
    } catch (const exception& e) {
        cerr << "Test f: Error de rango en minuto: " << e.what() << endl;
    }
    try {
        Time t_errorSeg(12, 59, 70); // Segundos fuera de rango (0-59)
    } catch (const exception& e) {
        cerr << "Test f: Error de rango en segundo: " << e.what() << endl;
    }
    cout << endl;
    try {
        Time t6; // Empezamos con 0h, 0m, 0s a.m.
        t6.set_hour(11);
        t6.set_min(59);
        t6.set_sec(10);
        t6.set_am_pm(false); // p.m.
        cout << "Test g: Después de setear atributos" << endl;
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
    } catch (const exception& e) {
        cerr << "Error en test g: " << e.what() << endl;
    }
    return 0;
}