#include <stdio.h>
#include <string.h>
int recursive(char arr[], char c) {

	char *p = NULL;
	int len = strlen(arr);
	p = arr;
	int i = 0;
	while (i < len) {
		if (p[0] == c) {
			return 1 + recursive(p + 1, c);
		}

		else
			return recursive(p + 1, c);

		i++;
	}
}

int main(void) {

	char ch[101] = { '\0' };
	char c;
	scanf("%s", ch);
	getchar();
	scanf("%c", &c);

	int m = recursive(ch,c);

	printf("%d",m);

	return 0;
}