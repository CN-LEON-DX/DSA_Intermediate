// [Two Pointer]. Bài 2. 28Tech_Smaller
// Problem
// Submissions
// Discussions
// Cho 2 mảng A[] và B[] có N và M phần tử đã được sắp xếp theo thứ tự tăng dần, nhiệm vụ của bạn là đối với mỗi phần tử trong mảng B[] hãy đếm xem trong mảng A[] có bao nhiêu phần tử nhỏ hơn nó.

// Input Format

// Dòng đầu tiên là N và M

// Dòng 2 là N số trong mảng A[]

// Dòng 3 là M số trong mảng B[]

// Constraints

// 1<=N,M<=10^7

// 1<=A[i],B[i]<= 10^9

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 6 7
// 2 3 6 6 6 8 
// 5 5 5 6 6 7 10 
// Sample Output 0

// 2 2 2 2 2 5 6 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binary_search1(int a[], int l, int r, int x){
    int result = -1;
    while (l <= r){
        int mid = (l+r)/2;
        if (a[mid]< x){
            result = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return result;
}
int main() {
    int n, m; cin >> n >> m;
    int a[n+1], b[m+1];
    for (int i = 0;i<n;i++) cin >> a[i];
    for (int i = 0;i<m;i++) cin >> b[i];
    for (int i = 0;i<m;i++){
        int result = binary_search1(a, 0, n-1, b[i]);
        if (result == -1) cout << 0 <<" ";
        else cout << result+1 << " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}