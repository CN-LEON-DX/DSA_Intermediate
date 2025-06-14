#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (next_permutation(s.begin(), s.end())) cout << s;
    else cout << "NOT EXIST";
    return 0;
}