#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>N;
    for(ll i=0,a,b;i<N;i++){
        cin>>a>>b;
        if(a>2*b||b>2*a)  cout<<"NO"<<"\n";
        else if((a+b)%3==0) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }

	return 0;
}