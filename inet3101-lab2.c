//Fuechi Xiong - Lab 2: Memory and Structure
//Parts Inventory Menu Without Arrays

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct part{
    int partNumber;
    char partName[50];
    float partSize;
    char partSizeMetric[10];
    float partCost;
};

// Prints all records
void printAllRecords(const struct part *database, int numRecords) {
    if (numRecords == 0) {
        printf("\nNo records to print.\n");
        return;
    }

    for (int i = 0; i < numRecords; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("Part Number: %d\n", database[i].partNumber);
        printf("Part Name: %s\n", database[i].partName);
        printf("Part Size: %.2f\n", database[i].partSize);
        printf("Metric: %s\n", database[i].partSizeMetric);
        printf("Part Cost: %.2f\n", database[i].partCost);
    }
}

// Add a record
void addRecord(struct part **database, int *numRecords) {
    //Increase record count by 1
    int newCount = *numRecords + 1;

    //realloc
    struct part *temp = realloc(*database, newCount * sizeof(struct part));
    if (temp == NULL) {
        printf("Memory allocation failed. Could not add new record.\n");
        return;
    }

    //Update the database pointer and record count
    *database = temp;
    *numRecords = newCount;

    // asks data from user for the new record
    struct part *newPart = &((*database)[newCount - 1]);

    printf("Enter Part Number: ");
    scanf("%d", &newPart->partNumber);
    getchar();

    printf("Enter Part Name: ");
    fgets(newPart->partName, sizeof(newPart->partName), stdin);
    //Remove trailing newline from fgets
    newPart->partName[strcspn(newPart->partName, "\n")] = '\0';

    printf("Enter Part Size (float): ");
    scanf("%f", &newPart->partSize);
    getchar();

    printf("Enter Part Size Metric: ");
    fgets(newPart->partSizeMetric, sizeof(newPart->partSizeMetric), stdin);
    newPart->partSizeMetric[strcspn(newPart->partSizeMetric, "\n")] = '\0';

    printf("Enter Part Cost (float): ");
    scanf("%f", &newPart->partCost);
    getchar();

    printf("\nRecord added successfully.\n");
}

// Deletes the last record
void deleteLastRecord(struct part **database, int *numRecords) {
    if (*numRecords == 0) {
        printf("No records to delete.\n");
        return;
    }

    // Decreases record count by 1
    int newCount = *numRecords - 1;

    //realloc
    struct part *temp = NULL;
    if (newCount > 0) {
        temp = realloc(*database, newCount * sizeof(struct part));
        if (temp == NULL) {
            printf("Memory reallocation failed.\n");
            return;
        }
    }

    *database = temp;
    *numRecords = newCount;
    printf("\nLast record was deleted. New total is now: %d\n", newCount);
}

int main(void) {
    struct part *database = NULL; // Pointer to  dynamic array of Part structs
    int numRecords = 0; // Number of records in our database
    int choice = 0; // User choice
    int running = 1; //Runs the program until it's done

    while (running) {
        printf("\nMENU\n");
        printf("======\n");
        printf("1. Print all records\n");
        printf("2. Print number of records\n");
        printf("3. Print size of database\n");
        printf("4. Add record\n");
        printf("5. Delete last record\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // consume leftover newline from buffer

        switch (choice) {
            case 1:
                printAllRecords(database, numRecords);
                break;
            case 2:
                printf("\nNumber of records: %d\n", numRecords);
                break;
            case 3:
                printf("\nSize of database in bytes: %lu\n",
                       (unsigned long)(numRecords * sizeof(struct part)));
                break;
            case 4:
                addRecord(&database, &numRecords);
                break;
            case 5:
                deleteLastRecord(&database, &numRecords);
                break;
            case 6:
                running = 0;
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    // deletes remaining allocated memory before quitting
    free(database);
    database = NULL;

    return 0;
}