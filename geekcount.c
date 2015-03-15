#include<stdio.h>
unsigned long long int myPow(unsigned long long int N, unsigned long long int k)
{
	unsigned long long int result;
	if(k==0)
		return 1;
	if(k==1)
		return N;
	result=myPow(N,k>>1);
	if(k%2==1)
		return result*result*N;
	return result*result;

}
unsigned long long int solveForLessThan(unsigned long long int N)
{
	unsigned long long int result,temp_N;
	int power=0,digits[20],flag=0;
	temp_N=N;
	result=0;
	while(temp_N/10!=0)
	{
		result+=myPow(5,power+1);
		digits[power]=temp_N%10;
		power++;
		temp_N=temp_N/10;
	}
	digits[power]=temp_N;
	while(power>0)
	{
		if(digits[power]%2==0)
		{
			result+=(digits[power]/2)*myPow(5,power);
			flag=1;
			break;
		}
		else
		{
			flag=0;
			result+=(digits[power]/2)*myPow(5,power);
		}
		power--;
	}
	if(!flag)
	{
		result+=((digits[power]+1)/2);
	}
	return N-result;
}

int main()
{
	int test_cases;
	unsigned long long int L,R;
	
	
	for(scanf("%d",&test_cases);test_cases>0;test_cases--)
	{
		scanf("%llu",&L);
		scanf("%llu",&R);
		printf("%llu\n",(solveForLessThan(R)-solveForLessThan(L-1)));

	}
}