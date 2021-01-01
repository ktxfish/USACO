#include <fstream>

#define MAX_N 50
#define MAX_M 50

std::ifstream fin("badmilk.in");
std::ofstream fout("badmilk.out");

int N, M, D, S;
int first[MAX_N][MAX_M];
int bad[MAX_M];
int ppl[MAX_M];
int med;

int main() {
    fin >> N >> M >> D >> S;
    for (int d = 0; d < D; ++d) {
        int p, m, t;
        fin >> p >> m >> t;
        --p, --m;
        if (first[p][m] == 0)
            ++ppl[m];
        if (first[p][m] == 0 || t < first[p][m])
            first[p][m] = t;
    }
    for (int s = 0; s < S; ++s) {
        int p, t;
        fin >> p >> t;
        --p;
        for (int m = 0; m < M; ++m)
            if (first[p][m] != 0 && first[p][m] < t)
                ++bad[m];
    }
    for (int m = 0; m < M; ++m)
        if (bad[m] == S && ppl[m] > med)
            med = ppl[m];
    fout << med << '\n';
    return 0;
}
