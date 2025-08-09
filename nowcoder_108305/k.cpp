/**
 * @file k.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-07
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <bits/stdc++.h>

#include <cstring>

#define x first
#define y second
#define D double

using namespace std;

typedef pair<D, D> PDD;
const int amou = 1e5 + 10;
const D eps = 1e-12;

int n;
struct Circle {
  PDD md;
  D r;
} c[amou], temp[amou];
PDD stac[amou];
D x[amou * 4];
bool we[amou];

int dcmp(D a, D b) {
  if (fabs(a - b) < eps) return 0;
  if (a < b) return -1;
  return 1;
}

D f(D x) {
  int top = 0;
  for (int i = 1; i <= n; i++) {
    if (dcmp(c[i].md.x - c[i].r, x) > 0 || dcmp(c[i].md.x + c[i].r, x) < 0)
      continue;
    D d = fabs(x - c[i].md.x), e = sqrt(c[i].r * c[i].r - d * d);
    stac[++top] = {c[i].md.y - e, c[i].md.y + e};
  }
  if (!top) return 0;
  sort(stac + 1, stac + top + 1);
  D st = stac[1].x, ed = stac[1].y, as = 0;
  for (int i = 2; i <= top; i++) {
    if (stac[i].x > ed)
      as += ed - st, st = stac[i].x, ed = stac[i].y;
    else
      ed = max(ed, stac[i].y);
  }
  return as + ed - st;
}

D simpson(D l, D r) {
  D mid = (l + r) / 2;
  return (r - l) * (f(l) + 4 * f(mid) + f(r)) / 6;
}

D asr(D l, D r, D s) {
  D mid = (l + r) / 2;
  D L = simpson(l, mid), R = simpson(mid, r);
  if (fabs(s - L - R) < eps) return L + R;
  return asr(l, mid, L) + asr(mid, r, R);
}

bool cmp(Circle a, Circle b) { return a.r > b.r; }

D get_dist(PDD a, PDD b) {
  D X = a.x - b.x, Y = a.y - b.y;
  return sqrt(X * X + Y * Y);
}

bool in(PDD a, Circle b) {
  D d = get_dist(a, b.md);
  return dcmp(d, b.r) <= 0;
}

bool has(Circle a, Circle b) {
  return in({b.md.x - b.r, b.md.y}, a) && in({b.md.x + b.r, b.md.y}, a) &&
         in({b.md.x, b.md.y + b.r}, a) && in({b.md.x, b.md.y - b.r}, a);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%lf%lf%lf", &c[i].md.x, &c[i].md.y, &c[i].r);
    sort(c + 1, c + n + 1, cmp);
    int u = 0;
    for (int i = 1; i <= n; i++) {
      if (!we[i]) temp[++u] = c[i];
      for (int j = i + 1; j <= n; j++)
        if (has(c[i], c[j])) we[j] = 1;
    }
    n = u;
    for (int i = 1; i <= n; i++)
      c[i] = temp[i], x[i * 2 - 1] = c[i].md.x - c[i].r,
      x[i * 2] = c[i].md.x + c[i].r;
    int tot = n * 2;
    sort(x + 1, x + tot + 1);
    tot = unique(x + 1, x + tot + 1) - x - 1;
    D as = 0;
    for (int i = 1; i < tot; i++) {
      D L = x[i], R = x[i + 1];
      as += asr(L, R, simpson(L, R));
    }
    printf("%.8lf", as);
    memset(x, 0, sizeof(double) * (n + 1));
    memset(c, 0, sizeof(Circle) * (n + 1));
    memset(temp, 0, sizeof(Circle) * (n + 1));
    memset(we, 0, sizeof(bool) * (n + 1));
    memset(stac, 0, sizeof(PDD) * (n + 1));
  }

  return 0;
}
