#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<queue>

using namespace std;

constexpr int func(const int n) {
    return 10 + n;
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix.at(0).size();
    int row = 0;
    while (row < m && matrix.at(row).at(n - 1) < target) {
        row++;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (matrix.at(row).at(i) == target) return true;
    }
    return false;
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int last_size = 0;
    int last_val = 0;

    for (int i = 0; i < nums.size(); ++i) {
        int val = nums.at(i);
        int start = 0;
        if (val == last_val) {
            start = last_size == 0 ? 1 : last_size;
        }
        last_val = val;
        int size = ans.size();
        last_size = size;
        if (size == 0) {
            ans.push_back(temp);
            temp.push_back(val);
            ans.push_back(temp);
        } else {
            for (int j = start; j < size; ++j) {
                temp = ans.at(j);
                temp.push_back(val);
                ans.push_back(temp);
            }
        }
    }
    return ans;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int xDepth = 0;
int yDepth = 0;
TreeNode* xParent;
TreeNode* yParent;



void dfs(TreeNode* root, int x, int y,int depth){

    if (root->right != nullptr){
        if (root->right->val == x){
            xDepth = depth;
            xParent = root;
        }
        if (root->right->val == y){
            yDepth = depth;
            yParent = root;
        }
        dfs(root->right,x,y,depth++);
    }
    if (root->left != nullptr){
        if (root->left->val == x){
            xDepth = depth;
            xParent = root;
        }
        if (root->left->val == y){
            yDepth = depth;
            yParent = root;
        }
        dfs(root->left,x,y,depth++);
    }
    return;

}

bool isCousins(TreeNode *root, int x, int y) {
    if (root == nullptr) return false;
    dfs(root,x,y,0);
    if ((xParent != yParent) && (xDepth != yDepth)){
        return true;
    } else{
        return false;
    }
}



int findMaximumXOR(vector<int> &nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
            int temp = nums.at(i) ^nums.at(j);
            result = result >= temp ? result : temp;
        }
    }
    return result;
}


int main() {
    cout << "456546132";
}


