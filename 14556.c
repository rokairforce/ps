// 14556번 저울 놓기 문제
//
// n개의 추가 있을 때를 a_n이라 하면
// a_n+1은 2^n+1 추를 어디에 놓느냐를 잘 케이스로 구분하면 금방 구할 수 있다.
// 사실 2^k꼴의 수는 2^m에서 m < k 인 한 아무리 (서로 다른) 2^m끼리 더해도 절대로 2^k를 넘을 수가 없기 때문에
// 피벗을 어떤 수로 잡느냐가 중요하다


#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000009LL

typedef long long ll;
ll ans[50010];
int main()
{
    int N;
    ans[0] = ans[1] = 1;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        ans[i] = (ans[i-1]*(2*i-1)) % MOD;
    }
    printf("%d", ans[N]);
    return 0;
}
