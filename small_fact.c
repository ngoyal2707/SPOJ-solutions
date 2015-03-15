#include<stdio.h>
#define MAX 1000

long result[MAX], length;

void multiplyResult(int num)
{
	int i,temp,carry=0;
	for(i=0; i < length; i++)
	{
		temp= result[i]*num +carry;
		result[i]=temp%10;
		carry=temp/10;
	}
	while(carry!=0)
	{
		result[i]=carry%10;
		carry=carry/10;
		length++;
		i++;
	}
}

long factorial(int n)
{
	//if(n == 0 || n == 1)
	//	return 1;
	//return n*factorial(n-1);
	int i;
	length=1;
	result[0]=1;
	for(i =1;i<=n;i++)
	{
		multiplyResult(i);
	}
}
int main()
{
	int test,i,n,j;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%d",&n);
		factorial(n);
		for(j=length-1;j>=0;j--)
		{
			printf("%ld",result[j]);
		}
		printf("\n");
	}
	return 0;
}