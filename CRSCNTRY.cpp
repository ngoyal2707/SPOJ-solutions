#include<iostream>
#include<cstring>
using namespace std;

int memoized[2005][2005];

int lcs(int *l1,int *l2, int i,int j){

	if(i==-1)
		return 0;
	if(j==-1)
		return 0;
	if(memoized[i][j]!=-1)
		return memoized[i][j];
	memoized[i][j]=max((1+ lcs(l1,l2,i-1,j-1))*(l1[i]==l2[j]),max(lcs(l1,l2,i,j-1),lcs(l1,l2,i-1,j)));
	return memoized[i][j];
}

int main(){
	int datasets;
	cin>>datasets;

	// memoized=new int* [2005];
	// for(int i=0;i<2005;i++){
	// 	memoized[i]=new int[2005];
	// }   

	while(datasets--){
		int max1=-1;
		int list1[2005],list2[2005];
		int len1,len2;
		int temp;
		int i=0;
		while(cin>>temp && temp!=0){
			list1[i++]=temp;
		}
		len1=i;
		while(1){
			int i=0;
			while(cin>>temp && temp!=0)
			{
				list2[i++]=temp;
			}
			len2=i;
			// memset(memoized,0,sizeof(memoized));
			// cout<<memoized[0][0];
			if(i==0)
				break;

			for(int i=0;i<len1;i++)
				for(int j=0;j<len2;j++)
					memoized[i][j]=-1;

			int result=lcs(list1,list2,len1-1,len2-1);
			// cout<<result<s<"\n";
			max1=max(max1,result);
		}
		cout<<max1<<"\n";
	}
}