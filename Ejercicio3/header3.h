#pragma once

#include <iostream>
#include <string>

using namespace std;

/*
3. Escriba una interfaz llamada “Numero” que indique la implementación de las operaciones suma, 
resta y multiplicación de números (si desea, puede también agregar la división), 
así como también un método denominado “toString” que muestra el número en formato string.
a. De esta interfaz, se deben implementar las siguientes tres clases:
• Clase “Entero”,
• Clase “Real”,
• Clase “Complejo”
b. Verifique el funcionamiento de cada uno de estas clases mediante la implementación 
de cada una de las operaciones con los números que desee e imprima el resultado 
utilizando el método “toString”.
*/

class Number {
    public:
        virtual Number* sum(const Number& other) const = 0;
        virtual Number* subtraction(const Number& other) const = 0;
        virtual Number* multiplication(const Number& other) const = 0;
        virtual string toString() const = 0;
        virtual ~Number();
};

class Integer : public Number {
    private: 
        int value;
    public:
        Integer(int n);
        int get_value() const;
        virtual Number* sum(const Number& other) const override;
        virtual Number* subtraction(const Number& other) const override;
        virtual Number* multiplication(const Number& other) const override;
        virtual string toString() const override;
};

class Real : public Number {
    private: 
        double value;
    public:
        Real(double n);
        double get_value() const;
        virtual Number* sum(const Number& other) const override;
        virtual Number* subtraction(const Number& other) const override;
        virtual Number* multiplication(const Number& other) const override;
        virtual string toString() const override;
};

class Complex : public Number {
    private: 
        double real;
        double imaginary;
    public:
        Complex(double r, double i);
        double get_real() const;
        double get_imaginary() const;
        virtual Number* sum(const Number& other) const override;
        virtual Number* subtraction(const Number& other) const override;
        virtual Number* multiplication(const Number& other) const override;
        virtual string toString() const override;
};