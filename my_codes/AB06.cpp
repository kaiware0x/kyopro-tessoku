
#include <bits/stdc++.h>

using namespace std;

#define rep(n) for (int i = 1; i <= (n); ++i)

using vi = vector<int>;

// int main(int argc, char const *argv[])
// {
//     int n, q;
//     cin >> n >> q;

//     vi a(n), rui(n);

//     rep(n)
//     {
//         cin >> a[i];

//         if (i >= 1)
//         {
//             rui[i] = a[i] + rui[i - 1];
//         }
//         else
//         {
//             rui[i] = a[i];
//         }
//     }

//     vi ans;

//     rep(q)
//     {
//         int l, r;
//         cin >> l >> r;

//         ans.emplace_back(rui[r - 1] - rui[l - 2]);
//     }

//     for(auto&& aa : ans){
//         cout << aa << endl;
//     }

//     return 0;
// }

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vi a(n + 1, 0), rui(n + 1, 0);
    rep(n)
    {
        int r;
        cin >> r;

        if (r == 0)
        {
            r = -1;
        }

        rui[i] = r + rui[i - 1];
    }

    int q;
    cin >> q;

    vi ans;
    rep(q)
    {
        int l, r;
        cin >> l >> r;

        ans.emplace_back(rui[r] - rui[l - 1]);
    }

    for (auto &&aa : ans)
    {
        if (aa >= 1)
        {
            cout << "win";
        }
        else if (aa == 0)
        {
            cout << "draw";
        }
        else
        {
            cout << "lose";
        }
        cout << endl;
    }

    return 0;
}
