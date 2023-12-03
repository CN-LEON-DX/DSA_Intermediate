#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        mp[a[i]]++;

        if (mp[a[i]] > 1 && a[i] * 2 == k) {
            cout << "YES";
            return;
        }

        if (mp[k - a[i]] && a[i] * 2 != k) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}

int main() {
    solve();
    return 0;
}
// TWO SUM bạn có thể dùng 2 con trỏ để duyệt như:
// Sắp xếp dãy tăng dần đã (nlogn)
// rồi cho: con trỏ left = 0, right = n
// nếu a[left] + a[right] > k thì right--
// nếu a[left] + a[right] < k thì left++
// nếu a[left] + a[right] == k thì in ra YES và return


// Cho mảng A[] gồm N phần tử và số nguyên K, hãy kiểm tra xem trong mảng có 2 phần tử A[i], A[j] với i khác j và A[i] + A[j] = K hay không ? Bài này các bạn có thể giải theo 3 cách : Binary search, Hai con trỏ, Map.

// Input Format

// Dòng đầu tiên là N và K

// Dòng thứ 2 là N số trong mảng A[]

// Constraints

// 1<=N<=5000

// 1<=A[i],K<=10^9

// Output Format

// In ra YES nếu tồn tại, ngược lại in ra NO

// Sample Input 0

// 5 28
// 2 1 10 5 9 
// Sample Output 0

// NO
// Sample Input 1

// 7 12
// 8 3 8 5 5 9 8 
// Sample Output 1

// YES