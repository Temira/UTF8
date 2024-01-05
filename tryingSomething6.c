#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

//int binaryToHex()
//{
//        long int binaryval, hexadecimalval = 0, i = 1, remainder;
//
//        printf("Enter the binary number: ");
//        scanf("%ld", &binaryval);
//
//        //convert input binary number to decimal equivalent
//        while (binaryval != 0)
//        {
//            remainder = binaryval % 10;
//            hexadecimalval = hexadecimalval + remainder * i;
//            i = i * 2;
//            binaryval = binaryval / 10;
//        }
//        printf("dec = %ld", hexadecimalval);
//        printf("Equivalent hexadecimal value: %lX", hexadecimalval);
//        return 0;
//}

//int hexToBinary(const char *hexa)
//{
////    char binarynum[MAX];
////
////
////    long int i = 0;
//    char binarynum[MAX] = {0}; // Initialize array with zeros
//
//    long int i = 0;
//    const char* hexaPointer;
//
//    //printf("\nEnter the value for hexadecimal: ");
//
//    //printf("Equivalent binary value: ");
//
//    //const char *hexaPointer;
//
//    if (hexa[0] == 'U' && hexa[1] == '+'){
//        hexaPointer = hexa + 2;}
//    else {hexaPointer = hexa;}
//
//
//    while (hexaPointer[i]!= '\0')
//    {
//        switch (hexaPointer[i])
//        { //yes, I know it's inefficient but that is ok with me
//            case '0':
//                binarynum[i*5] = '0';
//                binarynum[(i*5)+1] = '0';
//                binarynum[(i*5)+2] = '0';
//                binarynum[(i*5)+3] = '0';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case '1':
//                binarynum[i*5] = '0';
//                binarynum[(i*5)+1] = '0';
//                binarynum[(i*5)+2] = '0';
//                binarynum[(i*5)+3] = '1';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case '2':
//                binarynum[i*5] = '0';
//                binarynum[(i*5)+1] = '0';
//                binarynum[(i*5)+2] = '1';
//                binarynum[(i*5)+3] = '0';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case '3':
//                binarynum[i*5] = '0';
//                binarynum[(i*5)+1] = '0';
//                binarynum[(i*5)+2] = '1';
//                binarynum[(i*5)+3] = '1';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case '4':
//                binarynum[i*5] = '0';
//                binarynum[(i*5)+1] = '1';
//                binarynum[(i*5)+2] = '0';
//                binarynum[(i*5)+3] = '0';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case '5':
//                binarynum[i*5] = '0';
//                binarynum[(i*5)+1] = '1';
//                binarynum[(i*5)+2] = '0';
//                binarynum[(i*5)+3] = '1';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case '6':
//                binarynum[i*5] = '0';
//                binarynum[(i*5)+1] = '1';
//                binarynum[(i*5)+2] = '1';
//                binarynum[(i*5)+3] = '0';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case '7':
//                binarynum[i*5] = '0';
//                binarynum[(i*5)+1] = '1';
//                binarynum[(i*5)+2] = '1';
//                binarynum[(i*5)+3] = '1';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case '8':
//                binarynum[i*5] = '1';
//                binarynum[(i*5)+1] = '0';
//                binarynum[(i*5)+2] = '0';
//                binarynum[(i*5)+3] = '0';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case '9':
//                binarynum[i*5] = '1';
//                binarynum[(i*5)+1] = '0';
//                binarynum[(i*5)+2] = '0';
//                binarynum[(i*5)+3] = '1';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case 'A':
//            case 'a':
//                binarynum[i*5] = '1';
//                binarynum[(i*5)+1] = '0';
//                binarynum[(i*5)+2] = '1';
//                binarynum[(i*5)+3] = '0';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case 'B':
//            case 'b':
//                binarynum[i*5] = '1';
//                binarynum[(i*5)+1] = '0';
//                binarynum[(i*5)+2] = '1';
//                binarynum[(i*5)+3] = '1';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case 'C':
//            case 'c':
//                binarynum[i*5] = '1';
//                binarynum[(i*5)+1] = '1';
//                binarynum[(i*5)+2] = '0';
//                binarynum[(i*5)+3] = '0';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case 'D':
//            case 'd':
//                binarynum[i*5] = '1';
//                binarynum[(i*5)+1] = '1';
//                binarynum[(i*5)+2] = '0';
//                binarynum[(i*5)+3] = '1';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case 'E':
//            case 'e':
//                binarynum[i*5] = '1';
//                binarynum[(i*5)+1] = '1';
//                binarynum[(i*5)+2] = '1';
//                binarynum[(i*5)+3] = '0';
//                binarynum[(i*5)+4] = ' ';
//                break;
//            case 'F':
//            case 'f':
//                binarynum[i*5] = '1';
//                binarynum[(i*5)+1] = '1';
//                binarynum[(i*5)+2] = '1';
//                binarynum[(i*5)+3] = '1';
//                binarynum[(i*5)+4] = ' ';
//                break;
//
//            default:
//                printf("\n Invalid hexadecimal digit %c ", hexa[i]);
//                while (getchar() != '\n');
//                return -1;
//        }
//        i++; }
//    binarynum[i*5-1] = '\0';
//    printf("%s", binarynum);
//    return 0;
//}

//int determineByteLength(const char uni){
//
//    printf("length = %x", binary);
//
//    int binary = hexToBinary(uni);
//
//
//}

//int main() {
//
//        //binaryToHex();
//        hexToBinary("c790");
//        //determineByteLength()
//}