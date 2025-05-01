#include <iostream>

using namespace std;

int main() {
  int z_0, h, u_0, v_0, u_1, v_1;
  cin >> z_0 >> h >> u_0 >> v_0 >> u_1 >> v_1;

  size_t qNum;
  cin >> qNum;

  while (qNum--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (z < z_0 || z > z_0 + h) {
      cout << "NO\n";
      continue;
    }
    bool xFill = 0, yFill = 0;
    if ((x >= u_0 && x <= u_1) || (x <= u_0 && x >= u_1)) {
      xFill = true;
    }
    if ((y >= v_0 && y <= v_1) || (y <= v_0 && y >= v_1)) {
      yFill = true;
    }
    if (xFill && yFill) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
