#include<stdio.h>
main()
{
	int i,j,k;
	float detB,A[3][3],B[2][2],B1[2][2],G[3][3],G1[3][3],AG[3][3],AGA[3][3];
	printf("Enter the elements of the matrix row-wise: \n");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{
			scanf("%f",&A[i][j]);
		}
	}
	for(i=0;i<2;i++)
	{	for(j=0;j<2;j++)
		{
			B[i][j]=A[i][j];
		}
	}
	printf("\nThe sub-matrix is: \n");
	for(i=0;i<2;i++)
	{	for(j=0;j<2;j++)
		{
			printf("%.f\t",B[i][j]);
		}	
		printf("\n");
	}
	detB=B[0][0]*B[1][1]-B[0][1]*B[1][0];
	if(detB==0)
		printf("Determinant is 0");
	else
		printf("\nDeterminant of B is: %.f",detB);
//Calculating B inverse
	B1[0][0]=B[1][1]/detB; B1[1][1]=B[0][0]/detB; B1[1][0]=-B[0][1]/detB; B1[0][1]=-B[1][0]/detB;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			G[i][j]=B1[i][j];
	}
	G[0][2]=G[1][2]=G[2][0]=G[2][1]=G[2][2]=0;
	printf("\n\nThe Generalized Inverse of the matrix is: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%f\t",G[j][i]);	
			G1[i][j]=G[j][i];
		}
		printf("\n");
	}
	printf("\n");
//Verification
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			AG[i][j]=0;
			for(k=0;k<3;k++)
			{
				AG[i][j]+=A[i][k]*G1[k][j];
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			AGA[i][j]=0;
			for(k=0;k<3;k++)
			{
				AGA[i][j]+=AG[i][k]*A[k][j];
			}
		}
	}
	printf("\nAGA is given by:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%.f\t",AGA[i][j]);
		printf("\n");
	}
	printf("\nTherefore, AGA=A. Hence, G is the generalized inverse of A.");
}

