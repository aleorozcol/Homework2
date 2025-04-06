#include "header3.h"

#include <sstream>
#include <iomanip>

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

Number::~Number(){}

Integer::Integer(int n){
    value = n;
}

int Integer::get_value() const {
    return value;
}

Number* Integer::sum(const Number& other) const {
    const Integer* cast = dynamic_cast<const Integer*>(& other);
    if (cast){
        return new Integer(value + cast->get_value());
    } else {
        throw invalid_argument("El tipo de dato no es compatible.\n");
    }
}

Number* Integer::subtraction(const Number& other) const {
    const Integer* cast = dynamic_cast<const Integer*>(& other);
    if (cast){
        return new Integer(value - cast->get_value());
    } else {
        throw invalid_argument("El tipo de dato no es compatible.\n");
    }    
}

Number* Integer::multiplication(const Number& other) const {
    const Integer* cast = dynamic_cast<const Integer*>(& other);
    if (cast){
        return new Integer(value * cast->get_value());
    } else {
        throw invalid_argument("El tipo de dato no es compatible.\n");
    }    
}

string Integer::toString() const {
    return to_string(value);
}

Real::Real(double n){
    value = n;
}

double Real::get_value() const {
    return value;
}

Number* Real::sum(const Number& other) const {
    const Real* cast = dynamic_cast<const Real*>(& other);
    if (cast){
        return new Real(value + cast->get_value());
    } else {
        throw invalid_argument("El tipo de dato no es compatible.\n");
    }
}

Number* Real::subtraction(const Number& other) const {
    const Real* cast = dynamic_cast<const Real*>(& other);
    if (cast){
        return new Real(value - cast->get_value());
    } else {
        throw invalid_argument("El tipo de dato no es compatible.\n");
    }    
}

Number* Real::multiplication(const Number& other) const {
    const Real* cast = dynamic_cast<const Real*>(& other);
    if (cast){
        return new Real(value * cast->get_value());
    } else {
        throw invalid_argument("El tipo de dato no es compatible.\n");
    }    
}


string Real::toString() const {
    ostringstream oss; // para cambiar de 6.500000 a 6.50
    oss << fixed << setprecision(2) << value;
    return oss.str();
}

Complex::Complex(double r, double i){
    real = r;
    imaginary = i;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imaginary() const {
    return imaginary;
}

Number* Complex::sum(const Number& other) const {
    const Complex* cast = dynamic_cast<const Complex*>(& other);
    if (cast){
        return new Complex(real + cast->get_real(), imaginary + cast->get_imaginary());
    } else {
        throw invalid_argument("El tipo de dato no es compatible.\n");
    }
}

Number* Complex::subtraction(const Number& other) const {
    const Complex* cast = dynamic_cast<const Complex*>(& other);
    if (cast){
        return new Complex(real - cast->get_real(), imaginary - cast->get_imaginary());
    } else {
        throw invalid_argument("El tipo de dato no es compatible.\n");
    }    
}

Number* Complex::multiplication(const Number& other) const {
    const Complex* cast = dynamic_cast<const Complex*>(& other);
    if (cast){
        double r = real * cast->get_real() - imaginary * cast->get_imaginary();
        double i = real * cast->get_imaginary() + imaginary * cast->get_real();
        return new Complex(r, i);
    } else {
        throw invalid_argument("El tipo de dato no es compatible.\n");
    }    
}

string Complex::toString() const {
    ostringstream oss; // para cambiar de 6.500000 a 6.50
    oss << fixed << setprecision(2) << real;
    if (imaginary >= 0)
        oss << " + " << fixed << setprecision(2) << imaginary << "i";
    else
        oss << " - " << fixed << setprecision(2) << -imaginary << "i";
    return oss.str();
}
