#include <iostream>

using namespace std;

int N;
int map[16][16];
int cnt=0;

void dfs(int y1, int x1,int y2,int x2, int before){
    if(map[y1][x1]==1||map[y2][x2]==1)    return;
    if(before==2){
        if(map[y2-1][x2]==1||map[y2][x2-1]==1)  return;
    }
    if(y1>N||x1>N||y2>N||x2>N)  return;
    if(y2==N-1&&x2==N-1){
        cnt++;
        return;
    }
    if(before==0){
        dfs(y1,x1+1,y2,x2+1,0);
        dfs(y1,x1+1,y2+1,x2+1,2);
    }else if(before==1){
        dfs(y1+1,x1,y2+1,x2,1);
        dfs(y1+1,x1,y2+1,x2+1,2);
    }else if(before==2){
        dfs(y1+1,x1+1,y2,x2+1,0);
        dfs(y1+1,x1+1,y2+1,x2,1);
        dfs(y1+1,x1+1,y2+1,x2+1,2);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }

    dfs(0,0,0,1,0);
    cout<<cnt;
    return 0;
}