#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<stack>
#define MAX 4000
using namespace std;
char matrix[4000][4000];
int S[4000][4000];
long long int largestRectangleArea(int * height,int size) {
    stack<int> s,t;
    int leftArray[size];
    int rightArray[size];
    
    for(int i=0;i<size;i++){
        int left=0;
        while(!s.empty() && height[s.top()]>=height[i]){
            int poppedElement=s.top();
            s.pop();
            left+=leftArray[poppedElement]+1;
        }
        s.push(i);
        leftArray[i]=left;
    }
    
    
    for(int i=size-1;i>=0;i--){
        int right=0;
        while(!t.empty() && height[t.top()]>=height[i]){
            int poppedElement=t.top();
            t.pop();
            right+=rightArray[poppedElement]+1;
        }
        t.push(i);
        rightArray[i]=right;
    }
    long long int result=-1;
    for(int i=0;i<size;i++){
        result=max(result,(long long int)height[i]*(leftArray[i]+rightArray[i]+1));
    }
    return result==-1?0:result;
}

long long int maximalRectangle(int N, int M) {
    // int m,n;
    // m=matrix.size();
    if(!N || !M)
        return 0;
    // int ** S=new int* [N];
    // for(int i=0;i<N;i++){
    // 	S[i]= new int[M];
    // }
    for(int i=0;i<M;i++){
        S[0][i]=(matrix[0][i]=='H')?1:0;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<M;j++){
            S[i][j]=(matrix[i][j]=='H')?1+S[i-1][j]:0;
        }
    }
    long long int result=-1;
    for(int i=0;i<N;i++){
        result=max(result,largestRectangleArea(S[i],M));        
    }
    return result==-1?0:result;
}
int main(){
	int N,M;
	long int F;
	while(cin>>N && cin>>M && N && M){
		cin>>F;
		// std::vector<std::vector<char> > v(N,std::vector<char>(M));
		// char **v=new char * [N];
		// for(int i=0;i<N;i++){
		// 	matrix[i]=new char[M];
		// }
		for(int i=0;i<N;i++){
			scanf("%s",matrix[i]);
		}
		long long int result = F*maximalRectangle(N,M);
		cout<<result<<"\n";
	}
}