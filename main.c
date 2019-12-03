#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_operator(char *op)
{
    enum operators{
        add,
        sub,
        mult,
        div,
        unknown
    };

    if (*op == '+') {
        return add;
    } else if (*op == '-') {
        return sub;
    } else if (*op == '.') {
        return mult;
    } else if (*op == '/') {
        return div;
    }

    return unknown;
}

void output_result(int a, int b, int op)
{
    if (op == 0)
        printf("%d + %d = %d\n", a, b, a + b);
    else if (op == 1)
        printf("%d - %d = %d\n", a, b, a - b);
    else if (op == 2)
        printf("%d . %d = %d\n", a, b, a * b);
    else if (op == 3)
        printf("%d / %d = %d\n", a, b, a / b);
    else {
        printf("error: unknown operator\n");
    }
}

int main(int argc, char **argv)
{
    if (argc < 4) {
        printf("error: use with `calculate (int) (operator) (int)`\n");
        exit(1);
    }

    int a, b;
    a = atoi(argv[1]);
    b = atoi(argv[3]);

    int current_operation = check_operator(argv[2]);
    output_result(a, b, current_operation);

    return 0;
}
