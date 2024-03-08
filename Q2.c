#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SHOPNAME "ABC STORE"

//System variables
float itemsArray[101][1] = {0};

//User inputs
int functionIndex;
int functionOption;

//Functions declarations
void printAvailableFunctions ();
void printItemsFunction ();
void newItemFunction ();
void changeDetailsFunuction ();
void deleteItemFunction ();
void createInvoiceFunction ();

//Functions
void printAvailableFunctions () {
    printf("\n\t1. Add item\n\t2. Change item detail\n\t3. Delete item\n\t4. Create invoice\n\t5. See items\n\t6. Exit system\n> ");
}

void newItemFunction () {
    int itemIndex;
    float unitPrice;

    while (true) {
        printf("Enter item index number (1 - 100) (-1 to exit): ");
        scanf("%d", &itemIndex);

        if (itemIndex == -1) {
            break;

        } else if (itemsArray[itemIndex - 1][1] == 0) {
            printf("\tEnter unit price: Rs. ");
            scanf("%f", &unitPrice);

            if (unitPrice > 0) {
                itemsArray[itemIndex - 1][1] = unitPrice;
            } else {
                printf("[error] Unsupported item value Rs. %.2f\n", unitPrice);
                continue;
            }
        } else {
            printf("[error] Index (%d) in use\n", itemIndex);
            continue;
        }
    } 
}

void printItemsFunction () {
    int loopIndex = 0;
    for (loopIndex; loopIndex < 100; loopIndex++) {
        if (itemsArray[loopIndex][1] == 0) {
            printf("(%d).\tno assigned value\n", loopIndex + 1);
        } else {
            printf("(%d).\tRs. %.2f\n", loopIndex + 1, itemsArray[loopIndex][1]);
        }
    }
}

void changeDetailsFunuction () {
    int itemIndex;
    float newValue;

    do {
        printf("Enter item indexing number (1 - 100) (-1 to exit): ");
        scanf("%d", &itemIndex);

        if (itemIndex == -1) {
            return;
        } else if (itemIndex > 0 && itemIndex <= 100) {
            printf("Enter target item (%d) value (replacing Rs. %.2f) Rs. ", itemIndex, itemsArray[itemIndex - 1][1]);
            scanf("%f", &newValue);

            if (newValue > 0) {
                itemsArray[itemIndex - 1][1] = newValue;
            } else {
                printf("[error] Unsupported item value Rs. %.2f\n", newValue);
            }

        } else {
            printf("[error] Unsupported item number (%d)\n", itemIndex);
        }
    } while (true);
}

void deleteItemFunction () {
    int itemIndex;
    float newValue;

    do {
        printf("Enter item indexing number (1 - 100) (-1 to exit): ");
        scanf("%d", &itemIndex);

        if (itemIndex == -1) {
            return;
        } else if (itemIndex > 0 && itemIndex <= 100) {
            printf("Item (%d) is deleted and no value is assigned\n", itemIndex);
            itemsArray[itemIndex - 1][1] = 0;
        } else {
            printf("[error] Unsupported item number (%d)\n", itemIndex);
        }
    } while (true);
}

void createInvoiceFunction () {
    int pieces[100] = {0};
    int itemNumber;
    int loopIndex  = 0;

    printf("Add items to invoice below. Input -1 to exit the process\n");
    for (loopIndex; loopIndex < 100; loopIndex ++) {
        printf("\n\tItem number: ");
        scanf("%d", &itemNumber);

        if (itemNumber == -1) {
            break;
        }

        printf("\t\tRs. %.2f x ", itemsArray[itemNumber - 1][1]);
        scanf("%d", &pieces[itemNumber - 1]);

        if (pieces[itemNumber] == -1) {
            break;
        }
    }

    loopIndex = 0;
    int itemIndex = 0;
    int totalItems = 0;
    float finalTotal = 0;
    float unitTotal = 0;

    printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t%s\n", SHOPNAME);
    printf("\tKurunegala South - 60000\n");
    printf("---------------------------------------------\n");
    printf("#\tUnit\tQuantity\tTotal (Rs)\n");
    for (loopIndex; loopIndex < 100; loopIndex++) {
        if (pieces[loopIndex] != 0) {
            totalItems += pieces[loopIndex];
            itemIndex++;
            unitTotal = itemsArray[loopIndex][1] * pieces[loopIndex];
            finalTotal += unitTotal;

            printf("%d.\t(%d)\t%d\t\t%.2f\n", itemIndex,  loopIndex + 1, pieces[loopIndex], unitTotal);
        }
    }
    printf("---------------------------------------------\n");
    printf("Overall Total\t%d\t\t%.2f\n", totalItems, finalTotal);
    printf("---------------------------------------------\n");
    printf("\tThank you, Come again!\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++\n\n");

    for (loopIndex; loopIndex < 100; loopIndex++) {
        if (pieces[loopIndex] != 0) {
            printf("%d", loopIndex);
        }
    }
}

int main () {
    printf("\tWelcome to %s cashier system!\n", SHOPNAME);
    printf("\nUse one of following functions.\n");
    printAvailableFunctions();
    scanf("%d", &functionIndex);

    while (functionIndex != -1) {
        if (functionIndex > 0 && functionIndex <= 6) {
            switch (functionIndex) {
                case 1: {
                    newItemFunction ();
                    break;
                } case 2: {
                    changeDetailsFunuction ();
                    break;
                } case 3: {
                    deleteItemFunction ();
                    break;
                } case 4: {
                    createInvoiceFunction ();
                    break;
                } case 5: {
                    printItemsFunction ();
                    break;
                } case 6: {
                    return 0;
                }
            }
        } else {
            printf("\n[error] Unsupported index using %d", functionIndex);
        }

        printf("\n\nUse one of following functions.\n");
        printAvailableFunctions();
        scanf("%d", &functionIndex);
    }

    return 0;
}