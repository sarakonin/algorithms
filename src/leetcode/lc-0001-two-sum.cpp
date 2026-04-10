#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ts;
        bool f = false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ts.push_back(i);
                    ts.push_back(j);
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        return ts;
    }
};

int main() {
    int t, n;
    vector<int> nums;
    cin >> n >> t;

    int nn;
    while (n-- > 0) {
        cin >> nn;
        nums.push_back(nn);
    }
    Solution s;
    vector<int> sol = s.twoSum(nums, t);
    for (int i: sol)
        cout << i << " ";

    return 0;
}
