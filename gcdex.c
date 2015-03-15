//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#define PRIME_COUNT 1000
//#define MAX 1000010
//
//int main()
//{
//	long long unsigned int number,G[MAX];
//	long sieveArray[PRIME_COUNT],primes[PRIME_COUNT],prime_count=0;
//	int i=2,j,k;
//	long phi[MAX], temp,tempNumber;
//	int isNumberPrime;
//	memset(sieveArray,0,PRIME_COUNT*sizeof(long));
//
//	while(1)
//	{
//		if(i>PRIME_COUNT)
//			break;
//		if(sieveArray[i]==0)
//		{
//			primes[prime_count++]=i;
//			for(j=i;j<PRIME_COUNT;j=j+i)
//			{
//				sieveArray[j]=1; 
//			}
//		}
//		i++;
//	}
//
//	for(i=1;i<MAX;i++)
//	{
//		phi[i]=i;
//		temp=sqrt((double)i);
//		tempNumber=i;
//		for(j=0;primes[j]<=temp;j++)
//		{
//			if(tempNumber%primes[j]==0)
//			{
//				phi[i]*=(primes[j]-1);
//				phi[i]/=primes[j];
//				while(tempNumber%primes[j]==0)
//					tempNumber=tempNumber/primes[j];
//				temp=sqrt((double)tempNumber);
//			}
//		}
//		if(tempNumber!=1)
//		{
//			phi[i]*=(tempNumber-1);
//			phi[i]/=tempNumber;
//		}
//	}
//
//
//	for (i = 2; i < MAX; ++i) G[i] = phi[i];
//	G[0]=0;
//	G[1]=0;
//
//	for (i = 2; i * i < MAX; ++i)
//	{
//		for (k = i + 1; i * k < MAX; ++k)
//			G[i * k] += phi[k] * i + phi[i] * k;
//		G[i * i] += phi[i] * i;
//	}
//	for (i = 2; i < MAX; ++i) G[i] += G[i - 1];
//
//	while(1)
//	{
//		scanf("%lld",&number);
//		if(number==0 || number == EOF)
//		{
//			break;
//		}
//		
//		printf("%lld\n",G[number]);
//	}
//	return 0;
//}