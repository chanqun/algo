#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int ,pair<int, int > > > v;
int N = 7; //노드의 개수
int M = 11; //간선의 개수
int parent[7];

int getParent(int node){
    if(parent[node]==node){
        return node;
    }else{
        return getParent(parent[node]);
    }
}

int unionParent(int x, int y){
    x= getParent(x);
    y= getParent(y);
    if(x<y){
        parent[y]=x;
        return x;
    }else{
        parent[x]=y;
        return y;
    }
}

int findParent(int x, int y){
    x=getParent(x);
    y=getParent(y);
    if(x==y){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    v.push_back({12,{1,7}});
    v.push_back({13,{4,7}});
    v.push_back({18,{1,4}});
    v.push_back({67,{1,2}});
    v.push_back({17,{1,5}});
    v.push_back({24,{2,4}});
    v.push_back({62,{2,5}});
    v.push_back({20,{3,5}});
    v.push_back({37,{3,6}});
    v.push_back({45,{5,6}});
    v.push_back({73,{5,7}});

    sort(v.begin(),v.end());

    for(int i=0;i<N;i++){
        parent[i]=i;
    }

    int res=0;
    for(int i=0;i<v.size();i++){
        if(!findParent(v[i].second.first-1,v[i].second.second-1)){
            res+=v[i].first;
            unionParent(v[i].second.first-1,v[i].second.second-1);
        }
    }
    

    cout<<res;

    return 0;
}