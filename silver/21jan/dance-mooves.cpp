#include <iostream>
#include <unordered_set>

#define MAX_N 100000
#define MAX_K 200000

int N, K;
int dance[MAX_K][2];
struct Port {
    int next;
    std::unordered_set<int> been;
} port[MAX_N + 1];
struct Cow {
    std::unordered_set<int> been;
    int count = -1;
} cow[MAX_N + 1];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N >> K;
    for (int k = 0; k < K; ++k)
        std::cin >> dance[k][0] >> dance[k][1];

    int cur[MAX_N + 1];
    for (int n = 1; n <= N; ++n) {
        port[n].next = n;
        port[n].been.insert(n);
        cur[n] = n;
    }
    for (int k = 0; k < K; ++k) {
        port[cur[dance[k][0]]].next = dance[k][1];
        port[cur[dance[k][1]]].next = dance[k][0];
        port[cur[dance[k][0]]].been.insert(dance[k][1]);
        port[cur[dance[k][1]]].been.insert(dance[k][0]);
        int t = cur[dance[k][0]];
        cur[dance[k][0]] = cur[dance[k][1]];
        cur[dance[k][1]] = t;
    }

    for (int n = 1; n <= N; ++n)
        if (cow[n].count == -1) {
            std::unordered_set<int> same;
            int i = n;
            do {
                same.insert(i);
                for (int m : port[i].been)
                    cow[n].been.insert(m);
                i = port[i].next;
            } while (i != n);
            cow[n].count = cow[n].been.size();
            for (int c : same)
                cow[c].count = cow[n].count;
        }
    for (int n = 1; n <= N; ++n)
        std::cout << cow[n].count << '\n';
    return 0;
}
