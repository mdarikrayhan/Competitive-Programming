/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int NoOfTestCase = 1;
    cin >> NoOfTestCase;
    for (int testcaseno = 1; testcaseno <= NoOfTestCase; testcaseno++)
    {
        long long n;
        char from, to;
        string garbage, s,ans;
        cin >> from >> garbage >> to >> s;
        int base = from == 'b' ? 2 : from == 'o' ? 8
                                 : from == 'd'   ? 10
                                                 : 16;

        try
        {
            if (from == 'd')
            {
                n = stoll(s);
            }
            else
            {
                n = stoll(s, nullptr, base);
            }
        }
        catch (const std::invalid_argument)
        {
            cout << "Case " << testcaseno << " : Invalid Format" << nl;
            continue;
        }

        if (to == 'd')
        {
            ans = to_string(n);
        }
        if (to == 'b')
        {
            string binary = bitset<64>(n).to_string();
            int j = 0;
            while (binary[j] == '0')
            {
                ++j;
            }
            binary.erase(0, j);

            if (from == 'o')
            {
                int i =binary.size();
                int res = i % 4;
                if (res != 0)
                {
                    binary.insert(0, 4 - res, '0');
                }
            }
            ans=binary;
        }
        if (to == 'o')
        {
            stringstream ss;
            ss << std::oct << n;
            string octal = ss.str();
            ans=octal;
        }
        if (to == 'h')
        {
            stringstream ss;
            ss << std::hex << n;
            string hexa = ss.str();
            transform(hexa.begin(), hexa.end(), hexa.begin(), ::toupper);
            ans=hexa;
        }
        cout << "Case " << testcaseno << " : "<<to<< ans << nl;
    }
    return 0;
}
