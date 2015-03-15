#include<stdio.h>

unsigned long long int findCombination(long n,long r)
{
	long i,j;
	unsigned long long int  result=1;
	if(r>(n-r))
	{
		r=n-r;
	}
	for(i=1;i<=r;i++)
	{
		result*=(n-r+i);
		result/=i;
	}

	return result;
}
/*
Waste of time problem,just 
check why combinations will 
be n-1Ck-1. Calculation is 
easy.

*/
int main()
{
	unsigned short int i,test_cases;
	long n,k;
	unsigned long long int result;
	scanf("%hu",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		scanf("%ld",&n);
		scanf("%ld",&k);
		result=findCombination(n-1,k-1);
		printf("%lld\n",result);
	}
	return 0;
}