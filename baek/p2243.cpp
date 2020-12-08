#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
int N, M, K;

vector <ll> num1;

struct IndexedTree {
    vector <ll> tree;
    vector <ll> nums;
    int leafSize = 0, depth = 0;

    IndexedTree(vector <ll> nums1) {
        nums = nums1;
        while (pow(2, depth) < nums1.size() - 1) {
            depth++;
        }
        leafSize = pow(2, depth);
        while (nums.size() <= leafSize) {
            nums.push_back(0);
        }
        tree.resize(pow(2, depth + 1));
    }
    //내부노드에 값을 채워준다.
    ll makeTree(ll node, ll left, ll right) {
        if (left == right) {
            if (left <= nums.size()) {
                return tree[node] = nums[left];
            }
            else {
                return tree[node] = 0;
            }
        }
        ll mid = (left + right) / 2;
        tree[node] = makeTree(2 * node, left, mid);
        tree[node] += makeTree(2 * node + 1, mid + 1, right);
        return tree[node];
    }

    ll queryCount(ll node, ll left, ll right, ll target) {
        if (left == right) {//leaf에 도착함
            return left;
        }
        else {
            ll mid = (left + right) / 2;
            if (tree[node * 2] >= target) {
                return queryCount(node * 2, left, mid, target);
            }
            else {
                target -= tree[node * 2];
                if (tree[node * 2 + 1] >= target) {
                    return queryCount(node * 2 + 1, mid + 1, right, target);
                }
                else {
                    return 0;
                }
            }
        }
    }

    void update(ll node, ll left, ll right, ll index, ll diff) {
        if (index < left || right < index) {
            return;
        }
        else {
            tree[node] += diff;
            if (left != right) {
                ll mid = (left + right) / 2;
                update(node * 2, left, mid, index, diff);
                update(node * 2 + 1, mid + 1, right, index, diff);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);

    num1.resize(1000001);
    cin >> N;
    IndexedTree h(num1);

    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            int temp = h.queryCount(1, 1, 1000000, b);
            cout << temp << "\n";
            h.update(1, 1, 1000000, temp, -1);
        }
        else {
            cin >> b >> c;
            h.update(1, 1, 1000000, b, c);
        }
    }

    return 0;
}