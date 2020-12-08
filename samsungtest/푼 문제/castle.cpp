#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N,M,D,cnt,res;
int map[17][17];
int mapCopy[17][17];
int chk[17];
bool killmap[17][17];
bool isOK(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(map[i][j]==1)    return true;
        }
    }
    return false;
}
void gochking(int t){
    for(int i=1;i<=D;i++){
        int ny=N+1, nx=t-i;
        for(int j=0;j<i;j++){
            ny--,nx++;
            if(ny<1||nx<1||nx>=M+1) continue;
            if(map[ny][nx]==1){
                killmap[ny][nx]=true;
                return;
            }
        }
        for(int j=0;j<i-1;j++){
            ny++,nx++;
            if(ny<1||nx<1||nx>=M+1) continue;
            if(map[ny][nx]==1){
                killmap[ny][nx]=true;
                return;
            }
        }
    }
}
void kill(){
    memcpy(map,mapCopy,sizeof(map));
    int countkill=0;
    while(isOK()){
        memset(killmap,false,sizeof(killmap));
        for(int i=1;i<=M;i++){
            if(chk[i]==2){
                gochking(i);
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(killmap[i][j]){
                    map[i][j]=0;
                    countkill++;
                }
            }
        }
        for(int i=N;i>=1;i--){
            for(int j=1;j<=M;j++){
                if(i==N){
                    if(map[i][j]==1){
                        map[i][j]=0;
                    }
                }else{
                    if(map[i][j]==1){
                        map[i][j]=0;
                        map[i+1][j]=1;
                    }
                }
            }
        }
    }
    if(res<countkill)   res=countkill;
}
void simulation(int cnt1, int idx){
    if(cnt1==3){
        kill();
        return;
    }
    if(idx>=M+1)  return;
    chk[idx]=2;
    simulation(cnt1+1,idx+1);
    chk[idx]=0;
    simulation(cnt1,idx+1);
}
int main(){
    freopen("input.txt","r",stdin);
    cin>>N>>M>>D;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>mapCopy[i][j];
        }
    }
    simulation(0,1);
    cout<<res;
    return 0;
}