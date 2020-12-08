#include <iostream>
#include <vector>

using namespace std;
int N,M;
int map[500][500];
bool chking[500][500];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int result=0,temp=0;

void dfs(int y, int x, int cnt){
    
    if(cnt>=4){
        if(result<temp){
            result=temp;
        }
        return;
    }else{
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            if(!chking[ny][nx]){
                chking[ny][nx]=true;
                temp+=map[ny][nx];
                dfs(ny,nx,cnt+1);
                temp-=map[ny][nx];
                chking[ny][nx]=false;
            }
        }
    }
}

int main(){

    freopen("input.txt","r",stdin);
    
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            chking[i][j]=true;
            temp+=map[i][j];
            dfs(i,j,1);
            temp-=map[i][j];
            chking[i][j]=false;
        }
    }
    
    cout<<result;

    return 0;
}