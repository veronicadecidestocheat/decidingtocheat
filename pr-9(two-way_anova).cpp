#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
	int k=0,b=0,n=0,a=0;
	float s,s2,G,cf,st,sb;
	float SST,TSS,SSE,MST,MSE,SSB;
	float F1,F2,MSB;
	printf("\nEnter the number of treatments\n");
	scanf("%d",&k);
	printf("\nEnter the number of blocks\n");
	scanf("%d",&b);
	n=k*b;
	printf("\nEnter the data\n");
	float A[k][b],t[k],bl[b];
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<b;j++)
	{
		scanf("%f",&A[i][j]);
	}
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<b;j++)
	{
		s=s+A[i][j];
		s2=s2+A[i][j]*A[i][j];
		G=G+A[i][j];
	}
	t[a]=s;
	st=st+t[a]*t[a];
	s=0;
	a++;
	}
	for(int j=0;j<b;j++)
	{
		for(int i=0;i<k;i++)
		{
			s=s+A[i][j];
		}
		bl[b]=s;
		sb=sb+bl[b]*bl[b];
		s=0;
	}
	cf=G*G/n;
	SST=st/b-cf;
	SSB=sb/k-cf;
	TSS=s2-cf;
	SSE=TSS-SST-SSB;
	MST=SST/(k-1);
	MSB=SSB/(b-1);
	MSE=SSE/(n-k-b+1);
	F1=MST/MSE;
	F2=MSB/MSE;
	printf("\nSST %f",SST);
	printf("\nSSB %f",SSB);
	printf("\nSSE %f",SSE);
	printf("\nF-ratio for treatments %f",F1);
	printf("\nF-ratio for treatments %f",F2);
	if(F1>6.94)
	{
		printf("\nReject Null hypotheses for treatments\n");
	}
	else
	{
		printf("\nAccept Null Hypotheses for treatments\n");
	}
	if(F2>6.94)
	{
		printf("\nReject Null hypotheses for blocks\n");
	}
	else
	{
		printf("\nAccept Null Hypotheses for blocks\n");
	}
}

