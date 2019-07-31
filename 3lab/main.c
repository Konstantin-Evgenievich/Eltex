
/*
9
Фамилия спортсмена 
Вид спорта 
Количество медалей
Расположить в алфавитном порядке записи с ненулевым количеством медалей 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
*/

typedef struct {
	char surname[50];
	char sport[50];
	int kol;
} book;

void readBooks(book * st)
{
	printf("Введите фамилию спортсмена ");
	scanf("%s", st->surname);
	printf("Введите вид спорта: ");
	scanf("%s", st->sport);
	printf("Введите количество медалей");
	scanf("%d", &st->kol);
	printf("----------------------------------------\n\n");
}

static int cmp(const void *p1, const void *p2)
{
	book *st1 = *(book **) p1;
	book *st2 = *(book **) p2;
	return strcmp(st1->surname, st2->surname);
}

int main(int argc, char **argv)
{
	int count = 0;
	printf("Введите количество спортсменов: ");
	scanf("%d", &count);
	printf("----------------------------------------\n\n");
	book **st = (book **) malloc(sizeof (book *) * count);
	for (int i = 0; i < count; i++) {
		st[i] = (book *) malloc(sizeof (book));
		readBooks(st[i]);
	}
	printf("\tСортировка по названию\n\n");
	qsort(st, count, sizeof (book *), cmp);
	for (int i = 0; i < count; i++) {
		if (st[i]->kol != 0) {
			printf("Номер спортсмена %d\n", i + 1);
			printf("\t-------------\n\n");
			printf("Фамилия спорстмена: %s\n",
			       st[i]->surname);
			printf("Вид спорта: %s\n", st[i]->sport);
			printf("Колличество медалей: %d\n",
			       st[i]->kol);
			printf("\n");
		}
	}

	for (int i = 0; i < count; i++) {

		free(st[i]);
	}
	free(st);
	return 0;
}
