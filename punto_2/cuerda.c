#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 200

void cuerda();

int main()
{
	cuerda();	
 	return 0;
}

void cuerda()
{

int i, j;
int L= 100, T=40, rho=10;
double *x, *t;

double *u_past, *u_present, *u_future;

u_past= (double*)malloc(M*sizeof(double));
u_present= (double*)malloc(M*sizeof(double));
u_future= (double*)malloc(M*sizeof(double));
x= (double*)malloc(M*sizeof(double));
t= (double*)malloc(M*sizeof(double));

/* run through loops, equals to linspace(0,100,100)*/
for (i=0; i<M; i++)
	{
		x[i]= (((double) (i) / ((double) (M) - 1.0)) + i)/2.0;
		t[i]= (((double) (i) / ((double) (M) - 1.0)) + i)/2.0;
	if (i != M-1)
		{
			printf("%lf,", x[i]);
		}
	else
		{
			printf("%lf\n", x[i]);
		}

	}

double delta_x= x[1]-x[0];
double delta_t= t[1]-t[0];

/* filling u_past with the initial conditions */
for (i=0; i<M; i++)
	{
		if (x[i]<= 0.8*L)
		{
			u_past[i]= 1.25*(x[i]/ (double) (L));
		}
		else if (x[i]> 0.8*L)
		{
			u_past[i]=0.8* (double) (L);
		}
	if (i != M-1)
		{
			printf("%lf,", u_past[i]);
		}
	else
		{
			printf("%lf\n", u_past[i]);
		}
	}

u_past= u_present;
double c= sqrt((double) (T)/ (double) (rho)); 

/* filling u_future and actualizing u_past and u_present through time */
for (i=0; i<M; i++)
	{
		for (j=0; j<M; j++)
			{
				if (j==0)
				{
					u_future[j]= 0.0;
					printf("%lf,", u_future[j]);
				}
				else if (j==M-1)
				{
					u_future[j]= 0.0;
					printf("%lf\n", u_future[j]);
				}
				else
				{
					u_future[j]= (pow(c,2)* pow(delta_t,2)* ((u_present[j-1]-2*u_present[j]+ u_present[j+1])/(pow(delta_x,2))))-u_past[j] + 2*u_present[j];  
					printf("%lf,", u_future[j]);
				}
			}
	u_past = u_present;
	u_present = u_future;
	
	}

/* free memory 
free(u_past); free(u_present); free(u_future);*/

}
