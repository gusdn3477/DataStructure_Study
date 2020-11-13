#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct _Time {

	int hour;
	int minute;
	int second;

}Time;

int main(void) {

	Time t[2];
	int t1 = 0;
	int t2 = 0;
	int total;

	for (int i = 0; i < 2; i++) {
		scanf("%02d %02d %02d", &t[i].hour, &t[i].minute, &t[i].second);
	}

	t1 = t[0].hour * 3600 + t[0].minute * 60 + t[0].second;
	t2 = t[1].hour * 3600 + t[1].minute * 60 + t[1].second;

	total = t2 - t1;

	if (total / 3600) { // ½Ã°£
		printf("%d ", total / 3600);
		total = total % 3600;
	}

	else
		printf("0 ");

	if (total / 60) { // ºÐ
		printf("%d ", total / 60);
		total = total % 60;
	}

	else
		printf("0 ");

	if (total != 0)
		printf("%d ", total);
	else
		printf("0 ");


	return 0;
}
