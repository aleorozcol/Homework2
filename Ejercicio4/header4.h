#pragma once

#include <iostream>
#include <string>

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

class BankAccount {
    public:
        BankAccount(string account_holder);
        virtual void deposit(double amount);
        virtual void withdraw(double amount) = 0;
        virtual void show_info() = 0;
        virtual ~BankAccount();

    protected:
        double balance;
        string account_holder;
};

class SavingsAccount : public BankAccount {
    public:
        SavingsAccount(string account_holder);
        void withdraw(double amount) override;
        void show_info() override; 
        virtual ~SavingsAccount();
    private:
        int info_count; 
        friend class CheckingAccount;     

};

class CheckingAccount : public BankAccount {
    public:
        CheckingAccount(string account_holder);
        void withdraw(double amount) override;
        void set_savings_account(SavingsAccount* savings_account);
        void show_info() override;
        virtual ~CheckingAccount();
    private:
        SavingsAccount* savings;
};