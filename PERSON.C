#include<graphics.h>
#include<stdio.h>
#include"hz.h"
#include"mouse.h"
#include"PERSON.H"
#include"LOG.H"
#include"COMMON.H"
#include"input.h"
#include<stdlib.h>
/*********************************************
FUNCTION:page_person
DESCRIPTION：draw the personal interface
INPUT:void
RETURN:
***********************************************/
int page_person()
{
    cleardevice();
    clrmous(MouseX,MouseY);
    setfillstyle(SOLID_FILL,WHITE);
    bar(0, 0, 640, 480);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 120, 480);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(0, 0, 640, 70);
    puthz(220, 15, "个人中心", 48, 48, YELLOW);
    setcolor(BLACK);
    setlinestyle(0, 0, 3); // 粗线
    line(0, 70, 640, 70);
    setlinestyle(0, 0, 1);       // 细线
    //rectangle(0, 275, 120, 325); // 我的简历
    puthz(20, 180, "使用信息", 24, 25, BLACK);
    puthz(20, 285, "我的简历", 24, 25, BLACK);
    setfillstyle(1, RED);
    bar(550, 30, 630, 61); // 返回框
    puthz(565, 33, "返回", 24, 30, WHITE);
    puthz(300, 240, "简历助手", 32, 35, BLACK);
    puthz(350, 280, "让就业更简单！", 24, 28, BLACK);
    while(1)
    {
        if(MouseS != 0
        &&mouse_press(550,30,630,61) == 0
        &&mouse_press(0,70,120,120) == 0
        &&mouse_press(0,170,120,220) == 0
        &&mouse_press(0,270,120,320) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if(MouseX>550&&MouseX<630&&MouseY>30&&MouseY<61)//退出框
        {
            if (mouse_press(550,30,630,61) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
            } 
            if(mouse_press(550,30,630,61) == 1)
            {
                return 2;
            } 
        }  
        if(MouseX>0&&MouseX<120&&MouseY>175&&MouseY<225)//个人信息
        {
            if(mouse_press(0,175,120,225) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                person_change(0,175,120,225);
            } 
            if(mouse_press(0,175,120,225) == 1)
            {
                return 16;
            } 
        }
        else person_restore(0,175,120,225);
        if(MouseX>0&&MouseX<120&&MouseY>275&&MouseY<325)//简历助手
        {
            if (mouse_press(0,275,120,325) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                person_change(0,275,120,325);
            } 
            if(mouse_press(0,275,120,325) == 1)
            {
                puthz(200, 400, "已存入", 24, 25, BLACK);
                setcolor(RED);
                outtextxy(300, 400, "RESUME.txt");
                delay(2000);
                setfillstyle(1, WHITE);
                bar(200, 400, 500, 500);
            } 
        }
        else person_restore(0,275,120,325);
    }
}
/*********************************************
FUNCTION:person_change
DESCRIPTION：change the border color
INPUT:x1,y1,x2,y2
RETURN:void
***********************************************/
void person_change(int x1,int y1,int x2,int y2)
{
     setcolor(RED);
     setlinestyle(0,0,3);
	 rectangle(x1-2,y1-2,x2+2,y2+2);
	 setlinestyle(0,0,1);
}
/*********************************************
FUNCTION:person_restore
DESCRIPTION：restore the border color
INPUT:x1,y1,x2,y2
RETURN:void
***********************************************/
void person_restore(int x1,int y1,int x2,int y2)
{
    setcolor(BLACK);
    setlinestyle(0,0,3);
    rectangle(x1-2,y1-2,x2+2,y2+2);
    setlinestyle(0,0,1);
}

/*********************************************
FUNCTION:page_useinfo
DESCRIPTION：input self info
INPUT:void
RETURN:void
***********************************************/
 int page_useinfo(char *usernum,int count)
 {
     FILE *fp;
     int i = 0,len = 0;
     USER *u;
     char s1[10], s2[100];
     clrmous(MouseX,MouseY);
     setfillstyle(SOLID_FILL,WHITE);
     bar(0, 0, 640, 480);
     setfillstyle(SOLID_FILL, LIGHTCYAN);
     bar(0, 0, 120, 480);
     setfillstyle(SOLID_FILL, LIGHTBLUE);
     bar(0, 0, 640, 70);
     puthz(220, 15, "个人中心", 48, 48, YELLOW);
     setcolor(BLACK);
     setlinestyle(0, 0, 3); // 粗线
     line(0, 70, 640, 70);
     setlinestyle(0, 0, 1);       // 细线
    
     setfillstyle(1, RED);
     bar(550, 30, 630, 61); // 返回框
     puthz(565, 33, "返回", 24, 30, WHITE);
     puthz(20, 180, "使用信息", 24, 25, BLACK);
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
         if ((u = (USER*)malloc(sizeof(USER))) == NULL)
         {
             perror("memoryallocation runs wrong");
             delay(3000);
             exit(1);
         }
         fseek(fp, i * sizeof(USER), SEEK_SET);
         fread(u, sizeof(USER), 1, fp);
         if (*usernum == u->usernum)
         {
            
             puthz(120, 100, "欢迎用户", 24, 25, BLACK);
             itoa(*usernum, s1, 10);
             outtextxy(220, 100, s1);
             puthz(120, 180, "感谢您使用本产品", 24, 25, BLACK);
             itoa(count, s2, 10);
             puthz(120, 260, "使用本产品生成简历的次数为", 24, 25, BLACK);
             outtextxy(480, 260, s2);
         }
         else continue;
     }

     while (1)
     {
         if (MouseS != 0)
         {
             MouseS = 0;
         }
         newmouse(&MouseX,&MouseY,&press);
         delay(40);
         if(MouseX>550&&MouseX<630&&MouseY>30&&MouseY<61)//退出框
         {
             if (mouse_press(550,30,630,61) == 2)
             {
                 MouseS = 1;
                 newmouse(&MouseX,&MouseY,&press);
             } 
             if(mouse_press(550,30,630,61) == 1)
             {
                 return 5;
             } 
         } 
         if (MouseX > 0 && MouseX < 120 && MouseY>175 && MouseY < 225)//个人信息

         {
             if (mouse_press(0, 175, 120, 225) == 2)
             {
                 MouseS = 1;
                 newmouse(&MouseX, &MouseY, &press);
                 person_change(0, 175, 120, 225);
             }
             if (mouse_press(0, 175, 120, 225) == 1)
             {
                 return 16;
             }
         }
         else person_restore(0, 175, 120, 225);
      
     }
 }