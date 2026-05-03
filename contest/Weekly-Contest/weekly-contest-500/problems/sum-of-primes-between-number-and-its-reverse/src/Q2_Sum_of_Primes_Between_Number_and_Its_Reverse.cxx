#include <string>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using std::to_string;
using std::pow;
using std::vector;
using std::begin;
using std::end;
using std::accumulate;
using std::cin;
using std::cout;
using std::endl;

class Solution {
    public:
        int sumOfPrimesInRange(int n) {
            int Sn_length {static_cast<int>(to_string(n).length())};
            cout<<"Sn_length: "<<Sn_length<<endl;
            int Nn {n};
            int reverse_n {}, r {};
            while (Nn > 0) {
                r = Nn%10;
                if (Sn_length == 1) {
                    reverse_n += r*1;
                } else if (Sn_length == 2) {
                    reverse_n += r*pow(10,1);
                } else if (Sn_length > 2) {
                    reverse_n += r*pow(10,Sn_length-1);
                }
                Sn_length -= 1;
                Nn /= 10;
            }
            cout<<"reverse_n: "<<reverse_n<<endl;
            int factors {0};
            vector<int> primenumbers(0,0);
            int start_number {}, end_number {};
            if (reverse_n == n) {
                start_number = n;
                end_number = n;
            } else if (reverse_n < n) {
                start_number = reverse_n;
                end_number = n;
            } else if (reverse_n > n) {
                start_number = n;
                end_number = reverse_n;
            }
            for (int i {start_number}; i <= end_number; i += 1) {
                for (int j {1}; j <= end_number; j += 1) {
                    if (i%j==0) {
                        factors += 1;
                    }
                }
                if (factors == 2) {
                    primenumbers.push_back(i);
                }
                factors = 0;
            }
            return accumulate(begin(primenumbers), end(primenumbers), int {});
        }

};

auto
main(void) -> int {
    int T {};
    cin>>T;
    while (T) {
        int n {};
        cin>>n;
        Solution * solution = new Solution();
        cout<<solution->sumOfPrimesInRange(n)<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}