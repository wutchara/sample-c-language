#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lower, upper;
    printf("Welcome to the guessing game\n");
    printf("Please enter the range of this game: [lower, upper]\n");
    printf("lower:");
    scanf("%d", &lower);
    printf("upper:");
    scanf("%d", &upper);
    printf("the range [lower,upper] is [%d, %d]\n", lower, upper);

    if (lower >= upper)
    {
        printf("'lower' must be greather than 'upper', %d(lower), %d(upper)\n", lower, upper);
    }
    else
    {
        // Let's play the game
        int target = (rand() % (upper - lower + 1)) + lower;
        int isFinished = 0;
        printf("\n=>>> %d <<<=\n", target);

        int tempLower = lower, tempUpper = upper;
        do
        {
            printf("Please select the number\n");
            int i;
            for (i = tempLower; i <= tempUpper; i++)
            {
                printf("%d\t", i);
            }
            int selected;
            printf("\nYou select:");
            scanf("%d", &selected);

            // Check error
            if (selected > upper || selected < lower)
            {
                printf("Please select the right number: [%d, %d]\n", lower, upper);
            }
            else
            {
                printf("---------------------------------------\n");
                if (selected > target)
                {
                    printf("My number is lower than %d, Guess lower <=\n", selected);
                    tempUpper = selected - 1;
                }
                else if (selected < target)
                {
                    printf("My number is upper than %d, Guess upper =>\n", selected);
                    tempLower = selected + 1;
                }
                else
                {
                    printf("Yes, your are lucky, My number is %d.\n", selected);
                    printf(">>>>>>>>>> This Game is finished <<<<<<<<<<\n");
                    isFinished = 1;
                }
                printf("---------------------------------------\n");
            }
        } while (isFinished == 0);
    }
    return 0;
}