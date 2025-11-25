#include <stdio.h>

void solution() {
    printf("Hello World\n");
}

int main() {
    char TEST_CASE = !1;
    int t = 1;
    if (TEST_CASE == 1) {
        scanf("%d", &t);
    }

    while (t--) {
        solution();
    }
}
