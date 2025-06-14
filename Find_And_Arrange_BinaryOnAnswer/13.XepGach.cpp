// Nam có n viên gạch được đánh số từ 1 đến n. Các viên gạch có độ cứng lần lượt là a1, a2,..., an. Một viên gạch có độ cứng x nghĩa là Nam có thể chồng lên trên viên gạch đó tối đa x viên gạch khác, nếu chồng nhiều hơn thì viên gạch đó bị vỡ. Hỏi Nam có thể sắp được chồng gạch cao nhất là bao nhiêu?

// Input Format

// Dòng đầu tiên là số nguyên n - là số viên gạch.
// Dòng tiếp theo gồm n số nguyên a1, a2,..., an mỗi số cách nhau một khoảng trắng.
// Constraints

// 1<=n<=10^5; 0≤ai≤ 10^6

// Output Format

// Số nguyên xác định chiều cao cao nhất của chồng gạch mà Nam sắp được.

// Sample Input 0

// 4
// 1 2 3 4
// Sample Output 0

// 4
#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <map>
using namespace std;


int main() {
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a + n);
    int ok = a[n-1], cnt = 1;
    for (int i = n-2;i>=0;i--){
        if (ok==0) break;
        ok--;
        cnt++;
        ok = min(ok, a[i]);
    }
    cout << cnt;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}