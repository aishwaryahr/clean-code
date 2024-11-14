#include <stdio.h>

int main() {
    char array[5][20] = {"apple", "banana", "grapes", "oranges"};
    int index;

    for (index = 0; index < 5; index++) {
        if (array[index][0] == 'b' || array[index][0] == 'B') {
            printf("%s\n", array[index]);
        }
    }

    return 0;
}
