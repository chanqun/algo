#include <iostream>
using namespace std;

struct tree {
	char data;
	tree *left;
	tree *right;
};

tree trees[26];
int N;
char a, b, c;

void preorder(tree *R) {
	cout << R->data;
	if (R->left) {
		preorder(R->left);
	}
	if (R->right) {
		preorder(R->right);
	}
}

void inorder(tree *R) {
	if (R->left) {
		inorder(R->left);
	}
	cout << R->data;
	if (R->right) {
		inorder(R->right);
	}
}
void postorder(tree *R) {
	if (R->left) {
		postorder(R->left);
	}
	if (R->right) {
		postorder(R->right);
	}
	cout << R->data;
}
int main() {
	freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		trees[a - 'A'].data = a;
		if (b == '.') {
			trees[a - 'A'].left = NULL;
		}
		else{
			trees[a - 'A'].left = &trees[b - 'A'];
		}

		if (c == '.') {
			trees[a - 'A'].right = NULL;
		}
		else {
			trees[a - 'A'].right = &trees[c - 'A'];
		}
	}
	preorder(&trees[0]);
	cout << "\n";
	inorder(&trees[0]);
	cout << "\n";
	postorder(&trees[0]);
	return 0;
}