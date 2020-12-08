#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int map[51][51];
int copyMap[51][51];
int chk[6][3];
int num[6];
bool chknum[6];
int N,M,K;
int res=98787987;

void count(){
    int temp=0;
    for(int i=1;i<=N;i++){
        temp=0;
        for(int j=1;j<=M;j++){
            temp+=map[i][j];
        }
        if(res>temp)    res=temp;
    }
}

void rotate(int n){
    int r=chk[n][0], c=chk[n][1], s=chk[n][2];

    queue <int> q1;

    
    for(int j=1;j<=s;j++){
        int ny = r-j, nx = c-j;
        q1.push(map[ny+1][nx]);
        q1.push(map[ny][nx]);
        for(int i=0;i<2*j;i++){
            nx++;
            q1.push(map[ny][nx]);
        }
        for(int i=0;i<2*j;i++){
            ny++;
            q1.push(map[ny][nx]);
        }
        for(int i=0;i<2*j;i++){
            nx--;
            q1.push(map[ny][nx]);
        }
        for(int i=0;i<2*j-2;i++){
            ny--;
            q1.push(map[ny][nx]);
        }
        ny=r-j,nx=c-j;
        map[ny][nx]=q1.front();
        q1.pop();
        for(int i=0;i<2*j;i++){
            nx++;
            map[ny][nx]=q1.front();
            q1.pop();
        }
        for(int i=0;i<2*j;i++){
            ny++;
            map[ny][nx]=q1.front();
            q1.pop();
        }
        for(int i=0;i<2*j;i++){
            nx--;
            map[ny][nx]=q1.front();
            q1.pop();
        }
        for(int i=0;i<2*j-1;i++){
            ny--;
            map[ny][nx]=q1.front();
            q1.pop();
        }
    }
}

void dfs(int cnt){
    if(cnt==K){
        memcpy(map,copyMap,sizeof(map));
        for(int i=0;i<K;i++){
            rotate(num[i]);
        }
        count();
        return;
    }
    for(int i=0;i<K;i++){
        if(!chknum[i]){
            chknum[i]=true;
            num[cnt]=i;
            dfs(cnt+1);
            chknum[i]=false;
        }
    }
}

int main(){

    freopen("input.txt","r",stdin);

    cin>>N>>M>>K;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>copyMap[i][j];
        }
    }

    for(int i=0;i<K;i++){
        cin>>chk[i][0]>>chk[i][1]>>chk[i][2];
    }

    dfs(0);
    cout<<res;

    return 0;
}