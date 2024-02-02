// 2-5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void DesSort(int arr[], int len)
{
    int temp;
    for(int i=0; i<len-1;i++)
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}

int main()
{
    int arr[7];
    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < 7; i++) {
        printf("입력");
        scanf_s("%d", &arr[i]);
    }

    DesSort(arr, len);

    for (int j = 0; j < len; j++)
        printf("%d ", arr[j]);

    return 0;
}
