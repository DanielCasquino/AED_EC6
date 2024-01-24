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
	
	TreeNode* arrayToAVL(vector<int>& array) {
		// add your code
		
	}
};


vector<int> levelOrder(TreeNode *root) 
{ 
	vector<int> vec;
    if (root == NULL)  return vec; 
 
    queue<TreeNode *> q; 
    q.push(root); 
   
    while (q.empty() == false) 
    { 
        TreeNode *node = q.front(); 
        vec.push_back(node->val);
        q.pop(); 
        if (node->left != NULL) 
            q.push(node->left); 
        if (node->right != NULL) 
            q.push(node->right); 
    }
    return vec;
}   

void test(){
	
	vector<int> array = {2, 4, 1, 3, 5, 6, 7};
	vector<int> expected = {4, 2, 6, 1, 3, 5, 7};
	vector<int> ans = levelOrder(Solution().arrayToAVL(array));
	assert(ans == expected);
	
	array = {8, 10, 15, 25, 49, 56, 60, 64, 75, 89, 100};
	expected = {56, 15, 75, 8, 25, 60, 89, 10, 49, 64, 100};
	ans = levelOrder(Solution().arrayToAVL(array));
	assert(ans == expected);
}

int main(){
	test();
	return 0;
}

