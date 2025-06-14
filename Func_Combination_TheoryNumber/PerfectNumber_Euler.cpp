// Số hoàn hảo là số có tổng các ước thực sự (Không tính chính nó) bằng chính số đó. Cho một số nguyên dương n, kiểm tra xem n có phải là số hoàn hảo hay không.

// Định lý Euclid - Euler :' Nếu p là số nguyên tố và 2^p - 1 cũng là số nguyên tố thì : 2^(p-1) * (2^p - 1) sẽ tạo thành 1 số hoàn hảo.
//  Ví dụ p = 2, 2^2 - 1 = 3, 2 * 3 = 6 => HH Ví dụ p = 3, 2^3 - 1 = 7, 4 * 7 = 28 => HH

// Input Format

// Số nguyên dương N

// Constraints

// 1≤N≤9*10^18

// Output Format

// In YES nếu N là số hoàn hảo, ngược lại in NO

// Sample Input 0

// 28
// Sample Output 0

// YES
// Explanation 0

// 28 có các ước thực sự là 1, 2, 4, 7, 14 có tổng bằng 28.

// EUCLID - EULER
// Để kiểm tra số hoàn hảo bạn có thể sử dụng code ở mục 1, tuy nhiên nó chỉ phù hợp khi số N bạn cần kiểm tra ≤ 10^12. Trong trường hợp cần kiểm tra số N lên tới 1018 thì code trên chạy rất lâu mới ra kết quả. 

// Bạn thử viết hàm kiểm tra số hoàn hảo như mục 1 với số long long và thử chạy với  N = 10^18 để kiểm tra.

// Phương pháp tối ưu hơn để kiểm tra số hoàn hảo đó là sử dụng định lý Euclid - Euler. Định lý này phát biểu như sau

// Nếu p là số nguyên tố và 2^p - 1 cũng là số nguyên tố thì : 2^(p-1)* (2^p - 1) sẽ là một số hoàn hảo.

// Ví dụ :
// p = 2 là số nguyên tố, và 2^2 - 1 cũng là số nguyên tố nên : 2^(2-1) * (2^2 - 1) = 6 là số hoàn hảo

// p = 3 là số nguyên tố, và 2^3 - 1 cũng là số nguyên tố nên : 23-1 * (23 - 1) = 4 * 7 = 28 là số hoàn hảo

// Vậy để kiểm tra được hết các số hoàn hảo từ 1 tới giới hạn lớn nhất của số long long (9.1018) thì bạn cần duyệt các số nguyên tố p lớn tới đâu ?

// Nhận thấy tích 2p-1 * (2p - 1) ~ 22p sẽ phải lên tới 9.1018 ~ 263 => 2p ~ 63 nên bạn chỉ cần duyệt p tới 32, 33 là đủ rồi.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

bool  check(ll n){
    if (n<2) return 0;
    for (int i = 2;i<=sqrt(n);i++){
        if (n%i==0) return 0;
    }
    return 1;
}
void solve(){
    ll n; cin >> n;
    for (int p = 1;p<=33;p++){
        if (check(p)){
            ll k = pow(2, p) - 1;
            if (check(k)){
                ll t = pow(2, p - 1);
                if (t * k == n) {
                    cout << "YES";
                    return;
                }
            }
        }
    }
    cout << "NO";
}
int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}