#include<stdio.h>
#include<time.h>

unsigned long long Power( unsigned long long a,unsigned long long power,unsigned long long mod)
{
	unsigned long long half,temp;
	if(power == 1)
		return a%mod;
	if(power ==2)
		return ((a*a)%mod);
	half = Power(a, power>>1 , mod);
	if(power&1)
		return (((half*half) % mod)*a)%mod;
	else
	{
		temp = half*half;
		temp = temp%mod;
		return temp;
	}
}

int main()
{
	const char default_format[] = "%a %b %d %T %Y";
	const char *format = default_format;
	char result[80];
	unsigned long long x,k,a,p;
	time_t rawtime;
	struct tm *info;
	p=4000000007;
	k=1000000001;
	scanf("%lld",&a);
	rawtime= Power(a,k+1,p);
	info = gmtime(&rawtime);
	
	if(!((info->tm_year>= 70)&&(info->tm_year <=130)))
	{
		rawtime=p-rawtime;
	}
	info = gmtime(&rawtime);
	strftime(result, sizeof(result), format, info); 
	printf("%s",result);
	return 0;
}