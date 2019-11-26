#include <stdio.h>
#include <string.h>

void reverse(char *s,int start, int end)
{
	char tmp;

	while (start < end)
	{
		tmp = s[start];
		s[start] = s[end-1];
		s[end-1] = tmp;
		start++;
		end--;
	}
}

void reverseWords(char* s)
{
	int start;
	int len = strlen(s);

	for (int i = 0; i <= len; i++)
	{
		if (s[i] == ' ' || s[i] == '\0'){
			reverse(s, start, i);
			start = i+1;
		}
	}

}

int main()
{
	char arr[]={"Let's take LeetCode contest"};
	printf("%s\n", arr);
	char *ret;
	
	reverseWords(arr);
	printf("%s\n", arr);

}
