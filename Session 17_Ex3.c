#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int count_words(char *str) {
    int count = 0;
    char *token = strtok(str, " \t\n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    return count;
}

void to_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char str[100], str2[100];
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Nhap vao chuoi: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // Remove newline character if exists
                break;
            case 2:
                reverse_string(str);
                printf("Chuoi dao nguoc: %s\n", str);
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", count_words(str));
                break;
            case 4:
                printf("Nhap vao chuoi khac: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; // Remove newline character if exists
                if (strlen(str2) < strlen(str)) {
                    printf("Chuoi ban dau ngan hon chuoi khac\n");
                } else if (strlen(str2) > strlen(str)) {
                    printf("Chuoi ban dau dai hon chuoi khac\n");
                } else {
                    printf("Hai chuoi co do dai bang nhau\n");
                }
                break;
            case 5:
                to_uppercase(str);
                printf("Chuoi in hoa: %s\n", str);
                break;
            case 6:
                printf("Nhap vao chuoi khac de them vao chuoi ban dau: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; // Remove newline character if exists
                strcat(str, str2);
                printf("Chuoi sau khi them: %s\n", str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

