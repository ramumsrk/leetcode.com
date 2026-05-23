#include <vector>
#include <cstdlib>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution {
    public:
        int minimumSwaps(vector<int>& nums) {
            int nums_size {static_cast<int>(nums.size())};
            int zeros_count {};
            for (int i {}; i < nums_size; i += 1) {
                if (nums[i] == 0) {
                    zeros_count += 1;
                }
            }
            int min_swap_ops {};
            for (int i {nums_size-1}; zeros_count > 0; i -= 1) {
                if (nums[i] != 0) {
                    zeros_count -= 1;
                    min_swap_ops += 1;
                } else {
                    zeros_count -= 1;
                }
            }
            return min_swap_ops;
        }
};

auto
main(void) -> int {
    int T {};
    cin>>T;
    Solution solution {};
    while (T) {
        int N {};
        cin>>N;
        vector<int> nums(N,0);
        for (auto& e : nums) {
            cin>>e;
        }
        int min_swap_ops {solution.minimumSwaps(nums)};
        cout<<min_swap_ops<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}