#include<stdio.h>
#include<math.h>
main()
{
	float phat,qhat,p,q,z,n,N,ul,ll;
	printf("Enter the total number of throws N: ");
	scanf("%f",&N);
	printf("Enter the number of times the value is observed n: ");
	scanf("%f",&n);
	p=1.0/3.0;
	q=1-p;
	phat=n/N; 
	qhat=1-phat;
	printf("\nWe set up the following hypothesis: ");
	printf("\n\nHo: Population Proportion is equal to %.4f",p);
	printf("\nH1: Population Proportion is not equal to %.4f",p);
	z=(phat-p)/sqrt(p*q/N);
	printf("\n\nThe value of the test statistic is %.4f",z);
	if(z>1.96)
	{
		printf("\nWe reject Ho at 5percent level of significance and conclude that Population Proportion is not equal to %.4f",p);
	}
	else
	{
		printf("\nWe may accept Ho at 5percent level of significance and conclude that Population Proportion is equal to %.4f",p);
	}
	ul=phat+1.96*sqrt(p*q/N);
	ll=phat-1.96*sqrt(p*q/N);
	printf("\n\n95percent Confidence Interval for Population Proportion is: (%.4f,%.4f)",ll,ul);
}
