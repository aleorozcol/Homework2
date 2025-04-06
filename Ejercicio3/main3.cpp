#include "source3.cpp"

using namespace std;

int main() {
    cout << "---- Testing Numbers ----" << endl;
    cout << "---- Test Enteros ----" << endl;
    try {
        Number* a = new Integer(5);
        Number* b = new Integer(3);

        Number* sum_result = a->sum(*b);
        cout << "5 + 3 = " << sum_result->toString() << endl;
        delete sum_result;

        Number* sub_result = a->subtraction(*b);
        cout << "5 - 3 = " << sub_result->toString() << endl;
        delete sub_result;

        Number* mul_result = a->multiplication(*b);
        cout << "5 * 3 = " << mul_result->toString() << endl;
        delete mul_result;

        delete a;
        delete b;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl << "---- Test Reales ----" << endl;
    try {
        Number* a = new Real(2.5);
        Number* b = new Real(4.0);

        Number* sum_result = a->sum(*b);
        cout << "2.5 + 4.0 = " << sum_result->toString() << endl;
        delete sum_result;

        Number* sub_result = a->subtraction(*b);
        cout << "2.5 - 4.0 = " << sub_result->toString() << endl;
        delete sub_result;

        Number* mul_result = a->multiplication(*b);
        cout << "2.5 * 4.0 = " << mul_result->toString() << endl;
        delete mul_result;

        delete a;
        delete b;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl << "---- Test Complejos ----" << endl;
    try {
        Number* a = new Complex(1.0, 2.0); 
        Number* b = new Complex(3.0, -1.0);

        Number* sum_result = a->sum(*b);
        cout << "(1 + 2i) + (3 - 1i) = " << sum_result->toString() << endl;
        delete sum_result;

        Number* sub_result = a->subtraction(*b);
        cout << "(1 + 2i) - (3 - 1i) = " << sub_result->toString() << endl;
        delete sub_result;

        Number* mul_result = a->multiplication(*b);
        cout << "(1 + 2i) * (3 - 1i) = " << mul_result->toString() << endl;
        delete mul_result;

        delete a;
        delete b;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl << "----Testing Numbers Finalizó----" << endl;
    return 0;
}
