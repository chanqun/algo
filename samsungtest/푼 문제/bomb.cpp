#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, N, W, H;
int res;
int map[20][20];
bool chk[20][20];
int copyMap[20][20];
int num[5];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void bomb(int n){
    queue <pair<int ,int > > q1;
    for(int i=0;i<H;i++){
        if(map[i][n]!=0){
            q1.push({i,n});
            chk[i][n]=true;
            break;
        }
    }
    while(!q1.empty()){
        int y = q1.front().first;
        int x = q1.front().second;
        q1.pop();
        int range = map[y][x];
        map[y][x]=0;
        for(int j=1;j<range;j++){
            for(int i=0;i<4;i++){
                int ny = y+dy[i]*j;
                int nx = x+dx[i]*j;
                if(ny<0||nx<0||ny>=H||nx>=W)  continue;
                if(map[ny][nx]!=0&&!chk[ny][nx]){
                    chk[ny][nx]= true;
                    q1.push({ny,nx});
                }
            }
        }
    }
    for(int j=0;j<W;j++){
        int cnt=H-1;
        for(int i=H-1;i>=0;i--){
            if(map[i][j]!=0){
                int temp=map[i][j];
                map[i][j]=0;
                map[cnt][j]=temp;
                cnt--;
            }
        }
    }
}

void count(){
    int temp=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(map[i][j]!=0){
                temp++;
            }
        }
    }
    if(res>temp)    res=temp;
}

void dfs(int cnt){
    if(res==0)  return;
    if(cnt==N){
        memcpy(map,copyMap,sizeof(map));
        for(int i=0;i<N;i++){
            memset(chk,false,sizeof(chk));
            bomb(num[i]);
            count();
        }
        return;
    }
    for(int i=0;i<W;i++){
        num[cnt]=i;
        dfs(cnt+1);
    }
}

void solve(){

    cin>> N >> W >> H;
    
    res=W*H;

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>copyMap[i][j];
        }
    }

    dfs(0);

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