// Cho 4 số nguyên X, Y, Z, T. Nhiệm vụ của bạn là tìm giá trị lớn nhất của biểu thức X o1 Y o2 Z o3 T, trong đó o1, o2, o3 có thể là các dấu +, -.

// Input Format

// Dòng duy nhất gồm 4 số X, Y, Z, T

// Constraints

// -10^5<=X,Y,Z,T<=10^4

// Output Format

// In ra giá trị lớn nhất của biểu thức

// Sample Input 0

// 59 71 80 -3
// Sample Output 0

// 213
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int X, Y, Z, T;
    cin >> X >> Y >> Z >> T;
    int arr[4] = {X, Y, Z, T};
    sort(arr, arr + 4);
    int result = -arr[0];
    for (int i = 1; i < 4; ++i) {
        result += arr[i];
    }
    cout << result << endl;
    return 0;
}
