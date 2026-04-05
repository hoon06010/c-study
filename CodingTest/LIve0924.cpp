#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for qsort to sort characters
int compareChars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    char myString[] = "programming"; // The string to be sorted
    char word[2] = {0,};
    int arr[2] = {1, 0};
    int Length = 0;
    int check = 0;

    printf("Original string: %s\n", myString);
    Length = strlen(myString);

    // Sort the string using qsort
    // Arguments:
    // 1. Pointer to the array (myString)
    // 2. Number of elements in the array (strlen(myString))
    // 3. Size of each element (sizeof(char))
    // 4. Pointer to the comparison function (compareChars)
    qsort(myString, Length, sizeof(char), compareChars);

    printf("Sorted string: %s\n", myString);

    word[0] = myString[0];
    
    for (int i = 1; i < Length; i++)
    {
        word[1] = myString[i];
        if (word[0] == word[1])
        {
            if (!check) //check == 0
            {
                arr[0]++;
            }
            else // check == 1
            {
                arr[1]++;
            }
        }
        else
        {
            if (!check)
            {
                
            }
            else
            {
                
            }
        }
        
        
    }
    

    return 0;
}
