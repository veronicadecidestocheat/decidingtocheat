#include<stdio.h>
#include<math.h>
main()
{
	float n1=400.0,n2=600.0,X1=200.0,X2=325.0,z;
	float p1=X1/n1;
	float p2=X2/n2;
	printf("\nWe set up the following hypothesis:\n");
	printf("\nHo:p1=p2,i.e.,the proportion of men who have agreed is equal to the proportion of women who have agreed");
	printf("\nH1:The proportion of men who have agreed is not equal to the proportion of women who have agreed");
	float p=(X1+X2)/(n1+n2);
	z=(p1-p2)/sqrt(p*(1-p)*((1/n1)+(1/n2)));
	printf("\n\nThe value of the test statistic is: %.4f",z);
	if(abs(z)<1.96)
	{
		printf("\n\nWe may accept Ho at 5percent level of significance and conclude that the proportion of men who have agreed is equal to the proportion of women who have agreed");
	}
	else
		printf("\n\nWe reject Ho at 5percent level of significance and conclude that the proportion of men who have agreed is not equal to the proportion of women who have agreed");
	if(abs(z)<2.58)
	{
		printf("\n\nWe may accept Ho at 1percent level of significance and conclude that the proportion of men who have agreed is equal to the proportion of women who have agreed");
	}
	else
		printf("\n\nWe reject Ho at 1percent level of significance and conclude that the proportion of men who have agreed is not equal to the proportion of women who have agreed");
//Confidence Intervals at 5% level of significance
	float ll=(p1-p2)-1.96*sqrt(p*(1-p)*((1/n1)+(1/n2)));
	float ul=(p1-p2)+1.96*sqrt(p*(1-p)*((1/n1)+(1/n2)));
	printf("\n\n95percent CI for difference of proportions is: (%.4f,%.4f)",ll,ul);
//Confidence Intervals at 1% level of significance
	float ll1=(p1-p2)-2.58*sqrt(p*(1-p)*((1/n1)+(1/n2)));
	float ul1=(p1-p2)+2.58*sqrt(p*(1-p)*((1/n1)+(1/n2)));
	printf("\n\n99percent CI for difference of proportions is: (%.4f,%.4f)",ll1,ul1);
}
