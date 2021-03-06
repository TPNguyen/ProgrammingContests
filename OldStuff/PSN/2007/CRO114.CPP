/*
Alfonso Alfonso Peterssen
2 - 8 - 2007
PSN 2007 #114 "Trokut"
*/
#include <fstream>
using namespace std;

#define problem "d"

#define MAXN 300

int N, i, j, k, sol;
int a, b, c;
int C[MAXN][MAXN];
int X[MAXN], Y[MAXN];

  inline int cross( int o, int c, int m ) {
    return ( X[c] - X[o] ) * ( Y[m] - Y[o] ) -
           ( X[m] - X[o] ) * ( Y[c] - Y[o] );
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ ) fin >> X[i] >> Y[i];

  for ( i = 0; i < N; i++ )
  for ( j = 0; j < N; j++ )
  for ( k = 0; k < N; k++ )
    if ( cross( i, j, k ) < 0 ) C[i][j]++;

  for ( i = 0; i < N; i++ )
  for ( j = 0; j < N; j++ )
  for ( k = 0; k < N; k++ )
    if ( cross( i, j, k ) > 0 ) {
      int x = N - C[i][j] - C[j][k] - C[k][i];
      if ( x > sol ) {
        sol = x;
        a = i + 1; b = j + 1; c = k + 1;
      }
    }

  fout << sol << endl;
  fout << a << ' ' << b << ' ' << c << endl;

  return 0;
}

/*
114� Trokut.                                              Croacia 2007
����������������������������������������������������������������������

Sean  N  puntos  diferentes  en  un  plano.  Nosotros  sabemos  que un
tri�ngulo est�  formado por  algunos tres  puntos como  esquinas es un
s�per-tri�ngulo si el  n�mero  de puntos  dentro de este  tri�ngulo es
tan grande como sea posible.  Nosotros consideramos los puntos en  las
esquinas  o  en las  aristas del   tri�ngulo como  que est� dentro del
tri�ngulo. Escriba un programa que, entre los puntos dados,  encuentre
tres puntos que formen alg�n s�per-tri�ngulo.

Entrada

La primera l�nea del fichero  de entrada TROKUT.IN contiene un  entero
N, 3 <=  N <= 300.  Cada una de  las siguientes N  l�neas contiene dos
enteros �la coordenadas de un  punto. Nota: los casos de  prueba ser�n
de tal manera que existan al menos tres puntos no-coliniales.

Salida

La primera  l�nea del  fichero de  salida TROKUT.OUT  debe contener el
n�mero de  puntos incidente  en el  s�per-tri�ngulo. La  segunda l�nea
debe contener tres  n�meros ġndice de  los tres puntos  de la esquina
del s�per-tri�ngulo, en cualquier orden.

Ejemplos de Entrada y Salida:

Ejemplo #1               Ejemplo #2              Ejemplo #3
�����������Ŀ           �����������Ŀ           �����������Ŀ
� TROKUT.IN �           � TROKUT.IN �           � TROKUT.IN �
�����������Ĵ           �����������Ĵ           �����������Ĵ
� 6         �           � 9         �           � 13        �
� 1 3       �           � 1 1       �           � 1 3       �
� 2 3       �           � 2 2       �           � 2 4       �
� 2 1       �           � 3 3       �           � 3 1       �
� 3 1       �           � 2 1       �           � 4 1       �
� 3 2       �           � 3 2       �           � 4 2       �
� 4 4       �           � 3 1       �           � 4 3       �
�������������           � 4 2       �           � 4 4       �
                        � 4 1       �           � 4 5       �
                        � 5 1       �           � 5 1       �
                        �������������           � 5 2       �
                                                � 6 1       �
                                                � 6 5       �
                                                � 7 3       �
                                                �������������
������������Ŀ          ������������Ŀ          ������������Ŀ
� TROKUT.OUT �          � TROKUT.OUT �          � TROKUT.OUT �
������������Ĵ          ������������Ĵ          ������������Ĵ
� 5          �          � 9          �          � 9          �
� 1 4 6      �          � 1 9 3      �          � 3 11 8     �
��������������          ��������������          ��������������
*/
