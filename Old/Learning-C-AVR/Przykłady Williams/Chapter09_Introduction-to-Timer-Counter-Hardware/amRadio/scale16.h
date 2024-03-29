/* Skala z kluczem 1/10000 */

/* 
   Tutaj podawane są długści fal -- jeżeli odczekasz ten czas, 
   a potem przełączysz pin głośnika, to uzyskasz mniej więcej
   wybraną wysokość dźwięku.  

   To jest wersja 16-bitowa.  Im wyższe dźwięku tym mniej dokładnie
   można je wyznaczyć, ale nie jest tak źle jak w wersji 8-bitowej.
   
   "x" oznacza krzyżyk.
   
   Tę listę można wygenerować w Pythonie:

   import math
   scale = ['C', 'Cx', 'D', 'Dx', 'E', 'F', 'Fx', 'G', 'Gx', 'A', 'Ax', 'B']
   
   def octave(baseLength):
       wavelengths = [baseLength / math.exp(x*math.log(2)/12) for x in range(0, 12)]
       wavelengths = [int(round(x)) for x in wavelengths]
       return( zip(scale, wavelengths) )

   for i in range(0,4):
       for note, wavelength in octave(10000 / 2**i):
           if wavelength < 65500:
	       noteString = note + str(i)
	       print "#define  {:<5}{:>6}".format(noteString, wavelength)
*/


#define  C0    10000
#define  Cx0    9439
#define  D0     8909
#define  Dx0    8409
#define  E0     7937
#define  F0     7492
#define  Fx0    7071
#define  G0     6674
#define  Gx0    6300
#define  A0     5946
#define  Ax0    5612
#define  B0     5297
#define  C1     5000
#define  Cx1    4719
#define  D1     4454
#define  Dx1    4204
#define  E1     3969
#define  F1     3746
#define  Fx1    3536
#define  G1     3337
#define  Gx1    3150
#define  A1     2973
#define  Ax1    2806
#define  B1     2649
#define  C2     2500
#define  Cx2    2360
#define  D2     2227
#define  Dx2    2102
#define  E2     1984
#define  F2     1873
#define  Fx2    1768
#define  G2     1669
#define  Gx2    1575
#define  A2     1487
#define  Ax2    1403
#define  B2     1324
#define  C3     1250
#define  Cx3    1180
#define  D3     1114
#define  Dx3    1051
#define  E3      992
#define  F3      936
#define  Fx3     884
#define  G3      834
#define  Gx3     787
#define  A3      743
#define  Ax3     702
#define  B3      662
