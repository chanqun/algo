#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct Point{
    int y;
    int x;
    char type;
};

int R,C;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
char map[50][50];
int dp[50][50];
queue <Point> q;
vector <Point> wlist;

//X가 아니고 *도 아니고 *에 인접한 .도 아니고
bool chkSafe(int y, int x){
    if(map[y][x]=='D'){
        return true;
    }else if(map[y][x]=='.'){
        for(int i=0;i<4;i++){
            int ty=y+dy[i];
            int tx=x+dx[i];
            if(0<=ty&&ty<R&&0<=tx&&tx<C&&map[ty][tx]=='*'){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt","r",stdin);
    
    cin>>R>>C;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
            if(map[i][j]=='S'){
                q.push({i,j,'S'});
            }else if(map[i][j]=='*'){
                wlist.push_back({i,j,'*'});
            }
        }
    }
    for(int i=0;i<wlist.size();i++){
        q.push({wlist[i].y,wlist[i].x,wlist[i].type});
    }
    bool foundAnswer=false;
    while(!q.empty()){
        //1.큐에서 꺼내줌
        Point p = q.front();
        q.pop();
        //2.목적지인가?
        if(p.type=='D'){
            cout<<dp[p.y][p.x];
            foundAnswer=true;
            break;
        }
        //3.갈 수 있는 곳을 순회 (상,하,좌,우)
        for(int i=0;i<4;i++){
            int ty=p.y+dy[i];
            int tx=p.x+dx[i];
            //갈 수 있는가 if 맵을 벗어나지 않고 X가 아니고 *가 아니고
            if(0<=ty&&ty<R&&0<=tx&&tx<C){
                //체크인
                //큐에 넣음
                if(p.type=='.'||p.type=='S'){//고슴도치
                    if(dp[ty][tx]==0&&chkSafe(ty,tx)){
                        dp[ty][tx]=dp[p.y][p.x]+1;
                        q.push({ty,tx,map[ty][tx]});
                    }
                }else if(p.type=='*'&&map[ty][tx]=='.'){//물
                    //체크인   
                    //큐에 넣음
                    q.push({ty,tx,'*'});
                    map[ty][tx]='*';
                }
            }
        }
    }
    if(!foundAnswer){
        cout<<"KAKTUS";
    }
    return 0;
}