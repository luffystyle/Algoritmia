#include <iostream>
#include <cstring>

using namespace std;

// Función para resolver el problema de los paréntesis
void resolverParentesis(int posicionActual, int izquierdaTotal, int derechaTotal, int izquierdaEliminar, int derechaEliminar, int longitudCadena, char* cadena, int* arregloSolucion);

int main() {
    int longitudCadena;
    //cout << "Ingresar cantidad de caracteres a leer: ";
    //cin >> longitudCadena;

    // Crear una matriz dinámica para almacenar la cadena
    //char* cadena = new char[longitudCadena + 1];

    //cout << "Ingresar cadena: ";
    //for (int i = 0; i < longitudCadena + 1; i++) {
    //    cin >> cadena[i];
    //}
    longitudCadena=16;
    char* cadena = new char[longitudCadena + 1];
    strcpy(cadena,"(2+6)+(1))-(3*2)");
    
    //longitudCadena=12;
    //strcpy(cadena,"((2+3)*(4-8)");
    //cadena={"(","2","+","6",")","+","(","1",")",")","-","(","3","*","2",")","\n"};

    cout << "Se leyó la cadena: ";
    for (int i = 0; i < longitudCadena + 1; i++) {
        cout << cadena[i];
    }

    // Crear una matriz dinámica para almacenar la solución
    int* arregloSolucion = new int[longitudCadena + 1];

    int izquierda = 0;
    int derecha = 0;
    for (int i = 0; i < longitudCadena + 1; i++) {
        if (cadena[i] == '(') {
            izquierda++;
        } else if (cadena[i] == ')') {
            // Incrementar "derecha" solo si hay un "izquierda" correspondiente
            derecha = ((izquierda == 0) ? (derecha + 1) : derecha);
            // Decrementar "izquierda" si encontramos un "derecha" correspondiente
            izquierda = ((izquierda > 0) ? (izquierda - 1) : izquierda);
        }
    }

    // Llamar a la función para resolver el problema
    resolverParentesis(0, 0, 0, izquierda, derecha, longitudCadena, cadena, arregloSolucion);

    // Liberar la memoria de las matrices dinámicas
    delete[] cadena;
    delete[] arregloSolucion;

    return 0;
}


// Función para resolver el problema de los paréntesis
//posicionActual: posición en la cadena que estamos analizando. A medida que la función se llama recursivamente, esta posición se actualiza para recorrer la cadena desde el principio hasta el final.
//izquierdaTotal: Lleva un registro de la cantidad total de paréntesis izquierdos ('(') encontrados hasta el momento en el proceso de exploración de la cadena. Esto ayuda a determinar si es posible agregar un paréntesis izquierdo adicional en una posición dada.
//derechaTotal: Similar a izquierdaTotal, lleva un registro de la cantidad total de paréntesis derechos (')') encontrados hasta el momento en el proceso de exploración de la cadena. Esto ayuda a determinar si es posible agregar un paréntesis derecho adicional en una posición dada.
//izquierdaEliminar: Indica cuántos paréntesis izquierdos deben eliminarse en la cadena para alcanzar una solución válida. Este valor disminuye cuando se elimina un paréntesis izquierdo de manera que la función no lo considere nuevamente.
//derechaEliminar: Indica cuántos paréntesis derechos deben eliminarse en la cadena para alcanzar una solución válida. Este valor disminuye cuando se elimina un paréntesis derecho de manera que la función no lo considere nuevamente.
//longitudCadena: La longitud total de la cadena que se está analizando. Este valor se utiliza para determinar cuándo se ha llegado al final de la cadena y se debe verificar si se ha encontrado una solución válida.
//adena: La cadena de entrada que se está analizando. Se utiliza para acceder a los caracteres individuales de la cadena en la posición actual y para marcar los caracteres como parte de la solución.
//arregloSolucion: Un arreglo que se utiliza para llevar un registro de qué caracteres de la cadena están marcados como parte de la solución. Si arregloSolucion[i] es 1, significa que el carácter en la posición i de la cadena está marcado como parte de la solución; si es 0, no lo está.
void resolverParentesis(int posicionActual, int izquierdaTotal, int derechaTotal, int izquierdaEliminar, int derechaEliminar, int longitudCadena, char* cadena, int* arregloSolucion) {
    if (posicionActual == longitudCadena) {
        // Si hemos llegado al final de la cadena
        if ((izquierdaEliminar == 0) && (derechaEliminar == 0)) {
            // Y no hay paréntesis para eliminar
            cout << "\nUna solución: ";
            for (int i = 0; i < longitudCadena; i++) {
                if (arregloSolucion[i]) {
                    // Mostrar los caracteres marcados en la solución
                    cout << cadena[i];
                }
            }
        }
    } else {
        if ((cadena[posicionActual] == '(') && (izquierdaEliminar > 0)) {
            // Caso: Eliminar un paréntesis izquierdo
            resolverParentesis(posicionActual + 1, izquierdaTotal, derechaTotal, izquierdaEliminar - 1, derechaEliminar, longitudCadena, cadena, arregloSolucion);
        } else if ((cadena[posicionActual] == ')') && (derechaEliminar > 0)) {
            // Caso: Eliminar un paréntesis derecho
            resolverParentesis(posicionActual + 1, izquierdaTotal, derechaTotal, izquierdaEliminar, derechaEliminar - 1, longitudCadena, cadena, arregloSolucion);
        }

        // Marcar la posición actual como parte de la solución
        arregloSolucion[posicionActual] = 1;

        if ((cadena[posicionActual] != '(') && (cadena[posicionActual] != ')')) {
            // Caracter no es un paréntesis, seguir explorando
            resolverParentesis(posicionActual + 1, izquierdaTotal, derechaTotal, izquierdaEliminar, derechaEliminar, longitudCadena, cadena, arregloSolucion);
        } else if (cadena[posicionActual] == '(') {
            // Caso: Paréntesis izquierdo
            resolverParentesis(posicionActual + 1, izquierdaTotal + 1, derechaTotal, izquierdaEliminar, derechaEliminar, longitudCadena, cadena, arregloSolucion);
        } else if (derechaTotal < izquierdaTotal) {
            // Caso: Paréntesis derecho que coincide con un izquierdo
            resolverParentesis(posicionActual + 1, izquierdaTotal, derechaTotal + 1, izquierdaEliminar, derechaEliminar, longitudCadena, cadena, arregloSolucion);
        }

        // Desmarcar la posición actual como parte de la solución
        arregloSolucion[posicionActual] = 0;
    }
}
