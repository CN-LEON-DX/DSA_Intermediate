// Cho một xâu kí tự S chỉ bao gồm các kí tự '(' hoặc kí tự ')'. S có độ dài là số chẵn có giá trị N. Xâu S gồm N / 2 kí tự mở ngoặc và N / 2 kí tự đóng ngoặc. Ở mỗi thao tác các bạn được lựa chọn 1 kí tự bất kì của S để đưa về vị trí đầu tiên hoặc vị trí cuối cùng của dãy. Các bạn hãy xác định số thao tác tối thiểu cần thực hiện để tạo được 1 xâu dấu ngoặc hợp lệ. Một số ví dụ về xâu hợp lệ : (), (((()))), ()((()))...

// Input Format

// Một dòng duy nhất chứa xâu S

// Constraints

// 1<=N<=1000;

// Output Format

// In ra số thao tác tối thiểu cần thực hiện

// Sample Input 0

// )))((((())
// Sample Output 0

// 3
// Cach lam la:
// 1. Duyet tu dau den cuoi xau, neu gap dau '(' thi tang bien dem len 1, neu gap dau ')' thi giam bien dem xuong 1
// 2. Neu bien dem < 0 thi tang bien dem len 1 va tang so lan doi vi tri len 1
// 3. In ra so lan doi vi tri
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s; cin >> s;
    int cnt = 0;
    int res = 0;
    for (char x: s){
        if (x=='(') cnt++;
        else cnt--;
        if (cnt < 0) {
            cnt++;
            res++;
        }
    }
    cout << res;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
