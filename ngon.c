#include<stdio.h>
#define MAX 1010
#define MODULO 1000000007

int main()
{
	int test_cases,i,a,b;
	int sides,points[MAX],precalculate[MAX];
	unsigned long long int result[MAX][MAX],temp;
	for(scanf("%d",&test_cases);test_cases>0;test_cases--)
	{
		scanf("%d",&sides);
		for(i=0;i<sides;i++)
		{
			scanf("%d",&points[i]);
			precalculate[i]=points[i]*(points[i]-1)/2;
		}

		result[0][0]=1;
		for(a=1;a<=sides;a++)
		{
			result[a][0]=1;
			result[0][a]=0;
		}

		for(a=1;a<=sides;a++)
		{
			for(b=1;b<=sides;b++)
			{
				if(b>2*a)
				{
					result[a][b]=0;
				}
				else
				{
					result[a][b]=(result[a-1][b]+result[a-1][b-1]*points[a-1]);
					if(b>1)
					{
						temp=result[a-1][b-2]*precalculate[a-1];
						result[a][b]=(result[a][b]+temp)%MODULO;
					}
				}
			}
		}
		printf("%lld\n",result[sides][sides-1]);
	}
	return 0;
}