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
    ll n, k;
    cin >> n >> k;

    vll a(n);
    rep(n)
    {
        cin >> a[i];
    }

    vll rui(n + 1, 0);
    rep1(n)
    {
        rui[i] += a[i - 1] + rui[i - 1];
    }

    ll right = 1;
    ll ans = 0;
    for (ll left = 0; left < n; left++)
    {
        while (true)
        {
            if (right > n)
            {
                --right;
                ans += (right - left);
                break;
            }

            ll sum = rui[right] - rui[left];

            if (sum <= k)
            {
                ++right;
            }
            else
            {
                --right;
                ans += (right - left);
                break;
            }
        }
    }

    cout << ans << endl;
}
