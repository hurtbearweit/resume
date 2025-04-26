#include"CLASSIC.H"
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
/*********************************************
FUNCTION:page_classic
DESCRIPTION??use the classic template
INPUT:pinfo_page
RETURN:3,
***********************************************/
int page_classic(int *x,int *pinfo_page,int psave[],int ifin[][6],int pos[],int *template_page,int *ifadd,int *count,int turn[])
{

	unsigned s;
	void *p;
	int i[5] = {0};
	int partpos[8] = {0};//记录每个板块的开头
	int length[8] = {90,65,151,126,108,200,150,200};//记录每个模块的长度
	int addlength[2] = {150,200};
	int add[2] = {0,0};
	
	int i1 = 65,i2 = 151,i3 = 126,i4 = 108;
	if (*ifadd != 1)
	{
		pos[5] = 1;
		pos[6] = 1;
	}     //如果不添加，那么就令他们都是1，pos = 1 代表不显示
	if (pos[5] == 0)
	{
		add[0] = addlength[0];
	}
	if (pos[6] == 0)
	{
		add[1] = addlength[1];
	}
	
	
	i[0] = pos[0]*i1;
	i[1] = pos[0]*i1+pos[1]*i2;
	i[2] = i[1] + pos[2]*i[3];
	i[3] = pos[0]*i1+pos[1]*i2+pos[2]*i3+pos[3]*i4;
	
	
	*template_page = 1;
    //memset(&b,'\0',sizeof(BASIC));
	
	page_classic_draw(*x,psave,ifin,pos);
	
	//line(400,0,400,480);
	//rectangle(400,326,580,350);
	while (1)
	{
		if (MouseS != 0
		&& mouse_press(610, 0, 640, 45) == 0
		&& mouse_press(610, 430, 640, 480) == 0
		&& mouse_press(610, 45, 640, 80) == 0
		&& mouse_press(610, 395, 640, 430) == 0
		&&mouse_press(0,0,500,90+*x) == 0
		&&mouse_press(0,90+*x,500,160+*x) == 0
		&&mouse_press(0,155+*x,500,311+*x) == 0
		&&mouse_press(0,311+*x,500,437+*x) == 0
		&&mouse_press(0,437+*x,500,545+*x) == 0
		&&mouse_press(0,545+*x,500,745+*x) == 0)
		{
			MouseS = 0;
		}
		newmouse(&MouseX, &MouseY, &press);
		delay(40);
		//点击了添加窗口，就是重新添加模块
		if (MouseX>580&&MouseX<600&&MouseY>10+*x&&MouseY<30+*x)
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
		
		if (MouseX>0&&MouseX<500&&MouseY>0&&MouseY<90+*x)//姓名 line(0,70+x+20,610,70+x+25);
		{
			if (mouse_press(0,0,500,90+*x) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,0,500,90+*x,1);
			}
			 if (mouse_press(0,0,500,90+*x) == 1)
			{
				*pinfo_page = 1;
				delay(100);
				return 11;
			}
		}
        else classic_border(0,0,500,90+*x,0);
        if (MouseX>0&&MouseX<500&&MouseY>90+*x&&MouseY<155+*x&&pos[0] == 0)//求职意向 line(0,125+x+35-i[0],610,125+x+35-i[0]);
		{
			if (mouse_press(0,90+*x,500,160+*x) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,97+*x,500,157+*x,1);
			}
			 if (mouse_press(0,97+*x,500,157+*x) == 1)
			{
				*pinfo_page = 2;
				delay(100);
				return 11;
			}
		}
		else classic_border(0,97+*x,500,157+*x,0);
		if (MouseX>0&&MouseX<500&&MouseY>155+*x-i[0]&&MouseY<311+*x-i[0]&&pos[1] == 0)//教育经历 line(0,266+x+45-i[1],610,266+x+45-i[1]);
		{
			if (mouse_press(0,155+*x-i[0],500,311+*x-i[0]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,163+*x-i[0],500,306+*x-i[0],1);
			}
			 if (mouse_press(0,155+*x-i[0],500,311+*x-i[0]) == 1)
			{
				*pinfo_page = 3;
				delay(100);
				return 11;
			}
		}
		else classic_border(0,163+*x-i[0],500,306+*x-i[0],0);
		if (MouseX>0&&MouseX<500&&MouseY>311+*x-i[1]+add[0]+add[1]&&MouseY<437+*x-i[1]+add[0]+add[1]&&pos[2] == 0)//工作信息 line(0,382+x+55,610,382+x+55);
		{
			if (mouse_press(0,311+*x-i[1]+add[0]+add[1],500,437+*x-i[1]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,313+*x-i[1]+add[0]+add[1],500,432+*x-i[1]+add[0]+add[1],1);
			}
			 if (mouse_press(0,311+*x-i[1]+add[0]+add[1],500,437+*x-i[1]+add[0]+add[1]) == 1)
			{
				*pinfo_page = 4;
				delay(100);
				return 11;
			}
		}
		else classic_border(0,313+*x-i[1]+add[0]+add[1],500,432+*x-i[1]+add[0]+add[1],0);
		if (MouseX>0&&MouseX<500&&MouseY>437+*x-i[2]+add[0]+add[1]&&MouseY<545+*x-i[2]+add[0]+add[1]&&pos[3] == 0)//技能信息 line(0, 480 + x + 65 , 610, 480 + x+ 65 );
		{
			if (mouse_press(0,437+*x-i[2]+add[0]+add[1],500,545+*x-i[2]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,439+*x-i[2]+add[0]+add[1],500,540+*x-i[2]+add[0]+add[1],1);
			}
			 if (mouse_press(0,437+*x-i[2]+add[0]+add[1],500,545+*x-i[2]+add[0]+add[1]) == 1)
			{
				*pinfo_page = 5;
				delay(100);
				return 11;
			}
		}
		else classic_border(0,439+*x-i[2]+add[0]+add[1],500,540+*x-i[2]+add[0]+add[1],0);
		if (MouseX>0&&MouseX<500&&MouseY>545+*x-i[3]+add[0]+add[1]&&MouseY<745+*x-i[3]+add[0]+add[1]&&pos[4] == 0)//自我评价 
		{
			
			if (mouse_press(0,545+*x-i[3]+add[0]+add[1],500,745+*x-i[3]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,547+*x-i[3]+add[0]+add[1],500,740+*x-i[3]+add[0]+add[1],1);
			}
			 if (mouse_press(0,545+*x-i[3]+add[0]+add[1],500,745+*x-i[3]+add[0]+add[1]) == 1)
			{
				*pinfo_page = 6;
				delay(100);
				return 11;
			}
		}
		else classic_border(0,547+*x-i[3]+add[0]+add[1],500,740+*x-i[3]+add[0]+add[1],0);
		if (MouseX>0&&MouseX<500&&MouseY>311-i[1]+*x&&MouseY<461+*x-i[1]&&pos[5] == 0)//在校经历311-i[1]+x
		{
			
			if (mouse_press(0,311-i[1]+*x,500,461+*x-i[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,313-i[1]+*x,500,456+*x-i[1],1);
			}
			 if (mouse_press(0,311-i[1]+*x,500,461+*x-i[1]) == 1)
			{
				*pinfo_page = 7;
				delay(100);
				return 11;
			}
		}
		else classic_border(0,313-i[1]+*x,500,456+*x-i[1],0);
		
		if (MouseX>0&&MouseX<500&&MouseY>311-i[1]+add[0]+*x&&MouseY<511-i[1]+add[0]+*x&&pos[6] == 0)//实习经历545+x-i[3]+add[0]
		{
			
			if (mouse_press(0,311-i[1]+add[0]+*x,500,511-i[1]+add[0]+*x) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,313-i[1]+add[0]+*x,500,506-i[1]+add[0]+*x,1);
			}
			 if (mouse_press(0,311-i[1]+add[0]+*x,500,511-i[1]+add[0]+*x) == 1)
			{
				*pinfo_page = 8;
				delay(100);
				return 11;
			}
		}
		else classic_border(0,313-i[1]+add[0]+*x,500,506-i[1]+add[0]+*x,0);
		if (MouseX > 580 && MouseX < 600 && MouseY > 100+*x&& MouseY < 120+*x&&pos[0] == 0) //求职信息删除框 rectangle(580,100+x,600,120+x);
		{
			if (mouse_press(580,100+*x,600,120+*x) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580,100+*x,600,120+*x) == 1)
			{
					clrmous(MouseX,MouseY);
					pos[0] = 1;
					psave[1] = 0;
					i[0] = pos[0]*i1;
					i[1] = pos[0]*i1 + pos[1]*i2;
					i[2] = i[1] + pos[2]*i3;
					i[3] = pos[0]*i1+pos[1]*i2+pos[2]*i3+pos[3]*i4;
				    page_classic_draw(*x,psave,ifin,pos);
			}
		}
		
		//教育信息删除框rectangle(580,165+x-i[0],600,185+x-i[0]);rectangle(580,316+x-i[1],600,336+x-i[1]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 185+*x-i[0]&& MouseY < 205+*x-i[0]&&pos[1] == 0) 
		{
			if (mouse_press(580,185+*x-i[0],600,205+*x-i[0]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580,185+*x-i[0],600,205+*x-i[0]) == 1)
			{
					clrmous(MouseX,MouseY);
					pos[1] = 1;
					psave[2] = 0;
					i[1] = pos[0]*i1 + pos[1]*i2;
					i[2] = i[1] + pos[2]*i3;
					i[3] = pos[0]*i1+pos[1]*i2+pos[2]*i3+pos[3]*i4;
				    page_classic_draw(*x,psave,ifin,pos);
			}
		}

		//工作信息删除框rectangle(580,316+x-i[1],600,336+x-i[1]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 316+*x-i[1]+add[0]+add[1]&& MouseY < 336+*x-i[1]+add[0]+add[1]&&pos[2] == 0) 
		{
			if (mouse_press(580,316+*x-i[1]+add[0]+add[1],600,336+*x-i[1]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580,316+*x-i[1]+add[0]+add[1],600,336+*x-i[1]+add[0]+add[1]) == 1)
			{
					clrmous(MouseX,MouseY);
					pos[2] = 1;
					psave[3] = 0;
					i[2] = i[1] + pos[2]*i3;
					i[3] = pos[0]*i1+pos[1]*i2+pos[2]*i3+pos[3]*i4;
				    page_classic_draw(*x,psave,ifin,pos);
			}
		}
		
		//技能信息删除框rectangle(580,442+x-i[2],600,462+x-i[2]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 462+*x-i[2]+add[0]+add[1]&& MouseY < 482+*x-i[2]+add[0]+add[1]&&pos[3] == 0) 
		{
			if (mouse_press(580,462+*x-i[2]+add[0]+add[1],600,482+*x-i[2]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580,462+*x-i[2]+add[0]+add[1],600,482+*x-i[2]+add[0]+add[1]) == 1)
			{
					clrmous(MouseX,MouseY);
					pos[3] = 1;
					psave[4] = 0;
					i[3] = pos[0]*i1+pos[1]*i2+pos[2]*i3+pos[3]*i4;
				    page_classic_draw(*x,psave,ifin,pos);
			}
		}
		
		//自我评价删除框 rectangle(580,550+x-i[3]+add[0]+add[1],600,570+x-i[3]+add[0]+add[1]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 550+*x-i[3]+add[0]+add[1]&& MouseY < 570+*x-i[3]+add[0]+add[1]&&pos[4] == 0) 
		{
			if (mouse_press(580,550+*x-i[3]+add[0]+add[1],600,570+*x-i[3]+add[0]+add[1]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580,550+*x-i[3]+add[0]+add[1],600,570+*x-i[3]+add[0]+add[1]) == 1)
			{
					clrmous(MouseX,MouseY);
					pos[4] = 1;
					psave[5] = 0;
				    page_classic_draw(*x,psave,ifin,pos);
			}
		}
		//在校经历删除框 rectangle(580,331-i[1]+x,600,351-i[1]+x);
		if (MouseX > 580 && MouseX < 600 && MouseY > 331-i[1]+*x&& MouseY < 351-i[1]+*x&&pos[5] == 0) 
		{
			if (mouse_press(580,331-i[1]+*x,600,351-i[1]+*x) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580,331-i[1]+*x,600,351-i[1]+*x) == 1)
			{
					clrmous(MouseX,MouseY);
					pos[5] = 1;
					psave[6] = 0;
					add[0] = 0;
				    page_classic_draw(*x,psave,ifin,pos);
			}
		}
		//实习经历删除框 line(0, 545+x-i[3]+add[0], 610, 545+x-i[3]+add[0]);
		if (MouseX > 580 && MouseX < 600 && MouseY > 316+*x-i[1]+add[0]&& MouseY < 336+*x-i[1]+add[0]&&pos[6] == 0) 
		{
			if (mouse_press(580,316+*x-i[1]+add[0],600,336+*x-i[1]+add[0]) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(580,316+*x-i[1]+add[0],600,336+*x-i[1]+add[0]) == 1)
			{
					clrmous(MouseX,MouseY);
					pos[6] = 1;
					psave[7] = 0;
					add[1] = 0;
				    page_classic_draw(*x,psave,ifin,pos);
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
				memset(pos,0,8*sizeof(int));
				memset(psave,0,9*sizeof(int));
				memset(ifin,0,48*sizeof(int));
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
                *count = *count + 1;
				saveout(psave,ifin,template_page,turn);
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
				if (*x<0)
				{
					*x = *x + 40;
					delay(200);
					page_classic_draw(*x, psave, ifin, pos);
				}
				else
				{
					clrmous(MouseX,MouseY);
					s = imagesize(200, 50, 440, 150);
					p = malloc(s);
					if (p == NULL)
					{
						perror("Memory wrong");
						delay(3000);
						exit(1);
					}
					getimage(200,50,440,150,p);
					setfillstyle(1,LIGHTGRAY);
					bar(200,50,440,150);
					puthz(210,80,"已到顶端",32,64,BLACK);
					delay(1000);
					putimage(200,50,p,0);
					free(p);
					//操作：先存下来背景数据，接下来弹出提醒，最后又恢复背景数据
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
				page_classic_draw(*x,psave,ifin,pos);
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
void page_classic_draw(int x,int psave[],int ifin[][6],int pos[])
{
	int i1 = 65,i2 = 151,i3 = 126,i4 = 108;
	int i[5] = {0};
	int addlength[2] = {150,200};
	int add[2] = {0};
	if (pos[5] == 0)
	{
		add[0] = addlength[0];
	}
	if (pos[6] == 0)
	{
		add[1] = addlength[1];
	}
	
	i[0] = pos[0]*i1;//求职意向模块的长度
	i[1] = pos[0]*i1+pos[1]*i2;//求职意向和教育意义的长度
	i[2] = pos[0]*i1+pos[1]*i2+pos[2]*i3;
	i[3] = pos[0]*i1+pos[1]*i2+pos[2]*i3+pos[3]*i4;


	clrmous(MouseX, MouseY);
    setfillstyle(1, WHITE);
    bar(0, 0, 640, 480);

	//滚轮的原理就是，设定了一个指定的滚轮偏移量，然后根据鼠标的位置，初始时是0，之后点击向下的箭头，就会使x变成-30，
	// 则最上面的30像素就被掩盖了，下面的第31像素变成了第1像素，这样就实现了滚轮效果，因为本身所有的线和文字都是
	///基于x画出来的，收到x的影响，所以滚轮的效果就出来了


    //个人信息
	setlinestyle(0, 0, 3);
	setcolor(BLACK);
	line(0, 0 + x + 65, 610, 0 + x + 65);   //求职意见上面的一条直线
    puthz(0,0+x+5 +65,"姓名",24,32,BLACK);
    puthz(0,30+x+5 + 65,"手机",16,18,BLACK);
    puthz(200,30+x+5 + 65,"邮箱",16,18,BLACK);
    puthz(0,50+x+5 + 65,"微信",16,18,BLACK);
    puthz(200,50+x+5 + 65,"出生日期",16,18,BLACK);
	rectangle(580,10+x + 65,600,30+x + 65);
	line(585,20+x + 65,595,20+x + 65);
	line(590,15+x + 65,590,25+x + 65);
    //求职信息    个人信息一栏不管哪个模板都不会删
    if (pos[0] == 0)
	{
		setlinestyle(0, 0, 3);
		setcolor(BLACK);
		line(0, 70 + x + 25 - 90, 610, 70 + x + 25 - 90);   //求职意见上面的一条直线
		puthz(0, 75 + x + 25 -90 , "求职意向", 24, 32, BLACK);
		puthz(0, 105 + x + 25 -90 , "求职岗位", 16, 18, BLACK);
		puthz(100, 105 + x + 25 -90 ,"求职类型", 16, 18, BLACK);
		puthz(200, 105 + x + 25 - 90, "期望薪资", 16, 18, BLACK);
		puthz(300, 105 + x + 25 -90, "期望城市", 16, 18, BLACK);
		setlinestyle(0, 0, 1);  
		rectangle(580, 100 + x - 90, 600, 120 + x - 90);
		line(585, 105 + x -90, 595, 115 + x -90 );
		line(595, 105 + x -90, 585, 115 + x - 90);
		//画线规则就是这一个模块的上面的那一条线，而不画下面的那一条线
	}

    
    //教育信息
	///这里使用了一个i[0],就是因为i[0]实际上就是求职意向这一个模块的长度，如果删掉了这一个模块后教育经历就变成了第二个板块
	//后面的版块都需要向上移动i[0]的长度，所以这里就需要用到i[0]
    if (pos[1] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 125 + x + 35 - i[0], 610, 125 + x + 35 - i[0]);
		puthz(0, 130 + x + 35 - i[0], "教育经历", 24, 32, BLACK);
		puthz(0, 160 + x + 35 - i[0], "学校名称", 16, 18, BLACK);
		puthz(0, 185 + x + 35 - i[0], "专业学历", 16, 18, BLACK);
	    setlinestyle(0,0,1);
		line(0, 215 + x + 40-i[0], 5, 220 + x + 35 - i[0]);
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

    //工作信息
	//在校经历和实习经历都是插在工作经历前面的，所以还会加上add[0]和add[1]
    if (pos[2] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 266 + x + 45 -i[1]+add[0]+add[1], 610, 266 + x + 45 -i[1]+add[0]+add[1]);
		puthz(0, 271 + x + 45 -i[1]+add[0]+add[1], "工作经历", 24, 32, BLACK);
		puthz(0, 301 + x + 45 -i[1]+add[0]+add[1], "公司名称", 16, 18, BLACK);
		puthz(0, 326 + x + 45 -i[1]+add[0]+add[1], "职位名称", 16, 18, BLACK);
		puthz(400, 326 + x + 45 -i[1]+add[0]+add[1], "开始时间", 16, 18, BLACK);
		setlinestyle(0, 0, 1);
		line(480, 335 + x + 45 - i[1] + add[0] + add[1], 490, 335 + x + 45 - i[1] + add[0] + add[1]);
		puthz(500, 326 + x + 45 -i[1]+add[0]+add[1], "结束时间", 16, 18, BLACK);
		setlinestyle(0, 0, 1);
		rectangle(580, 316 + x -i[1]+add[0]+add[1], 600, 336 + x -i[1]+add[0]+add[1]);
		line(585, 321 + x -i[1]+add[0]+add[1], 595, 331 + x -i[1]+add[0]+add[1]);
		line(595, 321 + x -i[1]+add[0]+add[1], 585, 331 + x -i[1]+add[0]+add[1]);
		
	}

    //技能信息
    if (pos[3] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 382 + x + 55 -i[2]+add[0]+add[1], 610, 382 + x + 55 -i[2]+add[0]+add[1]);
		puthz(0, 387 + x + 55 -i[2]+add[0]+add[1], "技能证书", 24, 32, BLACK);
		setlinestyle(0, 0, 1);
		rectangle(580, 462 + x -i[2]+add[0]+add[1], 600, 482 + x -i[2]+add[0]+add[1]);
		line(585, 467 + x -i[2]+add[0]+add[1], 595, 477 + x -i[2]+add[0]+add[1]);
		line(595, 467 + x -i[2]+add[0]+add[1], 585, 477 + x -i[2]+add[0]+add[1]);
		
	}
	
	//自我评价
	if (pos[4] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 480 + x + 65 - i[3] + add[0] + add[1], 610, 480 + x + 65 - i[3] + add[0] + add[1]);
		puthz(0, 485 + x + 65 - i[3] + add[0] + add[1], "自我评价", 24, 32, BLACK);
		setlinestyle(0, 0, 1);
		rectangle(580, 550 + x - i[3] + add[0] + add[1], 600, 570 + x - i[3] + add[0] + add[1]);
		line(585, 555 + x - i[3] + add[0] + add[1], 595, 565 + x - i[3] + add[0] + add[1]);
		line(595, 555 + x - i[3] + add[0] + add[1], 585, 565 + x - i[3] + add[0] + add[1]);

	}

    //控制栏
	setcolor(BLACK);
    setlinestyle(0,0,1);
    line(610,0,610,480);
    setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,45);
    puthz(615,0,"返",16,10,BLACK);
    puthz(615,25,"回",16,10,BLACK);
    bar(610,430,640,480);
    puthz(615,432,"保",16,10,BLACK);
    puthz(615,457,"存",16,10,BLACK);

    rectangle(610,45,640,80);  
    line(625,45,610,80);
    line(625,45,640,80);
    rectangle(610,395,640,430);
    line(625,430,610,395);
    line(625,430,640,395);
	setfillstyle(1,BLACK);
    floodfill(626,50,BLACK);
	floodfill(626,409,BLACK);

	if (pos[5] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 311-i[1]+x, 610, 311-i[1]+x);//这一行和工作经历是一样的
		puthz(0,316-i[1]+x,"在校经历",24,32,BLACK);
		setlinestyle(0,0,1);
		rectangle(580,331-i[1]+x,600,351-i[1]+x);
		line(585,336-i[1]+x,595,346-i[1]+x);
		line(585,346-i[1]+x,595,336-i[1]+x);
	}
	if (pos[6] == 0)
	{
		setlinestyle(0, 0, 3);
		line(0, 311+x-i[1]+add[0], 610, 311+x-i[1]+add[0]);
		puthz(0,316+x-i[1]+add[0],"实习经历",24,32,BLACK);
		setlinestyle(0,0,1);
		rectangle(580,316+x-i[1]+add[0],600,336+x-i[1]+add[0]);
		line(585,321+x-i[1]+add[0],595,331+x-i[1]+add[0]);
		line(595,321+x-i[1]+add[0],585,331+x-i[1]+add[0]);
	}
		

    if (psave[0] == 1)
    {
		put_nameinfo(x,ifin);
	}
	if (psave[1] == 1&&pos[0] == 0)  //求职意向模块选中了并且已经保存，则需要将保存的东西输出出来
	{
		put_intention_info(125+x,ifin);
	}
	if (psave[2] == 1&&pos[1] == 0)
	{
		put_education_info(195+x-i[0],ifin);
	}
	if (psave[3] == 1&&pos[2] == 0)
	{
		put_experience_info(346+x-i[1],ifin);
	}
	if (psave[4] == 1&&pos[3] == 0)
	{
		put_skill_info(465+x-i[2],ifin);
	}
	if (psave[5] == 1&&pos[4]==0) 
	{
		put_comment_info(575+x-i[3]+add[0]+add[1],ifin);
	}
	if (psave[6] == 1&&pos[5] == 0)
	{
		put_undergo_info(311-i[1]+x+35,ifin);
	}
	if (psave[7] == 1&&pos[6] ==0)
	{
		put_intern_info(311+x-i[1]+add[0]+35,ifin);
	}
	


}
/*********************************************
FUNCTION:classic_border
DESCRIPTION:draw the border
INPUT:x1,y1,x2,y2,x
RETURN:void
***********************************************/
void classic_border(int x1,int y1,int x2,int y2,int x)
{
    setlinestyle(0,0,1);
    if (x == 1)
    {
        setcolor(BLUE);
        rectangle(x1,y1+2,x2,y2-2);
    }
    else 
    {
        setcolor(WHITE);
        rectangle(x1,y1+2,x2,y2-2);
    }
}
