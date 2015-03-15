#include<stdio.h>
#include<string.h>

int main()
{
	short int j;
	long test_cases,i;
	int D,N;
	char num[10];
	scanf("%ld",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		D=0;
		N=0;
		scanf("%s",&num);
		for(j=0;j<strlen(num);j++)
		{
			if((num[j]-'0')%2==0)
			{
				D+=(j+1);
			}
			else
			{
				N+=(j+1);
			}
		}
		printf("%ld. %d %d\n",i+1,D,N);
	}
	return 0;
}