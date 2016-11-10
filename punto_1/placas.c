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
double V0= 100.0;
int n;
int  inicial, final, fila_p1, fila_p2;
int i, j;

n= L/ h;
double V[n][n];

for (i=0; i<n; i++)
	{
	for (j=0; j<n; j++)
	{
		V[i][j]=0.0;
	}
} 


inicial= (n/ L)*(L/2- l/2);
final= n*(l/L);
fila_p1= (n/L)*(L/2-d/2);
fila_p2= fila_p1 + n*(d/L);



for (n=0; n< 2*pow(L/h,2) ;n++)
	{

	/* Valores de las placas */
	for (i=inicial; i<inicial+final ;i++)
		{
			V[fila_p1][i]= V0/2.0;
			V[fila_p2][i]= -V0/2.0;
		}

	double V_new[n][n];
	/* Se llena la matriz y se actualiza */
	for (i=1; i<n-1; i++)
		{
		for (j=1; j<n-1; j++)
			{
				V_new[i][j]= (V[i][j-1]+ V[i-1][j]+ V[i][j+1]+ V[i+1][j])/4;	
			}
		}

	/* Se actualiza la matriz V */
	for (i=0; i<n; i++)
		{
		for (j=0; j<n; j++)
			{
				V[i][j]= V_new[i][j];
			}
		}

	}


/* Se imprime resultado final de la iteracion */
for (i=0; i<n; i++)
	{
	for (j=0; j<n; j++)
	{
		if (j==n-1){
			printf("%lf", V[i][j]);
		}
		else 
		{
			printf("%lf,", V[i][j]);
		}

	}
	printf("\n");
	}
}


