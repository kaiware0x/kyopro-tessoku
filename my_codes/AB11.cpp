#include <bits/stdc++.h>

using namespace std;

#define rep(n) for (int i = 0; i < (n); ++i)
#define repp(i, n) for (int i = 0; i < (n); ++i)
#define rep1(n) for (int i = 1; i <= (n); ++i)
#define repp1(i, n) for (int i = 1; i <= (n); ++i)

using vi = vector<int>;
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

    vi a(n, 0);
    rep(n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int q;
    cin >> q;

    vi ans(q);
    rep(q)
    {
        int x;
        cin >> x;

        auto iter = lower_bound(a.begin(), a.end(), x);
        ans[i] = distance(a.begin(), iter);
    }

    for (auto &&aa : ans)
    {
        cout << aa << endl;
    }
}
