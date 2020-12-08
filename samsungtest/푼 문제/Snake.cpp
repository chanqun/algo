#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
int N, K, L;
int chk=0, time=0, nowdirection=0;
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int ny=1, nx=1;
vector <pair<int,char >> s1;
queue <pair<int,int >> snake;

void simulation(int t, char d){
    if(d=='D'){
        nowdirection=(nowdirection+4+1)%4;
    }else if(d=='L'){
        nowdirection=(nowdirection+4-1)%4;
    }

    for(int i=0;i<t;i++){
        int tempy= ny+dy[nowdirection];
        int tempx= nx+dx[nowdirection];
        time++;
        
        if(tempy<=0||tempx<=0||tempy>N||tempx>N||map[tempy][tempx]==1){
            chk=1;
            return;
        }

        if(map[tempy][tempx]==9){
            map[tempy][tempx]=1;
            snake.push({tempy,tempx});
        }else{
            map[tempy][tempx]=1;
            snake.push({tempy,tempx});
            ny=snake.front().first;
            nx=snake.front().second;
            snake.pop();
            map[ny][nx]=0;
        }
        
        ny=tempy;
        nx=tempx;
    
    }
}

int main(){
    
    freopen("input.txt","r",stdin);

    cin>>N>>K;
    for(int i=0;i<K;i++){
        int y, x;
        cin>>y>>x;
        map[y][x]=9;
    }
    cin>>L;    
    
    s1.push_back(make_pair(0,'N'));
    snake.push({1,1});
    map[1][1]=1;

    for(int i=0;i<L;i++){
        int t;
        char d;
        cin>>t>>d;
        s1.push_back(make_pair(t,d));
    }
    s1.push_back({1000,'N'});
        
    for(int i=0;i<=L;i++){
        int t = s1[i].first;
        char d = s1[i].second;
        int nt = s1[i+1].first;
        simulation((nt-t),d);
        if(chk==1){
            cout<<time;
            return 0;
        }
    }
    
    return 0;
}