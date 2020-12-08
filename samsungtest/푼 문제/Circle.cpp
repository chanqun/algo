#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, T;
int map[52][52];
int copyMap[52][52];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void simulation(int x, int d, int k){

    memcpy(copyMap, map, sizeof(map));
    k=k%M;
    for(int i=1;i<=N;i++){
        if(i%x==0){
            if(d==0){
                for(int t=0;t<k;t++){
                    int temp=copyMap[i][M];
                    for(int j=M;j>1;j--){
                        copyMap[i][j]=copyMap[i][j-1];
                    }
                    copyMap[i][1]=temp;
                }
            }else if(d==1){
                for(int t=0;t<k;t++){
                    int temp=copyMap[i][1];
                    for(int j=1;j<M;j++){
                        copyMap[i][j]=copyMap[i][j+1];
                    }
                    copyMap[i][M]=temp;
                }
            }
        }
    }
    memcpy(map,copyMap,sizeof(map));

    for(int i=1;i<=N;i++){
        copyMap[i][0]=copyMap[i][M];
        copyMap[i][M+1]=copyMap[i][1];
    }
    
    double avg=0;
    int dev =0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(copyMap[i][j]!=0){
                avg+=copyMap[i][j];
                dev++;
            }
        }
    }
    if(dev!=0){
        avg/=dev;
    }
    int chk=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int t=0;t<4;t++){
                int ny = i+dy[t];
                int nx = j+dx[t];
                if(copyMap[ny][nx]==copyMap[i][j]&&copyMap[i][j]!=0){
                    map[i][j]=0;
                    chk++;
                }
            }
        }
    }

    if(chk==0){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){ 
                if(avg<copyMap[i][j]&&copyMap[i][j]!=0){
                    map[i][j]--;
                }
                else if(avg>copyMap[i][j]&&copyMap[i][j]!=0){
                    map[i][j]++;
                }
            }
        }
        
    }
}

int main(){

    freopen("input.txt","r",stdin);
    cin>> N>> M>> T;


    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>> map[i][j];
        }
    }

    for(int i=0;i<T;i++){
        int a, b, c ;
        cin >> a>> b>> c;
        simulation(a,b,c);
    }
    
    int res = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            res+=map[i][j];
        }
    }

    cout<<res;

    return 0;
}