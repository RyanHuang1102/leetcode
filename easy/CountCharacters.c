#include <stdio.h>
#include <string.h>

int countCharacters(char ** words, int wordsSize, char * chars) {
    int len = strlen(chars);
    int chararray[26] = {0};
    int tmp = 0;
    int count = 0;
    int idx = 0;

    for (int i = 0; i < len; i++)
    {
        chararray[chars[i]-'a']++; // set nums of char(a-z);
    }

    for (int i = 0 ; i < wordsSize; i++)
    {
        int wordsarray[26] = {0};

        while(words[i][idx] != 0 )
        {
            tmp = ++wordsarray[words[i][idx] - 'a'];
            if (tmp > chararray[words[i][idx] - 'a'])
                break;
            idx++;
        }

        if (words[i][idx] == 0)
        {
            count+=strlen(*(words+i)) ;//words[i]
        }
        idx = 0;
    }
    return count;
}

void main(void)
{
    char *words[] = {"hello","world","leetcode"};
    char *chars = "welldonehoneyr";
    int wordsize = sizeof(words)/sizeof(char *);
    int ret;

    //printf("worldsize:%d\n", wordsize);
    ret = countCharacters(words, wordsize, chars);
    printf("counts:%d\n", ret);
}
