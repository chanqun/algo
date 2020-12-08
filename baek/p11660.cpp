#include<iostream>

using namespace std;

int pSum[1025][1025];
	
int main(){//dynamic programming
	int N,M;
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int element;
			scanf("%d",&element);
			pSum[i+1][j+1]=pSum[i+1][j]+pSum[i][j+1]-pSum[i][j]+element;
			//겹치는 부분을 빼준다 
		}
	}
	
	for(int i=0;i<M;i++){
		int x,y,x2,y2;
		scanf("%d %d %d %d",&x,&y,&x2,&y2); 
		printf("%d\n",pSum[x2][y2]-pSum[x-1][y2]-pSum[x2][y-1]+pSum[x-1][y-1]);
	}
	return 0;
}