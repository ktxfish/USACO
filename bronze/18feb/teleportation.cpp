#include <algorithm>
#include <fstream>

std::ifstream fin("teleport.in");
std::ofstream fout("teleport.out");

int a, b, x, y;

int main() {
    fin >> a >> b >> x >> y;
    fout << std::min({
        std::abs(a - b),
        std::abs(a - x) + std::abs(y - b),
        std::abs(a - y) + std::abs(x - b)
        }) << '\n';
    return 0;
}
