#include <iostream>
#include <algorithm>

using namespace std;

int map[10][10]; 
bool chk[10][10];
int color[6]={0,};
int res=30;

bool isOK(int y, int x, int size){

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!map[y+i][x+j]){
                return false;
            }
        }
    }
    return true;
}
void update(int y, int x ,int size, int t){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            map[y+i][x+j]=t;
        }
    }
}

void dfs(int y, int x, int cnt){
    while(map[y][x]==0){
        if(++x>=10){
            if(++y>=10){
                res = min(res,cnt);
                return;
            }
            x=0;
        }
    }
    if(res<=cnt)    return;
    for(int s=5;s>0;s--){
        if(y+s>10||x+s>10||color[s]==5) continue;
        if(isOK(y,x,s)){
            update(y,x,s,0);
            color[s]++;
            dfs(y,x,cnt+1);
            update(y,x,s,1);
            color[s]--;
        }
    }
}

int main(){

    freopen("input.txt","r",stdin);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>map[i][j];
        }
    }

    dfs(0,0,0);
    if(res==30)  res=-1;
    cout<<res;
    return 0;
}