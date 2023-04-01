#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{  int i, num1, num2, studAnsw, score = 0;

   srand(time(NULL));


   for (i = 1; i <= 4; i++ ) {
    num1 = 1 + rand() % 99;
    num2 = 1 + rand() % 99;
    printf("%d + %d = ", num1, num2);
    scanf("%d", &studAnsw);
    if (studAnsw == (num1 + num2)) score++;
   }

   switch (score) {
    case 0: printf("The score is: %c", 'E'); break;
    case 1: printf("The score is: %c", 'D'); break;
    case 2: printf("The score is: %c", 'C'); break;
    case 3: printf("The score is: %c", 'B'); break;
    case 4: printf("The score is: %c", 'A'); break;
   }

    return 0;
}
