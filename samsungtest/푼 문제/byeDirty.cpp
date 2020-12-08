#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int MAX = 60;
int map[MAX][MAX];
int copy_map[MAX][MAX];
int R, C, T;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int result2=0;
vector <pair<int,int >> chk_num;

void solve(){

    while(T--){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i][j]!=0&&map[i][j]!=-1){
                    int cnt=0;
                    for(int k=0;k<4;k++){
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if(ny<0||nx<0||ny>=R||nx>=C||map[ny][nx]==-1) continue;
                        copy_map[ny][nx]+=(map[i][j])/5;
                        cnt++;
                    }
                    copy_map[i][j]+=(map[i][j]-(cnt*(map[i][j]/5)));
                }
            }
        }

        int y = chk_num[0].first;
        int x = chk_num[0].second;

        for(int i=y; i>0; i--)  copy_map[i][x]=copy_map[i-1][x];
        for(int i=x; i<C-1; i++)  copy_map[0][i]=copy_map[0][i+1];
        for(int i=0; i<y; i++)  copy_map[i][C-1]=copy_map[i+1][C-1];
        for(int i=C-1; i>x; i--)  copy_map[y][i]=copy_map[y][i-1];

        int ny = y+1;
        for(int i=ny; i<R; i++) copy_map[i-1][x]=copy_map[i][x];
        for(int i=x; i<C-1; i++) copy_map[R-1][i]=copy_map[R-1][i+1];
        for(int i=R-1; i>ny; i--) copy_map[i][C-1]=copy_map[i-1][C-1];
        for(int i=C-1; i>x;i--) copy_map[ny][i]=copy_map[ny][i-1];
        copy_map[y][x]=-1;
        copy_map[ny][x]=-1;
        copy_map[y][x+1]=0;
        copy_map[ny][x+1]=0;


        memcpy(map,copy_map,sizeof(copy_map));
        memset(copy_map,0,sizeof(copy_map));
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<map[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n ";

    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]>0){
                result2+=map[i][j];
            }
        }
    }

}

int main(){

    freopen("input.txt","r",stdin);

    cin>> R >> C >> T;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
            if(map[i][j]==-1){
                chk_num.push_back({i,j});
            }
        }
    }

    solve();

    cout<<result2;

    return 0;
}