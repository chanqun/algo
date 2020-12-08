#include <iostream>
#include <vector>

using namespace std;

int N,M;
int map[510][510];
int result=0;
vector <int> dy[19]={{0,0,0,0},{0,1,2,3},{0,0,1,1},{1,1,1,0},{0,0,1,2},
{0,0,0,1},{0,1,2,2},{0,1,1,2},{1,1,0,0},{1,1,1,0},{0,1,1,2},{0,0,0,1},{1,0,1,2},{0,1,1,1},{0,1,2,2},{0,0,0,1},{0,0,1,2},{0,1,1,2},{0,0,1,1}};
vector <int> dx[19]={{0,1,2,3},{0,0,0,0},{0,1,0,1},{0,1,2,2},{0,1,1,1},
{0,1,2,0},{0,0,0,1},{0,0,1,1},{0,1,1,2},{0,1,2,1},{0,0,1,0},{0,1,2,1},{0,1,1,1},{0,0,1,2},{1,1,0,1},{0,1,2,2},{0,1,0,0},{1,1,0,0},{0,1,1,2}};

void simulation(int n){

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int temp=0;
            int cnt=0;
            for(int k=0;k<4;k++){
                int ny = i+dy[n][k];
                int nx = j+dx[n][k];
                if(ny<0||nx<0||ny>=N||nx>=M) {
                    temp=0;
                    break;
                }
                cnt++;
                temp+=map[ny][nx];
            }
            if(temp>result&&cnt==4){
                result =temp;
            }
        }
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
    for(int i=0;i<19;i++){
        simulation(i);
    }
    cout<<result;
    
    return 0;
}