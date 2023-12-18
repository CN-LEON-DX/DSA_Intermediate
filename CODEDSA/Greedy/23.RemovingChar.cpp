// Tí vào Tèo cùng chơi một trò chơi với xâu nhị phân S. Xâu nhị phân S chỉ bao gồm các kí tự 0 và 1. Ở mỗi bước đi, 2 bạn nhỏ có thể chọn 1 xâu con liên tiếp các kí tự giống nhau ở xâu S và xóa nó khỏi xâu S. Sau khi xóa 1 xâu thì 2 xâu bên trái và phải của xâu vừa xóa sẽ trở thành liền kề. Ban đầu Tí là người đi trước, sau đó 2 bạn lần lượt thực hiện bước đi của mình cho tới khi xâu S trở thành xâu rỗng. Bạn hãy xác định xem Tí có thể xóa tối đa bao nhiêu kí tự 1 biết rằng cả 2 bạn đều chơi tối ưu

// Input Format

// Dòng duy nhất chứa xâu S

// Constraints

// 1<=len(S)<=100000;

// Output Format

// In ra số lượng số 1 tối đa mà Tí có thể xóa được

// Sample Input 0

// 1000101110011111
// Sample Output 0

// 6
// Buoc lam 
// Cac buoc giai 
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    vector<int> vt;
    int cnt = 0;
    for (char c : S) {
        if (c == '1') {
            cnt++;
        } else if (cnt > 0) {
            vt.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt > 0) {
        vt.push_back(cnt);
    }
    sort(vt.begin(), vt.end(), greater<int>());
    int maxCount = 0;
    for (int i = 0; i < vt.size(); i += 2) {
        maxCount += vt[i];
    }
    cout << maxCount;
    return 0;
}