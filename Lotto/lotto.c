#include <stdio.h>

struct Choice
{
  unsigned *choices;
  unsigned n;
  unsigned pb;
  unsigned pbMatch;
  unsigned pbUB;
};

// choices: points to a null-terminated array of remaining choices
// n: the number of remaining trials
// fill: the next location in array that stores a ticket to be printed
// fillStart: the starting point of the array that stores a ticket to be printed
// param: void pointer to a structure for the call-back function
// cb: call back function when we are done with all trials
int genCombin(unsigned *choices, unsigned n, unsigned *fill, unsigned *fillStart, void *param, void (*cb)(void *param, unsigned *fill, unsigned *fillStart))
{
  int result = 0;
  if (n==0) 
  {
    result = 1;
    if (cb)
    {
      cb(param, fill, fillStart);
    }
  }
  else if (*choices == 0) // n != 0
  {
    result = 0;
  }
  else // n > 0 && *choices != 0
  {
    while (*choices != 0) // when I have alternatives 
    {
      *fill = *choices; // choose *choices as my pick in the ticket
      if (genCombin(choices+1, n-1, fill+1, fillStart, param, cb)) // recursive call
      {
      }
      else
      {
      }
      ++choices;
    }
  }
  return result;
}

void genPb(void *param, unsigned *fill, unsigned *fillStart)
{
  struct Choice *pC = (struct Choice *)param;
  unsigned i;
  for (i=1; i <= pC->pbUB; ++i)
  {
    if ((pC->pbMatch && i == pC->pb) || (!pC->pbMatch && i != pC->pb))
    {
      unsigned *ptr = fillStart;
      printf("{");
      while (ptr < fill)
      {
        if (ptr > fillStart)
        {
          printf(",");
        }
        printf("%u",*ptr);
        ++ptr;
      }
      printf("},%u\n",i);
    }
  }
}

void genUnlucky(void *param, unsigned *fill, unsigned *fillStart)
{
  struct Choice *pC = (struct Choice *)param;
  genCombin(pC->choices, pC->n, fill, fillStart, param, genPb);
}


int main()
{
  unsigned lucky[6], unlucky[69-5+1], powerball;
  unsigned winUB, pbUB;
  unsigned numWin, pbMatch;
  unsigned numbers[6];
  struct Choice unluckyChoice;
  scanf("%u", &winUB);
  scanf("%u", &pbUB);
  {
    unsigned i;
    for (i=0; i < 5; ++i)
    {
      scanf("%u", &lucky[i]);
    }
    lucky[5]= 0;
  }
  scanf("%u", &powerball);
  scanf("%u", &numWin);
  scanf("%u", &pbMatch);
  for (numbers[0]=1; numbers[0]<=winUB; ++numbers[0])
    for (numbers[1]=1+numbers[0]; numbers[1]<=winUB; ++numbers[1])
      for (numbers[2]=1+numbers[1]; numbers[2]<=winUB; ++numbers[2])
        for (numbers[3]=1+numbers[2]; numbers[3]<=winUB; ++numbers[3])
          for (numbers[4]=1+numbers[3]; numbers[4]<=winUB; ++numbers[4])
            for (numbers[5]=1; numbers[5]<=pbUB; ++numbers[5])
            {
              unsigned wtIndex, tIndex;
              unsigned matchCount;
              for (matchCount=0, wtIndex=0; wtIndex < 5; wtIndex++)
                for (tIndex=0; tIndex < 5; ++tIndex)
                {
                  matchCount = matchCount + (lucky[wtIndex] == numbers[tIndex] ? 1 : 0);
                }
              if (matchCount == numWin)
              {
                if ((pbMatch && numbers[5] == powerball) ||
                    (!pbMatch && numbers[5] != powerball))
                {
                  printf("{%u,%u,%u,%u,%u},%u\n",
                      numbers[0],
                      numbers[1],
                      numbers[2],
                      numbers[3],
                      numbers[4],
                      numbers[5]);
                }
              }
            }
  return 0;
}
