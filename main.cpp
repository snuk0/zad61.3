#include <bits/stdc++.h>

using namespace std;


int main()
{
    ifstream in("bledne.txt");
    int a;

    while (in >> a)
    {
        vector <int> v(a);
        for (int i = 0; i < a; i++) {
            in >> v[i];
        }
        vector <int> roznica;
        for (int i = 1; i < a; i++)
        {
            roznica.push_back(v[i] - v[i - 1]);
        }
        sort(roznica.begin(), roznica.end());
        int ans = -1;
        for (int i = 1; i < roznica.size(); i++)
        {
            if (roznica[i] == roznica[i - 1])
            {
                ans = roznica[i];
                break;
            }
        }
        bool ok = true;
        for (int i = 1; i < a - 1; i++)
        {
            if (v[i] - v[i - 1] != ans && v[i + 1] - v[i] != ans)
            {
                cout << v[i] << "\n";
                ok = false;
                break;
            }
        }
        if (ok)
        {
            if (v[1] - v[0] != ans)
                cout << v[0] << "\n";
            else if (v[a - 1] - v[a - 2] != ans)
                cout << v[a - 1] << "\n";
        }
    }

    return 0;
}


