// 3190번 뱀
// 뱀의 몸은 뱀 대가리랑 같은 경로로 움직임
// 따라서 맵 상에서 뱀 대가리가 지나간 곳에 해당 시각을 기록
// 1초에 1칸씩 움직이므로 현재 시각과 해당 타일의 시각의 차가 뱀 길이보다 짧거나 같으면
// 무조건 지 꼬리를 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int arg_t[100];
char arg_c[100];
int map[100][100];
int app[100][100];

int lenght = 1, px, py, pdir = 2, time = 0, N, K, L;

int ndir (int pd, char c) {
    int ret;
    switch(c) {
        case 'D' :
            if (pd == 0) ret = 3;
            else if (pd == 1) ret = 2;
            else if (pd == 2) ret = 0;
            else ret = 1;
            break;
        case 'L' :
            if (pd == 0) ret = 2;
            else if (pd == 1) ret = 3;
            else if (pd == 2) ret = 1;
            else ret = 0;
            break;
    }
    return ret;
}

int move(int T) {
    for (int t = 0; t < T; t++) {
        px += dir[pdir][0];
        py += dir[pdir][1];
        time++;
        if (px < 0 || px >= N || py < 0 || py >= N) {
            printf("%d", time);
            return 0;
        }
        if (map[px][py] && time - map[px][py] <= lenght) {
            printf("%d", time);
            return 0;
        } else {
             map[px][py] = time;
        }
        if (app[px][py]) {
            lenght++;
            app[px][py] = 0;
        }
    }
    return 1;
}

int main()
{
    int err = 0;
    memset(map, 0, sizeof(map));
    memset(app, 0, sizeof(app));
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; i++) {
        int ax, ay;
        scanf("%d%d", &ax, &ay);
        app[ax-1][ay-1] = 1;
    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
         scanf("%d %c", &arg_t[i], &arg_c[i]);
    }
    map[0][0] = 1;
    px = py = 0;
    for (int i = 0; i < L; i++) {
        if (!move(arg_t[i] - time)) {
            err = 1;
            break;
        }
        pdir = ndir(pdir, arg_c[i]);
    }
    if (!err) move(100);
    return 0;
}
