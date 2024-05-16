#include<stdio.h>
main()
{
	int i,j,k;
	float a,c,A[2][2],B[2][2],C[2][2],D[2][2],m,e;
	printf("Enter the probability of students who do Maths during one period and will do Maths in the next study period: ");
	scanf("%f",&a);
	float b=1-a;
	printf("Probability of students who do Maths during one peruid and will do English in the next study period: %.1f",b);
	printf("\nEnter the probability of students who do English during one period and will do English in the next study period: ");
	scanf("%f",&c);
	float d=1-c;
	printf("Probability of students who do English during one period and will do Maths in the next study period: %.1f",d);
	printf("\nThe Transition Probability Matrix is: \n");
	A[0][0]=a; A[0][1]=b; A[1][0]=d; A[1][1]=c;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%.1f\t",A[i][j]);
		printf("\n");
	}
	printf("\nEnter the number of students who do maths work: ");
	scanf("%f",&m);
	printf("\Enter the number of students who do english work: ");
	scanf("%f",&e);
	B[0][0]=m; B[0][1]=e; B[1][0]=0.0; B[1][1]=0.0;
	printf("\nNext study period is given by: \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			C[i][j]=0.0;
			for(k=0;k<2;k++)
			{
				C[i][j]+=B[i][k]*A[k][j];
			}			
		}
	}
	for(i=0;i<1;i++)
	{
		for(j=0;j<2;j++)
		printf("%0.0f\t",C[i][j]);
		printf("\t");
	}
	printf("\nNext-to-next study period is given by: \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			D[i][j]=0.0;
			for(k=0;k<2;k++)
			{
				D[i][j]+=C[i][k]*A[k][j];
			}
		}
	}
	for(i=0;i<1;i++)
	{
		for(j=0;j<2;j++)
		printf("%0.0f\t",D[i][j]);
		printf("\t");
	}
}

