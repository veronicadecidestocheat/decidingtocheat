#include<stdio.h>
#include<math.h>
main(){
	float A[4][5]={{8,10,12,8,7},{12,11,9,14,4}, {18,12,16,6,8},{13,9,12,16,15}}, T[5], G=0, cf, x, t=0;
	int i, j, n=20, v=4, b=5;
	for(i=0; i<4;i++){
		T[i]=0;
		for(j=0; j<5; j++){
			G+=A[i][j];
			T[i] += A[i][j];
			
			t+=A[i][j]*A[i][j];
		}

		x+=T[i]*T[i]/5;
		
	}
	cf=G*G/n;
	float SST = x-cf;
	float TSS = t-cf;
	float SSE=TSS-SST;
    float MSST= SST/3, MSSE=SSE/16, f = MSST/MSSE;
	printf("\t One-Way ANOVA Table");
	printf("\nS.V. \t  df \t  SS \t MSS \t F-Statistic \nTreatment 3 \t %.2f \t %.2f \nError \t 16 \t %.2f  %.2f \t %.2f\nTotal \t 19 \t %.2f ", SST, MSST,SSE, MSSE, f, TSS );

}

