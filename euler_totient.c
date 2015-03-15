#include<stdio.h>
#include<string.h>
#include<math.h>
#define PRIME_COUNT 1010

int main()
{
	long unsigned int number;
	long sieveArray[PRIME_COUNT],primes[PRIME_COUNT],prime_count=0;
	int i=2,j,test_cases;
	long phi, tempNumber;

	memset(sieveArray,0,PRIME_COUNT*sizeof(long));

	while(1)
	{
		if(i>=PRIME_COUNT)
			break;
		if(sieveArray[i]==0)
		{
			primes[prime_count++]=i;
			for(j=i;j<PRIME_COUNT;j=j+i)
			{
				sieveArray[j]=1; 
			}
		}
		i++;
	}


	scanf("%d",&test_cases);

	for(i=0;i<test_cases;i++)
	{
		scanf("%ld",&number);

		if(number!=0)
		{
			phi=number;
			tempNumber=number;
			for(j=0;primes[j]*primes[j]<=tempNumber;j++)
			{
				if(tempNumber%primes[j]==0)
				{
					phi*=(primes[j]-1);
					phi/=primes[j];
					while(tempNumber%primes[j]==0)
						tempNumber=tempNumber/primes[j];
				}
			}
			if(tempNumber!=1)
			{
				phi*=(tempNumber-1);
				phi/=tempNumber;
			}
		}
		else 
			phi =number;

		printf("%ld\n",phi);
	}
	return 0;
}