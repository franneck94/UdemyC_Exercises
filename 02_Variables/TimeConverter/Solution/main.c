#include <stdio.h>

int main()
{
    float millisconds = 0.0F;

    printf("Please enter a millisecond value: ");
    scanf("%f", &millisconds);

    float seconds = millisconds / 1000.0F;
    float minutes = seconds / 60.0F;
    float hours = minutes / 60.0F;
    float days = hours / 24.0F;

    printf("seconds: %.16f\n", seconds);
    printf("minutes: %.16f\n", minutes);
    printf("hours: %.16f\n", hours);
    printf("days: %.16f\n", days);

    return 0;
}
