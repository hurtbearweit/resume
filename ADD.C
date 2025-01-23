#include <stdio.h>
#include<graphics.h>
#include"mouse.h"
#include"hz.h"
#include"HOME.H"
#include<stdlib.h>
/*********************************************
FUNCTION:page_add
DESCRIPTION:add 
INPUT:
RETURN:
***********************************************/
int page_add(int pos[],int template_page,int *ifadd)
{
    int i = 0;
    //memset(pos,1,8*sizeof(int));
    *ifadd= template_page;

    clrmous(MouseX,MouseY);
    setfillstyle(1,WHITE);
    setcolor(BLACK);
    bar(0,0,640,480);
    puthz(155,20,"请选择恢复内容",32,64,RED);
    puthz(20,75,"求职意向",24,32,BLACK);
    home_draw(20,70,150,190,BLACK);
    rectangle(60,115,100,145);
    puthz(170,75,"教育信息",24,32,BLACK);
    home_draw(170,70,310,190,BLACK);
    rectangle(220,115,260,145);
    puthz(330,75,"工作信息",24,32,BLACK);
    home_draw(330,70,470,190,BLACK);
    rectangle(380,115,420,145);
    puthz(490,75,"技能信息",24,32,BLACK);
    home_draw(490,70,630,190,BLACK);
    rectangle(540,115,580,145);
    puthz(20,215,"自我评价",24,32,BLACK);
    home_draw(20,210,150,330,BLACK);
    rectangle(60,255,100,285);
    puthz(170,215,"在校经历",24,32,BLACK);
    home_draw(170,210,310,330,BLACK);
    rectangle(220,255,260,285);
    puthz(330,215,"实习经历",24,32,BLACK);
    home_draw(330,210,470,330,BLACK);
    rectangle(380,255,420,285);
    //home_draw(490,210,630,330,BLACK);
    setfillstyle(1,LIGHTGRAY);
    bar(270,385,370,435);
    puthz(270,390,"返回",24,64,BLACK);
    puthz(0,450,"该功能只能按预设顺序添加更改请自建模板",16,24,BLACK);

    for ( i = 0; i < 7; i++)
    {
        if (pos[i] == 0&&i<4)
        {
            setfillstyle(1,RED);
            bar(60+i*160,115,100+i*160,145);
        }
        if (pos[i] == 0&&i>=4)
        {
            setfillstyle(1,RED);
            bar(60+(i-4)*160,255,100+(i-4)*160,285);
        }
        
    } 
    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseS != 0
        &&mouse_press(270,385,370,435) == 0
        &&mouse_press(20,70,150,190) == 0
        &&mouse_press(170,70,310,190) == 0
        &&mouse_press(330,70,470,190) == 0)
        {
            MouseS = 0;
        }
        if (MouseX > 20 && MouseX < 150 && MouseY > 70 && MouseY < 190) //求职意向
        {
            if (mouse_press(20,70,150,190) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
                home_draw(20,70,150,190,RED);
            }
            if (mouse_press(20,70,150,190) == 1)
            {
                if (pos[0] == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,RED);
                    bar(60,115,100,145);
                    pos[0] = 0;
                } 
            }
        }
		else home_draw(20,70,150,190,BLACK);
        if (MouseX > 170 && MouseX < 310 && MouseY > 70 && MouseY < 190) //教育信息 home_draw(170,70,310,190,BLACK);
        {
            if (mouse_press(170,70,310,190) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
                home_draw(170,70,310,190,RED);
            }
            if (mouse_press(170,70,310,190) == 1)
            {
                if (pos[1] == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,RED);
                    bar(220,115,260,145);
                    pos[1] = 0;
                } 
            }
        }
		else home_draw(170,70,310,190,BLACK);
        if (MouseX > 330 && MouseX < 470 && MouseY > 70 && MouseY < 190) //工作信息 home_draw(330,70,470,190,BLACK);
        {
            if (mouse_press(330,70,470,190) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
                home_draw(330,70,470,190,RED);
            }
            if (mouse_press(330,70,470,190) == 1)
            {
                if (pos[2] == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,RED);
                    bar(380,115,420,145);
                    pos[2] = 0;
                } 
            }
        }
		else home_draw(330,70,470,190,BLACK);
        if (MouseX > 490 && MouseX < 630 && MouseY > 70 && MouseY < 190) //技能信息 home_draw(490,70,630,190,BLACK);
        {
            if (mouse_press(490,70,630,190) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
                home_draw(490,70,630,190,RED);
            }
            if (mouse_press(490,70,630,190) == 1)
            {
                if (pos[3] == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,RED);
                    bar(540,115,580,145);
                    pos[3] = 0;
                } 
            }
        }
		else home_draw(490,70,630,190,BLACK);
        if (MouseX > 20 && MouseX < 150 && MouseY > 210 && MouseY < 330) //自我评价 home_draw(20,210,150,330,BLACK);
        {
            if (mouse_press(20,210,150,330) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
                home_draw(20,210,150,330,RED);
            }
            if (mouse_press(20,210,150,330) == 1)
            {
                if (pos[4] == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,RED);
                    bar(60,255,100,285);
                    pos[4] = 0;
                } 
            }
        }
		else home_draw(20,210,150,330,BLACK);
        if (MouseX > 170 && MouseX < 310 && MouseY > 210 && MouseY < 330) //在校经历 home_draw(170,210,310,330,BLACK);
        {
            if (mouse_press(170,210,310,330) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
                home_draw(170,210,310,330,RED);
            }
            if (mouse_press(170,210,310,330) == 1)
            {
                if (pos[5] == 1)
                {
                    
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,RED);
                    bar(220,255,260,285);
                    pos[5] = 0;
                } 
            }
        }
		else home_draw(170,210,310,330,BLACK);
        if (MouseX > 330 && MouseX < 470 && MouseY > 210 && MouseY < 330) //荣誉奖项 home_draw(330,210,470,330,BLACK);
        {
            if (mouse_press(330,210,470,330) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
                home_draw(330,210,470,330,RED);
            }
            if (mouse_press(330,210,470,330) == 1)
            {
                if (pos[6] == 1)
                {
                    
                    
                    
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,RED);
                    bar(380,255,420,285);
                    pos[6] = 0;
                } 
            }
        }
		else home_draw(330,210,470,330,BLACK);
        if (MouseX > 270 && MouseX < 370 && MouseY > 385 && MouseY < 435) // 退出框
        {
            if (mouse_press(270,385,370,435) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(270,385,370,435) == 1)
            {
                clrmous(MouseX,MouseY);
                delay(200);
                switch(template_page)
                {
                    case 1 : return 6;
                            
                    case 2 : return 7;
                             
                    case 3 : return 8;
                            
                    case 4 : return 9;
                             
                    case 5 : return 15;
                             
                }
            }
        }
    }
}
