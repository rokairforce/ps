// 1756번 피자만들기
// 오븐을 위에서 밑에까지 탐색하면서 각 라인에서 맨 윗줄까지 최솟값 찾아서 적어주기
// 그 다음 맨 밑에서부터 최솟값이 넣는 피자의 직경보다 최초로 크거나 같은 슬롯에 넣어주기
// 피자가 다 못들어갔으면 카운트가 피자 수랑 같지 않음

#include <stdio.h>
#include <stdlib.h>

int oven[300000][2];
int pizza[300000];
int N, D;

int main()
{
    int min = 2000000000;
    scanf("%d%d", &D, &N);
    for (int i = 0; i < D; i++) {
        scanf("%d", &oven[i][0]);
        if (oven[i][0] < min) {
            min = oven[i][1] = oven[i][0];
        } else {
            oven[i][1] = min;
        }
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &pizza[i]);
    }

    int oven_ptr = D - 1;
    int pizza_in = 0;

    for (int i = 0; i < N; i++) {
        if (oven_ptr < 0) {
            break;
        }
        while (oven_ptr >= 0) {
            if (oven[oven_ptr][1] < pizza[i]) {
                oven_ptr--;
            } else {
                pizza_in++;
                oven_ptr--;
                break;
            }
        }
    }

    if (pizza_in != N) {
        printf("0");
    } else {
        printf("%d", oven_ptr+2);
    }

    return 0;
}
