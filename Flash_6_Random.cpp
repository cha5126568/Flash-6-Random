#include<stdio.h>
#include<windows.h>

int a1,a2;

int __cdecl sub_413B60(unsigned int seed) //seed == timeGetTime()
{
  DWORD v1;
  int result;

  v1 = seed;
  result = a1;
  a1 = v1 & 0x7FFFFFFF;
  a2 = 0x48000000;
  return result;
}


int  sub_413B90(signed int a1) //srand
{
  signed int v1;

  v1 = (a1 ^ (a1 << 13))
     - (a1 >> 21)
     + ((((a1 ^ (a1 << 13)) - (a1 >> 21))
       * (15731 * ((a1 ^ (a1 << 13)) - (a1 >> 21)) * ((a1 ^ (a1 << 13)) - (a1 >> 21)) + 789221)
       - 771171059) & 0x7FFFFFFF);
  return (v1 ^ (v1 << 13)) - (v1 >> 21);
}

int Rrand()
{
  unsigned int v1;
  int v2;

  v1 = a1;
  if ( a1 & 1 )
    v2 = a2 ^ (v1 >> 1);
  else
    v2 = v1 >> 1;
  a1 = v2;
  return sub_413B90(71 * v2) & 0x7FFFFFFF;
}


int main(void)
{
   for(auto i=0u;i<=300000;i++)
   {
      sub_413B60(i);
      if(Rrand()%10+1 == 2)
      	if(Rrand()%10+1 == 5)
      		if(Rrand()%10+1 == 7)
      			if(Rrand()%10+1 == 9)
      				if(Rrand()%10+1 == 8)
         				printf("Seed : %d Next : %d\n",i,Rrand()%10+1);
   }
   
}

