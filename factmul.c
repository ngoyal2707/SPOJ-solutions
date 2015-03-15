#include<stdio.h>
#define MODULO 109546051211
#define MODULO 109546051211
#define MODULO 109546051211

int main()
{
	long int n,i;
	unsigned long long int fact,result;
	scanf("%ld",&n);
	if(n>=587117)
	{
		printf("0");
	}
	else
	{
		fact=1;
		result=1;
		for(i=2;i<=n;i++)
		{
			fact=(fact*i)%MODULO;
			result=(result*fact)%MODULO;
		}
		printf("%llu",result);
	}
	return 0;
}