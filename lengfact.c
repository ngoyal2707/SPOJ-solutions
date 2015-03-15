#include<stdio.h>
#include<math.h>

/*
Very easy problem, just use stirling formula
with logarithm to calculate number of digits

Precompute all the constant values to get 
the best result (of course)
*/

int main()
{
	int test_cases=0,i;
	double result,number,pi,e,A,B;
	unsigned long long int resultInt;

	int y;

	pi=3.1415926535;
	/*
	e value is required to be of high precision
	since it's log value gets multiplied by the
	given number in the final answer
	*/
	e=2.71828182845904523536;

	A=log10(2.0*pi);
	A=A/2;
	B=log10(e);

	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		scanf("%lf",&number);
		if(number==1 || number == 0)
		{
			resultInt=1;
		}
		else
		{
			result=(number+0.5)*log10(number);
			result=result+A-(number*B);
			resultInt=(unsigned long long int)(result);
			resultInt++;
		}
		printf("%lld\n",resultInt);
	}
	return 0;
}
