#include "main.h"
/**
*cap_string - function that capitalize first character of a word
*@str: string to capitalize
*Return:returns the capitalized string
*/
/*char *cap_string(char *str)
{
int index = 0;

while (str[++index])
{
while (!(str[index] >= 'a' && str[index] <= 'z'))
index++;

if (str[index - 1] == ' ' || str[index - 1] == '\t' || str[index - 1] == '\n' || str[index - 1] == ',' || str[index - 1] == ';' || str[index - 1] == '.' || str[index - 1] == '!' || str[index - 1] == '?' || str[index - 1] == '"' || str[index - 1] == '(' || str[index - 1] == ')' || str[index - 1] == '{' || str[index - 1] == '}')
str[index] -= 32;
}
return (str);
}
*/
char* cap_string(char* str) {
int len = strlen(str);
int i;
// Capitalize the first letter of the string
str[0] = toupper(str[0]);

// Loop through the string, looking for separators
for (i = 1; i < len; i++) 
{
if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',' || str[i] == ';' || str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == '"' || str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}') 
{
// Capitalize the next character after the separator
str[i+1] = toupper(str[i+1]);
}
}

return str;
}
