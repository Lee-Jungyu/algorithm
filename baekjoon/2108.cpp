#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[8001] = { 0, };

int main()
{
	int num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		arr[num + 4000]++;
	}

	int sum = 0;
	int maxCnt = 0;
	int cntSum = 0;
	int middle = N / 2 + 1;
	int frequent;
	int minV = 9999;
	int maxV = -9999;
	int middleV;
	bool twice = false;
	bool middleCheck = false;
	for (int i = 0; i < 8001; i++) {
		if (arr[i]) {
			cntSum += arr[i];

			if (i < minV) minV = i;
			if (i > maxV) maxV = i;

			if (cntSum >= middle && !middleCheck) {
				middleV = i - 4000;
				middleCheck = true;
			}

			sum = sum + (i - 4000) * arr[i];

			if (maxCnt == arr[i] && !twice) {
				frequent = i - 4000;
				twice = true;
			}
			if (maxCnt < arr[i]) {
				maxCnt = arr[i];
				frequent = i - 4000;
				twice = false;
			}
		}
	}

	//산술평균
	int avg = round(sum / (float)N);
	printf("%d\n", avg);

	//중앙값
	printf("%d\n", middleV);

	//최빈값
	printf("%d\n", frequent);
	
	//범위
	int range = maxV - minV;
	printf("%d\n", range);
}
