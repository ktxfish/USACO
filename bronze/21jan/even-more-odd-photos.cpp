#include <iostream>

int N;
int even, odd;
int group;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N;
    for (int n = 0; n < N; ++n) {
        int b;
        std::cin >> b;
        if (b % 2)
            ++odd;
        else
            ++even;
    }
    while (even > 0 || odd > 0) {
        if (group % 2) {
            if (odd > 0)
                --odd, ++group;
            else
                break;
        }
        else {
            if (even > 0)
                --even, ++group;
            else if (odd > 1)
                odd -= 2, ++group;
            else
                break;
        }
    }
    if (odd % 2 && group % 2 == 0)
        --group;
    std::cout << group << '\n';
    return 0;
}
