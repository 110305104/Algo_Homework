#pragma warning( disable : 4996 )
#include <stdio.h>

int Max(int a, int b) {
	if (a >= b)	return a;
	return b;
}


int main() {
	int count = 0;
	int num;
	int ans = 0, sum = 0, max = -10002;
	int total = 0,ans2=0,sum2=0, min= -10002;
	while (scanf("%d", &num) != EOF) {
		count++;
		total += num;

		if (max < num)	max = num;
		sum += num;
		if (sum < 0)	sum = 0;
		if (ans < sum)	ans = sum;


		if (min < -num)	min = -num;
		sum2 += -num;
		if (sum2 < 0)	sum2 = 0;
		if (ans2 < sum2)	ans2 = sum2;

	}
	
	printf("%d", Max(ans, total + ans2 ));
}