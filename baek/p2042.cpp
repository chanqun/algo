#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int N, M, K;

vector <ll> num1;

struct IndexedTree{
	vector <ll> tree;
	vector <ll> nums;
	int leafSize=0, depth=0;

	IndexedTree(vector <ll> nums1){
		nums = nums1;
		while (pow(2, depth) < nums1.size()-1) {
			depth++;
		}
		leafSize = pow(2, depth);
		while (nums.size() <= leafSize) {
			nums.push_back(0);
		}
		tree.resize(pow(2, depth + 1));
	}
	//���γ�忡 ���� ä���ش�.
	ll makeTree(ll node, ll left, ll right) {
		//������ ���� �ϸ� �����͸� ä����
		if (left == right) {
			if (left <= nums.size()) {
				return tree[node] = nums[left];
			}
			else {
				return tree[node] = 0;
			}
		}
		//���� ����� ���
		ll mid = (left + right) / 2;
		tree[node] = makeTree(node * 2, left, mid);
		tree[node] += makeTree(node * 2 + 1, mid + 1, right);
		return tree[node];
	}
	//���ϴ� ������ �� or ������ ���� ���Ѵ�.

	ll query(ll node, ll left, ll right, ll qLeft, ll qRight) {
		if (qRight < left || right<qLeft) {//���� ���� ���
			return 0;
		}
		else if (qLeft <= left && right <= qRight) {//���� ���ϴ� ���
			return tree[node];
		}
		else {//�ָ��ϰ� ���� �ִ� ���
			ll mid = (left + right) / 2;
			return query(node * 2, left, mid, qLeft, qRight) + 
				query(node * 2 + 1, mid + 1, right, qLeft, qRight);
		}
	}
	//Ư������ �����Ѵ�.
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

	cin >> N >> M >> K;
	num1.push_back(0);
	ll a,b,c;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		num1.push_back(a);
	}

	IndexedTree h(num1);
	h.makeTree(1,1,h.leafSize);
	
	for (int i = 0; i < M+K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1) {
			ll targetIndex = b;
			ll targetValue = c;
			ll diff = targetValue - h.nums[targetIndex];
			h.update(1, 1, h.leafSize, b, diff);
			h.nums[targetIndex] = targetValue;
		}
		else if (a == 2) {
			cout<<h.query(1, 1, h.leafSize, b, c)<<"\n";
		}
	}

	return 0;
}