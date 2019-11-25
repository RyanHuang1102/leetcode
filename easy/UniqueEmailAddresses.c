#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void normalizeEmail(char* email, char *ret)
{
	int i = 0, index = 0;
	int skip = 0;
	// check local name
	while(email[i++] != 0)
	{
		if (email[i-1] == '@')
		{
			ret[index++] = email[i-1];
			break;
		}
		else if (skip || email[i-1] == '.')
			continue;
		else if (email[i-1] == '+')
		{
			skip = 1;
			continue;
		}
		ret[index++] = email[i-1];
	}
	// domain name
	while (email[i++] != 0)
	{
		ret[index++] = email[i-1];
	}

}

int numUniqueEmails(char **emails, int emailsSize)
{

	//printf("%s, size:%u\n", emails[0], emailsSize);
	int i = 0 ;
	int diff = 0 ;
	char *ret = calloc(128, sizeof(char));
	char *mem = calloc(128, sizeof(char));

	while( i < emailsSize)
	{
		normalizeEmail(emails[i], ret);
		printf("ret :%s\n", ret);
		if (strcmp(ret, mem))
		{
			strcpy(mem, ret);
			printf("mem:%s\n", ret);
			diff++;
		}
		i++;
	}

	printf("diff:%d\n", diff);

	free(ret);
	free(mem);

	return diff;

}

void main()
{
	char *emails[]={"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
	unsigned int sizes = sizeof(emails)/sizeof(char*);

	numUniqueEmails(emails, sizes);
}
