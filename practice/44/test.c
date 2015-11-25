#include "book.h"
#include "date.h"

int isLeapyear();
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
  int days1 = 0, days2 = 0;
  int k = 0;

  if (book.type == 0)
    k = 90;
  else if (book.type == 1)
    k = 10;
  else if (book.type == 2)
    k = 100;
  else if (book.type == 3)
    k = 5;

  int common_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  //date_borrowed
  for (int i = 0; i < date_borrowed.month - 1; i++)
    days1 += common_year[i];
  if (isLeapyear(&date_borrowed.year) && date_borrowed.month > 2)
    days1++;

  days1 += date_borrowed.day;
  if (date_borrowed.year != 1000)
    days1 += (date_borrowed.year - 1000) * 365 + (date_borrowed.year - 1001) / 4 - (date_borrowed.year - 1001) / 100 + (date_borrowed.year - 1001) / 400; //cbro

  //date_returned
  for (int i = 0; i < date_returned.month - 1; i++)
    days2 += common_year[i];
  if (isLeapyear(&date_returned.year) && date_returned.month > 2)
    days2++;

  days2 += date_returned.day;
  if (date_returned.year != 1000)
    days2 += (date_returned.year - 1000) * 365 + (date_returned.year - 1001) / 4 - (date_returned.year - 1001) / 100 + (date_returned.year - 1001) / 400; //cbro

  int i = 0, j = 0;
  int temp[2];
  while (j < 2) {
    if ((book.importance >> i) % 2 == 1) {
      temp[j] = i;
      j++;
    }
    i++;
  }
  if ((days2 - days1 + 1 - k) < 0)
    return 0;
  else
    return (days2 - days1 + 1 - k) * (temp[1] - temp[0] - 1);
}

int isLeapyear(int *year)
{
  if (*year % 400 == 0 || (*year % 4 == 0 && *year % 100 != 0))
    return 1;
  else
    return 0;
}
