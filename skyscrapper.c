#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5000
#define MODULO 10000000007
void solve(int N, int left, int right, unsigned long int **f,unsigned long int **prev)
{
	int i,j,k;
	prev[1][1]=1;
	for(i=2;i<=N;i++)
	{
		for(j=1;(j<=i)&&(j<=left);j++)
		{
			for(k=1;(k<=(i-j+1))&&(k<=right);k++)
			{
				f[j][k]=prev[j][k]*(i-2);
				f[j][k]+=prev[j-1][k];
				f[j][k]+=prev[j][k-1];
			}
		}
		for(j=1;(j<=i)&&(j<=left);j++)
		{
			for(k=1;(k<=(i-j+1))&&(k<=right);k++)
			{
				prev[j][k]=f[j][k];
			}
		}
	}
}

int main()
{

	int N,left,right,i,j;
	unsigned long int **f,**prev;

	f = (unsigned long int **)malloc(MAX * sizeof(unsigned long int *));
	prev = (unsigned long int **)malloc(MAX * sizeof(unsigned long int *));
	
	for (i = 0; i < MAX; i++)
	{
		f[i] = (unsigned long int *)malloc(MAX * sizeof(int));
		prev[i] = (unsigned long int *)malloc(MAX * sizeof(int));
	}	
	while(1)
	{
		for(i=0;i<MAX;i++)
		{
			for(j=0;j<MAX;j++)
			{
				prev[i][j]=0;
				f[i][j]=0;
			}
		}
		scanf("%d",&N);
		scanf("%d",&left);
		scanf("%d",&right);
		if(!N)
			break;
		solve(N,left,right,f,prev);
		printf("%lu\n",f[left][right]);
	}
}