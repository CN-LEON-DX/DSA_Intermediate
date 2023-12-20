// Cho mảng A[] có N phần tử, bạn hãy cài đặt thuật toán Quick sort - Sắp xếp nhanh để sắp dãy số tăng dần sau đó in ra màn hình. Sử dụng phân hoạch Hoare

// Input Format

// Dòng 1 là N : Số phần tử trong mảng

// Dòng 2 gồm N phần tử trong mảng A[]

// Constraints

// 1<=N<=10^6

// 0<=A[i]<=10^9

// Output Format

// In ra dãy số sau khi sắp xếp

// Sample Input 0
// 10
// 413 348 77 923 538 154 462 450 71 733 
// Sample Output 0
// 71 77 154 348 413 450 462 538 733 923 
#include <iostream>
#include <vector>
using namespace std;

int hoarePartition(vector<int>& A, int low, int high) {
    int pivot = A[low];
    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (A[i] < pivot);
        do {
            j--;
        } while (A[j] > pivot);
        if (i >= j) return j;
        swap(A[i], A[j]);
    }
}

void quickSort(vector<int>& A, int low, int high) {
    if (low < high) {
        int pi = hoarePartition(A, low, high);
        quickSort(A, low, pi);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    quickSort(A, 0, N - 1);
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    return 0;
}