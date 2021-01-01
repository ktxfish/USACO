#include <fstream>

std::ifstream fin("pails.in");
std::ofstream fout("pails.out");

int X, Y, M;
int max_amt;

int main() {
    fin >> X >> Y >> M;
    for (int y = 0; y <= M / Y; ++y) {
        int amt = y * Y + (M - y * Y) / X * X;
        if (amt > max_amt)
            max_amt = amt;
    }
    fout << max_amt << '\n';
    return 0;
}
