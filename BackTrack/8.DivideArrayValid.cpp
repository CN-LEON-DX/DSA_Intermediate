// Cho mảng các số nguyên A[] gồm N phần tử. Hãy chia mảng số nguyên A[] thành K tập con khác rỗng sao cho tổng các phần tử của mỗi tập con đều bằng nhau. Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong tất cả các tập con. Ví dụ với A[] = {2, 1, 4, 5, 6}, K =3 ta có kết quả {2, 4}, {1, 5}, {6}.

// Input Format

// Dòng thứ nhất là hai số N và K; Dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.

// Constraints

// 1≤N, K≤20; 0≤A[i]≤100.

// Output Format

// Đưa ra 1 nếu có thể chia tập con thành K tập thỏa mãn yêu cầu bài toán, ngược lại đưa ra 0

// Sample Input 0

// 6 4
// 82 43 38 38 18 61 
// Sample Output 0

// 0
// Bai nay nen su dung phuong phap quay lui de giai quyet
// Cac buoc giai quyet bai toan nay nhu sau:
// - Buoc 1: Tinh tong cac phan tu trong mang A[] va kiem tra xem tong co chia het cho K hay khong. Neu khong thi khong the chia duoc
// - Buoc 2: Sap xep mang A[] theo thu tu giam dan
// - Buoc 3: Tinh tong cac phan tu trong mang A[] chia cho K, goi la sum. Khoi tao mang B[] gom K phan tu voi gia tri ban dau la sum
// - Buoc 4: Goi ham Try(i) de chia cac phan tu trong mang A[] vao K tap con sao cho tong cac phan tu trong moi tap con bang sum
// - Buoc 5: Neu co the chia duoc thi in ra 1, nguoc lai in ra 0
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[20];
int B[20];

bool Try(int i) {
    // Neu i == N thi chung to la da chia het cac phan tu trong mang A[] vao K tap con
    if(i == N) return true;
    // Duyet cac tap con
    for(int j = 0; j < K; j++) {
        if(B[j] >= A[i]) {
            B[j] -= A[i];
            // Goi de quy de chia cac phan tu con lai trong mang A[] vao cac tap con
            if(Try(i+1)) return true;
            B[j] += A[i];
        }
    }
    return false;
}

int main() {
    cin >> N >> K;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    if(sum % K != 0) {
        cout << 0 << endl;
        return 0;
    }
    // Chung ta can phai sort mang A vi neu khong sort thi se khong the chia duoc
    sort(A, A+N, greater<int>());
    for(int i = 0; i < K; i++) {
        B[i] = sum / K;
    }
    if(Try(0)) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}