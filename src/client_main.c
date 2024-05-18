#include "client.h"
#include <stdio.h>

int main() {
    printf("1. Read\n");
    printf("2. Write\n");

    int choice;
    scanf("%d", &choice);

    startClient(choice);
    return 0;
}
