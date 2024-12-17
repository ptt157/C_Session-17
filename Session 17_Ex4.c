#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void reverse_array(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void sort_array(int *arr, int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, choice, search, found;
    int *arr;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap vao so phan tu: ");
                scanf("%d", &n);
                arr = (int *)malloc(n * sizeof(int));
                printf("Nhap vao cac phan tu:\n");
                for (int i = 0; i < n; i++) {
                    printf("Phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                printf("Cac phan tu la so chan:\n");
                for (int i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            case 3:
                printf("Cac phan tu la so nguyen to:\n");
                for (int i = 0; i < n; i++) {
                    if (is_prime(arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            case 4:
                reverse_array(arr, n);
                printf("Mang sau khi dao nguoc:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 5:
                printf("Chon 1. Tang dan  2. Giam dan: ");
                int sort_choice;
                scanf("%d", &sort_choice);
                if (sort_choice == 1) {
                    sort_array(arr, n, true);
                    printf("Mang sau khi sap xep tang dan:\n");
                } else if (sort_choice == 2) {
                    sort_array(arr, n, false);
                    printf("Mang sau khi sap xep giam dan:\n");
                } else {
                    printf("Lua chon khong hop le.\n");
                    break;
                }
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 6:
                printf("Nhap vao phan tu can tim: ");
                scanf("%d", &search);
                found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == search) {
                        printf("Phan tu %d duoc tim thay tai vi tri %d\n", search, i + 1);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Phan tu %d khong co trong mang.\n", search);
                }
                break;
            case 7:
                free(arr);
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

