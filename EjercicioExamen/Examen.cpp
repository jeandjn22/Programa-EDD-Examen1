#include <iostream>
#include <list>
#include <algorithm> // libreria para la funcion de ordenamiento
#include <limits> // Para limpiar el bufer de entrada

using namespace std;

// Definición de la estructura de Persona
struct Persona {
    string nombre;
    int cedula;
    int edad;

    // Constructor
    Persona(string nombre, int cedula, int edad) : nombre(nombre), cedula(cedula), edad(edad) {}
};

// Función para comparar personas por edad (para ordenar de mayor a menor)
bool compararPorEdadDesc(const Persona& p1, const Persona& p2) {
    return p1.edad > p2.edad;
}

// Función para comparar personas por cédula (para ordenar de menor a mayor)
bool compararPorCedulaAsc(const Persona& p1, const Persona& p2) {
    return p1.cedula < p2.cedula;
}

// Función para imprimir una lista de personas
void imprimirLista(const list<Persona>& lista) {
    cout << "Lista de personas:" << endl;
    for (const auto& persona : lista) {
        cout << "Nombre: " << persona.nombre << ", Cedula: " << persona.cedula << ", Edad: " << persona.edad << endl;
    }
    cout << endl;
}

// Funcion para determinar las posiciones en un círculo
void determinarPosicionesCirculo(const list<Persona>& lista) {
    // Verificar si hay al menos 4 personas en la lista
    if (lista.size() < 4) {
        cout << "No hay suficientes personas para determinar las posiciones del circulo." << endl;
        return;
    }

    // Crear una copia ordenada de la lista por edad (de mayor a menor)
    list<Persona> listaOrdenada = lista;
    listaOrdenada.sort(compararPorEdadDesc);

    // Mostrar las 4 primeras personas en las posiciones del círculo
    auto it = listaOrdenada.begin();
    cout << "Posiciones en el circulo:" << endl;
    cout << "12: " << it->nombre << endl;
    advance(it, 1);
    cout << "3: " << it->nombre << endl;
    advance(it, listaOrdenada.size() / 2 - 1); // Avanzar a la mitad de la lista
    cout << "6: " << it->nombre << endl;
    advance(it, 1);
    cout << "9: " << it->nombre << endl;
    cout << endl;
}

int main() {
    // Lista de personas
    list<Persona> listaPersonas;

    // Ejemplo: agregamos algunas personas a la lista
    listaPersonas.push_back(Persona("Juan", 1234, 30));
    listaPersonas.push_back(Persona("Maria", 5678, 25));
    listaPersonas.push_back(Persona("Pedro", 9876, 35));
    listaPersonas.push_back(Persona("Jean", 1378, 32));
    listaPersonas.push_back(Persona("Samara", 5890, 25));
    listaPersonas.push_back(Persona("Lucas", 9290, 18));
    listaPersonas.push_back(Persona("Daniela", 4679, 43));
    listaPersonas.push_back(Persona("Lucia", 5712, 91));

    int opcion;
    do {
        // Menú de opciones
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Reordenar lista de personas" << endl;
        cout << "2. Obtener referencia de una porcion de la lista" << endl;
        cout << "3. Borrar elementos dentro de un rango (por cedula o edad)" << endl;
        cout << "4. Determinar posiciones en un circulo" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Submenú para reordenar la lista
                int orden;
                cout << "Seleccione el orden de reordenamiento:" << endl;
                cout << "1. De mayor a menor por edad" << endl;
                cout << "2. De menor a mayor por cedula" << endl;
                cout << "Opción: ";
                cin >> orden;

                if (orden == 1) {
                    // Ordenar de mayor a menor por edad
                    listaPersonas.sort(compararPorEdadDesc);
                    cout << "Lista reordenada de mayor a menor por edad." << endl;
                } else if (orden == 2) {
                    // Ordenar de menor a mayor por cedula
                    listaPersonas.sort(compararPorCedulaAsc);
                    cout << "Lista reordenada de menor a mayor por cedula." << endl;
                } else {
                    cout << "Opción no valida." << endl;
                }

                // Mostrar la lista actualizada
                imprimirLista(listaPersonas);

                // Limpiar el buffer de entrada
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            case 2: {
                // Obtener referencia de una porción de la lista
                int indice;
                cout << "Ingrese el índice a partir del cual mostrar la lista: ";
                cin >> indice;

                // Validar que el índice esté dentro del rango
                if (indice < 0 || indice >= listaPersonas.size()) {
                    cout << "Índice fuera de rango." << endl;
                } else {
                    // Avanzar el iterador hasta el índice indicado
                    auto it = listaPersonas.begin();
                    advance(it, indice);

                    // Mostrar la lista desde el índice hasta el final
                    cout << "Lista desde el indice " << indice << ":" << endl;
                    while (it != listaPersonas.end()) {
                        cout << "Nombre: " << it->nombre << ", Cedula: " << it->cedula << ", Edad: " << it->edad << endl;
                        ++it;
                    }
                    cout << endl;
                }

                // Se limpia el buffer de entrada
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            case 3: {
                // Borrar elementos dentro de un rango (por cedula o edad)
                int rango;
                cout << "Ingrese el rango (cedula o edad): ";
                cin >> rango;

                // Ejemplo de borrar elementos por edad menor o igual al rango
                listaPersonas.remove_if([rango](const Persona& persona) {
                    return persona.edad <= rango;
                });

                cout << "Se han borrado las personas con edad menor o igual a " << rango << "." << endl;
                // Mostrar la lista actualizada
                imprimirLista(listaPersonas);

                // Limpiar el buffer de entrada
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            case 4: {
                // Determinar posiciones en un círculo
                determinarPosicionesCirculo(listaPersonas);
                break;
            }
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no valida." << endl;

                // Se limpia el buffer de entrada
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }

    } while (opcion != 5);

    return 0;
}