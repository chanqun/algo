#include <iostream>
#include <algorithm>

using namespace std;

int Gear[5][8];
int K;
int chk[100][2];

void change(int n, int direction){
    if(direction==-1){
        int temp=Gear[n][0];
        for(int i=0;i<7;i++){
            Gear[n][i]=Gear[n][i+1];
        }
        Gear[n][7]=temp;
    }

    if(direction==1){
        int temp=Gear[n][7];
        for(int i=7;i>=1;i--){    
            Gear[n][i]=Gear[n][i-1];
        }
        Gear[n][0]=temp;
        
    }
}

void Rotate(int num){
    int ny = chk[num][0];
    int nx = chk[num][1];
    int nx2;
    if(nx==1){
        nx2=-1;
    }else{
        nx2=1;
    }
    
    if(ny==1){
        if(Gear[1][2]!=Gear[2][6]){
            if(Gear[2][2]!=Gear[3][6]){
                if(Gear[3][2]!=Gear[4][6]){
                    change(1,nx);
                    change(2,nx2);
                    change(3,nx);
                    change(4,nx2);
                }else{
                    change(1,nx);
                    change(2,nx2);
                    change(3,nx);
                }
            }else{
                change(1,nx);
                change(2,nx2);
            }
        }else{
            change(1,nx);
        }
    }else if(ny==2){
        if(Gear[1][2]!=Gear[2][6]){
            change(1,nx2);
        }

        if(Gear[2][2]!=Gear[3][6]){
            if(Gear[3][2]!=Gear[4][6]){
                change(2,nx);
                change(3,nx2);
                change(4,nx);
            }else{
                change(2,nx);
                change(3,nx2);
            }
        }else{
            change(2,nx);
        }
    }else if(ny==3){
        if(Gear[3][2]!=Gear[4][6]){
            change(4,nx2);
        }
        if(Gear[3][6]!=Gear[2][2]){
            if(Gear[2][6]!=Gear[1][2]){
                change(3,nx);
                change(2,nx2);
                change(1,nx);
            }else{
                change(3,nx);
                change(2,nx2);
            }
        }else{
            change(3,nx);
        }

    }else if(ny==4){
        if(Gear[4][6]!=Gear[3][2]){
            if(Gear[3][6]!=Gear[2][2]){
                if(Gear[2][6]!=Gear[1][2]){
                    change(4,nx);
                    change(3,nx2);
                    change(2,nx);
                    change(1,nx2);
                }else{
                    change(4,nx);
                    change(3,nx2);
                    change(2,nx);
                }
            }else{
                change(4,nx);
                change(3,nx2);
            }
        }else{
            change(4,nx);
        }
    }
}


int main(){
    freopen("input.txt","r",stdin);

    for(int i=1;i<=4;i++){
        for(int j=0;j<8;j++){
            scanf("%1d",&Gear[i][j]);
        }
    }
    cin >> K;
    for(int i=0;i<K;i++){
        cin>>chk[i][0]>>chk[i][1];
        Rotate(i);
    }

    int solution=0;
    int k=1;
    for(int i=1;i<=4;i++){
        if(Gear[i][0]==1){
            solution+=k;
        }
        k*=2;
    }

    cout<<solution;
    
    return 0;
}