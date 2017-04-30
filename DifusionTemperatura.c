#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void inicial(float T_inicial[100][100] , float temp_recta , float temp_cuad );
void fijas(float coef, float lambda, float T_inicial[100][100]);
float promedio(float T[100][100]);
void IMPRIME(FILE *out, float T_inicial[100][100]);

int main()    
{ 
    /*Variables definidas para el problema de difusion*/
    float tamano = 100.0 ;
    float coef = pow(10,-4);
    float temp_cuad = 50.0;
    float temp_recta = 100.0;
    float alto = 10.0;
    float ancho = 20.0;
    float T_inicial[100][100];
    float T_old[100][100];
    float T_llena[100][100];
    float dx = 1.0 ;
    float dt = 0.2 ;
    float mean = 0.0;
    float lambda = coef * ( dt / pow(dx,2));
    
    
    
    FILE *cond_fijo = fopen("condiciones_fijas.txt", "w+");	
    FILE *fijas1_2500 = fopen("fijas_a_2500.txt", "w+");
    FILE *fijas1_100 = fopen("fijas_a_100.txt", "w+");
    FILE *fijas1_prom = fopen("Promedio_fijas.txt", "w+");

    
    int i ; 
    int j ;
	
    inicial(T_inicial, 100.0, 50.0);
	for(i=0; i<(2500/dt);i++)
	{	
		fijas(coef, lambda, T_inicial);
		
		if(i==(100/dt-1))
		{	
			IMPRIME(fijas1_100, T_inicial);
		}

		if(i==(2500/dt-1))
		{
			IMPRIME(fijas1_2500, T_inicial);
		}

		fprintf(fijas1_prom, "%f %f \n", dt*(i+1), promedio(T_inicial));	
	}

	fclose(fijas1_100);
	fclose(fijas1_2500);
	fclose(fijas1_prom);

}
    
  void inicial(float T_inicial[100][100] , float temp_recta , float temp_cuad )
  {
    int i,j;
    float casilla = 100 ;
      /*Condiciones iniciales*/
     for(i=0;i< casilla; i++)
	   {
         for(j=0;j<casilla; j++)
            {
             /*Rectangulo*/
			if((i >=20  || i<=40) && (j>=45  || j<=55))
                {
                    T_inicial[i][j] = temp_recta;
                }
            else
			     {
				    T_inicial[i][j] = temp_cuad;
			     }
		      }
        }
 }
    
   
    /*  Solucion Fijas */    
    
void fijas(float coef, float lambda, float T_inicial[100][100]){	
	
	int i,j;
    float T_old[100][100];
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			T_old[i][j] = T_inicial[i][j];
		}
	}

	for(i=1; i<99; i++)
	  {
		for(j=1; j<99; j++)
		  {
            if(!(i>=20 && i<40 && j>=45 && j<55))
                {
                    T_inicial[i][j]= coef*lambda*(T_old[i+1][j]+T_old[i-1][j]+T_old[i][j+1]+T_old[i][j-1]-4*T_old[i][j])+T_old[i][j];   
                }	
		   }
	   }
    }
    
    
float promedio(float T_inicial[100][100]){
	
    int i,j;
    float media = 0.0;
                                	
	for(i=0; i<100; i++)
	{
		for(j=0; j<100; j++)
		{                                       
			media+=T_inicial[i][j];
		}
	}
	
	return (float)(media/(100.0*100.0));
	
}

void   IMPRIME(FILE *out, float T_inicial[100][100]){
	
    int i,j;
	for(i=0; i<100; i++)
	{
		for(j=0; j<100; j++)
		{
			fprintf(out, "%f \n", T_inicial[i][j]);
		}
	}

}

    


  