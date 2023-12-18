// Cho xâu kí tự S chỉ bao gồm các kí tự in thường, hãy kiểm tra xem có thể sắp đặt lại các kí tự trong xâu sao cho không có 2 kí tự kề nhau nào giống nhau hay không?

// Input Format

// Dòng duy nhất chứa xâu S

// Constraints

// 1<=len(S)<=10000;

// Output Format

// In ra chuoi sau khi sap xep
// In mot trong cac chuoi thoa man 
// Neu khong ton tai in ra -1

// Sample Input 0

// aqeaaqwq
// Sample Output 0
// aqaeaqwa
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct CharFrequency {
    char c;
    int freq;
    CharFrequency(char c, int freq) : c(c), freq(freq) {}
};

struct Compare {
    bool operator()(CharFrequency const& cf1, CharFrequency const& cf2) {
        return cf1.freq < cf2.freq;
    }
};

string rearrangeString(string s) {
    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }

    priority_queue<CharFrequency, vector<CharFrequency>, Compare> maxHeap;
    for (char c = 'a'; c <= 'z'; c++) {
        if (count[c - 'a'] > 0) {
            maxHeap.push(CharFrequency(c, count[c - 'a']));
        }
    }

    CharFrequency prev('#', -1);
    string result = "";

    while (!maxHeap.empty()) {
        CharFrequency curr = maxHeap.top();
        maxHeap.pop();
        result += curr.c;

        if (prev.freq > 0) {
            maxHeap.push(prev);
        }

        curr.freq--;
        prev = curr;
    }

    if (s.size() != result.size()) {
        return "-1";
    } else {
        return result;
    }
}

int main() {
    string s;
    cin >> s;
    cout << rearrangeString(s) << endl;
    return 0;
}