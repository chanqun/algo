#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct dragon{
    int x,y,d,g;
};
int map[110][110]={0,};
int N;
dragon d1[21];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
vector <int> moving;


int count(){
    int cnt=0;
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            if(map[i][j]==1&&map[i+1][j]==1&&map[i+1][j+1]==1&&map[i][j+1]==1){
                cnt++;
            }
        }
    }
    return cnt;
}

void goDragon(int n){
    int ny = d1[n].y;
    int nx = d1[n].x;
    int nd = d1[n].d;
    int ng = d1[n].g;
    moving.clear();
    map[ny][nx]=1;
    moving.push_back(nd);

    while(ng--){
        int now_size=moving.size()-1;
        for(int i=now_size;i>=0;i--){
            int temp = moving[i];
            temp = (temp+1)%4;
            moving.push_back(temp);
        }
    }

    for(int i=0;i<moving.size();i++){
        ny = ny + dy[moving[i]];
        nx = nx + dx[moving[i]];
        map[ny][nx]=1;
    }
}

int main(){
    // freopen("input.txt","r",stdin);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>> d1[i].x >> d1[i].y >> d1[i].d >> d1[i].g;
    }

    for(int i=0;i<N;i++){
        goDragon(i);
    }
    
    int result2 = count();
    cout<<result2;
    return 0;
}