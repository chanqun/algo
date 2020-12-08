#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int map[20][20];
int mapCopy[20][20];
int arr[5];
int res = 0;
/*
void moveleft();
void moveright();
void movedown();
*/
void moveup(){
    for(int j=0;j<N;j++){
        int cnt=0;
        for(int i=0;i<N;i++){
            if(map[i][j]!=0){
                int temp =map[i][j];
                map[i][j]=0;
                map[cnt][j]=temp;
                cnt++;
            }
        }

        for(int i=0;i<N-1;i++){
            if(map[i][j]==map[i+1][j]){
                map[i][j]*=2;
                map[i+1][j]=0;
            }
        }
        cnt=0;
        for(int i=0;i<N;i++){
            if(map[i][j]!=0){
                int temp =map[i][j];
                map[i][j]=0;
                map[cnt][j]=temp;
                cnt++;
            }
        }
    }
}
void moveleft(){
    for(int i=0;i<N;i++){
        int cnt=0;
        for(int j=0;j<N;j++){
            if(map[i][j]!=0){
                int temp =map[i][j];
                map[i][j]=0;
                map[i][cnt]=temp;
                cnt++;
            }
        }
        for(int j=0;j<N-1;j++){
            if(map[i][j]==map[i][j+1]){
                map[i][j]*=2;
                map[i][j+1]=0;
            }
        }
        cnt=0;
        for(int j=0;j<N;j++){
            if(map[i][j]!=0){
                int temp =map[i][j];
                map[i][j]=0;
                map[i][cnt]=temp;
                cnt++;
            }
        }
    }
}
void movedown(){
    for(int j=0;j<N;j++){
        int cnt=N-1;
        for(int i=N-1;i>=0;i--){
            if(map[i][j]!=0){
                int temp =map[i][j];
                map[i][j]=0;
                map[cnt][j]=temp;
                cnt--;
            }
        }
        for(int i=N-1;i>0;i--){
            if(map[i][j]==map[i-1][j]){
                map[i][j]*=2;
                map[i-1][j]=0;
            }
        }
        cnt=N-1;
        for(int i=N-1;i>=0;i--){
            if(map[i][j]!=0){
                int temp =map[i][j];
                map[i][j]=0;
                map[cnt][j]=temp;
                cnt--;
            }
        }
    }

}
void moveright(){
    for(int i=0;i<N;i++){
        int cnt=N-1;
        for(int j=N-1;j>=0;j--){
            if(map[i][j]!=0){
                int temp =map[i][j];
                map[i][j]=0;
                map[i][cnt]=temp;
                cnt--;
            }
        }
        for(int j=N-1;j>0;j--){
            if(map[i][j]==map[i][j-1]){
                map[i][j]*=2;
                map[i][j-1]=0;
            }
        }
        cnt=N-1;
        for(int j=N-1;j>=0;j--){
            if(map[i][j]!=0){
                int temp =map[i][j];
                map[i][j]=0;
                map[i][cnt]=temp;
                cnt--;
            }
        }
    }
}

void moving(){
    memcpy(map,mapCopy,sizeof(map));
    for(int i=0;i<5;i++){
        //0 위 1 오 2 아래 3왼
        int dir = arr[i];
        if(dir==0){
            moveup();
        }else if(dir==1){
            moveright();
        }else if(dir==2){
            movedown();
        }else if(dir==3){
            moveleft();
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]>res) {
                res=map[i][j];
            }
        }
    }
}
void simulation(int cnt){
    if(cnt==5){
        moving();
        return;
    }
    for(int i=0;i<4;i++){
        arr[cnt]=i;
        simulation(cnt+1);
    }
}

int main(){
    
    freopen("input.txt","r",stdin);

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    
    memcpy(mapCopy,map,sizeof(map));

    simulation(0);
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<res;

    return 0;
    
}