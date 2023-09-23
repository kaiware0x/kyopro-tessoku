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
    int n, s;
    cin >> n >> s;

    vi a(n, 0);
    rep(n)
    {
        cin >> a[i];
    }

    vvi dp(n + 1, vi(s + 1, 0));
    dp[0][0] = 1;

    repp(item, n + 1)
    {
        if (item == n)
            break;

        repp(score, s + 1)
        {
            auto can_reach = dp[item][score];

            if (can_reach == 0)
            {
                continue;
            }

            /// item+1番目を選択しない場合、直下に到達可能。
            dp[item + 1][score] = 1;

            auto score_next = score + a[item];

            // 次のスコアが取り得る最大スコアを超えてしまっているので、その場所には到達不可。
            if (score_next > s)
            {
                continue;
            }

            dp[item + 1][score_next] = 1;
        }
    }

    // printvecvec(dp);

    if (dp[n][s] == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    vi route;

    int score = s;

    for (int item = n; item >= 1; item--)
    {
        // 真上が1だった場合、自身itemは選択されなくても答えに到達できていたことになる。
        if (dp[item - 1][score] == 1)
        {
            continue;
        }
        // 真上が1でなかった場合、自身itemは必ず選択されていたはず。
        else
        {
            route.emplace_back(item);
            score -= a[item - 1];
        }
    }

    ranges::reverse(route);
    cout << route.size() << endl;
    for (int i = 0; i < route.size(); i++)
    {
        cout << route[i];
        if (i != route.size() - 1)
        {
            cout << " ";
        }
    }

    cout << endl;
}
