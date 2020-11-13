#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void) {

	char str[101] = { '\0' };
	int len;
	char c;

	scanf("%s", str);

	len = strlen(str);
	for (int i = 0; i < len; i++) {
		printf("%s\n", str);
		c = str[0];
		strcpy(str, str + 1);
		str[len - 1] = c;
	}


	return 0;
}
