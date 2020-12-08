#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int map[20][20];
int N;
int fishSize = 2, fishCount=2;
int y, x;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
bool chk[20][20]= {false,};
int dist[20][20]={0,};
int eaty, eatx;

void bfs(){

    queue <pair<int, int>> q1;
    q1.push({y,x});
    chk[y][x]=true;

    while(!q1.empty()){
        
        int y1 = q1.front().first; 
        int x1 = q1.front().second;
        q1.pop();


        for(int i=0;i<4;i++){
            int ny = y1+dy[i];
            int nx = x1+dx[i];

            if(ny<0||nx<0||ny>=N||nx>=N||map[ny][nx]>fishSize) continue;

            if(!chk[ny][nx]&&map[ny][nx]<=fishSize){
                q1.push({ny,nx});
                dist[ny][nx]=dist[y1][x1]+1;
                chk[ny][nx]=true;
            }
        }
    }
}

int simulation(){
    int time = 0;

    while(1){

        memset(dist,0,sizeof(dist));
        memset(chk,false,sizeof(chk));
        bfs();

        int temp_dist=1000;
        int a=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j]!=0&&map[i][j]<fishSize){
                    a=1;
                    if(dist[i][j]!=0&&dist[i][j]<temp_dist){
                        temp_dist=dist[i][j];
                        eaty=i;
                        eatx=j;
                    }
                }
            }
        }
        if(a==0) return time;
        if(temp_dist==1000) return time;

        fishCount--;
        if(fishCount==0){
            fishSize++;
            fishCount=fishSize;    
        }

        time+=temp_dist;
        y=eaty;
        x=eatx;
        map[eaty][eatx]=0;


    }
}

int main(){

    freopen("input.txt","r",stdin);

    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>> map[i][j];
            if(map[i][j]==9){
                y=i, x=j;
                map[i][j]=0;
            }
        }
    }

    cout << simulation();

    return 0;
}