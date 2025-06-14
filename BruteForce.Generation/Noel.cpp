Ông già Noel quyết định vá lại hàng rào vườn nhà mình để chống tuần lộc vào ăn cà rốt. Hàng
rào nhà ông già Noel gồm N đoạn rào, mỗi đoạn là một tấm ván có chiều cao Ai
. Ông già Noel có
một chiếc xe cút kít, trên xe có sẵn một chồng ván, mỗi tấm ván có độ dài là Bi
. Ông già Noel đi
dọc theo hàng rào, đẩy theo xe cút kít. Nếu như ông muốn tăng chiều cao của đoạn rào nào đó,
thì ông chỉ cần đơn giản là lấy tấm ván ở trên xe và gắn lên trên đoạn rào. Khi đó, chiều cao mới
của đoạn rào sẽ bằng chiều cao cũ cộng với chiều dài của đoạn ván mới gắn vào. Vì muốn hàng
nào được bền vững, ông già Noel không muốn gắn quá một tấm ván vào một đoạn rào. Để tăng
chiều cao của đoạn rào, ông già Noel làm như thế này: Với mỗi đoạn rào, hoặc ông lấy tấm ván
trên cùng của chồng ván trên xe cút kít và gắn lên hàng rào, hoặc vứt đi một vài tấm trên cùng
và lấy tấm tiếp theo để gắn lên đoạn rào. Ông già Noel hiện đã già và không còn khỏe, vì vậy ông
không đi quay ngược lại và không nhặt lại những tấm ván đã vứt đi. Trước khi vá hàng rào, ông
già Noel đã thầm nghĩ đến chiều cao lớn nhất mà hàng rào có thể đạt được. Chiều cao hàng rào
được định nghĩa là chiều cao của đoạn rào thấp nhất.
Hãy giúp ông già Noel xác định chiều cao lớn nhất có thể của hàng rào.
Dữ liệu
• Dòng đầu tiên chứa một số nguyên dương N - số đoạn rào nhà ông già Noel (N ≤ 105
).
• Dòng thứ hai chứa N số nguyên dương A1, A2, ..., AN - chiều cao của các đoạn rào, liệt kê
theo đúng thứ tự mà ông già Noel sẽ đi để vá (Ai ≤ 108
).
• Dòng thứ ba chứa một số nguyên dương M - số lượng tấm ván trên xe cút kít (M ≤ 105
).
• Dòng thứ tư chứa các số nguyên dương B1, B2, ..., BM - độ dài các tấm ván trên xe cút kít,
bắt đầu từ tấm trên cùng (Bi ≤ 108
).
Kết quả
• Một số nguyên duy nhất là chiều cao lớn nhất của hàng rào sau khi vá.
Sample Input 
6
2 5 4 1 7 5
7
2 3 1 3 2 4 6
Sample Output
5
Giải thích
• Tấm ván thứ 2 dùng để vá đoạn rào thứ nhất,
• Tấm ván thứ 3 dùng để vá đoạn rào thứ 3,
• Tấm ván thứ 6 dùng để vá đoạn rào thứ 4.

    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    #define INT 1000001
    int n, m;
    int a[INT];
    vector<int> vt;
    int find(int vtri, int n){
        for (int i = vtri;i<m;i++){
            if (n>=vt[i]){
                return i;
            }
        }
        return -1;
    }

    bool check(int mid){
        int vtri = 0;
        for (int i = 1;i<=n;i++){
            if (mid>a[i]){
                int kq = find(vtri, mid-a[i]);
                if (kq==-1){
                    return 0;
                }else{
                    vtri = kq+1; 
                }
            }
        }
        return 1;
    }
    int main(){
        cin >> n;
        for (int i = 1;i<=n;i++){
            cin >> a[i];
        }
        cin >> m;
        for (int i = 0;i<m;i++){
            int k; cin >> k;
            vt.push_back(k);
        }
        ll l = 1, r = 1e9;
        ll res = 1;
        while (l <= r){
            ll mid = (l+r)/2;
            if (check(mid)){
                res = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
            cout << "Mid:" << mid << " res" << res << endl;
        }
        cout << res;
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
        return 0;
    }

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define INT 1000001
int t = 0;
int n, m;
int a[INT];
vector<int> vt;

int find(int vtri, ll mid) {
    for (int i = vtri; i < vt.size(); i++) {
        if (mid <= vt[i]) {
            return i;
        }
    }
    return -1;
}

bool check(ll mid) {
    t++;
    cout << "Lan " << t  << "mid:" << mid << endl;
    int vtri = 0;
    for (int i = 1; i <= n; i++) {
        if (mid > a[i]) {
            cout << "Mid - a[i]" << mid-a[i] << endl;
            int kq = find(vtri, mid - a[i]);
            cout << "Tim thay tai:"<< kq << " co " << vt[kq] << endl;
            if (kq == -1) {
                return false;
            } else {
                vtri = kq + 1;
            }
        }
        cout << "vtri:" << vtri << endl;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vt.push_back(k);
    }
    ll l = 1, r = 20;
    ll res = 1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res;
    return 0;
}
