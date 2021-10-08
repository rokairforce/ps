#include <stdio.h>
#include <stdlib.h>

int R, C;
char map[100][100];
int ard_idx[100][100];
int dir[10][2] = {{0, 0},
                  {1, -1}, {1, 0}, {1, 1},
                  {0, -1}, {0, 0}, {0, 1},
                  {-1, -1}, {-1, 0}, {-1, 1}};
int jong[2], ca[10000][2], dead[10000];

int main()
{
    char cmd[102];
    int numca = 0, cmdlen;
    memset(dead, 0, sizeof(dead));
    memset(ard_idx, -1, sizeof(ard_idx));
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf(" %c", &map[i][j]);
            if (map[i][j] == 'R') {
                ca[numca][0] = i, ca[numca][1] = j;
                ard_idx[i][j] = numca;
                numca++;
            } else if (map[i][j] == 'I') {
                jong[0] = i;
                jong[1] = j;
            }
        }
    }
    scanf("%s", cmd);
    cmdlen = strlen(cmd);
    int end;
    for (int i = 0; i < cmdlen; i++) {
        end = 0;
        jong[0] += dir[cmd[i] - '0'][0];
        jong[1] += dir[cmd[i] - '0'][1];
        if (ard_idx[jong[0]][jong[1]] != -1) {
            end = 1;
            printf("kraj %d", i+1);
            break;
        }
        memset(ard_idx, -1, sizeof(ard_idx));
        // ca coords
        for (int j = 0; j < numca; j++) {
            if (dead[j]) continue;
            int mind = 99999, md;
            for (int k = 1; k < 10; k++) {
                int caxnew = ca[j][0] + dir[k][0];
                int caynew = ca[j][1] + dir[k][1];
                if (caxnew < 0 || caxnew >= R
                    || caynew < 0 || caynew >= C) continue;
                if (mind > abs(jong[0] - caxnew) + abs(jong[1] - caynew)) {
                    mind = abs(jong[0] - caxnew) + abs(jong[1] - caynew);
                    md = k;
                }
            }
            ca[j][0] += dir[md][0];
            ca[j][1] += dir[md][1];
        }
        // embed position of cas
        for (int j = 0; j < numca; j++) {
            if (dead[j]) continue;
            if (ca[j][0] == jong[0] && ca[j][1] == jong[1]) {
                end = 1;
                break;
            } else {
                if (ard_idx[ca[j][0]][ca[j][1]] != -1) {
                    dead[ard_idx[ca[j][0]][ca[j][1]]] = 1;
                    dead[j] = 1;
                } else {
                    ard_idx[ca[j][0]][ca[j][1]] = j;
                }
            }
        }
        if (end) {
            printf("kraj %d", i+1);
            break;
        }
    }
    if (!end) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                map[i][j] = '.';
            }
        }
        for (int i = 0; i < numca; i++) {
            if (dead[i]) continue;
            map[ca[i][0]][ca[i][1]] = 'R';
        }
        map[jong[0]][jong[1]] = 'I';
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
