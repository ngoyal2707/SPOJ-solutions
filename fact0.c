#include<stdio.h>
#include<math.h>

int main()
{
	long long n,sqrt_n;
	long long i,j,powers;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		sqrt_n=sqrt((double)n);
		for(i=2;i<=sqrt_n;i++)
		{
			powers=0;
			if(n%i ==0)
			{
				while(n%i==0)
				{
					powers++;
					n=n/i;
				}
				printf("%lld^%lld ",i,powers);
				sqrt_n=sqrt((double)n);
			}
		}
		if(n!=1)
		{
			printf("%lld^%lld ",n,1);
		}
		printf("\n");
	}
	return 0;
}