#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) { 
  int mayor = arr[0];
  for (int i = 0; i < size; i++) {
    if (arr[i] > mayor) {
      mayor = arr[i];
    }
  }
  return mayor; }

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  
  int last = size - 1;
  int temp;
  for (int i = 0; i < size; i++) {
    if (i >= last) break;
    temp = arr[i];
    arr[i] = arr[last];
    arr[last] = temp;
    last--;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { 
  
  int cant_par = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      cant_par++;
    }
  }
  
  int talla = 0;
  int *new_arr = (int *)malloc(cant_par * sizeof(int));
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      new_arr[talla] = arr[i];
      talla++;
    }
  }

  (*newSize) = talla;
  return new_arr; 
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
  int new_size = size1 + size2;
  
  int i = 0;
  int k = 0;

  for (int indice = 0; indice < new_size; indice++) {
    if (i < size1 && k < size2) {
      if (arr1[i] < arr2[k]) {
        result[indice] = arr1[i];
        i++;
      }
      else if (arr1[i] == arr2[k]) {
        result[indice] = arr1[i];
        i++;
        indice++;
        result[indice] = arr2[k];
        k++;
      }
      else {
        result[indice] = arr2[k];
        k++;
      }
    }
    else if (i < k) {
      result[indice] = arr1[i];
      i++;
    }
    else {
      result[indice] = arr2[k];
      k++;
    }
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) { 
  int asc = 1; // true
  int desc = 1; 

  for (int i = 0; i < size - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      desc = 0;
    } 
    if (arr[i] > arr[i + 1]) { 
      asc = 0;
    }
  }
  if (asc) {
    return 1;
  }
  else if (desc) {
    return -1;
  }
  else {
    return 0;
  }
    

  return -2; 
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) {
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
  
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { 
  Nodo *head = NULL, *temp = NULL, *actual = NULL;

  for (int i = 0; i < size; i++) {
    temp = (Nodo *)malloc(sizeof(Nodo));
    temp->numero = arr[i];
    if (head == NULL) head = temp;
      
    else actual->siguiente = temp;
    
    actual = temp;
  }
  
  
  return head; 
}
