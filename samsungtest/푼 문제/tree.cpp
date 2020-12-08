#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int dy[]={-1,-1,-1,0,0,1,1,1};
int dx[]={-1,0,1,-1,1,-1,0,1};
int N,M,K;
vector <int> tree[10][10];
int map[10][10];
int copyMap[10][10];

void simulation(){
    //봄,여름
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=tree[i][j].size()-1;k>=0;k--){
                if(tree[i][j][k]<=map[i][j]){
                    map[i][j]-=tree[i][j][k];
                    tree[i][j][k]++;
                }else{
                    int temp=0;
                    for(int t=0;t<=k;t++){
                        map[i][j]+=tree[i][j][t]/2;
                    }
                    tree[i][j].erase(tree[i][j].begin(),tree[i][j].begin()+k+1);
                    break;
                }
            }
        }
    }

    //가을
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<tree[i][j].size();k++){
                if((tree[i][j][k]%5)==0){
                    for(int t=0;t<8;t++){
                        int ny= i+dy[t];
                        int nx= j+dx[t];
                        if(ny<0||nx<0||ny>=N||nx>=N) continue;
                        tree[ny][nx].push_back(1);
                    }
                }
            }
        }
    }

    //겨울
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j]+=copyMap[i][j];
        }
    }

}

int main(){
    freopen("input.txt","r",stdin);
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>copyMap[i][j];
            map[i][j]=5;
        }
    }

    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        tree[a][b].push_back(c);
    }
    for(int i=0;i<K;i++){
        simulation();
        for(int k=0;k<N;k++){
            for(int t=0;t<N;t++){
                cout<<map[k][t]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    int res=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            res+=tree[i][j].size();
        }
    }
    cout<<res;

    return 0;
}