#include <bits/stdc++.h>

using namespace std;

#define rep(n) for (int i = 0; i < (n); ++i)
#define rep1(n) for (int i = 1; i <= (n); ++i)

using vi = vector<int>;

template <class T>
void printvec(const vector<T> &vec)
{
    for (auto &&v : vec)
        cout << v << endl;
}

// int main()
// {
//     int d, n;
//     cin >> d >> n;

//     vi rui(d + 2, 0);

//     rep1(n)
//     {
//         int l, r;
//         cin >> l >> r;

//         rui[l]++;
//         rui[r + 1]--;
//     }

//     rep1(d)
//     {
//         rui[i] += rui[i - 1];
//     }

//     rep1(d)
//     {
//         cout << rui[i] << endl;
//     }
// }

int main(int argc, char const *argv[])
{
    int t, n;
    cin >> t >> n;

    vi rui(t + 2, 0);
    rep(n)
    {
        int l, r;
        cin >> l >> r;

        rui[l]++;
        rui[r]--;
    }

    rep(t)
    {
        if (i == 0)
            continue;

        rui[i] += rui[i - 1];
    }

    rep(t)
    {
        cout << rui[i] << endl;
    }
}
