#include <stdio.h>
#include <ctype.h>

int findStringLen(char str[]) {
    int totChar = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        totChar++;
    }
    return totChar;
}

void changeFirstIndex(char str[], int len) {    
    // swap first and last index
    char temp = str[0];
    for(int i = 0; i < len; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = temp;
}

void translateWordsPigLatin(char eng[], int len) {
    changeFirstIndex(eng, len);
    // add 'ay'
    eng[len] = 'a';
    eng[len + 1] = 'y';
    eng[len + 2] = '\0';
}

void resetString(char str[], int len) {
    for (int i = 0; i < len; i++) {
        str[i] = '\0';
    }
}

int concatStr(char result[], char str[], int start, int end) {
    int j = 0;
    int i;
    result[start] = ' ';
    for (i = start; i <= end; i++) {
        result[i + 1] = str[j++];
    }

    return i+1;
}

// set max 20 words per space
char tempWords[20] = { '\0' };
int tempWordsLen = 0;
int tempIndex = 0;

int translate(char pigLatin[], int lastPigLatinIndex) {
    tempWordsLen = findStringLen(tempWords);
    translateWordsPigLatin(tempWords, tempWordsLen);
    tempWordsLen = findStringLen(tempWords);
    return concatStr(pigLatin, tempWords, lastPigLatinIndex, lastPigLatinIndex + tempWordsLen - 1);
}

void translateSentencePigLatin(char eng[], char pigLatin[]) {
    int lastPigLatinIndex = 0;
    for(int i = 0; eng[i] != '\0'; i++) {
        if (eng[i] == ' ') {
            // let's translate
            lastPigLatinIndex = translate(pigLatin, lastPigLatinIndex);

            // reset
            resetString(tempWords, 20);
            tempIndex = 0;
        } else {
            tempWords[tempIndex++] = eng[i];
        }
    }
    // Process the last words
    lastPigLatinIndex = translate(pigLatin, lastPigLatinIndex);
}

int main() {
    char sentence[] = "The quick brown fox";
    printf("English: %s\n", sentence);

    char pigLatin[100] = { '\0' };
    translateSentencePigLatin(sentence, pigLatin);
    printf("Pig Latin: %s\n", pigLatin);

    return 0;
}