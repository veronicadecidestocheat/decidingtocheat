//initial vector with all elements as one. Find the dominant eigenvalue and eigenvector for the following matrix, 4x4, c(power,method)
//M=((2,-1,0,0),(-1,2,-1,0),(0,-1,2,-1),(0,0,-1,2)) X0=(1,1,1,1)
#include<stdio.h>
#include<math.h>
#define SIZE 5
void matrixVectorMult(double matrix[SIZE][SIZE],double vector[SIZE],double result[SIZE])
{
	int i,j;
	for(i=0;i<SIZE;i++)
	{
		result[i]=0;
		for(j=0;j<SIZE;j++)
		{
			result[i]+=matrix[i][j]*vector[j];}}}
double vectorMagnitude(double vector[SIZE])
{
	double sum=0;
	int i;
	for(i=0;i<SIZE;i++)
	{
		sum+=vector[i]*vector[i];
	}
	return sqrt(sum);}
void normalizeVector(double vector[SIZE])
{
	double magnitude=vectorMagnitude(vector);
	int i;
	for(i=0;i<SIZE;i++)
	{
		vector[i]/=magnitude;
}}
double dominantEigenvalue(double matrix[SIZE][SIZE],double initialVector[SIZE],double eigenVector[SIZE])
{
	double currentVector[SIZE];
	double eigenvalue=0;
//Initialize the current vector with the initial vector
	int i;
	for(i=0;i<SIZE;i++)
	{
		currentVector[i]=initialVector[i];}
//Power Method Iterations
	int iter=0;
	for(iter=0;iter<1000;iter++) //Adjust the no. of iterations as needed
	{
		matrixVectorMult(matrix,currentVector,eigenVector);
		eigenvalue=vectorMagnitude(eigenVector);
		normalizeVector(eigenVector);
//Check for Convergence
	double error=0;
	for(int i=0;i<SIZE;i++)
	{
		error+=fabs(currentVector[i]-eigenVector[i]);}
	if(error<1e-6)
	{
		break;}
//Update the current vector for the next iteration
	for(i=0;i<SIZE;i++)
	{
		currentVector[i]=eigenVector[i];
	}
	}
	return eigenvalue;}

int main()
{
	double matrix[SIZE][SIZE]={{2,-1,0,0},{-1,2,-1,0},{0,-1,2,-1},{0,0,-1,2}};
	double initialVector[SIZE]={1,1,1,1};
	double eigenVector[SIZE];
	double eigenvalue=dominantEigenvalue(matrix,initialVector,eigenVector);
	
	printf("Dominant Eigenvalue: %lf\n",eigenvalue);
	printf("\nEigenvector: ");
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("%lf",eigenVector[i]);
		printf("\t");
	}
	printf("\n");
	return 0;
}

