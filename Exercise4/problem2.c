#include<stdio.h>

int main(int argc, char* argv[]) {
	FILE *f1;
	f1 = fopen(argv[1], "r");
	if(!f1 || argc != 2) {
		printf("Error!");
	}
	char c;
	while((c = fgetc(f1)) != EOF) {
		printf("%c", c);
	}
	fclose(f1);
	return 0;
} 