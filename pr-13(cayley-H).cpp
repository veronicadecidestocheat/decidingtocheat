#include<stdio.h>
main()
{
	int i,j,k,n,c;
	int A[4][4],A2[4][4],A3[4][4],A4[4][4],I[4][4],d[4][4];
	printf("Enter the order of the matrix: ");
	scanf("%d",&n);
	printf("\nEnter the elements of the Matrix row-wise: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("\nEnter the elements of identity matrix row-wise: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&I[i][j]);
	}
	printf("\nThe characteristic equation for the given matrix is: (lambda^4)-(8*lambda^3)+(21*lambda)+5=0");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A2[i][j]=0;
			for(k=0;k<n;k++)
				A2[i][j]=A2[i][j]+(A[i][k]*A[k][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A3[i][j]=0;
			for(k=0;k<n;k++)
				A3[i][j]=A3[i][j]+(A2[i][k]*A[k][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A4[i][j]=0;
			for(k=0;k<n;k++)
				A4[i][j]=A4[i][j]+(A3[i][k]*A[k][j]);
		}
	}
	c=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d[i][j]=A4[i][j]-(8*A3[i][j])+(21*A2[i][j])-(20*A[i][j])+(5*I[i][j]);
			if(d[i][j]!=0)
			{
				c=0;
				break;
			}
		}
	}
	if(c)
		printf("\nThe given matrix satisfied the Cayley-Hamilton Theorem, i.e., (A^4)-(8*A^3)+(21*A^2)-(20*A)+(5*I)=0");
	else
		printf("\nThe given matrix does not satisfy the Cayley-Hamilton Theorem, i.e., (A^4)-(8*A^3)+(21*A^2)-(20*A)+(5*I)=0");
}

