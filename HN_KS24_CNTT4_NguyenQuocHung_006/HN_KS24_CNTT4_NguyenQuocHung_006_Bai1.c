#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Project {
    int id;
    char title[50];
    int owner[100];
    int priority;
} Project;
typedef struct SingLeNode {
    Project data;
    struct SingLeNode *next;
} SingLeNode;
typedef struct DoubleNode {
    Project data;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;
SingLeNode *head = NULL;
DoubleNode *completedHead=NULL,*completedTail=NULL;
int generateID() {
    static int id =1;
    return id++;
}
void addProject() {
    SingLeNode *newNode = (SingLeNode *)malloc(sizeof(SingLeNode));
    newNode->data.id = generateID();
    printf("Nhap ten du an: ");
    fflush(stdin);
    gets(newNode->data.title);
    printf("Nhap ten nguoi quan ly: ");
    gets(newNode->data.owner);
    printf("Nhap do uu tien: ");
    scanf("%d", &newNode->data.priority);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }else {
        SingLeNode *temp= head;
        while (temp->next) {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Them du an thanh cong\n");
}
void displayProject() {
    if (!head) {
        printf("Danh sach rong.\n");
        return;
    }
    SingLeNode *temp = head;
    printf("danh sach du an\n");
    while (temp) {
        printf("ID: %d | Ten: %s | Quan ly: %s | Uu tien: %d\n",
            temp->data.id, temp->data.title, temp->data.owner, temp->data.priority);
        temp = temp->next;
    }
}
void deleteProject() {
    int id;
    printf("Nhap id du an can xoa: ");
    scanf("%d", &id);
    SingLeNode *temp = head, *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp=temp->next;
    }
    if (!temp) {
        printf("Khong tim thay du an\n");
        return;
    }
    if (!prev) {
        head = temp->next;
    }else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Da xoa du an\n");
}
void updateProject() {
    int id;
    printf("Nhap ID du an can cap nhap:");
    scanf("%d", &id);
    SingLeNode *temp = head;
    while (temp && temp->data.id != id) {
        temp = temp->next;
    }
    if (!temp) {
        printf("Khong tim thay du an");
        return;
    }
    printf("Nhap ten du an moi: ");
    fflush(stdin);
    gets(temp->data.title);
    printf("Nhap ten nguoi quan ly: ");
    scanf("%d", &temp->data.owner);
    printf("Nhap do uu tien moi: ");
    scanf("%d", &temp->data.priority);
    printf("Cap nhat thanh cong\n");
}
void tickProject() {
    int id;
    printf("Nhap id du an da hoan thanh: ");
    scanf("%d", &id);
    SingLeNode *temp = head, *prev = NULL;
    while (temp&& temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Khong tim thay du an\n");
        return;
    }
    if (!prev) {
        head = temp->next;
    }else {
        prev->next= temp->next;
    }
    DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
    newNode->data=temp->data;
    newNode->prev=completedTail;
    newNode->next=NULL;
    if (completedTail) {
        completedTail->next=newNode;
    }else {
        completedTail=newNode;
    }
    completedTail=newNode;
    free(temp);
    printf("Du an da duoc danh dau hoan thanh\n");
}
void sortProject() {
    if (!head || !head->next) return;
    for (SingLeNode *i = head; i; i = i->next) {
        for (SingLeNode *j = head;j;j=j->next) {
            if (i->data.priority>j->data.priority) {
                Project temp = i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
    printf("Da sap xep du an theo do uu tien\n");
}
void searchProject() {
    char name[100];
    printf("Nhap ten du an can tim: ");
    fflush(stdin);
    gets(name);
    SingLeNode *temp=head;
    while (temp) {
        if (strcmp(temp->data.title,name)==0) {
            printf("Tim thay: ID: %d | Ten: %s | Quan ly: %s | Uu tien: %d\n",
                temp->data.id,temp->data.owner,temp->data.priority);
            return;
        }
        temp= temp->next;
    }
    printf("Khong tim thay du an\n");
}
int main() {
    int choice;
    do {
        printf("1. Them moi du an\n");
        printf("2. Hien thi danh sach du an ca nhan\n");
        printf("3. Xoa du an\n");
        printf("4. Cap nhat thong tin du an\n");
        printf("5. Danh dau du an da hoan thanh\n");
        printf("6. Sap xep du an theo do uu tien\n");
        printf("7. Tim kiem du an theo ten\n");
        printf("8. Thoat chuong trinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProject();
                break;
            case 2: displayProject();
                break;
            case 3: deleteProject();
                break;
            case 4: updateProject();
                break;
            case 5: tickProject();
                break;
            case 6: sortProject();
                break;
            case 7: searchProject();
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    }while (choice != 8);
    return 0;
}