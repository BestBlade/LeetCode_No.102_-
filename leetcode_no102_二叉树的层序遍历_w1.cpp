/* ------------------------------------------------------------------|
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了89.26%的用户
*	内存消耗：11.6 MB, 在所有 C++ 提交中击败了66.82%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    if (!root) {
        return {};
    }
    q.emplace(root);
    vector<vector<int>> res;
    while (!q.empty()) {
        int len = q.size();
        vector<int> tmp;
        while (len--) {
            TreeNode* curr = q.front();
            q.pop();
            tmp.emplace_back(curr->val);
            if (curr->left) {
                q.emplace(curr->left);
            }
            if (curr->right) {
                q.emplace(curr->right);
            }
        }
        res.emplace_back(tmp);
    }
    return res;
}