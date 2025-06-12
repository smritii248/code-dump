
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void dectobinary(int nbit, int num, int arry[]) {
for (int i = nbit - 1; i >= 0; i--) {
arry[i] = num % 2;
num /= 2;
}
}

void twoComplement(int arry[], int nbit) {
int carry = 1;
for (int i = 0; i < nbit; i++) {
arry[i] = !arry[i];
}

for (int i = nbit - 1; i >= 0; i--) {
int bitsum = arry[i] + carry;
arry[i] = bitsum % 2;
carry = bitsum / 2;
}
}

void showbinary(int *p, int size) {
for (int i = 0; i < size; i++) {
printf("%d", *(p + i));
}
printf("\n");
}

int addbinary(int arry1[], int arry2[], int nbit, int sum[]) {
int carry = 0;
for (int i = nbit - 1; i >= 0; i--) {
int bitsum = arry1[i] + arry2[i] + carry;
sum[i] = bitsum % 2;
carry = bitsum / 2;
}
return carry;
}

void binarytodec(int arry[], int nbit, int isSubtraction) {
int result = 0;
if (isSubtraction && arry[0] == 1) {
int temp[10];
for (int i = 0; i < nbit; i++) {
temp[i] = arry[i];
}
twoComplement(temp, nbit);
for (int i = 0; i < nbit; i++) {
result += temp[i] * pow(2, (nbit - 1 - i));
}
result = -result;
} else {
for (int i = 0; i < nbit; i++) {
result += arry[i] * pow(2, (nbit - 1 - i));
}
}

printf("The decimal equivalent is %d", result);
}

int main() {
int num1, num2, arry1[10] = {0}, arry2[10] = {0}, sum[10] = {0}, nbit, status;
printf("Enter number of bits: ");
scanf("%d", &nbit);
printf("Enter the two number: ");
scanf("%d %d", &num1, &num2);

int isSubtraction = (num1 < 0 || num2 < 0);

if (num1 < 0) {
dectobinary(nbit, abs(num1), arry1);
twoComplement(arry1, nbit);
} else {
dectobinary(nbit, num1, arry1);
}

if (num2 < 0) {
dectobinary(nbit, abs(num2), arry2);
twoComplement(arry2, nbit);
} else {
dectobinary(nbit, num2, arry2);
}

printf("Binary of %d: ",num1);
showbinary(arry1, nbit);
printf("Binary of %d: ",num2);
showbinary(arry2, nbit);

status = addbinary(arry1, arry2, nbit, sum);
printf("The sum is: ");
showbinary(sum, nbit);

if (status == 1 & !isSubtraction) {
printf("with carry overflow of 1\n");
}

binarytodec(sum, nbit, isSubtraction);

return 0;
}



