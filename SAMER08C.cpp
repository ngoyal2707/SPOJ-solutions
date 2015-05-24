#include<iostream>
#include<vector>
using namespace std;

// long int getRowValue(int *array,long int i){
// 	if(i<0)
// 		return 0;
// 	if(i==0)
// 		return array[i];
// 	long int result=max(array[i]+getRowValue(array,i-2),getRowValue(array,i-1));
// 	return result;
// }

long int solve(int **a,long int M,long int N){
	int rowValues[M];
	for(int i=0;i<M;i++){
		long int result[N];
		result[0]=a[i][0];
		for(int j=1;j<N;j++){
			result[j]=max(a[i][j]+ (j>1?result[j-2]:0),result[j-1]);
		}
		rowValues[i]=result[N-1];
		// cout<<rowValues[i]<<"\n";
	}

	long int row_results[M];
	row_results[0]=rowValues[0];
	for(int i=1;i<M;i++){
		row_results[i]=max(rowValues[i]+(i>1?row_results[i-2]:0),row_results[i-1]);
	}

	return row_results[M-1];
}
int main(){
	long int M,N;
	while(cin>>M>>N && M && N){
		int **a=new int* [M];
		for(int i=0;i<M;i++)
			a[i]= new int[N];
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin>>a[i][j];
			}
		}
		long int result=solve(a,M,N);
		cout<<result<<"\n";

	}
}