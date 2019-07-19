/*
 
						9 вариант		
			Расположить строки по возрастанию длины первого слова 
			Входные параметры:
			1. Массив 
			2. Размерность массива 
			Выходные параметры:
			1. Максимальная длина слова 
			2. Количество перестановок 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1024		/* максимальная длина строки */

int
inp_str (char *string, int maxlen)
{
  char buffer[MAX_LEN];
  scanf ("%[^\n]", buffer);	// читаем строку в буфер
  getchar ();
  strncpy (string, buffer, maxlen);	//копируем maxlen
  size_t len = strlen (buffer);
  return (int) len;
}

int
inp_str2 (char **string, int maxlen)
{
  char buffer[MAX_LEN];
  char bufflen[MAX_LEN];
  sprintf (bufflen, "%%%ds", maxlen);
  scanf (bufflen, buffer);	// читаем строку в буфер
  size_t len = strlen (buffer);
  *string = (char *) malloc (sizeof (char) * len);	//выделяем память для строки
  strcpy (*string, buffer);	//копируем строку из буфера в массив указателей
  return (int) len;
}

char **
readMas (int count, char **mas, int maxlen)
{
  for (int i = 0; i < count; i++)
    {
      mas[i] = (char *) malloc (sizeof (char) * maxlen);	//выделяем память для строки
      inp_str (mas[i], maxlen);
    }
  return mas;
}

void
printMas (char **mas, int count)
{
  for (int i = 0; i < count; i++)
    {
      printf ("%s\n", mas[i]);
    }
}

void
freeMas (char **mas, int count)
{
  for (int i = 0; i < count; i++)
    {
      free (mas[i]);		// освобождаем память для отдельной строки
    }
  free (mas);			// освобождаем памать для массива указателей на строки
}

int
getLenFirst (char *str)
{
  int len = 0;
  for (int i = 0; i < strlen (str); i++)
    {
      if (str[i] != ' ')
	{
	  len++;
	}
      else
	{
	  break;
	}
    }
  return len;
}


int
bubleSort (char **mas, int n)
{
  int c = 0;
  int d = 0;
  int swichcount = 0;
  char *swap;
  for (c = 0; c < (n - 1); c++)
    {
      for (d = 0; d < n - c - 1; d++)
	{
	  if (getLenFirst (mas[d + 1]) < getLenFirst (mas[d]))
	    {
	      swap = mas[d];
	      mas[d] = mas[d + 1];
	      mas[d + 1] = swap;
	      swichcount++;
	    }
	}
    }
  return swichcount;
}

int
main (int argc, char **argv)
{
  char **mas = NULL;		//указатель на массив указателей на строки
  int count = 3;
  printf ("Введите кол-во строк:");
  scanf ("%d", &count);
  getchar ();
  printf ("Введите строку:\n");
  mas = (char **) malloc (sizeof (char *) * count);	// выделяем память для массива указателей
  mas = readMas (count, mas, MAX_LEN);
  int swichcount = bubleSort (mas, count);
  printf ("Сортированный список:возрастание\n");
  printMas (mas, count);
  printf ("Кол-во перестановок:");
  printf ("%d\n", swichcount);
  freeMas (mas, count);
}
