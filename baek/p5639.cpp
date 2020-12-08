#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
vector <int> v;

struct tree {
	int data;
	tree* left;
	tree* right;
};

tree* rootnode;

void insert(int num) {
	tree* newtree = new tree;

	newtree->data = num;
	newtree->left = NULL;
	newtree->right = NULL;

	if (cnt == 0) {
		rootnode = newtree;
	}
	else {
		tree* temp = rootnode;

		while (true) {
			if (temp->data < num) {
				if (temp->right == NULL) {
					temp->right = newtree;
					break;
				}
				temp = temp->right;
			}
			else if (temp->data > num) {
				if (temp->left == NULL) {
					temp->left = newtree;
					break;
				}
				temp = temp->left;
			}
		}
	}
	cnt++;
	return;
}

void postorder(tree* temp) {
	if (temp) {
		postorder(temp->left);
		postorder(temp->right);
		cout << temp->data << '\n'; 
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	while (cin >> n) {
		v.push_back(n);
	}

	for (int i = 0; i < v.size(); i++)
	{
		insert(v[i]);
	}

	postorder(rootnode);

	return 0;
}