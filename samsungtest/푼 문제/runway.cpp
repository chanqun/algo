#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;

int map[MAX][MAX];
int N, L;
int sol;
vector <int> temp;

bool chk(){
    int up[MAX]={0,};
    int down[MAX]={0,};

    for(int i=0;i<N-1;i++){
        if(abs(temp[i]-temp[i+1])>1) return false;
    }

    for(int i=0;i<N-1;i++){
        if(temp[i]-temp[i+1]==1){
            for(int j=1;j<=L;j++){
                if(i+j>=N) return false;
                up[i+j]++;
            }
        }
    }
    

    for(int i=N-1;i>0;i--){
        if(temp[i]-temp[i-1]==1){
            for(int j=1;j<=L;j++){
                if(i-j<0) return false;
                down[i-j]++;
            }
        }
    }

    for(int i=0;i<N;i++){
        if(up[i]>=2){
            return false;
        }
        if(down[i]>=2){
            return false;
        }
        if(up[i]>=1&&down[i]>=1){
            return false;
        }
    }

    return true;
}


void solution(){

    for(int i=0;i<N;i++){
        temp.clear();
        for(int j=0;j<N;j++){
            temp.push_back(map[i][j]);
        }
        bool now = chk();
        if(now) sol++;
    }

    for(int j=0;j<N;j++){
        temp.clear();
        for(int i=0;i<N;i++){
            temp.push_back(map[i][j]);
        }
        bool now = chk();
        if(now) sol++;
    }

}


int main(){

    freopen("input.txt","r",stdin);

    cin>>N>>L;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }

    solution();
    
    cout<<sol;

    return 0;
}