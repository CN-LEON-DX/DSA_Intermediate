// Trong quan điểm người Việt, một số nguyên dương được gọi là “lộc phát” nếu chỉ có hai chữ số là 6 và/hoặc 8. Một số lộc phát X được gọi là đối xứng chẵn nếu: Số chữ số của X là chẵn X thỏa mãn tính chất đối xứng. Hãy liệt kê N số lộc phát đối xứng chẵn đầu tiên theo thứ tự từ nhỏ đến lớn.

// Input Format

// Dòng duy nhất chứa số nguyên dương N

// Constraints

// 1<=N<=1000.

// Output Format

// In ra các số thỏa mãn yêu cầu trên 1 dòng.

// Sample Input 0

// 57
// Sample Output 0

// 66 88 6666 6886 8668 8888 666666 668866 686686 688886 866668 868868 886688 888888 66666666 66688666 66866866 66888866 68666686 68688686 68866886 68888886 86666668 86688668 86866868 86888868 88666688 88688688 88866888 88888888 6666666666 6666886666 6668668666 6668888666 6686666866 6686886866 6688668866 6688888866 6866666686 6866886686 6868668686 6868888686 6886666886 6886886886 6888668886 6888888886 8666666668 8666886668 8668668668 8668888668 8686666868 8686886868 8688668868 8688888868 8866666688 8866886688 8868668688 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> vt;

void in(int n) {
    int sl = n / 2;
    for (int i = 0; i < (1<<sl); ++i) {
        string s = "";
        int num = i;
        for (int j = 0; j < sl; ++j) {
            if (num & (1<<j)) {
                s = "6" + s;
            } else {
                s = "8" + s;
            }
        }
        string s1(s.rbegin(), s.rend());
        vt.push_back((s+s1));
    }
}
bool cmp(string a, string b){
    if (a.size() != b.size()) return a.size() < b.size();
    else return a < b;
}
int main() {
    int n;
    cin >> n;
    for (int len = 2; len <= 30; len += 2) {
        in(len);
    }
    sort(vt.begin(), vt.end(), cmp);
    if (n > vt.size()) n = vt.size();
    for (int i = 0; i < n; i++) cout << vt[i] << " ";
    return 0;
}