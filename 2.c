//#include <stdio.h>
//#define MAX 1000000
//
//int binaryToDecimal(const char* binary);
//
//// Function to check if a byte is the start of a UTF-8 character
//int isUtf8_StartByte(unsigned char byte) {
//    return (byte & 0xC0) != 0x80;
//}
//
//// Function to check if a byte is a continuation byte in a UTF-8 character
//int isUtf8_ContinuationByte(unsigned char byte) {
//    return (byte & 0xC0) == 0x80;
//}
//
//int hexToBinary(const char *hexa, char *binarynum){
//    long int i = 0;
//    const char* hexaPointer;
//    printf("%c", hexa[0]);
//
//    if (hexa[0] == '\\' && hexa[1] == 'u') {
//        printf("\nUh oh: %c, %c", hexa[0], hexa[1]);
//        hexaPointer = hexa + 2;
//        printf("\npointer %c\n", *hexaPointer);
//    } else {
//        hexaPointer = hexa;
//        printf("\npointer %c\n", *hexaPointer);
//    }
//
//    while (hexaPointer[i]!= '\0') {
//        switch (hexaPointer[i])
//        { //yes, I know it's inefficient but that is ok with me
//            case '0':
//                binarynum[i*4] = '0';
//                binarynum[(i*4)+1] = '0';
//                binarynum[(i*4)+2] = '0';
//                binarynum[(i*4)+3] = '0';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case '1':
//                binarynum[i*4] = '0';
//                binarynum[(i*4)+1] = '0';
//                binarynum[(i*4)+2] = '0';
//                binarynum[(i*4)+3] = '1';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case '2':
//                binarynum[i*4] = '0';
//                binarynum[(i*4)+1] = '0';
//                binarynum[(i*4)+2] = '1';
//                binarynum[(i*4)+3] = '0';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case '3':
//                binarynum[i*4] = '0';
//                binarynum[(i*4)+1] = '0';
//                binarynum[(i*4)+2] = '1';
//                binarynum[(i*4)+3] = '1';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case '4':
//                binarynum[i*4] = '0';
//                binarynum[(i*4)+1] = '1';
//                binarynum[(i*4)+2] = '0';
//                binarynum[(i*4)+3] = '0';
//                //binarynum[(i*5)+4] = ' ';
//                //printf("44444");
//                break;
//            case '5':
//                binarynum[i*4] = '0';
//                binarynum[(i*4)+1] = '1';
//                binarynum[(i*4)+2] = '0';
//                binarynum[(i*4)+3] = '1';
//                //binarynum[(i*5)+4] = ' ';
//                //printf("55555");
//                break;
//            case '6':
//                binarynum[i*4] = '0';
//                binarynum[(i*4)+1] = '1';
//                binarynum[(i*4)+2] = '1';
//                binarynum[(i*4)+3] = '0';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case '7':
//                binarynum[i*4] = '0';
//                binarynum[(i*4)+1] = '1';
//                binarynum[(i*4)+2] = '1';
//                binarynum[(i*4)+3] = '1';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case '8':
//                binarynum[i*4] = '1';
//                binarynum[(i*4)+1] = '0';
//                binarynum[(i*4)+2] = '0';
//                binarynum[(i*4)+3] = '0';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case '9':
//                binarynum[i*4] = '1';
//                binarynum[(i*4)+1] = '0';
//                binarynum[(i*4)+2] = '0';
//                binarynum[(i*4)+3] = '1';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case 'A':
//            case 'a':
//                binarynum[i*4] = '1';
//                binarynum[(i*4)+1] = '0';
//                binarynum[(i*4)+2] = '1';
//                binarynum[(i*4)+3] = '0';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case 'B':
//            case 'b':
//                binarynum[i*4] = '1';
//                binarynum[(i*4)+1] = '0';
//                binarynum[(i*4)+2] = '1';
//                binarynum[(i*4)+3] = '1';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case 'C':
//            case 'c':
//                binarynum[i*4] = '1';
//                binarynum[(i*4)+1] = '1';
//                binarynum[(i*4)+2] = '0';
//                binarynum[(i*4)+3] = '0';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case 'D':
//            case 'd':
//                binarynum[i*4] = '1';
//                binarynum[(i*4)+1] = '1';
//                binarynum[(i*4)+2] = '0';
//                binarynum[(i*4)+3] = '1';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case 'E':
//            case 'e':
//                binarynum[i*4] = '1';
//                binarynum[(i*4)+1] = '1';
//                binarynum[(i*4)+2] = '1';
//                binarynum[(i*4)+3] = '0';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            case 'F':
//            case 'f':
//                binarynum[i*4] = '1';
//                binarynum[(i*4)+1] = '1';
//                binarynum[(i*4)+2] = '1';
//                binarynum[(i*4)+3] = '1';
//                //binarynum[(i*5)+4] = ' ';
//                break;
//            default:
//                printf("\n Invalid hexadecimal digit %c ", hexaPointer[i]);
//                while (getchar() != '\n');
//                return -1;
//        }
//        i++; }
//    binarynum[i*4] = '\0';
//    printf("%s", binarynum);
//    return 0;
//}
//void printBinaryEquivalent(const unsigned char *stri) {
//    //printf("\nutf: %x \n", stri[0]);
//    char binary[9]; // Initialize array with zeros and leave space for the null terminator
//    int asciiValue;
//    if (stri[0] == '\\' && stri[1] == 'u') {
//        printf("\nUh oh: %c, %c", stri[0], stri[1]);
//        printf("\nutf: %x \n", stri[2]);
//        asciiValue = (int)stri[2];
//    } else {
//        asciiValue = (int) stri[0];
//        printf("\nutf: %x \n", stri[0]); // ASCII value of the character
//    }
//
//    // Convert ASCII value to binary
//    for (int i = 7; i >= 0; --i) {
//        binary[7 - i] = ((asciiValue >> i) & 1) ? '1' : '0';
//    }
//    binary[8] = '\0'; // Null-terminate the binary string
//
//    // Print the binary representation
//    printf("Binary: %s\n", binary);
//    binaryToDecimal(binary);
//}
//
//// Function to determine the length of a UTF-8 character based on its start byte
//int checkCharLength(const unsigned char *stri) {
//    int length;
//
//    if ((stri[0] & 0x80) == 0){
//        length = 1;
//        printf("Number of Bytes in Char: %d ", length);
//        return length;
//    }
//
//    switch (stri[0] & 0xF0) {
//        case 0xD0:
//        case 0xC0:
//            length = 2; // Two bytes
//            break;
//        case 0xE0:
//            length = 3; // Three bytes
//            break;
//        case 0xF0:
//            length = 4; // Four bytes
//            break;
//        default:
//            length = -1; // Handle unexpected start byte
//            break;
//    }
//    printf("Number of Bytes in Char: %d ", length);
//    return length;
//}
//
////checks the string length
//int my_utf8_strlen(char *string){
//    int length = 0;
//    while(*string){
//        //count start bytes to determine string length
//        if (isUtf8_StartByte(*string)) {
//            length ++;
//            int plus = checkCharLength((const unsigned char *) string);
//            string += plus;
//        }
//        //skip continuation bytes
//        else {
//            string++;
//        }
//    }
//    return length;
//}
//
////int my_utf8_
//
//int binaryToDecimal(const char *binary) {
//    int decimal = 0;
//
//    // Calculate the length of the binary string
//    int length = 0;
//    while (binary[length] == '0' || binary[length] == '1') {
//        length++;
//    }
//
//    // Convert binary to decimal
//    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
//        if (binary[i] == '1') {
//            decimal += (1L << j);  // Equivalent to 2^j
//        }
//    }
//
//    printf("DEC = %d\n", decimal);
//    return decimal;
//}
//
//int main(void) {
//    char binary[MAX] = {0}; // Initialize array with zeros
////    const char *hex = "\\uc790";
////    printf("%s\n", hex);
////    hexToBinary(hex, binary);
////    binaryToDecimal(binary);
////    printf(" \n ");
//    const char* hex1 = "1F";
//    const char* hex2 = "0x2A";
//    const char* *hex3 = "\\u0123";
//    hexToBinary(hex3, binary);
//    const char *character = "!";
//    printBinaryEquivalent(hex3);
//    int len = checkCharLength((const unsigned char *) character);
//    //printBinaryEquivalent((const unsigned char *) character);
//    printf("Length of character is %d", len);
//    return 0;
//}
//
