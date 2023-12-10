// Kì thì cuối kì môn Triết ở trường đại học xyz sắp diễn ra. 
// Tèo và bạn bè có ý định sẽ photo phao thi để bán kiếm tiền,
// hiện tại Tèo và bạn của mình đã có bản gốc của phao thi. 
//Theo ước tính của tèo thì có n bạn sẽ mua phao thi của tèo. 
//Tèo không có ý định bán bản phao gốc của mình nên sẽ đi photo n bản nữa để bán,
// tới quán photo chỉ còn 2 máy photo có thể hoạt động. 
// Trong đó máy photo 1 cần x giây để photo xong phao thi cho Tèo, máy thứ 2 cần y giây. 
//Vì muốn nhanh chóng đem phao đi bán nên Tèo muốn nhờ bạn tính hộ là
// anh ấy cần ít nhất bao nhiêu giây để có thể photo ra n bản khác từ 1 bản gốc ban đầu.
// Chú ý các máy photo có thể photo từ bản gốc hoặc có thể photo từ bản đã sao đã được in từ bản gốc.
// 2 máy này có thể hoạt động một cách đồng thời.
// Input Format
// 1 dòng chứa ba số nguyên n, x và y;
// Constraints
// (1≤n≤2⋅10^8, 1≤x, y≤10).
// Output Format
// In ra thời gian tối thiểu mà Tèo cần.

// Sample Input 0

// 5 1 2
// Sample Output 0

// 4
// Explanation 0

// Tèo cần photo 5 bản, ban đầu Tèo dùng máy số 1 để photo ra ban sao đầu tiên. 
// Sau đó còn lại 3 giây, Tèo photo được 3 bản từ máy 1 và 1 bản từ máy 2. Vậy là đủ 5 bản.


// Ở ĐÂY CẦN ĐỂ Ý RẰNG BAN ĐẦU CHỈ CÓ 1 BẢN GỐC, SAU ĐÓ CÓ THỂ PHOTO TỪ BẢN GỐC HOẶC TỪ BẢN SAO
// DO VẬY TA CẦN CHỌN MỘT CÁI MÁY ĐẦU NHANH NHẤT ĐỂ IN BẢN ĐẦU TIÊN 
// SAU ĐÓ CẦN CHỌN MỘT CÁI MÁY CÒN LẠI ĐỂ IN BẢN SAO TIẾP THEO
// DO ĐÓ số lượng cần check là n-1 và giá trị mid cần check còn mid - min(x, y) là thời gian thực hiện cái đầu tiên
// Dùng pp chặt nhị phân để tìm ra thời gian tối thiểu cần thiết để in ra n bản sao
// Độ phức tạp O(log(N)) với N là thời gian tối đa cần thiết để in ra n bản sao
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

bool check(ll n, ll m, ll k, ll mid){
    
    return (mid/m + mid/k) >= n;
}
int main() {
    ll n, m, k; cin >> n >> m >> k;
    ll left = 1;
    ll right = 1e18;
    ll res = -1;
    while (left <= right){
        ll mid = (left+right)/2;
        if (check(n-1, m, k, mid-min(m, k))){
            res = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    cout << res;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}