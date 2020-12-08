#include <bits/stdc++.h>
using namespace std;

#define ll long long

string sol;
bool chk[7][7];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
char dd[]={'U','R','D','L'};
char li[48];
int ans=0;

void chking(){
    for(int i=0;i<48;i++){
        if(sol[i]=='?') continue;
        if(sol[i]!=li[i]&&sol[i]!='?')   return;
    }
    ans++;
    return;
}


void dfs(int y, int x, int cnt){
    
    if(cnt>=48||y==6&&x==0){
        cout<<li[47];
        chking();
        return;
    }
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||nx<0||ny>=7||nx>=7)    continue;
        if(!chk[ny][nx]){
            li[cnt]=dd[i];
            chk[ny][nx]=true;
            dfs(ny,nx,cnt+1);
            chk[ny][nx]=false;
            li[cnt]=' ';
        }
    }
}

int main() {

    freopen("input.txt","r",stdin);

    cin>>sol;
    chk[0][0]=true;
    dfs(0,0,0);
    cout<<ans;

	return 0;
}