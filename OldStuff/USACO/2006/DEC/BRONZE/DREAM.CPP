/*
Alfonso Alfonso Peterssen
13 - 7 - 2007
USACO 2006 DEC Bronze "So�ar Contando"
*/
#include <fstream>
using namespace std;

#define problem "dream"

int A, B, i, x;
int digit[10];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> A >> B;

  for ( i = A; i <= B; i++ )
    for ( x = i; x; x /= 10 )
      digit[ x % 10 ]++;

  for ( i = 0; i < 9; i++ )
    fout << digit[i] << " ";

  fout << digit[9] << endl;

  return 0;
}

/*
Problema 13: So�ar Contando [Rob Kolstad, 2006]

Bessie estaba dormitando en el d�a un d�a en que ella estaba entre el
cansancio y esa deliciosa pereza que todos sentimos cuando estamos
cansados. Por un momento, ella cont� ovejas y no pudo dormir. La mente de
Bessie es afilada y visualiza los n�meros conforme ella va contando. Ella
comenz� a darse cuenta de los d�gitos y pens�: �Cu�ntas instancias de
cada d�gito aparecen en una secuencia de conteo?

Escriba un programa que responda esta pregunta. Dados dos enteros M y N
(1 <= M <= N <= 2,000,0000,000 y N-M <= 500,000), �cu�ntas ocurrencias de
cada d�gito aparecen?

Considere la secuencia: 129..137: 129, 130, 131, 132, 133, 134, 135, 136,
137. Cuente los d�gitos para encontrar:

   1x0      1x5
  10x1      1x6
   2x2      1x7
   9x3      0x8
   1x4      1x9

NOMBRE DEL PROBLEMA: dream

FORMATO DE ENTRADA:

* L�nea 1: Dos enteros separados por espacio: M y N

Entrada Ejemplo (archivo dream.in):

129 137

FORMATO DE SALIDA:

* L�nea 1: Diez enteros separados por espacios que son el n�mero de veces
      que cada d�gito (0..9) aparece cuando se cuenta a trav�s de la
      secuencia.

ARCHIVO EJEMPLO (archivo dream.out):

1 10 2 9 1 1 1 1 0 1


DETALLES DE LA SALIDA:

Un cero, diez unos, etc.
*/
