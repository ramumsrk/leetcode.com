#include <cstdlib>
#include <vector>
#include <iostream>

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
            int first_element {nums[0]}, last_element {nums[nums_size-1]};
            vector<int> result(0,0);
            result.push_back(first_element);
            bool is_greater_than_left {false}, is_greater_than_right {false};
            for (int i {1}; i <= nums_size-2; i += 1) {
                for (int j {0}; j < i; j += 1) {
                    if (nums[i] > nums[j]) {
                        is_greater_than_left = true;
                    } else {
                        is_greater_than_left = false;
                    }
                }
                for (int j {i+1}; j <= nums_size-2; j += 1) {
                    if (nums[i] > nums[j]) {
                        is_greater_than_right = true;
                    } else {
                        is_greater_than_right = false;
                    }
                }
                if (
                    is_greater_than_left
                    ||
                    is_greater_than_right
                ) result.push_back(nums[i]);
            }
            result.push_back(last_element);
            return result;   
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
        for (const auto& e: result) {
            cout<<e<<' ';
        }cout<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}