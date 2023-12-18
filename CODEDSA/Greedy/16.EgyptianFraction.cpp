// Một phân số đơn vị nếu tử số của phân số đó là 1. Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số đơn vị. Ví dụ 2/3 = 1/2 + 1/6. Cho phân số nguyên dương P/Q bất kỳ , hãy biểu diễn phân số nguyên dương thành tổng phân số đơn vị với số hạng tử là ít nhất.

// Input Format

// 1 dòng duy nhất chứa 2 số P, Q

// Constraints

// 1<=P,Q<=200

// Output Format

// Đưa ra đáp án trên 1 dòng

// Sample Input 0

// 9 6
// Sample Output 0

// 1/1 + 1/2
// Sample Input 1

// 5 6
// Sample Output 1

// 1/2 + 1/3
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void printEgyptian(int nr, int dr) {
    if (nr == 0 || dr == 0) {
        return;
    }

    int g = gcd(nr, dr);
    nr /= g;
    dr /= g;

    if (dr % nr == 0) {
        cout << "1/" << dr/nr;
        return;
    }

    if (nr % dr == 0) {
        cout << nr/dr << "/1";
        return;
    }

    if (nr > dr) {
        cout << nr/dr << "/1 + ";
        nr = nr%dr;
    }

    int n = dr/nr;
    if (dr % nr != 0) {
        n += 1;
    }
    cout << "1/" << n;

    int new_nr = nr*n - dr;
    int new_dr = dr*n;

    if (new_nr != 0) {
        cout << " + ";
        printEgyptian(new_nr, new_dr);
    }
}

int main() {
    int nr, dr;
    cin >> nr >> dr;
    printEgyptian(nr, dr);
    return 0;
}