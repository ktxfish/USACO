#include <algorithm>
#include <fstream>

std::ifstream fin("square.in");
std::ofstream fout("square.out");

int ax1, ay1, ax2, ay2;
int bx1, by1, bx2, by2;

int main() {
    fin >> ax1 >> ay1 >> ax2 >> ay2
        >> bx1 >> by1 >> bx2 >> by2;
    int s = std::max({
        ax2 - bx1, bx2 - ax1,
        ay2 - by1, by2 - ay1,
        ax2 - ax1, bx2 - bx1,
        ay2 - ay1, by2 - by1
        });
    fout << s * s << '\n';
    return 0;
}
