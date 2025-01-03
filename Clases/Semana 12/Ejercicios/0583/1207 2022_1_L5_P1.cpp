#include <iostream>
#include <cstring>

using namespace std;

// Funci�n para resolver el problema de los par�ntesis
void resolverParentesis(int posicionActual, int izquierdaTotal, int derechaTotal, int izquierdaEliminar, int derechaEliminar, int longitudCadena, char* cadena, int* arregloSolucion);

int main() {
    int longitudCadena;
    //cout << "Ingresar cantidad de caracteres a leer: ";
    //cin >> longitudCadena;

    // Crear una matriz din�mica para almacenar la cadena
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

    cout << "Se ley� la cadena: ";
    for (int i = 0; i < longitudCadena + 1; i++) {
        cout << cadena[i];
    }

    // Crear una matriz din�mica para almacenar la soluci�n
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

    // Llamar a la funci�n para resolver el problema
    resolverParentesis(0, 0, 0, izquierda, derecha, longitudCadena, cadena, arregloSolucion);

    // Liberar la memoria de las matrices din�micas
    delete[] cadena;
    delete[] arregloSolucion;

    return 0;
}


// Funci�n para resolver el problema de los par�ntesis
//posicionActual: posici�n en la cadena que estamos analizando. A medida que la funci�n se llama recursivamente, esta posici�n se actualiza para recorrer la cadena desde el principio hasta el final.
//izquierdaTotal: Lleva un registro de la cantidad total de par�ntesis izquierdos ('(') encontrados hasta el momento en el proceso de exploraci�n de la cadena. Esto ayuda a determinar si es posible agregar un par�ntesis izquierdo adicional en una posici�n dada.
//derechaTotal: Similar a izquierdaTotal, lleva un registro de la cantidad total de par�ntesis derechos (')') encontrados hasta el momento en el proceso de exploraci�n de la cadena. Esto ayuda a determinar si es posible agregar un par�ntesis derecho adicional en una posici�n dada.
//izquierdaEliminar: Indica cu�ntos par�ntesis izquierdos deben eliminarse en la cadena para alcanzar una soluci�n v�lida. Este valor disminuye cuando se elimina un par�ntesis izquierdo de manera que la funci�n no lo considere nuevamente.
//derechaEliminar: Indica cu�ntos par�ntesis derechos deben eliminarse en la cadena para alcanzar una soluci�n v�lida. Este valor disminuye cuando se elimina un par�ntesis derecho de manera que la funci�n no lo considere nuevamente.
//longitudCadena: La longitud total de la cadena que se est� analizando. Este valor se utiliza para determinar cu�ndo se ha llegado al final de la cadena y se debe verificar si se ha encontrado una soluci�n v�lida.
//adena: La cadena de entrada que se est� analizando. Se utiliza para acceder a los caracteres individuales de la cadena en la posici�n actual y para marcar los caracteres como parte de la soluci�n.
//arregloSolucion: Un arreglo que se utiliza para llevar un registro de qu� caracteres de la cadena est�n marcados como parte de la soluci�n. Si arregloSolucion[i] es 1, significa que el car�cter en la posici�n i de la cadena est� marcado como parte de la soluci�n; si es 0, no lo est�.
void resolverParentesis(int posicionActual, int izquierdaTotal, int derechaTotal, int izquierdaEliminar, int derechaEliminar, int longitudCadena, char* cadena, int* arregloSolucion) {
    if (posicionActual == longitudCadena) {
        // Si hemos llegado al final de la cadena
        if ((izquierdaEliminar == 0) && (derechaEliminar == 0)) {
            // Y no hay par�ntesis para eliminar
            cout << "\nUna soluci�n: ";
            for (int i = 0; i < longitudCadena; i++) {
                if (arregloSolucion[i]) {
                    // Mostrar los caracteres marcados en la soluci�n
                    cout << cadena[i];
                }
            }
        }
    } else {
        if ((cadena[posicionActual] == '(') && (izquierdaEliminar > 0)) {
            // Caso: Eliminar un par�ntesis izquierdo
            resolverParentesis(posicionActual + 1, izquierdaTotal, derechaTotal, izquierdaEliminar - 1, derechaEliminar, longitudCadena, cadena, arregloSolucion);
        } else if ((cadena[posicionActual] == ')') && (derechaEliminar > 0)) {
            // Caso: Eliminar un par�ntesis derecho
            resolverParentesis(posicionActual + 1, izquierdaTotal, derechaTotal, izquierdaEliminar, derechaEliminar - 1, longitudCadena, cadena, arregloSolucion);
        }

        // Marcar la posici�n actual como parte de la soluci�n
        arregloSolucion[posicionActual] = 1;

        if ((cadena[posicionActual] != '(') && (cadena[posicionActual] != ')')) {
            // Caracter no es un par�ntesis, seguir explorando
            resolverParentesis(posicionActual + 1, izquierdaTotal, derechaTotal, izquierdaEliminar, derechaEliminar, longitudCadena, cadena, arregloSolucion);
        } else if (cadena[posicionActual] == '(') {
            // Caso: Par�ntesis izquierdo
            resolverParentesis(posicionActual + 1, izquierdaTotal + 1, derechaTotal, izquierdaEliminar, derechaEliminar, longitudCadena, cadena, arregloSolucion);
        } else if (derechaTotal < izquierdaTotal) {
            // Caso: Par�ntesis derecho que coincide con un izquierdo
            resolverParentesis(posicionActual + 1, izquierdaTotal, derechaTotal + 1, izquierdaEliminar, derechaEliminar, longitudCadena, cadena, arregloSolucion);
        }

        // Desmarcar la posici�n actual como parte de la soluci�n
        arregloSolucion[posicionActual] = 0;
    }
}
