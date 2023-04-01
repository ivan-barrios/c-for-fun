#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20

int contar(char string[]);
int contarOcurrencias(char string[], char caracter);

int main()
{
  char string[DIM];
  printf("Introduzca una palabra:\n");
  scanf("%s", string);
  printf("%s", string);
  int cantidad = contar(string);
  printf("La cantidad es %d", cantidad);
  return 0;
}

int contarOcurrencias(char string[], char caracter)
{
  int cant = 0;
  while (*string != '\0')
  {
    if (*string == caracter)
    {
      ++cant;
    }
  }
  return cant;
}

int contar(char string[])
{
  char *ptrString = string;
  int cantidad = 0;
  while (*ptrString != '\0')
  {
    cantidad += contarOcurrencias(string, *ptrString);
    ptrString++;
  }
}
