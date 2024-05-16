#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
main()
{
	float u[500],sum=0.0,sum1=0.0,sum2=0.0,sum3=0.0,sum4=0.0,m[500],m2[500],v[500],ovmean,ovvar,z[100],X[100],mle_m,mle_v;
	int i,j,k,n,mu,sig;
	printf("Enter the value of mu and sigma2: ");
	scanf("%d%d",&mu,&sig);
	printf("\nEnter the size of the sample: ");
	scanf("%d",&n);
	srand(time(NULL));
	for(k=0;k<50;k++)
	{
		for(j=0;j<n;j++)
		{
			sum=0.0;
			for(i=0;i<500;i++)
			{
				u[i]=rand()/(1.0+RAND_MAX);
				sum+=u[i];
			}
			z[j]=(sum-250)/sqrt(500/12);
			X[j]=z[j]*sqrt(sig)+mu;
		}
		sum1=0.0,sum2=0.0;	
		for(j=0;j<n;j++)
		{
			sum1+=X[j];
			sum2+=X[j]*X[j];
		}
		m[k]=sum1/n;
		
		v[k]=sum2/n-m[k]*m[k];
		sum3+=m[k];
		sum4+=v[k];
	}
	mle_m=sum3/50;
	mle_v=sum4/50;
 
printf("mle of mean is: %.2f ",mle_m);
printf("mle of variance is: %.2f ",mle_v);
}
