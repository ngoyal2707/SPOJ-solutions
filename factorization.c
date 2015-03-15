/*
solving fact2 problem with Pollard's Rho method
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX_INPUT 22
#define BASE 10
#define MAX_FACTORS 1000

long long gcd(long long x, long long y)
{
	long long temp;
	if(x>y)
	{
		temp=x;
		x=y;
		y=temp;
	}
	while(x!=0)
	{
		temp=x;
		x=y%x;
		y=temp;

	}
	return y;
}

long long findFactors(long long low_number)
{

	long long xi,x2i,d,c;
	xi=1;
	c=7;
	x2i=((xi+xi)+c)%low_number;
	d=1;
	while(d==1)
	{
		xi=((xi*xi)+c)%low_number;
		x2i=((x2i*x2i)+c)%low_number;
		x2i=((x2i*x2i)+c)%low_number;
		d=gcd(abs((double)(x2i-xi)),low_number);
	}
	return d;
}

int main()
{
	short int num_len;
	long i,sqrt_number=0;
	long long low_number=0,high_number=0,newFactor;
	char num_buff[MAX_INPUT];

	long result[MAX_FACTORS][2];
	long factorCount=0;

	while(1)
	{
		factorCount=0;
		memset(result,0,MAX_FACTORS*2);

		low_number=0;
		high_number=0;
		scanf("%s",&num_buff);
		num_len=strlen(num_buff);

		for(i=0;i<(num_len<BASE?num_len:BASE);i++)
		{
			low_number=low_number*10+(num_buff[i]-'0');
		}
		for(;i<num_len;i++)
		{
			high_number=high_number*10+(num_buff[i]-'0');
		}

		if((low_number==0)&&(high_number==0))
		{
			break;
		}
		newFactor=0;
		while(newFactor!=1)
		{
			newFactor=findFactors(low_number);
			if(newFactor!=1)
			{
				result[factorCount][0]=newFactor;
				while((low_number%newFactor)==0)
				{	
					result[factorCount][1]++;
					low_number=low_number/newFactor;
				}
				factorCount++;
			}
		}
	}
	return 0;	
}

