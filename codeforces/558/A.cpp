#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int treeNumber, location, numberOfApples;
    cin >> treeNumber;
    int collectedApples = 0;

    vector<pair<int, int>> right, left;

    for (int i = 0; i < treeNumber; i++)
    {
        cin >> location >> numberOfApples;
        if (location > 0)
        {
            right.push_back({location, numberOfApples});
        }
        else
            left.push_back({-location, numberOfApples});
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int leftSize = left.size();
    int rightSize = right.size();
    if (rightSize >= leftSize)
    {
        int counter = 0;
        int collectedApples = 0;
        while (rightSize || leftSize)
        {
            collectedApples += right[counter].second;
            rightSize--;
            if (leftSize == 0)
                break;
            collectedApples += left[counter].second;
            leftSize--;
            counter++;
        }
        cout << collectedApples << "\n";
    }
    else
    {
        int counter = 0;
        int collectedApples = 0;
        while (rightSize || leftSize)
        {
            collectedApples += left[counter].second;
            leftSize--;
            if (rightSize == 0)
                break;
            collectedApples += right[counter].second;
            rightSize--;
            counter++;
        }
        cout << collectedApples << "\n";
    }
    return 0;
}