#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char* vect = "DATA|32ALL|0|200|100|ABABC|200";

    char str[256];
    strcpy(str, vect);

    char* token = strtok(str, "|");
    int sum = 0;
    char other[256] = "";
    int isFirst = 1;

//    printf("%s ", token);

    while (token != NULL) {
    	char* endptr;
    	int number = strtol(token, &endptr, 10);

    	if (*endptr == '\0') {
    		sum += number;
    	}
    	else {
    		if (!isFirst){
    			strcat(other, "|");
    		}
    		strcat(other, token);
    		isFirst = 0;
    	}
    	token = strtok(NULL, "|");
    }

    printf("sum : %d\n", sum);
    printf("other : %s\n", other);

//    출력결과
//    sum : 500
//    other : DATA|32ALL|ABABC

    return 0;
}