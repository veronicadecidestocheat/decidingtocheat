#include <stdio.h>
#include <math.h>
int main()
{
	int i,fi[15],ei;
	float tstat,tab=16.919,sum=0.0,x[15];
	printf("H0: Digits occur equally frequently");
	printf("\nEnter the Observed Frequencies:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&fi[i]);
		printf("\t");		
	}
	for(i=0;i<10;i++)
	{
		sum+=fi[i];
		ei=sum/10;
	}	
	for(i=0;i<10;i++)
	{
		x[i]=(pow((fi[i]-ei),2)/ei);
		tstat+=x[i];
	}
	printf("\n");
	printf("Digits\t\t\tFrequencies\t\tExpected Frequencies\tValue\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t\t\t%d\t\t\t%d\t\t\t%f\n",i,fi[i],ei,x[i]);
	}
	printf("Calculated Test Statistic is: %.5f\n",tstat);
	if(tstat>tab)
		printf("The Hypothesis is Rejected");
	else 
		printf("The Hypothesis may be accepted");
}

