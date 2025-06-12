#include <stdio.h>
#include <conio.h>

// Function to perform binary addition
int binaryAddition(int a, int b) {
    int carry = 0, result = 0, bit = 1;
    while (a != 0 || b != 0 || carry != 0) {
        int bit_a = a % 10;
        int bit_b = b % 10;

        int sum = bit_a + bit_b + carry;
        result += (sum % 2) * bit;
        carry = sum / 2;

        a /= 10;
        b /= 10;
        bit *= 10;
    }
    return result;
}

// Logical Shift Left (multiply by 10 for binary in decimal)
int logicalShiftLeft(int num) {
    return num * 10;
}

// Function to perform binary multiplication (not Booth's, but correct for positive binary)
int binaryMultiply(int multiplicand, int multiplier) {
    int result = 0;
    int shift = 0;

    while (multiplier != 0) {
        int lsb = multiplier % 10;

        if (lsb == 1) {
            int shiftedMultiplicand = multiplicand;
            for (int i = 0; i < shift; i++) {
                shiftedMultiplicand = logicalShiftLeft(shiftedMultiplicand);
            }
            result = binaryAddition(result, shiftedMultiplicand);
        }

        multiplier /= 10;
        shift++;
    }

    return result;
}

// Convert binary to decimal
int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary != 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

int main() {
    int multiplicand, multiplier;
    printf("Enter the multiplicand (binary): ");
    scanf("%d", &multiplicand);
    printf("Enter the multiplier (binary): ");
    scanf("%d", &multiplier);

    int product = binaryMultiply(multiplicand, multiplier);

    printf("Product (binary): %d\n", product);
    printf("Product (decimal): %d\n", binaryToDecimal(product));

    getch();
    return 0;
}






























