#include <algorithm>
#include <iostream>

#define MAX_N 100000
#define MAX_Q 100000

int N, Q;
int final[MAX_N + 1];
struct Stroke {
    int beg, end;
} stroke[MAX_N];
int S;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N >> Q;
    char final_str[MAX_N + 1];
    std::cin >> final_str;
    for (int n = 0; n < N; ++n)
        final[n] = final_str[n] - 'A';
    final[N] = -1;

    for (int i = 0; i < 26; ++i) {
        bool down = false;
        for (int n = 0; n <= N; ++n)
            if (down) {
                if (final[n] == i)
                    stroke[S].end = n;
                else if (final[n] < i) {
                    down = false;
                    ++S;
                }
            }
            else if (final[n] == i) {
                down = true;
                stroke[S].beg = stroke[S].end = n;
            }
    }
    std::sort(stroke, stroke + S, [](Stroke a, Stroke b){ return a.beg < b.beg; });

    for (int q = 0; q < Q; ++q) {
        int beg, end;
        std::cin >> beg >> end;
        --beg, --end;
        int r = S;
        int s = 0;
        while (s < S && stroke[s].beg < beg) {
            if (stroke[s].end > end)
                ++r;
            ++s;
        }
        while (s < S && stroke[s].beg <= end) {
            if (stroke[s].end <= end)
                --r;
            ++s;
        }
        std::cout << r << '\n';
    }
    return 0;
}
