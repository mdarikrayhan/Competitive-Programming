// #include <bits/stdc++.h>
#include <iostream>
#include <string.h>  // هذة المكتبة التي بها مثد جاهزة
#include <cmath>     // الخاصة بمكتبات التقريب cout << fixed << setprecision(0000) << DUBLE NUMBER << endl;
#include <cctype>    // الخاصة بمكتبات التحكم في الحروف والمسافات
#include <algorithm> // الخاصة بمكتبات المقارنة من الاصغر والاكبر
#include <iomanip>   // الخاصة بمكتبات تحديد عدد الارقام بعد العلامة العشرية
#include <vector>    // المكتبة الخاصة الأري المنشأ بال فكتر
#include <cstdlib>   // لاستخدام دالة abs()
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{

  int nums[4];
  for (int i = 0; i < 4; i++)
  {
    cin >> nums[i];
  }
  ll result = 0;
  string n;
  cin >> n;
  for (int i = 0; i < n.length(); i++)
  {
    ll add = nums[(int(n[i]) - '0') - 1];
    result += add;
  }
  cout << result << endl;

  return 0;
}
