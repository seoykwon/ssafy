#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
	// dereference the pointers to get the actual strings and compare them using strcmp
	return strcmp(*(const char**)a, *(const char**)b);
}

int main(){
	const char* p[7] = {"BTS", "BTS", "BBQ", "BTS", "BBQ", "ABCD", "AS"};

	int n = sizeof(p) / sizeof(p[0]);

	qsort(p, n, sizeof(char*), compare);

	const char* result[7] = {'\0',};

	int idx = 0;

	result[idx] = p[0];
	idx++;

	for (int i = 1; i < n; i++){
		if (strcmp(p[i], p[i-1]) != 0){
			result[idx] = p[i];
			idx++;
		}
	}

	int rn = sizeof(result) / sizeof(result[0]);

//	print("출력 결과: n\");

	for (int i = 0; i < rn; i++){
		if (result[i] == NULL) break;
		printf("%s \n", result[i]);
	}

	return 0;
}

//int x = 10;
//int *p = &x;  // p is a pointer to x
//int **q = &p; // q is a pointer to p (a pointer to a pointer)
