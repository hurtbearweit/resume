#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "hz.h"
#include "mouse.h"
#include "CHOOSE.H"
#include "LOG.H"
#include"HOME.H"
/*********************************************
FUNCTION:page_choose
DESCRIPTION：draw the choose template page
INPUT:void
RETURN:2,6
***********************************************/
int page_choose()
{

    cleardevice();
    clrmous(MouseX, MouseY);
    setfillstyle(1, WHITE);
    bar(0, 0, 648, 480);
    setfillstyle(1, YELLOW);
    bar(600, 0, 648, 35); // 退出框
    log_restore(600, 0, 648, 35);
    puthz(605, 10, "退出", 16, 15, RED);
    puthz(215, 20, "请选择使用场景", 32, 32, BLACK);

    home_draw(200, 80, 440, 145, BLACK);// 1
    puthz(240, 90, "经典求职模板", 24, 28, BLACK);
    puthz(260, 120, "全行业通用模板", 16, 18, BLACK);

    home_draw(200, 160, 440, 225, BLACK);// 2
    puthz(250, 170, "零经验求职", 24, 28, BLACK);
    puthz(240, 200, "适合第一次找工作使用", 16, 18, BLACK);

    home_draw(200, 240, 440, 305, BLACK);// 3
    puthz(260, 250, "学生求职", 24, 28, BLACK);
    puthz(220, 280, "适合有一定实习经历的学生", 16, 18, BLACK);

    home_draw(200, 320, 440, 385, BLACK);// 4
    puthz(260, 330, "评奖评优", 24, 28, BLACK);
    puthz(240, 360, "适合高校内评奖评优", 16, 18, BLACK);
    while (1)
    {
        if (MouseS != 0 
        && mouse_press(200, 80, 440, 145) == 0
        && mouse_press(200, 160, 440, 225) == 0
        && mouse_press(200, 240, 440, 305) == 0
        && mouse_press(200, 320, 440, 385) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX, &MouseY, &press);
		delay(40);
        if (MouseX > 600 && MouseX < 648 && MouseY > 0 && MouseY < 35) // 退出框
        {
            if (mouse_press(600, 0, 648, 35) == 2)
            {
                log_change(600, 0, 648, 35);
            }
            if (mouse_press(600, 0, 648, 35) == 1)
            {
                return 2;
            }
        }
        //home_draw(200, 80, 440, 145, BLACK);// 1
        if (MouseX > 200 && MouseX < 440 && MouseY > 80 && MouseY < 145) // 经典求职
        {
            if (mouse_press(200, 80, 440, 145) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(200, 80, 440, 145) == 1)
            {
                return 6;
            }
        }
        //home_draw(200, 160, 440, 225, BLACK);// 2
        if (MouseX > 200 && MouseX < 440 && MouseY > 160 && MouseY < 225) // 零经验求职
        {
            if (mouse_press(200, 160, 440, 225) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(200, 160, 440, 225) == 1)
            {
                return 7;
            }
            
        }
        //home_draw(200, 240, 440, 305, BLACK);// 3
        if (MouseX > 200 && MouseX < 440 && MouseY > 240 && MouseY < 305) // 学生求职
        {
            if (mouse_press(200, 240, 440, 305) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(200, 240, 440, 305) == 1)
            {
                return 8;
            }
            
        }
        //home_draw(200, 320, 440, 385, BLACK);// 4
        if (MouseX > 200 && MouseX < 440 && MouseY > 320 && MouseY < 385) // 评奖评优
        {
                if (mouse_press(200, 320, 440, 385) == 2)
                {
                    MouseS = 1;
                    newmouse(&MouseX, &MouseY, &press);
                }
                if (mouse_press(200, 320, 440, 385) == 1)
                {
                    return 9;
                }               
        }
        
    }
}
/*********************************************
FUNCTION:page_choose_constdraw
DESCRIPTION：draw the const part
INPUT:x
RETURN:void
***********************************************/
void page_choose_constdraw(int p)
{
    clrmous(MouseX,MouseY);
    setfillstyle(1, WHITE);
    bar(0, 0, 610, 480);
    // 控制栏
    setlinestyle(0, 0, 1);
    setcolor(BLACK);
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
    setfillstyle(1, LIGHTGRAY);
    floodfill(626, 50, BLACK);
    floodfill(626, 409, BLACK);
}