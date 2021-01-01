#include <algorithm>
#include <fstream>

#define MAX_N 100

std::ifstream fin("hoofball.in");
std::ofstream fout("hoofball.out");

int N;
int loc[MAX_N];
int pass[MAX_N];
int num_init;

int target(int i) {
    if (i == N - 1 || (i != 0 &&
        loc[i] - loc[i - 1] <= loc[i + 1] - loc[i]))
        return i - 1;
    return i + 1;
}

int main() {
    fin >> N;
    if (N == 1) {
        fout << "1\n";
        return 0;
    }
    for (int n = 0; n < N; ++n)
        fin >> loc[n];
    std::sort(loc, loc + N);

    for (int n = 0; n < N; ++n) {
        bool seen[MAX_N] = {};
        int i = n;
        while (!seen[i]) {
            seen[i] = true;
            i = target(i);
        }
        for (int m = 0; m < N; ++m)
            if (seen[m])
                ++pass[m];
        --pass[n];
    }
    for (int n = 0; n < N; ++n)
        if (pass[n] == 0)
            ++num_init;
        else if (n != N - 1 && target(n) == n + 1 && target(n + 1) == n
            && pass[n] == 1 && pass[target(n)] == 1)
            ++num_init;
    fout << num_init << '\n';
    return 0;
}
