#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

struct user{
    int y, x;
};
struct beacon{
    int y,x;
    int d,p,u;
};
user us[2];
beacon bc[8];
vector <int> moving[2];
int T,M,A,res;
int dy[]={0,-1,0,1,0};
int dx[]={0,0,1,0,-1};
int ret=0;

bool check(int a, int b){
    int dist = abs(us[a].x-bc[b].x)+abs(us[a].y-bc[b].y);
    if(dist <= bc[b].d){
        return true;
    }else{
        return false;
    }
}

void dfs(int user, int d){
    if(user==2){
        ret = max(ret,d);
        return;
    }
    for(int i=0;i<A;i++){
        if(bc[i].u==0&&check(user,i)){
            bc[i].u=1;
            dfs(user+1,d+bc[i].p);
            bc[i].u=0;
        }
    }
    dfs(user+1,d);
}

int count(){
    ret = 0;
    dfs(0,0);
    return ret;
}
void solve(){
    moving[0].clear();
    moving[1].clear();
    for(int i=0;i<A;i++){
        bc[i].u=0;
    }
    us[0].x=1,us[0].y=1,us[1].x=10,us[1].y=10;
    
    cin>>M>>A;
    for(int i=0;i<2;i++){
        for(int j=0;j<M;j++){
            int a;
            cin>>a;
            moving[i].push_back(a);
        }
    }
    for(int i=0;i<A;i++){
        cin>>bc[i].x>>bc[i].y>>bc[i].d>>bc[i].p;
    }
    res+=count();
    for(int i=0;i<M;i++){
        for(int j=0;j<2;j++){
            us[j].x+=dx[moving[j][i]];
            us[j].y+=dy[moving[j][i]];
        }
        res+=count();
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>T;

    for(int i=1;i<=T;i++){
        res=0;
        solve();
        cout<<"#"<<i<<" "<<res<<"\n";
    }

    return 0;
}