#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N,M,chkArea,res=98787987;
int map[50][50];
int copyMap[50][50];
int chk[10];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

vector <pair<int, int >> Virus;

void bfs(queue <pair<int, int>> q1){
    int infect_place=0;
    int total_time=0;

    while(!q1.empty()){
        int y = q1.front().first;
        int x = q1.front().second;
        q1.pop();
        for(int i=0;i<4;i++){
            int ny= y+dy[i];
            int nx= x+dx[i];
            if(ny<0||nx<0||ny>=N||nx>=N) continue;
            if(map[ny][nx]!=1&&copyMap[ny][nx]==-1){
                copyMap[ny][nx]=copyMap[y][x]+1;
                if(map[ny][nx]==0){
                    infect_place++;
                    total_time=copyMap[ny][nx];
                }
                q1.push({ny,nx});
            }
        }
    }
    if(infect_place==chkArea){
        res=min(res,total_time);
    }
}


void select_virus(int idx, int cnt){
    if(cnt==M){
        queue <pair<int, int>> q1;
        memset(copyMap, -1, sizeof(copyMap));
        for(int i=0;i<Virus.size();i++){
            if(chk[i]){
                q1.push(make_pair(Virus[i].first,Virus[i].second));
                copyMap[Virus[i].first][Virus[i].second]=0;
            }
        }
        bfs(q1);
        return;
    }
    for(int i=idx;i<Virus.size();i++){
        if(chk[i]==true) continue;
        chk[i]=true;
        select_virus(i+1,cnt+1);
        chk[i]=false;
    }
}

void simulation(){
    select_virus(0,0);
    if(res==98787987) cout<<-1;
    else cout<<res;
}

int main(){

    freopen("input.txt","r",stdin);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j]==0) chkArea++;
            else if(map[i][j]==2) Virus.push_back({i,j});
        }
    }

    simulation();
    return 0;
}