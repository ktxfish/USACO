#include <fstream>

#define MAX_N 8
#define MAX_K 10

std::ifstream fin("bcs.in");
std::ofstream fout("bcs.out");

int N, K;
bool org[MAX_N][MAX_N];
bool pcs[MAX_K][MAX_N][MAX_N];
int top[MAX_K], btm[MAX_K], lft[MAX_K], rht[MAX_K];
int F, S;

int main() {
    fin >> N >> K;
    for (int n = 0; n < N; ++n) {
        fin.get();
        for (int m = 0; m < N; ++m) {
            char c;
            fin >> c;
            if (c == '#')
                org[n][m] = true;
        }
    }
    for (int k = 0; k < K; ++k) {
        for (int n = 0; n < N; ++n) {
            fin.get();
            for (int m = 0; m < N; ++m) {
                char c;
                fin >> c;
                if (c == '#')
                    pcs[k][n][m] = true;
            }
        }
        for (int n = 0; n < N; ++n)
            for (int m = 0; m < N; ++m)
                if (pcs[k][n][m]) {
                    top[k] = n;
                    goto end_top;
                }
        top[k] = N;
        end_top: ;
        for (int n = N - 1; n >= 0; --n)
            for (int m = 0; m < N; ++m)
                if (pcs[k][n][m]) {
                    btm[k] = N - n - 1;
                    goto end_btm;
                }
        btm[k] = N;
        end_btm: ;
        for (int m = 0; m < N; ++m)
            for (int n = 0; n < N; ++n)
                if (pcs[k][n][m]) {
                    lft[k] = m;
                    goto end_lft;
                }
        lft[k] = N;
        end_lft: ;
        for (int m = N - 1; m >= 0; --m)
            for (int n = 0; n < N; ++n)
                if (pcs[k][n][m]) {
                    rht[k] = N - m - 1;
                    goto end_rht;
                }
        rht[k] = N;
        end_rht: ;
    }
    for (int k = 0; k < K; ++k)
        for (int a = -top[k]; a <= btm[k]; ++a)
            for (int b = -lft[k]; b <= rht[k]; ++b) {
                bool first[MAX_N][MAX_N] = {};
                for (int n = 0; n < N; ++n)
                    for (int m = 0; m < N; ++m)
                        if (pcs[k][n][m])
                            first[n + a][m + b] = true;
                for (int h = k + 1; h < K; ++h)
                    for (int c = -top[h]; c <= btm[h]; ++c)
                        for (int d = -lft[h]; d <= rht[h]; ++d) {
                            bool second[MAX_N][MAX_N] = {};
                            for (int n = 0; n < N; ++n)
                                for (int m = 0; m < N; ++m)
                                    if (pcs[h][n][m])
                                        second[n + c][m + d] = true;
                            bool combo[MAX_N][MAX_N] = {};
                            for (int n = 0; n < N; ++n)
                                for (int m = 0; m < N; ++m)
                                    if (first[n][m] != second[n][m])
                                        combo[n][m] = true;
                            for (int n = 0; n < N; ++n)
                                for (int m = 0; m < N; ++m)
                                    if (combo[n][m] != org[n][m])
                                        goto next;
                            F = k;
                            S = h;
                            goto found;
                            next: ;
                        }
            }
    found: ;
    fout << F + 1 << ' ' << S + 1 << '\n';
    return 0;
}
