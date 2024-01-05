//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_LINE_LENGTH 256
//
//const char *getEmojiName(const char *emoji, const char *filename) {
//    FILE *file = fopen(filename, "r");
//
//    if (file == NULL) {
//        fprintf(stderr, "Error opening file: %s\n", filename);
//        return NULL;
//    }
//
//    char line[MAX_LINE_LENGTH];
//
//    // Search for the line containing the emoji
//    while (fgets(line, sizeof(line), file) != NULL) {
//        // Check if the line contains the emoji
//        if (strstr(line, emoji) != NULL) {
//            // Process the line (e.g., tokenize it using strtok)
//            char *token = strtok(line, ",");
//            token = strtok(NULL, ",");
//            // Assuming the emoji name is the first field in the CSV
//            if (token != NULL) {
//                fclose(file);
//                return token;
//            } else {
//                fprintf(stderr, "Emoji name not found in the line.\n");
//                fclose(file);
//                return NULL;
//            }
//        }
//    }
//
//    fprintf(stderr, "Emoji not found in the file.\n");
//    fclose(file);
//    return NULL;
//}
//
//const char *getEmojiByEmojiName(const char *emojiName, const char *filename) {
//    FILE *file = fopen(filename, "r");
//
//    if (file == NULL) {
//        fprintf(stderr, "Error opening file: %s\n", filename);
//        return NULL;
//    }
//
//    char line[MAX_LINE_LENGTH];
//
//    // Search for the line containing the emoji name
//    while (fgets(line, sizeof(line), file) != NULL) {
//        // Process the line (e.g., tokenize it using strtok)
//        char *token = strtok(line, ",");
//        // Move to the second field (emoji name)
//        token = strtok(NULL, ",");
//
//        if (token != NULL) {
//            // Remove leading/trailing whitespaces
//            while (*token == ' ' || *token == '\t') {
//                ++token;
//            }
//
//            size_t len = strlen(token);
//            while (len > 0 && (token[len - 1] == ' ' || token[len - 1] == '\t' || token[len - 1] == '\n')) {
//                token[--len] = '\0';
//            }
//
//            // Check if the emoji name matches
//            if (strcmp(token, emojiName) == 0) {
//                // Move back to the first field (emoji)
//                token = strtok(line, ",");
//                // Remove leading/trailing whitespaces
//                while (*token == ' ' || *token == '\t') {
//                    ++token;
//                }
//
//                size_t len = strlen(token);
//                while (len > 0 && (token[len - 1] == ' ' || token[len - 1] == '\t' || token[len - 1] == '\n')) {
//                    token[--len] = '\0';
//                }
//
//                fclose(file);
//                return token;
//            }
//        }
//    }
//
//    fprintf(stderr, "Emoji name not found in the file.\n");
//    fclose(file);
//    return NULL;
//}
//
//
//
////int main() {
////    const char *filename = "emoji_df.csv";
////    const char *emoji = "😀";  // Replace with the desired emoji
////    const char *emojiN = "melting face";
////
////    const char *emojiName = getEmojiName(emoji, filename);
////
////    if (emojiName != NULL) {
////        printf("Emoji Name: %s\n", emojiName);
////    } else {
////        printf("Unable to find the emoji or its name.\n");
////    }
////
////    const char *emojil = getEmojiByEmojiName(emojiN, filename);
////
////    if (emojil != NULL) {
////        printf("Emoji: %s\n", emojil);
////    } else {
////        printf("Unable to find the emoji or its name.\n");
////    }
////    return 0;
////}
//#include <stdio.h>
//#define MAX_LINE_LENGTH 256
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