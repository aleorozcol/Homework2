#include "source4.cpp"


/*
4. Se tiene una clase abstracta que representa una cuenta de banco genérica. 
Esta clase tiene los siguiente atributos y métodos:
i. balance: el total de la cuenta (tipo double).
ii. titularCuenta: nombre del dueño de la cuenta (string).
iii. depositar(): deposita una cantidad de dinero en la cuenta.
iv. retirar(): retira una cantidad de dinero de la cuenta (método virtual puro).
v. mostrarInfo(): muestra la información de la cuenta (método virtual puro) que consta del balance, 
el tipo de cuenta y el nombre del titular.
De esta clase se derivan dos subclases:
CajaDeAhorro:
• El método retirar() impide retirar más dinero del que existe en el balance.
• Se realizará un descuento de $20 del balance luego de mostrar más de 2 veces la información de la cuenta.
CuentaCorriente:
• El método retirar() permite retirar dinero de la caja de ahorro si no existen 
suficientes fondos en este tipo de cuenta.
• En caso de que la caja de ahorro tampoco tenga dinero, se imprimirá un aviso de 
que la cuenta no posee dinero. Utilizar friend para esto.
Se pide:
a. Establecer los especificadores de acceso (public, private y private) en los atributos y 
métodos de todas las clases, explicando su elección en función de la seguridad y la la 
flexibilidad para futuros requerimientos de cambio.
b. Escriba el código para implementar todas clases.
c. Escriba el código que permita probar los puntos mencionados para CajaDeAhorro y CuentaCorriente.
*/

void test_savings(BankAccount* savings_account){
    cout << "----Test de Caja de Ahorro----" << endl;
    savings_account->deposit(500);
    savings_account->show_info();
    savings_account->withdraw(100);
    savings_account->show_info();
    savings_account->show_info();
    savings_account->show_info();
    savings_account->show_info();
    savings_account->show_info();
    savings_account->withdraw(100);
    cout << "----Fin del test de Caja de Ahorro----" << endl;
}

void test_checking(BankAccount* savings_account){
    cout << "----Test de Cuenta Corriente----" << endl;
    unique_ptr<BankAccount> account = make_unique<CheckingAccount>("Alejandro Orozco");
    CheckingAccount* checking = dynamic_cast<CheckingAccount*>(account.get());
    SavingsAccount* savings = dynamic_cast<SavingsAccount*>(savings_account);
    if (!checking || !savings) {
        throw runtime_error("Error al crear la cuenta corriente o la cuenta de ahorros");
    }
    checking->set_savings_account(savings);
    account->deposit(500);
    account->show_info();
    account->withdraw(700);
    cout << "----Fin del test de Cuenta Corriente----" << endl;
}

int main() {
    try {
        unique_ptr<BankAccount> savings_account = make_unique<SavingsAccount>("Alejandro Orozco");
        savings_account->deposit(1000);
        test_savings(savings_account.get()); //usar .get() para obtener el raw pointer así la función trabaja tranquilamente y el smart pointer se encarga de liberar la memoria
        test_checking(savings_account.get());

    } catch (const std::exception& e) {
        cerr << "Error general: " << e.what() << endl;
    }

    return 0;
}