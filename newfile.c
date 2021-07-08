#include <stdio.h>
#include <conio.h>
#include <c64.h>
#include <cbm_petscii_charmap.h>
#include <string.h>
#include <peekpoke.h>

void main(void) 
{
  int src = 0xE000;
  int length = 400;
  int dest = 0x0400 + 80;
  int dest2 = 0x0400 + 120 + length;
  int start, end, x = 0;
  VIC.bordercolor = 0;
  
  clrscr();
  
  while (1)
  {
    while (VIC.rasterline !=0)
    {
    }
    //clrscr();
    while (VIC.rasterline != 0)
    {
    }
    //start = VIC.rasterline;
    memcpy((int*) dest, (int*) src, length);
    //end = VIC.rasterline - start;
    //printf("%d\n", end);
    
    while (VIC.rasterline != 0)
    {
    }
    //start = VIC.rasterline;
    for (x = 0; x < length; x++)
    {
      POKEW(dest2 + x, PEEKW(src + x));
    }
    end = VIC.rasterline - start;
    //printf("%d\n", end);
    src++;
  }
}
