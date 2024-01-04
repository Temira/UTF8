#include <stdio.h>
////#include <stdlib.h>
////#include <string.h>
////#include <time.h>
//#define MAX_LINE_LENGTH 256
////
////
////#include <stdio.h>
////
////    char *hexToBinary(char *hex, int length)
////    {
////        char *binary = (char*) malloc(length * 5 + 1);
////        if(binary == NULL)
////            exit(1);
////        while(*hex != '\0')
////        {
////            char *binaryValue = valueOf(*hex);
////            while(*binaryValue != '\0')
////                *binary++ = *binaryValue++;
////            ++hex;
////        }
////        *binary = '\0';
////        binary -= length * 5;
////        return binary;
////    }
////    int main(void)
////    {
////        char hex[101];
////        int length;
////        int validation;
////        char *binary;
////        scanf("%100s", hex);
////        length = strlen(hex);
////        binary = hexToBinary(hex, length);
////        printf("%s in hexadecimal is %sin binary\n", hex, binary);
////        return 0;
////    }
////// Function to check if a byte is the start of a UTF-8 character
////int isUtf8_StartByte(unsigned char byte) {
////    return (byte & 0xC0) != 0x80;
////}
////
////// Function to check if a byte is a continuation byte in a UTF-8 character
////int isUtf8_ContinuationByte(unsigned char byte) {
////    return (byte & 0xC0) == 0x80;
////}
////
////// Function to determine the length of a UTF-8 character based on its start byte
////int check_Char_length(char *str) {
////    int length;
////    switch (*str & 0xF0) {
////        case 0x00:
////            length = 1; // One byte character sequence
////            break;
////        case 0xC0:
////            length = 2; // Two bytes
////            break;
////        case 0xE0:
////            length = 3; // Three bytes
////            break;
////        case 0xF0:
////            length = 4; // Four bytes
////            break;
////        default:
////            length = 1; // Handle unexpected start byte
////            break;
////    }
////    return length;
////}
////
////// Function to print the UTF-8 encoding of a string
////void print_utf8_encoding(const char *str) {
////    while (*str) {
////        if (isUtf8_StartByte(*str)) {
////            // Determine the length
////            int length = check_Char_length((char *)str);
////
////            // Print the entire UTF-8 encoding for each character on a single line
////            printf("UTF-8 encoding: ");
////
////            // Print the bytes of the UTF-8 encoding
////            for (int i = 0; i < length && *str; ++i) {
////                printf("0x%x ", (unsigned char)str[i]);
////            }
////            printf("\n");
////
////            // Move to the next character
////            str += length;
////        } else {
////            // Skip continuation bytes
////            ++str;
////        }
////    }
////}
////
////// Function to check the validity of UTF-8 encoding
////int my_utf8_check(const char *str) {
////    while (*str) {
////        if (isUtf8_StartByte(*str)) {
////            int char_length = check_Char_length((char *)str);
////
////            // Validate appropriate continuation bytes starting from the second byte
////            for (int i = 1; i < char_length; ++i) {
////                if (!isUtf8_ContinuationByte(str[i])) {
////                    fprintf(stderr, "Error: Unexpected continuation byte.\n");
////                    return 0;
////                }
////            }
////
////            // Move the pointer to the next UTF-8 character
////            str += char_length;
////        } else {
////            // Handle unexpected continuation byte
////            fprintf(stderr, "Error: Unexpected continuation byte.\n");
////            return 0;
////        }
////    }
////    return 1;
////}
////
////// Function to get a random emoji name
////const char *randomEmoji() {
////    int array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
////    time_t t;
////    srand((unsigned)time(&t));
////
////    int numy = array[rand() % 12];
////
////    const char *emojiName;
////
////    switch (numy) {
////        case 1:
////            emojiName = "red heart";
////            break;
////        case 2:
////            emojiName = "robot";
////            break;
////        case 3:
////            emojiName = "smiling face with horns";
////            break;
////        case 4:
////            emojiName = "smiling face with sunglasses";
////            break;
////        case 5:
////            emojiName = "face with spiral eyes";
////            break;
////        case 6:
////            emojiName = "face with rolling eyes";
////            break;
////        case 7:
////            emojiName = "saluting face";
////            break;
////        case 8:
////            emojiName = "winking face";
////            break;
////        case 9:
////            emojiName = "hot face";
////            break;
////        case 10:
////            emojiName = "loudly crying face";
////            break;
////        case 11:
////            emojiName = "sparkles";
////            break;
////        case 12:
////            emojiName = "cherry blossom";
////            break;
////    }
////    return emojiName;
////}
////
////
////// Function to print the user's selected emoji name
////const char *printemoji() {
////    int choice;
////
////    // Make a choice
////    printf("How do you feel today?\n  1. Happy\n  2. Ecstatic\n  3. Silly\n  4. Sad\n  5. Angry\n  6. Like Temira\n  7. Random!!!\n");
////
////    // Take the user's input and put it in the variable choice
////    scanf("%d", &choice);
////
////    // Declare emojiName outside the switch block to ensure it's in scope
////    const char *emojiName;
////
////    // Use a switch statement for better readability
////    switch (choice) {
////        case 1:
////            emojiName = "smiling face with smiling eyes";
////            break;
////        case 2:
////            emojiName = "star-struck";
////            break;
////        case 3:
////            emojiName = "zany face";
////            break;
////        case 4:
////            emojiName = "crying face";
////            break;
////        case 5:
////            emojiName = "face with steam from nose";
////            break;
////        case 6:
////            emojiName = "yawning face";
////            break;
////        case 7:
////            emojiName = randomEmoji();
////            break;
////        default:
////            printf("Invalid choice\n");
////            return NULL; // Return or exit the function if the choice is invalid
////    }
////
////    // Print the selected emoji name
////    //printf("You chose: %s\n", emojiName);
////
////    // Print the UTF-8 encoding of the emoji itself
////    //print_utf8_encoding(emojiName);
////
////    // Check the validity of UTF-8 encoding
////    my_utf8_check(emojiName);
////
////    return emojiName;
////}
////
////// Function to get the emoji corresponding to a given emoji name
////void getEmojiByEmojiName(const char *filename) {
////    const char *emojiName = printemoji();
////
////    FILE *file = fopen(filename, "r");
////
////    if (file == NULL) {
////        fprintf(stderr, "Error opening file: %s\n", filename);
////        return;
////    }
////
////    char line[MAX_LINE_LENGTH];
////
////    // Search for the line containing the emoji name
////    while (fgets(line, sizeof(line), file) != NULL) {
////        // Process the line (e.g., tokenize it using strtok)
////        char *token = strtok(line, ",");
////        // Move to the second field (emoji name)
////        token = strtok(NULL, ",");
////
////        if (token != NULL) {
////            // Remove leading/trailing whitespaces
////            while (*token == ' ' || *token == '\t') {
////                ++token;
////            }
////
////            size_t len = strlen(token);
////            while (len > 0 && (token[len - 1] == ' ' || token[len - 1] == '\t' || token[len - 1] == '\n')) {
////                token[--len] = '\0';
////            }
////
////            // Check if the emoji name matches
////            if (strcmp(token, emojiName) == 0) {
////                // Move back to the first field (emoji)
////                token = strtok(line, ",");
////                // Remove leading/trailing whitespaces
////                while (*token == ' ' || *token == '\t') {
////                    ++token;
////                }
////
////                size_t len = strlen(token);
////                while (len > 0 && (token[len - 1] == ' ' || token[len - 1] == '\t' || token[len - 1] == '\n')) {
////                    token[--len] = '\0';
////                }
////                printf("Emoji for %s: %s\n", emojiName, token);
////
////                // Print the UTF-8 encoding of the emoji itself
////                print_utf8_encoding(token);
////
////                // Check the validity of UTF-8 encoding
////                my_utf8_check(token);
////
////                fclose(file);
////                return;
////            }
////        }
////    }
////
////    fprintf(stderr, "Emoji name not found in the file.\n");
////    fclose(file);
////}
////
////int main(void) {
//////    const char str = 'א';;
//////    print_utf8_encoding(str);
////    char choice;
////    // Prompt the user to make a choice
////    printf("What would you like to do?\n  1. Print an emoji from the name\n  2. Print the name from the emoji\n");
////
////    // Take the user's input and put it in the variable choice
////    scanf("%d", &choice);
////
////    // Use a switch statement for better readability
////    switch (choice) {
////        case 1:
////            getEmojiByEmojiName("emoji_df.csv");  // Provide the filename as an argument
////            break;
////        case 2:
////
////            break;
////        default:
////            printf("Invalid choice\n");
////            break;
////    }
////
////    return 0;
////}
//
//#include <stdio.h>
//
//// Function to convert a hexadecimal string to unsigned long
//unsigned long hexStringToULong(const char *hex) {
//    unsigned long result = 0;
//    int i;
//    if (hex[0] == 'U' && hex[1] == '+'){
//        i = 2;}
//    else {i = 0;}
//    ;// Start from the third character to skip "U+"}
//
//    while (hex[i] != '\0') {
//        result = result * 16 + (hex[i] >= 'A' ? hex[i] - 'A' + 10 : hex[i] - '0');
//        i++;
//    }
//
//    return result;
//}
//
//// Function to determine the range based on the Unicode code point
//void determineRange(const char *codePoint) {
//    unsigned long value = hexStringToULong(codePoint);
//
//    // Determine the range based on the Unicode code point
//    if (value >= 0x0000 && value <= 0x007F) {
//        printf("Range 1\n"); // U+0000 to U+007F
//    } else if (value >= 0x0080 && value <= 0x07FF) {
//        printf("Range 2\n"); // U+0080 to U+07FF
//    } else if (value >= 0x0800 && value <= 0xFFFF) {
//        printf("Range 3\n"); // U+0800 to U+FFFF
//    } else if (value >= 0x10000 && value <= 0x10FFFF) {
//        printf("Range 4\n"); // U+10000 to U+10FFFF
//    } else {
//        printf("Invalid Unicode code point\n");
//    }
//}
//
//int main() {
//    determineRange("U+0024");    // Example: U+0024 (Range 1)
//    determineRange("U+0800");    // Example: U+0800 (Range 3)
//    determineRange("U+20AC");    // Example: U+20AC (Range 3)
//    determineRange("U+10348");   // Example: U+10348 (Range 4)
//    determineRange("10348");
//    return 0;
//}
//void main(){
//    int x = 0x1A20;
//    int y = 0x1A2E;
//
//    if (x >= y)
//    {
//        printf("x greater than y");
//    }
//    else
//    {
//        printf("x smaller than y");
//    }
//}