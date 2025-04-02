#include "header4.h"

using namespace std;
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

BankAccount::BankAccount(string name){
    account_holder = name;
    balance = 0;
}

void BankAccount::deposit(double amount){
    if (amount < 0) throw runtime_error("Monto inválido.\n");
    balance+=amount;
    cout << "Se depositó: " << amount << endl;
    cout << "Estado actual de la cuenta: " << balance << endl;
}

BankAccount::~BankAccount(){}

SavingsAccount::SavingsAccount(string account_holder): BankAccount(account_holder), info_count(0) {}

void SavingsAccount::withdraw(double amount){
    if (amount > balance) throw runtime_error("No se puede retirar esta cantidad de dinero, se excede del balance.\n");
    balance-=amount;
    cout << "Se retiró de la Caja de Ahorro: " << amount << endl;
    cout << "Estado actual de la Caja de Ahorro: " << balance << endl;
}

void SavingsAccount::show_info() {
    info_count++;
    cout << "Información de la Caja de Ahorro" << endl;
    cout << "Titular: " << account_holder << endl;
    cout << "Balance: " << balance << endl;
    if (info_count > 2){
        balance -= 20;
        cout << "Se descontaron $20 por ver más de 2 veces la Caja de Ahorro." << endl;
        cout << "Estado actual de la Caja de Ahorro: " << balance << endl; 
    }
}

SavingsAccount::~SavingsAccount(){}

CheckingAccount::CheckingAccount(string account_holder): BankAccount(account_holder), savings(nullptr) {}

void CheckingAccount::show_info(){
    cout << "Información de la Cuente Corriente" << endl;
    cout << "Titular: " << account_holder << endl;
    cout << "Balance: " << balance << endl;
}

void CheckingAccount::set_savings_account(SavingsAccount* savings_account) {
    savings = savings_account;
    cout << "Se ha vinculado la Caja de Ahorro al titular: " << savings_account->account_holder << endl;
}

void CheckingAccount::withdraw(double amount){
    if (amount <= balance){
        balance -= amount;
        cout << "Se retiró de la Cuenta Corriente: " << amount << endl;
        cout << "Estado actual de la Cuenta Corriente: " << balance << endl;
    } else {
        double missing = amount - balance;
        if (missing <= savings->balance){
            double all_out = balance;
            balance = 0;
            savings->balance -= missing;
            cout << "Se retiró de la Cuenta Corriente: " << all_out << endl;
            cout << "Se retiró de la Caja de Ahorro: " << missing;
            cout << "Estado actual de la Cuenta Corriente: " << balance << endl;
            cout << "Estado actual de la Caja de Ahorro: " << savings->balance << endl;
        } else {
            throw runtime_error("La cuenta no posee fondos suficientes ni en Cuente Corriente ni en Caja de Ahorros.");
        }
    }
}

CheckingAccount::~CheckingAccount(){}