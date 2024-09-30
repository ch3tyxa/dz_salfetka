#include "stdio.h"
#include "funcs.h"
int main(void)
{
    #ifdef TEST
        Tester_1();
        Tester_2();
        Tester_3();
        Tester_4();
    #else
        char file_name[99] = "";
    printf("Enter file name\n");
    scanf("%s", file_name);
        int output = max_range(file_name);
        switch (output)
        {
            case -1:
                printf("incorrect link\n");
                break;
            case -2:
                printf("symbol is not correct\n");
                break;
            case -3:
                printf("file empty\n");
                break;
            case -4:
                printf("file uncorrect subseqence\n");
                break;
        default:
                printf("%d", output);
                break;
        }
    #endif
    return 0;
}
