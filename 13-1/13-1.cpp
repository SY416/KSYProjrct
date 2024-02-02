#include <iostream>

int main()
{
    int arr[5] = { 1,2,3,4,5 };

    int arr2[6] = { 1,2,3,4,5,6 };

    int* ptr = arr2;
    int* ptr2 = arr2 + 5;

    int a;

    int result = 0;
    /*for (int i = 0; i < 5; i++) {
        *ptr += 2;
        ptr++;
    }*/

    /*for (int i = 0; i < 5; i++) {
        *(ptr+i) += 2;
        
    }*/

    /*for (int i = 0; i < 5; i++) {
        result += *ptr2;
        ptr2--;

    }*/

    for (int i = 0; i < 3; i++)
    {
        a = *ptr;
        *ptr = *ptr2;
        *ptr2 = a;

        ptr++;
        ptr2--;
    }

    //printf("%d  ", result);


    for (int i = 0; i < 6; i++) {
        printf("%d  ", arr2[i]);
    }
    
    return 0;
}

