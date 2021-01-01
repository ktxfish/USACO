#include <fstream>

#define MAX_N 100

std::ifstream fin("shuffle.in");
std::ofstream fout("shuffle.out");

int N;
int order[MAX_N];
int back[MAX_N];

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n) {
        int b;
        fin >> b;
        back[b - 1] = n;
    }
    for (int n = 0; n < N; ++n)
        fin >> order[n];
    for (int i = 0; i < 3; ++i) {
        int new_order[MAX_N];
        for (int n = 0; n < N; ++n)
            new_order[back[n]] = order[n];
        for (int n = 0; n < N; ++n)
            order[n] = new_order[n];
    }
    for (int n = 0; n < N; ++n)
        fout << order[n] << '\n';
    return 0;
}
