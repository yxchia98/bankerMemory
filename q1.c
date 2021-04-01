// Banker's Algorithm Question

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int available[4] = {0, 0, 0, 0};// available array
int need[6][4] = {0};           // need array

int sequence[6];                // safe sequence array
int index = 0;                  // index of safe sequence
int check[] = {0,0,0,0,0,0};    // set all checking value to avoid random value
int unsafe = 0;                 // check for unsafe process
int notEnoughIndex[4];          // Index to identify resource

int i, j, n, y;

//Allocation Matrix
int allocation[6][4] = {{2,1,3,3},      //P0
                        {2,3,1,2},      //P1
                        {3,3,3,1},      //P2
                        {2,1,3,4},      //P3
                        {3,2,2,5},      //P4
                        {2,1,2,3}};     //P5

//Max Matrix
int max[6][4] = {{7,3,4,5},     //P0
                 {8,6,2,4},     //P1
                 {9,5,5,6},     //P2
                 {6,4,6,6},     //P3
                 {8,3,2,6},     //P4
                 {8,3,2,3}};    //P5

int main()
{
    // Calculate for minimum instances for each resource
    int miniInstances[4] = {0, 0, 0, 0};
    for (i=0;i<6;i++)
    {
        miniInstances[0] += allocation[i][0];
        miniInstances[1] += allocation[i][1];
        miniInstances[2] += allocation[i][2];
        miniInstances[3] += allocation[i][3];
    }

    // Display min num of instance required for each resource
    printf("Minimum number of instances of resource A required: %d", miniInstances[0]);
    printf("\nMinimum number of instances of resource B required: %d", miniInstances[1]);
    printf("\nMinimum number of instances of resource C required: %d", miniInstances[2]);
    printf("\nMinimum number of instances of resource D required: %d\n\n", miniInstances[3]);

    // Requesting for user input
    while (available[0] < miniInstances[0])
    {
        printf("Enter number of total instances of resource type A : ");
        scanf("%d", &available[0]);
    }
    while (available[1] < miniInstances[1])
    {
        printf("Enter number of total instances of resource type B : ");
        scanf("%d", &available[1]);
    }
    while (available[2] < miniInstances[2])
    {
        printf("Enter number of total instances of resource type C : ");
        scanf("%d", &available[2]);
    }
    while (available[3] < miniInstances[3])
    {
        printf("Enter number of total instances of resource type D : ");
        scanf("%d", &available[3]);
    }

    // Available resource
    for (i=0;i<4;i++)
        available[i] -= miniInstances[i];

    // Print Available Resources
    printf("\nAvailable resources: ");
    printf("\nA: %d\t B: %d\t C: %d\t D: %d", available[0], available[1], available[2], available[3]);

    // Calculation for need
    for (i=0;i<6;i++)
    {
        for (n=0;n<4;n++)
        {
            need[i][n] = max[i][n] - allocation[i][n];
        }
    }

    // Banker�s algorithm
    // Loop through all 6 process needs
    for (int i=0;i<6;i++)
    {
        // Loop through all 6 processes again
        for (int n=0;n<6;n++)
        {
            // Check if all the process has finished checking
            if (check[n] == 0)
            {
                // Variable Flag for checking enough resource, 0 for true and 1 for false
                int flag = 0;
                // Loop through their resource
                for (int j=0;j<4;j++)
                {
                    // Check if the amount of resource needed is more than the available
                    // If it is, we flag it by changing the value of flag to 1
                    if (need[n][j] > available[j])
                    {
                        flag = 1;
                        notEnoughIndex[j] = j+1;
                    }
                }
                // Check if flag is equal to 0
                // If it is, it means that we have enough resource for it
                if (flag == 0)
                {
                    // Add the current process into the sequence array
                    sequence[index ++] = n;
                    // Sum the available resource with the current process allocated resource
                    for (int y=0;y<4;y++)
                        available[y] += allocation[n][y];
                    check[n] = 1;
                }
                // Flag is not equal to 0
                // Output of first resource which does not have enough
                else
                {
                    for (int y=0;y<4;y++)
                    {
                        if (notEnoughIndex[y] > 0)
                        {
                            printf("\nResource %c does not have enough resource in process %d", notEnoughIndex[y]+65-1, n); //65-1 because of character code/ascii code
                            printf("\nCurrent available resource = %d, needed resource = %d ", available[notEnoughIndex[y-1]], need[i][n]);
                            printf("\nPossible of unsafe\n");
                        }
                    }
                }
            }
        }
    }

    // Check for safe or unsafe state
    for (int i=0;i<6;i++)
    {
        if (check[i] == 0)
            unsafe ++;
    }

    // Output of safe or unsafe
    if (unsafe == 0)
    {
        printf("\nFollowing is the SAFE Sequence\n");
        for (int i=0;i<6-1;i++)
            printf(" P%d ->", sequence[i]);
        printf(" P%d", sequence[5]);
    }

    else
    {
        printf("\nFollowing is the UNSAFE Process\n");
        for (int i=0;i<6;i++)
        {
            if (check[i] == 0)
                printf(" P%d, ", i);
        }
        printf("does not have sufficient resource");
    }

}

