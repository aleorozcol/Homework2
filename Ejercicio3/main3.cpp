#include "source3.cpp"

using namespace std;

int main() {
    cout << "==== Test de Integer ====" << endl;
    {
        Number* a = new Integer(5);
        Number* b = new Integer(3);

        // Suma
        Number* sumResult = a->sum(*b);
        cout << "5 + 3 = " << sumResult->toString() << endl;
        delete sumResult;

        // Resta
        Number* subResult = a->subtraction(*b);
        cout << "5 - 3 = " << subResult->toString() << endl;
        delete subResult;

        // Multiplicación
        Number* mulResult = a->multiplication(*b);
        cout << "5 * 3 = " << mulResult->toString() << endl;
        delete mulResult;

        // Limpieza
        delete a;
        delete b;
    }

    cout << endl << "==== Test de Real ====" << endl;
    {
        Number* x = new Real(2.5);
        Number* y = new Real(4.0);

        // Suma
        Number* sumResult = x->sum(*y);
        cout << "2.5 + 4.0 = " << sumResult->toString() << endl;
        delete sumResult;

        // Resta
        Number* subResult = x->subtraction(*y);
        cout << "2.5 - 4.0 = " << subResult->toString() << endl;
        delete subResult;

        // Multiplicación
        Number* mulResult = x->multiplication(*y);
        cout << "2.5 * 4.0 = " << mulResult->toString() << endl;
        delete mulResult;

        // Limpieza
        delete x;
        delete y;
    }

    cout << endl << "==== Test de Complex ====" << endl;
    {
        Number* c1 = new Complex(1.0, 2.0); // 1 + 2i
        Number* c2 = new Complex(3.0, -1.0); // 3 - 1i

        // Suma: (1 + 2i) + (3 - 1i) = (4 + 1i)
        Number* sumResult = c1->sum(*c2);
        cout << "(1 + 2i) + (3 - 1i) = " << sumResult->toString() << endl;
        delete sumResult;

        // Resta: (1 + 2i) - (3 - 1i) = (-2 + 3i)
        Number* subResult = c1->subtraction(*c2);
        cout << "(1 + 2i) - (3 - 1i) = " << subResult->toString() << endl;
        delete subResult;

        // Multiplicación: (1 + 2i)*(3 - 1i) = (1*3 + 1* -1i + 2i*3 + 2i*-1i)
        //                  = 3 - 1i + 6i - 2i^2 = 3 + 5i + 2 (porque i^2 = -1) = 5 + 5i
        Number* mulResult = c1->multiplication(*c2);
        cout << "(1 + 2i) * (3 - 1i) = " << mulResult->toString() << endl;
        delete mulResult;

        // Limpieza
        delete c1;
        delete c2;
    }

    cout << endl << "==== Fin de Pruebas ====" << endl;
    return 0;
}
