#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct shark{
    int s,d,z;
};

int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};
shark map[100][100];
int R,C,M;

int simulation(){
    int sum=0;
    shark copyMap[100][100];

    for(int t=0;t<C;t++){
        for(int i=0;i<R;i++){
            if(map[i][t].z>0){
                sum+=map[i][t].z;
                map[i][t].z=0;
                break;
            }
        }
        memcpy(copyMap,map,sizeof(map));
        memset(map,0,sizeof(map));

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                shark &curr = copyMap[i][j];
                if(curr.z>0){
                    int ny = i + curr.s *dy[curr.d];
                    int nx = j + curr.s *dx[curr.d];
                    if(ny<0){
                        ny=-ny;
                        curr.d=1;
                    }
                    if(ny>R-1){
                        int a = ny/(R-1);
                        int b = ny%(R-1);
                        if(a%2==0){
                            ny=b;
                        }else{
                            ny=R-1-b;
                            curr.d=0;
                        }
                    }
                    if(nx<0){
                        nx=-nx;
                        curr.d=2;
                    }
                    if(nx>C-1){
                        int a = nx/(C-1);
                        int b = nx%(C-1);
                        if(a%2==0){
                            nx=b;
                        }else{
                            nx=C-1-b;
                            curr.d=3;
                        }
                    }
                    if(map[ny][nx].z<curr.z){
                        map[ny][nx] = curr;
                    }
                }
            }
        }
    }
    return sum;
}

int main(){
    freopen("input.txt","r",stdin);

    cin>>R>>C>>M;

    for(int i=0;i<M;i++){
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        r--;
        c--;
        d--;
        map[r][c]={s,d,z};
    }

    cout<<simulation();

    return 0;
}