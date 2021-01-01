#include <fstream>

#define MAX_N 100
#define MAX_M 100

std::ifstream fin("cownomics.in");
std::ofstream fout("cownomics.out");

int N, M;
char spotty[MAX_N][MAX_M + 1], plain[MAX_N][MAX_M + 1];
int count;

int main() {
    fin >> N >> M;
    for (int n = 0; n < N; ++n)
        fin >> spotty[n];
    for (int n = 0; n < N; ++n)
        fin >> plain[n];
    for (int m = 0; m < M; ++m) {
        bool spot[26] = {};
        for (int n = 0; n < N; ++n)
            spot[spotty[n][m] - 'A'] = true;
        for (int n = 0; n < N; ++n)
            if (spot[plain[n][m] - 'A'])
                goto next_m;
        ++count;
        next_m: ;
    }
    fout << count << '\n';
    return 0;
}
