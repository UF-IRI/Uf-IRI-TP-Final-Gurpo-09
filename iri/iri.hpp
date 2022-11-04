#pragma once

#include <string>
#include <cstring>

namespace IRI {

    std::string BASE_PATH = "../../../";

    template<typename T> struct _Vector {
        /*
        * Variables
        * ---------
        */
        int size;
        T* Array;
        /*
        * Inicialización por Defecto
        * -------------------------
        * Inicializa con tamaño 0.
        */
        void _init() {
            Array = new T[0];
        }
        /*
        * Inicialización con tamaño
        * -------------------------
        * Inicializa con el tamaño recibido por parametro.
        */
        void _init(int size) {
            Array = new T[size];
        }
        void add(T _value) {
            resize(size + 1);
            Array[size - 1] = _value;
        }
        void add(int pos, T _value) {
            // ...
        }
        void delete(T _value) {
            // ...
        }
        void delete(int pos) {
            // ...
        }
        /*
        * Lectura de Valor
        * ----------------
        * Busca y devuelve el valor en la posición indicada.
        * Exception: Posición fuera del limite se cierra el programa.
        */
        T& operator[](int pos) {
            if (pos < 0 || (pos + 1) > size) {
                std::cout << "Array index out of bound, exiting";
                exit(0);
            }
            return Array[pos];
        }
        /*
        * Devuelve Array
        * --------------
        */
        T* getArray() {
            return Array;
        }
        /*
        * Redimension Array
        * -----------------
        * Recibe el nuevo tamaño del array y lo redimensiona
        */
        void resize(int size) {
            T* newVector = nullptr;

            newVector = new T[size];
            if (newVector == nullptr) {
                std::cout << "Available Memory" << std::endl;
                return;
            }

            if (Array != nullptr) {
                memcpy(newVector, Array, sizeof(T) * (size));
                delete[] Array;
            }

            Array = newVector;
            size = size;
        }
        /*
        * Destructor
        * ----------
        * Elimina el array y libera la memoria.
        */
        void clear() {
            if (Array != nullptr) {
                delete[] _Array;
                Array = nullptr;
                size = 0;
            }
        }
    };

}