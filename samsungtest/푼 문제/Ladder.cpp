#include <iostream>
#include <algorithm>

using namespace std;
const int INF=98787987;
int N,M,H;
int visit[31][31];
int res=INF;

bool chking(){
    for(int i=1;i<=N;i++){
        int a=i;
        for(int j=1;j<=H;j++){
            if(visit[j][a]) a++;
            else if(visit[j][a-1]) a--;
        }
        if(a!=i){
            return false;
        }
    }
    return true;
}

void simulation(int idx, int cnt){
    if(cnt>3) return;
    if(chking()){
        res = min(res,cnt);
        return;
    }
    for(int i=idx;i<=H;i++){
        for(int j=1;j<=N;j++){
            if(visit[i][j]||visit[i][j-1]||visit[i][j+1]) continue;
            visit[i][j]=1;
            simulation(i,cnt+1);
            visit[i][j]=0;
        }
    }
}

int main(){

    freopen("input.txt","r",stdin);
    cin>>N>>M>>H;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        visit[a][b]=1;
    }
    simulation(1,0);
    cout<<((res==INF)? -1: res);
    return 0;
}