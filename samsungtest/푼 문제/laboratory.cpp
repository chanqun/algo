#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[10][10];
int map_copy[10][10];
vector <pair<int, int >> chk;
vector <int> dy={-1,0,1,0};
vector <int> dx={0,1,0,-1};
int max_sol=0;

int bfs(){
    queue <pair<int, int >> q1;
    for(int i=0;i<chk.size();i++){
        q1.push(make_pair(chk[i].first,chk[i].second));
    }
    
    while(!q1.empty()){
        int y = q1.front().first;
        int x = q1.front().second;

        q1.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||nx<0||ny>N||nx>M) continue;
            if(map_copy[ny][nx]==0){
                map_copy[ny][nx]=2;
                q1.push(make_pair(ny,nx));
            }
        }
    }

    int result = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map_copy[i][j]==0){
                result++;
            }
        }
    }
    return result;
}

void makeWall(int cnt){
    if(cnt==3){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                map_copy[i][j]=map[i][j];
            }
        }
        int temp = bfs();
        if(temp>max_sol){
            max_sol=temp;
        }
        return;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0){
                map[i][j]=1;
                makeWall(cnt+1);
                map[i][j]=0;
            }
        }
    }
}


int main(){

    freopen("input.txt","r",stdin);

    cin>> N>> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                chk.push_back(make_pair(i,j));
            }
        }
    }
   
    makeWall(0);

    cout<<max_sol;
    return 0;
}