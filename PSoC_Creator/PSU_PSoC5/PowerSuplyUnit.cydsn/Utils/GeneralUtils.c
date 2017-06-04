

#include <device.h>
#include "Utils\GeneralUtils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void ProgramVersion(PCHAR buffer) {//вывод версии программы
const CHAR * csMonths[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
BYTE Mon, Day, Year, Hour, Min;
CHAR ch[20];
INT i;
 // example "Oct 30 2010". *
  strcpy(ch, __DATE__);
  if (ch[4] >= '0') Day = (ch[4] - '0') * 10;
  else Day = 0;
  Day += ch[5] - '0';

  Year = (ch[9] - '0') * 10;
  Year += ch[10] - '0';

  ch[3] = 0;
  Mon = 0;
  for(i = 0; i < 12; ++i) {
    if (strcmp(csMonths[i], ch) == 0) {
      Mon = i + 1;
      break;
    }
  }

  strcpy(ch, __TIME__);   //the form "hh:mm:ss".*
  Hour = (ch[0] - '0') * 10;
  Hour += ch[1] - '0';
  Min = (ch[3] - '0') * 10;
  Min += ch[4] - '0';
  sprintf(buffer, "v%u.%u %02d%02d%02d.%02d%02d", PROGRAM_VERSION_MAJOR, PROGRAM_VERSION_MINOR, Year, Mon, Day, Hour, Min);
}
