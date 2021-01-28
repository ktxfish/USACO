#include <iostream>
#include <string>

int idx[26];
std::string hum;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 0; i < 26; ++i) {
        char l;
        std::cin >> l;
        idx[l - 'a'] = i;
    }
    std::cin >> hum;
    int cur = -1;
    int cnt = 1;
    for (char l : hum) {
        if (idx[l - 'a'] <= cur)
            ++cnt;
        cur = idx[l - 'a'];
    }
    std::cout << cnt << '\n';
    return 0;
}
