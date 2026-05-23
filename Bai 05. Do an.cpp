/*
ĐỒ ÁN
Có 𝑛 đồ án mà Phúc có thể tham gia. Với mỗi đồ án thì chúng ta biết được ngày bắt đầu và ngày kết thúc và lượng tín chỉ nhận được khi ta hoàn thành đồ án đó. 
Mỗi ngày, Phúc chỉ có thể thực hiện được duy nhất một đồ án thôi, nếu không thì sẽ bị deadlines dí mất >.< nên đừng có tham lam.

Là một người muốn ra trường càng sớm càng tốt ^^.Hãy giúp Phúc tính số lượng tín chỉ lớn nhất mà Phúc có thể nhận được.

Input

Dòng duy nhất chứa số nguyên dương 𝑛: số lượng các đồ án

Sau đó, 𝑛 dòng:  Mỗi dòng chứa 3 số nguyên dương 𝑎𝑖 , 𝑏𝑖 , 𝑝𝑖 : tương ứng với ngày bắt đầu, ngày kết thực và số lượng tín chỉ nhận được khi hoàn thành đồ án đó

Output

Dòng duy nhất chứa kết quả là số lượng tín chỉ lớn nhất Phúc đạt được

Constraints

1 ≤ 𝑛 ≤ 2 × 105

1 ≤ 𝑎𝑖 ≤ 𝑏𝑖 ≤ 109

1 ≤ 𝑝𝑖 ≤ 109 


Example

Input

4
2 4 4
3 6 6
6 8 2
5 7 3

Output 
7

Giải thích: Chọn đồ án thứ nhất và thứ 4
*/
#include <bits/stdc++.h>
using namespace std;

struct DoAn {
    long long a, b, p;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<DoAn> jobs(n);
    for(int i = 0; i < n; i++)
        cin >> jobs[i].a >> jobs[i].b >> jobs[i].p;

    sort(jobs.begin(), jobs.end(), [](DoAn x, DoAn y){
        return x.b < y.b;
    });

    vector<long long> dp(n + 1, 0);

    for(int i = 1; i <= n; i++){
        long long a = jobs[i-1].a;
        long long b = jobs[i-1].b;
        long long p = jobs[i-1].p;

        int l = 1, r = i - 1, j = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(jobs[mid-1].b < a){
                j = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        dp[i] = max(dp[i-1], dp[j] + p);
    }

    cout << dp[n];
    return 0;
}
