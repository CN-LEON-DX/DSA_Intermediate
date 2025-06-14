#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
// CODE WILL TIME LIMIT WITH N = 10^18 but N = 10^12 is ok
int main() {
    ll n; cin >> n;
    ll cnt = 1;
    for (ll i = 2;i*i<=n;i++){
        if (n%i==0){
            cnt++;
            if (i*i != n){
                cnt++;
            }
        }
    }
    if (n>1) cnt++;
    if (cnt%2==1) cout << "YES";
    else cout << "NO";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
// Kiểm tra xem một số có số lượng ước số của nó là số lẻ

// Input Format

// Số nguyên dương N

// Constraints

// 1≤N≤10^18

// Output Format

// In ra YES nếu N là số có số ước là số lẻ, ngược lại in NO.

// Sample Input 0

// 100
// Sample Output 0

// YES
// Explanation 0

// Số 100 có các ước 1, 2, 4, 5, 10, 20, 25, 50, 100. Vậy 100 có 9 ước là số lẻ, nên đáp án là YES.
// OPTIMIZE CODE: 
// We know that the square number will have odd number of divisors.
// Like : 100 = 2^2 * 5^2
// Like : 256 = 2^8
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
int main() {
    ll n; cin >> n;
    ll k = sqrt(n);
    if (k*k==n) cout << "YES";
    else cout << "NO";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}