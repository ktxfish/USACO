#include <fstream>

#define MAX_N 100
#define MAX_S 10

std::ifstream fin("mowing.in");
std::ofstream fout("mowing.out");

int N;
int field[MAX_N * MAX_S * 2 + 1][MAX_N * MAX_S * 2 + 1];
int x = MAX_N * MAX_S + 1;

int main() {
    fin >> N;

    int h = MAX_N * MAX_S, k = MAX_N * MAX_S;
    field[h][k] = 1;

    for (int n = 0, t = 2; n < N; ++n) {
        char d;
        int S;
        fin >> d >> S;

        int a = 0, b = 0;
        if (d == 'N')
            a = -1;
        else if (d == 'E')
            b = 1;
        else if (d == 'S')
            a = 1;
        else
            b = -1;

        for (int s = 0; s < S; ++s, ++t) {
            h += a;
            k += b;
            if (field[h][k] > 0 && t - field[h][k] < x)
                x = t - field[h][k];
            field[h][k] = t;
        }
    }
    if (x == MAX_N * MAX_S + 1)
        fout << -1 << '\n';
    else
        fout << x << '\n';
    return 0;
}
