#include <stdio.h>
#include <stdlib.h>
typedef struct NODE {
    int x, y;
} pt;

int N, M, F, front, rear, map[20][20];
int patt[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
pt q[400], p, dest[20][20];

void push(int x, int y) {
    q[front].x = x;
    q[front].y = y;
    front++;
}

pt* pop() {
    pt *t = &q[rear];
    rear++;
    return t;
}

int bfs(int sx, int sy, int s) {
    int px, py, i, X, Y, md = 9999;
    int v[20][20], d[20][20];
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    v[sx][sy] = 1;
    if (s) {
        d[sx][sy] = F;
        map[sx][sy] = 0;
    } else {
        if (map[sx][sy]) {
            p.x = sx, p.y = sy;
            return 0;
        }
        d[sx][sy] = 0;
    }
    front = rear = 0;
    push(sx, sy);
    p.x = p.y = 999;
    while (front != rear) {
        pt *t = pop();
        px = t->x;
        py = t->y;
        for (i = 0; i < 4; i++) {
            X = px + patt[i][0];
            Y = py + patt[i][1];
            if (X >= N || Y >= N || X < 0
                || Y < 0) continue;
            if (v[X][Y] || map[X][Y] == 1)
                continue;
            v[X][Y] = 1;
            push(X, Y);
            if (s) {
                d[X][Y] = d[px][py] - 1;
                if (d[X][Y] < 0) {
                    return 1;
                } else if (X == dest[sx][sy].x &&
                           Y == dest[sx][sy].y) {
                    F = d[X][Y] + 2 * (d[sx][sy] - d[X][Y]);
                    p.x = X, p.y = Y;
                    return 0;
                }
            } else {
                d[X][Y] = d[px][py] + 1;
                if (map[X][Y] >= 2) {
                    if (F < d[X][Y]) {
                        return 1;
                    }
                    if (md > d[X][Y]) {
                        md = d[X][Y];
                        p.x = X, p.y = Y;
                    } else if (md == d[X][Y]) {
                        if (X < p.x) {
                            md = d[X][Y];
                            p.x = X, p.y = Y;
                        } else if (X == p.x) {
                            if (Y < p.y) {
                                md = d[X][Y];
                                p.x = X, p.y = Y;
                            }
                        }
                    }
                }
            }
        }
    }
    if (p.x == 999 && p.y == 999) return 1;
    if (!s) F -= md;
    return 0;
}


int main() {
    int i, j, sx, sy, dx, dy;
    scanf("%d%d%d", &N, &M, &F);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d%d", &p.x, &p.y);
    p.x--, p.y--;
    for (i = 0; i < M; i++) {
        scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
        map[sx - 1][sy - 1] = 2 + i;
        dest[sx - 1][sy - 1].x = dx - 1;
        dest[sx - 1][sy - 1].y = dy - 1;
    }
    while (M) {
        M--;
        if (bfs(p.x, p.y, 0)) {
            printf("-1");
            return 0;
        }
        if (bfs(p.x, p.y, 1)) {
            printf("-1");
            return 0;
        }
    }
    if (!M) printf("%d", F);
    return 0;
}
