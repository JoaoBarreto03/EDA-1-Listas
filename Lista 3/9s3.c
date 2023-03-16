#include <stdio.h>

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int stringSize(char* n) {
    int i = 0;
    while (n[i] != '\0') {
        i++;
    }
    return i;
}

int charToInt(char c) {
    return c - 48;
}

int isDivisibleByNine(int n) {
    int rounds = 0;
    int digitSum = n;
    
    while (digitSum > 9) {
       digitSum = sumOfDigits(digitSum);
       rounds+=1;
    }
    
    if (digitSum == 9) {
        return rounds + 1; // +1 because of last degree
    }
    return -1;
}

int isDivisibleByNineChar(char* n) {
    // Creates initial sum and converts it to integer type
    int initialSum = 0;
    
    int size = stringSize(n);
    
    for (int i = 0; i < size; i++) {
        initialSum += charToInt(n[i]);
    }
    
    if (initialSum < 9) {
        return -1;
    }
    
    int isDivisible = isDivisibleByNine(initialSum);
    
    if (isDivisible > 0) {
        return isDivisible;
    }
    
    return -1;
}

int main()
{
    while(1) {
        char number[1001];
        scanf("%s", number);
        
        if (stringSize(number) == 1 && number[0] == '0') {
            break;
        }
        
        int rounds = isDivisibleByNineChar(number);
        if (rounds >= 0) {
            printf("%s is a multiple of 9 and has 9-degree %lld.\n", number, rounds);
        } else {
            printf("%s is not a multiple of 9.\n", number);
        }
    }
    return 0;
}