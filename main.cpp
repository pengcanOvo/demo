#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

int clumsy(int N) {
    int temp[N];
    int result=0;
    for (int i = N; i > 0; --i) {
        temp[N-i]=i;
    }
    int i = 0;
    while(i < N-1){
        temp[i+1] = temp[i] * temp[i+1];
        temp[i]=0;
        i=i+4;
    }
    i=1;
    while (i<N-1){
        temp[i+1] = temp[i] / temp[i+1];
        temp[i]=0;
        i+=4;
    }

    i = 1;
    for (int j = 0; j <= N-1; j++) {
        if (temp[j]==0) continue;
        if (i%2 == 0 || result == 0){
            result+=temp[j];
        }else{
            result-=temp[j];
        }
        i++;
    }
    return result;
}


int findMaximumXOR(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
            int temp = nums.at(i)^nums.at(j);
            result = result >= temp ? result : temp;
        }
    }
    return result;
}
struct TrieNode
{
    array<TrieNode *, 2> data;
    TrieNode() { data.fill(nullptr); }
    bool contains(int bit) { return data[bit] != nullptr; }
    TrieNode *put(int bit) { return data[bit] = new TrieNode(); }
};
struct TrieTree
{
    TrieNode *root;
    TrieTree() { root = new TrieNode(); }
    void add(int val)
    {
        auto cur = root;
        for (int i=31; i>=0; i--)
        {
            int bit = (val >> i) & 1;
            if (cur->contains(bit)) cur = cur->data[bit];
            else cur = cur->put(bit);
        }
    }
    int search(int val)
    {
        auto cur = root;
        int ans = 0;
        for (int i=31; i>=0; i--)
        {
            int bit = (val >> i) & 1;
            int match = cur->contains(1 - bit) ? 1 - bit : bit;
            ans |= (match << i);
            cur = cur->data[match];
        }
        return ans;
    }
};

int main() {
    vector<int> temp ={3,10,5,25,2,8};
    cout << findMaximumXOR(temp);

}


