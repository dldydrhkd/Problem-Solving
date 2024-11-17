import java.util.*;

public class Main {
    static int N;
    static int[][] map;
    static boolean[][] visited;
    static int sharkSize = 2;
    static int sharkX, sharkY;
    static int eatCount = 0;  // 먹은 물고기 수
    static int time = 0;  // 총 시간

    static int[] dx = {-1, 1, 0, 0};  // 상, 하, 좌, 우
    static int[] dy = {0, 0, -1, 1};

    static class Fish implements Comparable<Fish> {
        int x, y, dist;

        Fish(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }

        @Override
        public int compareTo(Fish o) {
            // 거리 같으면, 위쪽, 그 다음 왼쪽
            if (this.dist == o.dist) {
                if (this.x == o.x) return this.y - o.y;
                return this.x - o.x;
            }
            return this.dist - o.dist;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        map = new int[N][N];
        visited = new boolean[N][N];

        // 입력 받기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = sc.nextInt();
                if (map[i][j] == 9) {  // 아기 상어 위치
                    sharkX = i;
                    sharkY = j;
                    map[i][j] = 0;  // 아기 상어 위치는 빈 칸으로 처리
                }
            }
        }

        // 아기 상어가 물고기를 잡아먹는 과정
        while (true) {
            Fish target = bfs();  // BFS로 먹을 물고기 찾기
            if (target == null) break;  // 먹을 수 있는 물고기가 없다면 종료

            // 물고기 먹기
            sharkX = target.x;
            sharkY = target.y;
            map[target.x][target.y] = 0;  // 물고기를 먹었으므로 해당 칸은 비게 된다.
            time += target.dist;  // 이동 시간 추가
            eatCount++;  // 먹은 물고기 수 증가

            // 상어 크기 증가
            if (eatCount == sharkSize) {
                sharkSize++;
                eatCount = 0;  // 물고기 먹은 개수 초기화
            }

            // 다시 탐색할 때마다 visited 배열 초기화
            visited = new boolean[N][N];
        }

        System.out.println(time);
    }

    // BFS로 먹을 물고기 찾기
    private static Fish bfs() {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{sharkX, sharkY});
        visited[sharkX][sharkY] = true;

        List<Fish> possibleFishes = new ArrayList<>();  // 먹을 수 있는 물고기들
        int dist = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] cur = queue.poll();
                int x = cur[0], y = cur[1];

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir], ny = y + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
                        if (map[nx][ny] <= sharkSize) {  // 상어가 갈 수 있는 칸
                            visited[nx][ny] = true;
                            queue.add(new int[]{nx, ny});

                            if (map[nx][ny] > 0 && map[nx][ny] < sharkSize) {
                                possibleFishes.add(new Fish(nx, ny, dist + 1));
                            }
                        }
                    }
                }
            }

            // 물고기 찾았으면 바로 종료
            if (!possibleFishes.isEmpty()) {
                break;
            }

            dist++;
        }

        if (possibleFishes.isEmpty()) return null;  // 먹을 수 있는 물고기가 없다면 null 반환

        // 거리 순으로 가장 가까운 물고기 하나를 선택
        Collections.sort(possibleFishes);
        return possibleFishes.get(0);  // 가장 우선순위가 높은 물고기
    }
}
