#include <stdio.h>

int main() {
    int choice, n = 0;
    int a[100];

    while (1) {
        printf("\n Menu \n");
        printf("1. Insert\n");
        printf("2. Update (insert at position)\n");
        printf("3. Delete (from position)\n");
        printf("4. Display\n");
        printf("5. Sort\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("How many values you want to insert: ");
                scanf("%d", &n);
                printf("Enter %d values:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                break;
            }

            case 2: {
                int pos, value;
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d %d", &pos, &value);
                if (pos >= 0 && pos <= n) {
                    for (int i = n; i > pos; i--) {
                        a[i] = a[i - 1];
                    }
                    a[pos] = value;
                    n++;
                    printf("Value inserted at position %d.\n", pos);
                } else {
                    printf("Invalid position.\n");
                }
                break;
            }

            case 3: {
                int pos;
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if (pos >= 0 && pos < n) {
                    for (int i = pos; i < n - 1; i++) {
                        a[i] = a[i + 1];
                    }
                    n--;
                    printf("Value deleted from position %d.\n", pos);
                } else {
                    printf("Invalid position.\n");
                }
                break;
            }

            case 4: {
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", a[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 5: {
                int temp, ch;
                printf("1. Ascending\n2. Descending\nEnter sort order: ");
                scanf("%d", &ch);
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if ((ch == 1 && a[i] > a[j]) || (ch == 2 && a[i] < a[j])) {
                            temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        }
                    }
                }
                printf("Array sorted.\n");
                break;
            }

            case 6: {
                int val, found = 0;
                printf("Enter value to search: ");
                scanf("%d", &val);
                for (int i = 0; i < n; i++) {
                    if (a[i] == val) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("Value found.\n");
                } else {
                    printf("Value not found.\n");
                }
                break;
            }

            case 7: {
                printf("Exiting program.\n");
                return 0;
            }

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}




