#include <fstream>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

std::ifstream fin("cowqueue.in");
std::ofstream fout("cowqueue.out");

int N;
std::priority_queue<
    std::pair<int, int>,
    std::vector<std::pair<int, int>>,
    std::greater<std::pair<int, int>>
    > line;
int now;

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n) {
        int a, b;
        fin >> a >> b;
        line.push({a, b});
    }
    while (!line.empty()) {
        std::pair<int, int> cow = line.top();
        line.pop();
        if (now < cow.first)
            now = cow.first;
        now += cow.second;
    }
    fout << now << '\n';
    return 0;
}
