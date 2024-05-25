#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int h;
    cin>>h;
    vector<int> levels(h+1);
    bool perfect = true;
    int not_ones = 0;
    for(int i=0; i<h+1; i++)
    {
        cin>>levels[i];
        if(levels[i] != 1)
        {
            not_ones++;
        }
        else
        {
            not_ones = 0;
        }
        if(not_ones > 1)
        {
            perfect = false;
        }
    }
    if(perfect)
    {
        cout<<"perfect";
        return 0;
    }
    cout<<"ambiguous\n";
    int parent = 0;
    vector<int> result;
    vector<int> node_level(200001);
    int c = 0;
    int index = -1;
    not_ones = 0;
    for(int e:levels)
    {
        if(e != 1)
        {
            not_ones++;
        }
        else
        {
            not_ones = 0;
        }
        for(int i=1; i<=e; i++)
        {
            result.push_back(parent);
            if(not_ones == 2 && index == -1)
            {
                index = c;
            }
            c++;
        }
        parent += e;
    }
    for(int e: result)
    {
        cout<<e<<" ";
    }
    cout<<"\n";
    int size = result.size();
    for(int i=0; i<size; i++)
    {
        if(i == index)
        {
            cout<<result[i]-1<<" ";
            continue;
        }
        cout<<result[i]<<" ";
    }
    return 0;
}