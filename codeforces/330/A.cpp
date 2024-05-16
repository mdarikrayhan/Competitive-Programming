#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; ++i)
    {
        cin >> grid[i];
    }

    vector<vector<bool>> eaten(r, vector<bool>(c, false));

    int rows_eaten = 0;
    for (int i = 0; i < r; ++i)
    {
        bool has_strawberry = false;
        for (int j = 0; j < c; ++j)
        {
            if (grid[i][j] == 'S')
            {
                has_strawberry = true;
                break;
            }
        }
        if (!has_strawberry)
        {
            rows_eaten += c;
            for (int j = 0; j < c; ++j)
            {
                eaten[i][j] = true;
            }
        }
    }

    int cols_eaten = 0;
    for (int j = 0; j < c; ++j)
    {
        bool has_strawberry = false;
        for (int i = 0; i < r; ++i)
        {
            if (grid[i][j] == 'S')
            {
                has_strawberry = true;
                break;
            }
        }
        if (!has_strawberry)
        {
            for (int i = 0; i < r; ++i)
            {
                if (!eaten[i][j])
                {
                    ++cols_eaten;
                }
            }
        }
    }

    int total_eaten = rows_eaten + cols_eaten;
    cout << total_eaten << endl;

    return 0;
}
