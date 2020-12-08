#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N,M;
int map[10][10];
bool chk[10][10];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int mc=1;
int parent[7];

vector <pair<int, pair<int, int > > > v;


int getDist(int a, int b){
    int dist = 500;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int temp=500;
            if(map[i][j]==a){
                for(int k=0;k<4;k++){
                    int ny =i , nx=j;
                    while(true){
                        ny+=dy[k];
                        nx+=dx[k];
                        if(ny>=N||nx>=M||ny<0||nx<0)  break;
                        if(map[ny][nx]==b){
                            if(abs(ny-i)+abs(nx-j)>2){
                                dist = min(dist,(abs(ny-i)+abs(nx-j)));
                                break;
                            }else{
                                break;
                            }
                        }else if(map[ny][nx]==0){
                            continue;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
    return dist;
}

void bfs(int y, int x){
    chk[y][x]=true;
    queue < pair <int, int > >  q1;
    q1.push({y,x});

    while(!q1.empty()){
        y= q1.front().first;
        x= q1.front().second;
        map[y][x]=mc;
        q1.pop();
        
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0||nx<0||ny>=N||nx>=M)    continue;
            if(map[ny][nx]==1&&!chk[ny][nx]){
                chk[ny][nx]=true;
                q1.push({ny,nx});
            }
        }
    }
}

int getParent(int node){
    if(parent[node]==node){
        return node;
    }
    return getParent(parent[node]);
}

int unionParent(int x, int y){
    x= getParent(x);
    y= getParent(y);
    if(x<y){
        parent[y]=x;
        return x;
    }else{
        parent[x]=y;
        return y;
    }
}

int findParent(int x, int y){
    x= getParent(x);
    y= getParent(y);
    if(x==y){
        return 1;
    }else{
        return 0;
    }
}

int main(){

    freopen("input.txt","r",stdin);

    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    //섬표시
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==1&&!chk[i][j]){
                bfs(i,j);
                mc++;
            }
        }
    }
    //거리 저장
    int D = mc-1;
    for(int i=1;i<=D;i++){
        for(int j=i;j<=D;j++){
            if(i!=j){
                int tt = getDist(i,j);
                if(tt-1!=0&&tt-1>=2&&tt!=500){
                    v.push_back({tt-1,{i,j}});
                }
            }
        }
    }
    //최소 거리 구하기
    sort(v.begin(),v.end());

    for(int i=1;i<7;i++){
        parent[i]=i;
    }
    
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(!findParent(v[i].second.first,v[i].second.second)){
            sum+=v[i].first;
            unionParent(v[i].second.first,v[i].second.second);
        }
    }
    int chk = getParent(1);
    for(int i=1;i<mc;i++){
        if(chk!=getParent(i)){
            sum=-1;
        }
    }
    cout<<sum;
    
    return 0;
}