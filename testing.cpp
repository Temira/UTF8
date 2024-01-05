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
//
//
//
//void test_my_utf8_strcmp(unsigned char* string1, unsigned char* string2, int expected) {
//    int result = my_utf8_strcmp(string1, string2);
//    const char* resultString = (result == expected) ? "PASSED" : "FAILED";
//
//    printf("Test %s - my_utf8_strcmp\n", resultString);
//    printf("  String1 : \"%s\"\n", string1);
//    printf("  String2 : \"%s\"\n", string2);
//    printf("  Expected: %d\n", expected);
//    printf("  Actual  : %d\n", result);
//    printf("\n");
//}
//
//void my_utf8_strcmp_tests() {
//    // Basic tests
//    test_my_utf8_strcmp("", "", 1);
//    test_my_utf8_strcmp("Hello, world!", "Hello, world!", 1);
//    test_my_utf8_strcmp("abc", "def", 0);
//
//    // Tests with valid UTF-8 characters
//    test_my_utf8_strcmp("a\xC3\xA9", "a\xC3\xA9", 1); // Same UTF-8 characters
//    test_my_utf8_strcmp("a\xC3\xA9", "a\xC3\xA9\xC3\xA9", 0); // Different lengths
//
//    // Tests with invalid UTF-8 sequences
//    test_my_utf8_strcmp("a\xC3", "a\xC3\xA9", -1); // Incomplete UTF-8 sequence in String1
//    test_my_utf8_strcmp("a\xC3\xA9", "a\xC3", -1); // Incomplete UTF-8 sequence in String2
//}
//
//void test_my_utf8_check(char *string, int expected) {
//    int result = my_utf8_check(string);
//    const char* resultString = (result == expected) ? "PASSED" : "FAILED";
//
//    printf("Test %s - my_utf8_check\n", resultString);
//    printf("  String  : \"%s\"\n", string);
//    printf("  Expected: %d\n", expected);
//    printf("  Actual  : %d\n", result);
//    printf("\n");
//}
//
//void my_utf8_check_tests() {
//    // Basic tests
//    test_my_utf8_check("", 0);
//    test_my_utf8_check("abc", 0); // ASCII characters
//
//    // Valid UTF-8 characters
//    test_my_utf8_check("a\xC3\xA9", 0); // Valid UTF-8 sequence
//    test_my_utf8_check("a\xE2\x82\xAC", 0); // Valid UTF-8 sequence (Euro symbol)
//
//    // Incomplete UTF-8 sequences
//    test_my_utf8_check("\xC3", -1); // Incomplete 2-byte sequence
//    test_my_utf8_check("\xE2\x82", -1); // Incomplete 3-byte sequence
//    test_my_utf8_check("\xF0\x90\x8D", -1); // Incomplete 4-byte sequence
//
//    // Invalid UTF-8 sequences
//    test_my_utf8_check("\xC3\xC3", -1); // Overlapping 2-byte sequences
//    test_my_utf8_check("\xE2\x82\xE2", -1); // Overlapping 3-byte sequences
//    test_my_utf8_check("\xF0\x90\x8D\xF0", -1); // Overlapping 4-byte sequences
//
//    // Valid and invalid sequences combined
//    test_my_utf8_check("a\xC3\xA9\xE2\x82\xAC\xC3\xC3\xE2\x82\xE2\xF0\x90\x8D\xF0", -1);
//
//    // Valid sequence with ASCII characters
//    test_my_utf8_check("a\xC3\xA9xyz", 0);
//
//    // Large string with valid sequences
//    char largeString[10000];
//    for (int i = 0; i < 9999; i += 3) {
//        largeString[i] = 'a';
//        largeString[i + 1] = '\xC3';
//        largeString[i + 2] = '\xA9';
//    }
//    largeString[9999] = '\0';
//    test_my_utf8_check(largeString, 0);
//}
//
//void test_my_utf8_encode(char *input, char *expected) {
//    char output[1000];  // Adjust the size based on your maximum expected output
//    int result = my_utf8_encode(input, output);
//
//    const char* resultString = (result == 0 && my_strcmp(output, expected) == 0) ? "PASSED" : "FAILED";
//
//    printf("Test %s - my_utf8_encode\n", resultString);
//    printf("  Input   : \"%s\"\n", input);
//    printf("  Expected: \"%s\"\n", expected);
//    printf("  Actual  : \"%s\"\n", output);
//    printf("\n");
//}
//
//void my_utf8_encode_tests() {
//    // Basic tests
//    test_my_utf8_encode("", "");
//    test_my_utf8_encode("Hello, world!", "Hello, world!");
//
//    // Tests with valid UTF-8 characters
//    test_my_utf8_encode("\\u05D0\\u05E8\\u05D9\\u05D4", "אריה"); // Hebrew characters
//
//    // Edge cases
//    test_my_utf8_encode("\\uFFFF", ""); // Invalid Unicode point, expected empty string
//
//    // Invalid hex characters
//    test_my_utf8_encode("\\u0G12", "[INVALID_UNICODE]G12");
//
//    // Unicode points with different lengths
//    test_my_utf8_encode("\\u1234", "ሴ");
//    test_my_utf8_encode("\\u1F602", "😂");
//
//    // Multiple Unicode points
//    test_my_utf8_encode("This is \\u0041 \\u0042 test.", "This is A B test.");
//
//    // Combining invalid and valid sequences
//    test_my_utf8_encode("\\u0041 \\uZZZZ \\u0042 \\u03A9", "A [INVALID_UNICODE] B Ω");
//
//    // Very long input string
//    char longInput[1001];
//    for (int i = 0; i < 1000; ++i) {
//        longInput[i] = '\\';
//    }
//    longInput[1000] = '\0';
//    test_my_utf8_encode(longInput, ""); // Expected empty string due to invalid Unicode point
//}
//
//
//int main() {
//    //printf("** TESTING STRLEN FUNCTION **\n");
//    my_utf8_strlen_tests();
//    //my_utf8_encode_tests();
//    my_utf8_strcmp_tests();
//    my_utf8_check_tests();
//    return 0;
//}
