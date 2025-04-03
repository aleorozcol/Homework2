#include "header3.h"

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
    
}

