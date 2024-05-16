#include<stdio.h>
#include<math.h>
int main()
{
	int i,n,x[20];
	float c,lb,ub,err,mean=0,var,sum1=0,sum2=0;
	printf("Enter the size of the sample: ");
	scanf("%d",&n);
	printf("\nEnter the data: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	printf("\nEnter the desired Confidence Level: ");
	scanf("%f",&c);
//Calculating the Mean and Variance
	for(i=0;i<n;i++)
	{
		sum1+=x[i];
	}
	mean=sum1/n;
	for(i=0;i<n;i++)
	{
		sum2+=pow((x[i]-mean),2);
	}
	var=sum2/13;
	printf("\nThe Mean of the data is: %.f",mean);
	printf("\nThe Variance of the data is: %.f",var);
//Calculating the Margin Error
	err=2.1603*sqrt(var/n);
//Calculating the Confidence Intervals
	lb=mean-err;
	ub=mean+err;
	printf("\nThe Confidence Interval is: (%.4f , %.4f)",lb,ub);
}
