#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

auto
countCommas(
    const int& n
) -> int {
    if (n >= 1 && n <= 999) return 0;
    return ((n - 1000)+1);
}

auto
main(void) {
    int n {};
    cin>>n;
    cout<<countCommas(n)<<endl;
    return EXIT_SUCCESS;
}