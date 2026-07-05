#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::min_element;
using std::max_element;
using std::begin;
using std::end;
using std::map;

class Solution {
    private:
        pair<int,int> minAndMaxDigits(const int& num) {
            int a_num {num};
            int remainder {};
            vector<int> digits(0,0);
            constexpr int BASE_TEN {10};
            while (a_num > 0) {
                remainder = a_num % BASE_TEN;
                digits.push_back(remainder);
                a_num /= BASE_TEN;
            }
            int min_digit {*min_element(begin(digits), end(digits))};
            int max_digit {*max_element(begin(digits), end(digits))};
            return {max_digit, min_digit};            
        }
    public:
        int maxDigitRange(vector<int>& nums) {
            int nums_size {static_cast<int>(nums.size())};
            int max_digit_range {};
            map<int,int> digit_digitrange;
            for (int i {}; i < nums_size; i += 1) {
                pair<int,int> max_and_min_digits {this->minAndMaxDigits(nums[i])};
                digit_digitrange[nums[i]] = max_and_min_digits.first - max_and_min_digits.second;
                if (max_digit_range < (max_and_min_digits.first - max_and_min_digits.second)) {
                    max_digit_range = max_and_min_digits.first - max_and_min_digits.second;
                }
            }
            int sum_max_digit_range {};
            for (const auto& [k, v] : digit_digitrange) {
                if (v == max_digit_range) {
                    sum_max_digit_range += k;
                }
            }
            return sum_max_digit_range;
        }
};

auto
main(void) -> int {
    int t {};
    cin>>t;
    Solution solution {};
    while (t) {
        int n {};
        cin>>n;
        vector<int> nums(n,0);
        for (auto& e : nums) {
            cin>>e;
        }
        cout<<solution.maxDigitRange(nums)<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}