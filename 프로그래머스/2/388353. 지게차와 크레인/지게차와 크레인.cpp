#include <string>
#include <vector>
#include <queue>

using namespace std;

int dirY[] = {1,0,-1,0};
int dirX[] = {0,1,0,-1};

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;

    int c = storage.size();   //y크기
    int r = storage[0].size(); //x크기

    vector<vector<bool>> container (c, vector<bool>(r, true)); //해당 위치에 컨테이너 존재여부

    for(string req: requests) //명령어 순회
    {
        vector<vector<bool>> copyContainer = container; //현재 container 저장
        for(int y =0; y < c; y++)
        {
            for(int x = 0; x< r; x++)
            {
                if(req[0] == storage[y][x]) //일치하는 글자 찾음
                {


                    if(req.size() == 2)
                    {
                        //크레인을 사용한 제거
                        copyContainer[y][x] = false;
                    }
                    else
                    {
                        //지게차를 사용한 제거 
                        queue<pair<int,int>> q; //y,x좌표
                        q.push({y,x});
                        vector<vector<bool>> check(c , vector<bool>(r,false)); //방문여부
                        check[y][x] = true; //현재위치 방문 완료
                        int canMove = false;
                        while(!q.empty())
                        {
                            //체크할 현재 위치
                            int curY = q.front().first;
                            int curX = q.front().second;
                            q.pop();

                            //4방향 순회
                            for(int dir =0; dir<4; dir++)
                            {
                                //방향에 따른 다음 위치
                                int nextY = curY + dirY[dir];
                                int nextX = curX + dirX[dir];

                                //다음 위치가 범위를 벗어난다 = 가장자리이다. 컨테이너 제거 가능
                                if(nextY < 0 || nextY > c-1 || nextX < 0 || nextX > r-1)
                                {
                                    canMove = true;
                                    break;
                                }

                                //이미 지나간 자리거나 다음위치에 다른 컨테이너가 있다. 무시
                                if(check[nextY][nextX] == true || container[nextY][nextX] == true)
                                {
                                    continue;
                                }

                                //지나간적 없고 , 비어있는 자리라면 큐에 삽입
                                q.push({nextY,nextX});
                                check[nextY][nextX] = true;
                            }
                        }

                        //제거 가능하면 제거
                        if(canMove == true)
                        {
                            copyContainer[y][x] = false; //제거
                        }
                    } 

                } 
            }
        } 
        container = copyContainer;
    }

    for(int i =0; i< c; i++)
    {
        for(int j =0; j< r; j++)
        {
            if(container[i][j] == true)
            {
                answer++;
            }
        }
    }

    return answer;
}