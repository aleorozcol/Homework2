#include "source4.cpp"

int main() {
    try {
        // 1. Crear objetos
        SavingsAccount mySavings("Bob");
        CheckingAccount myChecking("Bob");

        // 2. Probar depósitos
        cout << "==== Depositar en Caja de Ahorro (Bob) ====" << endl;
        mySavings.deposit(200.0); // Debe incrementar el balance a 200
        cout << endl;

        cout << "==== Depositar en Cuenta Corriente (Bob) ====" << endl;
        myChecking.deposit(100.0); // Debe incrementar el balance a 100
        cout << endl;

        // 3. Mostrar información inicial
        cout << "==== Info de Caja de Ahorro ====" << endl;
        mySavings.show_info(); // Primera visualización
        cout << endl;

        cout << "==== Info de Cuenta Corriente ====" << endl;
        myChecking.show_info();
        cout << endl;
        
        // 4. Intentar retiros
        cout << "==== Retirar 50 de la Cuenta Corriente (Bob) ====" << endl;
        myChecking.withdraw(50.0); 
        cout << endl;

        cout << "==== Retirar 250 de la Caja de Ahorro (Alice) (Error) ====" << endl;
        // Este retiro excede el balance de 200 y lanzará una excepción
        try {
            mySavings.withdraw(250.0); 
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
        cout << endl;

        // 5. Mostrar info nuevamente para corroborar balance
        cout << "==== Info de Caja de Ahorro (segunda visualización) ====" << endl;
        mySavings.show_info(); 
        cout << endl;

        // 6. Realizar un retiro válido en la Caja de Ahorro
        cout << "==== Retirar 50 de la Caja de Ahorro (Alice) ====" << endl;
        mySavings.withdraw(50.0); 
        cout << endl;

        // 7. Vincular Caja de Ahorro a Cuenta Corriente y hacer retiro que use ambos fondos
        cout << "==== Vincular Caja de Ahorro a Cuenta Corriente ====" << endl;
        // Llamamos al método (si lo has hecho público) o lo hacemos dentro de checkings
        // myChecking.set_savings_account(&mySavings); // si set_savings_account es público
        // O, si deseas, haz la lógica en tu constructor.

        // 8. Probar retiro que exceda saldo en Cuenta Corriente y tome el resto de la Caja de Ahorro
        cout << "==== Retirar 80 de la Cuenta Corriente (Bob) (se completará usando Ahorros) ====" << endl;
        try {
            myChecking.set_savings_account(&mySavings); // Vincular la cuenta de ahorros
            myChecking.withdraw(80.0); // Retiro que usa fondos de ambas cuentas
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
        cout << endl;

        // 9. Mostrar información varias veces en la Caja de Ahorro para forzar el descuento de $20
        cout << "==== Info de Caja de Ahorro (tercera visualización) ====" << endl;
        mySavings.show_info(); // Tercera vez -> se descuenta $20
        cout << endl;

        cout << "==== Info de Caja de Ahorro (cuarta visualización) ====" << endl;
        mySavings.show_info(); 
        cout << endl;

        // 10. Mostrar estado final de ambas cuentas
        cout << "==== Info final de Cuenta Corriente (Bob) ====" << endl;
        myChecking.show_info();
        cout << endl;

        cout << "==== Info final de Caja de Ahorro (Alice) ====" << endl;
        mySavings.show_info();
        cout << endl;

    } catch (const std::exception& e) {
        cerr << "Error general: " << e.what() << endl;
    }

    return 0;
}