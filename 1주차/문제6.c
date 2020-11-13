#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct _Student {

	char name[10];
	int score;

}Student;

int main(void) {

	Student st[5];
	int sum = 0;
	double aver = 0.0;

	for (int i = 0; i < 5; i++) {
		scanf("%s %d", st[i].name, &st[i].score);
		sum += st[i].score;
		getchar();
	}

	aver = sum / 5.0;
	for (int i = 0; i < 5; i++) {
		if (st[i].score < aver)
			printf("%s\n", st[i].name);
	}


	return 0;
}
