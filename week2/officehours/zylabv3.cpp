#include <stdio.h>
#include <string.h>

int main()
{
  char array[1000];  // read into here
  char reverse[1000];
  int  i;            // position in the string
  int  j;
  while(1) // goes until I get 'q'
    {
      i = -1;
      do {
	i++;
	scanf("%c", &array[i]);
      } while(array[i]!='\n' && i < 999);

      array[i] = '\0';

      if ( strcmp(array,"quit")==0 || strcmp(array,"q")==0 )
	break;
      
      printf("%s\n",array);

      j=0;
      i=i-1;
      while(i>=0) {
	reverse[j] = array[i];
	i--;
	j++;
      }
      reverse[j] = '\0';
      printf("%s\n",reverse);
    }
 
  return 0;
}
