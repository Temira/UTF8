//#include "3.c"
//#define MAX 1000000
////
////int isUtf8_StartByte(unsigned char byte); //determines if a byte is a valid start byte
////int isUtf8_ContinuationByte(unsigned char byte); //determines if a byte is a valid continuation byte
////int hexToBinary(const char *hexa, unsigned char *binarynum); //converts hex to binary (duh)
////void printBinaryEquivalent(const unsigned char *stri);
////int checkCharLength(char *stri); //determines how many UTF-8 Hex pairs there will be based on start byte
////int my_utf8_strlen(char *string); //uses start bytes
////int lengthBinary(unsigned char *string); //uses nul to locate end of string
////int binaryToDecimal(unsigned const char *binary); //converts binary to decimal
////int determineRange(int number); //determines what range the unicode string falls into
////int fillTemp1(unsigned char * binaryNum, unsigned char * newNumber); //fills one byte template
////int fillTemp2(unsigned char * binaryNum, unsigned char * newNumber); //fills two byte template
////int fillTemp3(unsigned char * binaryNum, unsigned char * newNumber); //fills three byte template
////int fillTemp4(unsigned char * binaryNum, unsigned char * newNumber); // fills four byte template
////int codepointToUTF(const unsigned char *stri, const char *output); //converts unicode codepoint to equivalent UTF-8 hex
////int stripLeadingZeros(unsigned char *binaryString);
////int addLeadingZeros(unsigned char *binaryString, int targetLength);
////int binaryToHex(unsigned char  *inputString, char *outputString);
////int isValidHexChar(char c);
////int my_utf8_encode(char *input, char *output);
////int lengthString(const char *str);
////int my_utf8_check(char *string);
////char my_utf8_charat(char *string, int index);
//
//
//void test_my_utf8_strlen(unsigned char* string, int expected) {
//    int actual = my_utf8_strlen(string);
//    const char* result = (expected == actual) ? "PASSED" : "FAILED";
//
//    printf("Test %s - my_utf8_strlen\n", result);
//    printf("  Input   : \"%s\"\n", string);
//    printf("  Expected: %d\n", expected);
//    printf("  Actual  : %d\n", actual);
//    printf("\n");
//}
//
//void my_utf8_strlen_tests() {
//    // Basic tests
//    test_my_utf8_strlen("", 0);
//    test_my_utf8_strlen("a", 1);
//    test_my_utf8_strlen("ab", 2);
//    test_my_utf8_strlen("abc", 3);
//    test_my_utf8_strlen("abcd", 4);
//    test_my_utf8_strlen("abcde", 5);
//    test_my_utf8_strlen("abcdef", 6);
//
//    // Tests with invalid UTF-8
//    test_my_utf8_strlen("\xC3", -1); // Incomplete UTF-8 sequence
//    test_my_utf8_strlen("abc\x80def", -1); // Invalid UTF-8 character
//
//    // Tests with valid UTF-8 characters
//    test_my_utf8_strlen("a\xC3\xA9", 2);
//    test_my_utf8_strlen("a\xC3\xA9\xC3\xA9", 3);
//    test_my_utf8_strlen("a\xC3\xA9\xC3\xA9\xC3\xA9", 4);
//    test_my_utf8_strlen("a\xC3\xA9\xC3\xA9\xC3\xA9\xC3\xA9", 5);
//    test_my_utf8_strlen("a\xD7\x90", 2);
//    test_my_utf8_strlen("a\xD7\x90\xD7\x90", 3);
//
//    // Edge cases
//    // Test a very long string
//    unsigned char longString[10000];
//    for (int i = 0; i < 9999; ++i) {
//        longString[i] = 'a';
//    }
//    longString[9999] = '\0';
//    test_my_utf8_strlen(longString, 10000);
//
//    // Test a string with only continuation bytes
//    test_my_utf8_strlen("\x80\x80\x80", -1);
//
//    // Test an empty string
//    test_my_utf8_strlen("", 0);
//}
//int main() {
//    my_utf8_strlen_tests();
//    return 0;
//}

int my_utf8_strcmp(unsigned char *string1, unsigned char *string2) {
    while (*string1 != '\0' || *string2 != '\0') {
        if (*string1 != *string2) {
            return (*string1 - *string2);
        }

        // Move to the next character in each string based on UTF-8 encoding rules
        if (*string1 < 0x80) {
            string1++;
        } else if ((*string1 & 0xE0) == 0xC0) {
            string1 += 2;
        } else if ((*string1 & 0xF0) == 0xE0) {
            string1 += 3;
        } else if ((*string1 & 0xF8) == 0xF0) {
            string1 += 4;
        }

        if (*string2 < 0x80) {
            string2++;
        } else if ((*string2 & 0xE0) == 0xC0) {
            string2 += 2;
        } else if ((*string2 & 0xF0) == 0xE0) {
            string2 += 3;
        } else if ((*string2 & 0xF8) == 0xF0) {
            string2 += 4;
        }
    }

    return 0;
}