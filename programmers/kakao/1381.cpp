// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int answer;

void recursive(int n, int starCnt, int plusCnt)
{
    if(plusCnt > starCnt * 2) return;
    if(n == 3)
    {
        if(starCnt == 1 && plusCnt == 0) answer++;

        return;
    }

    if(n % 3) {
        if(plusCnt > 0) {
            recursive(n - 1, starCnt, plusCnt - 1);
        }
    }

    else {
        if(starCnt > 0) {
            recursive(n / 3, starCnt - 1, plusCnt);
        }
        if(plusCnt > 0) {
            recursive(n - 1, starCnt, plusCnt - 1);
        }
    }
}

int solution(int n) {
    answer = 0;
    int plusCnt = 0;
    int starCnt = 0;
    int temp = n;
    while(temp >= 3) {
        temp /= 3;
        plusCnt += 2;
    }

    starCnt = plusCnt / 2;
    int rest = n - 2;
    plusCnt -= 2;
    
    recursive(rest, starCnt, plusCnt);

    return answer;
}
