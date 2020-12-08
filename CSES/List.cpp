#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
list <int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin>>N;
    if(N==1){
        cout<<1;
        return 0;
    }
    if(N<4){
        cout<<"NO SOLUTION";
        return 0;
    }

    ans.push_back(2);
    ans.push_back(4);
    ans.push_back(1);
    ans.push_back(3);
    ans.push_back(5);
    for(int i=6;i<=N;i++){
        if(i%2==0){
            ans.push_front(i);
        }else{
            ans.push_back(i);
        }
    }
    
    list<int>::iterator it;
    for(auto it=ans.begin();it!=ans.end();it++){
        cout<<*it<<" ";
    }

	return 0;
}