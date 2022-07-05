//
//  main.c
//  AlgC-Homework-2
//
//  Created by admin on 05.07.2022.
//

#include <stdio.h>

void solution1();
void solution2();
//void solution3();
void menu();

int main(int argc, const char * argv[]) {
    menu();
    return 0;
}

void menu() {
    int solutionNumber;
    printf("Choose solution (1..3):\n");
    scanf("%d", &solutionNumber);
    switch (solutionNumber) {
        case 1:
            solution1();
            break;
        case 2:
            solution2();
            break;
//        case 3:
//            solution3();
//            break;
        default:
            printf("Wrong solution number!");
            break;
    }
}

int toBinary(int decimalNum) {
    if (decimalNum == 1) {
        return decimalNum % 2;
    } else {
        int binaryNum = 10 * toBinary(decimalNum / 2) + decimalNum % 2;
        return binaryNum;
    }
}

void solution1() {
    printf("Solution 1:\n");
    
    int decimalNum;
    printf("Input decimal number: \n");
    scanf("%d", &decimalNum);
    int binaryNum = toBinary(decimalNum);
    printf("Binary - %d\n", binaryNum);
}

int recursionDegree(int result, int degree) {
    if (degree > 1) {
        return result * recursionDegree(result, degree - 1);
    } else {
        return result;
    }
}

void solution2() {
    printf("Solution 2:\n");
    
    int methodNumber;
    printf("Choose method (1..3):\n");
    printf("1 - without recusion\n");
    printf("2 - with recusion\n");
    printf("3 - with recusion and even degree property\n");
    scanf("%d", &methodNumber);
    
    int number;
    printf("Input number:\n");
    scanf("%d", &number);
    int degree;
    printf("Input degree:\n");
    scanf("%d", &degree);
    int result = 1;
    
    switch (methodNumber) {
        case 1:
            while (degree > 0) {
                result *= number;
                degree--;
            }
            break;
        case 2:
            result = recursionDegree(number, degree);
            break;
        case 3:
            
            break;
        default:
            break;
    }
    
    printf("Result - %d\n", result);
}
