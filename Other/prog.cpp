#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bitmask;
char* characters;
int characters_count;
char* running;
int running_count;
void permutations() {
    int i;
    if (running_count == characters_count) {
        printf("%s\n", running);
    } else {
        for (i=0; i<characters_count; i++) {
            if ( ((bitmask>>i)&1) == 0 ) {
                running[running_count] = characters[i];
                bitmask |= (1<<i);
                running_count = running_count + 1;
                permutations();
                bitmask ^= (1<<i);
                running_count = running_count - 1;
            }
        }
    }
}

main() {
    int i;
    int cases;

    characters = (char*)malloc(sizeof(char)*30);
    scanf("%s", characters);
    characters_count = strlen(characters);

    running = (char*)malloc(sizeof(char)*30);
    memset(running, 0, 30);
    running_count = 0;

    permutations();

    free(characters);
    free(running);
}
