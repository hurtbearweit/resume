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
    setfillstyle(1,LIGHTCYAN);
    bar(0,0,648,480);
    setfillstyle(1,YELLOW);
    bar(600,0,648,35);//退出框
    log_restore(600,0,648,35);
    puthz(605,10,"退出",16,15,RED);
	/*setfillstyle(1,WHITE);
    bar(99,430,549,480);
    setcolor(BLUE);
    // line(249,430,249,480);//选择框（99，430，249，480），制作框（249，430，399，480），个人框（399，430，549，480）
    //line(399,430,399,480);
    puthz(114,445,"选择模板",16,32,BLACK);
    puthz(268,445,"创作模板",16,32,BLACK);
    puthz(434,445,"我的",16,64,BLACK);*/
    //rectangle(75,100,205,350);
	puthz(213,30,"简历助手",48,64,RED);
    home_draw(75,100,205,350,BLUE);
    puthz(80,300,"选择模板",24,32,RED);
    setcolor(BLUE);
	rectangle(100,120,180,240);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(105,130,"RESUME");
	line(110,160,150,160);
	line(110,170,140,170);
	line(110,180,150,180);
	line(110,190,155,190);
	line(110,200,140,200);
	//rectangle(255,100,385,350);
	home_draw(255,100,385,350,BLUE);
	puthz(260,300,"创建模板",24,32,RED);
	home_draw(280,120,360,240,BLUE);
	setlinestyle(0,0,3);
	line(320,160,320,200);
	line(300,180,340,180);
	//rectangle(435,100,575,350);
	home_draw(435,100,575,350,BLUE);
	circle(505,150,30);
	line(530,170,550,240);
	line(480,170,460,240);
	line(460,240,550,240);
	puthz(440,300,"个人中心",24,32,RED);
    //printf("%d",usernum);
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
        if (MouseX>75&&MouseX<205&&MouseY>100&&MouseY<350)//选择框
        {
            if (mouse_press(75,100,205,350) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(75,100,205,350,LIGHTRED);
            }
            if (mouse_press(75,100,205,350) == 1)
            {
                clrmous(MouseX,MouseY);
                return 3;
            }
        }
        else home_draw(75,100,205,350,BLUE);
        if (MouseX>255&&MouseX<385&&MouseY>100&&MouseY<350)//制作框
        {
            if (mouse_press(255,100,385,350) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(255,100,385,350,LIGHTRED);
            }
            if (mouse_press(255,100,385,350) == 1)
            {
                clrmous(MouseX,MouseY);
                return 4;
            }
        }
        else home_draw(255,100,385,350,BLUE);
        if (MouseX>435&&MouseX<575&&MouseY>100&&MouseY<350)//个人框
        {
            if (mouse_press(435,100,575,350) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(435,100,575,350,LIGHTRED);
            }
            if (mouse_press(435,100,575,350) == 1)
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
                    setfillstyle(1,LIGHTCYAN);
                    bar(200,360,400,410);
                }	
            }
        }
        else home_draw(435,100,575,350,BLUE);
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