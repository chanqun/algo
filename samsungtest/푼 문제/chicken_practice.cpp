#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 98787987;
const int MAX = 50;
int N,M;
int result;
int map[MAX][MAX];
vector <pair<int, int>> home, chicken;
bool chk[16];

int distance(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b. second);
}

void dfs(int idx, int select){
    
    if(select==M){
        int tempResult = 0;
        for(int i=0;i<home.size();i++){
            int dist = INF;
            for(int j=0;j<chicken.size();j++){
                if(chk[j]){
                    dist = min(dist, distance(home[i],chicken[j]));
                }
            }
            tempResult += dist;
        }
        result = min(tempResult, result);
        return;
    }

    if(idx==chicken.size()){
        return;
    }
    chk[idx]=true;
    dfs(idx+1, select+1);
    chk[idx]=false;
    dfs(idx+1, select);

}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt","r",stdin);
    
    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                home.push_back({i,j});
            }else if(map[i][j]==2){
                chicken.push_back({i,j});
            }
        }
    }

    result = INF;
    dfs(0,0);
    cout<<result<<"\n";

    return 0;
}