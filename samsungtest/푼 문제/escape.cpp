#include <iostream>
#include <queue>

using namespace std;

int N, M;
char map[10][10];
bool chk[10][10][10][10];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int ry, rx ,by, bx;

struct bead{
    int ry,rx,by,bx,d;
};

void move(int &y, int &x, int &c, int dx, int dy){
    while(map[y+dy][x+dx]!='#' && map[y][x]!='O'){
        y+=dy;
        x+=dx;
        c+=1;
    }
}
void bfs(){
    queue <bead> q;
    q.push({ry,rx,by,bx,0});
    chk[ry][rx][by][bx]=true;

    while(!q.empty()){
        int rx=q.front().rx, ry= q.front().ry, d=q.front().d;
        int bx=q.front().bx, by= q.front().by;
        q.pop();
        if(d>=10)   break;
        for(int i=0;i<4;i++){
            int nry = ry, nrx = rx,nby = by,nbx = bx;
            int rc=0, bc=0, nd=d+1;
            move(nry,nrx,rc,dx[i],dy[i]);
            move(nby,nbx,bc,dx[i],dy[i]);
            if(map[nby][nbx]=='O') continue;
            if(map[nry][nrx]=='O'){
                cout<<nd;
                return;
            }
            if(nrx==nbx && nry==nby){
                if(rc>bc) nry-=dy[i], nrx-=dx[i];
                else nby-=dy[i], nbx -= dx[i];
            }
            if(chk[nry][nrx][nby][nbx]) continue;
            chk[nry][nrx][nby][nbx] = true;
            q.push({nry,nrx,nby,nbx,nd});
        }
    }
    cout<<-1;
}


int main(){
    
    freopen("input.txt","r",stdin);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]=='R') ry=i, rx=j;
            else if(map[i][j]=='B') by=i, bx=j;
        }
    }
    
    bfs();
    return 0;
}