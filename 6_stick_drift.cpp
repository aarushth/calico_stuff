#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int T;

pair<int, int> add(pair<int, int> tup1, pair<int, int> tup2, int N, int M) {
    return make_pair((tup1.first + tup2.first) % N, (tup1.second + tup2.second) % M);
}

char Ndirection(int startN, int endN, int N) {
    int a = abs(startN - endN);
    int b = startN + N - endN;
    int c = endN + N - startN;
    if (startN == endN) {
        return '\0';
    } else if (a < min(b, c)) {
        return (startN < endN) ? 'D' : 'U';
    } else if (b < c) {
        return 'U';
    } else {
        return 'D';
    }
}

char Mdirection(int startM, int endM, int M) {
    int a = abs(startM - endM);
    int b = startM + M - endM;
    int c = endM + M - startM;
    if (startM == endM) {
        return '\0';
    } else if (a < min(b, c)) {
        return (startM < endM) ? 'R' : 'L';
    } else if (b < c) {
        return 'L';
    } else {
        return 'L';
    }
}

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;
        string drift;
        cin >> drift;
        int driftLen = drift.length();

        unordered_map<int, pair<int, int>> dic;
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                int x;
                cin >> x;
                dic[x] = make_pair(n, m);
            }
        }

        pair<int, int> curr = make_pair(0, 0);
        int actions = 0;
        int driftCount = 0;
        pair<int, int> goal = dic[1];

        for (int i = 1; i <= N * M; i++) {
            goal = dic[i];
            while (goal != curr) {
                char dr = drift[driftCount];
                curr = add(curr, (dr == 'U') ? make_pair(-1, 0) : (dr == 'D') ? make_pair(1, 0) : (dr == 'R') ? make_pair(0, 1) : make_pair(0, -1), N, M);
                driftCount = (driftCount + 1) % driftLen;
                actions++;
                if (goal == curr) {
                    break;
                } else {
                    if (dr == 'R' || dr == 'L') {
                        char d = Ndirection(curr.first, goal.first, N);
                        if (d) {
                            curr = add(curr, (d == 'D') ? make_pair(1, 0) : make_pair(-1, 0), N, M);
                        } else {
                            curr = add(curr, (dr == 'R') ? make_pair(0, 1) : make_pair(0, -1), N, M);
                        }
                    } else if (dr == 'U' || dr == 'D') {
                        char d = Mdirection(curr.second, goal.second, M);
                        if (d) {
                            curr = add(curr, (d == 'U') ? make_pair(-1, 0) : make_pair(1, 0), N, M);
                        } else {
                            curr = add(curr, (dr == 'U') ? make_pair(-1, 0) : make_pair(1, 0), N, M);
                        }
                    }
                }
            }
        }
        cout << actions << endl;
    }
    return 0;
}