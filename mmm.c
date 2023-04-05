#include "types.h"
#include "user.h"
#include "fcntl.h"

#define INVALID_NUMBER -9999

int custom_atoi(const char *str)
{
    int sign = 1, unsigned_num = 0;

    if (*str == '-')
    {
        sign = -1;
        ++str;
    }
    else if (*str == '+')
    {
        ++str;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            unsigned_num = unsigned_num * 10 + (str[i] - '0');
        }
        else
        {
            return INVALID_NUMBER;
        }
    }

    return sign * unsigned_num;
}

void insertionSort(int len, int *numbers)
{
    int i, key, j;
    for (i = 1; i < len; i++)
    {
        key = numbers[i];
        j = i - 1;

        while (j >= 0 && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

int calcMean(int len, int *numbers)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += numbers[i];
    }
    return (int)(sum / len);
}

int calcMedian(int len, int *numbers)
{
    int median, idx = 0;
    if (len % 2 == 0)
    {
        idx = len / 2;
        median = (int)((numbers[idx - 1] + numbers[idx]) / 2);
    }
    else
    {
        idx = (int)(len / 2);
        median = numbers[idx];
    }
    return median;
}

int calcMode(int len, int *numbers)
{
    int maxOccurence = 0;
    int mode = numbers[0];

    for (int i = 0; i < len; i++)
    {
        int occurrenceCount = 0;
        for (int j = 0; j < len; j++)
        {
            if (numbers[j] == numbers[i])
            {
                occurrenceCount++;
            }
        }
        if (occurrenceCount > maxOccurence)
        {
            maxOccurence = occurrenceCount;
            mode = numbers[i];
        }
    }
    return mode;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf(2, "mmm: 1 arg required at least!\n");
        exit();
    }
    if (argc > 8)
    {
        printf(2, "mmm: too many args; maximum number of arguments is 7!\n");
        exit();
    }
    int len = argc - 1;
    int numbers[7];

    for (int i = 0; i < len; i++)
    {
        numbers[i] = custom_atoi(argv[i + 1]);
        if (numbers[i] == INVALID_NUMBER)
        {
            printf(2, "Error in numbers; please enter uint numbers!\n");
            exit();
        }
    }

    int mean = calcMean(len, numbers);
    insertionSort(len, numbers);
    int median = calcMedian(len, numbers);
    int mode = calcMode(len, numbers);

    unlink("mmm_result.txt");
    int file_handler = open("mmm_result.txt", O_CREATE | O_WRONLY);
    if (file_handler < 0)
    {
        printf(2, "mmm: cannot create mmm_result.txt!\n");
        exit();
    }

    printf(file_handler, "%d %d %d\n", mean, median, mode);
    close(file_handler);
    exit();
}