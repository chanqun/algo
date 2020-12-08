#include <iostream>
#include <algorithm>

using namespace std;

int N;
int col[15];
int result=0;

bool isPromising(int i){
    for(int j=0;j<i;j++){
        if(col[j]==col[i] || abs(col[i]-col[j])==(i-j)){
            return false;
        }
    }
    return true;
}

void nQueen(int i){
    if(i==N){
        result++;
        return;
    }else{
        for(int j=0;j<N;j++){
            col[i]=j;
            if(isPromising(i)){
                nQueen(i+1);
            }
        }
    }
}

int main(){

    cin>> N;
    nQueen(0);
    cout<<result<<endl;
    return 0;
}