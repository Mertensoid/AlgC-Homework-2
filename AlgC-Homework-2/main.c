//
//  main.c
//  AlgC-Homework-2
//
//  Created by admin on 05.07.2022.
//

#include <stdio.h>

void solution1();
//void solution2();
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
//        case 2:
//            solution2();
//            break;
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
    printf("%d", binaryNum);
    
}
