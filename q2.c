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
    int largest = 0;
    char delim[] = ", ";
    int i = 0, choice = 0;
    bool proceed = true;
    // Transverse the memory paritions array to find out largest size
    for (int i = 0; i < 10; i++)
    {
        if (memoryPartitions[i] > largest)
        {
            largest = memoryPartitions[i];
        }
    }
    // Print out existing memory parititions
    printf("\n\nExisting memory partitions: |");
    for (int i = 0; i < 12; i++){
        printf("%d|", memoryPartitions[i]);
    }
    printf("\n\n");
    // Prompt user for user-input processes
    printf("Enter processeses, splitted by a commas. Processes entered cannot exceed %dKB size.\nEnter processses(KB):", largest);
    fgets(str, 100, stdin);
    // Split the string by commas
    char *ptr = strtok(str, delim);
    while (ptr != NULL)
    {
        userInputs[i] = atoi(ptr);
        ptr = strtok(NULL, delim);
        i++;
    }
    // Print out processes that the user entered
    printf("Process size based on input: |");
    for(int i = 0; i < 10; i++){
        printf("%d|", userInputs[i]);
    }
    printf("\n");
    while (proceed)
    {
        // Main menu for user to select algorithms
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
        // Go to firstFit algorithm
            firstFit(userInputs, memoryPartitions);
            break;
        case 2:
        // Go to bestFit algorithm
            bestFit(userInputs, memoryPartitions);
            break;
        case 3:
        // Go to worstFit algorithm
            worstFit(userInputs, memoryPartitions);
            break;
        default:
        // exit out of main menu, and terminate program.
            proceed = false;
            break;
        }
    }
    return (0);
}
