
#include <iostream>

using namespace std;

// int main(int argc, char const *argv[])
// {
//     int N;
//     cin >> N;

//     for (auto i = 9; i >= 0; i--)
//     {
//         auto wari = (1 << i); // 2のn乗
//         auto tmp = (N / wari);
//         cout << tmp % 2;
//     }
//     cout << endl;
//     return 0;
// }

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int j = s.size() - i - 1;

        if(s.at(j) == '1') {
            auto tmp = (1 << i);
            ans += (1 << i);
        }
    }

    cout << ans << endl;

    return 0;
}
