#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
//문제 제대로 읽기, 배열 크기 제대로 설정, 조건 확인
//while믄 탈출 조건
using namespace std;
int T, N;
int map[13][13];
int res,cnt;
int where[13];
int tt;
vector < pair< int, int > > stair, human;

void time(){
    vector <int> d1, d2;
    d1.clear();
    d2.clear();
    queue <int> q1, q2;
    for(int i=0;i<cnt;i++){
        if(where[i]==1){
            int distance = abs(stair[1].first-human[i].first) + abs(stair[1].second-human[i].second);
            d1.push_back(distance);
        }else{
            int distance = abs(stair[0].first-human[i].first) + abs(stair[0].second-human[i].second);
            d2.push_back(distance);
        }
    }

    sort(d1.begin(),d1.end());
    sort(d2.begin(),d2.end());
    
    int min1=0,t1=0,t2=0;
    int k = map[stair[1].first][stair[1].second];

    for(int i=0;i<d1.size();i++){
        if(q1.size()<3){
            q1.push(d1[i]);
        }else{
            int temp = q1.front();
            q1.pop();
            if(temp+1+k<=d1[i]){
                q1.push(d1[i]);
            }else{
                q1.push(temp+k);
            }
        }
    }
    while(!q1.empty()){
        t1=q1.front();
        q1.pop();
    }
    t1+=map[stair[1].first][stair[1].second]+1;

    k = map[stair[0].first][stair[0].second];

    for(int i=0;i<d2.size();i++){
        if(q2.size()<3){
            q2.push(d2[i]);
        }else{
            int temp = q2.front();
            q2.pop();
            if(temp+1+k<=d2[i]){
                q2.push(d2[i]);
            }else{
                q2.push(temp+k);
            }
        }
    }
    while(!q2.empty()){
        t2=q2.front();
        q2.pop();
    }
    t2+=map[stair[0].first][stair[0].second]+1;

    if(t1>t2)   min1=t1;
    else    min1=t2;
    if(res>min1)    res=min1;

}

void dfs(int nc){
    if(nc>=cnt){
        time();
        return;
    }
    where[nc] =1;
    dfs(nc+1);
    where[nc] =0;
    dfs(nc+1);
}

void solve(){
    cin>>N;
    stair.clear();
    human.clear();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j]!=0&&map[i][j]!=1)    stair.push_back({i,j});
            if(map[i][j]==1)    human.push_back({i,j});
        }
    }
    cnt=human.size();
    dfs(0);
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>T;

    for(int i=1;i<=T;i++){
        tt=i;
        res = 98787987;
        solve();
        cout<<"#"<<i<<" "<<res<<"\n";
    }

    return 0;
}