#include <iostream>
#include <cstring>
using namespace std;

int R,C,N;
int time;
int map[200][200];
int dy[]={-1,0,1,0,0};
int dx[]={0,1,0,-1,0};
bool chk[200][200];

void simulation(){
    if(time==N) return;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]==0){
                map[i][j]=3;
            }
        }
    }
    time++;
    if(time==N) return;
    while(1){
        
        memset(chk,false,sizeof(chk));
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i][j]>0){
                    map[i][j]--;
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i][j]==1){
                    for(int k=0;k<5;k++){
                        int ny = i+dy[k];
                        int nx = j+dx[k];
                        if(ny<0||nx<0||ny>=R||nx>=C)    continue;
                        chk[ny][nx]=true;
                    }
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(chk[i][j]){
                    map[i][j]=0;
                }
            }
        }
        time++;
        if(time==N) return;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i][j]==0){
                    map[i][j]=3;
                }
            }
        }
        time++;
        if(time==N) return;
    }
}


int main(){

    freopen("input.txt","r",stdin);

    cin>>R>>C>>N;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char a;
            cin>>a;
            if(a=='O'){
                map[i][j]=2;
            }
        }
    }
    time++;
    simulation();

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]!=0){
                cout<<"O";
            }else{
                cout<<".";
            }
        }
        cout<<"\n";
    }
    return 0;
}