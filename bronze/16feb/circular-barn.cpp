#include <fstream>

#define MAX_N 1000
#define MAX_R 100

std::ifstream fin("cbarn.in");
std::ofstream fout("cbarn.out");

int N;
int r[MAX_N];
int min_walk = MAX_N * MAX_N * MAX_R;

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n)
        fin >> r[n];

    for (int n = 0; n < N; ++n) {
        int walk = 0;
        for (int i = 1; i < N; ++i)
            walk += i * r[(n + i) % N];
        if (walk < min_walk)
            min_walk = walk;
    }
    fout << min_walk << '\n';
    return 0;
}
