#include <bits/stdc++.h>
using namespace std;

#define ll long long

int alphabet[26];
string al;
int chk;
list <char> solf,solm,solb;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin>>al;

    for(int i=0;i<al.size();i++){
        alphabet[al[i]-'A']++;
    }
    for(int j=0;j<26;j++){
        char a = j+'A';
        if(chk>=2){
            cout<<"NO SOLUTION";
            return 0;
        }
        int temp = alphabet[j]%2;
        int f = alphabet[j]/2;
        if(temp==0){
            for(int i=0;i<f;i++){
                solf.push_back(a);
                solb.push_front(a);
            }
        }else{
            for(int i=0;i<f;i++){
                solf.push_back(a);
                solb.push_front(a);
            }
            solm.push_back(a);
            chk++;
        }
    }
    for(auto it=solf.begin();it!=solf.end();it++){
        cout<<*it;
    }
    for(auto it=solm.begin();it!=solm.end();it++){
        cout<<*it;
    }
    for(auto it=solb.begin();it!=solb.end();it++){
        cout<<*it;
    }

	return 0;
}