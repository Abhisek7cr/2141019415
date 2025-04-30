#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *fp;
	char buffer[100];
	fp = fopen("data.txt", "w+");
	if (fp == NULL) {
    	perror("Error opening file");
    	return 1;
	}
	fputs("Hello, File Handling in C!", fp);
	rewind(fp);
	fgets(buffer, sizeof(buffer), fp);
	printf("File content: %s\n", buffer);
	fclose(fp);
	return 0;
}
