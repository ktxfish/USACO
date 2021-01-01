#include <fstream>

std::ifstream fin("lostcow.in");
std::ofstream fout("lostcow.out");

int x, y;
const int exp[] = {
    1, 2, 4, 8, 16, 32, 64, 128, 256,
    512, 1024, 2048, 4096, 8192
    };

int main() {
    fin >> x >> y;
    int z = x, d = 1;
    for (int i = 1; x < y ? z < y : z > y; ++i)
        d += exp[i - 1] + exp[i],
        z = x + (i % 2 == 0 ? 1 : -1) * exp[i];
    d -= (x < y ? z - y : y - z);
    fout << d << '\n';
    return 0;
}
