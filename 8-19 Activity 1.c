#include <stdio.h>

void add(int, int, int*);

int main() {
    // Write C code here
    int x = 1, y = 1, sum = 0;
    add(x, y, &sum);
    printf("%d", sum);

    return 0;
}

void add(int x, int y, int *sum) {
	*sum = x + y;	
}
