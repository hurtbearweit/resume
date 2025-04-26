#include<graphics.h>
#include<stdio.h>
#include"hz.h"
#include"mouse.h"
#include"MAKE.H"
#include"LOG.H"
#include"HOME.H"
#include"CLASSIC.H"
#include"INFO.H"
#include<stdlib.h>
#include<string.h>
#include"COMMON.H"
#include"save.H"
/*********************************************
FUNCTION:page_make
DESCRIPTION：draw the make template page
INPUT:void
RETURN:
***********************************************/
int page_make()
{
    
    clrmous(MouseX,MouseY);
    setfillstyle(1,WHITE);
    bar(0,0,640,480);
    setfillstyle(1,YELLOW);
    bar(600,0,648,35);//退出框
    log_restore(600,0,648,35);
    puthz(605,10,"退出",16,15,RED);
    puthz(230, 20, "创建模板", 32, 64, BLACK);

    /*setfillstyle(1,WHITE);
    bar(20, 60, 420, 125);*/
    home_draw(20,60,420,125,BLACK);
    puthz(25,70,"选择内容",24,32,BLACK);
    setlinestyle(0,0,3);
    // line(380,80,400,90);
    // line(400,90,410,80);
    line(400,80,410,90);
    line(410,90,400,100);
     
    //bar(20,165,420,230);
    home_draw(20,165,420,230,BLACK); 
    puthz(25,175,"顺序预览",24,32,BLACK);
    setlinestyle(0,0,3);
    line(400,185,410,195);
    line(410,195,400,205);

    setfillstyle(1,LIGHTGRAY);
    bar(440,100,600,180);
    home_draw(440, 100, 600, 180,BLACK);
    puthz(460,130,"创建",32,64,BLACK);

    while(1)
    {
        if(MouseS != 0
            &&mouse_press(20,60,420,125) == 0
            &&mouse_press(20,165,420,230) == 0
            &&mouse_press(440, 100, 600, 180) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>20&&MouseX<420&&MouseY>60&&MouseY<125)//选择内容
        {
            if (mouse_press(20,60,420,125) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(20,60,420,125,RED);
            }
            if (mouse_press(20,60,420,125) == 1)
            {
                setfillstyle(1,WHITE);
                bar(400,80,410,100);
                setlinestyle(0,0,1);
                setcolor(BLACK);
                line(390,90,400,100);
                line(400,100,410,90);
                return 13;
            }            
        }
        else home_draw(20,60,420,125,BLACK);
        if (MouseX>20&&MouseX<420&&MouseY>165&&MouseY<230)//顺序预览
        {
            if (mouse_press(20,165,420,230) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(20,165,420,230,RED);
            }
            if (mouse_press(20,165,420,230) == 1)
            {
                setfillstyle(1,WHITE);
                bar(390,185,410,205);
                setlinestyle(0,0,1);
                setcolor(BLACK);
                line(390,195,400,205);
                line(400,205,410,195);
                return 14;
            }            
        }
		else home_draw(20,165,420,230,BLACK);
        //   home_draw(440, 100, 600, 180,BLACK);
        if (MouseX>440&&MouseX<600&&MouseY>100&&MouseY<180)//创建
        {
            if (mouse_press(440, 100, 600, 180) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(440, 100, 600, 180,RED);
            }
            if (mouse_press(440, 100, 600, 180) == 1)
            {
                return 15;
            }
            
        }
        
        if(MouseX>600&&MouseX<648&&MouseY>0&&MouseY<35)//退出框
        {
            if (mouse_press(600,0,648,35) == 2)
            {
                log_change(600,0,648,35);
            } 
            if(mouse_press(600,0,648,35) == 1)
            {
                return 2;
            } 
        }
    }
}
/*********************************************
FUNCTION:make_list
DESCRIPTION：draw the make list
INPUT:void
RETURN:void
***********************************************/
int make_list(int pchoose[],int turn[])
{
    int i = 0,max = 0,j = 0;
    char output[8][2];
    memset(output,0,16*sizeof(char));
    clrmous(MouseX,MouseY);
    setfillstyle(1,WHITE);
    setcolor(BLACK);
    home_draw(20,60,420,125,BLACK);
    bar(20,125,420,445);
    setlinestyle(0,0,3);
    line(20, 125, 20, 445);
    line(420, 125, 420, 445);
    //向右箭头覆盖成向右箭头
    puthz(20,130,"基本信息",24,32,BLACK);
    rectangle(390,130,410,150);
    line(20,165,420,165);
    puthz(20,170,"求职意向",24,32,BLACK);
    rectangle(390,170,410,190);
    line(20,205,420,205);
    puthz(20,210,"教育信息",24,32,BLACK);
    rectangle(390,210,410,230);
    line(20,245,420,245);
    puthz(20,250,"工作信息",24,32,BLACK);
    rectangle(390,250,410,270);
    line(20,285,420,285);
    puthz(20,290,"技能信息",24,32,BLACK);
    rectangle(390,290,410,310);
    line(20,325,420,325);
    puthz(20,330,"自我评价",24,32,BLACK);
    rectangle(390,330,410,350);
    line(20,365,420,365);
    puthz(20,370,"在校经历",24,32,BLACK);
    rectangle(390,370,410,390);
    line(20,405,420,405);
    puthz(20,410,"实习经历",24,32,BLACK);
    rectangle(390,410,410,430);
    line(20, 450, 420, 450);
    
    setfillstyle(1,YELLOW);
    bar(600,0,648,35);//退出框
    log_restore(600,0,648,35);
    puthz(605,10,"重置",16,15,RED);

    settextstyle(1,0,3);
    for ( i = 0; i < 8; i++)
    {
        if (pchoose[i] == 1)
        {
            setcolor(RED);
            line(390,140+40*i,400,150+40*i);
            line(400,150+40*i,410,130+40*i);
            if (turn[i] != 0)
            {
                if (max < turn[i])
                {
                    max = turn[i];
                }
                
                itoa(turn[i],output[i],10);
                outtextxy(200,135+40*i,output[i]);
            }
        }
    }
    //printf("%d",max);
     i = max + 1;
    while (1)
    {
        if (MouseS != 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>20&&MouseX<420&&MouseY>60&&MouseY<125)//选择内容
        {
            if (mouse_press(20,60,420,125) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(20,60,420,125,RED);
            }
            if (mouse_press(20,60,420,125) == 1)
            {
                clrmous(MouseX,MouseY);
                return 4;
            }            
        }
        else home_draw(20,60,420,125,BLACK);
        if(MouseX>600&&MouseX<648&&MouseY>0&&MouseY<35)//重置框
        {
            if (mouse_press(600,0,648,35) == 2)
            {
                log_change(600,0,648,35);
            } 
            if(mouse_press(600,0,648,35) == 1)
            {
                for ( i = 0; i < 8; i++)
                {
                    pchoose[i] = 0;
                    turn[i] = 0;
                }
                
                return 13;
            } 
        }
        if (MouseX>20&&MouseX<420&&MouseY>125&&MouseY<445)
        {
            if (mouse_press(20,125,420,165) == 1)//基本信息
            {
                clrmous(MouseX,MouseY);
                if (pchoose[0] == 0)
                {
                    pchoose[0] = 1;
                    setcolor(RED);
                    line(390,140,400,150);
                    line(400,150,410,130);
                    turn[0] = i;
                    itoa(i, output[0], 10);
                    outtextxy(200, 135, output[0]);
                    i++;
                }
                //若未选中，那么就会直接加入pchooose，并且直接排序
                else if (pchoose[0] == 1)
                {
                    for(j = 0;j<8;j++)
                    {
                        if (turn[0] < turn[j])
                        {
                            turn[j] = turn[j] - 1;
                            setfillstyle(1, WHITE);
                            setcolor(RED);
                            bar(200, 130+40*j, 240, 160+40*j);
                            itoa(turn[j],output[j],10);
                            outtextxy(200,135+40*j,output[j]);
                        } 
                    }
                    //若已经选中过了，删掉的话，就会删掉之前的所有信息，还会把排在他后面的信息往前移一位
                    pchoose[0] = 0;
                    turn[0] = 0;
                    i--;
                    setfillstyle(1,WHITE);
                    bar(200,130,240,160);
                    bar(390,130,410,150);
                    rectangle(390,130,410,150);
                    
                }
                
            }
            if (mouse_press(20,165,420,205) == 1)//求职意向
            {
                clrmous(MouseX,MouseY);
                if (pchoose[1] == 0)
                {
                    pchoose[1] = 1;
                    setcolor(RED);
                    line(390,180,400,190);
                    line(400,190,410,170);
                    turn[1] = i;
                    itoa(i, output[1], 10);
                    outtextxy(200, 175, output[1]);
                    i++;
                }
                else if (pchoose[1] == 1)
                {
                    for(j = 0;j<8;j++)
                    {
                        if (turn[1] < turn[j])
                        {
                            turn[j] = turn[j] - 1;
                            setfillstyle(1, WHITE);
                            setcolor(RED);
                            bar(200, 130+40*j, 240, 160+40*j);
                            itoa(turn[j],output[j],10);
                            outtextxy(200,135+40*j,output[j]);
                        }
                        
                    }
                    pchoose[1] = 0;
                    turn[1] = 0;
                    i--;
                    setfillstyle(1,WHITE);
                    bar(200,170,240,200);
                    bar(390,170,410,190);
                    rectangle(390,170,410,190);
                }
                
            }
            if (mouse_press(20,205,420,245) == 1)//教育经历
            {
                clrmous(MouseX,MouseY);
                if (pchoose[2] == 0)
                {
                    pchoose[2] = 1;
                    setcolor(RED);
                    line(390,220,400,230);
                    line(400,230,410,210);
                    turn[2] = i;
                    itoa(i, output[2], 10);
                    outtextxy(200, 215, output[2]);
                    i++;
                }
                else if (pchoose[2] == 1)
                {
                    for(j = 0;j<8;j++)
                    {
                        if (turn[2] < turn[j])
                        {
                            turn[j] = turn[j] - 1;
                            setfillstyle(1, WHITE);
                            setcolor(RED);
                            bar(200, 130+40*j, 240, 160+40*j);
                            itoa(turn[j],output[j],10);
                            outtextxy(200,135+40*j,output[j]);
                        }
                        
                    }
                    pchoose[2] = 0;
                    turn[2] = 0;
                    i--;
                    setfillstyle(1,WHITE);
                    bar(200,210,240,240);
                    bar(390,210,410,230);
                    rectangle(390,210,410,230);
                }
            }
            if (mouse_press(20,245,420,285) == 1)//项目经历
            {
                clrmous(MouseX,MouseY);
                if (pchoose[3] == 0)
                {
                    pchoose[3] = 1;
                    setcolor(RED);
                    line(390,260,400,270);
                    line(400,270,410,250);
                    turn[3] = i;
                    itoa(i, output[3], 10);
                    outtextxy(200, 255, output[3]);
                    i++;
                }
                else if (pchoose[3] == 1)
                {
                    for(j = 0;j<8;j++)
                    {
                        if (turn[3] < turn[j])
                        {
                            turn[j] = turn[j] - 1;
                            setfillstyle(1, WHITE);
                            setcolor(RED);
                            bar(200, 130+40*j, 240, 160+40*j);
                            itoa(turn[j],output[j],10);
                            outtextxy(200,135+40*j,output[j]);
                        }
                        
                    }
                    pchoose[3] = 0;
                    turn[3] = 0;
                    i--;
                    setfillstyle(1,WHITE);
                    bar(200,250,240,280);
                    bar(390,250,410,270);
                    rectangle(390,250,410,270);
                }
            }
            if (mouse_press(20,285,420,325) == 1)//技能信息
            {
                clrmous(MouseX,MouseY);
                if (pchoose[4] == 0)
                {
                    pchoose[4] = 1;
                    setcolor(RED);
                    line(390,300,400,310);
                    line(400,310,410,290);
                    turn[4] = i;
                    itoa(i, output[4], 10);
                    outtextxy(200, 295, output[4]);
                    i++;
                }
                else if (pchoose[4] == 1)
                {
                    for(j = 0;j<8;j++)
                    {
                        if (turn[4] < turn[j])
                        {
                            turn[j] = turn[j] - 1;
                            setfillstyle(1, WHITE);
                            setcolor(RED);
                            bar(200, 130+40*j, 240, 160+40*j);
                            itoa(turn[j],output[j],10);
                            outtextxy(200,135+40*j,output[j]);
                        }
                        
                    }
                    pchoose[4] = 0;
                    turn[4] = 0;
                    i--;
                    setfillstyle(1,WHITE);
                    bar(200,290,240,320);
                    bar(390,290,410,310);
                    rectangle(390,290,410,310);
                }
            }
            if (mouse_press(20,325,420,365) == 1)//自我评价
            {
                clrmous(MouseX,MouseY);
                if (pchoose[5] == 0)
                {
                    pchoose[5] = 1;
                    setcolor(RED);
                    line(390,340,400,350);
                    line(400,350,410,330);
                    turn[5] = i;
                    itoa(i, output[5], 10);
                    outtextxy(200, 335, output[5]);
                    i++;
                }
                else if (pchoose[5] == 1)
                {
                    for(j = 0;j<8;j++)
                    {
                        if (turn[5] < turn[j])
                        {
                            turn[j] = turn[j] - 1;
                            setfillstyle(1, WHITE);
                            setcolor(RED);
                            bar(200, 130+40*j, 240, 160+40*j);
                            itoa(turn[j],output[j],10);
                            outtextxy(200,135+40*j,output[j]);
                        }
                        
                    }
                    pchoose[5] = 0;
                    turn[5] = 0;
                    i--;
                    setfillstyle(1,WHITE);
                    bar(200,330,240,360);
                    bar(390,330,410,350);
                    rectangle(390,330,410,350);
                }
            }
            if (mouse_press(20,365,420,405) == 1)//在校经历
            {
                clrmous(MouseX,MouseY);
                if (pchoose[6] == 0)
                {
                    pchoose[6] = 1;
                    setcolor(RED);
                    line(390,380,400,390);
                    line(400,390,410,370);
                    turn[6] = i;
                    itoa(i, output[6], 10);
                    outtextxy(200, 375, output[6]);
                    i++;
                }
                else if (pchoose[6] == 1)
                {
                    for(j = 0;j<8;j++)
                    {
                        if (turn[6] < turn[j])
                        {
                            turn[j] = turn[j] - 1;
                            setfillstyle(1, WHITE);
                            setcolor(RED);
                            bar(200, 130+40*j, 240, 160+40*j);
                            itoa(turn[j],output[j],10);
                            outtextxy(200,135+40*j,output[j]);
                        }
                        
                    }
                    pchoose[6] = 0;
                    turn[6] = 0;
                    i--;
                    setfillstyle(1,WHITE);
                    bar(200,370,240,400);
                    bar(390,370,410,390);
                    rectangle(390,370,410,390);
                }
            }
            if (mouse_press(20,405,420,445) == 1)//实习经历
            {
                clrmous(MouseX,MouseY);
                if (pchoose[7] == 0)
                {
                    pchoose[7] = 1;
                    setcolor(RED);
                    line(390,420,400,430);
                    line(400,430,410,410);
                    turn[7] = i;
                    itoa(i, output[7], 10);
                    outtextxy(200, 415, output[7]);
                    i++;
                }
                else if (pchoose[7] == 1)
                {
                    for(j = 0;j<8;j++)
                    {
                        if (turn[7] < turn[j])
                        {
                            turn[j] = turn[j] - 1;
                            setfillstyle(1, WHITE);
                            setcolor(RED);
                            bar(200, 130+40*j, 240, 160+40*j);
                            itoa(turn[j],output[j],10);
                            outtextxy(200,135+40*j,output[j]);
                        }
                    }
                    pchoose[7] = 0;
                    turn[7] = 0;
                    i--;
                    setfillstyle(1,WHITE);
                    bar(200,410,240,440);
                    bar(390,410,410,430);
                    rectangle(390,410,410,430);
                }
            }
        }
        
    }
    
}
/*********************************************
FUNCTION:turn_list
DESCRIPTION：draw the turn list
INPUT:void
RETURN:
***********************************************/
int turn_list(int pchoose[],int turn[])
{
    int i = 0,j = 0,k = 1,l = 0;
    char temp[8][20] = {"基本信息","求职意向","教育信息","工作信息","技能信息","自我评价","在校经历","实习经历"};
    char output[8][2] ={{0},{0},{0},{0},{0},{0},{0},{0}};
    clrmous(MouseX,MouseY);
    setfillstyle(1,WHITE);
    setcolor(BLACK);
    setlinestyle(0,0,3);
    bar(20,230,420,480);
    for ( i = 0; i < 8; i++)
    {
        for ( l = 0; l < 8; l++)
        {
            if (turn[l] == k)
            {
                k++;
                j++;
                line(20, 230 + 32 * j, 420, 230 + 32 * j);
                line(20, 200 + 32 * j, 20, 230 + 32 * j);
                line(420, 200 + 32 * j, 420, 230 + 32 * j);
                puthz(22, 230 + 32 * (j - 1), temp[l], 24, 32, BLACK);
            }
        }    
    }
    while (1)
    {
        if (MouseS != 0&&mouse_press(20,165,420,230) == 0)
        {
            MouseS = 0;
        }
        
		newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>20&&MouseX<420&&MouseY>165&&MouseY<230)//选择顺序
        {
            if (mouse_press(20,165,420,230) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(20,165,420,230,RED);
            }
            if (mouse_press(20,165,420,230) == 1)
            {
                return 4;
            }            
        }
        
    }
    
}
/*********************************************
FUNCTION:my_template
DESCRIPTION： the  template page
INPUT:pchoose,turn
RETURN:
***********************************************/
int my_template(int *x,int pchoose[],int turn[],int *info_page,int *template_page,int ifin[][6],int psave[],int *count)
{
    
    //int x = 0;
    int i = 0,j = 0,k = 1,l = 0;
    int length[8] = {90,65,156,126,108,200,150,200};
    int turnlength[8] = {0};//第N个板块的长度
    int turnnum[8] = {0};//第N个板块对应的值
    void *p;
    unsigned s;
    FILE *fp;
    USER *u;
    if (*template_page != 5)
    {
        memset(psave,0,9*sizeof(int));
        memset(ifin,0,48*sizeof(int));
    }
    *template_page = 5;
    //template_page就是选择的模板编号，0~3就是经典，小白，毕业生和评优生的模板，4是自定义模板
    
    
    my_template_draw(*x,pchoose,turn,ifin,psave);
    for ( i = 0; i < 8; i++)
    {
        for ( l = 0; l < 8; l++)
        {
            if (turn[l] == k)
            {
                k++;
                j = j + length[l];
                turnlength[k-2] = j;
                turnnum[k-2] = l + 1; 
            }
            //统计出选出来的模块的次序以及对应的长度
            else if (turn[l] == 0)
            {
                psave[l] = 0;
                ifin[l][0] = ifin[l][1] = ifin[l][2] = ifin[l][3] = ifin[l][4] = ifin[l][5] = 0;
            }
            
        }    
    }
    while (1)
    {
        if (MouseS != 0
            &&mouse_press(610, 45, 640, 80) == 0
            &&mouse_press(610, 395, 640, 430) == 0
            &&mouse_press(0,0,500,turnlength[0]+*x) == 0
            &&mouse_press(610, 0, 640, 45) == 0
            &&mouse_press(610, 430, 640, 480) == 0)
        {
            MouseS = 0;
        }
        
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>0&&MouseX<500&&MouseY>0&&MouseY<turnlength[0]+*x-3&&turnlength[0] > 0)//第一个板块
        {
            if (mouse_press(0,0,500,turnlength[0]+*x-3) == 2)
            {
                MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,0,500,turnlength[0]+*x-3,1);
            }
            if (mouse_press(0,0,500,turnlength[0]+*x-3) == 1)
            {
                *info_page = turnnum[0];
				delay(100);
				return 11;
            }
        }
        else classic_border(0,0,500,turnlength[0]+*x-3,0);
        if (MouseX>0&&MouseX<500&&MouseY>turnlength[0]+*x+2&&MouseY<turnlength[1]+*x-3&&turnlength[1] > 0)//第二个板块
        {
            if (mouse_press(0,turnlength[0]+*x+2,500,turnlength[1]+*x-3) == 2)
            {
                MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,turnlength[0]+*x+2,500,turnlength[1]+*x-3,1);
            }
            if (mouse_press(0,turnlength[0]+*x+2,500,turnlength[1]+*x-3) == 1)
            {
                *info_page = turnnum[1];
				delay(100);
				return 11;
            }
        }
        else classic_border(0,turnlength[0]+*x+2,500,turnlength[1]+*x-3,0);
        if (MouseX>0&&MouseX<500&&MouseY>turnlength[1]+*x+2&&MouseY<turnlength[2]+*x-3&&turnlength[2] > 0)//第三个板块
        {
            if (mouse_press(0,turnlength[1]+*x+2,500,turnlength[2]+*x-3) == 2)
            {
                MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,turnlength[1]+*x+2,500,turnlength[2]+*x-3,1);
            }
            if (mouse_press(0,turnlength[1]+*x+2,500,turnlength[2]+*x-3) == 1)
            {
                *info_page = turnnum[2];
				delay(100);
				return 11;
            }
        }
        else classic_border(0,turnlength[1]+*x+2,500,turnlength[2]+*x-3,0);
        if (MouseX>0&&MouseX<500&&MouseY>turnlength[2]+*x+2&&MouseY<turnlength[3]+*x-3&&turnlength[3] > 0)//第四个板块
        {
            if (mouse_press(0,turnlength[2]+*x+2,500,turnlength[3]+*x-3) == 2)
            {
                MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,turnlength[2]+*x+2,500,turnlength[3]+*x-3,1);
            }
            if (mouse_press(0,turnlength[2]+*x+2,500,turnlength[3]+*x-3) == 1)
            {
                *info_page = turnnum[3];
				delay(100);
				return 11;
            }
        }
        else classic_border(0,turnlength[2]+*x+2,500,turnlength[3]+*x-3,0);
        if (MouseX>0&&MouseX<500&&MouseY>turnlength[3]+*x+2&&MouseY<turnlength[4]+*x-3&&turnlength[4] > 0)//第五个板块
        {
            if (mouse_press(0,turnlength[3]+*x+2,500,turnlength[4]+*x-3) == 2)
            {
                MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,turnlength[3]+*x+2,500,turnlength[4]+*x-3,1);
            }
            if (mouse_press(0,turnlength[3]+*x+2,500,turnlength[4]+*x-3) == 1)
            {
                *info_page = turnnum[4];
				delay(100);
				return 11;
            }
        }
        else classic_border(0,turnlength[3]+*x+2,500,turnlength[4]+*x-3,0);
        if (MouseX>0&&MouseX<500&&MouseY>turnlength[4]+*x+2&&MouseY<turnlength[5]+*x-3&&turnlength[5] > 0)//第六个板块
        {
            if (mouse_press(0,turnlength[4]+*x+2,500,turnlength[5]+*x-3) == 2)
            {
                MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,turnlength[4]+*x+2,500,turnlength[5]+*x-3,1);
            }
            if (mouse_press(0,turnlength[4]+*x+2,500,turnlength[5]+*x-3) == 1)
            {
                *info_page = turnnum[5];
				delay(100);
				return 11;
            }
        }
        else classic_border(0,turnlength[4]+*x+2,500,turnlength[5]+*x-3,0);
        if (MouseX>0&&MouseX<500&&MouseY>turnlength[5]+*x+2&&MouseY<turnlength[6]+*x-3&&turnlength[6] > 0)//第七个板块
        {
            if (mouse_press(0,turnlength[5]+*x+2,500,turnlength[6]+*x-3) == 2)
            {
                MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,turnlength[5]+*x+2,500,turnlength[6]+*x-3,1);
            }
            if (mouse_press(0,turnlength[5]+*x+2,500,turnlength[6]+*x-3) == 1)
            {
                *info_page = turnnum[6];
				delay(100);
				return 11;
            }
        }
        else classic_border(0,turnlength[5]+*x+2,500,turnlength[6]+*x-3,0);
        if (MouseX>0&&MouseX<500&&MouseY>turnlength[6]+*x+2&&MouseY<turnlength[7]+*x-3&&turnlength[7] > 0)//第八个板块
        {
            if (mouse_press(0,turnlength[6]+*x+2,500,turnlength[7]+*x-3) == 2)
            {
                MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
				classic_border(0,turnlength[6]+*x+2,500,turnlength[7]+*x-3,1);
            }
            if (mouse_press(0,turnlength[6]+*x+2,500,turnlength[7]+*x-3) == 1)
            {
                *info_page = turnnum[7];
				delay(100);
				return 11;
            }
        }
        else classic_border(0,turnlength[6]+*x+2,500,turnlength[7]+*x-3,0);
        if (MouseX > 610 && MouseX < 640 && MouseY > 0 && MouseY < 45) // 退出框
		{
			if (mouse_press(610, 0, 640, 45) == 2)
			{
				MouseS = 1;
				newmouse(&MouseX, &MouseY, &press);
			}
			if (mouse_press(610, 0, 640, 45) == 1)
			{
				// memset(psave,0,9*sizeof(int));
                // memset(ifin,0,48*sizeof(int));
                return 4;
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
					my_template_draw(*x,pchoose,turn,ifin,psave);
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
				my_template_draw(*x,pchoose,turn,ifin,psave);
			}
		}
    }
    
}
/*********************************************
FUNCTION:my_template_draw
DESCRIPTION：draw the  template page
INPUT:pchoose,turn
RETURN:
***********************************************/
void my_template_draw(int x,int pchoose[],int turn[],int ifin[][6],int psave[])
{
    int i = 0,j = 0,k = 1,l = 0;
    char temp[8][20] = {"基本信息","求职意向","教育信息","工作信息","技能信息","自我评价","在校经历","实习经历"};
    int length[8] = {90,65,156,126,108,200,150,200};
    int myturnlength[8] = {0};//各预设顺序板块起点的位置
    clrmous(MouseX,MouseY);
    setfillstyle(1,WHITE);
    setcolor(BLACK);
    bar(0,0,640,480);
    //控制栏
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
    floodfill(625,70,BLACK);
	floodfill(625,410,BLACK);
    
    
    for ( i = 0; i < 8; i++)
    {
        for ( l = 0; l < 8; l++)
        {
            if (turn[l] == k)
            {
                k++;
                //puthz(0,j,temp[l],24,32,BLACK);
                certain_part_draw(j+x,l);
                myturnlength[l] = j;
                j = j + length[l];
                setlinestyle(0,0,3);
                setcolor(BLACK);
                line(0,j+x,610,j+x);
            }
        }    
    }
    if (psave[0] == 1&&turn[0] != 0)
    {
		put_nameinfo(x + myturnlength[0],ifin);
	}
	if (psave[1] == 1&&turn[1] != 0)
	{
		put_intention_info(x + myturnlength[1] + 30,ifin);
	}
	if (psave[2] == 1&&turn[2] != 0)
	{
		put_education_info(x + myturnlength[2] + 35,ifin);
	}
	if (psave[3] == 1&&turn[3] != 0)
	{
		put_experience_info(x + myturnlength[3]+35,ifin);
	}
	if (psave[4] == 1&& turn[4] != 0)
	{
		put_skill_info(x + myturnlength[4]+30,ifin);
	}
	if (psave[5] == 1&&turn[5] != 0) 
	{
		put_comment_info(x + myturnlength[5]+30,ifin);
	}
    if (psave[6] == 1&&turn[6] != 0)
    {
        put_undergo_info(x + myturnlength[6]+30,ifin);
    }
    if (psave[7] == 1&&turn[7] != 0)
    {
        put_intern_info(x + myturnlength[7]+30,ifin);
    }
    
}
/*********************************************
FUNCTION:certain_part_draw
DESCRIPTION：draw the certain part
INPUT:x
RETURN:
***********************************************/
void certain_part_draw(int x,int part)
{
    
    switch (part)
    {
        //基本信息
        case 0 :  puthz(0,0+x+5,"姓名",24,32,BLACK);
                  puthz(0,30+x+5,"手机",16,18,BLACK);
                  puthz(200,30+x+5,"邮箱",16,18,BLACK);
                  puthz(0,50+x+5,"微信",16,18,BLACK);
                  puthz(200,50+x+5,"出生日期",16,18,BLACK);
	              break;
        //求职意向
        case 1 : puthz(0,  x + 5, "求职意向", 24, 32, BLACK);
		         puthz(0, 30 + x + 5 , "求职岗位", 16, 18, BLACK);
		         puthz(100, 30 + x + 5 , "求职类型", 16, 18, BLACK);
		         puthz(200, 30 + x + 5, "期望薪资", 16, 18, BLACK);
		         puthz(300, 30 + x + 5, "期望城市", 16, 18, BLACK);
                 break;
        //教育信息
        case 2 : puthz(0, 0 + x + 5, "教育经历", 24, 32, BLACK);
		         puthz(0, 30 + x + 5, "学校名称", 16, 18, BLACK);
		         puthz(0, 55 + x + 5, "专业学历", 16, 18, BLACK);
	             setlinestyle(0,0,1);
		         line(0, 85 + x + 5, 5, 85 + x + 5);
	             puthz(7, 80 + x + 5, "专业成绩", 16, 18, BLACK);
		         line(0, 103 + x + 5, 5, 103 + x+ 5 );
		         puthz(7, 98 + x + 5, "主修课程", 16, 18, BLACK);
		         line(0, 121 + x + 5, 5, 121 + x + 5);
		         puthz(7, 116 + x + 5, "荣誉奖项", 16, 18, BLACK);
                 break;
        //工作信息
        case 3 : puthz(0, 0 + x + 5, "工作经历", 24, 32, BLACK);
		         puthz(0, 30 + x + 5, "公司名称", 16, 18, BLACK);
		         puthz(0, 55 + x + 5, "职位名称", 16, 18, BLACK);
		         puthz(400, 55 + x + 5, "开始时间", 16, 18, BLACK);
		         puthz(500, 55 + x + 5, "结束时间", 16, 18, BLACK);
		         setlinestyle(0, 0, 1);
		         line(480, 64 + x + 5, 490, 64 + x + 5);
                 break;
        //技能信息
        case 4 : puthz(0,  x + 5, "技能证书", 24, 32, BLACK);
                 break;
        //自我评价
        case 5 : puthz(0,  x + 5, "自我评价", 24, 32, BLACK);
                 break;
        //在校经历
        case 6 : puthz(0,x + 5,"在校经历",24,32,BLACK);
                 //puthz(0, 35 + x, "社团或活动名称", 16, 18, BLACK);
                 break;
        //实习经历
        case 7 : puthz(0, 5 + x, "实习经历", 24, 32, BLACK);
                //  puthz(0, 30 + x, "公司名称", 16, 18, BLACK);
                //  puthz(0, 55 + x, "职位名称", 16, 18, BLACK);
                //  puthz(0,90 + x,"经历",16,24,BLACK);
                 break;          
    }
}
