#include <stdio.h>

//Program for encrypting/decrypting with a one-time pad
void main(int argc, char** args)
{
  char s[100];
  FILE *in, *out, *key;
  int c_in, c_out, c_key;

  printf("\nONE-TIME PAD ENCRYPTOR ;)\n\n");

  if(argc==3)
  {
    if((in=fopen(args[1], "r")) == NULL)
    {
      printf("Input file not found.\n");
      return;
    }
    if((key=fopen(args[2], "r")) == NULL)
    {
      printf("Key file not found.\n");
      return;
    }
  }
  else
  {
    printf("Input file name: ");
    scanf("%99s", s);
    if((in=fopen(s, "r")) == NULL)
    {
      printf("Input file not found.\n");
      return;
    }
    printf("Key file name: ");
    scanf("%99s", s);
    if((key=fopen(s, "r")) == NULL)
    {
      printf("Key file not found.\n");
      return;
    }

  }
  out = fopen("out", "w");
  printf("Writing to 'out'...\n");

  while(1)
  {
    if((c_in=fgetc(in)) == EOF)
    {
      printf("End of Input reached.\n");
      return;
    }
    if((c_key=fgetc(key)) == EOF)
    {
      printf("End of key reached.\n");
      return;
    }
    c_out = c_in ^ c_key;
    fputc(c_out, out);
  }

  fclose(in);
  fclose(out);
  fclose(key);
}
