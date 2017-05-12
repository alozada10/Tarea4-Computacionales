#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void ini(float TPlaca, float TZona, float T[100][100]);
void ArchOut(FILE *out, float T[100][100]);
float mean(float T[100][100]);
//float makeT(float T[100][100]);
int m(int i);
void F1(float alpha,float t[100][100],float v_u);
void F2(float alpha,float t[100][100],float v_u);
void A1(float alpha,float t[100][100],float v_u);
void A2(float alpha,float t[100][100],float v_u);
void P1(float alpha,float t[100][100],float v_u);
void P2(float alpha,float t[100][100],float v_u);



int main()
{
	//ctes

	float dx = 1.0;
	float v_u = 0.9;
	float dt = 0.1;
	float alpha = 0.1;
	float t0 = 0.0;
	int i;
	int j;


	float T[100][100];
	float Tcopy[100][100];

	
 
	// Caso1 -----------------------------------------------------

	//ARCHIVOS FIJAS

	
	
       	ini(50.0, 100.0, T);
       	ini(50.0, 100.0, Tcopy);

	
       
	FILE *f1F0 = fopen("1F0.txt", "w+");

	FILE *f1F100 = fopen("1F100.txt", "w+");

	FILE *f1F2500 = fopen("1F2500.txt", "w+");

	FILE *f1FM = fopen("1FM.txt", "w+");
	

	ArchOut(f1F0, T);
	fclose(f1F0);
	fprintf(f1FM, "%f %f \n", t0, mean(T)); 

	
	//ARCHIVOS ABIERTAS

	FILE *f1A0;
	f1A0 = fopen("1A0.txt", "w+");

	FILE *f1A100;
	f1A100 = fopen("1A100.txt", "w+");

	FILE *f1A2500;
	f1A2500 = fopen("1A2500.txt", "w+");

	FILE *f1AM;
	f1AM = fopen("1AM.txt", "w+");

	ArchOut(f1A0, T);
	fclose(f1A0);
	fprintf(f1AM, "%f %f \n", t0, mean(T)); 

	
	//ARCHIVOS PERIÓDICAS

	FILE *f1P0;
	f1P0 = fopen("1P0.txt", "w+");

	FILE *f1P100;
	f1P100 = fopen("1P100.txt", "w+");

	FILE *f1P2500;
	f1P2500 = fopen("1P2500.txt", "w+");

	FILE *f1PM;
	f1PM = fopen("1PM.txt", "w+");

	ArchOut(f1P0, T);
	fclose(f1P0);
	fprintf(f1PM, "%f %f \n", t0, mean(T)); 

	
//----------------------------------------------------------------------------------------------//

//F1
	i=0;
	while(i<2500/dt){
		
		F1(alpha,T,v_u);

		if(i==(100/dt-1)){
			ArchOut(f1F100,T);
			
		}

		else if(i==(2500/dt-1)){
			ArchOut(f1F2500,T);

		}

	

		i+=1;
		fprintf(f1FM, "%f %f \n", dt*(i+1), mean(T));
		

	}

	fclose(f1F100);
	fclose(f1F2500);
	fclose(f1FM);

	



//A1
	ini(50.0, 100.0, T);
	ini(50.0, 100.0, Tcopy);

	i=0;
	while(i<2500/dt){

		A1(alpha,T,v_u);

		if(i==100/dt-1){
			ArchOut(f1A100,T);
		}

		else if(i==2500/dt-1){
			ArchOut(f1A2500,T);
		}

		i+=1;
		fprintf(f1AM, "%f %f \n", dt*(i+1), mean(T));
		
	}

	fclose(f1A100);
	fclose(f1A2500);
	fclose(f1AM);




//P1
       	ini(50.0, 100.0, T);
       	ini(50.0, 100.0, Tcopy);

	i=0;
	while(i<2500/dt){

		P1(alpha,T,v_u);

		if(i==100/dt-1){
			ArchOut(f1P100,T);
		}

		else if(i==2500/dt-1){
			ArchOut(f1P2500,T);
		}

		i+=1;
		fprintf(f1PM, "%f %f \n", dt*(i+1), mean(T));
		
	}

	fclose(f1P100);
	fclose(f1P2500);
	fclose(f1PM);




	// Caso2 -----------------------------------------------------

	//ARCHIVOS FIJAS

	
       	ini(50.0, 100.0, T);
       	ini(50.0, 100.0, Tcopy);

       
	FILE *f2F0;
	f2F0 = fopen("2F0.txt", "w+");

	FILE *f2F100;
	f2F100 = fopen("2F100.txt", "w+");

	FILE *f2F2500;
	f2F2500 = fopen("2F2500.txt", "w+");

	FILE *f2FM;
	f2FM = fopen("2FM.txt", "w+");

	ArchOut(f2F0, T);
	fclose(f2F0);
	fprintf(f2FM, "%f %f \n", t0, mean(T)); 

	//ARCHIVOS ABIERTAS

	FILE *f2A0;
	f2A0 = fopen("2A0.txt", "w+");

	FILE *f2A100;
	f2A100 = fopen("2A100.txt", "w+");

	FILE *f2A2500;
	f2A2500 = fopen("2A2500.txt", "w+");

	FILE *f2AM;
	f2AM = fopen("2AM.txt", "w+");

	ArchOut(f2A0, T);
	fclose(f2A0);
	fprintf(f2AM, "%f %f \n", t0, mean(T)); 

	//ARCHIVOS PERIÓDICAS

	FILE *f2P0;
	f2P0 = fopen("2P0.txt", "w+");

	FILE *f2P100;
	f2P100 = fopen("2P100.txt", "w+");

	FILE *f2P2500;
	f2P2500 = fopen("2P2500.txt", "w+");

	FILE *f2PM;
	f2PM = fopen("2PM.txt", "w+");

	ArchOut(f2P0, T);
	fclose(f2P0);
	fprintf(f2PM, "%f %f \n", t0, mean(T)); 

//----------------------------------------------------------------------------------------------//


//F2
	i=0;
	while(i<2500/dt){

		F2(alpha,T,v_u);

		if(i==(100/dt-1)){
			ArchOut(f1F100,T);
		}

		else if((i==2500/dt-1)){
			ArchOut(f1F2500,T);
		}

		i+=1;
		fprintf(f2FM, "%f %f \n", dt*(i+1), mean(T));
		
	}


	fclose(f2F100);
	fclose(f2F2500);
	fclose(f2FM);


//A2
       	ini(50.0, 100.0, T);
       	ini(50.0, 100.0, Tcopy);

	i=0;
	while(i<2500/dt){

		A2(alpha,T,v_u);

		if(i==(100/dt-1)){
			ArchOut(f2A100,T);
		}

		else if(i==(2500/dt-1)){
			ArchOut(f2A2500,T);
		}

		i+=1;
		fprintf(f2AM, "%f %f \n", dt*(i+1), mean(T));
		
	}

	fclose(f2A100);
	fclose(f2A2500);
	fclose(f2AM);


//P2
       	ini(50.0, 100.0, T);
       	ini(50.0, 100.0, Tcopy);

	i=0;
	while(i<2500/dt){

		P2(alpha,T,v_u);

		if(i==100/dt-1){
			ArchOut(f1P100,T);
		}

		else if(i==2500/dt-1){
			ArchOut(f1P2500,T);
		}

		i+=1;
		fprintf(f1PM, "%f %f \n", dt*(i+1), mean(T));
		
	}

	fclose(f2P100);
	fclose(f2P2500);
	fclose(f2PM);



	return 0;
}



//-------------------------------------MÉTODOS---------------------------------------------------//

//Inicializar
void ini(float TPlaca, float TZona,float t[100][100]){
	int i;
	int j;
	for(j=0;j<100;j+=1){
		
		for(i=0;i<100;i+=1){
						//Distinto 45,55
			if(j<=40 && j>=20 && i>=20 && i<=30){
			
				t[j][i] = TZona;
			}
			else{
				t[j][i] = TPlaca;
			}
		}
	}
}

//Promedio
float mean(float t[100][100]){

	int i;
	int j;
        float mea;
	mea = 0.0;
	float norm;
	norm = 100.0*100.0;
                                	
	for(i=0; i<100; i++){
		for(j=0; j<100; j++){                                       
			mea+=t[i][j];
		}
	}
	
	return (float)(mea/norm);
}


//Imprimir
void ArchOut(FILE *archOut, float t[100][100]){

		int i;
		int j;
		for(i=0;i<100;i+=1){
			for(j=0;j<100;j+=1){
				fprintf(archOut, "%f \n", t[i][j]);
			}
		}
}


//Crear temporal
/*float makeT(float T[100][100]){

	int i;
	int j;
	float tt[100][100];

	for(i=0;i<100;i+=1){
		for(j=0;j<100;j+=1){
			
			t[i][j] = T[i][j];
		}

	}

	return TT[100][100];

}
*/

//-------------------------------------SOLUCIONES-----------------------------------------//

//Fijas caso 1
void F1(float alpha,float t[100][100],float v_u){

	int i;
	int j;

	float tt[100][100];

	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			tt[i][j] = t[i][j];
		}
	}


	for(i=1;i<99;i+=1){
		for(j=1;j<99;j+=1){
									//Distinto
			t[i][j] = alpha*v_u*(tt[i+1][j]+tt[i-1][j]+tt[i][j+1]+tt[i][j-1]-4*tt[i][j]) + tt[i][j];
		}
	}

}





//Fijas caso 2
void F2(float alpha,float t[100][100],float v_u){

	int i;
	int j;

	float tt[100][100];

	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			tt[i][j] = t[i][j];
		}
	}


	for(i=1;i<99;i+=1){
		for(j=1;j<99;j+=1){      //Distinto
			if(!(i>=20 && i<40 && j>=20 && j<30))
									//Distinto
			t[i][j] = alpha*v_u*(tt[i+1][j]+tt[i-1][j]+tt[i][j+1]+tt[i][j-1]-4*tt[i][j]) + tt[i][j];
		}
	}

}


//Periódicas caso 1
void P1(float alpha,float t[100][100],float v_u){

	int i;
	int j;

	float tt[100][100];

	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			tt[i][j] = t[i][j];
		}
	}

	for(i=0;i<100;i+=1){
		for(j=0;j<100;j+=1){
			
			t[i][j] = alpha*v_u*(tt[i][m(j+1)] + tt[i][m(j-1)] + tt[m(i+1)][j] + tt[m(i-1)][j] - 4*tt[i][j]) + tt[i][j];
		}

	}

}


//Periódicas caso 2
void P2(float alpha,float t[100][100],float v_u){

	int i;
	int j;

	float tt[100][100];

	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			tt[i][j] = t[i][j];
		}
	}

	for(i=0;i<100;i+=1){
		for(j=0;j<100;j+=1){
			
			if(!(i>=20 && i<40 && j>=20 && j<30)){
				t[i][j] = alpha*v_u*(tt[i][m(j+1)] + tt[i][m(j-1)] + tt[m(i+1)][j] + tt[m(i-1)][j] - 4*tt[i][j]) + tt[i][j];
			
			}
		}
	}
}





//Abiertas caso 1
void A1(float alpha,float t[100][100],float v_u){

	int i;
	int j;

	float tt[100][100];

	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			tt[i][j] = t[i][j];
		}
	}


	for(i=0;i<100;i+=1){
		for(j=0;j<100;j+=1){
			
			if(i==0 && j>0 && j<100){
				t[i][j] = alpha*v_u*(tt[i][j+1] + tt[i][j-1] + 2*tt[i+1][j] - 4*tt[i][j]) + tt[i][j];
			}

			if(i==100 && j>0 && j<100){
				t[i][j] = alpha*v_u*(tt[i][j+1] + tt[i][j-1] + 2*tt[i-1][j] - 4*tt[i][j]) + tt[i][j];
			}

			if(j==0 && i>0 && i<100){
				t[i][j] = alpha*v_u*(2*tt[i][j+1] + tt[i+1][j] + tt[i-1][j] - 4*tt[i][j])+ tt[i][j];
			}

			if(j==100 && i>0 && i<100){
				t[i][j] = alpha*v_u*(2*tt[i][j-1] + tt[i+1][j] + tt[i-1][j] - 4*tt[i][j])+ tt[i][j];	
			}
		
			
			if(i==0 && j==0){
				t[i][j] = alpha*v_u*(tt[i][1] + tt[1][j] - 2*tt[i][j]) + tt[i][j];
			}
			
			if(i==100 && j==0){
				t[i][j] = alpha*v_u*(tt[i][1] + tt[99][j] - 2*tt[i][j]) + tt[i][j];
			}

			if(i==0 && j==100){
				t[i][j] = alpha*v_u*(tt[i][99] + tt[1][j] - 2*tt[i][j])+ tt[i][j];
			}

			if(i==100 && j==100){
				t[i][j] = alpha*v_u*(tt[i][99] + tt[99][j] - 2*tt[i][j] + tt[0][0]);
			}
			
			else{
				t[i][j] = alpha*v_u*(tt[i][j+1] + tt[i][j-1] + tt[i+1][j] + tt[i-1][j] - 4*tt[i][j]) + tt[i][j];
			}

		}

	}




}


//Abiertas caso 2
void A2(float alpha,float t[100][100],float v_u){

	int i;
	int j;

	float tt[100][100];

	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			tt[i][j] = t[i][j];
		}
	}

	for(i=0;i<100;i+=1){
		for(j=0;j<100;j+=1){

			if(!(i>20 && i<40 && j>20 && j<30)){

				if(j>0&&j<100&&i==0){
					t[i][j] = alpha*v_u*(tt[i][j+1] + tt[i][j-1] + 2*t[i+1][j] - 4*t[i][j]) + tt[i][j];		
				}

				if(j>0&&j<100&&i==100){
					t[i][j] = alpha*v_u*(tt[i][j+1] + tt[i][j-1] + 2*tt[i-1][j] - 4*tt[i][j]) + tt[i][j];
				}

				if(i>0&&i<100&&j==0){
					t[i][j] = alpha*v_u*(2*tt[i][j+1] + tt[i+1][j] + tt[i-1][j] - 4*tt[i][j])+ tt[i][j];
				}

				if(i>0&&i<100&&j==100){
					t[i][j] = alpha*v_u*(2*tt[i][j-1] + tt[i+1][j] + tt[i-1][j] - 4*tt[i][j]) + tt[i][j];
				}

				if(i==0 && j==0){
					t[i][j] = alpha*v_u*(tt[i][1] + tt[1][j] - 4*tt[i][j]) + tt[i][j];
				}
			
				if(i==100 && j==0){
					t[i][j] = alpha*v_u*(tt[i][1] + tt[99][j] - 4*tt[i][j]) + tt[i][j];
				}

				if(i==0 && j==100){
					t[i][j] = alpha*v_u*(tt[i][99] + tt[1][j] - 4*tt[i][j])+ tt[i][j];
				}

				if(i==100 && j==100){
					t[i][j] = alpha*v_u*(tt[i][99] + tt[99][j] - 4*tt[i][j] + tt[0][0]);
				}
			

				if(i>0&&i<100&&j>0&&j<100){
					t[i][j] = alpha*v_u*(tt[i][j+1] + tt[i][j-1] + tt[i+1][j] + tt[i-1][j] - 4*tt[i][j]) + tt[i][j];
				}
			}
			 
			else{
				t[i][j] = 100;
			}
		}

	}

}





int m(int i)
{	
	int resp;
	  
	resp = i % 100;
	
	if(resp < 0)
	{
		resp =99;
	}
	return resp;
}






























