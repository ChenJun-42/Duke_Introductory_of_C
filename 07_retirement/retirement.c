#include <stdlib.h>
#include <stdio.h>

struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void  cal_saving(int *age, double *saving, retire_info x)
{
  int i = 0;
  while (i < x.months)
    {
      printf("Age %3d month %2d you have $%.2lf\n", *age / 12, *age % 12, *saving);
      *saving = (*saving) * (1 + (x.rate_of_return)) + x.contribution;
      (*age)++;
      i++;
    }
}

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  double saving = initial;
  int age = startAge;

  cal_saving(&age, &saving, working);
  cal_saving(&age, &saving, retired);
}

int main(void)
{
  retire_info working;
  retire_info retired;
  int startAge;
  double initial;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12;
  
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;
  
  startAge = 327;
  initial = 21345;
  retirement(startAge, initial, working, retired);
  return 0;
}
