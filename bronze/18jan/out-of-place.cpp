#include <algorithm>
#include <fstream>

#define MAX_N 100

std::ifstream fin("outofplace.in");
std::ofstream fout("outofplace.out");

int N;
int height[MAX_N], sorted[MAX_N];
int swap = -1;

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n)
        fin >> height[n], sorted[n] = height[n];
    std::sort(sorted, sorted + N);
    for (int i = 0; i < N; ++i)
        if (sorted[i] != height[i])
            ++swap;
    fout << std::max(0, swap) << '\n';
    return 0;
}
