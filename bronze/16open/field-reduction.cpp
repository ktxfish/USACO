#include <algorithm>
#include <fstream>

#define MAX_N 50000

std::ifstream fin("reduce.in");
std::ofstream fout("reduce.out");

int N;
struct Cow {
    int n, x, y;
} cow[MAX_N];
int min_area;

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n) {
        cow[n].n = n;
        fin >> cow[n].x >> cow[n].y;
    }
    std::sort(cow, cow + N, [](const Cow a, const Cow b){ return a.x < b.x; });
    int min_x = cow[0].n;
    int min2_x = cow[1].n;
    int max_x = cow[N - 1].n;
    int max2_x = cow[N - 2].n;
    std::sort(cow, cow + N, [](const Cow a, const Cow b){ return a.y < b.y; });
    int min_y = cow[0].n;
    int min2_y = cow[1].n;
    int max_y = cow[N - 1].n;
    int max2_y = cow[N - 2].n;
    std::sort(cow, cow + N, [](const Cow a, const Cow b){ return a.n < b.n; });

    min_area = (cow[max_x].x - cow[min_x].x) * (cow[max_y].y - cow[min_y].y);
    if (min_x == min_y)
        min_area = std::min(min_area, (cow[max_x].x - cow[min2_x].x) * (cow[max_y].y - cow[min2_y].y));
    else if (min_x == max_y)
        min_area = std::min(min_area, (cow[max_x].x - cow[min2_x].x) * (cow[max2_y].y - cow[min_y].y));
    else
        min_area = std::min(min_area, (cow[max_x].x - cow[min2_x].x) * (cow[max_y].y - cow[min_y].y));
    if (max_x == min_y)
        min_area = std::min(min_area, (cow[max2_x].x - cow[min_x].x) * (cow[max_y].y - cow[min2_y].y));
    else if (max_x == max_y)
        min_area = std::min(min_area, (cow[max2_x].x - cow[min_x].x) * (cow[max2_y].y - cow[min_y].y));
    else
        min_area = std::min(min_area, (cow[max2_x].x - cow[min_x].x) * (cow[max_y].y - cow[min_y].y));
    if (min_y != min_x && min_y != max_x)
        min_area = std::min(min_area, (cow[max_x].x - cow[min_x].x) * (cow[max_y].y - cow[min2_y].y));
    if (max_y != min_x && max_y != max_x)
        min_area = std::min(min_area, (cow[max_x].x - cow[min_x].x) * (cow[max2_y].y - cow[min_y].y));
    fout << min_area << '\n';
    return 0;
}
