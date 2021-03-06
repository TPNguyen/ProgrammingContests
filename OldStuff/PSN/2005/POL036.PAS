{koder: A^2P}
{PSN 2005 #36 "Zidarska"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i,j,k,h,a,b,sol : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  for i:=1 to N do
  begin
    readln(fin,j,k);
    inc(a,h); inc(b,k); h := j;
    if b - a > sol then sol := b - a;
  end;{for}

  {dprint}
  write(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
36� Zidarska.                                             Polonia 2005
����������������������������������������������������������������������

Mirko  quiere  bajar su canci�n favorita de Internet.  La canci�n est�
dividida  en   segmentos que  tienen  que ser   bajados  en un  orden.
Nosotros conocemos  la longitud  y el tiempo de  bajar cada   segmento
(ambos expresados en segundos).

Si es  posible, el  quiere comenzar  a escuchar  su canci�n tan pronto
como sea  posible, a�n  antes de  ser bajada,  sin interrupciones (sin
esperar por alg�n segmento a ser bajado en la  mitad de  la  canci�n).
El puede  comenzar a  escuchar un  segmento solamente  despu�s de  ser
bajado completamente.

Escriba un  programa que determine el n�mero m�nimo de segundos (desde
el momento que  comienza a  bajar  la canci�n) despu�s  del cual Mirko
puede comenzar a escuchar la canci�n.

Entrada

En la primera l�nea del fichero STD.IN contiene un entero N, 1 <= N <=
100,000, el n�mero  de segmentos. Cada  una de las  siguientes l�neas,
contiene    dos    enteros  D   y    V,   1  <=  D,V <=  1000.   Estos
n�meros representan  segmentos en   el orden  que deben   ser bajados.
D es  la longitud y V es tiempo que demora en bajar.

Salida

En la primera y �nica l�nea  del fichero de salida STD.OUT usted  debe
de escribir el n�mero de segundos.

Ejemplos de Entrada y Salida:

      Ejemplo # 1             Ejemplo # 2            Ejemplo # 3
 ��������Ŀ ���������Ŀ  ��������Ŀ ���������Ŀ  ��������Ŀ ���������Ŀ
 �STD.IN  � � STD.OUT �  � STD.IN � � STD.OUT �  �STD.IN  � � STD.OUT �
 ��������Ĵ ���������Ĵ  ��������Ĵ ���������Ĵ  ��������Ĵ ���������Ĵ
 � 4      � � 7       �  � 5      � � 2       �  � 7      � � 3       �
 � 2 1    � �����������  � 1 1    � �����������  � 2 1    � �����������
 � 1 5    �              � 1 2    �              � 2 4    �
 � 3 3    �              � 3 1    �              � 1 2    �
 � 2 4    �              � 2 1    �              � 2 1    �
 ����������              � 3 3    �              � 3 2    �
                         ����������              � 3 1    �
                                                 � 1 3    �
                                                 ����������
}