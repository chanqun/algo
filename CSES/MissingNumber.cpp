#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;
int ar[mxN];
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin>>N;
    for(int i=0, a;i<N-1;i++){
        cin>>a;
        ar[a-1]++;
    }
    for(int i=0;i<mxN;i++){
        if(ar[i]==0){
            cout<<i+1;
            return 0;
        }
    }

	return 0;
}