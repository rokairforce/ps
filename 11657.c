// 11657번 타임머신
// 임의의 노드에서 모든 노드로의 최소 가중치를 구하는 문제
// 그 뭐시냐 벨만포드 알고리즘을 사용하면 해결 가능함
// 음의 가중치가 있기 때문에 다익스트라를 사용할 수 없음 사실 쓸 줄도 모르지만
// 벨만포드 알고리즘은 사용법이 간단하다
// 일단 방문한 노드는 거리가 INF보다 작기 때문에 (내가 INF를 그렇게 되도록 설정함)
// 방문했는지 안했는지 알 수 있고, 방문했으면 해당 노드는 출발점이 될 수 있음. 
// 만약 방문하지 않았으면 그 노드는 걸러야 한다. 
// 모든 edge의 탐색을 vertex - 1의 개수만큼 반복하면 무조건 최단거리를 찾을 수 있다..
// 만약 음의 사이클이 존재하면 벨만포드 알고리즘을 사용 불가능하다.
// 음의 사이클 판정 => N번 반복문을 돌려 마지막 N번째에 최단거리가 업데이트 되면 음의 사이클이 있는 것이다. 

#include <stdio.h>
#include <stdlib.h>
#define INF 2000000001LL

typedef long long ll;
typedef struct NODE {
    int A, B;   // A가 출발, B가 도착
    ll w;
} edge;

int N, M;
ll dist[501];
edge list[6001];


int main()
{
    scanf("%d%d", &N, &M);
    int num_node = N;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%lld", &list[i].A, &list[i].B, &list[i].w);
    }

    for (int i = 2; i <= N; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;  // reference node

    while (N) {  // N번 반복
        N--;
        int updated = 0;
        for (int i = 0; i < M; i++) {  // 모든 edge에 대해
            if (dist[list[i].A] == INF) {
                continue;
            } else {
                if (dist[list[i].A] + list[i].w < dist[list[i].B]) {
                    dist[list[i].B] = dist[list[i].A] + list[i].w;
                    updated++;
                }
            }
        }
        if (!N && updated) { // N번째에 업데이트 됐는가?
            printf("-1");
            return 0;
        } else if (!N) {  
             for (int i = 2; i <= num_node; i++) {
                if (dist[i] != INF) printf("%lld\n", dist[i]);
                else printf("-1\n");
             }
        }
    }
    return 0;
}
