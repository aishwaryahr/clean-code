#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool startsWithB(const char *str) {
    if (str == NULL) {
        return false;
    }
    return str[0] == 'b';
}

bool endsWithB(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return false;
    }
    return str[strlen(str) - 1] == 'b';
}
int fliterString(char *names[], int arrayLength, bool (*predicate) (const char*), char *result[], int maxResults) {
    int count = 0;
    for (int i = 0; i < arrayLength; i++) {
        // Compare the first char of the names with the given alphabet
        if(predicate(names[i])) {
            if (count < maxResults) {
                result[count] = names[i];
                count++;
            }
        }
    }
    return count;
}

void printOnConsole(char *result[], int count)
{
    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
    }
}

int main() {
    char *names[10] = {"bosch", "Bob", "Lenovo", "Bengaluru", "Rubic"};
    int arrayLength = sizeof(names) / sizeof(names[0]);
    char* result[arrayLength];
    int maxResults = arrayLength;

    int count = fliterString(names, arrayLength, startsWithB, result, maxResults);
    printOnConsole(result, count);
    
    count = fliterString(names, arrayLength, endsWithB, result, maxResults);
    printOnConsole(result, count);

    return 0;
}
