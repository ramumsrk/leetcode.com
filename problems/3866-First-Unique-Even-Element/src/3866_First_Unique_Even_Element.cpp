#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;

auto
firstUniqueEven(
    const vector<int>& nums
) -> int {
    // even numbers and their occurrences
    map<int,int> n_o;
    // build a map of even numbers and their
    // occurrences from a vector
    for (int i {}; i < static_cast<int>(nums.size()); i += 1) {
        if (nums[i]%2 == 0) {
            if (!n_o.contains(nums[i])) {
                n_o[nums[i]] = 1;
            } else {
                n_o[nums[i]] += 1;
            }
        }
    }
    // there are no even numbers in input vector
    if (n_o.size() == 0) return -1;
    // first even number in vector that has only
    // an occurrence of 1. -1 if there is no such
    // even number
    int first_even_number {-1};
    for (int i {}; i < static_cast<int>(nums.size()); i += 1) {
        if (
            nums[i]%2 == 0
            &&
            n_o[nums[i]] == 1
        ) {
            first_even_number = nums[i];
            break;
        }
    }
    return first_even_number;
}

auto
main(void) -> int {
    int t {};
    cin>>t;
    while (t) {
        int n {};
        cin>>n;
        vector<int> nums(n,0);
        for (auto& e : nums) {
            cin>>e;
        }
        int result {firstUniqueEven(nums)};
        cout<<result<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}