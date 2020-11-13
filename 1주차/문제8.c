#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Student {
	
	char name[8];
	int korean, english, math;
	double aver;

}Student;
int main(void) {

	int N;
	int sum = 0;
	Student *st = NULL;

	scanf("%d", &N);

	st = (Student *)malloc(sizeof(Student) * N);

	if (st == NULL)
		printf("동적 할당 실패!");

	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", st[i].name, &st[i].korean, &st[i].english, &st[i].math);
		getchar();
		st[i].aver = (st[i].korean + st[i].english + st[i].math) / 3.0;
	}

	for (int i = 0; i < N; i++) {
		
		printf("%s %.1f ", st[i].name, st[i].aver);
		if (st[i].korean >= 90 || st[i].english >= 90 || st[i].math >= 90)
			printf("GREAT ");
		if (st[i].korean < 70 || st[i].english < 70 || st[i].math < 70)
			printf("BAD ");
		printf("\n");

	
	}

	free(st);

	return 0;
}
