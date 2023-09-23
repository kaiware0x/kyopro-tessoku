#include <bits/stdc++.h>

using namespace std;

#define rep(n) for (int i = 0; i < (n); ++i)
#define repp(i, n) for (int i = 0; i < (n); ++i)
#define rep1(n) for (int i = 1; i <= (n); ++i)
#define repp1(i, n) for (int i = 1; i <= (n); ++i)

using vi = vector<int>;
using vvi = vector<vi>;

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
//     int h, w, n;
//     cin >> h >> w >> n;

//     vvi masu(h + 2, vi(w + 2, 0));

//     rep(n)
//     {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;

//         auto x1 = a;
//         auto y1 = b;
//         auto x2 = c;
//         auto y2 = d;

//         masu[y1][x1]++;
//         masu[y1][x2 + 1]--;
//         masu[y2 + 1][x1]--;
//         masu[y2 + 1][x2 + 1]++;
//     }

//     // x方向 累積和
//     for (int i = 1; i < h + 2; i++)
//     {
//         for (int j = 1; j < w + 2; j++)
//         {
//             masu[i][j] += masu[i][j - 1];
//         }
//     }

//     // y方向 累積和
//     for (int j = 1; j < w + 2; j++)
//     {
//         for (int i = 1; i < h + 2; i++)
//         {
//             masu[i][j] += masu[i - 1][j];
//         }
//     }

//     repp1(i, h)
//     {
//         repp1(j, w)
//         {
//             cout << masu[i][j];

//             if (j != w)
//             {
//                 cout << " ";
//             }
//         }
//         cout << endl;
//     }
// }

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    constexpr int MAX = 1501;
    vvi p(MAX, vi(MAX, 0));

    rep(n)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        auto x1 = a;
        auto y1 = b;
        auto x2 = c;
        auto y2 = d;

        p[y1][x1]++;
        p[y1][x2]--;
        p[y2][x1]--;
        p[y2][x2]++;
    }

    // x方向累積和
    repp(i, MAX)
    {
        repp(j, MAX)
        {
            if (j == 0)
                continue;

            p[i][j] += p[i][j - 1];
        }
    }

    // y方向累積和
    repp(j, MAX)
    {
        repp(i, MAX)
        {
            if (i == 0)
                continue;

            p[i][j] += p[i - 1][j];
        }
    }

    // 答えをカウント
    uint64_t ans = 0;
    repp(i, MAX)
    {
        repp(j, MAX)
        {
            if (p[i][j] > 0)
            {
                ans++;
            }
        }
    }

    // printvecvec(p);

    cout << ans << endl;
}
