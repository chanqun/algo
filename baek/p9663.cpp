#include <iostream>
#include <algorithm>

using namespace std;

int N;
int chk[15];
int result=0;

bool isOk(int i){
    for(int j=0;j<i;j++){
        if(chk[j]==chk[i]||abs(chk[j]-chk[i])==(i-j)){
            return false;
        }
    }
    return true;
}

void dfs(int index){
    if(index==N){
        result++;
        return;
    }else{
        for(int i=0;i<N;i++){
            chk[index]=i;
            if(isOk(index)){
                dfs(index+1);
            }
        }
    }
}

int main(){
    cin>>N;
    dfs(0);
    cout<<result;
    return 0;
}