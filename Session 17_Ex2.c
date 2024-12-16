#include <stdio.h>
#include <ctype.h>  // De su dung ham isalpha, isdigit

// Ham nhap chuoi
void nhap_chuoi(char **str) {
    printf("Nhap vao chuoi: ");
    *str = (char*)malloc(100 * sizeof(char));  // Cap phat bo nho dong
    fgets(*str, 100, stdin);  // Doc chuoi, bao gom khoang trang
    // Xoa ky tu '\n' neu co tu fgets
    size_t len = strlen(*str);
    if ((*str)[len - 1] == '\n') {
        (*str)[len - 1] = '\0';
    }
}

// Ham in chuoi
void in_chuoi(char *str) {
    printf("Chuoi nhap vao: %s\n", str);
}

// Ham dem so luong chu cai trong chuoi
int dem_chu_cai(char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

// Ham dem so luong chu so trong chuoi
int dem_chu_so(char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

// Ham dem so luong ky tu dac biet trong chuoi
int dem_ky_tu_dac_biet(char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {  // Ky tu khong phai chu cai va khong phai chu so
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char *chuoi = NULL;
    int choice;
    
    while (1) {
        // Hien thi menu
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();  // Doc ky tu '\n' con sot lai sau khi nhap so
        
        switch (choice) {
            case 1:
                nhap_chuoi(&chuoi);
                break;
            case 2:
                if (chuoi != NULL) {
                    in_chuoi(chuoi);
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            case 3:
                if (chuoi != NULL) {
                    printf("So luong chu cai trong chuoi: %d\n", dem_chu_cai(chuoi));
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            case 4:
                if (chuoi != NULL) {
                    printf("So luong chu so trong chuoi: %d\n", dem_chu_so(chuoi));
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            case 5:
                if (chuoi != NULL) {
                    printf("So luong ky tu dac biet trong chuoi: %d\n", dem_ky_tu_dac_biet(chuoi));
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            case 6:
                free(chuoi);  // Giai phong bo nho
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }
}

