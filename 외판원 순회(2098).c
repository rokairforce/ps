// dp를 사용하는 문제
// 종말조건만 잘 써주면 특별한 자료구조 없이 잘 돌아간다
// dp[a][v]는 노드 a에서 방문상태 v일 때 0으로의 최소 비용이다.

#include <stdio.h>
#include <stdlib.h>
#define INF 1000000001

int N, W[16][16], bit_mask[17];
int dp[16][70000];


int solve(int a, int visit) {
    if (dp[a][visit]) {
        return dp[a][visit];
    } else {
        int min = INF;
        for (int i = 0; i < N; i++) {
            if (W[a][i] && !(visit & bit_mask[i])) {
                int val;
                if (i == 0 && visit != (bit_mask[N]-2)) {  // 전체 노드를 탐색하기 전에 0으로 들어가는 거 방지
                    continue;
                } else if (i == 0 && visit == bit_mask[N]-2) {  // 0을 마지막에 들어가면 적당히 끝내줘야함
                    val = W[a][0];
                } else {
                    val = W[a][i] + solve(i, visit|bit_mask[i]);  // 그 외에는 계속 탐색
                }
                if (val < min) min = val;
            }
        }
        dp[a][visit] = min;
        return min;
    }
}

int main()
{
    memset(dp, 0, sizeof(dp));
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &W[i][j]);
        }
    }
    bit_mask[0] = 1;
    for (int i = 1; i <= N; i++) {
        bit_mask[i] = bit_mask[i-1]*2;
    }
    printf("%d", solve(0, 0));
    return 0;
}
