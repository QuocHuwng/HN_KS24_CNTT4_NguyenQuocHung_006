#include <stdio.h>
#include <stdlib.h>
int main() {
    int choice;
    do {
        printf("1. Copy\n");
        printf("2. Paste\n");
        printf("3. Undo\n");
        printf("4. Redo\n");
        printf("5. Hien Thi\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Thoat");
                break;
            default:
                printf("Lua chon khong hop le");
        }

    }while (choice != 6);
    return 0;
}