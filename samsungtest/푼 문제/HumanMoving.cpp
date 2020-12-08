#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N,L,R;
int map[50][50];
bool chk[50][50];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int a;
int sum,cnt;
vector <pair<int,int >> ss;

void bfs(int y, int x){
    queue <pair<int, int >> q1;
    q1.push({y,x});
    chk[y][x]=true;

    while(!q1.empty()){
        y = q1.front().first;
        x = q1.front().second;
        sum+=map[y][x];
        cnt++;
        ss.push_back({y,x});
        q1.pop();

        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0||nx<0||ny>=N||nx>=N) continue;
            if(!chk[ny][nx]&&L<=abs(map[y][x]-map[ny][nx])&&abs(map[ny][nx]-map[y][x])<=R){
                q1.push({ny,nx});
                chk[ny][nx] = true;
                a=1;
            }
        }
    }
}

int simulation(){
    int time = 0;

    while(1){
        a=0;
        memset(chk,false,sizeof(chk));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!chk[i][j]){
                    ss.clear();
                    sum=0,cnt=0;
                    bfs(i,j);
                    for(int k=0;k<ss.size();k++){
                        map[ss[k].first][ss[k].second] = sum/cnt;
                    }
                }
            }
        }        
        if(a==0) return time;
        time++;
    }
    return time;
}

int main(){
    
    freopen("input.txt","r",stdin);
    cin>>N>>L>>R;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }

    cout<<simulation();

    return 0;
}