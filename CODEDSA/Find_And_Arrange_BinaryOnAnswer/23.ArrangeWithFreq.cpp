// Cho mảng A[] gồm n phần tử. Bạn hãy thực hiện làm các công việc sau đây :

// Sắp xếp các phần tử trong mảng theo tần suất giảm dần, nếu 2 số có cùng tần suất thì số nào nhỏ hơn sẽ in ra trước.

// Sắp xếp các phần tử trong mảng theo tần suất giảm dần, nếu 2 số có cùng tần suất thì số nào xuất hiện trước sẽ in ra trước.

// Input Format

// Dòng đầu tiên đưa vào n là số phần tử của mảng A[]; Dòng tiếp theo là n số A[i] ; Các số được viết cách nhau một vài khoảng trống.

// Constraints

// 1<=n<=10^5; 0<=A[i]<=10^6;

// Output Format

// Dòng đầu tiên in ra các số được sắp xếp theo yêu cầu 1. Dòng thứ 2 in ra các số được sắp xêp theo yêu cầu 2.

// Sample Input 0

// 10
// 6 8 4 10 3 4 10 2 4 1 
// Sample Output 0

// 4 4 4 10 10 1 2 3 6 8 
// 4 4 4 10 10 6 8 3 2 1 
// Sample Input 1

// 10
// 2 5 6 7 2 1 3 10 3 6 
// Sample Output 1

// 2 2 3 3 6 6 1 5 7 10 
// 2 2 6 6 3 3 5 7 1 10 

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> freq;
    map<int, int> f;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        if (f.count(a[i]) == 0) {
            f[a[i]] = i;
        }
    }

    vector<int> b = a;
    sort(b.begin(), b.end(), [&](int x, int y) {
        if (freq[x] != freq[y]) return freq[x] > freq[y];
        else return x < y;
    });
    for (int x : b) cout << x << " ";
    cout << endl;

    vector<int> c = a;
    sort(c.begin(), c.end(), [&](int x, int y) {
        if (freq[x] != freq[y]) return freq[x] > freq[y];
        else return f[x] < f[y];
    });
    for (int x : c) cout << x << " ";
    cout << endl;

    return 0;
}
