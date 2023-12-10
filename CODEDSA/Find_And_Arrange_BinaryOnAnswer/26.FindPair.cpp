// Cho mảng A[] gồm N phần tử và số X. Nhiệm vụ của bạn là tìm cặp phần tử A[i] - A[j] = X. Nếu tồn tại A[i] - A[j] = X đưa ra 1, ngược lại đưa ra -1.

// Input Format

// Dòng thứ nhất là cặp số N, X; Dòng tiếp theo là N số A[i] là các phần tử của mảng A[].

// Constraints

// 1≤ N ≤10^5; 1≤ X, A[i] ≤10^5.

// Output Format

// In ra 1 nếu tìm thấy một cặp số có hiệu bằng X, ngược lại in ra -1.

// Sample Input 0

// 5 3
// 1 1 2 3 5
// Sample Output 0

// 1
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    if (n==1) {
        cout << -1;
        return 0;
    }
    unordered_map<int, int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (x == 0 && nums[num] > 0) {
            cout << 1;
            return 0;
        }
        if (nums.count(num - x) > 0 || nums.count(num + x) > 0) {
            cout << 1;
            return 0;
        }
        nums[num]++;
    }
    cout << -1;
    return 0;
}