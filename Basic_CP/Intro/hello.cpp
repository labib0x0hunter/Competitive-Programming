#include <iostream>
using namespace std;

#define endl '\n'

void solution() {
    cout << "Hello World" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool TEST_CASE = !true;
    int t_c = 1;
    if (TEST_CASE)
        cin >> t_c;

    while (t_c--) {
        solution();
    }

    return 0;
}
