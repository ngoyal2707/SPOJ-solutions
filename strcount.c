#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 64

int main()
{
	unsigned long long int f[MAX][MAX][MAX],res,prev;
	int i,j,k;
	memset(&f,0,sizeof(f));
	for(i=0;i<MAX;i++)
	{
		f[i][0][0]=1;
		f[i][1][0]=0;
	}
	f[1][1][1]=1;
	for(i=2;i<MAX;i++)
	{
		for(j=1;j<=i;j++)
		{
			for(k=0;k<=i-1;k++)
			{
				f[i][j][0]+=f[i-1][j][k];
			}
			for(k=1;k<=j;k++)
			{
				f[i][j][k]+=f[i-1][j][k-1];	
			}
			f[i][j][j]+=f[i-1][j-1][j-1];
		}
	}
	for(i=1;i<MAX;i++)
	{
		for(j=0;j<=i;j++)
		{
			res=0;
			for(k=0;k<=j;k++)
			{
				res+=f[i][j][k];	
			}
			printf("%llu\t",res);
		}
		printf("\n");
	}
	return 0;
}
