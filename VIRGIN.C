#include"VIRGIN.H"
#include"mouse.h"
#include"hz.h"
#include<graphics.h>
#include"CHOOSE.H"
#include"INFO.H"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LOG.H"
#include"INFO.H"
#include"input.h"
#include"HOME.H"
#include"save.H"
/*********************************************
FUNCTION:page_classic
DESCRIPTION??use the classic template
INPUT:pinfo_page
RETURN:3,
***********************************************/
int page_virgin(int *x,int* pinfo_page, int psave[], int ifin[][6], int pos[], int* template_page,int *ifadd,int *count,int turn[])
{
	unsigned s;
	void* p;

	int i[5] = { 0 };
    int addlength[2] = {200,126};
	int add[2] = {0,0};
	int i1 = 65, i2 = 151, i3 = 150, i4 = 108;
	i[0] = pos[0] * i1;//求职意向的长度
	i[1] = pos[0] * i1 + pos[1] * i2;//教育信息
	i[2] = i[1] + pos[5] * i3;//
	i[3] = pos[0] * i1 + pos[1] * i2 + pos[5] * i3 + pos[3] * i4;
    if (*ifadd != 2)
	{
		pos[2] = 1;
		pos[6] = 1;
	}
	if (pos[6] == 0)
	{
		add[0] = addlength[0];
	}
	if (pos[2] == 0)
	{
		add[1] = addlength[1];
	}
	*template_page = 2;
	//memset(&b,'\0',sizeof(BASIC));
	page_virgin_draw(*x, psave, ifin, pos);
	//line(400,0,400,480);
	//rectangle(400,326,580,350);
	while (1)
	{
		if (MouseS != 0
			&& mouse_press(610, 0, 640, 45) == 0
			&& mouse_press(610, 430, 640, 480) == 0
			&& mouse_press(610, 45, 640, 80) == 0
			&& mouse_press(610, 395, 640, 430) == 0
			&& mouse_press(0, 0, 500, 90 + *x) == 0
			&& mouse_press(0, 90 + *x, 500, 160 + *x) == 0
			&& mouse_press(0, 155 + *x, 500, 311 + *x) == 0
			&& mouse_press(0, 311 + *x, 500, 437 + *x) == 0
			&& mouse_press(0, 437 + *x, 500, 545 + *x) == 0
			&& mouse_press(0, 545 + *x, 500, 745 + *x) == 0)
		{
			MouseS = 0;
		}
		newmouse(&MouseX, &MouseY, &press);
		delay(40);
		if (MouseX>580&&MouseX<600&&MouseY>10+*x&&MouseY<30+*x)    //添加模块
		{
			if (mouse_press(580,10+*x,600,30+*x) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580,10+*x,600,30+*x) == 1)
			{
				clrmous(MouseX,MouseY);
				return 12;
			}
		}
        if (MouseX > 0 && MouseX < 500 && MouseY>0 && MouseY < 90 + *x)//姓名 line(0,70+x+20,610,70+x+25);
		{
			if (mouse_press(0, 0, 500, 90 + *x) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				virgin_border(0, 0, 500, 90 + *x, 1);
			}
			if (mouse_press(0, 0, 500, 90 + *x) == 1)
			{
				*pinfo_page = 1;
				delay(100);
				return 11;
			}
		}
		else virgin_border(0, 0, 500, 90 + *x, 0);
		if (MouseX > 0 && MouseX < 500 && MouseY>90 + *x && MouseY < 155 + *x && pos[0] == 0)//求职意向 line(0,125+x+35-i[0],610,125+x+35-i[0]);
		{
			if (mouse_press(0, 90 + *x, 500, 160 + *x) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				virgin_border(0, 97 + *x, 500, 157 + *x, 1);
			}
			if (mouse_press(0, 97 + *x, 500, 157 + *x) == 1)
			{
				*pinfo_page = 2;
				delay(100);
				return 11;
			}
		}
		else virgin_border(0, 97 + *x, 500, 157 + *x, 0);
		if (MouseX > 0 && MouseX < 500 && MouseY>155 + *x - i[0] && MouseY < 311 + *x - i[0] && pos[1] == 0)//教育经历 line(0,266+x+45-i[1],610,266+x+45-i[1]);
		{
			if (mouse_press(0, 155 + *x- i[0], 500, 311 + *x - i[0]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				virgin_border(0, 163 + *x - i[0], 500, 306 + *x - i[0], 1);
			}
			if (mouse_press(0, 155 + *x - i[0], 500, 311 + *x - i[0]) == 1)
			{
				*pinfo_page = 3;
				delay(100);
				return 11;
			}
		}
		else virgin_border(0, 163 + *x - i[0], 500, 306 + *x - i[0], 0);
		if (MouseX > 0 && MouseX < 500 && MouseY>311 + *x - i[1] && MouseY < 467 + *x- i[1] && pos[5] == 0)//在校经历 line(0,382+x+55,610,382+x+55);
		{
			if (mouse_press(0, 311 + *x- i[1], 500, 467 + *x - i[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				virgin_border(0, 313 +*x - i[1], 500, 462 + *x - i[1], 1);
			}
			if (mouse_press(0, 311 + *x - i[1], 500, 467 + *x - i[1]) == 1)
			{
				*pinfo_page = 7;
				delay(100);
				return 11;
			}
		}
		else virgin_border(0, 313 + *x - i[1], 500, 462 + *x - i[1], 0);
		if (MouseX > 0 && MouseX < 500 && MouseY>467 + *x - i[2]+add[0]+add[1] && MouseY < 575 + *x- i[2]+add[0]+add[1] && pos[3] == 0)//技能信息 line(0, 480 + x + 65 , 610, 480 + x+ 65 );
		{
			if (mouse_press(0, 467 + *x - i[2]+add[0]+add[1], 500, 575 + *x - i[2]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				virgin_border(0, 469 + *x - i[2]+add[0]+add[1], 500, 570 + *x - i[2]+add[0]+add[1], 1);
			}
			if (mouse_press(0, 467 + *x - i[2]+add[0]+add[1], 500, 575 + *x - i[2]+add[0]+add[1]) == 1)
			{
				*pinfo_page = 5;
				delay(100);
				return 11;
			}
		}
		else virgin_border(0, 469 + *x - i[2]+add[0]+add[1], 500, 570 + *x - i[2]+add[0]+add[1], 0);
		if (MouseX > 0 && MouseX < 500 && MouseY>575 + *x- i[3]+add[0]+add[1] && MouseY < 775 + *x - i[3] +add[0]+add[1]&& pos[4] == 0)//自我评价 
		{
			if (mouse_press(0, 575 + *x- i[3]+add[0]+add[1], 500, 775 + *x - i[3]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				virgin_border(0, 577 + *x - i[3]+add[0]+add[1], 500, 770 + *x - i[3]+add[0]+add[1], 1);
			}
			if (mouse_press(0, 575 + *x- i[3]+add[0]+add[1], 500, 775 +*x - i[3]+add[0]+add[1]) == 1)
			{
				*pinfo_page = 6;
				delay(100);
				return 11;
			}
		}
		else virgin_border(0, 577+ *x - i[3]+add[0]+add[1], 500, 770 + *x - i[3]+add[0]+add[1], 0);
        if (MouseX > 0 && MouseX < 500 && MouseY>467+*x-i[2] && MouseY < 667+*x-i[2] && pos[6] == 0)//实习经历467+x-i[2]
		{
			if (mouse_press(0, 467+*x-i[2], 500, 667+*x-i[2]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				virgin_border(0, 469+*x-i[2], 500, 662+*x-i[2], 1);
			}
			if (mouse_press(0, 467+*x-i[2], 500, 667+*x-i[2]) == 1)
			{
				*pinfo_page = 8;
				delay(100);
				return 11;
			}
		}
		else virgin_border(0, 469+*x-i[2], 500, 662+*x-i[2], 0);
        if (MouseX > 0 && MouseX < 500 && MouseY>467+*x-i[2]+add[0] && MouseY < 593+*x-i[2]+add[0] && pos[2] == 0)//工作信息467+x-i[2]+add[0]
		{
			if (mouse_press(0, 467+*x-i[2]+add[0], 500, 593+*x-i[2]+add[0]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				virgin_border(0, 469+*x-i[2], 500, 588+*x-i[2]+add[0], 1);
			}
			if (mouse_press(0, 467+*x-i[2]+add[0], 500, 593+*x-i[2]+add[0]) == 1)
			{
				*pinfo_page = 4;
				delay(100);
				return 11;
			}
		}
		else virgin_border(0, 469+*x-i[2], 500, 588+*x-i[2]+add[0], 0);
		if (MouseX > 580 && MouseX < 600 && MouseY > 100 + *x && MouseY < 120 + *x && pos[0] == 0) //求职信息删除框 rectangle(580,100+x,600,120+x);
		{
			if (mouse_press(580, 100 + *x, 600, 120 + *x) == 2)
			{
				MouseS = 1;;
				newmouse(&MouseX, &MouseY, &press);
			}
				
			if (mouse_press(580, 100 +*x, 600, 120 + *x) == 1)
			{
				clrmous(MouseX, MouseY);
				pos[0] = 1;
				psave[1] = 0;
				i[0] = pos[0] * i1;
				i[1] = pos[0] * i1 + pos[1] * i2;
				i[2] = i[1] + pos[2] * i3;
				i[3] = pos[0] * i1 + pos[1] * i2 + pos[5] * i3 + pos[3] * i4;
				page_virgin_draw(*x, psave, ifin, pos);
			}
		}
		//教育信息删除框rectangle(580,165+x-i[0],600,185+x-i[0]);rectangle(580,316+x-i[1],600,336+x-i[1]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 185 + *x - i[0] && MouseY < 205 + *x - i[0] && pos[1] == 0)
		{
			if (mouse_press(580, 185 + *x - i[0], 600, 205 + *x - i[0]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580, 185 + *x- i[0], 600, 205 + *x - i[0]) == 1)
			{
				clrmous(MouseX, MouseY);
				pos[1] = 1;
				psave[2] = 0;
				i[1] = pos[0] * i1 + pos[1] * i2;
				i[2] = i[1] + pos[5] * i3;
				i[3] = pos[0] * i1 + pos[1] * i2 + pos[5] * i3 + pos[3] * i4;
				page_virgin_draw(*x, psave, ifin, pos);
			}
		}
		//在校经历删除框rectangle(580,316+x-i[1],600,336+x-i[1]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 316 + *x - i[1] && MouseY < 336 + *x - i[1] && pos[5] == 0)
		{
			if (mouse_press(580, 316 + *x - i[1], 600, 336 + *x - i[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580, 316 + *x - i[1], 600, 336 + *x - i[1]) == 1)
			{
				clrmous(MouseX, MouseY);
				pos[5] = 1;
				psave[6] = 0;
				i[2] = i[1] + pos[5] * i3;
				i[3] = pos[0] * i1 + pos[1] * i2 + pos[5] * i3 + pos[3] * i4;
				page_virgin_draw(*x, psave, ifin, pos);
			}
		}
		//技能信息删除框rectangle(580,442+x-i[2],600,462+x-i[2]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 492 + *x- i[2]+add[0]+add[1] && MouseY < 512 + *x - i[2]+add[0]+add[1] && pos[3] == 0)
		{
			if (mouse_press(580, 492 + *x - i[2]+add[0]+add[1], 600, 512 + *x - i[2]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580, 492 + *x - i[2]+add[0]+add[1], 600, 512 + *x - i[2]+add[0]+add[1]) == 1)
			{
				clrmous(MouseX, MouseY);
				pos[3] = 1;
				psave[4] = 0;
				i[3] = pos[0] * i1 + pos[1] * i2 + pos[5] * i3 + pos[3] * i4;
				page_virgin_draw(*x, psave, ifin, pos);
			}
		}
		//自我评价删除框 rectangle(580,550+x-i[3],600,570+x-i[3]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 580 + *x - i[3]+add[0]+add[1] && MouseY < 600 + *x - i[3]+add[0]+add[1] && pos[4] == 0)
		{
			if (mouse_press(580, 580 + *x - i[3]+add[0]+add[1], 600, 600 + *x - i[3]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580, 580 + *x- i[3]+add[0]+add[1], 600, 600 + *x - i[3]+add[0]+add[1]) == 1)
			{
				clrmous(MouseX, MouseY);
				pos[4] = 1;
				psave[5] = 0;
				page_virgin_draw(*x, psave, ifin, pos);
			}
		}
        //实习信息删除框 rectangle(580,472+x-i[2],600,492+x-i[2]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 492+*x-i[2] && MouseY < 512+*x-i[2] && pos[6] == 0)
		{
			if (mouse_press(580, 492+*x-i[2], 600, 512+*x-i[2]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580, 492+*x-i[2], 600, 512+*x-i[2]) == 1)
			{
				clrmous(MouseX, MouseY);
                pos[6] = 1;
				psave[7] = 0;
				add[0] = 0;
				page_virgin_draw(*x, psave, ifin, pos);
			}
		}
        //工作信息删除框 rectangle(580, 472+x-i[2]+add[0], 600, 492+x-i[2]+add[0]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 472+*x-i[2]+add[0] && MouseY < 492+*x-i[2]+add[0] && pos[2] == 0)
		{
			if (mouse_press(580, 472+*x-i[2]+add[0], 600, 492+*x-i[2]+add[0]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580, 472+*x-i[2]+add[0], 600, 492+*x-i[2]+add[0]) == 1)
			{
				clrmous(MouseX, MouseY);
                pos[2] = 1;
				psave[3] = 0;
				add[1] = 0;
				page_virgin_draw(*x, psave, ifin, pos);
			}
		}
		if (MouseX > 610 && MouseX < 640 && MouseY > 0 && MouseY < 45) // 退出框
		{
			if (mouse_press(610, 0, 640, 45) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(610, 0, 640, 45) == 1)
			{
				//pos[0] = pos[1] = pos[2] = pos[3] = pos[4] = 0;
				memset(pos,0,8*sizeof(int));
				memset(psave, 0, 9 * sizeof(int));
				memset(ifin, 0, 48 * sizeof(int));
				*x = 0;
				*ifadd = 0;
				return 3;
			}
		}
		if (MouseX > 610 && MouseX < 640 && MouseY > 430 && MouseY < 480) // 保存
		{
			if (mouse_press(610, 430, 640, 480) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(610, 430, 640, 480) == 1) // 点击
			{
				clrmous(MouseX, MouseY);
				*count = *count + 1;
				saveout(psave, ifin,template_page,turn); 
			}
		}
		if (MouseX > 610 && MouseX < 640 && MouseY > 45 && MouseY < 80) //上
		{
			if (mouse_press(610, 45, 640, 80) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(610, 45, 640, 80) == 1)
			{
				if (*x < 0)
				{
					*x = *x + 40;
					delay(200);
					page_virgin_draw(*x, psave, ifin, pos);
				}
				else
				{
					clrmous(MouseX, MouseY);
					s = imagesize(200, 50, 440, 150);
					p = malloc(s);
					if (p == NULL)
					{
						perror("Memory wrong");
						delay(3000);
						exit(1);
					}
					getimage(200, 50, 440, 150, p);
					setfillstyle(1, LIGHTGRAY);
					bar(200, 50, 440, 150);
					puthz(210, 80, "已到顶端", 32, 64, BLACK);
					delay(1000);
					putimage(200, 50, p, 0);
					free(p);
				}
			}
		}
		if (MouseX > 610 && MouseX < 640 && MouseY > 395 && MouseY < 430) // 下
		{
			if (mouse_press(610, 395, 640, 430) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(610, 395, 640, 430) == 1)
			{
				*x = *x - 40;
				delay(200);
				page_virgin_draw(*x, psave, ifin, pos);
			}
		}
	}
}
/*********************************************
FUNCTION:page_classic_draw
DESCRIPTION:draw and roll the classic template
INPUT:x
RETURN:void
***********************************************/
void page_virgin_draw(int x, int psave[], int ifin[][6], int pos[])
{
	int i1 = 65, i2 = 151, i3 = 126, i4 = 108;
	int i[5] = { 0 };
    int addlength[2] = {200,126};
	int add[2] = {0,0};
    if (pos[6] == 0)
	{
		add[0] = addlength[0];
	}
	if (pos[2] == 0)
	{
		add[1] = addlength[1];
	}
	i[0] = pos[0] * i1;
	i[1] = pos[0] * i1 + pos[1] * i2;
	i[2] = pos[0] * i1 + pos[1] * i2 + pos[5] * i3;
	i[3] = pos[0] * i1 + pos[1] * i2 + pos[5] * i3 + pos[3] * i4;
	clrmous(MouseX, MouseY);
	//cleardevice();

	setfillstyle(1, WHITE);
	bar(0, 0, 640, 480);

	//个人信息
	puthz(0, 0 + x + 5, "姓名", 24, 32, BLACK);
	puthz(0, 30 + x + 5, "手机", 16, 18, BLACK);
	puthz(200, 30 + x + 5, "邮箱", 16, 18, BLACK);
	puthz(0, 50 + x + 5, "微信", 16, 18, BLACK);
	puthz(200, 50 + x + 5, "出生日期", 16, 18, BLACK);
    rectangle(580,10+x,600,30+x);
	line(585,20+x,595,20+x);
	line(590,15+x,590,25+x);
	//求职信息
	if (pos[0] == 0)
	{
		setlinestyle(0, 0, 3);
		setcolor(BLACK);
		line(0, 70 + x + 25, 610, 70 + x + 25);
		puthz(0, 75 + x + 25, "求职意向", 24, 32, BLACK);
		puthz(0, 105 + x + 25, "求职岗位", 16, 18, BLACK);
		puthz(100, 105 + x + 25, "求职类型", 16, 18, BLACK);
		puthz(200, 105 + x + 25, "期望薪资", 16, 18, BLACK);
		puthz(300, 105 + x + 25, "期望城市", 16, 18, BLACK);
		setlinestyle(0, 0, 1);
		rectangle(580, 100 + x, 600, 120 + x);
		line(585, 105 + x, 595, 115 + x);
		line(595, 105 + x, 585, 115 + x);
	}

	// if (pos[0] != 0)
	// {
	// 	setfillstyle(1,WHITE);
	// 	bar(0,94+x,610,160+x);

	// }

	//教育信息
	if (pos[1] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 125 + x + 35 - i[0], 610, 125 + x + 35 - i[0]);
		puthz(0, 130 + x + 35 - i[0], "教育经历", 24, 32, BLACK);
		puthz(0, 160 + x + 35 - i[0], "学校名称", 16, 18, BLACK);
		puthz(0, 185 + x + 35 - i[0], "专业学历", 16, 18, BLACK);
		setlinestyle(0, 0, 1);
		line(0, 215 + x + 40 - i[0], 5, 220 + x + 35 - i[0]);
		puthz(7, 210 + x + 35 - i[0], "专业成绩", 16, 18, BLACK);
		line(0, 233 + x + 35 - i[0], 5, 238 + x + 30 - i[0]);
		puthz(7, 228 + x + 35 - i[0], "主修课程", 16, 18, BLACK);
		line(0, 251 + x + 35 - i[0], 5, 251 + x + 35 - i[0]);
		puthz(7, 246 + x + 35 - i[0], "荣誉奖项", 16, 18, BLACK);
		setlinestyle(0, 0, 1);
		rectangle(580, 185 + x - i[0], 600, 205 + x - i[0]);
		line(585, 190 + x - i[0], 595, 200 + x - i[0]);
		line(595, 190 + x - i[0], 585, 200 + x - i[0]);
	}

	// if (pos[1] != 0)
	// {
	// 	setfillstyle(1,WHITE);
	// 	bar(0,160+x-i[0],610,311+x-i[0]);
	// }

	//在校经历
	if (pos[5] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 266 + x + 45 - i[1], 610, 266 + x + 45 - i[1]);
		puthz(0, 271 + x + 45 - i[1], "在校经历", 24, 32, BLACK);
		setlinestyle(0, 0, 1);
		setlinestyle(0, 0, 1);
		rectangle(580, 316 + x - i[1], 600, 336 + x - i[1]);
		line(585, 321 + x - i[1], 595, 331 + x - i[1]);
		line(595, 321 + x - i[1], 585, 331 + x - i[1]);
	}

	// if (pos[2] != 0)
	// {
	// 	setfillstyle(1,WHITE);
	// 	bar(0,311+x-i[1],610,437+x-i[1]);
	// }

	//技能信息
	if (pos[3] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 412 + x + 55 - i[2]+add[0]+add[1], 610, 412 + x + 55 - i[2]+add[0]+add[1]);
		puthz(0, 417 + x + 55 - i[2]+add[0]+add[1], "技能证书", 24, 32, BLACK);
		setlinestyle(0, 0, 1);
		rectangle(580, 492 + x - i[2]+add[0]+add[1], 600, 512 + x - i[2]+add[0]+add[1]);
		line(585, 497 + x - i[2]+add[0]+add[1], 595, 507 + x - i[2]+add[0]+add[1]);
		line(595, 497 + x - i[2]+add[0]+add[1], 585, 507 + x - i[2]+add[0]+add[1]);
	}

	// if (pos[3] != 0)
	// {
	// 	setfillstyle(1,WHITE);
	// 	bar(0,437+x-i[2],610,545+x-i[2]);
	// }

	//控制栏
	setcolor(BLACK);
	setlinestyle(0, 0, 1);
	line(610, 0, 610, 480);
	setfillstyle(1, LIGHTGRAY);
	bar(610, 0, 640, 45);
	puthz(615, 0, "返", 16, 10, BLACK);
	puthz(615, 25, "回", 16, 10, BLACK);
	bar(610, 430, 640, 480);
	puthz(615, 432, "保", 16, 10, BLACK);
	puthz(615, 457, "存", 16, 10, BLACK);

	rectangle(610, 45, 640, 80);
	line(625, 45, 610, 80);
	line(625, 45, 640, 80);
	rectangle(610, 395, 640, 430);
	line(625, 430, 610, 395);
	line(625, 430, 640, 395);
	setfillstyle(1, BLACK);
	floodfill(626, 50, BLACK);
	floodfill(626, 409, BLACK);

	if (pos[4] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 510 + x + 65 - i[3]+add[0]+add[1], 610, 510 + x + 65 - i[3]+add[0]+add[1]);
		puthz(0, 515 + x + 65 - i[3]+add[0]+add[1], "自我评价", 24, 32, BLACK);
		setlinestyle(0, 0, 1);
		rectangle(580, 580 + x - i[3]+add[0]+add[1], 600, 600 + x - i[3]+add[0]+add[1]);
		line(585, 585 + x - i[3]+add[0]+add[1], 595, 595 + x - i[3]+add[0]+add[1]);
		line(595, 585 + x - i[3]+add[0]+add[1], 585, 595 + x - i[3]+add[0]+add[1]);
	}
    if (pos[2] == 0)
    {
        setlinestyle(0, 0, 3);
		line(0, 467+x-i[2]+add[0], 610, 467+x-i[2]+add[0]);
		puthz(0, 472+x-i[2]+add[0], "工作经历", 24, 32, BLACK);
		puthz(0, 502+x-i[2]+add[0], "公司名称", 16, 18, BLACK);
		puthz(0, 527+x-i[2]+add[0], "职位名称", 16, 18, BLACK);
		puthz(400, 527+x-i[2]+add[0], "开始时间", 16, 18, BLACK);
		puthz(500, 527+x-i[2]+add[0], "结束时间", 16, 18, BLACK);
		setlinestyle(0, 0, 1);
		line(480, 536+x-i[2]+add[0], 490, 536+x-i[2]+add[0]);
		setlinestyle(0, 0, 1);
		rectangle(580, 472+x-i[2]+add[0], 600, 492+x-i[2]+add[0]);
		line(585, 477+x-i[2]+add[0], 595, 487+x-i[2]+add[0]);
		line(595, 477+x-i[2]+add[0], 585, 487+x-i[2]+add[0]);
    }
    if (pos[6] == 0)
    {
        setlinestyle(0, 0, 3);
		line(0, 467+x-i[2], 610, 467+x-i[2]);
		puthz(0,472+x-i[2],"实习经历",24,32,BLACK);
		setlinestyle(0,0,1);
		rectangle(580,492+x-i[2],600,512+x-i[2]);
		line(585,497+x-i[2],595,507+x-i[2]);
		line(595,497+x-i[2],585,507+x-i[2]);
    }
    //printf("%d%d%d%d%d%d%d",psave[0],psave[1],psave[2],psave[3],psave[4],psave[5],psave[6]);
	

	if (psave[0] == 1)
	{
		put_nameinfo(x, ifin);
	}
	if (psave[1] == 1 && pos[0] == 0)
	{
		put_intention_info(125 + x, ifin);
	}
	if (psave[2] == 1 && pos[1] == 0)
	{
		put_education_info(195 + x - i[0], ifin);
	}
	if (psave[6] == 1 && pos[5] == 0)
	{
		put_undergo_info(346 + x - i[1], ifin);
	}
	if (psave[4] == 1 && pos[3] == 0)
	{
		put_skill_info(495 + x - i[2], ifin);
	}
	if (psave[5] == 1 && pos[4] == 0)
	{
		put_comment_info(605 + x - i[3], ifin);
	}
    if (psave[3] == 1&&pos[2] == 0)
    {
        put_experience_info(467+35+x-i[2]+add[0],ifin);
    }
    if (psave[7] == 1&&pos[6] == 0)
    {
        put_intern_info(467+x-i[2]+35,ifin);
    }
    


}
/*********************************************
FUNCTION:classic_border
DESCRIPTION:draw the border
INPUT:x1,y1,x2,y2,x
RETURN:void
***********************************************/
void virgin_border(int x1, int y1, int x2, int y2, int x)
{
	setlinestyle(0, 0, 1);
	if (x == 1)
	{
		setcolor(BLUE);
		rectangle(x1, y1 + 2, x2, y2 - 2);
	}
	else
	{
		setcolor(WHITE);
		rectangle(x1, y1 + 2, x2, y2 - 2);
	}
}
