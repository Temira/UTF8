#include <stdio.h>
#define MAX 1000000

int isUtf8_StartByte(unsigned char byte); //determines if a byte is a valid start byte
int isUtf8_ContinuationByte(unsigned char byte); //determines if a byte is a valid continuation byte
int hexToBinary(const char *hexa, unsigned char *binarynum); //converts hex to binary (duh)
void printBinaryEquivalent(const unsigned char *stri);
int checkCharLength(const unsigned char *stri); //determines how many UTF-8 Hex pairs there will be based on start byte
int my_utf8_strlen(char *string); //uses start bytes
//int length(char *string); //uses nul to locate end of string
int binaryToDecimal(unsigned const char *binary); //converts binary to decimal
int determineRange(int number); //determines what range the unicode string falls into
//int fillTemp1(); //fills one byte template
int fillTemp2(); //fills two byte template
int fillTemp3(); //fills three byte template
int fillTemp4(); // fills four byte template
int codepointToUTF(const unsigned char *stri); //converts unicode codepoint to equivalent UTF-8 hex
int stripLeadingZeros(unsigned char *binaryString); //



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
}

int length(unsigned char *str){
    int currentLength = 0;
    // Calculate the current length of the string
    while (str[currentLength] != '\0') {
        currentLength++;
    }
    return currentLength;
}
//
int addLeadingZeros(unsigned char *binaryString, int targetLength) {
    if (binaryString == NULL || targetLength <= 0) {
        return -1;
    }
    int currentLength = length(binaryString);
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
    }
}


int fillTemp1(unsigned char * binaryNum, unsigned char * newNumber){
    printf("\n1\n");
    //get significant numbers to make sure it fits into the template
    stripLeadingZeros(binaryNum);
    //should be a binary of length 7 for it to fit well into the template
    addLeadingZeros(binaryNum, 7);
    newNumber[0] = '0';
    for (int i=0; i<7; i++){
        newNumber[i+1] = binaryNum[i];
    }
    newNumber[8] ='\0';
    return 0;
}

int fillTemp2(unsigned char * binaryNum, unsigned char * newNumber){
    printf("\n2\n");
    //get significant numbers to make sure it fits into the template
    stripLeadingZeros(binaryNum);
    //should be a binary of length 11 for it to fit well into the template
    addLeadingZeros(binaryNum, 11);
    newNumber[0] = '1';
    newNumber[1] = '1';
    newNumber[2] = '0';
    for (int i = 0, j = 3; i < 6; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[8] = '1';
    newNumber[9] = '0';
    for (int i = 6, j = 10; i < 12; j++, i++){
        newNumber[j] = binaryNum[i];
    }
    newNumber[8] ='\0';
    return 0;
}
int fillTemp3(){
    printf("\nt3");
}
int fillTemp4(){
    printf("\nt4");
}
int codepointToUTF(const unsigned char *stri) {
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
        printf("new %s", newBinary);
    }
    else if (range == 3){
        fillTemp3();
    }
    else if (range == 4){
        fillTemp4();
    }
    else{
        printf("no");
    }
    return 0;
};

int main(void) {
    char binary[MAX] = {0}; // Initialize array with zeros
//
//    const char* hex1 = "1F";
//    const char* hex2 = "0x2A";
    const char* hex3 = "\\u0081";
//    hexToBinary(hex3, binary);
//    const char *character = "!";
    //hexToBinary(hex3, binary);
    codepointToUTF(hex3);
//    int len = checkCharLength((const unsigned char *) character);
//    //printBinaryEquivalent((const unsigned char *) character);
//    printf("Length of character is %d", len);
    return 0;
}
