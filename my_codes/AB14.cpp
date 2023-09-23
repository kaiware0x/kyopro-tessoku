#include <bits/stdc++.h>

using namespace std;

#define rep(n) for (int i = 0; i < (n); ++i)
#define repp(i, n) for (int i = 0; i < (n); ++i)
#define rep1(n) for (int i = 1; i <= (n); ++i)
#define repp1(i, n) for (int i = 1; i <= (n); ++i)

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
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

vll enumrate(const vll &half)
{
    vll sum_vec;
    // i: ビット列としてすべての選択パターンを列挙する。
    for (ll i = 0; i < (1 << half.size()); i++)
    {
        ll sum = 0;
        // j: ビット列iのうち、j番目が選択されているか？を調べる。
        for (ll j = 0; j < half.size(); j++)
        {
            auto bitflag = (1 << j);

            // iのうち、j番目のビットフラグが立っているなら...
            if ((i / bitflag) % 2 == 1)
            {
                sum += half[j]; // j番目の数が選択されているとして加算
            }
        }

        sum_vec.emplace_back(sum);
    }
    return sum_vec;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vi a(n, 0);
    rep(n)
    {
        cin >> a[i];
    }

    vll half_first, half_last;

    for (int i = 0; i < a.size() / 2; i++)
    {
        half_first.emplace_back(a[i]);
    }
    for (int i = a.size() / 2; i < a.size(); i++)
    {
        half_last.emplace_back(a[i]);
    }

    // 前半部分、後半部分それぞれにおいて加算組み合わせを取得
    auto sum_vec_first = enumrate(half_first);
    auto sum_vec_last = enumrate(half_last);

    // lower_boundのためsortしておく。
    ranges::sort(sum_vec_first);
    ranges::sort(sum_vec_last);

    for (ll i = 0; i < sum_vec_first.size(); i++)
    {
        // Kから引いた残り分がlast部分から見つかるか？
        auto remain = k - sum_vec_first[i];
        auto iter = ranges::lower_bound(sum_vec_last, remain);

        if (iter == sum_vec_last.end())
        {
            continue;
        }

        ll pos = iter - sum_vec_last.begin();
        if (sum_vec_last[pos] == remain)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
