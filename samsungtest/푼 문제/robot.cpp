#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 50;

struct robot{
    int r,c,d;
};


int N,M;
int map[MAX][MAX];
robot r1;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int result=0;

void cleaning(){
    
    int y = r1.r;
    int x = r1.c;
    int dir = r1.d;
    queue <pair<pair<int,int >,int>> q1;
    q1.push({{y,x},dir});
    
    while(!q1.empty()){
        int y = q1.front().first.first;
        int x = q1.front().first.second;
        int dir = q1.front().second;

        if(map[y][x]==0){
            map[y][x] = 2;
            result++;
        }
        q1.pop();

        bool flag = false;
        for(int i=0;i<4;i++){
            int nd = (dir+(3-i))%4;
            int ny = y+dy[nd];
            int nx = x+dx[nd];
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            if(!map[ny][nx]){
                q1.push({{ny,nx},nd});
                flag =true;
                break;
            }
        }

        if(!flag){
            int by = y - dy[dir];
            int bx = x - dx[dir];
            if(by<0 || bx<0 || by>= N || bx>=M) continue;
            if(map[by][bx]!=1){
                q1.push({{by,bx},dir});
            }
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    
    cin >> N >> M;
    cin >> r1.r >> r1.c >> r1.d;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    cleaning();

    cout<<result;
    return 0;
}