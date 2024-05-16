#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Function for inner product
double inn_prod(double *x,double *y,int n)
{
	int i;
	double ans;
	for(i=0;i<n;i++)
		ans=ans+x[i]*y[i];
	return ans;
}
//Function for Normalizing
void normalize(double *x,int n)
{
	double norm;
	norm=sqrt(inn_prod(x,x,n));
	for(int i=0;i<n;i++)
		x[i]=x[i]/norm;
}
//Function for Gram-Schmidth Orthogonalization Process
void gram(double **q,int m,int n)
{
	int i,j,k;
	double sf;     //scaling function
	for(i=1;i<m;i++)
	{
		for(j=0;j<i;j++)
		{
			sf=inn_prod(q[i],q[j],n)/inn_prod(q[j],q[j],n);
			for(k=0;k<n;k++)
				q[i][k]-=sf*q[j][k];
		}
	}
	for(i=0;i<m;i++)
		normalize(q[i],n);
}
//Main Function
main()
{
	int i,j,m,n;
	printf("Enter the number of arrays:");
	scanf("%d",&m);
	printf("Enter the number of elements in each array:");
	scanf("%d",&n);
	double **arr = (double **)malloc(m * sizeof(double *));
	for(i=0;i<m;i++)
		arr[i] = (double *)malloc(n * sizeof(double));
	printf("\nEnter the vector row-wise: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%lf",&arr[i][j]);
	}
	gram(arr,m,n);
	printf("\nThe Gram-Schmidth Orthogonalization Process: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("\t%.4lf",arr[i][j]);
		printf("\n");
	}
	for(i=0;i<m;i++)
		free(arr[i]);
	free(arr);
}
