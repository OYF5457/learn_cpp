//
// Created by 陈志宵 on 16/5/25.
//
/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>>vec(nums.size() + 1);
        vector<int> res;
        unordered_map<int, int> dict;
        for(auto n : nums) {
            ++dict[n];
        }
        for(auto iter = dict.begin(); iter != dict.end(); ++iter) {
            vec[iter->second].push_back(iter->first);
        }
        for(int i = vec.size() - 1; i >= 0 && res.size() < k; --i) {
            for(int num : vec[i]) {
                res.push_back(num);
                if(res.size() == k) {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec{1,1,1,2,2,3};
    Solution solution;
    vector<int> res = solution.topKFrequent(vec, 2);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}


