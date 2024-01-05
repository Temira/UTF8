#include <stdio.h>
//#define MAX 1000000
//#include <stdio.h>
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
////Function to determine the length of a UTF-8 character based on its start byte
//int checkCharLength(unsigned char stri) {
//    int length;
//
//    switch (stri & 0xF0) {
//        case 0x00:
//            length = 1; // One byte character sequence
//            break;
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
//            length = 1; // Handle unexpected start byte
//            break;
//    }
//    printf("Number of Bytes in Char: %d ", length);
//    return length;
//}
//
//
//// Function to print the UTF-8 encoding of a string
//void print_utf8_encoding(const char *str) {
//    while (*str) {
//        if (isUtf8_StartByte(*str)) {
//            // Determine the length
//            int length = checkCharLength(*str);
//            // Print the entire UTF-8 encoding for each character on a single line
//            printf("\nUTF-8 encoding: ");
//            for (int i = 0; i < length; ++i) {
//                printf("%x ", (unsigned char)str[i]);
//            }
//            printf("\n");
//            // Move to the next character
//            str += length;
//        } else {
//            // Skip continuation bytes
//            ++str;
//        }
//    }
//}
//
//int my_utf8_strlen(char *string){
//    int length = 0;
//
//    while(*string){
//        if (isUtf8_StartByte(*string)) {
//            length ++;
//            int plus = checkCharLength(*string);
//            string += plus;
//        }
//        else{
//            string++;
//        }
//    }
//    return length;
//}
//
////// Function to check the validity of UTF-8 encoding
////int my_utf8_check(const char *str) {
////    while (*str) {
////        if (isUtf8_StartByte(*str)) {
////            int char_length = checkCharLength((char *) str);
////
////            // Validate appropriate continuation bytes starting from the second byte
////            for (int i = 1; i < char_length; ++i) {
////                if (!isUtf8_ContinuationByte(str[i])) {
////                    fprintf(stderr, "Error: Unexpected continuation byte.\n");
////                    return 0;
////                }
////            }
////            // Move the pointer to the next UTF-8 character
////            str += char_length;
////        } else {
////            // Handle unexpected continuation byte
////            fprintf(stderr, "Error: Unexpected continuation byte.\n");
////            return 0;
////        }
////    }
////    printf("valid");
////    return 1;
////}
//
//
//int main(void) {
//
//    //const char *str = "ჿ38";
//    //print_utf8_encoding(str);
//    const char *string = "é";
//    int length = my_utf8_strlen((char *)string);
//    printf("\nNumber of characters: %d\n", length);
//
//    return 0;
//}
//


//// Function to check if a byte is the start of a UTF-8 character
//int isUtf8_StartByte(unsigned char byte) {
//    return (byte & 0xC0) != 0x80;
//}

//// Function to determine the length of a UTF-8 character based on its start byte
//int checkCharLength(unsigned char stri) {
//    int length;
//
//    switch (stri & 0xF0) {
//        case 0x00:
//            length = 1; // One byte character sequence
//            break;
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
//            length = 1; // Handle unexpected start byte
//            break;
//    }
//    printf("Number of Bytes in Char: %d ", length);
//    return length;
//}

//// Function to convert a hexadecimal string to binary
//void hexToBinary(const char *hexa, char *binarynum) {
//    long int i = 0;
//    const char *hexaPointer;
//
//    if (hexa[0] == 'U' && hexa[1] == '+') {
//        hexaPointer = hexa + 2;
//    } else {
//        hexaPointer = hexa;
//    }
//
//    while (hexaPointer[i] != '\0') {
//        // Check if the current character is a valid hexadecimal digit
//        if ((hexaPointer[i] >= '0' && hexaPointer[i] <= '9') ||
//            (hexaPointer[i] >= 'A' && hexaPointer[i] <= 'F') ||
//            (hexaPointer[i] >= 'a' && hexaPointer[i] <= 'f')) {
//
//            switch (hexaPointer[i]) {
//                case '0':
//                    printf("0000 ");
//                    break;
//                case '1':
//                    printf("0001 ");
//                    break;
//                case '2':
//                    printf("0010 ");
//                    break;
//                case '3':
//                    printf("0011 ");
//                    break;
//                case '4':
//                    printf("0100 ");
//                    break;
//                case '5':
//                    printf("0101 ");
//                    break;
//                case '6':
//                    printf("0110 ");
//                    break;
//                case '7':
//                    printf("0111 ");
//                    break;
//                case '8':
//                    printf("1000 ");
//                    break;
//                case '9':
//                    printf("1001 ");
//                    break;
//                case 'A':
//                case 'a':
//                    printf("1010 ");
//                    break;
//                case 'B':
//                case 'b':
//                    printf("1011 ");
//                    break;
//                case 'C':
//                case 'c':
//                    printf("1100 ");
//                    break;
//                case 'D':
//                case 'd':
//                    printf("1101 ");
//                    break;
//                case 'E':
//                case 'e':
//                    printf("1110 ");
//                    break;
//                case 'F':
//                case 'f':
//                    printf("1111 ");
//                    break;
//            }
//        } else {
//            // Print an error message for invalid hex digits
//            printf("\n Invalid hexadecimal digit %c ", hexaPointer[i]);
//        }
//
//        i++;
//    }
//    // Terminate the binarynum array
//    binarynum[i * 5 - 1] = '\0';
//}
//int my_utf8_strlen(char *string){
//    int length = 0;
//
//    while(*string){
//        if (isUtf8_StartByte(*string)) {
//            length ++;
//            int plus = checkCharLength(*string);
//            string += plus;
//        }
//        else{
//            string++;
//        }
//    }
//    return length;
//}

//int binaryToDecimal(const char* binary) {
//    int decimal = 0;
//    int length = my_utf8_strlen(binary);
//
//    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
//        if (binary[i] == '1') {
//            decimal += (1L << j);  // Equivalent to 2^j
//        }
//    }
//    printf("\nDEC = %d\n", decimal);
//    return decimal;
//}



//int hexToBinary(const char *hexa, char *binarynum){
//    long int i = 0;
//    const char* hexaPointer;
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
//                break;
//            case '5':
//                binarynum[i*4] = '0';
//                binarynum[(i*4)+1] = '1';
//                binarynum[(i*4)+2] = '0';
//                binarynum[(i*4)+3] = '1';
//                //binarynum[(i*5)+4] = ' ';
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
//                printf("\n Invalid hexadecimal digit %c ", hexa[i]);
//                while (getchar() != '\n');
//                return -1;
//        }
//        i++; }
//    binarynum[i*4] = '\0';
//    printf("%s", binarynum);
//    return 0;
//}

//int main(void) {
//    char binary[MAX] = {0}; // Initialize array with zeros
//    hexToBinary("c790", binary);
//    printf(" \n ");
//    binaryToDecimal(binary);
//    printf(" \n ");
//
//    return 0;
//}
