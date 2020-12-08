#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

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
		//리프에 도달 하면 데이터를 채워줌
		if (left == right) {
			if (left <= nums.size()) {
				return tree[node] = nums[left];
			}
			else {
				return tree[node] = 0;
			}
		}
		//내부 노드일 경우
		ll mid = (left + right) / 2;
		tree[node] = makeTree(node * 2, left, mid);
		tree[node] += makeTree(node * 2 + 1, mid + 1, right);
		return tree[node];
	}
	//원하는 구간의 합 or 문제에 답을 구한다.

	ll query(ll node, ll left, ll right, ll qLeft, ll qRight) {
		if (qRight < left || right < qLeft) {//관련 없는 경우
			return 0;
		}
		else if (qLeft <= left && right <= qRight) {//완전 속하는 경우
			return tree[node];
		}
		else {//애매하게 걸쳐 있는 경우
			ll mid = (left + right) / 2;
			return query(node * 2, left, mid, qLeft, qRight) +
				query(node * 2 + 1, mid + 1, right, qLeft, qRight);
		}
	}
	//특정값을 갱신한다.
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
	cin >> N >> M;
	num1.push_back(0);
	ll a, b, c, d;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		num1.push_back(a);
	}

	IndexedTree h(num1);
	h.makeTree(1, 1, h.leafSize);

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c >> d;
		ll targetIndex = c;
		ll targetValue = d;
		ll diff = targetValue - h.nums[targetIndex];
		if (a < b) {
			cout << h.query(1, 1, h.leafSize, a, b) << "\n";
		}
		else {
			cout << h.query(1, 1, h.leafSize, b, a) << "\n";
		}
		h.update(1, 1, h.leafSize, c, diff);
		h.nums[targetIndex] = targetValue;
	}

	return 0;
}