#include <fstream>

#define MAX_M 10
#define MAX_N 10

std::ifstream fin("cowsignal.in");
std::ofstream fout("cowsignal.out");

int M, N, K;
char sig[MAX_M][MAX_N + 1];

int main() {
    fin >> M >> N >> K;
    for (int m = 0; m < M; ++m)
        fin >> sig[m];
    for (int m = 0; m < M; ++m)
        for (int k = 0; k < K; ++k) {
            for (int n = 0; n < N; ++n)
                for (int h = 0; h < K; ++h)
                    fout << sig[m][n];
            fout << '\n';
        }
    return 0;
}
