#include<stdio.h>
#include<string.h>
#include<math.h>

long gcd(long a, long b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int B_len;
	long test_cases,i,j;
	long A,B[250],temp;
	char buff[255];
	long power,remainder,result;

	scanf("%ld",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		scanf("%ld",&A);
		scanf("%s",&buff);

		memset(B,0,250*sizeof(long));
		B_len=strlen(buff);

		for(j=0;j<B_len;j=j++)
		{
			B[j]=(buff[j]-'0');
		}

		if(A!=0)
		{
			remainder=0;
			for(j=0;j<B_len;j++)
			{
				temp=remainder*10+B[j];
				remainder=temp%A;
			}
			result=gcd(remainder,A);
			printf("%ld\n",result);
		}
		else
		{
			for(j=0;j<B_len;j++)
			{
				printf("%ld",B[j]);
			}
			printf("\n");
		}
	}
	return 0;
}