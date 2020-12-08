#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
bool visited[26];
vector <char> chk;

void dfs(int index, int cnt, int mo, int ja, string s){
    if(cnt==L){
        if(mo>=1 && ja>=2){
            cout<<s<<"\n";
        }
        return;
    }
    if(index==C) return;
    if(chk[index]=='a'||chk[index]=='e'||chk[index]=='o'||chk[index]=='i'||chk[index]=='u'){
        dfs(index+1,cnt+1,mo+1,ja,s+chk[index]);
    }else{
        dfs(index+1,cnt+1,mo,ja+1,s+chk[index]);
    }
    dfs(index+1,cnt,mo,ja,s);
}

int main() {

    freopen("input.txt", "r", stdin);

    cin >> L >> C;
    
    for(int i=0;i<C;i++){
        char a;
        cin>>a;
        chk.push_back(a);
    }
    sort(chk.begin(),chk.begin()+C);
    dfs(0,0,0,0,"");

    return 0;
}