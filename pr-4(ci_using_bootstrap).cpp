#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,i,j,k;
	float mu,sd,mle_m,mle_v,u[500],z[100],X[100],ul,ll,ulv,llv;
	printf("Enter the Mean and Standard Deviation: ");
	scanf("%f%f",&mu,&sd);
	printf("\nEnter the size of the sample: ");
	scanf("%d",&n);
	srand(time(0));
	float summ=0.0,sumv=0.0,suml=0.0,sumu=0.0,sumlv=0.0,sumuv=0.0;
	for(k=0;k<500;k++)
	{
		for(j=0;j<n;j++)
		{
			float sum=0.0;
			for(i=0;i<500;i++)
			{
				u[i]=rand()/(1.0+RAND_MAX);
				sum+=u[i];
			}
			z[j]=(sum-250)/sqrt(500/12);
			X[j]=(z[j]*sd)+mu;
		}
		float sumz=0.0,sumz2=0.0,ml_m[500],ml_v[500],ul[500],ll[500],ulv[500],llv[500];
		for(j=0;j<n;j++)
		{
			sumz+=X[j];
			sumz2+=pow(X[j],2);
		}
		ml_m[k]=sumz/n;
		ml_v[k]=sumz2/n-(ml_m[k]*ml_m[k]);
		summ+=ml_m[k];
		sumv+=ml_v[k];
		//sumvb+=n*ml_v[k];
		ul[k]=ml_m[k]+1.96*0.5/sqrt(n);
		ll[k]=ml_m[k]-1.96*0.5/sqrt(n);
		suml+=ll[k];
		sumu+=ul[k];
		ulv[k]=n*ml_v[k]/13.11972;
		llv[k]=n*ml_v[k]/40.64647;
		sumlv+=ulv[k];
		sumuv+=llv[k];
	}
	mle_m=summ/500;
	printf("\nMean: %.6f",mle_m);
	mle_v=sumv/500;
	printf("\nVariance: %.6f",mle_v);
	ul=sumu/500;
	ll=suml/500;
	printf("\n95 Confidence Intervals for Mu is (%.6f,%.6f)",ll,ul);
	ulv=sumlv/500;
	llv=sumuv/500;
	printf("\n95 Confidence Intervals for Sigma2 is (%.6f,%.6f)",llv,ulv);
}

		

