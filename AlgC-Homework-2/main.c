//
//  main.c
//  AlgC-Homework-2
//
//  Created by admin on 05.07.2022.
//

#include <stdio.h>

void solution1();
void solution2();
void solution3();
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
        case 3:
            solution3();
            break;
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

int noRecursionDegree(int number, int degree) {
    int result = 1;
    while (degree > 0) {
        result *= number;
        degree--;
    }
    return result;
}

int recursionDegree(int result, int degree) {
    if (degree > 1) {
        return result * recursionDegree(result, degree - 1);
    } else {
        return result;
    }
}

int recursionDegreeWithDivision(int result, int degree) {
    if (degree > 1) {
        if (degree % 2 == 0) {
            return recursionDegree(result, degree / 2) * recursionDegree(result, degree / 2);
        } else {
            return result * recursionDegree(result, degree - 1);
        }
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
            result = noRecursionDegree(number, degree);
            break;
        case 2:
            result = recursionDegree(number, degree);
            break;
        case 3:
            result = recursionDegreeWithDivision(number, degree);
            break;
        default:
            break;
    }
    
    printf("Result - %d\n", result);
}

int doSomething(int startNumber, int endNumber) {
    if (startNumber == endNumber) {
        return 1;
    } else if (startNumber > endNumber) {
        return 0;
    } else {
        return doSomething(startNumber + 1, endNumber) + doSomething(startNumber * 2, endNumber);
    }
}

void solution3() {
    printf("Solution 3:\n");
    
    int startNumber = 3;
    int endNumber = 20;
    printf("Start number - %d\n", startNumber);
    printf("End number - %d\n", endNumber);
    
    int result = doSomething(startNumber, endNumber);
    printf("Number of programs - %d\n", result);
}
