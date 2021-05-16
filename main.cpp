#include <iostream>
#include <vector>
#include <algorithm>


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


int main() {
//    vector<int> temp = {1, 2, 2};
//    vector<vector<int>> result = subsetsWithDup(temp);
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result.at(i).size(); ++j) {
//            cout << result.at(i).at(j);
//        }
//        cout<<endl;
//    }

    cout << clumsy(4);

}


