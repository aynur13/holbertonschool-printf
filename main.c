#include <stdio.h>

int _printf(const char *format, ...);  // Declaration of _printf

int main(void)
{
    int count;

    count = _printf("Hello, %s! Character: %c and percent: %%\n", "World", 'A');
    printf("Printed %d characters.\n", count);

    count = _printf("Nothing special here.\n");
    printf("Printed %d characters.\n", count);

    count = _printf("NULL string test: %s\n", NULL);
    printf("Printed %d characters.\n", count);

    return 0;
}
