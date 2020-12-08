#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100][100];
int R,C,K;

int solve(){

    int rsize = 3, csize=3;

    for(int t=0;t<=100;t++){
        if(arr[R][C]==K){
            return t;
        }

        if(rsize>=csize){
            for(int i=0;i<rsize;i++){
                vector <pair<int, int>> nums;
                nums.clear();
                int cnt[101]={0,};
                for(int j=0;j<csize;j++){
                    cnt[arr[i][j]]++;
                }
                for(int c=1;c<=100;c++){
                    if(cnt[c]>0){
                        nums.push_back({cnt[c],c});
                    }
                }
                sort(nums.begin(), nums.end());
                int idx = 0;
                for(auto pair : nums){
                    if (idx >=99) break;
                    arr[i][idx++] = pair.second;
                    arr[i][idx++] = pair.first;
                }
                csize = max(csize,idx);
                for(;idx<100;idx++){
                    arr[i][idx] = 0;
                }
            }
        }else{
            for(int j=0;j<csize;j++){
                vector <pair<int, int>> nums;
                nums.clear();
                int cnt[101]={0,};
                for(int i=0;i<rsize;i++){
                    cnt[arr[i][j]]++;
                }
                for(int c=1;c<=100;c++){
                    if(cnt[c]>0){
                        nums.push_back({cnt[c],c});
                    }
                }
                sort(nums.begin(),nums.end());
                int idx = 0;
                for(auto pair:nums){
                    if(idx>=99) break;
                    arr[idx++][j] = pair.second;
                    arr[idx++][j] = pair.first;
                }
                rsize = max(rsize, idx);
                for(;idx<100;idx++){
                    arr[idx][j]=0;
                }
            }
        }
    }
    return -1;

}

int main(){
    freopen("input.txt","r",stdin);
    cin>>R>>C>>K;
    R--;
    C--;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    cout<<solve();

    return 0;
}
