//
// Created by sansan on 25-9-26.
// 把顺序表中所有的奇数移动到前面,偶数移动到后面
//

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void move_number(int a[], int n) {
    int left = 0, right = n - 1;

    while (left<right) {
        while (left<right&&a[left]%2==1)
            left++;
        while (left<right&&a[right]%2==0)
            right--;

        if (left<right) {
            swap(&a[left],&a[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr,n);
    move_number(arr,n);
    print_array(arr,n);

    return 0;
}
