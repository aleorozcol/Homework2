#include "source3.cpp"

using namespace std;

int main() {
    // Prueba con enteros
    Integer int1(5), int2(3);
    Number* sumaInt = int1.sum(int2);
    cout << "Suma Enteros: " << sumaInt->toString() << endl;
    delete sumaInt;

    // Prueba con reales
    Real real1(2.5), real2(4.2);
    Number* sumaReal = real1.sum(real2);
    cout << "Suma Reales: " << sumaReal->toString() << endl;
    delete sumaReal;

    // Prueba con complejos
    Complex comp1(3, 2), comp2(1, 7);
    Number* sumaComp = comp1.sum(comp2);
    cout << "Suma Complejos: " << sumaComp->toString() << endl;
    delete sumaComp;

    return 0;
}
