#include <stdio.h>
#include <string.h>

int main () {
	char str1[50], str2[50];


	strcpy(str1, "This is my initial string");

	strcpy(str2, ", add this");


	strcat(str1, str2);


	printf("String after concatenation: %s", str1);

	return(0);
}
