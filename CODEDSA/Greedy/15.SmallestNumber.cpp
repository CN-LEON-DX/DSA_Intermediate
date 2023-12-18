// .Cho hai số nguyên dương S và D, trong đó S là tổng các chữ số và D là số các chữ số của một số. Nhiệm vụ của bạn là tìm số nhỏ nhất thỏa mãn S và D?

// Input Format

// 1 dòng gồm 2 số S, D

// Constraints

// 1<=S,D<=1000;

// Output Format

// In ra số nhỏ nhất có D chữ số và có tổng bằng S, nếu không tìm được đáp án thì in ra -1

// Sample Input 0

// 12 8
// Sample Output 0

// 10000029
// Cac buoc giai 
// 1. Tim so co D chu so nho nhat
// 2. Tim so co tong cac chu so bang S
// 3. Neu khong tim duoc thi in ra -1
#include <bits/stdc++.h>
using namespace std;
int main(){
    int s, d; cin >> s >> d;
    if (s > d * 9) {
        cout << -1;
        return 0;
    }
    vector<int> vt(d, 0);
    vt[0] = 1;
    s--;
    for (int i = d - 1;i>=0 && s > 0;i--){
        int add = min(9, s);
        vt[i]+= add;
        s -= add;
    }
    if (s>0){
        cout << -1;
    }else {
        for (int i = 0;i<vt.size();i++){
            cout << vt[i];
        }
    }
    return 0;
}