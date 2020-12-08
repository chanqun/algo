#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX=50;

vector <pair<int,int >> chicken, home;
int map[50][50];
int N, M;
int minDistance = 98787987;
bool chk[15]={false,};

void getDistance(){
    int nowtemp=0;
    for(int i=0;i<home.size();i++){      
        int temp=98787987;
        for(int j=0;j<chicken.size();j++){
            if(chk[j]){
                if(abs(home[i].first-chicken[j].first)+abs(home[i].second-chicken[j].second)<temp){
                    temp = abs(home[i].first-chicken[j].first)+abs(home[i].second-chicken[j].second);
                }
            }
        }
        nowtemp+=temp;
    }
    if(nowtemp<minDistance){
        minDistance= nowtemp;
    }  
    return;
}

void solution(int cnt, int chking){


    if(chking==M){
        getDistance();
        return;
    }
    
    if(cnt>=chicken.size()){
        return;
    }

    chk[cnt]=true;
    solution(cnt+1,chking+1);
    chk[cnt]=false;
    solution(cnt+1,chking);
}

int main(){
    freopen("input.txt","r",stdin);
  
    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j]==1){
                home.push_back({i,j});
            }else if(map[i][j]==2){
                chicken.push_back({i,j});
            }
        }
    }

    solution(0,0);

    cout<<minDistance;

    return 0;
}