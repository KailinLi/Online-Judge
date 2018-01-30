#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int opPrint = 30;
const int opLock = 31;
const int opUnlock = 32;
const int opEnd = 33;
struct Program {
    int sequence[30];
    int data[30];
    int p;
    Program(): p(0) {}
    void clean () {
        p = 0;
    }
};
Program program[15];
int variable[26];
deque<int> ready;
deque<int> blockQueue;

int programCnt, assignT, outputT, lockT, unlockT, endT;
int timeCut;
bool lockState;
int running;
int inputCnt;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &inputCnt);
    for (int t = 0; t < inputCnt; ++t) {
        scanf("%d %d %d %d %d %d %d", 
            &programCnt, &assignT, &outputT, &lockT, &unlockT, &endT, &timeCut);
        running = 0;
        lockState = false;
        memset(variable, 0, sizeof(variable));
        char tmpStr[10];
        for (int i = 0; i < programCnt; ++i) {
            program[i].clean();
            while (scanf("%s", tmpStr) && strcmp(tmpStr, "end")) {
                if (!strcmp(tmpStr, "print")) {
                    scanf(" %c ", tmpStr);
                    program[i].sequence[program[i].p] = opPrint;
                    program[i].data[program[i].p++] = tmpStr[0] - 'a';
                }
                else if (!strcmp(tmpStr, "lock")) {
                    program[i].sequence[program[i].p++] = opLock;
                }
                else if (!strcmp(tmpStr, "unlock")) {
                    program[i].sequence[program[i].p++] = opUnlock;
                }
                else {
                    program[i].sequence[program[i].p] = tmpStr[0] - 'a';
                    int tmpData;
                    scanf("%s %d", tmpStr, &tmpData);
                    program[i].data[program[i].p++] = tmpData;
                }
            }
            program[i].sequence[program[i].p] = 33;
            program[i].p = 0;
            ready.push_back(i);
        }
        while (programCnt) {
            running = ready.front();
            ready.pop_front();
            int pc = program[running].p;
            int leftTime = timeCut;
            while (leftTime > 0) {
                switch (program[running].sequence[pc]) {
                    case opPrint:
                        printf("%d: %d\n", running + 1, variable[program[running].data[pc]]);
                        leftTime -= outputT;
                        break;
                    case opLock:
                        if (lockState) {
                            leftTime = -1;
                            blockQueue.push_back(running);
                            program[running].p = pc;
                            pc = -1;
                        }
                        else {
                            lockState = true;
                        }
                        leftTime -= lockT;
                        break;
                    case opUnlock:
                        lockState = false;
                        if (!blockQueue.empty()) {
                            ready.push_front(blockQueue.front());
                            blockQueue.pop_front();
                        }
                        leftTime -= unlockT;
                        break;
                    case opEnd:
                        leftTime = -1;
                        pc = -1;
                        --programCnt;
                        break;
                    default:
                        variable[program[running].sequence[pc]] = program[running].data[pc];
                        leftTime -= assignT;
                        break;
                }
                ++pc;
            }
            if (pc) {
                ready.push_back(running);
                program[running].p = pc;
            }
        }
        if (t != inputCnt - 1)
            printf("\n");
    }
}