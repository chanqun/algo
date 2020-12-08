#include <iostream>
#include <algorithm>

using namespace std;

int Testcase;
int N,M;
int num[31][31];

int combi(int n, int r){
    if(n==r||r==0){
        return 1;
    }else{
        return num[n][r] = combi(n-1,r-1) + combi(n-1, r);
    }
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt","r",stdin);
    
    cin>>Testcase;

    for(int t=0;t<Testcase;t++){
        cin>>N>>M;
        cout<<combi(M,N)<<"\n";
    }

    return 0;
}