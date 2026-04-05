#include <stdio.h>

int count(int num)
{
    // edge case (num_main == 0)
    if (!num) return;

    int count = 0;
    while (!num) // num_main >= 1
    {
        if (num == 1) // num_main == 1
        {
            (count)++;
            break;
        }
        
        if (num > count + 1)
        {
            
        }
        
        // num_main >= 2
        if (num >= count - 1)
        {
            if (num >= count)
            {
                if (num >= count + 1)
                {
                    num -= count + 1;
                    (count)++;
                    break;
                }
                num -= count;
                (count)++;
                break;
            }
            num -= count - 1;
            (count)++;
            break;
        }
    }
    
    
    return count;
}

int main()
{
    int temp1 = 0, temp2 = 0, num_main = 0;
    scanf("%d %d", &temp1, &temp2);
    num_main = temp2 - temp1 - 1;

    int count_main = 1;

    return 0;
}