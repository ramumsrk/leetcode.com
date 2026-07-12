#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <cmath>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pow;

class Solution {
    private:
        int strTimeToIntTime(const string& strTime) {
            constexpr int SIXTY_MINUTES {60}, SIXTY_SECONDS {60};
            map<char,int> CH_DIGIT {
                {'0', 0},
                {'1', 1},
                {'2', 2},
                {'3', 3},
                {'4', 4},
                {'5', 5},
                {'6', 6},
                {'7', 7},
                {'8', 8},
                {'9', 9},
            };
            int colon_count {}, intTime {}, raised {1}, hours {}, minutes {};
            for (int i {}; i < 8; i += 1) {
                if (strTime[i] == ':' && colon_count == 0) {
                    hours += intTime;
                    colon_count += 1;
                    raised = 1;
                    intTime = 0;
                    cout<<"hours: "<<hours<<endl;      
                } else if (strTime[i] == ':' && colon_count == 1) {
                    minutes += intTime;
                    raised = 1;
                    intTime = 0;
                    cout<<"minutes: "<<minutes<<endl;
                } else if (CH_DIGIT.contains(strTime[i])) {
                    intTime += CH_DIGIT[strTime[i]] * static_cast<int>(pow(10,raised));
                    raised -= 1;
                }
            }
            intTime += (((hours * SIXTY_MINUTES) + minutes) * SIXTY_SECONDS);
            cout<<"intTime: "<<intTime<<endl;
            return intTime;
        }
    public:
        int secondsBetweenTimes(string startTime, string endTime) {
            int sTime {this->strTimeToIntTime(startTime)};
            int eTime {this->strTimeToIntTime(endTime)};
            return eTime - sTime;
        }
};

auto
main(void) -> int {
    int T {};
    cin>>T;
    Solution solution {};
    while (T) {
        string startTime {}, endTime {};
        cin>>startTime>>endTime;
        cout<<solution.secondsBetweenTimes(startTime, endTime)<<endl;
        T -= 1;
    }
    return EXIT_SUCCESS;
}