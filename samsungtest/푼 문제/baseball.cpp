#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N;
int map[51][11];
int num[11];
bool chk[11];
int res=0;

void simulation(){
    int score=0;
    int k=1;
    for(int i=1;i<=N;i++){
        queue <int> field;
        for(int j=0;j<3;j++){
            field.push(0);
        }
        int cnt=0;
        while(cnt!=3){
            if(map[i][num[k]]==1){
                field.push(1);
                score+=field.front();
                field.pop();
            }else if(map[i][num[k]]==2){
                field.push(1);
                field.push(0);
                for(int j=0;j<2;j++){
                    score+=field.front();
                    field.pop();
                }
            }else if(map[i][num[k]]==3){
                field.push(1);
                field.push(0);
                field.push(0);
                for(int j=0;j<3;j++){
                    score+=field.front();
                    field.pop();
                }
            }else if(map[i][num[k]]==4){
                field.push(1);
                field.push(0);
                field.push(0);
                field.push(0);
                for(int j=0;j<4;j++){
                    score+=field.front();
                    field.pop();
                }
            }else{
                cnt++;
            }
            k++;
            if(k==10){
                k=1;
            }
        }
    }

    if(res<score)   res=score;
}

void dfs(int cnt){
    if(cnt==10){
        simulation();
        return;
    }
    for(int i=1;i<=9;i++){
        if(num[i]!=0)   continue;
        num[i]=cnt;
        dfs(cnt+1);
        num[i]=0;
        
    }
}

int main(){

    freopen("input.txt","r",stdin);

    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=9;j++){
            cin>>map[i][j];
        }
    }
    num[4]=1;
    dfs(2);
    cout<<res;
    return 0;
}