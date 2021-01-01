#include <algorithm>
#include <fstream>

std::ifstream fin("blocks.in");
std::ofstream fout("blocks.out");

int N;
int ttl[26];

int main() {
    fin >> N;
    for (int n = 0; n < N; ++n)  {
        char word[11];
        fin >> word;
        int cnt1[26] = {};
        for (int c = 0; c < 11 && word[c]; ++c)
            ++cnt1[word[c] - 'a'];
        fin >> word;
        int cnt2[26] = {};
        for (int c = 0; c < 11 && word[c]; ++c)
            ++cnt2[word[c] - 'a'];
        for (int i = 0; i < 26; ++i)
            ttl[i] += std::max(cnt1[i], cnt2[i]);
    }
    for (int i = 0; i < 26; ++i)
        fout << ttl[i] << '\n';
    return 0;
}
