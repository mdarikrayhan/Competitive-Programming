/* -*- coding: utf-8 -*-
 *
 * 1970F3.cc: F3. Playing Quidditch (Hard)
 */

#include<cstdio>
#include<algorithm>

using namespace std;

/* constant */

const int MAX_N = 99;
const int MAX_M = 99;
const int P = 10;
const int K = P * 2 + 3;

enum { B = 0, R = 1 };
enum { QF = P * 2, BL, ST, BG, RG };
enum { DU, DD, DL, DR, CATCH, THROW };

/* typedef */

struct Entity {
  int y, x;
  Entity() {}
  Entity(int _y, int _x): y(_y), x(_x) {}

  void move(int di) {
    switch (di) {
    case DU: y--; break;
    case DD: y++; break;
    case DL: x--; break;
    case DR: x++; break;
    }
  }

  bool operator==(const Entity &e) const {
    return y >= 0 && y == e.y && x == e.x;
  }
};

/* global variables */

Entity es[K];

/* subroutines */

int gs[MAX_N][MAX_M];

int readentity() {
  char w[8];
  scanf("%s", w);

  if (w[0] == 'B')
    return (w[1] == 'G') ? BG : B * P + (w[1] - '0');
  if (w[0] == 'R')
    return (w[1] == 'G') ? RG : R * P + (w[1] - '0');
  if (w[1] == 'Q')
    return QF;
  if (w[1] == 'B')
    return BL;
  if (w[1] == 'S')
    return ST;

  return -1;
}

int readmove() {
  char w[4];
  scanf("%s", w);

  switch (w[0]) {
  case 'U': return DU;
  case 'D': return DD;
  case 'L': return DL;
  case 'R': return DR;
  case 'C': return CATCH;
  case 'T': return THROW;
  }
  return -1;
}

/* main */

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  fill(es, es + K, Entity(-1, -1));
  
  for (int y = 0; y < n; y++) {
    fill(gs[y], gs[y] + m, -1);
    for (int x = 0; x < m; x++) {
      int i = readentity();
      //printf(" %d,%d = %d\n", y, x, i);

      if (i == BG || i == RG) gs[y][x] = i;
      else if (i >= 0) es[i] = Entity(y, x);
    }
  }

  int qc = -1;
  int sc[2] = {0, 0};

  int tn;
  scanf("%d", &tn);
  
  for (int t = 0; t < tn; t++) {
    int i = readentity();
    int di = readmove();
    int ey = es[i].y, ex = es[i].x;
    //printf(" %d: %d %d\n", t, i, di);

    if (di == CATCH) {
      int j = readentity();
      if (j == QF) {
	qc = i;
      }
      else if (j == ST) {
	if (i < P) {
	  printf("%d BLUE CATCH GOLDEN SNITCH\n", t);
	  sc[B] += 10;
	}
	else {
	  printf("%d RED CATCH GOLDEN SNITCH\n", t);
	  sc[R] += 10;
	}
	break;
      }
    }
    else if (di == THROW) {
      if (gs[ey][ex] == BG) {
	sc[R]++, es[QF] = Entity(n / 2, m / 2), qc = -1;
	printf("%d RED GOAL\n", t);
      }
      else if (gs[ey][ex] == RG) {
	sc[B]++, es[QF] = Entity(n / 2, m / 2), qc = -1;
	printf("%d BLUE GOAL\n", t);
      }
    }
    else {
      es[i].move(di);

      for (int i = 0; i < P * 2; i++)
	if (es[i] == es[BL]) {
	  es[i] = Entity(-1, -1);
	  printf("%d %c%d ELIMINATED\n",
		 t, (i < P) ? 'B' : 'R', i % P);
	}
    }
  }

  printf("FINAL SCORE: %d %d\n", sc[R], sc[B]);

  return 0;
}
