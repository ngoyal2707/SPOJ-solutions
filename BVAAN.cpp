#include <iostream>
#include <cstring>
#define MAX 200

int result[MAX][MAX][MAX];

int solve(char *a,char *b,int i,int j, int K){
  int score1=-1;
  if(K==0){
    return 0;
  }
  if(i==-1 || j==-1){
    return -1;
  }
  if(result[i][j][K]!=-2){
	  return result[i][j][K];
  }
  if(a[i]==b[j]){
    score1=solve(a,b,i-1,j-1,K-1);
    score1=score1==-1?-1:(score1+a[i]);
  }
  int score2=-1;
  int score3=-1;
    score2 =solve(a,b,i-1,j,K);
    score3 =solve(a,b,i,j-1,K);
  
  result[i][j][K]=std::max(score1,std::max(score2,score3));
  return result[i][j][K];
 }

int main(int argc, char **argv) {
    int T=1;
    int K;
//    std::cout <<"enter:";
    std::cin >> T;
    char a[MAX],b[MAX];
    for(int i =0;i<T;i++){
      std::cin >> a;
      std::cin >> b;
      std::cin >> K;
		for(int x=0;x<102;x++)
			for(int y=0;y<102;y++)
				for(int z=0;z<102;z++)
					result[x][y][z]=-2;
      int res=solve(a,b,strlen(a)-1,strlen(b)-1,K);
      res=res==-1?0:res;
      std::cout << res<<"\n";
    }
    return 0;
}
