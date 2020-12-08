#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;

char c[1000][50];
char dna[4]={'A','C','G','T'};
int tt[4];
int res=0;

int main(){

    freopen("input.txt","r",stdin);
    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>c[i][j];
        }
    }
    for(int j=0;j<M;j++){
        memset(tt,0,sizeof(tt));
        int max=0;
        int chk=0;
        for(int i=0;i<N;i++){
            for(int k=0;k<4;k++){
                if(c[i][j]==dna[k]){
                    tt[k]++;
                }    
            }
        }
        for(int i=0;i<4;i++){
            int temp=tt[i];
            if(max<temp){
                max=temp;
                chk=i;
            }
        }
        res+=N-max;
        cout<<dna[chk];
    }
    cout<<"\n";
    cout<<res;
    return 0;
}