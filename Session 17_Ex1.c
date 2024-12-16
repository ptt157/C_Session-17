#include <stdio.h>

#define MAX_SIZE 100  // Kich thuoc toi da cua mang

// Ham nhap mang
void nhap_mang(int arr[], int *size) {
    printf("Nhap so phan tu: ");
    scanf("%d", size);
    
    // Dam bao khong vuot qua kich thuoc toi da cua mang
    if (*size > MAX_SIZE) {
        printf("So phan tu qua lon, gioi han toi da la %d.\n", MAX_SIZE);
        *size = MAX_SIZE;
    }
    
    // Nhap cac phan tu vao mang
    for (int i = 0; i < *size; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);  // Nhap phan tu vao mang
    }
}

// Ham hien thi mang
void hien_thi_mang(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham tinh tong cac phan tu trong mang
int tinh_tong(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Ham tim phan tu lon nhat trong mang
int tim_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[MAX_SIZE];  // Mang co dinh
    int size = 0;
    int choice;
    
    while (1) {
        // Hien thi menu
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh tong cac phan tu trong mang\n");
        printf("4. Tim phan tu lon nhat\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                nhap_mang(arr, &size);
                break;
            case 2:
                if (size > 0) {
                    hien_thi_mang(arr, size);
                } else {
                    printf("Mang chua duoc nhap!\n");
                }
                break;
            case 3:
                if (size > 0) {
                    printf("Tong cac phan tu: %d\n", tinh_tong(arr, size));
                } else {
                    printf("Mang chua duoc nhap!\n");
                }
                break;
            case 4:
                if (size > 0) {
                    printf("Phan tu lon nhat: %d\n", tim_max(arr, size));
                } else {
                    printf("Mang chua duoc nhap!\n");
                }
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }
}

