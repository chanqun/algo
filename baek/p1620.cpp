#include <iostream>
#include <map>
#include <string>

using namespace std;

int N,M;
map <int, string> a;
map <string, int> b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt","r",stdin);

    cin>>N>>M;

    for(int i=1;i<=N;i++){
        string temp;
        cin>>temp;
        a.insert({i,temp});
        b.insert({temp,i});
    }

    for(int i=1;i<=M;i++){
        string tt;
        cin>>tt;
        if(tt[0]>='0'&&tt[0]<='9'){
            int temp = stoi(tt);
            cout<<a.at(temp)<<"\n";
        }else{
            cout<<b.at(tt)<<"\n";
        }
    }
    return 0;
}