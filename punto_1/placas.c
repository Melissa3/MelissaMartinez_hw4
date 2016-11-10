#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void placas();

int main()
{
	placas();	
 	return 0;
}

void placas()
{
double L= 5.0,l= 2.0, d=1.0, h=0.02;
double V0= 100;
int n;
int  

n=L/h;
double V[n][n];

for (i=0; i<n; i++)
	{
	for (j=0; j<n; j++)
	{
		V[i][j]=0;

	}
} 


inicial= (n/L)*(L/2-l/2);
final= n*(l/L);
fila_p1= (n/L)*(L/2-d/2);
fila_p2= fila_p1 + n*(d/L)

for (i=inicial; i<inicial+final ;i++)
	{
	V[fila_p1][i]= V0/2;
	V[fila_p1][i]= -V0/2;
	}




