#include <iostream>
#include <cstdint>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int maximum_sum {nums[0]};
            int current_sum {nums[0]};
            int nums_size {static_cast<int>(nums.size())};
            for (int i {1}; i < nums_size; i += 1) {
                if (current_sum >= 0) {
                    current_sum += nums[i];
                } else if (current_sum < 0) {
                    current_sum = nums[i];
                }
                if (current_sum > maximum_sum) {
                    maximum_sum = current_sum;
                }
            }
            return maximum_sum;
        }
};

auto
main(void) -> int {
    int T {};
    cin>>T;
    while (T) {
        int N {};
        cin>>N;
        vector<int> nums(N,0);
        for (auto& e : nums) {
            cin>>e;
        }
        Solution * solution = new Solution();
        int maximum_sum {solution->maxSubArray(nums)};
        cout<<maximum_sum<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}