#include <fstream>

#define MAX_N 100
#define MAX_T 1000

std::ifstream fin("lifeguards.in");
std::ofstream fout("lifeguards.out");

int N;
struct Shift {
    int beg, end;
} shift[MAX_N];
int cover[MAX_T + 1];
int ttl_cover;
int min_lost = MAX_T;

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n)
        fin >> shift[n].beg >> shift[n].end;

    for (int n = 0; n < N; ++n)
        for (int t = shift[n].beg; t < shift[n].end; ++t)
            ++cover[t];
    for (int t = 0; t <= MAX_T; ++t)
        if (cover[t] > 0)
            ++ttl_cover;
    for (int n = 0; n < N; ++n) {
        int lost = 0;
        for (int t = shift[n].beg; t < shift[n].end; ++t)
            if (cover[t] == 1)
                ++lost;
        if (lost < min_lost)
            min_lost = lost;
    }
    fout << ttl_cover - min_lost << '\n';
    return 0;
}
