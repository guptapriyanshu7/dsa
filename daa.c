#include <stdio.h>
#include <string.h>

void stringcount(char* s)
{
	static  int i, vowels = 0, consonants = 0;

	if (!s[i])
	{
		printf("%d", vowels);
		return;
	}
	else
	{

		if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
		{

			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
				vowels++;
			else
				consonants++;
		}
		i++;
		stringcount(s);
	}
}
int main()
{
	char s[1000];
	gets(s);
	stringcount(s);
}