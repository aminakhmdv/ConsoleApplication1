// Превратить строчные в заглавные

#include <stdio.h>
int main() {
	char x;

	FILE* fin = fopen("test.txt", "r");
	if (fin == NULL)
	{
		printf("File don't open\n");
		return -1;
	}

	while (fscanf_s(fin, "%c", &x) == 1)
	{
		if (x >= 'a' && x <= 'z')
		{
			x = x - 32;
			printf("%d %c\n", x, x);
		}
	}

	return 0;
}