#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sequence(n);
    vector<long long> count(100001, 0); // Массив для подсчета встречающихся элементов

    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
        count[sequence[i]] += sequence[i]; // Подсчет встречающихся элементов
    }

    // Применяем жадный алгоритм
    vector<long long> dp(100001, 0);
    dp[1] = count[1];
    for (int i = 2; i <= 100000; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + count[i]);
    }

    // Выводим максимальное количество очков
    cout << dp[100000] << endl;

    return 0;
}
