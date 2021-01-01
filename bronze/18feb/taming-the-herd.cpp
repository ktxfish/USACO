#include <fstream>

#define MAX_N 100

std::ifstream fin("taming.in");
std::ofstream fout("taming.out");

int N;
int counter[MAX_N];
int breakout[MAX_N];
int min, maybe;

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n)
        fin >> counter[n];

    if (counter[0] > 0) {
        fout << "-1\n";
        return 0;
    }
    counter[0] = 0;

    for (int n = 0; n < N; ++n) {
        if (counter[n] == -1)
            continue;

        if (breakout[n - counter[n]] == -1) {
            fout << "-1\n";
            return 0;
        }
        breakout[n - counter[n]] = 1;

        for (int i = n; i > n - counter[n]; --i) {
            if (i < 0 || i >= N || breakout[i] == 1) {
                fout << "-1\n";
                return 0;
            }
            breakout[i] = -1;
        }
    }
    for (int n = 0; n < N; ++n)
        if (breakout[n] == 1)
            ++min;
        else if (breakout[n] == 0)
            ++maybe;
    fout << min << ' ' << min + maybe << '\n';
    return 0;
}
