#include <iostream>
#include "find_path.cpp"
int main() {
    // Test case 1
    int n = 3, m = 3;
    int a[3][3] = {
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
    };
    int mark[3][3] = {0};
    loang(0, 0, a, mark, n, m);
    if (mark[2][2] == 1) {
        std::cout << "Test case 1 passed.\n";
    } else {
        std::cout << "Test case 1 failed.\n";
    }

    // Test case 2
    n = 3, m = 3;
    int b[3][3] = {
        {1, 0, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    int mark2[3][3] = {0};
    loang(0, 0, b, mark2, n, m);
    if (mark2[2][2] == 0) {
        std::cout << "Test case 2 passed.\n";
    } else {
        std::cout << "Test case 2 failed.\n";
    }

    return 0;
}