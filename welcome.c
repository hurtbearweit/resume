#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"welcome.h"
/*********************************************
FUNCTION:page_welcome
DESCRIPTION：welcome people to use
INPUT:void
RETURN:0
***********************************************/
void page_welcome(void)
{
	delay(200);
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,648,480);
	puthz(135,200,"简历设计辅助系统",48,48,BLACK);
	delay(1000);
}
