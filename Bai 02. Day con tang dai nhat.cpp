/*
DÃY CON TĂNG DÀI NHẤT
Cho dãy 𝑎 gồm 𝑛 phần tử. Nhiệm vụ của chúng ta là đi tìm độ dài dãy con tăng (𝑎i < 𝑎j , 𝑖 < 𝑗) dài nhất.
Input:
Dòng duy nhất chứa số nguyên dương 𝑛 (1 ≤ 𝑛 ≤ 2.105)
Sau đó, 𝑛 số nguyên 𝑎1 , 𝑎2 , . . , 𝑎n là các phần tử của dãy (1 ≤ 𝑎i ≤ 109 , 𝑖 ∈ [1 … 𝑛])

Output
Dòng duy nhất chứa kết quả là độ dài của dãy con tăng dài nhất.

Example:
Input
8
7 3 5 3 6 2 9 8
Output
4
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tails; 

    for(int i = 0; i < n; i++){
        auto it = lower_bound(tails.begin(), tails.end(), a[i]);
        if(it == tails.end()){
            tails.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }

    cout << tails.size();

    return 0;
}
