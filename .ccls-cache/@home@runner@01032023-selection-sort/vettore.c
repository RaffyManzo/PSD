#include "vettore.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int minimo(int a[], int n) {
  int i, pos = 0;

  for (i = 1; i < n; i++) {
    if (a[i] < a[pos])
      pos = i;
  }

  return pos;
}

void ordina_array(int *a, int n) {
  // selection sort
  int i, min;

  for (i = 0; i < n - 1; i++) {
    // a + i verrà ricercato il minimo della parte restante
    // del vettore ovvero quella non ordinata, partente dall'indirizzo
    // base + l'indice corrente
    min = minimo(a + i, n - i) + i;
    swap(&a[i], &a[min]);
  }
}

// se la posizione passata è corretta, verrà elimnato il valore relativo a
// quella pos il vettore verrà shiftato a sinistra
int elimina(int a[], int *n, int x) {
  if (x >= *n || x < 0)
    return -1;

  printf("\n\nVerra' eliminato l'elemento %d in posizione %d", a[x], x);

  while (x < (*n) - 1) {
    a[x] = a[x + 1];
    x++;
  }

  // dimensione del vettore modificata
  (*n)--;
  return 0;
}

// ricerca un elemento passato come parametro e ritorna la sua posizione
// se esiste, in caso contrario -1
int ricerca(int a[], int n, int x) {
  int i;

  for (i = 0; i < n; i++)
    if (a[i] == x)
      return i;

  return -1;
}

void inserimento(int *a, int *n, int new) {
  int i;

  // realloca la dimensione del vettore, aggiungendo una posizione
  // accoda il nuovo elemento nella posizione n(ultima posizione utile nel nuovo vettore)
  // pos = n equivale alla precedente grandezza del vettore
  a = realloc(a, (*n + 1) * sizeof(int));

  a[*n] = new;

  (*n)++;
  ordina_array(a, *n);
  output_array(a, *n);
}

void input_array(int *a, int n) {
  int i;

  for (i = 0; i < n; i++) {
    if (!scanf("%d", &a[i]))
      break;
  }
}

void output_array(int *a, int n) {
  int i = 0;

  for (printf("\n\nIl tuo array è:\t"); i < n; i++) {
    printf("%d\t", a[i]);
  }
}