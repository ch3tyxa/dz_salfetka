#include "stdio.h"
#include "funcs.h"
#include "stdlib.h"

enum error_codes
{
    FILENOTFOUND = -1,
    NOTCORRECTSUBSEQUENCE = -2,
    EMPTYFILE = -3,
    NOTCORRECTSYMBOLFOUND = -4
};

int max_range(char filename[])
{
    FILE* fp = NULL;
    fp = fopen(filename, "r");
    
    int num = 0;
    int last_num = 0;
    int n = 0;
    int flag = 1;
    
    if (!fp)
    {
        return FILENOTFOUND;
    }
    
    while (fscanf(fp, "%d", &num) == 1)
    {
        if (flag)
        {
            n += 1;
            last_num = num;
            flag = 0;
        }
        if (num > last_num && num != last_num)
        {
            if (num != last_num) 
            {} else {
                return NOTCORRECTSUBSEQUENCE;
            }
            last_num = num;
            n += 1;
        }
    }
    
    if (fscanf(fp, "%c", &num) == 1) // вообще не варик брат тут что то сделать, пусть компилятор не ругается
    {
        fclose(fp);
        return NOTCORRECTSYMBOLFOUND;
    }
    
    if (n)
    {
        return EMPTYFILE;
    }
    
    fclose(fp);
    return n;
}

int Tester_1(void)
{
    int out = max_range("test_1.txt");

    if (out != FILENOTFOUND)
    {
        printf("Test_1 Error\n");
        printf("expected:-1 got:%d\n\n", out);
        return 0;
    }

    printf("Test_1 Completed\n\n");
    return 1;
}

int Tester_2(void)
{
    int out = max_range("test_2.txt");
    if (out != NOTCORRECTSYMBOLFOUND)
    {
        printf("Test_2 Error\n");
        printf("expected:-2 got:%d\n\n", out);
        return 0;
    }

    printf("Test_2 Completed\n\n");
    return 1;
}

int Tester_3(void)
{
    int out = max_range("test_3.txt");
    if (out != EMPTYFILE)
    {
        printf("Test_3 Error\n");
        printf("expected:-3 got:%d\n\n", out);
        return 0;
    }

    printf("Test_3 Completed\n\n");
    return 1;
}

int Tester_4(void)
{
    int out = max_range("test_4.txt");
    if (out != NOTCORRECTSUBSEQUENCE)
    {
        printf("Test_4 Error\n");
        printf("expected:-4 got:%d\n\n", out);
        return 0;
    }

    printf("Test_4 Completed\n\n");
    return 1;
}
