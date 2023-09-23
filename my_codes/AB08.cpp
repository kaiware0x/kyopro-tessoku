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

// int main()
// {
//     int h, w;
//     cin >> h >> w;

//     vvi rui(h + 2, vi(w + 2, 0));
//     repp1(i, h)
//     {
//         repp1(j, w)
//         {
//             cin >> rui[i][j];
//         }
//     }

//     // x方向 累積和
//     repp1(i, h)
//     {
//         repp1(j, w)
//         {
//             rui[i][j] += rui[i][j - 1];
//         }
//     }

//     // y方向 累積和
//     repp1(j, w)
//     {
//         repp1(i, h)
//         {
//             rui[i][j] += rui[i - 1][j];
//         }
//     }

//     int q;
//     cin >> q;

//     vi ans(q, 0);
//     rep(q)
//     {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;

//         int y1 = a;
//         int x1 = b;
//         int y2 = c;
//         int x2 = d;

//         auto z22 = rui[y2][x2];
//         auto z12 = rui[y2][x1 - 1];
//         auto z21 = rui[y1 - 1][x2];
//         auto z11 = rui[y1 - 1][x1 - 1];
//         ans[i] = z22 - z12 - z21 + z11;
//     }
//     printvec(ans);
// }

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    constexpr int MAX = 1510;
    vvi p(MAX, vi(MAX, 0));

    rep(n)
    {
        int x, y;
        cin >> x >> y;

        p[y][x]++;
    }

    // x方向 累積和
    repp1(i, 1501)
    {
        repp1(j, 1501)
        {
            p[i][j] += p[i][j - 1];
        }
    }
    // y方向 累積和
    repp1(j, 1501)
    {
        repp1(i, 1501)
        {
            p[i][j] += p[i - 1][j];
        }
    }

    int q;
    cin >> q;

    vi ans(q, 0);
    rep(q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        auto x1 = a;
        auto x2 = c;
        auto y1 = b;
        auto y2 = d;

        auto z22 = p[y2][x2];
        auto z21 = p[y1 - 1][x2];
        auto z12 = p[y2][x1 - 1];
        auto z11 = p[y1 - 1][x1 - 1];

        ans[i] = z22 - z21 - z12 + z11;
    }

    printvec(ans);
}
