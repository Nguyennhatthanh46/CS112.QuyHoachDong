/*
TRUY VẤN TỔNG
 

Cho một mảng 𝐴 chứa 𝑛 phần tử và 𝑞 cặp số 𝑎, 𝑏. Tính tổng các giá trị của mảng 𝐴 có thứ tự nằm trong khoảng [𝑎, 𝑏]. 
Thứ tự bắt đầu đếm từ 1, A[0] là phần tử thứ 1.

Input:
Dòng đầu tiên chứa hai số nguyên 𝑛 và 𝑞 (1 ≤ 𝑛, 𝑞 ≤ 2.105).

Dòng thứ hai chứa 𝑛 số nguyên là các phần tử trong mảng (1 ≤ 𝑥i ≤ 109 , 𝑖 ∈ [1 … 𝑛]).

Cuối cùng, có 𝑞 dòng, mỗi dòng có hai số nguyên 𝑎 và 𝑏 (1 ≤ 𝑎 ≤ 𝑏 ≤ 𝑛).

Output
Kết quả tính tổng của mỗi truy vấn trong mỗi dòng 𝑞.

Example:
Input
8 4 
3 2 4 5 1 1 5 3 
2 4 
5 6 
1 8 
3 3

Output
11 
2 
24 
4
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);                      

    int n, q;
    cin >> n >> q;

    vector<long long> A(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> A[i];

    vector<long long> Luu(n + 1, 0);
    for(int i = 1; i <= n; i++)
        Luu[i] = Luu[i-1] + A[i];

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << Luu[b] - Luu[a-1] << "\n";  
    }
}
