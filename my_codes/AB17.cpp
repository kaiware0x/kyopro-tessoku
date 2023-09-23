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

        // dp[i-1]の時点から1ステップ移動するためのコスト
        auto cost1 = abs(h[i] - h[i1]) + dp[i1];
        if (i2 < 0)
        {
            dp[i] = cost1;
            continue;
        }

        // dp[i-2]の時点から2ステップ移動するためのコスト
        auto cost2 = abs(h[i] - h[i2]) + dp[i2];
        dp[i] = min(cost1, cost2);
    }

    vi route;
    route.emplace_back(n - 1); // ゴールには必ず到達しているはず

    for (int i = n - 1; i >= 1;)
    {
        // コストの計算
        ll cost1 = 1e9, cost2 = 1e9;
        if (i - 2 >= 0)
        {
            cost2 = abs(h[i] - h[i - 2]) + dp[i - 2];
        }
        if (i - 1 >= 0)
        {
            cost1 = abs(h[i] - h[i - 1]) + dp[i - 1];
        }

        // ステップを遡る
        if (cost1 < cost2)
        {
            route.emplace_back(i - 1);
            i -= 1;
        }
        else
        {
            route.emplace_back(i - 2);
            i -= 2;
        }
    }

    ranges::reverse(route);
    cout << route.size() << endl;
    for (int i = 0; i < route.size(); i++)
    {
        cout << route[i] + 1;
        if (i != route.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}
