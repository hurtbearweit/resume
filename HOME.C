#include"HOME.H"
#include<graphics.h>
#include<stdio.h>
#include"hz.h"
#include"mouse.h"
#include"LOG.H"

extern iflog;
/*********************************************
FUNCTION: page_home
DESCRIPTION: draw the home page
INPUT:p
RETURN:0,3,4,5,2
***********************************************/
int page_home(char usernum,char *count)
{
    cleardevice();
    clrmous(MouseX,MouseY);
    setfillstyle(1,WHITE);
    bar(0,0,648,480);
    setfillstyle(1,YELLOW);
    bar(600,0,648,35);//退出框
    log_restore(600,0,648,35);
    puthz(605,10,"退出",16,15,RED);
	puthz(213,30,"简历助手",48,64,RED);

    home_draw(200,130,440,180,BLACK);
    puthz(260,145,"选择模板",24,32,RED);

    home_draw(200, 200, 440, 250, BLACK);
    puthz(260, 215, "创建模板", 24, 32, RED);

    home_draw(200, 270, 440, 320, BLACK);
    puthz(260, 285, "个人中心", 24, 32, RED);

    while (1)
    {
         if (MouseS != 0&&mouse_press(75,100,205,350) == 0&&mouse_press(255,100,385,350) == 0&&mouse_press(435,100,575,350) == 0&&mouse_press(600,0,648,35) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if(MouseX>600&&MouseX<648&&MouseY>0&&MouseY<35)//退出框    
        {
            if (mouse_press(600,0,648,35) == 2)
            {
                log_change(600,0,648,35);
            } 
            if(mouse_press(600,0,648,35) == 1)
            {
                *count = 0;
                return 0;
            } 
        }
        else log_restore(600,0,648,35); 
        // home_draw(200,130,440,180,BLACK);
        if (MouseX>200&&MouseX<440&&MouseY>130&&MouseY<180)//选择框
        {
            if (mouse_press(200, 130, 440, 180) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(200, 130, 440, 180,LIGHTRED);
            }
            if (mouse_press(200, 130, 440, 180) == 1)
            {
                clrmous(MouseX,MouseY);
                return 3;
            }
        }
        else home_draw(200, 130, 440, 180,BLACK);
        //home_draw(200, 200, 440, 250, BLACK);
        if (MouseX>200&&MouseX<440&&MouseY>200&&MouseY<250)//制作框
        {
            if (mouse_press(200, 200, 440, 250) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(200, 200, 440, 250,LIGHTRED);
            }
            if (mouse_press(200, 200, 440, 250) == 1)
            {
                clrmous(MouseX,MouseY);
                return 4;
            }
        }
        else home_draw(200, 200, 440, 250,BLACK);
        //home_draw(200, 270, 440, 320, BLACK);
        if (MouseX>200&&MouseX<440&&MouseY>270&&MouseY<320)//个人框
        {
            if (mouse_press(200, 270, 440, 320) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(200, 270, 440, 320,LIGHTRED);
            }
            if (mouse_press(200, 270, 440, 320) == 1)
            {
                if (usernum != 0)
                {
                    clrmous(MouseX,MouseY);
                    return 5;
                }
                else//提示登录
                {                 
                    puthz(230,370,"请先登录！",32,32,BLACK);
                    delay(500);					
                    setfillstyle(1,WHITE);
                    bar(200,360,400,410);
                }	
            }
        }
        else home_draw(200, 270, 440, 320,BLACK);
    }
    
}
/*********************************************
FUNCTION: home_draw
DESCRIPTION: draw the const part
INPUT:x1,y1,x2,y2
RETURN:void
***********************************************/
void home_draw(int x1,int y1,int x2,int y2,int color)
{
    setlinestyle(0,0,3);
    setcolor(color);
	line(x1,y1+10,x1,y2-10);
	line(x2,y1+10,x2,y2-10);
	line(x1+10,y1,x2-10,y1);
	line(x1+10,y2,x2-10,y2);
	arc(x1+10,y1+10,90,180,10);
	arc(x1+10,y2-10,180,270,10);
	arc(x2-10,y1+10,0,90,10);
	arc(x2-10,y2-10,270,360,10);
}