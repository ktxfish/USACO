#include <fstream>

std::ifstream fin("promote.in");
std::ofstream fout("promote.out");

int reg[4][2], pro[4];

int main() {
    fin >> reg[0][0] >> reg[0][1] >> reg[1][0] >> reg[1][1]
        >> reg[2][0] >> reg[2][1] >> reg[3][0] >> reg[3][1];
    for (int p = 3; p > 0; --p) {
        pro[p] = reg[p][1] - reg[p][0];
        reg[p - 1][1] += pro[p];
    }
    for (int p = 1; p < 4; ++p)
        fout << pro[p] << '\n';
    return 0;
}
