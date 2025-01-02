#include <cstdio>
#include <map>
typedef long long int64;
static const int MAXN = 5004;
static const int MAXM = 1004;

inline int64 hash(const char *s) {
    int64 ans = 0;
    for (; *s; ++s) ans = ans * 26 + (*s - 'a');
    return ans;
}
inline bool eval(bool lhs, bool rhs, char op) {
    switch (op) {
        case 'A': return lhs && rhs;
        case 'O': return lhs || rhs;
        case 'X': return lhs ^ rhs;
        default: return false;
    }
}

int n, m;
std::map<int64, int> var_id;
bool result[MAXN][MAXM][2];
int result_sum[MAXM][2] = {{ 0 }};
bool ans_max[MAXM], ans_min[MAXM];

int main()
{
    scanf("%d%d", &n, &m); getchar();
    char var[14], expr[MAXM];
    char operand[3][14];
    for (int i = 0; i < n; ++i) {
        scanf("%s", var);
        var_id[hash(var)] = i;
        for (int j = 0; j < 4; ++j) getchar();
        gets(expr);

        if (expr[0] == '0' || expr[0] == '1') {
            for (int j = 0; j < m; ++j)
                result[i][j][0] = result[i][j][1] = expr[j] - '0';
        } else {
            sscanf(expr, "%s %s %s", operand[0], operand[1], operand[2]);
            int l_op = (operand[0][0] == '?' ? -1 : var_id[hash(operand[0])]),
                r_op = (operand[2][0] == '?' ? -1 : var_id[hash(operand[2])]);
            for (int j = 0; j < m; ++j) {
                result[i][j][0] = eval(l_op == -1 ? 0 : result[l_op][j][0], r_op == -1 ? 0 : result[r_op][j][0], operand[1][0]);
                result[i][j][1] = eval(l_op == -1 ? 1 : result[l_op][j][1], r_op == -1 ? 1 : result[r_op][j][1], operand[1][0]);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            result_sum[j][0] += result[i][j][0];
            result_sum[j][1] += result[i][j][1];
        }

    for (int i = m - 1; i >= 0; --i) {
        if (result_sum[i][0] > result_sum[i][1]) ans_min[i] = 1, ans_max[i] = 0;
        else if (result_sum[i][0] < result_sum[i][1]) ans_min[i] = 0, ans_max[i] = 1;
        else ans_min[i] = ans_max[i] = 0;
    }

    for (int i = 0; i < m; ++i) putchar('0' + (int)ans_min[i]); putchar('\n');
    for (int i = 0; i < m; ++i) putchar('0' + (int)ans_max[i]); putchar('\n');
    return 0;
}
