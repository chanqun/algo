#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[8][8];
int map2[8][8];
int N,M;
int result= 98787987;
int cctv=0;
vector <pair<int, int >> chkcctv;
vector <pair<int, int >> chking;
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int chk[6][4]={
    {0,0,0,0},
    {1,0,0,0},
    {1,0,1,0},
    {1,0,0,1},
    {1,0,1,1},
    {1,1,1,1}
};



void moving(int y, int x){
    int ny = chkcctv[y].first;
    int nx = chkcctv[y].second;
    y=map[ny][nx];

    int n1=chk[y][0],n2=chk[y][1],n3=chk[y][2],n4=chk[y][3];

    for(int i=0;i<x;i++){
        int temp = n1;
        n1=n4;
        n4=n3;
        n3=n2;
        n2=temp;
    }
    int nny = ny;
    int nnx = nx;
    if(n1==1){
        for(int i=0;i<10;i++){
            nny = nny + dy[0];
            nnx = nnx + dx[0];
            if(nny<0||nnx<0||nny>=N||nnx>=M||map[nny][nnx]==6) break;
            map2[nny][nnx]=9;
        }
    }
    nny=ny;
    nnx=nx;
    if(n2==1){
        for(int i=0;i<10;i++){
            nny = nny + dy[1];
            nnx = nnx + dx[1];
            if(nny<0||nnx<0||nny>=N||nnx>=M||map[nny][nnx]==6) break;
            map2[nny][nnx]=9;
        }
    }
    nny=ny;
    nnx=nx;
    if(n3==1){
        for(int i=0;i<10;i++){
            nny = nny + dy[2];
            nnx = nnx + dx[2];
            if(nny<0||nnx<0||nny>=N||nnx>=M||map[nny][nnx]==6) break;
            map2[nny][nnx]=9;
        }
    }
    nny=ny;
    nnx=nx;
    if(n4==1){
        for(int i=0;i<10;i++){
            nny = nny + dy[3];
            nnx = nnx + dx[3];
            if(nny<0||nnx<0||nny>=N||nnx>=M||map[nny][nnx]==6) break;
            map2[nny][nnx]=9;
        }
    }

}


void simulation(int cnt){

    if(cnt>=cctv){
        memcpy( map2, map ,sizeof(map));

        for(int i=0;i<chking.size();i++){
            int ny= chking[i].first, nx= chking[i].second;
            moving(ny,nx);
        }
        int temp=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map2[i][j]==0) temp++;
            }
        }
        if(temp<result) result = temp;
        return; 
    }

    for(int i=0;i<4;i++){
        chking.push_back({cnt,i});
        simulation(cnt+1);
        chking.erase(chking.end());
    }

}

int main(){

    freopen("input.txt","r",stdin);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]>=1&&map[i][j]<=5){
                chkcctv.push_back({i,j});
                cctv++;
            }
        }
    }

    simulation(0);

    cout<<result;

    return 0;
}