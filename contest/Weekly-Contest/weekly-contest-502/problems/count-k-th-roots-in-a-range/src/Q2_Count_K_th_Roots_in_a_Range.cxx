#include <cmath>
#include <iostream>
#include <cstdlib>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::pow;
using std::map;

class Solution {
    public:
        int countKthRoots(long long int l, long long int r, int k) {
            int count_of_ints {};
            map<__int128_t, long long int> l_r {};
            for (long long int i {}; i <= r; i += 1) {
                l_r[pow(i,k)] = i;
            }
            for (;l<=r; l += 1) {
                if (l_r.contains(l)) {
                    count_of_ints += 1;
                }
            }
            return count_of_ints;
        }
        // int countKthRoots(long long int l, long long int r, int k) {
        //     int count_of_ints {};
        //     for (long long int left {l}; left <= r; left += 1) {
        //         for (long long int j {0}; j <= r; j += 1) {
        //             if (left == pow(j,k)) {
        //                 count_of_ints += 1;
        //             }
        //         }
        //     }
        //     return count_of_ints;
        // }
};

auto
main(void) -> int {
    int T {};
    cin>>T;
    Solution * solution = new Solution();
    while (T) {
        int l {}, r {}, k {};
        cin>>l>>r>>k;
        int count_of_ints {solution->countKthRoots(l, r, k)};
        cout<<count_of_ints<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}