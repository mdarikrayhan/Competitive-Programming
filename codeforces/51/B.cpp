#include "bits/stdc++.h"
using namespace std;

#define TOK_DELIM " <>\n\r\t\0"

int main()
{
    string in, s, tok1, tok2;
    vector<char *> tokens;
    char *token;
    
    s = "";

    for (int i = 0; i < 10; i++)
    { 
        getline(cin, in);
        if (in.length() == 0)
            break;
        s = s + in;
    } 

    char *pch = new char[s.length() + 1];
    strcpy(pch, s.c_str()); 

    token = strtok(pch, TOK_DELIM);
    while (token != NULL)
    {
        tokens.push_back(token);
        token = strtok(NULL, TOK_DELIM);
    }


    stack<string> toks;
    int len;
    stack<int> cnts;
    vector<int> res;

    len = tokens.size();

    for (int i = 0; i < len; i ++)
    {
        tok1 = tokens[i];
        if (tok1[0] != '/')
        {
            if (tok1 == "table")
            {
                cnts.push(0);
            }

            toks.push(tok1);
        }
        else
        {
            tok2 = toks.top();
            if (tok2 == "td")
            {
                cnts.top() ++;
            }
            else if (tok2 == "table")
            {
                res.push_back(cnts.top());
                cnts.pop();
            }
            toks.pop();
        }
    }

    sort(res.begin(), res.end());
    
    cout << res[0];
    for (int i = 1; i < res.size(); i ++)
    {
        cout << " " << res[i];
    }
    cout << "\n";

    return 0;
}