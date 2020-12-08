#include <iostream>

using namespace std;

int map[20][20];
int N,M,K;
int dy[]={0,0,0,-1,1};
int dx[]={0,1,-1,0,0};
int y,x;
int dice[8]={0,};

void simulation(int nd){
    int ny = y + dy[nd];
    int nx = x + dx[nd];

    if(ny<0||nx<0||ny>=N||nx>=M) return;
    
    y = y+dy[nd];
    x = x+dx[nd];

    if(nd==1){
        int temp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    }else if(nd==2){
        int temp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
    }else if(nd==3){
        int temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }else if(nd==4){
        int temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }

    if(map[y][x]==0){
        map[y][x]=dice[6];
    }else{
        dice[6]=map[y][x];
        map[y][x]=0;
    }
    cout<<dice[1]<<"\n";
    
    return;
}

int main(){

    freopen("input.txt","r",stdin);

    cin>>N >> M>> y>> x>> K;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=K;i++){
        int direction;
        cin>>direction;
        simulation(direction);
    }
    return 0;
}