#include"LOG.H"
#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include"hz.h"
#include"mouse.h"
#include<bios.h>
#include"COMMON.H"
#include"REGISTER.H"
#include<stdlib.h>
extern MouseX,MouseY,MouseS;
/*********************************************
FUNCTION:page_log
DESCRIPTION：log
INPUT:p
RETURN:-1,1,2
***********************************************/
int page_log(char *usernum)
{    
    char name[15] = {'\0'};//账号
    char code[15] = {'\0'};//密码
    //画基本框架
    *usernum = 0;//重置iflog
	clrmous(MouseX,MouseY);
    cleardevice();
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	bar(0,0,648,480);
	setfillstyle(SOLID_FILL,WHITE);
    bar(100,160,548,210);
    bar(100,280,548,330);
    puthz(175,60,"欢迎使用",48,64,LIGHTRED);
	puthz(30,160,"用户",32,30,BLACK);
    puthz(30,280,"密码",32,30,BLACK);
    setfillstyle(SOLID_FILL,YELLOW);
	bar(100,380,230,440);   //注册框
	bar(250,380,400,440);   //用户登录框
	bar(420,380,548,440);   //游客登录框
	bar(550,0,648,50);      //退出框
	puthz(100,390,"用户注册",32,30,BLUE);
	puthz(260,390,"用户登录",32,30,BLUE);
	puthz(420,390,"游客登录",32,30,BLUE);
	puthz(560,10,"退出",32,30,RED);
    setcolor(LIGHTBLUE);
	setlinestyle(0,0,3);
	rectangle(100-2,380-2,230+2,440+2);
	rectangle(250-2,380-2,400+2,440+2);
	rectangle(420-2,380-2,548+2,440+2);
	rectangle(100-2,160-2,548+2,210+2);
	rectangle(100-2,280-2,548+2,330+2);
    rectangle(550-2,0-2,648+2,50+2);
	setlinestyle(0,0,1);
    while(1)
    {
        if (MouseS != 0&&mouse_press(100,160,548,210) == 0&&mouse_press(100,280,548,330) == 0)
        {
            MouseS = 0;
        }
		newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>100&&MouseX<548&&MouseY>160&&MouseY<210)//用户框
        {
            if (mouse_press(100,160,548,210) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                log_change(100,160,548,210);
            }
             if (mouse_press(100,160,548,210) == 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(SOLID_FILL,WHITE);
			    bar(100,160,548,210);
				log_inputaccount(name,100,170,12,WHITE,1);
            }
            if (mouse_press(100,160,548,210) == 0)
            {
                log_restore(100,160,548,210);
            }
            
        }
         if (MouseX>100&&MouseX<548&&MouseY>280&&MouseY<330)//密码框
        {
            if (mouse_press(100,280,548,330) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                log_change(100,280,548,330);
            }
             if (mouse_press(100,280,548,330) == 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(SOLID_FILL,WHITE);
			    bar(100,280,548,330);
                log_inputcode(code,100,290,12,WHITE);
            }
            if (mouse_press(100,280,548,330) == 0)
            {
               log_restore(100,280,548,330);
            }
        }
        if (MouseX>100&&MouseX<230&&MouseY>380&&MouseY<440)//注册框
        {
             if (mouse_press(100,380,230,440) == 2)
            {                
                log_change(100,380,230,440);
            }
             if (mouse_press(100,380,230,440) == 1)
            {
				clrmous(MouseX,MouseY);
                return 1;
            }
        }
        else log_restore(100,380,230,440);
         if (MouseX>250&&MouseX<400&&MouseY>380&&MouseY<440)//用户登录框
        {
             if (mouse_press(250,380,400,440) == 2)
            {                
                log_change(250,380,400,440);
            }
             if (mouse_press(250,380,400,440) == 1)
            {
				if (log_complete(name,code,usernum) == 0)
                {
                    return 2;
                }              
            }
        }
        else log_restore(250,380,400,440);
        if (MouseX>420&&MouseX<548&&MouseY>380&&MouseY<440)//游客登录框
        {
             if (mouse_press(420,380,548,440) == 2)
            {                
                log_change(420,380,548,440);
            }
             if (mouse_press(420,380,548,440) == 1)
            {
                return 2;
            }
        }
        else log_restore(420,380,548,440);
        if (MouseX>550&&MouseX<648&&MouseY>0&&MouseY<50)//退出框
        {
            if (mouse_press(550,0,648,50) == 2)
            {
                log_change(550,0,648,50);
            }
            if(mouse_press(550,0,648,50) == 1)
            {
                return -1;
            }          
        }
        else log_restore(550,0,648,50);
    }
}
/*********************************************
FUNCTION:log_change
DESCRIPTION：change the border color
INPUT:x1,y1,x2,y2
RETURN:void
***********************************************/
void log_change(int x1,int y1,int x2,int y2)
{
     setcolor(RED);
     setlinestyle(0,0,3);
	 rectangle(x1-2,y1-2,x2+2,y2+2);
	 setlinestyle(0,0,1);
}
/*********************************************
FUNCTION:log_restore
DESCRIPTION：restore the border color
INPUT:x1,y1,x2,y2
RETURN:void
***********************************************/
void log_restore(int x1,int y1,int x2,int y2)
{
    setcolor(LIGHTBLUE);
    setlinestyle(0,0,3);
    rectangle(x1-2,y1-2,x2+2,y2+2);
    setlinestyle(0,0,1);
}
/*********************************************
FUNCTION:log_inputaccount
DESCRIPTION：input account
INPUT:name,x,y,limit,color
RETURN:void
***********************************************/
void log_inputaccount(char *name,int x,int y,int limit,int color,int size)
{
    int time = 0;//控制光标闪烁
    int i = 0;
    char t = 0;//接受键入值
    int k = 0;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(0);
	if (size == 1)
    {
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    }
    else if (size == 9)
    {
        settextstyle( 2,0,3);
    }
    else settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x + 10, y + 6, x + 10, y + 20);//初始化光标
    while (bioskey(1))
    {
        k = bioskey(0);
    }
    
    while (1)
    {
        t = 0;
        while (bioskey(1))
        {
            t = bioskey(0);
        }    
        if (t == 0)
        {
            if(mouse_press(100,160,548,210) == 2)
            {
				setfillstyle(SOLID_FILL, color);
				bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
				break;
            }
            time++;
            if(time < 10000)
            {
                line(x+10+i*18,y+6,x+10+i*18,y+20);
            }
            else if(time < 15000)
			{
				bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
			}
            else time = 0;
            continue;
        }
        if (i < limit)
        {
            if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 0
                && t != 033)
            {
                if (t != '\b')
				{
					*(name + i) = t;
					*(name + i + 1) = '\0';//防越界
					bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24); //遮盖光标
					outtextxy(x + 8 + i * 18, y-1, name + i);//输出t字符(16)
					i++;
			
					line(x + 10 + i * 18, y + 6, x + 10 + i * 18, y + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
					bar(x - 10 + i * 18, y + 3, x + 7 + i * 18, y + 24);//遮盖文字
					i--;//减少一个字数
					
			
					line(x + 10 + i * 18, y + 6, x + 10 + i * 18, y + 20);//绘制光标
					*(name + i) = '\0';
					*(name + i + 1) = '\0';
				}
            }
            else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
				break;
			}
        }
        else 
        {
            if (t != '\n'
				&& t != '\r'
				&& t != ' '
                && t != 033)
			{
				if (t == '\b' && i > 0)//退格键
				{
					bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
					bar(x - 10 + i * 18, y + 3, x + 7 + i * 18, y + 24);//遮盖文字
					i--;//减少一个字数
					
					line(x + 10 + i * 18, y + 6, x + 10 + i * 18, y + 20);//绘制光标
					*(name + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标  
				break;
			}
        }
        
    }
    
}
/*********************************************
FUNCTION:log_inputcode
DESCRIPTION：input code
INPUT:
RETURN:void
***********************************************/
void log_inputcode(char *code,int x,int y,int limit ,int color)
{
    int time = 0;//控制光标闪烁
    int i = 0;
    char t = 0;//接受键入值
    int k = 0;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(0);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x + 10, y + 6, x + 10, y + 20);//初始化光标
    while (bioskey(1))
    {
        k = bioskey(0);
    }
    while (1)
    {
        t = 0;
        while (bioskey(1))
        {
            t = bioskey(0);
        }
        if (t == 0)
        {
            if(mouse_press(100,280,548,330) == 2)
            {
				setfillstyle(SOLID_FILL, color);
				bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
				break;
            }
            time++;
            if(time < 10000)
            {
                line(x+10+i*18,y+6,x+10+i*18,y+20);
            }
            else if(time < 15000)
			{
				bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
			}
            else time = 0;
            continue;
        }
        if (i < limit)
        {
            if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 0
                && t != 033)
            {
                if (t != '\b')
				{
					*(code + i) = t;
					*(code + i + 1) = '\0';//防越界
					bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24); //遮盖光标
					outtextxy(x + 8 + i * 18, y-1, "*");//输出*
					i++;
			
					line(x + 10 + i * 18, y + 6, x + 10 + i * 18, y + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
					bar(x - 10 + i * 18, y + 3, x + 7 + i * 18, y + 24);//遮盖文字
					i--;//减少一个字数
					
			
					line(x + 10 + i * 18, y + 6, x + 10 + i * 18, y + 20);//绘制光标
					*(code + i) = '\0';
					*(code + i + 1) = '\0';
				}
            }
            else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
				break;
			}
        }
        else 
        {
            if (t != '\n'
				&& t != '\r'
				&& t != ' '
                && t != 033)
			{
				if (t == '\b' && i > 0)//退格键
				{
					bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标
					bar(x - 10 + i * 18, y + 3, x + 7 + i * 18, y + 24);//遮盖文字
					i--;//减少一个字数
					
					line(x + 10 + i * 18, y + 6, x + 10 + i * 18, y + 20);//绘制光标
					*(code + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x + 8 + i * 18, y + 3, x + 12 + i * 18, y + 24);//遮盖光标  
				break;
			}
        }
    }
    
}
/*********************************************
FUNCTION:log_judge
DESCRIPTION：judge whether the account  code matches
INPUT:name,code,usernum
RETURN: 0,1
***********************************************/
int log_judge(char *name, char *code, char *usernum)
{
    int len = 0;
    int i = 0;
    FILE *fp;
    USER *u = NULL;
    if ((fp = fopen("C:\\CODE\\database\\userdata.dat", "rb+")) == NULL)
    {
        perror("Can't open userdata.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(USER);
    for (i = 0; i < len; i++)
    {
        if ((u = (USER *)malloc(sizeof(USER))) == NULL)
        {
            perror("memoryallocation runs wrong");
            delay(3000);
            exit(1);
        }
        fseek(fp, i * sizeof(USER), SEEK_SET);
        fread(u, sizeof(USER), 1, fp);
        if (strcmp(name, u->user) == 0) // 用户名匹配
        {
            if (strcmp(code, u->password) != 0) // 密码不配
            {
                
                puthz(450, 290, "密码错误", 16, 17, RED);
                delay(1000);
                if (u != NULL)
                {
                    free(u);
                    u = NULL;
                }
                return 0;
            }
			else if (strcmp(code, u->password) == 0) // 密码匹配
            {
                *usernum = u->usernum;
                puthz(290, 355, "登录成功", 16, 17, RED);
                if (u != NULL)
                {
                    free(u);
                    u = NULL;
                }
                if (fclose(fp) != 0)
                {
                    perror("Can't close database");
                    delay(3000);
                    exit(1);
                }
                return 1;
                // 切换界面
            }
        }
        if (u != NULL)
        {
            free(u);
            u = NULL;
        }
    }
    if (i == len)
    {
        puthz(450, 170, "账户未注册", 16, 17, RED); // 走到最后一位
    }
    if (u != NULL)
    {
        free(u);
        u = NULL;
    }
    
    if (fclose(fp) != 0)
    {
        perror("Can't close database.");
        delay(3000);
        exit(1);
    }
	return 0;
}
/*********************************************
FUNCTION:log_complete
DESCRIPTION：complete log.0 for complete
INPUT:name,code,usernum
RETURN: 0,1
***********************************************/
int log_complete(char *name,char*code,char *usernum)
{
    int state1 = 0;
    int state2 = 0;
    state1 = register_judgeinput(name,360,170);
    state2 = register_judgeinput(code,360,290);
    if(state1 == 0||state2 == 0)
    {
        return 1;
    }
    else
    {
        if (log_judge(name, code, usernum) == 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}