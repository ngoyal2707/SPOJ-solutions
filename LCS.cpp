
// Author: ngoyal2707

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#define ALPHABET_SIZE 128
#define MAX 510015
using namespace std;
long givenString[MAX];

inline bool leq(long a1, long a2, long b1, long b2) 
{ 
	return(a1 < b1 || a1 == b1 && a2 <= b2); 
}
inline bool leq(long a1, long a2, long a3, long b1, long b2, long b3){ 
	return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3)); 
}

void radixSort(long *actualIndex,long *sortedIndex,long *str,long n,long K){
	long buckets[K+1];
	for(long i=0;i<=K;i++)	
		buckets[i]=0;
	for(long i=0;i<n;i++)
		buckets[str[actualIndex[i]]]++;
	long sum=0;
	for(long i=0;i<=K;i++){
		long temp=buckets[i];
		buckets[i]=sum;
		sum+=temp;
	}
	for(long i=0;i<n;i++){
		sortedIndex[buckets[str[actualIndex[i]]]++]=actualIndex[i];
	}
	// delete [] buckets;
}

void createSuffixArrayRecur(long *str,long *SA,long n,long K){
	long n0=(n+2)/3;
	long n1=(n+1)/3;
	long n2=n/3;
	long n12=n0+n2;
	long *R12=new long[n12+3];
	long *SA12=new long[n12+3];
	long *R0=new long[n0];
	long *SA0=new long[n0];

	R12[n12]=R12[n12+1]=R12[n12+2]=0;
	SA12[n12]=SA12[n12+1]=SA12[n12+2]=0;

	for(long i=0,j=0;i<n+(n0-n1);i++){
		if(i%3!=0)
			R12[j++]=i;
	}

	radixSort(R12,SA12,str+2,n12,K);
	radixSort(SA12,R12,str+1,n12,K);
	radixSort(R12,SA12,str,n12,K);

	long name=0;
	long c0=-1,c1=-1,c2=-1;
	for(long i=0;i<n12;i++){
		if(str[SA12[i]]!=c0 || str[SA12[i]+1]!=c1 || str[SA12[i]+2]!=c2){
			name++;
			c0=str[SA12[i]];c1=str[SA12[i]+1];c2=str[SA12[i]+2];
		}
		if(SA12[i]%3==1)	
			R12[SA12[i]/3]=name;
		else
			R12[SA12[i]/3 + n0]=name;
	}

	if(name<n12){
		createSuffixArrayRecur(R12,SA12,n12,name);
		for(long i=0;i<n12;i++){
			R12[SA12[i]]=i+1;
		}
	}
	else{
		for(long i=0;i<n12;i++){
			SA12[R12[i]-1]=i;
		}
	}


	for (long i=0, j=0; i < n12; i++) 
		if (SA12[i] < n0) 
			R0[j++] = 3*SA12[i];
	
	radixSort(R0, SA0, str, n0, K);


	for (long p=0, t=n0-n1, k=0; k < n; k++) {

#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)

		long i = GetI(); 
		long j = SA0[p]; 

		if (SA12[t] < n0 ? 
		leq(str[i], R12[SA12[t] + n0], str[j], R12[j/3]) :
		leq(str[i],str[i+1],R12[SA12[t]-n0+1], str[j],str[j+1],R12[j/3+n0]))
		{ 
			SA[k] = i; t++;
			if (t == n12) 
				for (k++; p < n0; p++, k++) 
					SA[k] = SA0[p];
		} 
		else { 
			SA[k] = j; p++;
			if (p == n0) 
				for (k++; t < n12; t++, k++) 
					SA[k] = GetI();
		}
	}
	delete [] R12; delete [] SA12; delete [] SA0; delete [] R0;



}

void createSuffixArray(long * str,long *suffixArray,long length){
	createSuffixArrayRecur(str,suffixArray,length+1,ALPHABET_SIZE+1);

}

void lcpArray(long *str,long *suffixArray,long *lcp,long n){
	// long *rank=new long[n+1];
	long rank[MAX];
	for(long i=0;i<n;i++){
		rank[suffixArray[i]]=i;
	}
	long h=0;
	lcp[0]=0;
	for(long i=0;i<n;i++){
		if(rank[i]>0){
			long k=suffixArray[rank[i]-1];
			while((i+h)<n && (k+h)<n && str[i+h]==str[k+h]){
				h++;
			}
			lcp[rank[i]]=h;
			if(h>0) h--;
		}
	}
	// delete [] rank;
}
void createSuffixLCPArray(char * str,long *suffixArray,long *lcp,long length){
	long i;
	for(i=0;i<length;i++)
	{
		givenString[i]=1+(long)str[i];
	}
	givenString[i]=0;
	createSuffixArray(givenString,suffixArray,length);
	lcpArray(givenString,suffixArray,lcp,length+1);
}

int main(){
	long T;
	char str1[MAX];
	char str2[MAX];
	long length1;

	// for(long i=0;i<250000;i++)
	// 	str1[i]=rand()%26 +'a';
	// for(long i=0;i<250000;i++)
	// 	str2[i]=rand()%26 +'a';
	scanf("%s",str1);
	scanf("%s",str2);

	length1=strlen(str1);
	char separator[2]={'~'};
	strcat(str1,separator);
	strcat(str1,str2);
	long length=strlen(str1);
	memset(givenString,0,sizeof(givenString));
	if(length==0){
		cout<<"0\n";
	}else{
		long *suffixArray=new long [length+1];
		long *lcp=new long [length+1];
		createSuffixLCPArray(str1,suffixArray,lcp,length);
		long result=-1;

		for(long i=1;i<length;i++){
			if(((suffixArray[i-1]<length1)&&(suffixArray[i]>length1))|| 
				((suffixArray[i-1]>length1)&&(suffixArray[i]<length1)))
				result=max(result,(long)lcp[i]);
		}
		cout<<result<<"\n";
		delete [] suffixArray;
		delete [] lcp;
	}
}
