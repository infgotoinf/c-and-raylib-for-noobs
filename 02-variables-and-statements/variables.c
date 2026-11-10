#include <stdio.h>

int main(void)
{
    int i = 2;
    const char* text = "Cool!";

    printf("%d + %d = %d\n", i, i, i + i);
    printf("%s\n", text);
}
