#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define INT 1000001
ll n, m;
int main() {
    n = 366;
    double a[n], b[n];
    double s1 = 0;
    double s2 = 0;
    for (int i = 1; i<n;i++) {
        cin >> a[i];
        s1 += a[i];
    }
    for (int j = 1; j<=n;j++){
        cin >> b[j];
        s2 += b[j];
    }
    if (s2==0 || s1==0 || s1 < s2){
        cout << "oo";
    }else
    cout << ceil(1.0000000*s1/s2);
    return 0;
}
Cuối năm rồi Trường và Giang cũng cần nhìn lại năm vừa qua xem đã làm được những gì, vì thế cả hai người đã tổng hợp lại những số lượng nhiệm vụ mà mỗi người thực hiện thành công mỗi ngày. Bây giờ Trường thắc mắc, trong năm 2023 vừa qua, tổng số nhiệm vụ Trường hoàn thành nhiều hơn tổng số nhiệm vụ Giang hoàn thành bao nhiêu lần(hãy in ra kết quả được làm tròn lên số nguyên gần nhất). Nếu câu trả lời không tồn tại, hãy in ra "oo".

Đầu vào
Dòng thứ nhất là 365 số nguyên a1, a2, …, a365 (0<=ai<=18) – số nhiệm vụ Trường hoàn thành ngày thứ i.
Dòng thứ hai là 365 số nguyên b1, b2, …, b365 (0<=bi<=18) – số nhiệm vụ Giang hoàn thành ngày thứ i.

Đầu ra
Tổng số nhiệm vụ Trường hoàn thành nhiều hơn tổng số nhiệm vụ Giang hoàn thành bao nhiêu lần bao nhiêu lần (hãy in ra kết quả được làm tròn lên số nguyên gần nhất). Nếu câu trả lời không tồn tại, hãy in ra oo.

Input:
Copy
18 18 18 18 18 18 17 12 8 3 3 18 0 12 4 15 13 14 15 18 3 2 13 15 9 9 7 6 9 18 6 15 1 14 12 13 15 12 17 11 13 18 1 11 15 14 11 2 17 15 16 16 6 7 18 16 13 17 0 14 15 1 13 7 18 9 10 4 18 3 11 18 11 4 12 14 0 4 5 9 12 8 11 4 5 9 16 6 7 8 5 1 13 4 4 11 10 7 18 9 14 7 5 12 7 1 4 5 18 1 18 15 13 6 14 11 4 12 10 5 6 10 18 3 6 14 11 15 8 6 13 14 8 13 8 12 13 3 3 6 4 10 8 9 7 2 18 11 5 11 18 10 1 17 5 0 15 12 10 8 0 12 17 6 5 3 17 13 13 12 9 8 9 12 10 10 10 18 9 6 13 5 12 5 9 2 6 13 14 15 5 7 10 15 8 6 2 15 5 17 11 18 4 3 10 10 2 5 13 17 1 1 2 14 1 16 15 15 12 15 2 17 1 10 16 5 0 12 5 15 12 16 18 16 18 9 5 9 14 14 13 3 12 9 5 12 8 12 16 18 3 7 17 13 11 12 15 12 16 17 16 6 11 7 4 8 4 6 6 18 1 13 9 11 17 9 8 0 18 17 18 16 12 10 11 16 13 10 17 7 8 9 6 3 8 7 17 16 1 0 14 17 16 13 12 16 18 18 9 14 15 2 8 11 12 16 1 1 7 6 17 3 9 9 18 2 1 0 2 7 5 9 4 12 17 5 1 14 1 5 9 9 17 13 17 15 12 13 16 7 4 15 13 16 3 16 17 1 2 1 2 1 16 12 15
4 2 3 2 11 12 0 15 10 3 14 12 15 16 0 0 6 0 17 2 0 12 9 6 10 2 0 0 0 0 0 6 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 1 2 3
Output:

Copy
19
Giải thích Trong input trên, tổng số nhiệm vụ Trường hoàn thành là 3650 nhiệm vụ, và Giang là 201 nhiệm vụ, ta có 3650/201=18,1592... làm tròn lên là 19

Trường đã ngồi đếm số lượng các số cung cấp bên trên rồi, đảm bảo ở đó có 365*2=730 số nguyên, và trong các input khác cũng đảm bảo sẽ có 730 số nguyên.