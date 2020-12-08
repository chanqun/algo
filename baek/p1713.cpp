#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,K,temp;
vector <pair<int,int>> candi;

void chking(int a){
    int chking=true;
    for(int i=0;i<candi.size();i++){
        if(candi[i].first==a){
            candi[i].second++;
            chking=false;
            break;
        }
    }
    if(chking){
        if(candi.size()<N){
            candi.push_back({a,1});
        }else{
            int min=1000;
            int index=-1;
            for(int i=0;i<candi.size();i++){
                int chk = candi[i].second;
                if(min>chk){
                    min=chk;
                    index=i;
                }
            }
            candi.erase(candi.begin()+index);
            candi.push_back({a,1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt","r",stdin);
    
    cin>>N>>K;
    for(int i=0;i<K;i++){
        cin>>temp;
        chking(temp);
    }
    sort(candi.begin(),candi.end());
    for(int i=0;i<N;i++){
        cout<<candi[i].first<<" ";
    }
    return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node{
public:
    int time;
    int value;
    int reco;
    bool isin;
};

int s, k, min_index;
vector<int> input;
vector<node> now;
int map[101];

bool compare(node a, node b){
    if(a.reco > b.reco){
        return true;
    }
    else if(a.reco == b.reco){
        if(a.time > b.time){
            return true;
        }
        else if(a.time < b.time){
            return false;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool compare2(node a, node b){
    return a.value < b.value;
}

int main(){
    cin >> s >> k;
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    for(int i=0; i<input.size(); i++){
        if(map[input[i]]){
            for(int j=0; j<now.size(); j++){
                if(now[j].value == input[i]){
                    map[input[i]]++;
                    now[j].reco++;
                }
            }
        }
        else{
            node n;
            n.time = i;
            n.value = input[i];
            n.reco = 1;
            map[input[i]] = 1;
            if(now.size()<s){
                now.push_back(n);
            }
            else{
                sort(now.begin(), now.end(), compare);
                map[now.back().value] = 0;
                now.pop_back();
                now.push_back(n);
            }
        }
      
    }

    sort(now.begin(), now.end(), compare2);
    
    for(int i=0; i<now.size(); i++){
        cout << now[i].value << " ";
    }
}
*/