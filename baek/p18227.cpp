#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int MAX = 200001;
int N, C, Q;
vector <ll> num2;
vector<int> node[MAX];
int d[MAX];
struct tree {
    int start;
    int end;
    int index;
};
tree trees[MAX];

struct IndexedTree {
    vector <ll> tree;
    vector <ll> num;
    int leafSize = 0, depth = 0;

    IndexedTree(vector <ll> num1) {
        num = num1;
        while (pow(2, depth) < num1.size() - 1) {
            depth++;
        }
        leafSize = pow(2, depth);
        while (num.size() <= leafSize) {
            num.push_back(0);
        }
        tree.resize(2 * leafSize);
    }

    ll query(int node, int left, int right, int qLeft, int qRight) {
        if (qRight < left || right < qLeft) {
            return 0;
        }
        else if (qLeft <= left && right <= qRight) {
            return tree[node];
        }
        else {
            ll mid = (left + right) / 2;
            return query(node * 2, left, mid, qLeft, qRight) + query(node * 2 + 1, mid + 1, right, qLeft, qRight);
        }
    }

    void update(int node, int left, int right, int index) {
        if (index < left || right < index) {
            return;
        }
        else {
            tree[node] += 1;
            if (left != right) {
                ll mid = (left + right) / 2;
                update(2 * node, left, mid, index);
                update(2 * node + 1, mid + 1, right, index);
            }
        }
    }
};


int cnt = 1;
void dfs(int n){
    trees[n].start = cnt;
    trees[n].index = cnt;
    cnt++;
    for (int i = 0; i < node[n].size(); i++) {
        int ny = node[n][i];
        if (!d[ny]) {
            d[ny] = d[n] + 1;
            dfs(ny);
        }
    }
    trees[n].end = cnt-1;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    
    num2.resize(200001);
    IndexedTree h(num2);

    cin >> N >> C;
    for (int i = 0; i < N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    d[C] = 1;
    dfs(C);

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            h.update(1, 1, h.leafSize, trees[b].index);
        }
        else if (a == 2) {
           cout << h.query(1, 1, h.leafSize, trees[b].start, trees[b].end)*d[b]<<"\n";
        }
    }
    return 0;
}