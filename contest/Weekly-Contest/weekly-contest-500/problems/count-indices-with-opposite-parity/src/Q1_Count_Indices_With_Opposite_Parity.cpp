#include <vector>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
    public:
        vector<int> countOppositeParity(vector<int>& nums) {
            vector<int> answer(0,0);
            int nums_size {static_cast<int>(nums.size())};
            for (int i {}; i < nums_size; i += 1) {
                int number = nums[i];
                bool is_even {false}, is_odd {false};
                if (number%2==0) {
                    is_even = true;
                } else {
                    is_odd = true;
                }
                if (is_even) {
                    int count {};
                    for (int j {i+1}; j < nums_size; j += 1) {
                        if (nums[j]%2!=0) {
                            count += 1;
                        }
                    }
                    answer.push_back(count);
                } else if (is_odd) {
                    int count {};
                    for (int j {i+1}; j < nums_size; j += 1) {
                        if (nums[j]%2==0) {
                            count += 1;
                        }
                    }
                    answer.push_back(count);
                }
            }
            return answer;
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
        vector<int> answer = solution->countOppositeParity(nums);
        for (const auto& e : answer) {
            cout<<e<<' ';
        }cout<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}