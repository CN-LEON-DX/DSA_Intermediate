




// Code chua toi uu nhat
// De toi uu nhat ta co the dung phuong phap quay lui voi can la so luong thanh pho
// - Buoc 1: Dung mang visited[] de danh dau cac thanh pho da di qua
// - Buoc 2: Dung mang X[] de luu cac thanh pho da di qua
// - Buoc 3: Dung bien sum de luu tong quang duong da di qua
// - Buoc 4: Dung bien res de luu quang duong ngan nhat
// - Buoc 5: Goi ham Try(i) de tim quang duong ngan nhat
// - Buoc 6: Neu i == n thi chung to da di qua tat ca cac thanh pho, ta can kiem tra xem quang duong da di qua co nho hon res hay khong. Neu nho hon thi cap nhat res
// - Buoc 7: Neu i != n thi ta se di qua cac thanh pho tiep theo
// - Buoc 8: Duyet cac thanh pho tiep theo
// - Buoc 9: Neu thanh pho tiep theo chua di qua thi ta se di qua thanh pho do
// - Buoc 10: Cap nhat visited[] va X[]
// - Buoc 11: Goi de quy de di qua cac thanh pho tiep theo
// - Buoc 12: Sau khi di qua cac thanh pho tiep theo ta can phai tra lai gia tri ban dau cho visited[] va X[]
// - Buoc 13: Tra lai gia tri ban dau cho sum
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int c[100][100], visited[100];
int sum = 0, X[100];
int res = 1e9;
void Try(int i){
    for (int j = 1;j<=n;j++){
        if (visited[j] == 0){
            visited[j] = 1; 
            X[i] = j;
            sum += c[X[i-1]][X[i]];
            if (i==n){
                res = min(res, sum + c[X[n]][1]);
            }else Try(i+1);
            visited[j] = 0;
            sum-= c[X[i-1]][X[i]];
        }   
    }
}
int main(){
    cin >> n;
    for (int i = 1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> c[i][j];
        }
    }
    X[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << res;
    return 0;
}

// CACH TOI UU 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int c[100][100], visited[100];
int mindis = 1e9;
int sum = 0, X[100];
int res = 1e9;
void Try(int i){
    for (int j = 1;j<=n;j++){
        if (visited[j] == 0){
            visited[j] = 1; 
            X[i] = j;
            sum += c[X[i-1]][X[i]];
            if (i==n){
                res = min(res, sum + c[X[n]][1]);
            }else if ((sum+mindis*(n-i+1)) < res) Try(i+1);
            visited[j] = 0;
            sum-= c[X[i-1]][X[i]];
        }   
    }
}
int main(){
    cin >> n;
    for (int i = 1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> c[i][j];
            if (c[i][j]!=0) mindis=min(mindis, c[i][j]);
        }
    }
    X[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << res;
    return 0;
}