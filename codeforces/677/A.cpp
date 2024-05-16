// A. Vanya and Fence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;


int main()
{
    short numberOfFriends{ 0 }, theHightOfFence{ 0 };
    cin >> numberOfFriends >> theHightOfFence;
    short theFriendHight{ 0 };
    unsigned short MinWidth{ 0 };
    while (numberOfFriends--) {
        cin >> theFriendHight;
        if (theFriendHight > theHightOfFence) {
            MinWidth += 2;

        }
        else {
            MinWidth++;
        }
    }
    cout << MinWidth;
}
