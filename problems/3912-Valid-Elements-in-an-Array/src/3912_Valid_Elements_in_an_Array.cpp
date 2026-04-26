#include <iostream>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
    public:
        vector<int> findValidElements(vector<int>& nums) {
            int nums_size {static_cast<int>(nums.size())};
            if (nums_size == 1) {
                return nums;
            }
            vector<int> results(0,0);
            for (int i {}; i < nums_size; i += 1) {
                // element at index 0 and
                // nums.size()-1 are always valid
                // elements
                if (
                    i == 0
                    ||
                    i == nums_size-1
                ) {
                    results.push_back(nums[i]);
                } else {
                    bool is_greater_than_left {false}; 
                    for (int j {i-1}; j >= 0; j -= 1) {
                        if (nums[i] > nums[j]) {
                            is_greater_than_left = true;
                        } else {
                            is_greater_than_left = false;
                            break;
                        }
                    }
                    bool is_greater_than_right {false};
                    for (int j {i+1}; j < nums_size; j += 1) {
                        if (nums[i] > nums[j]) {
                            is_greater_than_right = true;
                        } else {
                            is_greater_than_right = false;
                            break;
                        }
                    }
                    if (
                        is_greater_than_left
                        ||
                        is_greater_than_right
                    ) {
                        results.push_back(nums[i]);
                    }
                }
            }
            return results;
        }
};

auto
main(void) -> int {
    int t {};
    cin>>t;
    Solution * solution = new Solution();
    while (t) {
        int n {};
        cin>>n;
        vector<int> nums(n,0);
        for (auto& e : nums) {
            cin>>e;
        }
        vector<int> result {solution->findValidElements(nums)};
        for (const auto& e : result) {
            cout<<e<<' ';
        } cout<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}