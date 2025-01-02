import core.stdc.stdio;
import core.stdc.stdlib;
import std.algorithm.comparison;
import std.algorithm.sorting;
import std.algorithm.mutation;
import std.stdio;


int[200010] b;
int[200010] b1;
int[200010] b2;
int[200010] b3;

extern(C) int comp(scope const void* a, scope const void* b) {
  return *cast(const int*)a - *cast(const int*)b;
}

int main()
{
  
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  readln();
  string c = readln();

  int n1 = 0, n2 = 0, n3 = 0;
  for (int i = 0; i < n; i++) {
	  if (c[i] == 'W') {
		  b1[n1++] = b[i];
	  }
	  if (c[i] == 'R') {
		  b2[n2++] = b[i];
	  }
	  if (c[i] == 'O') {
		  b3[n3++] = b[i];
	  }
  }
  qsort(b1.ptr, n1, b1[0].sizeof, &comp);
  qsort(b2.ptr, n2, b2[0].sizeof, &comp);
  qsort(b3.ptr, n3, b3[0].sizeof, &comp);
  for (int i = 0; i < n1 / 2; i++) {
    int t = b1[i];
    b1[i] = b1[n1 - i - 1];
    b1[n1 - i - 1] = t;
  }
  for (int i = 0; i < n2 / 2; i++) {
    int t = b2[i];
    b2[i] = b2[n2 - i - 1];
    b2[n2 - i - 1] = t;
  }
  for (int i = 0; i < n3 / 2; i++) {
    int t = b3[i];
    b3[i] = b3[n3 - i - 1];
    b3[n3 - i - 1] = t;
  }
  for (int i = 1; i < n1; i++) {
	  b1[i] += b1[i - 1];
  }
  for (int i = 1; i < n2; i++) {
	  b2[i] += b2[i - 1];
  }
  for (int i = 1; i < n3; i++) {
	  b3[i] += b3[i - 1];
  }
  int maxc = -1;
  for (int i = 1; i <= min(n3, k - 1); i++) {
    if (k - i <= n1) {
      maxc = max(maxc, b3[i - 1] + b1[k - i - 1]);
    }
    if (k - i <= n2) {
      maxc = max(maxc, b3[i - 1] + b2[k - i - 1]);
    }
  }
  printf("%d\n", maxc);
  return 0;
}