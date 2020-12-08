#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

const int MAX=20;
int N;
int map[MAX][MAX];
bool chk[MAX][MAX];
int result = 98787987;

int ny1, ny2, ny3, ny4;
int nx1, nx2, nx3, nx4;


bool chking(){
    if(ny1<0||nx1<0||ny1>=N||nx1>=N) return false;
    if(ny2<0||nx2<0||ny2>=N||nx2>=N) return false;
    if(ny3<0||nx3<0||ny3>=N||nx3>=N) return false;
    if(ny4<0||nx4<0||ny4>=N||nx4>=N) return false;
    return true;
}

int menCount(){
    vector <int> arr = {0,0,0,0,0,0};
    memset(chk,false,sizeof(chk));
    int ny11=ny1, ny22=ny2, ny33=ny3, ny44=ny4;
    int nx11=nx1, nx22=nx2, nx33=nx3, nx44=nx4;

    for(int i=0;i<ny22;i++){
        if(i>=ny1) nx11--;
        for(int j=0;j<=nx11;j++){    
            if(i>=0&&j>=00&&i<N&&j<N){   
                arr[1]+=map[i][j];
                chk[i][j]=true;
            }
        }
    }
    ny11=ny1, ny22=ny2, ny33=ny3, ny44=ny4;
    nx11=nx1, nx22=nx2, nx33=nx3, nx44=nx4;
    for(int i=0;i<=ny33;i++){
        if(i>ny1) nx11++;
        for(int j=nx11+1;j<N;j++){
            if(i>=0&&j>=00&&i<N&&j<N){   
                arr[2]+=map[i][j];
                chk[i][j]=true;
            }
        }
    }
    ny11=ny1, ny22=ny2, ny33=ny3, ny44=ny4;
    nx11=nx1, nx22=nx2, nx33=nx3, nx44=nx4;
    for(int i=ny22;i<N;i++){
        for(int j=0;j<nx22;j++){
            if(i>=0&&j>=00&&i<N&&j<N){   
                arr[3]+=map[i][j];
                chk[i][j]=true;
            }
        }
        if(i<ny4){
            nx22++;
        }
    }
    ny11=ny1, ny22=ny2, ny33=ny3, ny44=ny4;
    nx11=nx1, nx22=nx2, nx33=nx3, nx44=nx4;
    for(int i=ny33+1;i<N;i++){
        for(int j=nx33;j<N;j++){
            if(i>=0&&j>=00&&i<N&&j<N){   
                arr[4]+=map[i][j];
                chk[i][j]=true;
            }
        }
        if(i<=ny4){
            nx33--;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!chk[i][j]){
                arr[5]+=map[i][j];
            }
        }
    }

    sort(arr.begin(),arr.end());
    if((arr[5]-arr[1])<result){
        result = arr[5]-arr[1];
    }
    return result;
}

void solve(){

    for(int i=1;i<N-1;i++){
        for(int j=1;j<N-1;j++){
            ny1=i;
            nx1=j;
            for(int k=1;k<N;k++){
                for(int l=1;l<N;l++){
                    ny2 = ny1 + k;
                    nx2 = nx1 - k;
                    ny3 = ny1 + l;
                    nx3 = nx1 + l;
                    ny4 = ny1 + k + l;
                    nx4 = nx1 - k + l;
                    if(chking()){
                        menCount();
                    }
                }
            }
        }
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

    solve();
    cout<<result<<"\n";
    return 0;
}
