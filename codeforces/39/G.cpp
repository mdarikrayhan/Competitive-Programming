// LUOGU_RID: 158045696
#include <bits/stdc++.h>
using namespace std;
const int NUM_MAX = 0x7fff, N = 1000005;
const int UNSOLVEABLE = NUM_MAX + 1;
class Interpreter {
	public:
		char code[N];
		int ret[NUM_MAX + 5];
		bool vis[NUM_MAX + 5];
		Interpreter(const char* _code = "\0") {
			memset(ret, -1, sizeof(ret));
			strcpy(code + 1, _code);
		}
		Interpreter operator=(const Interpreter& i) {
			memset(ret, -1, sizeof(ret));
			strcpy(code + 1, i.code + 1);
			return *this;
		}
		void init(const char* _code) {
			*this = Interpreter(_code);
		}
		int explainNumber(int argu, int l, int r) {
			int x;
			sscanf(code + l, "%d", &x);
			return x;
		}
		int explainMultiplier(int argu, int l, int r) {
			for (int i = l; i <= r; i++) {
				if (code[i] == 'n') return argu;
				if (code[i] == 'f') {
					int bracLevel = 0, lBracPos = -1, rBracPos;
					for (int j = i + 1; j <= r; j++) {
						if (code[j] == '(' && lBracPos == -1) lBracPos = j;
						if (code[j] == '(') bracLevel++;
						if (code[j] == ')') bracLevel--;
						if (bracLevel == 0) {
							rBracPos = j;
							break;
						}
					}
					int ariExp = explainArithmExpr(argu, lBracPos + 1, rBracPos - 1);
					if (ariExp == UNSOLVEABLE) return UNSOLVEABLE;
					return explainFunction(ariExp, 1, strlen(code + 1));
				}
			}
			return explainNumber(argu, l, r);
		}
		int explainProduct(int argu, int l, int r) {
			int opPos = -1, opType = 1, bracLevel = 0;
			for (int i = r; i >= l; i--) {
				if (code[i] == ')') bracLevel++;
				if (code[i] == '(') bracLevel--;
				if (bracLevel == 0) {
					if (code[i] == '*') {
						opPos = i, opType = 1;
						break;
					}
					if (code[i] == '/') {
						opPos = i, opType = 2;
						break;
					}
				}
			}
			int product = 1;
			if (opPos != -1) {
				product = explainProduct(argu, l, opPos - 1);
				if (product == UNSOLVEABLE) return UNSOLVEABLE;
			} else opPos = l - 1;
			int mult = explainMultiplier(argu, opPos + 1, r);
			if (mult == UNSOLVEABLE) return UNSOLVEABLE;
			if (opType == 1) return (product * mult + NUM_MAX + 1) % (NUM_MAX + 1);
			return (product / mult + NUM_MAX + 1) % (NUM_MAX + 1);
		}
		int explainSum(int argu, int l, int r) {
			int opPos = -1, opType = 1, bracLevel = 0;
			for (int i = r; i >= l; i--) {
				if (code[i] == ')') bracLevel++;
				if (code[i] == '(') bracLevel--;
				if (bracLevel == 0) {
					if (code[i] == '+') {
						opPos = i, opType = 1;
						break;
					}
					if (code[i] == '-') {
						opPos = i, opType = 2;
						break;
					}
				}
			}
			int sum = 0;
			if (opPos != -1) {
				sum = explainSum(argu, l, opPos - 1);
				if (sum == UNSOLVEABLE) return UNSOLVEABLE;
			} else opPos = l - 1;
			int product = explainProduct(argu, opPos + 1, r);
			if (product == UNSOLVEABLE) return UNSOLVEABLE;
			if (opType == 1) return (sum + product + NUM_MAX + 1) % (NUM_MAX + 1);
			return (sum - product + NUM_MAX + 1) % (NUM_MAX + 1);
		}

		int explainArithmExpr(int argu, int l, int r) {
			return explainSum(argu, l, r);
		}
		int explainLogicalExpr(int argu, int l, int r) {
			int opBegin, opEnd, opType;
			for (int i = l; i <= r; i++) {
				if (code[i] == '<') {
					opBegin = opEnd = i;
					opType = 1;
					break;
				}
				if (code[i] == '>') {
					opBegin = opEnd = i;
					opType = 2;
					break;
				}
				if (code[i] == '=' && code[i + 1] == '=') {
					opBegin = i, opEnd = i + 1;
					opType = 3;
					break;
				}
			}
			int ari1Result = explainArithmExpr(argu, l, opBegin - 1);
			if (ari1Result == UNSOLVEABLE) return UNSOLVEABLE;
			int ari2Result = explainArithmExpr(argu, opEnd + 1, r);
			if (ari2Result == UNSOLVEABLE) return UNSOLVEABLE;
			if (opType == 1) return ari1Result < ari2Result;
			if (opType == 2) return ari1Result > ari2Result;
			return ari1Result == ari2Result;
		}

		int explainOperator(int argu, int l, int r) {
			for (int i = l; i <= r; i++) {
				if (code[i] == 'i' && code[i + 1] == 'f') {
					int logExpBegin = -1, bracLevel = 0, logExpEnd;
					for (int j = i; j <= r; j++) {
						if (code[j] == '(' && logExpBegin == -1) logExpBegin = j + 1;
						if (code[j] == '(') bracLevel++;
						if (code[j] == ')') bracLevel--;
						if (bracLevel == 0 && logExpBegin != -1) {
							logExpEnd = j - 1;
							break;
						}
					}
					int logResult = explainLogicalExpr(argu, logExpBegin, logExpEnd);
					if (logResult == 0 || logResult == UNSOLVEABLE) return UNSOLVEABLE;
					i = logExpEnd + 2;
				}
				if (code[i] == 'r' && code[i + 1] == 'e') {
					int ariEnd;
					for (int j = i + 6; j <= r; j++) {
						if (code[j] == ';') {
							ariEnd = j - 1;
							break;
						}
					}
					return explainArithmExpr(argu, i + 6, ariEnd);
				}
			}
			return UNSOLVEABLE;
		}

		int explainOperatorSequence(int argu, int l, int r) {
			if (l >= r) return UNSOLVEABLE;
			int opEnd, opResult;
			for (opEnd = l; opEnd <= r; opEnd++) {
				if (code[opEnd] == ';') break;
			}
			if ((opResult = explainOperator(argu, l, opEnd)) != UNSOLVEABLE) return opResult;
			return explainOperatorSequence(argu, opEnd + 1, r);
		}

		int explainFunction(int argu, int l, int r) {
			if (vis[argu]) return UNSOLVEABLE;
			if (ret[argu] >= 0) return ret[argu];
			vis[argu] = true;
			int opSeqBegin, opSeqEnd;
			for (int i = l; i <= r; i++) {
				if (code[i] == '{') opSeqBegin = i + 1;
				if (code[i] == '}') {
					opSeqEnd = i - 1;
					break;
				}
			}
			return ret[argu] = explainOperatorSequence(argu, opSeqBegin, opSeqEnd);
		}
		int run(int want) {
			int codeLen = strlen(code + 1), ans = -1;
			for (int argu = 0; argu <= NUM_MAX; argu++) {
				memset(vis, 0, sizeof(vis));
				if (explainFunction(argu, 1, codeLen) == want) ans = max(ans, argu);
			}
			return ans;
		}
};

Interpreter intPre;
int want;
string code, s;

int main() {
	scanf("%d\n", &want);
	while (getline(cin, s)) code += s + " ";
	intPre.init(code.c_str());
	printf("%d\n", intPre.run(want));
	return 0;
}