#include <stdio.h>
#include <stdlib.h>

/*
Problem description:
Find the max sub sum in the arr that each element doesn't neighbor each other.
Elements in the array are not less than 0.
*/

int max_sub_sum(int* arr, int len){
    if(len<0)
    {
        printf("error: array length is less than 0!\n");
        return -1;
    }
    int result = 0;
    /*
    dp[i]: max sub sum that includes the element i
    */
    int* dp = (int*)malloc(sizeof(*dp)*len);

    /*
    np[i]: max sub sum that excludes the element i
    */
    int* np = (int*)malloc(sizeof(*np)*len);

    /*
    This is a dp problem.
    If we use arr[i] to get the result, then we cannot use arr[i-1].
    so we get:
    dp[i] = np[i-1]+arr[i]

    If we don't use arr[i] to get the result, then we the ith max sub sum
    equals the (i-1)th max sub sum, for we don't care about whether it includes
    arr[i].
    so we get:
    np[i] = max(dp[i-1], np[i-1])

    Time complexity is O(n).
    */
    dp[0] = arr[0];
    np[0] = 0;

    int i=0;
    for(i=1; i<len; i++){
        dp[i] = np[i-1] + arr[i];
        np[i] = dp[i-1]>np[i-1] ? dp[i-1] : np[i-1];

    }

    result = dp[len-1]>np[len-1] ? dp[len-1] : np[len-1];

    free(dp);
    free(np);
    return result;
}

int main()
{
    int arr[8] = {1, 7, 4, 0, 9, 4, 8, 8};
    int result = max_sub_sum(arr, 8);

    printf("result: %d\n", result);


    return 0;
}
