#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int T, N, K;
int map[8][8];
bool chk[8][8];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int res=0;

void dfs(int y, int x, int cnt, int nn){
    if(res<cnt){
        res=cnt;
    }
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0||nx<0||ny>=N||nx>=N||chk[ny][nx])    continue;
        if(map[ny][nx]>=map[y][x]&&nn==0){
            chk[ny][nx]=true;
            for(int j=1;j<=K;j++){
                map[ny][nx]-=j;
                if(map[ny][nx]<map[y][x]){
                    dfs(ny,nx,cnt+1,1);
                }
                map[ny][nx]+=j;
            }
            chk[ny][nx]=false;
        }else if(map[ny][nx]<map[y][x]){
            chk[ny][nx]=true;
            dfs(ny,nx,cnt+1,nn);
            chk[ny][nx]=false;
        }
    }
}

void solve(){
    cin>>N>>K;
    int max=0;
    res=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(max<map[i][j]){
                max=map[i][j];
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==max){
                memset(chk,false,sizeof(chk));
                chk[i][j]=true;
                dfs(i,j,1,0);
                chk[i][j]=false;
            }
        }
    }

}

int main(){
    freopen("input.txt","r",stdin);
    cin>>T;
    for(int i=1;i<=T;i++){
        solve();
        cout<<"#"<<i<<" "<<res<<"\n";
    }
    return 0;
}