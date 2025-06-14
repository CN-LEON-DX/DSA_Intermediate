// Cho mảng số nguyên gồm N phần tử, các phần tử trong mảng không quá 100. Hãy liệt kê các hoán vị của các phần tử khác nhau trong mảng theo thứ tự ngược.

// Input Format

// Dòng đầu tiên là N; Dòng thứ 2 là các phần tử trong mảng;

// Constraints

// 1<=N<=15;

// Output Format

// In ra các hoán vị ngược của các phần tử khác nhau trong mảng.

// Sample Input 0

// 2
// 1 2
// Sample Output 0

// 2 1
// 1 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    N = arr.size();
    sort(arr.begin(), arr.end(), greater<int>());
    do {
        for (int i = 0; i < N; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    } while (prev_permutation(arr.begin(), arr.end()));
    return 0;
}