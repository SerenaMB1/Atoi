#include <stdio.h>
#include <stdlib.h>

int myAtoi(char* s, int* error)
{
    int index = 0;
    int value = 0;
    int sign = 1;

    // Find the index of the first non-white space
    while (s[index] == ' ' || s[index] == '\t')
    {
        index += 1;
    }
    //If it's NOT a number or a minus sign return an error
    if (!(s[index] >= '0' && s[index] <= '9') && s[index] != '-')
    {
        *error = 1;
        //Return 0 on failure.
        return(0);
    }
    // if a character within the string uses a minus, the sign and counter will be updated
    if (s[index] == '-')
    {
        sign = -1;
        index += 1;
    }
    //Hexadecimal
    //if the string begins with 0x it will be treated as a hex value
    if (s[index] == '0' && s[index + 1] == 'x')
    {
        //Move the index to the start of the hex value
        index = index + 2;
        //While there are characters in the string the loop will continue
        while (s[index] != '\0')
        {
            //if the character is not between the range values it will return an error
            if (!(s[index] >= '0' && s[index] <= '9') && !((s[index] >= 'a' &&  s[index] <= 'f')))
            {
                if (s[index - 1] == 'x')
                {
                    *error = 1;
                    //Return 0 on failure.
                    return(0);
                }
                break;
            }
            else
            {
                //if its a number, calculate the decimal value
                if (s[index] >= '0' && s[index] <= '9')
                {
                     //Multiplying by the base moves everything one place to the left.
                    value = value * 16 + (s[index] - 48);
                }
                //if its a valid letter, calculate the decimal value
                else
                {
                    //Multiplying by the base moves everything one place to the left.
                    value = value * 16 + (s[index] - 87);
                }
            }
            // Increment to next char
            index += 1;
        }
        //Update the sign
        value = value * sign;
        //Return a value on success.
        return(value);
    }
    //Decimal
    else
    {
        //loop until end of string
        while (s[index] != '\0')
        {
            //if the character is not between the range values it will return an error
            if (!(s[index] >= '0' && s[index] <= '9'))
            {
                break;
            }
            else
            {
                //Multiplying by the base moves everything one place to the left.
                value = value * 10 + (s[index] - 48);
            }
            // Increment to next char
            index += 1;
        }
        value = value * sign;
        //Return a value on success.
        return(value);
    }
}

int main()
{
    char str[] = "0aaa";
    int value = 0;
    int error = 0;

    value = myAtoi(str, &error);
    printf("Input: %s, Error: %d, Output: %d\n", str, error, value);

    return 0;
}
