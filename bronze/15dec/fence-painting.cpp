#include <fstream>

std::ifstream fin("paint.in");
std::ofstream fout("paint.out");

int main() {
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    int ans = b - a + d - c;
    if (c >= a && d <= b)
        ans -= d - c;
    else if (a >= c && b <= d)
        ans -= b - a;
    else if (c < a && a < d)
        ans -= d - a;
    else if (c < b && b < d)
        ans -= b - c;
    fout << ans << '\n';
    return 0;
}
