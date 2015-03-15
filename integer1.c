#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1000000000000000000

unsigned long long int myPow(unsigned long long int N,unsigned long long int k)
{
	unsigned long long int result;
	if(k==0)
		return 1;
	if(k==1)
		return N;
	result=myPow(N,k>>1);
	if(k%2==0)
		return result*result;
	else
		return N*result*result;

}

int main()
{
	unsigned long long int a,b,result;
	unsigned long long int power[65],temp,temp1;
	int i,j;

	while(1)
	{
		memset(&power,0,sizeof(power));
		scanf("%llu",&a);
		scanf("%llu",&b);
		if(a==0)
			break;
		result=0;
		power[0]=0;
		power[1]=b-a+1;

		a--;
		for(i=2;i<64;i++)
		{
			power[i]=floor(pow((long double)b,(long double)1/i));
			while(myPow(power[i],i)>b)
			{
				power[i]--;
			}
			
			while(1)
			{
				if(pow((long double)(power[i]+1),(long double)i)>MAX)
				{
					break;
				}
				if(myPow((power[i]+1),i)<=b)
					power[i]++;
				else
					break;
			}

			temp=floor(pow((long double)a,(long double)1/i));
			while(myPow(temp,i)>a)
			{
				temp--;
			}
			while(1)
			{
				if(pow((long double)(temp+1),(long double)i)>MAX)
				{
					break;
				}
				if(myPow((temp+1),i)<=a)
					temp++;
				else
					break;
			}
			power[i]-=temp;
		}
		for(i=63;i>=1;i--)
		{
			for(j=i*2;j<64;j=j+i)
			{
				power[i]-=power[j];
			}
		}
		for(i=1;i<64;i++)
		{
			result+=i*power[i];
		}
		printf("%llu\n",result);
	}
	
	return 0;
}