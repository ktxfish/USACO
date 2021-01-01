#include <algorithm>
#include <fstream>

std::ifstream fin("billboard.in");
std::ofstream fout("billboard.out");

int b1x1, b1y1, b1x2, b1y2;
int b2x1, b2y1, b2x2, b2y2;
int tx1, ty1, tx2, ty2;
int ans;

int main() {
    fin >> b1x1 >> b1y1 >> b1x2 >> b1y2
        >> b2x1 >> b2y1 >> b2x2 >> b2y2
        >> tx1 >> ty1 >> tx2 >> ty2;
    ans = (b1x2 - b1x1) * (b1y2 - b1y1) + (b2x2 - b2x1) * (b2y2 - b2y1);
    int a = std::min(tx2, b1x2) - std::max(tx1, b1x1);
    int b = std::min(ty2, b1y2) - std::max(ty1, b1y1);
    if (a > 0 && b > 0)
        ans -= a * b;
    a = std::min(tx2, b2x2) - std::max(tx1, b2x1);
    b = std::min(ty2, b2y2) - std::max(ty1, b2y1);
    if (a > 0 && b > 0)
        ans -= a * b;
    fout << ans << '\n';
    return 0;
}
