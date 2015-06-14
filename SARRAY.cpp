
// Author: ngoyal2707

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#define ALPHABET_SIZE 62
#define MAX 100005
using namespace std;

inline bool leq(int a1, int a2, int b1, int b2) 
{ 
	return(a1 < b1 || a1 == b1 && a2 <= b2); 
}
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3){ 
	return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3)); 
}

void radixSort(int *actualIndex,int *sortedIndex,int *str,int n,int K){
	int *buckets=new int[K+1];
	for(int i=0;i<=K;i++)	
		buckets[i]=0;
	for(int i=0;i<n;i++)
		buckets[str[actualIndex[i]]]++;
	int sum=0;
	for(int i=0;i<=K;i++){
		int temp=buckets[i];
		buckets[i]=sum;
		sum+=temp;
	}
	for(int i=0;i<n;i++){
		sortedIndex[buckets[str[actualIndex[i]]]++]=actualIndex[i];
	}
	delete [] buckets;
}

void createSuffixArrayRecur(int *str,int *SA,int n,int K){
	int n0=(n+2)/3;
	int n1=(n+1)/3;
	int n2=n/3;
	int n12=n0+n2;
	int *R12=new int[n12+3];
	int *SA12=new int[n12+3];
	int *R0=new int[n0];
	int *SA0=new int[n0];

	R12[n12]=R12[n12+1]=R12[n12+2]=0;
	SA12[n12]=SA12[n12+1]=SA12[n12+2]=0;

	for(int i=0,j=0;i<n+(n0-n1);i++){
		if(i%3!=0)
			R12[j++]=i;
	}

	// cout<<"\n";
	// for(int i=0;i<n+(n0-n1);i++)
	// 	cout<<R12[i]<<"\t";

	radixSort(R12,SA12,str+2,n12,K);
	radixSort(SA12,R12,str+1,n12,K);
	radixSort(R12,SA12,str,n12,K);

	int name=0;
	int c0=-1,c1=-1,c2=-1;
	for(int i=0;i<n12;i++){
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
		for(int i=0;i<n12;i++){
			R12[SA12[i]]=i+1;
		}
	}
	else{
		for(int i=0;i<n12;i++){
			SA12[R12[i]-1]=i;
		}
	}


	for (int i=0, j=0; i < n12; i++) 
		if (SA12[i] < n0) 
			R0[j++] = 3*SA12[i];
	
	radixSort(R0, SA0, str, n0, K);


	for (int p=0, t=n0-n1, k=0; k < n; k++) {

#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)

		int i = GetI(); // pos of current offset 12 suffix
		int j = SA0[p]; // pos of current offset 0 suffix

		if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
		leq(str[i], R12[SA12[t] + n0], str[j], R12[j/3]) :
		leq(str[i],str[i+1],R12[SA12[t]-n0+1], str[j],str[j+1],R12[j/3+n0]))
		{ // suffix from SA12 is smaller
			SA[k] = i; t++;
			if (t == n12) // done --- only SA0 suffixes left
				for (k++; p < n0; p++, k++) 
					SA[k] = SA0[p];
		} 
		else { // suffix from SA0 is smaller
			SA[k] = j; p++;
			if (p == n0) // done --- only SA12 suffixes left
				for (k++; t < n12; t++, k++) 
					SA[k] = GetI();
		}
	}
	delete [] R12; delete [] SA12; delete [] SA0; delete [] R0;



}

void createSuffixArray(char * str,int *suffixArray,long length){
	int givenString[MAX];
	int i;
	for(i=0;i<length;i++)
	{
		if(str[i]>='0' && str[i]<='9')
			givenString[i]=1+str[i]-'0';

		if(str[i]>='A' && str[i]<='Z')
			givenString[i]=1+10+str[i]-'A';

		if(str[i]>='a' && str[i]<='z')
			givenString[i]=1+10+26+str[i]-'a';
	}
	givenString[i]=0;

	// for(i=0;i<str.length()+1;i++){
	// 	cout<<givenString[i]<<"\t";
	// }
	// cout<<"\n";
	createSuffixArrayRecur(givenString,suffixArray,length+1,ALPHABET_SIZE+1);

	for(int i=1;i<length+1;i++)
		printf("%d\n",suffixArray[i]);
	// cout<<"\n";
}

int main(){
	char str[MAX];
	scanf("%s",str);
	long length=strlen(str);
	int suffixArray[length+1];
	createSuffixArray(str,suffixArray,length);
}
