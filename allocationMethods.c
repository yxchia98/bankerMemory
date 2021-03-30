#include "q2.h"

void firstFit(int userInputs[10], int memParts[12])
{
    int count = 0;
    int leftOver[10] = {0};
    int memoryPartitions[12];
    bool notAllocated = false;
    // Clone memory partitions array to be used in this function
    for (int i = 0; i < 12; i++)
    {
        memoryPartitions[i] = memParts[i];
    }
    printf("---------- First-Fit Algorithm ----------");
    for (int i = 0; i < 10; i++)
    {
        for (int n = 0; n < 12; n++)
        {
            if (userInputs[i] <= memoryPartitions[n]) // insert in memory partition
            {
                printf("\nInput process %d(%dKB) is added in Memory Partition %d(%dKB)", i + 1, userInputs[i], n + 1, memoryPartitions[n]);
                memoryPartitions[n] -= userInputs[i];
                printf("\nMemory Partition %d left %d", n + 1, memoryPartitions[n]);
                break;
            }
            if (n == 11) // not inserted into any memory partition
            {
                count++;
                printf("\nInput process %d is not added due to insufficient space. (%d KB)", i + 1, userInputs[i]);
                leftOver[count - 1] = userInputs[i];
                notAllocated = true;
                printf("\nTotal memory not added: %d", count);
            }
        }
    }
    printf("\n\n");
    if (notAllocated)
    {
        for (int i = 0; i < 10; i++)
        {
            if (leftOver[i] > 0)
            {
                printf("Process %d(%dKB), ", i + 1, leftOver[i]);
            }
        }
        printf("has not been allocated due to insufficient hole size.");
    }
    printf("\nMemory Partition Left = ");
    for (int i = 0; i < 12; i++)
        printf("| %d ", memoryPartitions[i]);
    printf("\nEnter any key to continue...");
    scanf("%s");
    printf("|\n\n");
}

void bestFit(int userInputs[10], int memParts[12])
{
    int leftOver[10] = {0};
    int count = 0;
    int memoryPartitions[12];
    bool notAllocated = false;
    // Clone memory partitions array to be used in this function
    for (int i = 0; i < 12; i++)
    {
        memoryPartitions[i] = memParts[i];
    }
    printf("---------- Best-Fit Algorithm ----------");
    for (int i = 0; i < 10; i++)
    {
        int index = 0, amount = -1;
        for (int n = 0; n < 12; n++)
        {
            if (amount < 0) // find first value before compare, negative means not enough memory
            {
                amount = memoryPartitions[n] - userInputs[i];
                index = n;
            }
            else // find second value is there is a need to comapre best-fit
            {
                int newAmount = memoryPartitions[n] - userInputs[i];

                if (amount > newAmount && newAmount >= 0)
                {
                    amount = newAmount;
                    index = n;
                }
            }
        }
        if (amount < 0) // negative value means not inserted in memory partition
        {
            count++;
            printf("\nInput process %d is not added due to insufficient space. (%d KB)", i + 1, userInputs[i]);
            leftOver[count - 1] = userInputs[i];
            notAllocated = true;
            printf("\nTotal memory not added: %d", count);
        }
        else // insert memory partition
        {
            printf("\nInput process %d(%dKB) is added in Memory Partition %d(%dKB)", i + 1, userInputs[i], index + 1, memoryPartitions[index]);
            memoryPartitions[index] -= userInputs[i];
            printf("\nMemory Partition %d left %d", index + 1, memoryPartitions[index]);
        }
    }
    printf("\n\n");

    if (notAllocated)
    {
        for (int i = 0; i < 10; i++)
        {
            if (leftOver[i] > 0)
            {
                printf("Process %d(%dKB), ", i + 1, leftOver[i]);
            }
        }
        printf("has not been allocated due to insufficient hole size.");
    }
    printf("\nMemory Partition Left = ");
    for (int i = 0; i < 12; i++)
        printf("| %d ", memoryPartitions[i]);
    printf("\nEnter any key to continue...");
    scanf("%s");
    printf("|\n\n");
}

void worstFit(int userInputs[10], int memParts[12])
{
    int leftOver[10] = {0};
    int count = 0;
    int memoryPartitions[12];
    bool notAllocated = false;
    // Clone memory partitions array to be used in this function
    for (int i = 0; i < 12; i++)
    {
        memoryPartitions[i] = memParts[i];
    }
    printf("---------- Worst-Fit Algorithm ----------");
    for (int i = 0; i < 10; i++)
    {
        int index = 0, amount = -1;

        for (int n = 0; n < 12; n++)
        {
            if (amount < 0) // find first value before compare, negative means not enough memory
            {
                amount = memoryPartitions[n] - userInputs[i];
                index = n;
            }
            else // find second value is there is a need to comapre worst-fit
            {
                int newAmount = memoryPartitions[n] - userInputs[i];
                if (amount < newAmount && newAmount >= 0)
                {
                    amount = newAmount;
                    index = n;
                }
            }
        }
        if (amount < 0) // negative value means not inserted in memory partition
        {
            count++;
            printf("\nInput process %d is not added due to insufficient space. (%d KB)", i + 1, userInputs[i]);
            leftOver[count - 1] = userInputs[i];
            notAllocated = true;
            printf("\nTotal memory not added: %d", count);
        }
        else // insert memory partition
        {
            printf("\nInput process %d(%dKB) is added in Memory Partition %d(%dKB)", i + 1, userInputs[i], index + 1, memoryPartitions[index]);
            memoryPartitions[index] -= userInputs[i];
            printf("\nMemory Partition %d left %d", index + 1, memoryPartitions[index]);
        }
    }
    printf("\n\n");

    if (notAllocated)
    {
        for (int i = 0; i < 10; i++)
        {
            if (leftOver[i] > 0)
            {
                printf("Process %d(%dKB), ", i + 1, leftOver[i]);
            }
        }
        printf("has not been allocated due to insufficient hole size.");
    }
    printf("\nMemory Partition Left = ");
    for (int i = 0; i < 12; i++)
        printf("| %d ", memoryPartitions[i]);
    printf("\nEnter any key to continue...");
    scanf("%s");
    printf("|\n\n");
}