/*
Alfonso Alfonso Peterssen
28 - 8 - 2007
USACO 2005 FEB Silver "Adquisici�n de Partes"
*/
#include <cstdio>

#define problem "d"
#define MAXV 1001
#define oo 1000000

int V, E, i, j, k;
int len[MAXV];
int ls[MAXV][MAXV];
bool mark[MAXV];
int dist[MAXV], last[MAXV];

  void print_path( int x ) {
    if ( !x ) return ;
    print_path( last[x] );
    printf( "%d\n", x );
  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &E, &V );
  for ( i = 0; i < E; i++ ) {
    scanf( "%d %d", &j, &k );
    ls[j][ len[j]++ ] = k;
  }

  /* Dijkstra */
  for ( i = 0; i <= V; i++ )
    dist[i] = oo;

  dist[1] = 0;

  for ( i = 0; i < V; i++ ) {

    k = 0;
    for ( j = 1; j <= V; j++ )
      if ( !mark[j] && dist[j] < dist[k] )
        k = j;

    mark[k] = true;

    for ( j = 0; j < len[k]; j++ )
      if ( dist[k] + 1 < dist[ ls[k][j] ] ) {
        dist[ ls[k][j] ] = dist[k] + 1;
        last[ ls[k][j] ] = k;
      }

  }

  if ( dist[V] == oo )
    printf( "-1\n" );
  else {
    printf( "%d\n", dist[V] + 1 );
    print_path( V );
  }

  return 0;
}

/*
Problema 6: Adquisici�n de Partes [Entrenadores, 2004]

Las vacas han sido enviadas en una misi�n a trav�s del espacio para
adquirir una nueva m�quina orde�adora para su establo. Ellas est�n
viajando a trav�s de un conglomerado de estrellas conteniendo N (1 <= N
<= 50,000) planetas, cada uno con una tienda.

Las vacas han determinado cu�les de K (1 <= K <= 1,000) tipos de objetos
(numerados 1..K) de cada planeta en el conglomerado desean, y cu�les
productos deben comerciar. Ning�n planeta ha desarrollado dinero, por lo
tanto ellos trabajan con el sistema de trueque: todo los intercambios
consisten de que cada parte da exactamente un objeto (presumiblemente de
tipos diferentes).

Las vacas parten de la Tierra con un paquete de heno de alta calidad
(�tem 1), y ellas desean una nueva m�quina orde�adora (�tem K). Ay�delas
a encontrar la mejor manera de hacer una serie de intercambios en los
planetas del conglomerado para obtener el �tem K. Si esta tarea es
imposible, d� como salida -1.

NOMBRE DEL PROBLEMA: acquire

FORMATO DE ENTRADA:

* L�nea 1: Dos enteros separados por espacios, N y K.

* L�neas 2..N+1: La L�nea i+1 contiene dos enteros separados por
    espacio, a_i y b_i respectivamente, que son los productos de
    intercambio del planeta i. El planeta dar� el �tem b_i con el
    prop�sito de recibir el �tem a_i.

ENTRADA EJEMPLO (archivo acquire.in):

6 5
1 3
3 2
2 3
3 1
2 5
5 4

FORMATO DE SALIDA:

* L�nea 1: El m�nimo n�mero de intercambios T requeridos para obtener la
    m�quina orde�adora, la cual es el �tem K (o -1 si las vacas no pueden
    obtener el �tem K).

* L�neas 2..T+1: La lista ordenada de objetos que las vacas poseen
    durante la secuencia de intercambios.

SALIDA EJEMPLO (archivo acquiere.out):

4
1
3
2
5

DETALLES DE LA SALIDA

Las vacas poseen 4 objetos en total: primero ellas intercambian el objeto
1 por el objeto 3, luego el objeto 3 por el objeto 2, y luego el objeto 2
por el objeto 5.
*/
