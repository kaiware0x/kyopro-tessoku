#include <bits/stdc++.h>

using namespace std;

#define rep(n) for (int i = 0; i < (n); ++i)
#define repp(i, n) for (int i = 0; i < (n); ++i)
#define rep1(n) for (int i = 1; i <= (n); ++i)
#define repp1(i, n) for (int i = 1; i <= (n); ++i)

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;

template <class T>
void printvec(const vector<T> &vec)
{
    for (auto &&v : vec)
        cout << v << endl;
}
template <class T>
void printvecvec(const vector<vector<T>> &vecvec)
{
    for (auto &&vec : vecvec)
    {
        for (auto &&v : vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}



int main()
{
    int n;
    cin >> n;

    vi h(n, 0);
    rep(n)
    {
        cin >> h[i];
    }

    vi dp(n, std::numeric_limits<int>::max());

    rep(n)
    {
        auto i1 = i - 1;
        auto i2 = i - 2;

        if (i1 < 0)
        {
            dp[i] = 0;
            continue;
        }

        // dp[i1]の時点から1ステップ移動するためのコスト
        auto cost1 = abs(h[i] - h[i1]) + dp[i1];
        if (i2 < 0)
        {
            dp[i] = cost1;
            continue;
        }

        // dp[i2]の時点から2ステップ移動するためのコスト
        auto cost2 = abs(h[i] - h[i2]) + dp[i2];
        dp[i] = min(cost1, cost2);
    }

    cout << dp[n - 1] << endl;
}
