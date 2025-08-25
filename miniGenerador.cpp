#include <iostream>
#include <string>
using namespace std;

// Verifica si el caracter es letra
bool esLetra(char c) {
    return isalpha(c);
}

// Verifica si el caracter es dígito
bool esDigito(char c) { 
    return isdigit(c);
}

// Imprime el token validando si es identificador o real
void imprimirToken(string token) {
    if (token.empty()) return;

    // Verificar si es identificador (empieza con letra)
    if (esLetra(token[0])) {
        bool valido = true;
        for (char c : token) {
            if (!esLetra(c) && !esDigito(c)) {
                valido = false;
                break;
            }
        }
        if (valido) {
            cout << "Identificador: " << token << endl;
            return;
        }
    }

    // Verificar si es real
    int puntos = 0;
    bool antesPunto = false, despuesPunto = false;
    for (char c : token) {
        if (esDigito(c)) {
            if (puntos == 0) antesPunto = true;
            else despuesPunto = true;
        } else if (c == '.') {
            puntos++;
        } else {
            puntos = 99; // inválido
            break;
        }
    }

    if (puntos == 1 && antesPunto && despuesPunto) {
        cout << "Real: " << token << endl;
        return;
    }

    cout << "Token inválido: " << token << endl;
}

// Función para analizar el texto y encontrar tokens
void analizarTexto(const string& texto) {
    string tokenActual;

    for (char c : texto) {
        if (esLetra(c) || esDigito(c) || c == '.') {
            tokenActual += c;
        } else {
            imprimirToken(tokenActual);
            tokenActual.clear();
        }
    }
    imprimirToken(tokenActual);
}

int main() {
    string texto = "a, x12, prueba123, b2c3, 3.14, 12.5, 99.001, 12.";

    cout << "Analizando el texto:" << endl;
    analizarTexto(texto);

    return 0;
}

