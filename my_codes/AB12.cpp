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

double f(const double &x)
{
    return x * x * x + x;
}

int main()
{
    int n;
    cin >> n;

    double xmax{100.0};
    double xmin{0.0};
    double x = (xmax + xmin) / 2.0;
    while (true)
    {
        auto y = f(x);
        if (abs(y - n) <= 0.001)
        {
            cout << x << endl;
            return 0;
        }

        if (y > n)
        {
            xmax = x;
        }
        else
        {
            xmin = x;
        }
        x = (xmax + xmin) / 2.0;
    }
}
