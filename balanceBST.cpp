#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
	
public:
int height(TreeNode *node)
	{
		return !node ? -1 : 1 + max(height(node->left), height(node->right));
	}
	TreeNode *buildTree(vector<int> &nodes, int start, int end)
	{
		if (start > end)
		{
			return nullptr;
		}
		int mid = (start + end) / 2;
		TreeNode *root = new TreeNode(nodes[mid]);
		root->left = buildTree(nodes, start, mid - 1);
		root->right = buildTree(nodes, mid + 1, end);
		return root;
	}

	TreeNode* balanceBST(TreeNode *root) {
		if (!root) return nullptr;
		vector<int> nodes;
		queue<TreeNode *> queue;
		queue.push(root);
		while (!queue.empty())
		{
			TreeNode *curr = queue.back();
			nodes.push_back(curr->val);
			queue.pop();
			if (curr->left)
			{
				queue.push(curr->left);
			}
			if (curr->right)
			{
				queue.push(curr->right);
			}
		}
		sort(nodes.begin(), nodes.end());
		return this->buildTree(nodes, 0, nodes.size() - 1);
	}
};

void test(){
	
	TreeNode* nodo_a = new TreeNode(1);
	TreeNode* nodo_b = new TreeNode(2);
	TreeNode* nodo_c = new TreeNode(3);
	TreeNode* nodo_d = new TreeNode(4);
	nodo_a->right = nodo_b;
	nodo_b->right = nodo_c;
	nodo_c->right = nodo_d;
	assert(Solution().balanceBST(nodo_a) == nodo_c);
	
	nodo_a = new TreeNode(2);
	nodo_b = new TreeNode(1);
	nodo_c = new TreeNode(3);
	nodo_a->left = nodo_b;
	nodo_a->right = nodo_c;
	assert(Solution().balanceBST(nodo_a) == nodo_a);
	
}

int main(){
	test();
	return 0;
}
