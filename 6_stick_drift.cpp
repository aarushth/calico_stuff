#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;

int N, M;

char Ndirection(int startN, int endN) {
    int a = abs(startN - endN);
    int b = startN + N - endN;
    int c = endN + N - startN;
    if (startN == endN)
        return '\0';
    else if (a < min(b, c))
        return (startN < endN) ? 'D' : 'U';
    else if (b < c)
        return 'U';
    else
        return 'D';
}

char Mdirection(int startM, int endM) {
    int a = abs(startM - endM);
    int b = startM + M - endM;
    int c = endM + M - startM;
    if (startM == endM)
        return '\0';
    else if (a < min(b, c))
        return (startM < endM) ? 'R' : 'L';
    else if (b < c)
        return 'L';
    else
        return 'L';
}

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
    return make_pair((a.first + b.first + N) % N, (a.second + b.second + M) % M);
}

int main() {
    int T;
    cin >> T;

    map<char, pair<int, int>> moves = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'R', {0, 1}},
        {'L', {0, -1}}
    };

    for (int t = 0; t < T; ++t) {
        cin >> N >> M;
        string drift;
        cin >> drift;
        int driftLen = drift.length();

        map<int, pair<int, int>> dic;
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                int val;
                cin >> val;
                dic[val] = make_pair(n, m);
            }
        }

        pair<int, int> curr = make_pair(0, 0);
        int actions = 0;
        int driftCount = 0;

        for (int i = 1; i <= N * M; ++i) {
            pair<int, int> goal = dic[i];
            while (goal != curr) {
                char dr = drift[driftCount];
                curr = add(curr, moves[dr]);
                driftCount = (driftCount + 1) % driftLen;
                actions++;

                if (goal == curr)
                    break;

                if (dr == 'R' || dr == 'L') {
                    char d = Ndirection(curr.first, goal.first);
                    if (d)
                        curr = add(curr, moves[d]);
                    else
                        curr = add(curr, moves[dr]);
                } else if (dr == 'U' || dr == 'D') {
                    char d = Mdirection(curr.second, goal.second);
                    if (d)
                        curr = add(curr, moves[d]);
                    else
                        curr = add(curr, moves[dr]);
                }
            }
        }

        cout << actions << endl;
    }

    return 0;
}
