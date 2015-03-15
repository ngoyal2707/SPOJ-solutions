#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define PRIME_COUNT 1010
#define MAX 1000010


int main()
{
	long unsigned int number;
	long int sieveArray[PRIME_COUNT],primes[PRIME_COUNT];
	long int prime_count;
	long i=2,j,test_cases;
	long long tempNumber;
	long long int *phi=(long long int *)calloc(1,MAX*sizeof(long long int ));
	long long int *lcmsum=(long long int *)calloc(1, MAX*sizeof(long long int ));
	long long int res;
	prime_count=0;


	scanf("%ld",&test_cases);


	phi[1]=1;
	for( i=2;i<MAX;i++){
		if( phi[i]==0){
			phi[i] = i-1;
			for( j = i*2; j<MAX; j+=i){
				if( phi[j] == 0 )phi[j] = j;
				phi[j] /= i ;
				phi[j] *= (i-1) ;
			}
		}
	}
	for(i=1;i <= MAX ; i++) 
		for (j = i ; j <= MAX ; j += i  ) 
			lcmsum[j]+= i*phi[i];

	for(i=0;i<test_cases;i++)
	{
		scanf("%ld",&number);
		res=lcmsum[number]+1;
		number=number>>1;
		res*=number;
		printf("%lld\n",res);
	}
	return 0;
}


//for(j=1;j*j<=number;j++)
//		{
//			if(number%j==0)
//			{
//				res+=j*phi[j];
//				if(j*j!=number)
//				{
//					tempNumber=number/j;
//					res+=tempNumber*phi[tempNumber];
//				}
//			}
//		}
//		res+=1;
//		res*=number;
//		res/=2;

 
//typedef long long ll;
// 
// 
//ll pfactor[MAXN+1];
//ll mcount[MAXN+1];
//ll mv[MAXN+1];



//#define MAXN 1010
//int main(){
//  
//	
////long long int *pfactor=(long long int *)calloc(1, MAXN*sizeof(long long int ));
//	long long int pfactor[MAXN];
//long long int *mcount=(long long int *)calloc(1, MAXN*sizeof(long long int ));
//long long int *mv=(long long int *)calloc(1, MAXN*sizeof(long long int ));
//long i,j,k,n,t;
//long long int res;
//    mv[1]=1;
//    
//    for(i=1;i<=MAXN;++i) pfactor[i]=i;
//    
//    for(i=2;i*i<=MAXN;++i)
//      if(pfactor[i]==i)
//       for(j=i+i;j<=MAXN;j+=i)
//         if(pfactor[j]==j)
//           pfactor[j]=i;
//           
//    for(i=2;i<=MAXN;++i){
//        k = i;
//        mcount[i]=1;
//        while(k%pfactor[i]==0){
//          mcount[i] *= pfactor[i];
//          k/=pfactor[i];
//        }
//    }
//    
//    for(i=2;i<=MAXN;++i){
//      mv[i] = mv[i/pfactor[i]]+mcount[i]*(mcount[i]-mcount[i]/pfactor[i])*mv[i/mcount[i]];
//    }
// 
//    
//    t;
//    scanf("%d",&t);
//    
//    while(t--){
//       scanf("%d",&n);
//      res = mv[n]-1;
//      if(res%2==0) { res/=2; res*=n;}
//      else {
//          res *= n/2;
//      }
//      res +=n;
//      
//      if(t)
//      printf("%lld\n",res);
//      else
//      printf("%lld",res);
//    }
//        
//    return 0;
//}                          