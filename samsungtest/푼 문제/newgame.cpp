#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct drone{
    int y,x,d;
};

drone d[11];
int N,K;
int color[13][13];
vector <int> map[13][13];
int dy[]={0,0,0,-1,1};
int dx[]={0,1,-1,0,0};
int turn[]={0,2,1,4,3};

int move(int i){
    int ny = d[i].y + dy[d[i].d];
    int nx = d[i].x + dx[d[i].d];

    if(ny<=0||nx<=0||ny>N||nx>N||color[ny][nx]==2){
        d[i].d=turn[d[i].d];
        ny = d[i].y + dy[d[i].d];
        nx = d[i].x + dx[d[i].d];
        if(ny<=0||nx<=0||ny>N||nx>N||color[ny][nx]==2){
            return 0;
        }
    }

    vector <int> &cur = map[d[i].y][d[i].x];
    vector <int> &next = map[ny][nx];

    vector <int>::iterator idx = find(cur.begin(),cur.end(),i);
    
    if(color[ny][nx]==1){
        reverse(idx, cur.end());
    }
    for(vector <int>::iterator it=idx;it!=cur.end();it++){
        d[*it].y=ny, d[*it].x=nx;
        next.push_back(*it);
    }

    cur.erase(idx,cur.end());
    return next.size();
}
int simulation(){
    for(int time=1;time<=1000;time++){
        for(int i=0;i<K;i++){
            int stack_cnt = move(i);
            if(stack_cnt>=4){
                return time;
            }
        }
    }
    return -1;
}

int main(){

    freopen("input.txt","r",stdin);
    cin>>N>>K;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>color[i][j];
        }
    }

    for(int i=0;i<K;i++){
        cin>>d[i].y>>d[i].x>>d[i].d;
        map[d[i].y][d[i].x].push_back(i);
    }
    
    cout<< simulation();
    
    return 0;
}