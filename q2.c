#include "q2.h"

// // Arrays for Question 2

// // Replace test with userInputs array after testing
// // int test[] = {123, 456, 78, 901, 234, 567, 89, 600, 200, 345};

// // Processes not added in memory partition

int main()
{
    int memoryPartitions[] = {160, 350, 650, 80, 410, 50, 720, 905, 570, 130, 260, 830};
    int userInputs[10];
    char str[100];
    // Transverse the memory paritions array to find out largest size
    int largest = 0;
    char delim[] = ", ";
    int i = 0, choice = 0;
    bool proceed = true;

    for (int i = 0; i < 10; i++)
    {
        if (memoryPartitions[i] > largest)
        {
            largest = memoryPartitions[i];
        }
    }
    printf("\n\nExisting memory partitions: |");
    for (int i = 0; i < 12; i++){
        printf("%d|", memoryPartitions[i]);
    }
    printf("\n\n");
    printf("Enter processeses, splitted by a commas. Processes entered cannot exceed %dKB size.\nEnter processses(KB):", largest);
    fgets(str, 100, stdin);
    // printf("Input String is %s", str);
    char *ptr = strtok(str, delim);
    while (ptr != NULL)
    {
        userInputs[i] = atoi(ptr);
        ptr = strtok(NULL, delim);
        i++;
    }
    printf("Process size based on input: |");
    for(int i = 0; i < 10; i++){
        printf("%d|", userInputs[i]);
    }
    printf("\n");
    while (proceed)
    {
        printf("\n----------Memory Partitions Algorithm----------\n");
        printf("\n1. First-fit algorithm");
        printf("\n2. Best-fit algorithm");
        printf("\n3. Worse-fit algorithm\n");
        printf("\n----------Enter 0 to exit----------\n");
        printf("\nWhich algorithm do you want? 1,2,3? : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            proceed = false;
            break;
        case 1:
            firstFit(userInputs, memoryPartitions);
            break;

        case 2:
            bestFit(userInputs, memoryPartitions);
            break;

        case 3:
            worstFit(userInputs, memoryPartitions);
            break;

        default:
            proceed = false;
            break;
        }
    }
    return (0);
}
