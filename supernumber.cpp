#include<stdio.h>
#define MAX 100000

long n,numbers[MAX];
long res_len,result[MAX];

long search(long s[],long low,long high, long x)
{
	long half,required_index;
	while(low<=high)
	{		
		half=(low+high)/2;
		if(numbers[s[half]]>=x)
		{
			high=half-1;
			required_index=half;
		}
		else
		{
			low=half+1;
		}
	}
	return required_index;
}

void findResult(long dp[], long s_length)
{
	long i;
	for(i=n-1;i>=0;i--)
	{
		if(dp[i]==s_length)
		{
			result[numbers[i]]=1;
		}
	}
}

void solve()
{
	long i,current;
	long s[MAX], s_length=0, index,dp[MAX];
	//long parent[MAX];
	for(i=0;i<n;i++)
	{
		if((s_length==0)||(numbers[i]>numbers[s[s_length-1]]))
		{
			s[s_length]=i;
			//parent[i]=s[s_length-1];
			dp[i]=s_length;

			s_length++;
		}
		else 
		{
			index=search(s,0,s_length,numbers[i]);
			s[index]=i;
			//parent[i]=s[index-1];
			dp[i]=index;
		}
	}
	/*current=s[s_length-1];
	for(i=0;i<s_length;i++)
	{
		result[res_len++]=numbers[current];
		current=parent[current];
	}*/
	findResult(dp,s_length);
}

int main()
{
	int i;
	long j;
	
	for(i=0;i<10;i++)
	{
		scanf("%ld",&n);
		for(j=0;j<n;j++)
		{
			scanf("%ld",&numbers[j]);
		}
		solve();
	}
	return 0;
}



//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int a[100010], N;
//int b[100010], K;
//int inc[100010], dec[100010];
//
//int main()
//{
//	for (int cs = 1; cs <= 10 && scanf("%d", &N) == 1 && N > 0; cs++) {
//		for (int i = 0; i < N; i++)
//			scanf("%d", &a[i]);
//
//		K = 0;
//		for (int i = 0; i < N; i++) {
//			int left = -1, right = K;
//			while (right - left > 1) {
//				int mid = (left + right) / 2;
//				if (b[mid] > a[i])
//					right = mid;
//				else
//					left = mid;
//			}
//			inc[i] = right+1;
//			b[right] = a[i];
//			if (right == K) K++;
//		}
//
//		K = 0;
//		for (int i = N-1; i >= 0; i--) {
//			int left = -1, right = K;
//			while (right - left > 1) {
//				int mid = (left + right) / 2;
//				if (b[mid] < a[i])
//					right = mid;
//				else
//					left = mid;
//			}
//			dec[i] = right+1;
//			b[right] = a[i];
//			if (right == K) K++;
//		}
//
//		//printf("  a="); for (int i = 0; i < N; i++) printf(" %d", a[i]); printf("\n");
//		//printf("inc="); for (int i = 0; i < N; i++) printf(" %d", inc[i]); printf("\n");
//		//printf("dec="); for (int i = 0; i < N; i++) printf(" %d", dec[i]); printf("\n");
//
//		int len = inc[0];
//		for (int i = 0; i < N; i++)
//			if (inc[i] > len) len = inc[i];
//
//		vector<int> out;
//		for (int i = 0; i < N; i++)
//			if (inc[i] + dec[i] - 1 == len)
//				out.push_back(a[i]);
//
//		sort(out.begin(), out.end());
//
//		printf("%d\n", out.size());
//		for (int i = 0; i < (int)out.size(); i++)
//			printf(i == 0 ? "%d" : " %d", out[i]);
//		printf("\n");
//	}
//}