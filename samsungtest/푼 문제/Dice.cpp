#include <iostream>
#include <algorithm>

using namespace std;

int num[10];
int answer =0;
int position[4]={0,};
bool exChk[34]={false,};

int move(int np, bool chking){
    if(np==5&&chking) return 26;
    else if(np==10&&chking) return 21;
    else if(np==15&&chking) return 29;
    else if(np==20) return 33;
    else if(np==26) return 27;
    else if(np==27) return 28;
    else if(np==28) return 23;
    else if(np==29) return 30;
    else if(np==30) return 31;
    else if(np==31) return 23;
    else if(np==25) return 20;
    else if(np==33) return 33;
    else return np+1;
}
int score(int pos){
    if(pos==26) return 13;
    else if(pos==27) return 16;
    else if(pos==28) return 19;
    else if(pos==21) return 22;
    else if(pos==22) return 24;
    else if(pos==23) return 25;
    else if(pos==24) return 30;
    else if(pos==25) return 35;
    else if(pos==29) return 28;
    else if(pos==30) return 27;
    else if(pos==31) return 26;
    else if(pos==33) return 0;
    else return pos*2;
}
void dfs(int cnt, int total){
    if(cnt==10){
        answer = max(answer,total);
        return;
    }
    for(int i=0;i<4;i++){
        int start = position[i];
        int np = start;
        int dist = num[cnt];
        if(np==5||np==10||np==15){
            dist--;
            np = move(np, true);
        }
        while(dist--){
            np = move(np, false);
        }
        if(np!=33&&exChk[np]) continue;
        position[i] = np;
        exChk[start]=false;
        exChk[np]=true;
        dfs(cnt+1 , total+score(np));
        position[i] = start;
        exChk[start]=true;
        exChk[np]=false;
    }
}

int main(){

    freopen("input.txt","r",stdin);

    for(int i=0;i<10;i++){
        cin>>num[i];
    }
    dfs(0,0);
    cout<<answer;
    return 0;
}