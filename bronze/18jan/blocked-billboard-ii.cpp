#include <algorithm>
#include <fstream>

std::ifstream fin("billboard.in");
std::ofstream fout("billboard.out");

int lx1, ly1, lx2, ly2;
int fx1, fy1, fx2, fy2;
int tarp;

int main() {
    fin >> lx1 >> ly1 >> lx2 >> ly2
        >> fx1 >> fy1 >> fx2 >> fy2;
    tarp = (lx2 - lx1) * (ly2 - ly1);

    if (fx1 <= lx1 && fx2 >= lx2 && (fy1 <= ly1 || fy2 >= ly2)) {
        int a = std::min(fy2, ly2) - std::max(fy1, ly1);
        if (a > 0)
            tarp -= (lx2 - lx1) * a;
    } else if (fy1 <= ly1 && fy2 >= ly2 && (fx1 <= lx1 || fx2 >= lx2)) {
        int b = std::min(fx2, lx2) - std::max(fx1, lx1);
        if (b > 0)
            tarp -= (ly2 - ly1) * b;
    }
    fout << tarp << '\n';
    return 0;
}
