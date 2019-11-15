# include <stdio.h>
# include <math.h>

int time2minutes(float times);
float mintets2time(float minutes);

int main() {

char operator;
float firstNumber,secondNumber;


printf("Enter operation: ");
scanf("%f %s %f",&firstNumber, &operator, &secondNumber);

int time_in_minutes;

switch(operator)
    {
        case '+':
          time_in_minutes = time2minutes(firstNumber) + time2minutes(secondNumber);
          printf("%0.2f + %0.2f = %0.2f \n", firstNumber, secondNumber, mintets2time(time_in_minutes));
          break;

        case '-':
            time_in_minutes = time2minutes(firstNumber) - time2minutes(secondNumber);
            printf("%0.2f - %0.2f = %0.2f\n",firstNumber, secondNumber, mintets2time(time_in_minutes));
            break;

        case '*':
            time_in_minutes = time2minutes(firstNumber) * secondNumber;
            printf("%0.2f * %0.2f = %0.2f\n",firstNumber, secondNumber, mintets2time(time_in_minutes));
            break;

        case '/':
            time_in_minutes = time2minutes(firstNumber) / secondNumber;
            printf("%0.2f / %0.2f = %0.2f\n",firstNumber, secondNumber, mintets2time(time_in_minutes));
            break;

        // operator doesn't match any case constant (+, -, *, /)
        default:
            printf("Error! operator is not correct");
    }

return 0;
}

int time2minutes(float number)
{
    int hours = number;
    int minutes = (number - hours)*100 + hours*60;
    //printf("%i \n", minutes);
    return minutes;
}

float mintets2time(float min)
{
    int hours = min/60;
    int minutes = min - hours*60;
    float times = (float)hours + (float)minutes/100;
    //printf("result: %f \n", times);
    return times;
}



