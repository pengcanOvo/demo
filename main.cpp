#include "demo.h"


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
TreeNode *xParent;
TreeNode *yParent;


void dfs(TreeNode *root, int x, int y, int depth) {

    if (root->right != nullptr) {
        if (root->right->val == x) {
            xDepth = depth;
            xParent = root;
        }
        if (root->right->val == y) {
            yDepth = depth;
            yParent = root;
        }
        dfs(root->right, x, y, depth++);
    }
    if (root->left != nullptr) {
        if (root->left->val == x) {
            xDepth = depth;
            xParent = root;
        }
        if (root->left->val == y) {
            yDepth = depth;
            yParent = root;
        }
        dfs(root->left, x, y, depth++);
    }
    return;

}

bool isCousins(TreeNode *root, int x, int y) {
    if (root == nullptr) return false;
    dfs(root, x, y, 0);
    if ((xParent != yParent) && (xDepth != yDepth)) {
        return true;
    } else {
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

vector<int> find_shui() {
    vector<int> nums;
    for (int i = 100; i < 1000; ++i) {
        int result = 0;
        int temp = i;
        do {
            result += pow(temp % 10, 3);
            temp /= 10;
        } while (temp > 0);
        if (result == i) nums.push_back(i);
    }
    return nums;
}

void test() {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << i << "x" << j << "=" << i * j << "\t";
        }
        cout << endl;
    }
}

void bubble_sort(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        cout << a[i];
    }
}

int * func(){
    int * p = new int(10);
    return p;
}

void swap(int *a, int *b){
    int * temp = a;
    a = b;
    b = temp;
}

void func(int &a){
    cout<<"";
}
void func(const int &a){
    cout<<"";
}

class Club{

    int c_h;
    int c_w;
    int c_l;
public :
    int getMj(){
        return ((c_h * c_l) * 2 + (c_h * c_w) * 2 + (c_l * c_w) * 2);
    }
    int getTj(){
        return c_w * c_l * c_h;
    }

    int getCH() const {
        return c_h;
    }

    void setCH(int cH) {
        c_h = cH;
    }

    int getCW() const {
        return c_w;
    }

    void setCW(int cW) {
        c_w = cW;
    }

    int getCL() const {
        return c_l;
    }

    void setCL(int cL) {
        c_l = cL;
    }
};



//int main() {
//
////    cout << "************************" << endl;
////    cout << "*******1. 添加联系人******" << endl;
////    cout << "*******2. 显示联系人******" << endl;
////    cout << "*******3. 删除联系人******" << endl;
////    cout << "*******4. 查找联系人******" << endl;
////    cout << "*******5. 修改联系人******" << endl;
////    cout << "*******6. 清空联系人******" << endl;
////    cout << "*******0. 推出通讯录******" << endl;
////    index();
//    int * p = func();
//
//    cout << p;
//    int a = 10;
//    int b = 30;
//    cout<< a;
//    cout<< b;
//    cout<<"交换后";
//    swap(a,b);
//    cout<< a;
//    cout<< b;
//
//
//
//
//
//
//}


