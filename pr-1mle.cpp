#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
main()
{
	float u[500],sum=0.0,X[100],z,sum1=0.0,sum2=0.0,mean,sigma_hat;
	int i,j,mu,sig,n;
	printf("Enter the value of mu and sigma: ");
	scanf("%d%d",&mu,&sig);
	printf("\nEnter the size of the sample: ");
	scanf("%d",&n);
	srand(time(NULL));
	for(j=0;j<n;j++)
	{
		for(i=0;i<500;i++)
		{
			u[i]=rand()/(1.0+RAND_MAX);
			sum+=u[i];
		}
		z=(sum-250)/sqrt(500/12);
		X[j]=z*sig+mu;
		sum=0.0;
	}
	printf("\nThe %d random numbers from N(-5,1) are:\n",n);
	for(j=0;j<n;j++)
	{
		printf("%.3f",X[j]);
		printf("\t");
	}
//MLE of mu and sigma
	for(j=0;j<n;j++)
	{
		sum1+=X[j];
	}
	mean=sum1/n;
	printf("\n\nThe MLE of mu is: %.4f",mean);
	for(j=0;j<n;j++)
	{
		sum2+=(X[j]-mean)*(X[j]-mean);
		sigma_hat=sum2/(n-1);
	}
	printf("\n\nThe MLE of sigma is: %.4f",sigma_hat);
}
