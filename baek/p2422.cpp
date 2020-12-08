#include <iostream>

using namespace std;

int N, M;
int arr[201][201];
int res;
bool chk[201];
int num[3];

bool chking(){
    int a,b,c;
    a=num[0], b=num[1], c=num[2];
    if(arr[a][b]==1||arr[b][c]==1||arr[c][a]==1){
        return false;
    }
    return true;
}

void dfs(int cnt, int idx){
    if(cnt==3){
        bool now = chking();
        if(now) res++;
        return;
    }
    for(int i=1;i<=N;i++){
        if(i>idx&&!chk[i]){
            chk[i]=true;
            num[cnt]=i;
            dfs(cnt+1,i);
            chk[i]=false;
        }
    }
}

int main(){

    freopen("input.txt","r",stdin);

    cin>>N>>M;

    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }

    dfs(0,0);
    cout<<res;

    return 0;
}