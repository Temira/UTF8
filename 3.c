#include <stdio.h>
#define MAX 1000000

int isUtf8_StartByte(unsigned char byte); //determines if a byte is a valid start byte
int isUtf8_ContinuationByte(unsigned char byte); //determines if a byte is a valid continuation byte
int hexToBinary(const char *hexa, unsigned char *binarynum); //converts hex to binary (duh)
void printBinaryEquivalent(const unsigned char *stri);
int checkCharLength(char *stri); //determines how many UTF-8 Hex pairs there will be based on start byte
int my_utf8_strlen(char *string); //uses start bytes
int lengthBinary(unsigned char *string); //uses nul to locate end of string
int binaryToDecimal(unsigned const char *binary); //converts binary to decimal
int determineRange(int number); //determines what range the unicode string falls into
int fillTemp1(unsigned char * binaryNum, unsigned char * newNumber); //fills one byte template
int fillTemp2(unsigned char * binaryNum, unsigned char * newNumber); //fills two byte template
int fillTemp3(unsigned char * binaryNum, unsigned char * newNumber); //fills three byte template
int fillTemp4(unsigned char * binaryNum, unsigned char * newNumber); // fills four byte template
int codepointToUTF(const unsigned char *stri, const char *output); //converts unicode codepoint to equivalent UTF-8 hex
int stripLeadingZeros(unsigned char *binaryString);
int addLeadingZeros(unsigned char *binaryString, int targetLength);
int binaryToHex(unsigned char  *inputString, char *outputString);
int isValidHexChar(char c);
int my_utf8_encode(char *input, char *output);
int lengthString(const char *str);
int my_utf8_check(char *string);
char my_utf8_charat(char *string, int index);



int hexToBinary(const char *hexa, unsigned char *binarynum){
    long int i = 0;
    const char *hexaPointer;
    //printf("%c", hexa[0]);

    if (hexa[0] == '\\' && hexa[1] == 'u') {
        hexaPointer = hexa + 2;
    } else {
        hexaPointer = hexa;
    }
    printf("char %c", *hexaPointer);

    while (hexaPointer[i] != '\0') {
        //printf("\ncurrently pointing at a %c", hexa[i]);
        switch (hexaPointer[i])
        { //yes, I know it's inefficient but that is ok with me
            case '0':
                binarynum[i*4] = '0';
                binarynum[(i*4)+1] = '0';
                binarynum[(i*4)+2] = '0';
                binarynum[(i*4)+3] = '0';
                //printf("\nbin0 %s", binarynum);
                break;
            case '1':
                binarynum[i*4] = '0';
                binarynum[(i*4)+1] = '0';
                binarynum[(i*4)+2] = '0';
                binarynum[(i*4)+3] = '1';
                //printf("\nbin 1 %s", binarynum);
                break;
            case '2':
                binarynum[i*4] = '0';
                binarynum[(i*4)+1] = '0';
                binarynum[(i*4)+2] = '1';
                binarynum[(i*4)+3] = '0';
                //printf("\nbin 2 %s", binarynum);
                break;
            case '3':
                binarynum[i*4] = '0';
                binarynum[(i*4)+1] = '0';
                binarynum[(i*4)+2] = '1';
                binarynum[(i*4)+3] = '1';
                break;
            case '4':
                binarynum[i*4] = '0';
                binarynum[(i*4)+1] = '1';
                binarynum[(i*4)+2] = '0';
                binarynum[(i*4)+3] = '0';
                //binarynum[(i*5)+4] = ' ';
                //printf("44444");
                break;
            case '5':
                binarynum[i*4] = '0';
                binarynum[(i*4)+1] = '1';
                binarynum[(i*4)+2] = '0';
                binarynum[(i*4)+3] = '1';
                //binarynum[(i*5)+4] = ' ';
                //printf("55555");
                break;
            case '6':
                binarynum[i*4] = '0';
                binarynum[(i*4)+1] = '1';
                binarynum[(i*4)+2] = '1';
                binarynum[(i*4)+3] = '0';
                //binarynum[(i*5)+4] = ' ';
                break;
            case '7':
                binarynum[i*4] = '0';
                binarynum[(i*4)+1] = '1';
                binarynum[(i*4)+2] = '1';
                binarynum[(i*4)+3] = '1';
                //binarynum[(i*5)+4] = ' ';
                break;
            case '8':
                binarynum[i*4] = '1';
                binarynum[(i*4)+1] = '0';
                binarynum[(i*4)+2] = '0';
                binarynum[(i*4)+3] = '0';
                //binarynum[(i*5)+4] = ' ';
                break;
            case '9':
                binarynum[i*4] = '1';
                binarynum[(i*4)+1] = '0';
                binarynum[(i*4)+2] = '0';
                binarynum[(i*4)+3] = '1';
                //binarynum[(i*5)+4] = ' ';
                break;
            case 'A':
            case 'a':
                binarynum[i*4] = '1';
                binarynum[(i*4)+1] = '0';
                binarynum[(i*4)+2] = '1';
                binarynum[(i*4)+3] = '0';
                //binarynum[(i*5)+4] = ' ';
                break;
            case 'B':
            case 'b':
                binarynum[i*4] = '1';
                binarynum[(i*4)+1] = '0';
                binarynum[(i*4)+2] = '1';
                binarynum[(i*4)+3] = '1';
                //binarynum[(i*5)+4] = ' ';
                break;
            case 'C':
            case 'c':
                binarynum[i*4] = '1';
                binarynum[(i*4)+1] = '1';
                binarynum[(i*4)+2] = '0';
                binarynum[(i*4)+3] = '0';
                //binarynum[(i*5)+4] = ' ';
                break;
            case 'D':
            case 'd':
                binarynum[i*4] = '1';
                binarynum[(i*4)+1] = '1';
                binarynum[(i*4)+2] = '0';
                binarynum[(i*4)+3] = '1';
                //binarynum[(i*5)+4] = ' ';
                break;
            case 'E':
            case 'e':
                binarynum[i*4] = '1';
                binarynum[(i*4)+1] = '1';
                binarynum[(i*4)+2] = '1';
                binarynum[(i*4)+3] = '0';
                //binarynum[(i*5)+4] = ' ';
                break;
            case 'F':
            case 'f':
                binarynum[i*4] = '1';
                binarynum[(i*4)+1] = '1';
                binarynum[(i*4)+2] = '1';
                binarynum[(i*4)+3] = '1';
                //binarynum[(i*5)+4] = ' ';
                break;
            default:
                printf("\n Invalid hexadecimal digit %c ", hexaPointer[i]);
                //while (getchar() != '\n');
                return -1;
            }
        i++;}

    binarynum[i*4] = '\0';
    printf("Binary equivalent is: %s", binarynum);
    return 0;
}
int binaryToDecimal(unsigned const char *binary) {
    int decimal = 0;

    // Calculate the length of the binary string
    int length = 0;
    while (binary[length] == '0' || binary[length] == '1') {
        length++;
    }

    // Convert binary to decimal
    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        if (binary[i] == '1') {
            decimal += (1L << j);  // Equivalent to 2^j
        }
    }
    printf("DEC = %d\n", decimal);
    return decimal;
}

int determineRange(int number) {

    if (number >= 0 && number <= 127) {
        return 1; //ASCII range
    } else if (number >= 128 && number <= 2047) {
        return 2; //Latin script (plus a few other scripts)
    } else if (number >= 2048 && number <= 65535) {
        return 3; //Remaining characters for Basic Multilingual Plane
    } else if (number >= 65536 && number <= 1114111) {
        return 4; //Supplementary planes
    } else {
        // Handle error
        return 0;
    }
}

int stripLeadingZeros(unsigned char *binaryString) {
    if (binaryString == NULL) {
        // Handle NULL pointer accordingly
        return -1;
    }
    int leadingZeros = 0;
    // Find the number of leading zeros
    while (binaryString[leadingZeros] == '0' && binaryString[leadingZeros] != '\0') {
        leadingZeros++;
    }
    // Shift over however many leading zeros there are
    int i;
    for (i = 0; binaryString[i + leadingZeros] != '\0'; i++) {
        binaryString[i] = binaryString[i + leadingZeros];
    }
    binaryString[i] = '\0';
    return 0;
}

int lengthBinary(unsigned char *str){
    int currentLength = 0;
    // Calculate the current length of the string
    while (str[currentLength] != '\0') {
        currentLength++;
    }
    return currentLength;
}
int lengthString(const char *str){
    int currentLength = 0;
    // Calculate the current length of the string
    while (str[currentLength] != '\0') {
        currentLength++;
    }
    return currentLength;
}

int addLeadingZeros(unsigned char *binaryString, int targetLength) {
    if (binaryString == NULL || targetLength <= 0) {
        return -1;
    }
    int currentLength = lengthBinary(binaryString);
    if (currentLength >= targetLength) {
        // The string is already longer or equal to the target length
        return 0;
    }
    // Calculate the number of zeros to add
    int zerosToAdd = targetLength - currentLength;
    // Make room for the leading zeros
    for (int i = currentLength; i >= 0; i--) {
        binaryString[i + zerosToAdd] = binaryString[i];
    }
    // Add the leading zeros
    for (int i = 0; i < zerosToAdd; i++) {
        binaryString[i] = '0';
        return 0;
    }
}


int fillTemp1(unsigned char * binaryNum, unsigned char * newNumber){
    printf("\n1\n");
    //get significant numbers to make sure it fits into the template
    stripLeadingZeros(binaryNum);
    //should be a binary of  7 for it to fit well into the template
    addLeadingZeros(binaryNum, 7);
    newNumber[0] = '0';
    for (int i=0; i<7; i++){
        newNumber[i+1] = binaryNum[i];
    }
    newNumber[8] ='\0';
    return 0;
}

int fillTemp2(unsigned char * binaryNum, unsigned char * newNumber){
    //get significant numbers to make sure it fits into the template
    stripLeadingZeros(binaryNum);
    //should be a binary of 11 for it to fit well into the template
    addLeadingZeros(binaryNum, 11);
    newNumber[0] = '1';
    newNumber[1] = '1';
    newNumber[2] = '0';
    for (int i = 0, j = 3; i < 5; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[8] = '1';
    newNumber[9] = '0';
    for (int i = 5, j = 10; i < 12; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[17] ='\0';
    return 0;
}
int fillTemp3(unsigned char * binaryNum, unsigned char * newNumber){
    //get significant numbers to make sure it fits into the template
    stripLeadingZeros(binaryNum);
    printf("\nstrip = %s\n", binaryNum);
    //should be a binary of 16 for it to fit well into the template
    addLeadingZeros(binaryNum, 16);
    printf("\nadd = %s\n", binaryNum);
    newNumber[0] = '1';
    newNumber[1] = '1';
    newNumber[2] = '1';
    newNumber[3] = '0';
    for (int i = 0, j = 4; i < 4; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[8] = '1';
    newNumber[9] = '0';
    for (int i = 4, j = 10; i < 10; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[16] = '1';
    newNumber[17] = '0';
    for (int i = 10, j = 18; i < 17; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[25] ='\0';
    printf("\nres = %s\n", newNumber);
    return 0;
}
int fillTemp4(unsigned char * binaryNum, unsigned char * newNumber){
    // this was PAINFULLLLLL to write
    //get significant numbers to make sure it fits into the template
    stripLeadingZeros(binaryNum);
    //should be a binary of 21 for it to fit well into the template
    addLeadingZeros(binaryNum, 21);
    newNumber[0] = '1';
    newNumber[1] = '1';
    newNumber[2] = '1';
    newNumber[3] = '1';
    newNumber[4] = '0';
    for (int i = 0, j = 5; i < 3; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[8] = '1';
    newNumber[9] = '0';
    for (int i = 3, j = 10; i < 9; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[16] = '1';
    newNumber[17] = '0';
    for (int i = 9, j = 18; i < 15; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[24] = '1';
    newNumber[25] = '0';
    for (int i = 15, j = 26; i < 23; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[40] ='\0';
    return 0;
}

int codepointToUTF(const unsigned char *stri, const char *output) {
    unsigned char binary[MAX] = {0};
    unsigned char newBinary[MAX] = {0};
    hexToBinary(stri, binary);
    int i = binaryToDecimal(binary);
    //at this point, i contains the decimal equivalent of the unicode codepoint
    int range = determineRange(i);
    printf("Needs %d bytes", range);
    //Fill appropriate template
    if (range == 1){
        fillTemp1(binary, newBinary);
        printf("new %s", newBinary);
    }
    else if (range == 2){
        fillTemp2(binary, newBinary);
        printf("\nnew %s", newBinary);
    }
    else if (range == 3){
        printf("\nbin = %s\n", binary);
        fillTemp3(binary, newBinary);
        printf("\nbin = %s\n", newBinary);
    }
    else if (range == 4){
        fillTemp4(binary, newBinary);
        printf("\nnew %s", newBinary);
    }
    else{
        return -1;
    }
    binaryToHex(newBinary, output);
    printf("\nbin = %s\n", output);
    return 0;
};

int binaryToHex(unsigned char *inputString, char *outputString) {
        int len = lengthBinary(inputString);
        int resultIndex = 0;

        for (int i = 0; i < len; i += 4) {
            char group[5];  // Assuming each group is 4 characters long, plus null terminator
            // Copy 4 characters from inputString to group

            for (int j = 0; j < 4; j++) {
                group[j] = inputString[i + j];
            }
            group[4] = '\0';  // Null-terminate the group

            // Use if-else statements to manually compare different cases based on the group
            if (group[0] == '0' && group[1] == '0' && group[2] == '0' && group[3] == '0') {
                outputString[resultIndex] = '0';
                resultIndex++;
            } else if (group[0] == '0' && group[1] == '0' && group[2] == '0' && group[3] == '1') {
                outputString[resultIndex] = '1';
                resultIndex++;
            } else if (group[0] == '0' && group[1] == '0' && group[2] == '1' && group[3] == '0') {
                outputString[resultIndex] = '2';
                resultIndex++;
            } else if (group[0] == '0' && group[1] == '0' && group[2] == '1' && group[3] == '1') {
                outputString[resultIndex] = '3';
                resultIndex++;
            } else if (group[0] == '0' && group[1] == '1' && group[2] == '0' && group[3] == '0') {
                outputString[resultIndex] = '4';
                resultIndex++;
            } else if (group[0] == '0' && group[1] == '1' && group[2] == '0' && group[3] == '1') {
                outputString[resultIndex] = '5';
                resultIndex++;
            } else if (group[0] == '0' && group[1] == '1' && group[2] == '1' && group[3] == '0') {
                outputString[resultIndex] = '6';
                resultIndex++;
            } else if (group[0] == '0' && group[1] == '1' && group[2] == '1' && group[3] == '1') {
               outputString[resultIndex] = '7';
                resultIndex++;
            } else if (group[0] == '1' && group[1] == '0' && group[2] == '0' && group[3] == '0') {
                outputString[resultIndex] = '8';
                resultIndex++;
            } else if (group[0] == '1' && group[1] == '0' && group[2] == '0' && group[3] == '1') {
                outputString[resultIndex] = '9';
                resultIndex++;
            } else if (group[0] == '1' && group[1] == '0' && group[2] == '1' && group[3] == '0') {
                outputString[resultIndex] = 'A';
                resultIndex++;
            } else if (group[0] == '1' && group[1] == '0' && group[2] == '1' && group[3] == '1') {
                outputString[resultIndex] = 'B';
                resultIndex++;
            } else if (group[0] == '1' && group[1] == '1' && group[2] == '0' && group[3] == '0') {
                outputString[resultIndex] = 'C';
                resultIndex++;
            } else if (group[0] == '1' && group[1] == '1' && group[2] == '0' && group[3] == '1') {
                outputString[resultIndex] = 'D';
                resultIndex++;
            } else if (group[0] == '1' && group[1] == '1' && group[2] == '1' && group[3] == '0') {
                outputString[resultIndex] = 'E';
                resultIndex++;
            } else if (group[0] == '1' && group[1] == '1' && group[2] == '1' && group[3] == '1') {
                outputString[resultIndex] = 'F';
                resultIndex++;
            }
            else {
                printf("uhoh %c %c %c %c", group[0],group[1], group[2], group[3]);
            }
        }

        outputString[resultIndex] = '\0';  // Null terminate the result string
        printf("Result String: %s\n", outputString);
        return 0;
}

int isValidHexChar(char c) {
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) ? 1 : 0;
}

int my_utf8_encode(char *input, char *output) {
    int strLength = lengthString(input);
    int i = 0;
    int outputIndex = 0;

    while (i < strLength) {
        // Process Unicode point starting with '\\U'
        if (input[i] == '\\' && (input[i + 1] == 'U' || input[i + 1] == 'u')) {
            int unicodeLength = (input[i + 1] == 'U') ? 7 : 6; // Check if it's \\U or \\u and how long code pt is

            // Verify that the characters following '\\U' or '\\u' are valid hex characters
            int validHexChars = 1;
            for (int j = i + 2; j < i + unicodeLength; ++j) {
                if (!isValidHexChar(input[j])) {
                    validHexChars = 0;
                    break;
                }
            }
            // Process the Unicode point if the characters are valid hex
            if (validHexChars) {
                // Create a string to store the entire Unicode point
                char unicodeString[8]; // Assuming the maximum length is 7 (\\UXXXX) + null terminator
                for (int k = 0; k < unicodeLength; ++k) {
                    unicodeString[k] = input[i + k];
                }
                unicodeString[unicodeLength] = '\0'; // Null terminate the string

                // Print the entire Unicode string
                printf("%s", unicodeString);
                codepointToUTF(unicodeString, &output[outputIndex]);
                outputIndex += lengthString(unicodeString);
                printf("here");

            } else {
                // Handle the case where characters are not valid hex
                printf("[INVALID_UNICODE]");
            }

            i += unicodeLength; // Move to the next character after the Unicode point

        } else {
            output[outputIndex] = input[i];
            printf("\n%c", input[i]);
            i++;
            outputIndex++;
            printf("\nout %s",output);
        }
    printf("\n real out %s",output);
    }
    printf("\n real real real out %s",output);
    return 0;
}

// Function to determine the length of a UTF-8 character based on its start byte
int checkCharLength(char *stri) {
    int length;
    if ((stri[0] & 0x80) == 0) {
        length = 1; //One byte
    } else if ((stri[0] & 0xE0) == 0xC0) {
        length = 2; // Two bytes
    } else if ((stri[0] & 0xF0) == 0xE0) {
        length = 3; // Three bytes
    } else if ((stri[0] & 0xF8) == 0xF0) {
        length = 4; // Four bytes
    } else {
        length = -1; // Error
    }
    //printf("Number of Bytes in Char: %d ", length);
    return length;
}

// Function to check if a byte is the start of a UTF-8 character
int isUtf8_StartByte(unsigned char byte) {
    return (byte & 0xC0) != 0x80;
}

// Function to check if a byte is a continuation byte in a UTF-8 character
int isUtf8_ContinuationByte(unsigned char byte) {
    return (byte & 0xC0) == 0x80;
}

int my_utf8_check(char *string) {
    int strLength = lengthString(string);
    int charLength;

    for (int i = 0; i < strLength; i++) {
        charLength = checkCharLength(string + i);

        if (charLength == 1) {
            if (!isUtf8_StartByte(string[i])) {
                return 0; // Invalid
            }
        }
        else if (charLength >= 2 && charLength <= 4) {
            for (int j = 1; j < charLength; j++) {
                if (!isUtf8_ContinuationByte(string[i + j])) {
                    return 0; // Invalid
                }
            }
            i += charLength - 1; //bc loop already increments i
        }
        else {
            return 0; // Invalid
        }
    }
    return 1; // Valid
}
//checks the string length (how many characters there are)
int my_utf8_strlen(char *string){
    int length = 0;
    while(*string){
        //first, make sure that it is a valid utf8 string
        if (!my_utf8_check(string)) {
            return -1; // Invalid UTF-8
        }
        //count start bytes to determine string length
        if (isUtf8_StartByte(*string)) {
            length ++;
            int plus = checkCharLength((const unsigned char *) string);
            //skip the continuation bytes
            string += plus;
        }
        //skip continuation bytes
        else {
            return -1;
        }
    }
    return length;
}

char my_utf8_charat(char *string, int index){
    //check that the string is valid utf8
    if (!my_utf8_check(string)) {
        return '\0'; // Invalid UTF-8
    }
    //check that index is inside the string
    if (!(my_utf8_strlen(string)>index)) {
        return '\0'; // Invalid UTF-8
    }
    int count = 0;
    //basically apply the same principle of my_utf8_strlen
    while(*string){
        if (count == index && isUtf8_StartByte(*string)) {
            return *string;
        }
        if (isUtf8_StartByte(*string)) {
            //increment character counter
            count ++;
            //skip the continuation bytes
            int plus = checkCharLength((const unsigned char *) string);
            string += plus;
        }
        else{
            string++; //next character
        }
    } return '\0';
}
int main() {
    // Test Case 1: Valid UTF-8 string
    char utf8String[] = "Hello, 你好, こんにちは";
    int index1 = 8;  // Index of the character '你'
    char result1 = my_utf8_charat(utf8String, index1);
    printf("Test Case 1: %c\n", result1);  // Expected output: '你'

    // Test Case 2: Invalid UTF-8 string
    char invalidUtf8String[] = "Invalid \xE3\x28\xA1 String";
    int index2 = 2;  // Index inside the invalid character sequence
    char result2 = my_utf8_charat(invalidUtf8String, index2);
    printf("Test Case 2: %c\n", result2);  // Expected output: '\0' (Invalid UTF-8)

    // Test Case 3: Index out of bounds
    char string3[] = "Test";
    int index3 = 10;  // Index outside the string length
    char result3 = my_utf8_charat(string3, index3);
    printf("Test Case 3: %c\n", result3);  // Expected output: '\0' (Invalid index)

    return 0;
}

//int main() {
//    // Example UTF-8 strings
//    const char utf8String1[] = "Hello, 世界!";  // Length: 10 characters
//    const char utf8String2[] = "\xd0\x98\xc2\xa3\xf0\x90\x8D\x88";    // Length: 3 characters
//    const char utf8String3[] = "UTF-8 🌍";        // Length: 7 characters
//
//    // Test the function with different UTF-8 strings
//    printf("Length of UTF-8 string 1: %d\n", my_utf8_strlen(utf8String1));
//    printf("Length of UTF-8 string 2: %d\n", my_utf8_strlen(utf8String2));
//    printf("Length of UTF-8 string 3: %d\n", my_utf8_strlen(utf8String3));
//
//    return 0;
//}
//int main() {
//    char validUtf8[] = "Hello, 世界!"; // Valid UTF-8 string
//    char invalidUtf8[] = "Hello, \xE5\x95!"; // Invalid UTF-8 string
//
//    if (my_utf8_check(validUtf8)) {
//        printf("The string is a valid UTF-8.\n");
//    } else {
//        printf("The string is not a valid UTF-8.\n");
//    }
//
//    if (my_utf8_check(invalidUtf8)) {
//        printf("The string is a valid UTF-8.\n");
//    } else {
//        printf("The string is not a valid UTF-8.\n");
//    }
//
//    return 0;
//}
//int main(void) {
//    char binary[MAX] = {0}; // Initialize array with zeros
//    const char* hex = "12\\u12345qqq112";
//    my_utf8_encode(hex, binary);
//    printf("\noutput= %s", binary);
//    //codepointToUTF(hex3);
//    //unsigned char *inputString = (unsigned char *)"00100100";
//    //char outputString[16] = {0};
//    //unsigned char* st = "00100100";
//    //binaryToHex(inputString, outputString);
////    int len = checkCharLength((const unsigned char *) character);
////    //printBinaryEquivalent((const unsigned char *) character);
////    printf("Length of character is %d", len);
//    return 0;
//}
