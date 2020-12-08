#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[21][21];
int result2 = 98787987;
bool chking[21];
vector <int> team1, team2;


void startCount(){
    
    int temp1=0, temp2=0;
    team1.clear();
    team2.clear();
    for(int i=1;i<=N;i++){
        if(chking[i]){
            team1.push_back(i);
            }else{
            team2.push_back(i);
        }
    }

    for(int i=0;i<team1.size();i++){
        for(int j=i+1;j<team1.size();j++){
            temp1+=(map[team1[i]][team1[j]]+map[team1[j]][team1[i]]);  
        }
    }
    for(int i=0;i<team2.size();i++){
        for(int j=i+1;j<team2.size();j++){
            temp2+=(map[team2[i]][team2[j]]+map[team2[j]][team2[i]]);
        }
    }
    if(abs(temp1-temp2)< result2){
        result2 = abs(temp1 - temp2);
    
    }
}

void solve(int cnt, int now){

    if(cnt>=N/2){
        startCount();
    }
    else{
        for(int i=1;i<=N;i++){
            if(!chking[i]&i>now){
                chking[i] = true;
                solve(cnt+1,i);
                chking[i] = false;
            }
        }
    }
}

int main(){

    freopen("input.txt", "r", stdin);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>map[i][j];
        }
    }

    solve(0,0);
    
    cout<<result2;

    return 0;
}