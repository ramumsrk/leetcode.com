#include <string>
#include <iostream>
#include <cstdlib>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
    public:
        string rearrangeString(string s, char x, char y) {
            string prefix {}, suffix {}, result {};
            int x_count {};
            int s_length {static_cast<int>(s.length())};
            for (int i {}; i < s_length; i += 1) {
                if (x == s[i]) {
                    x_count += 1;
                }
            }
            if (x_count == 0) {
                result = s;
            } else {
                for (int i {}; i < s_length; i += 1) {
                    if (s[i] == y) {
                        prefix.push_back(s[i]);
                    } else {
                        suffix.push_back(s[i]);
                    }
                }
                for (const auto& ch : prefix) {
                    result.push_back(ch);
                } 
                for (const auto& ch : suffix) {
                    result.push_back(ch);
                }
            }
            return result;
        }
};

auto
main(void) -> int {
    int t {};
    cin>>t;
    Solution solution {};
    while (t) {
        string s {};
        char x {}, y {};
        cin>>s>>x>>y;
        string result {solution.rearrangeString(s, x, y)};
        cout<<result<<endl;
        t -= 1;
    }
    return EXIT_SUCCESS;
}