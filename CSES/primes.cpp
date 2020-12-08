#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6;

int N;
int arr[mxN+1][2];
bool vis[mxN+1];

bool isPrime(int n){
    int chk=0;
    if(n==2){
        return true;
    }
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            chk++;
        }
        if(chk>=2){
            return false;
        }
    }
    return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin>>N;
    for(int i=N;i>0;i--){
        arr[i][0]=i;
        for(int j=1;j<=N;j++){
            if(!vis[j]&&isPrime(i+j)){
                vis[j]=true;
                arr[i][1]=j;
                break;
            }
        }
    }
    
    for(int i=0;i<2;i++){
        for(int j=1;j<=N;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<"\n";
    }
    
	return 0;
}