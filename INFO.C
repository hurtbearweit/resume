#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include <math.h>
#include <bios.h>
#include <conio.h>
#include <dos.h>
#include "hz.h"
#include "mouse.h"
#include"INFO.H"
#include"PERSON.H"
#include"LOG.H"
#include"input.h"
#include"REGISTER.H"
#include"HOME.H"
#include"MAKE.H"
/*********************************************
FUNCTION:page_info
DESCRIPTION:input info
INPUT:info_page,psave
RETURN:
***********************************************/
int page_info(int info_page,int psave[],int ifin[][6],int template_page)
{
    int x = 0;
    BASIC *b = (BASIC *)malloc(sizeof(BASIC));
    INTENTION *inten = (INTENTION *)malloc(sizeof(INTENTION));
    EDUCATION *edu = (EDUCATION *)malloc(sizeof(EDUCATION));
    EXPERIENCE *exp = (EXPERIENCE *)malloc(sizeof(EXPERIENCE));
    SKILL *ski = (SKILL *)malloc(sizeof(SKILL));
    COMMENT *com = (COMMENT *)malloc(sizeof(COMMENT));
    UNDERGO *und = (UNDERGO *)malloc(sizeof(UNDERGO));
    INTERN *hon = (INTERN *)malloc(sizeof(INTERN));
	memset(b,'\0',sizeof(BASIC));
    memset(inten,'\0',sizeof(INTENTION));
    memset(edu,'\0',sizeof(EDUCATION));
    memset(exp,'\0',sizeof(EXPERIENCE));
    memset(ski,'\0',sizeof(SKILL));
    memset(com,'\0',sizeof(COMMENT));
    memset(und,'\0',sizeof(UNDERGO));
    memset(hon,'\0',sizeof(INTERN));
    
    cleardevice();
    clrmous(MouseX,MouseY);
    setfillstyle(1, WHITE);
    bar(0, 0, 640, 480);
    switch(info_page)
    {
		case 1 : x = name_info(b,psave,ifin,template_page);
				 break;
		case 2 : x = intention_info(inten,psave,ifin,template_page);
				 break;
		case 3 : x = education_info(edu,psave,ifin,template_page);
				 break;
		case 4 : x = experience_info(exp,psave,ifin,template_page);
				 break;
		case 5 : x = skill_info(ski,psave,ifin,template_page);
                 break;
        case 6 : x = comment_info(com,psave,ifin,template_page);
                 break;
        case 7 : x = undergo_info(und,psave,ifin,template_page);
                 break;
        case 8 : x = intern_info(hon,psave,ifin,template_page);
                 break;         
	}

	free(b);
    free(inten);
    free(edu);
    free(exp);
    free(ski);
    free(com);
    free(und);
    free(hon);

    return x;
}
/*********************************************
FUNCTION:name_info
DESCRIPTION:put the basic info
INPUT:b,psave
RETURN:6
***********************************************/
int name_info(BASIC *b,int psave[],int ifin[][6],int template_page)
{
    int len = 0;
    BASIC temp;
    FILE *fp;
    int j = 0;
    puthz(200, 15, "基本信息", 48, 64, BLACK);
	setlinestyle(0, 0, 1);
    puthz(70, 75, "姓名", 24, 64, BLACK);
	person_restore(190, 75, 520, 115);
    puthz(70, 135, "手机", 24, 64, BLACK);
	person_restore(190, 135, 520, 175);
	puthz(70, 195, "邮箱", 24, 64, BLACK);
	person_restore(190, 195, 520, 235);
	puthz(70, 255, "微信", 24, 64, BLACK);
	person_restore(190, 255, 520, 295);
	puthz(70, 315, "出生日期", 24, 24, BLACK);
	person_restore(190, 315, 520, 355);
    setfillstyle(1,LIGHTGRAY);
    bar(150,370,250,420);
    puthz(150,375,"返回",24,64,BLACK);
    bar(430,370,530,420);
    puthz(430,375,"保存",24,64,BLACK);
    if (psave[0] == 1)
    {
        if ((fp = fopen("C:\\CODE\\database\\basic.dat", "rb+")) == NULL)
        {
            perror("Can't open basic.dat");
            delay(3000);
            exit(1);
        }
        fseek(fp, 0, SEEK_END);
        len = ftell(fp) / sizeof(BASIC);
        fseek(fp, (len - 1) * sizeof(BASIC), SEEK_SET);
        fread(&temp, sizeof(BASIC), 1, fp);
        if (fclose(fp) != 0)
        {
            perror("Can't close basic.");
            delay(3000);
            exit(1);
        }
        setcolor(0);
	    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	    settextjustify(LEFT_TEXT, TOP_TEXT);
        if (ifin[0][0] > 0)
        {
            puthz(192, 85, temp.name, 16, 18, BLACK);
            strcpy(b->name,temp.name);
            ifin[0][0] = 2;
        }
        if (ifin[0][1] > 0)
        {
            outtextxy(195,137,temp.phone);
            strcpy(b->phone,temp.phone);
            ifin[0][1] = 2;
        }
        if (ifin[0][2] > 0)
        {
            outtextxy(195,197,temp.email);
            strcpy(b->email,temp.email);
            ifin[0][2] = 2;
        }
        if (ifin[0][3] > 0)
        {
            outtextxy(195,257,temp.wechat);
            strcpy(b->wechat,temp.wechat);
            ifin[0][3] = 2;
        }
        if (ifin[0][4] > 0)
        {
            outtextxy(195,317,temp.birth);
            strcpy(b->birth,temp.birth);
            ifin[0][4]  = 2;
        }
        
    }
	while(1)
	{
        if (MouseS != 0
        &&mouse_press(190, 75, 520, 115) == 0
        &&mouse_press(190, 135, 520, 175) == 0
        &&mouse_press(190, 195, 520, 235) == 0
        &&mouse_press(190, 255,520, 295) == 0
        &&mouse_press(190, 315,520, 355) == 0
        &&mouse_press(150,370,250,420) == 0
        &&mouse_press(430,370,530,420) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>190&&MouseX<520&&MouseY>75&&MouseY<115)//姓名
        {
            if (mouse_press(190, 75, 520, 115) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 75, 520, 115);
            }
            if(mouse_press(190, 75, 520, 115)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190, 75, 520, 115);
                memset(b->name,'\0',13);
                j = hz_input(190, 85, 495, 115, b->name, 0, WHITE, BLACK, 16);
                if (j > 0)
                {
                    if (j <= 8)
                    {
                        ifin[0][0] = 1;
                    }
                    else
                    {
                        j = 0;
                        ifin[0][0] = 0;
                        puthz(540, 85, "超出限制", 16, 24, BLACK);
                        memset(b->name, '\0', 13);
                        delay(1000);
                        setfillstyle(1, WHITE);
                        bar(540, 85, 640, 130);
                        bar(190, 75, 520, 115);
                    }
                    if (cheek_legal(b->name,j))
                    {
                        j = 0;
                        ifin[0][0] = 0;
                        puthz(540, 85, "请输入中文", 16, 24, BLACK);
                        memset(b->name, '\0', 13);
                        delay(1000);
                        setfillstyle(1, WHITE);
                        bar(540, 85, 640, 130);
                        bar(190, 75, 520, 115);
                    }
                    
                }
                else ifin[0][0] = 0;
            }
        }
        else person_restore(190, 75, 520, 115);
        if (MouseX>190&&MouseX<520&&MouseY>135&&MouseY<175)//手机
        {
            if (mouse_press(190, 135, 520, 175) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 135, 520, 175);
            }
            if(mouse_press(190, 135, 520, 175)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190, 135, 520, 175);
                memset(b->phone,'\0',12);
                log_inputaccount(b->phone,195,140,11,WHITE,2);
                if (*(b->phone) != '\0')
                {
                    if (strlen(b->phone) <= 11)
                    {
                        ifin[0][1] = 1;
                    }
                    else
                    {
                        memset(b->phone,'\0',12);
                        ifin[0][1] = 0;
                        puthz(540,140,"超出限制",16,24,BLACK);
                        delay(1000);
                        setfillstyle(1,WHITE);
                        bar(540,140,640,185);
                        bar(190,135,520,175);
                    }
                }
                else ifin[0][1] = 0;
            }
        }
        else person_restore(190, 135, 520, 175);
        if (MouseX>190&&MouseX<520&&MouseY>195&&MouseY<235)//邮箱
        {
            if (mouse_press(190, 195, 520, 235) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 195, 520, 235);
            }
            if(mouse_press(190, 195,520, 235)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190, 195,520, 235);
                memset(b->email,'\0',18);
                log_inputaccount(b->email,195,200,17,WHITE,2);
                if (*(b->email) != '\0')
                {
                    if (strlen(b->email) <= 17)
                    {
                        ifin[0][2] = 1;
                    }
                    else
                    {
                        ifin[0][2] = 0;
                        memset(b->email,'\0',18);
                        puthz(540,200,"超出限制",16,24,BLACK);
                        delay(1000);
                        setfillstyle(1,WHITE);
                        bar(540,200,640,245);
                        bar(190,195,520,235);
                    }
                }
                else ifin[0][2] = 0;
            }
        }
        else person_restore(190, 195,520, 235);
        if (MouseX>190&&MouseX<520&&MouseY>255&&MouseY<295)//微信
        {
            if (mouse_press(190, 255,520, 295) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 255,520, 295);
            }
            if(mouse_press(190, 255,520, 295)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190, 255,520, 295);
                memset(b->wechat,'\0',18);
                log_inputaccount(b->wechat,195,260,17,WHITE,2);
                if (*(b->wechat) != '\0')
                {
                    if (strlen(b->wechat) <= 17)
                    {
                        ifin[0][3] = 1;
                    }
                    else
                    {
                        memset(b->wechat,'\0',18);
                        ifin[0][3] = 0;
                        puthz(540,260,"超出限制",16,24,BLACK);
                        delay(1000);
                        setfillstyle(1,WHITE);
                        bar(540,260,640,305);
                        bar(190,255,520,295);
                    }
                }
                else ifin[0][3] = 0;
            }
        }
        else person_restore(190, 255,520, 295);
        if (MouseX>190&&MouseX<520&&MouseY>315&&MouseY<355)//出生日期
        {
            if (mouse_press(190, 315,520, 355) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 315,520, 355);
            }
            if(mouse_press(190, 315,520, 355)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190, 315,520, 355);
                memset(b->birth,'\0',11);
				log_inputaccount(b->birth,195,320,17,WHITE,2);
                if (*(b->birth) != '\0')
                {
                    if (strlen(b->birth) <= 10)
                    {
                        ifin[0][4] = 1;
                    }
                    else
                    {
                        ifin[0][4] = 0;
                        memset(b->birth,'\0',11);
                        puthz(540,320,"超出限制",16,24,BLACK);
                        delay(1000);
                        setfillstyle(1,WHITE);
                        bar(540,320,640,365);
                        bar(190,315,520,355);
                    }
                }
                else ifin[0][4] = 0;
            }
        }
        else person_restore(190, 315,520, 355);
        if (MouseX > 150 && MouseX < 250 && MouseY > 370 && MouseY < 420) // 退出框
        {
            if (mouse_press(150,370,250,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(150,370,250,420) == 1)
            {
                clrmous(MouseX,MouseY);
                // delay(200);
                // return 6;
                switch (template_page)
                {
                    case 1 : delay(200);
                             return 6;
                    case 2 : delay(200);
                             return 7;         
                    case 3 : delay(200);
                             return 8;   
                    case 4 : delay(200);
                             return 9;   
                    case 5 : delay(200);
                             return 15;                   
                }
            }
        }
        if (MouseX > 430 && MouseX < 530 && MouseY > 370 && MouseY < 420) // 保存
        {
            if (mouse_press(430,370,530,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(430,370,530,420) == 1)
            {
                 nameinfo_save(b,psave);
                 
            }
        }
    }
}
/*********************************************
FUNCTION:nameinfo_save
DESCRIPTION:save the basic info
INPUT:b
RETURN:void
***********************************************/
void nameinfo_save(BASIC *b,int psave[])//记得限制游客
{
    FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\basic.dat", "rb+")) == NULL)
    {
        perror("Can't open basic.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
	fwrite(b, sizeof(BASIC), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close basic.");
		delay(3000);
		exit(1);
	}
    else
    {
        puthz(250,440,"保存成功",32,48,RED);
        delay(1000);
        setfillstyle(1, WHITE);
        bar(250,440,600,480);
        psave[0] = 1;
    }
    
}
/*********************************************
FUNCTION:put_nameinfo
DESCRIPTION:put out the nameinfo
INPUT:
RETURN:
***********************************************/
void put_nameinfo(int x,int ifin[][6])
{
    //BASIC *b = NULL;
    int len = 0;
    BASIC b = {{'\0'},{'\0'},{'\0'},{'\0'},{'\0'}};  
    FILE *fp;
	//memset(b,'\0',sizeof(BASIC));
    
//    if ((b = (BASIC*)malloc(sizeof(BASIC))) == NULL)
// 		{
// 			perror("memoryallocation runs wrong");
// 			delay(3000);
// 			exit(1);
// 		}
    if ((fp = fopen("C:\\CODE\\database\\basic.dat", "rb+")) == NULL)
    {
        perror("Can't open basic.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(BASIC);
    fseek(fp,(len-1)*sizeof(BASIC),SEEK_SET);
	fread(&b, sizeof(BASIC), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close basic.");
		delay(3000);
		exit(1);
	}
    setcolor(BLACK);
	settextstyle(2, HORIZ_DIR, 6);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	//outtextxy(0,30+x+5,b.phone);
    //strcpy(s,b.phone);
    setfillstyle(1,WHITE);
    if (ifin[0][0] > 0)
    {
        bar(0,0+x,60,25+x);
        puthz(2,2+x,b.name,24,32,BLACK);
    }
    if (ifin[0][1] > 0)
    {
        outtextxy(40,25+x+5,b.phone);
    }
    if (ifin[0][2] > 0)
    {
        outtextxy(240,25+x+5,b.email);
    }
    if (ifin[0][3] > 0)
    {
        outtextxy(40,50+x+5,b.wechat);
    }
    if (ifin[0][4] > 0)
    {
        outtextxy(280,50+x+5,b.birth);
    }
}
/*********************************************
FUNCTION:intention_info
DESCRIPTION:put the intention info
INPUT:inten,psave
RETURN:
***********************************************/
int intention_info(INTENTION *inten,int psave[],int ifin[][6],int template_page)
{
    int len = 0;
    INTENTION temp;
    INTENTION temp2;
    FILE *fp;
    int j[3] = {0};
    puthz(200, 15, "求职意向", 48, 64, BLACK);
	setlinestyle(0, 0, 1);
    puthz(65, 75, "求职岗位", 24, 32, BLACK);
	person_restore(190, 75, 520, 115);
	puthz(65, 135, "求职类型", 24, 32, BLACK);
	person_restore(190, 135, 520, 175);
	puthz(65, 195, "期望薪资", 24, 32, BLACK);
	person_restore(190, 195, 520, 235);
	puthz(65, 255, "期望城市", 24, 32, BLACK);
	person_restore(190, 255, 520, 295);
    setfillstyle(1,LIGHTGRAY);
    bar(150,370,250,420);
    puthz(150,375,"返回",24,64,BLACK);
    bar(430,370,530,420);
    puthz(430,375,"保存",24,64,BLACK);
    if (psave[1] == 1)
    {
        if ((fp = fopen("C:\\CODE\\database\\intent.dat", "rb+")) == NULL)
        {
            perror("Can't open intent.dat");
            delay(3000);
            exit(1);
        }
        fseek(fp, 0, SEEK_END);
        len = ftell(fp) / sizeof(INTENTION);
        fseek(fp, (len - 1) * sizeof(INTENTION), SEEK_SET);
        fread(&temp2, sizeof(INTENTION), 1, fp);
        if (fclose(fp) != 0)
        {
            perror("Can't close intent.");
            delay(3000);
            exit(1);
        }
        if (ifin[1][0] > 0)
        {
            puthz(192,85,temp2.job,16,18,BLACK);
            strcpy(temp.job,temp2.job);
            ifin[1][0] = 3;
        }
        if (ifin[1][1] > 0)
        {
            puthz(192,145,temp2.sort,16,18,BLACK);
            strcpy(temp.sort,temp2.sort);
            ifin[1][1] = 3;
        }
        if (ifin[1][2] > 0)
        {
            setcolor(0);
	        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	        settextjustify(LEFT_TEXT, TOP_TEXT);
            outtextxy(195,197,temp2.wage);
            strcpy(temp.wage,temp2.wage);
            ifin[1][2] = 3;
        }
        if (ifin[1][3] > 0)
        {
            puthz(192,265,temp2.city,16,18,BLACK);
            strcpy(temp.city,temp2.city);
            ifin[1][3] = 3;
        }
        
    }
	while(1)
	{
        if (MouseS != 0
        &&mouse_press(190, 75, 520, 115) == 0
        &&mouse_press(190, 135, 520, 175) == 0
        &&mouse_press(190, 195, 520, 235) == 0
        &&mouse_press(190, 255,520, 295) == 0
        &&mouse_press(150,370,250,420) == 0
        &&mouse_press(430,370,530,420) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>190&&MouseX<520&&MouseY>75&&MouseY<115)//求职岗位
        {
            if (mouse_press(190, 75, 520, 115) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 75, 520, 115);
            }
            if(mouse_press(190, 75, 520, 115)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190, 75, 520, 115);
                memset(temp.job,'\0',21);
                j[0] = hz_input(190,85,520,115,temp.job,0,WHITE,BLACK,16);
                if (j[0] > 0)
                {
                    if (j[0] <= 10)
                    {
                        ifin[1][0] = 2;
                    }
                    else
                    {
                        ifin[1][0] = 0;
                        j[0]  =0;
                        memset(temp.job,'\0',21);
                        setfillstyle(1,WHITE);
                        puthz(540,85,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,85,640,130);
                        bar(190,75,520,115);
                    }
                    if (cheek_legal(temp.job,j[0]))
                    {
                        ifin[1][0] = 0;
                        j[0]  =0;
                        memset(temp.job,'\0',21);
                        setfillstyle(1,WHITE);
                        puthz(540,85,"请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,85,640,130);
                        bar(190,75,520,115);
                    }
                    
                }
                else ifin[1][0] = 0;
            }
        }
        else person_restore(190, 75, 520, 115);
        if (MouseX>190&&MouseX<520&&MouseY>135&&MouseY<175)//求职类型
        {
            if (mouse_press(190, 135, 520, 175) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 135, 520, 175);
            }
            if(mouse_press(190, 135, 520, 175)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190, 135, 520, 175);
                memset(temp.sort,'\0',21);
                j[1] = hz_input(190,145,520,175,temp.sort,0,WHITE,BLACK,16);
                if (j[1] > 0)
                {
                    if (j[1]<=10)
                    {
                        ifin[1][1] = 2;
                    }
                    else
                    {
                        memset(temp.sort,'\0',21);
                        ifin[1][1] = 0;
                        j[1] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,145,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,145,640,190);
                        bar(190,135,520,175);
                    }
					if (cheek_legal(temp.sort,j[1]))
                    {
                        memset(temp.sort,'\0',21);
                        ifin[1][1] = 0;
                        j[1] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,145,"请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,145,640,190);
                        bar(190,135,520,175);
                    }
                    
                }
                else ifin[1][1] = 0;
                //hz_input(190,145,520,175,inten->sort,0,WHITE,BLACK,16);
            }
        }
        else person_restore(190, 135, 520, 175);
        if (MouseX>190&&MouseX<520&&MouseY>195&&MouseY<235)//期望薪资
        {
            if (mouse_press(190, 195, 520, 235) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 195, 520, 235);
            }
            if(mouse_press(190, 195,520, 235)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,195,520, 235);
                memset(temp.wage,'\0',15);
				//log_inputaccount(inten->wage,193,200,15,WHITE,2);
                log_inputaccount(temp.wage,193,200,15,WHITE,2);
                if (*(temp.wage) != '\0')
                {
                    if (strlen(temp.wage)<=14)
                    {
                        ifin[1][2] = 2;
                    }
                    else
                    {
                        ifin[1][2] = 0;
                        memset(temp.wage,'\0',15);
                        setfillstyle(1,WHITE);
                        puthz(540,200,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,200,640,245);
                        bar(190,195,520,235);
                    }
                }
                else ifin[1][2] = 0;
            }
        }
        else person_restore(190, 195,520, 235);
        if (MouseX>190&&MouseX<520&&MouseY>255&&MouseY<295)//期望城市
        {
            if (mouse_press(190, 255,520, 295) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 255,520, 295);
            }
            if(mouse_press(190, 255,520, 295)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190, 255, 520, 295);
                memset(temp.city,'\0',21);
                j[2] = hz_input(190,265,520,295,temp.city,0,WHITE,BLACK,16);
                if (j[2] > 0)
                {
                    if (j[2]<=20)
                    {
                        ifin[1][3] = 2;
                    }
                    else
                    {
                        ifin[1][3] = 0;
                        memset(temp.city,'\0',21);
                        j[2] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,265,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,265,640,310);
                        bar(190,255,520,295);
                    }
                    if (cheek_legal(temp.city,j[2]))
                    {                        
                        ifin[1][3] = 0;
                        memset(temp.city,'\0',21);
                        j[2] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,265,"请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,265,640,310);
                        bar(190,255,520,295);
                    }
                    
                }
                else ifin[1][3] = 0;
                //hz_input(190,265,520,295,inten->city,0,WHITE,BLACK,16);
            }
        }
        else person_restore(190, 255,520, 295);
        if (MouseX > 150 && MouseX < 250 && MouseY > 370 && MouseY < 420) // 退出框
        {
            if (mouse_press(150,370,250,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(150,370,250,420) == 1)
            {
                clrmous(MouseX,MouseY);
                switch (template_page)
                {
                    case 1 : delay(200);
                             return 6;
                    case 2 : delay(200);
                             return 7;         
                    case 3 : delay(200);
                             return 8;   
                    case 4 : delay(200);
                             return 9;   
                    case 5 : delay(200);
                             return 15;                   
                }
            }
        }
        if (MouseX > 430 && MouseX < 530 && MouseY > 370 && MouseY < 420) // 保存
        {
            if (mouse_press(430,370,530,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(430,370,530,420) == 1)
            {
                *inten = temp;
                 intention_info_save(inten,psave);
                 
            }
        }
    }
}
/*********************************************
FUNCTION:intention_info_save
DESCRIPTION:save the intention info
INPUT:inten,psave
RETURN:void
***********************************************/
void intention_info_save(INTENTION *inten,int psave[])
{
    FILE *fp;
    //puthz(0,0,inten->job,24,32,BLACK);
    if ((fp = fopen("C:\\CODE\\database\\intent.dat", "rb+")) == NULL)
    {
        perror("Can't open intent.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
	fwrite(inten, sizeof(INTENTION), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close intent.dat.");
		delay(3000);
		exit(1);
	} 
    else
    {
        puthz(250,440,"保存成功",32,48,RED);
        delay(1000);
        setfillstyle(1, WHITE);
        bar(250,440,600,480);
        psave[1] = 1;
        
    }
}
/*********************************************
FUNCTION:put_intention_info
DESCRIPTION:put out the intetntion info
INPUT:
RETURN:
***********************************************/
void put_intention_info(int x,int ifin[][6])
{
   
    int len = 0;
    INTENTION intent = {{'\0'},{'\0'},{'\0'},{'\0'}};  
    FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\intent.dat", "rb+")) == NULL)
    {
        perror("Can't open intent.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(INTENTION);
    fseek(fp,(len-1)*sizeof(INTENTION),SEEK_SET);
	fread(&intent, sizeof(INTENTION), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close intent.");
		delay(3000);
		exit(1);
	}
    setcolor(BLACK);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
    setfillstyle(1,WHITE);
	//bar(0,100+x+25,400,150+x);
    if (ifin[1][0] > 0)
    {
        bar(0,x,75,25+x);
        puthz(0,x+5,intent.job,16,18,BLACK);
    }
    if (ifin[1][1] > 0)
    {
        bar(100,x,175,25+x);
        puthz(100,x+5,intent.sort,16,18,BLACK);
    }
    if (ifin[1][2] > 0)
    {
	    bar(200,x,275,25+x);
        outtextxy(200,x+5,intent.wage);
    }
    if (ifin[1][3] > 0)
    {
        bar(300,x,375,25+x);
        puthz(300,x+5,intent.city,16,18,BLACK);
    }
}
/*********************************************
FUNCTION:education_info
DESCRIPTION:put the education info
INPUT:edu,psave
RETURN:
***********************************************/
int education_info(EDUCATION *edu,int psave[],int ifin[][6],int template_page)
{
    int len = 0;
    EDUCATION temp;
    EDUCATION temp2;
    FILE *fp;
    int j[4] = {0};
    puthz(200, 15, "教育经历", 48, 64, BLACK);
	setlinestyle(0, 0, 1);
    puthz(65, 75, "学校名称", 24, 32, BLACK);
	person_restore(190, 75, 520, 115);
	puthz(65, 135, "专业学历", 24, 32, BLACK);
	person_restore(190, 135, 520, 175);
	puthz(65, 195, "专业成绩", 24, 32, BLACK);
	person_restore(190, 195, 520, 235);
	puthz(65, 255, "专业课程", 24, 32, BLACK);
	person_restore(190, 255, 520, 295);
    puthz(65, 315, "荣誉奖项", 24, 32, BLACK);
	person_restore(190, 315, 520, 355);
    setfillstyle(1,LIGHTGRAY);
    bar(150,370,250,420);
    puthz(150,375,"返回",24,64,BLACK);
    bar(430,370,530,420);
    puthz(430,375,"保存",24,64,BLACK);
    if (psave[2] == 1)
    {
        if ((fp = fopen("C:\\CODE\\database\\edu.dat", "rb+")) == NULL)
        {
            perror("Can't open education.dat");
            delay(3000);
            exit(1);
        }
        fseek(fp, 0, SEEK_END);
        len = ftell(fp) / sizeof(EDUCATION);
        fseek(fp, (len - 1) * sizeof(EDUCATION), SEEK_SET);
        fread(&temp2, sizeof(EDUCATION), 1, fp);
        if (fclose(fp) != 0)
        {
            perror("Can't close edu.");
            delay(3000);
            exit(1);
        }
        if (ifin[2][0] > 0)
        {
            puthz(192,85,temp2.school,16,18,BLACK);
            strcpy(temp.school,temp2.school);
            ifin[2][0] = 4;
        }
        if (ifin[2][1] > 0)
        {
            puthz(192,145,temp2.degree,16,18,BLACK);
            strcpy(temp.degree,temp2.degree);
            ifin[2][1] = 4;
        }
        if (ifin[2][2] > 0)
        {
            setcolor(0);
	        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	        settextjustify(LEFT_TEXT, TOP_TEXT);
            outtextxy(195,197,temp2.score);
            strcpy(temp.score,temp2.score);
            ifin[2][2] = 4;
        }
        if (ifin[2][3] > 0)
        {
            puthz(192,265,temp2.course,16,18,BLACK);
            strcpy(temp.course,temp2.course);
            ifin[2][3] = 4;
        }
        if (ifin[2][4] > 0)
        {
            puthz(192,325,temp2.honor,16,18,BLACK);
            strcpy(temp.honor,temp2.honor);
            ifin[2][4] = 4;
        }
        
    }
    
	while(1)
	{
        if (MouseS != 0
        &&mouse_press(190, 75, 520, 115) == 0
        &&mouse_press(190, 135, 520, 175) == 0
        &&mouse_press(190, 195, 520, 235) == 0
        &&mouse_press(190, 255,520, 295) == 0
        &&mouse_press(190,315,520,295) == 0
        &&mouse_press(150,370,250,420) == 0
        &&mouse_press(430,370,530,420) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>190&&MouseX<520&&MouseY>75&&MouseY<115)//学校名称
        {
            if (mouse_press(190, 75, 520, 115) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 75, 520, 115);
            }
            if(mouse_press(190, 75, 520, 115)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,75,520, 115);
                memset(temp.school,'\0',19);
                j[0] = hz_input(190,85,520,115,temp.school,0,WHITE,BLACK,16);
                if (j[0] > 0)
                {
                    if (j[0]<=18)
                    {
                        ifin[2][0] = 3;
                    }
                    else
                    {
                        ifin[2][0] = 0;
                        memset(temp.school,'\0',19);
                        j[0] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,85,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,85,640,130);
                        bar(190,75,520,115);
                    }
                    if (cheek_legal(temp.school,j[0]))
                    {
                       
                        ifin[2][0] = 0;
                        memset(temp.school,'\0',19);
                        j[0] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,85, "请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,85,640,130);
                        bar(190,75,520,115);
                    }
                    
                }
                else ifin[2][0] = 0;
            }
        }
        else person_restore(190, 75, 520, 115);
        if (MouseX>190&&MouseX<520&&MouseY>135&&MouseY<175)//专业学历
        {
            if (mouse_press(190, 135, 520, 175) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 135, 520, 175);
            }
            if(mouse_press(190, 135, 520, 175)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,135,520, 175);
                memset(temp.degree,'\0',17);
                j[1] = hz_input(190,145,520,175,temp.degree,0,WHITE,BLACK,16);
                if (j[1] > 0)
                {
                    if (j[1]<=16)
                    {
                        ifin[2][1] = 3;
                    }
                    else
                    {
                        ifin[2][1] = 0;
                        j[1] = 0;
                        memset(temp.degree,'\0',17);
                        setfillstyle(1,WHITE);
                        puthz(540,145,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,145,640,190);
                        bar(190,135,520,175);
                    }
                    if (cheek_legal(temp.degree,j[1]))
                    {
                        
                        ifin[2][1] = 0;
                        j[1] = 0;
                        memset(temp.degree,'\0',17);
                        setfillstyle(1,WHITE);
                        puthz(540,145, "请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,145,640,190);
                        bar(190,135,520,175);
                    }
                    
                }
                else ifin[2][1] = 0;
            }    
        }
        else person_restore(190, 135, 520, 175);
        if (MouseX>190&&MouseX<520&&MouseY>195&&MouseY<235)//专业成绩
        {
            if (mouse_press(190, 195, 520, 235) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 195, 520, 235);
            }
            if(mouse_press(190, 195,520, 235)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,195,520, 235);
                log_inputaccount(temp.score,190,200,15,WHITE,2);
                if (*(temp.score) != '\0')
                {
                    if (strlen(temp.score) <= 10)
                    {
                        ifin[2][2] = 3;
                    }
                    else
                    {
                        ifin[2][2] = 0;
                        memset(temp.score,'\0',11);
                        setfillstyle(1,WHITE);
                        puthz(540,200,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,200,640,245);
                        bar(190,195,520,235);
                    }
                }
                else ifin[2][2] = 0;
            }
        }
        else person_restore(190, 195,520, 235);
        if (MouseX>190&&MouseX<520&&MouseY>255&&MouseY<295)//专业课程
        {
            if (mouse_press(190, 255,520, 295) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 255,520, 295);
            }
            if(mouse_press(190, 255,520, 295)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,255,520, 295);
                memset(temp.course,'\0',19);
                j[2] = hz_input(190,265,520,295,temp.course,0,WHITE,BLACK,16);
                if (j[2] > 0)
                {
                    if (j[2]<=18)
                    {
                        ifin[2][3] = 3;
                    }
                    else
                    {
                        j[2] = 0;
                        memset(temp.course,'\0',19);
                        ifin[2][3] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,265,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,265,640,310);
                        bar(190,255,520,295);
                    }
                    if (cheek_legal(temp.course,j[2]))
                    {
                        
                        j[2] = 0;
                        memset(temp.course,'\0',19);
                        ifin[2][3] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,265, "请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,265,640,310);
                        bar(190,255,520,295);
                    }
                    
                }
                else ifin[2][3] = 0;
            }
        }
        else person_restore(190, 255,520, 295);
        if (MouseX>190&&MouseX<520&&MouseY>315&&MouseY<355)//荣誉奖项
        {
            if (mouse_press(190, 315,520, 355) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 315,520, 355);
            }
            if(mouse_press(190, 315,520, 355)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,315,520, 355);
                memset(temp.honor,'\0',151);
                j[3] = hz_input(190,325,495,355,temp.honor,0,WHITE,BLACK,16);
                if (j[3] > 0)
                {
                    if (j[3]<=150)
                    {
                        ifin[2][4] = 3;
                    }
                    else
                    {
                        ifin[2][4] = 0;
                        j[3] = 0;
                        memset(temp.honor,'\0',151);
                        setfillstyle(1,WHITE);
                        puthz(540,325,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,325,640,370);
                        bar(190,315,520,355);
                    }
                    if (cheek_legal(temp.honor,j[3]))
                    {
                        
                        ifin[2][4] = 0;
                        j[3] = 0;
                        memset(temp.honor,'\0',151);
                        setfillstyle(1,WHITE);
                        puthz(540,325, "请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,325,640,370);
                        bar(190,315,520,355);
                    }
                    
                }
                else ifin[2][4] = 0;
            }
        }
        else person_restore(190, 315,520, 355);
        if (MouseX > 150 && MouseX < 250 && MouseY > 370 && MouseY < 420) // 退出框
        {
            if (mouse_press(150,370,250,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(150,370,250,420) == 1)
            {
                clrmous(MouseX,MouseY);
                switch (template_page)
                {
                    case 1 : delay(200);
                             return 6;
                    case 2 : delay(200);
                             return 7;         
                    case 3 : delay(200);
                             return 8;   
                    case 4 : delay(200);
                             return 9;   
                    case 5 : delay(200);
                             return 15;                   
                }
            }
        }
        if (MouseX > 430 && MouseX < 530 && MouseY > 370 && MouseY < 420) // 保存
        {
            if (mouse_press(430,370,530,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(430,370,530,420) == 1)
            {
                *edu = temp;
                education_info_save(edu,psave);
                 
            }
        }
    }
}
/*********************************************
FUNCTION:education_info_save
DESCRIPTION:save the education info
INPUT:edu,psave
RETURN:void
***********************************************/
void education_info_save(EDUCATION *edu,int psave[])
{
    FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\edu.dat", "wb+")) == NULL)
    {
        perror("Can't open education.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
	fwrite(edu, sizeof(EDUCATION), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close edu.dat.");
		delay(3000);
		exit(1);
	} 
    else
    {
        puthz(250,440,"保存成功",32,48,RED);
        delay(1000);
        setfillstyle(1, WHITE);
        bar(250,440,600,480);
        psave[2] = 1; 
    }
}
/*********************************************
FUNCTION:put_education_info
DESCRIPTION:put out the education info
INPUT:x
RETURN:void
***********************************************/
void put_education_info(int x,int ifin[][6])
{
    int len = 0;
    EDUCATION edu;  
	FILE *fp;
	memset(&edu,'\0',sizeof(EDUCATION));
    if ((fp = fopen("C:\\CODE\\database\\edu.dat", "rb+")) == NULL)
    {
        perror("Can't open education.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(EDUCATION);
    fseek(fp,(len-1)*sizeof(EDUCATION),SEEK_SET);
	fread(&edu, sizeof(EDUCATION), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close edu.");
		delay(3000);
		exit(1);
	}
    setcolor(BLACK);
	settextstyle(2, HORIZ_DIR, 6);
	settextjustify(LEFT_TEXT, TOP_TEXT);
    setfillstyle(1,WHITE);
    //bar(0,195+x,100,240+x);
    if (ifin[2][0] > 0)
    {
        bar(0,x,80,15+x);
        puthz(0,x,edu.school,16,18,BLACK);
    }
    if (ifin[2][1] > 0)
    {
        bar(0,25+x,80,40+x);
        puthz(0,25+x,edu.degree,16,18,BLACK); 
    }
    if (ifin[2][2] > 0)
    {
        outtextxy(90,43+x,edu.score);
    }
    if (ifin[2][3] > 0)
    {
        puthz(90,68+x,edu.course,16,18,BLACK);
    }
    if (ifin[2][4] > 0)
    {
        puthz(90,86+x,edu.honor,16,18,BLACK);
    }
}
/*********************************************
FUNCTION:experience_info
DESCRIPTION:put the experience info
INPUT:exp,psave
RETURN:
***********************************************/
int experience_info(EXPERIENCE *exp,int psave[],int ifin[][6],int template_page)
{
    int len = 0;
    EXPERIENCE temp2;
    EXPERIENCE temp;
    FILE *fp;
    int j[3] = {0};
    puthz(200, 15, "工作经历", 48, 64, BLACK);
	setlinestyle(0, 0, 1);
    puthz(65, 75, "公司名称", 24, 32, BLACK);
	person_restore(190, 75, 520, 115);
	puthz(65, 135, "职位名称", 24, 32, BLACK);
	person_restore(190, 135, 520, 175);
	puthz(65, 195, "开始时间", 24, 32, BLACK);
	person_restore(190, 195, 520, 235);
	puthz(65, 255, "结束时间", 24, 32, BLACK);
	person_restore(190, 255, 520, 295);
    puthz(65, 335, "工作事迹", 24, 32, BLACK);
	person_restore(190, 315, 620, 400);
    setfillstyle(1,LIGHTGRAY);
    bar(150,420,250,470);
    puthz(150,425,"返回",24,64,BLACK);
    bar(430,420,530,470);
    puthz(430,425,"保存",24,64,BLACK);
    if (psave[3] == 1)
    {
        if ((fp = fopen("C:\\CODE\\database\\exper.dat", "rb+")) == NULL)
        {
            perror("Can't open exper.dat");
            delay(3000);
            exit(1);
        }
        fseek(fp, 0, SEEK_END);
        len = ftell(fp) / sizeof(EXPERIENCE);
        fseek(fp, (len - 1) * sizeof(EXPERIENCE), SEEK_SET);
        fread(&temp2, sizeof(EXPERIENCE), 1, fp);
        if (fclose(fp) != 0)
        {
            perror("Can't close exper.");
            delay(3000);
            exit(1);
        }
        setcolor(0);
	    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	    settextjustify(LEFT_TEXT, TOP_TEXT);
        if (ifin[3][0] > 0)
        {
            puthz(192,85,temp2.company,16,18,BLACK);
            strcpy(temp.company,temp2.company);
            ifin[3][0] = 5;
        }
        if (ifin[3][1] > 0)
        {
            puthz(192,145,temp2.postition,16,18,BLACK);
            strcpy(temp.postition,temp2.postition);
            ifin[3][1] = 5;
        }
        if (ifin[3][2] > 0)
        {
            outtextxy(195,197,temp2.start);
            strcpy(temp.start,temp2.start);
            ifin[3][2] = 5;
        }
        if (ifin[3][3] > 0)
        {
            outtextxy(195,257,temp2.end);
			strcpy(temp.end,temp2.end);
            ifin[3][3] = 5;
        }
        if (ifin[3][4] > 0)
        {
            puthz(192,325,temp2.deed,16,18,BLACK);
            strcpy(temp.deed,temp2.deed);
            ifin[3][4] = 5;
        }
        
    }
    
	while(1)
	{
        if (MouseS != 0
        &&mouse_press(190, 75, 520, 115) == 0
        &&mouse_press(190, 135, 520, 175) == 0
        &&mouse_press(190, 195, 520, 235) == 0
        &&mouse_press(190, 255,520, 295) == 0
        &&mouse_press(190,315,620,400) == 0
        &&mouse_press(150,420,250,470) == 0
        &&mouse_press(430,420,530,470) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>190&&MouseX<520&&MouseY>75&&MouseY<115)//公司名称
        {
            if (mouse_press(190, 75, 520, 115) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 75, 520, 115);
            }
            if(mouse_press(190, 75, 520, 115)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,75,520, 115);
                memset(temp.company,'\0',49);
                j[0] = hz_input(190,85,495,115,temp.company,0,WHITE,BLACK,16);
                if (j[0] > 0)
                {
                    if (j[0]<=18)
                    {
                        ifin[3][0] = 4;
                    }
                    else
                    {
                        ifin[3][0] = 0;
                        memset(temp.company,'\0',49);
                        j[0] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,85,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(190,75,520,115);
                        bar(540,85,640,130);
                    }
                    if (cheek_legal(temp.company,j[0]))
                    {
                        
                        ifin[3][0] = 0;
                        memset(temp.company, '\0', 49);
                        j[0] = 0;
                        setfillstyle(1, WHITE);
                        puthz(540, 85, "请输入中文", 16, 24, BLACK);
                        delay(1000);
                        bar(190, 75, 520, 115);
                        bar(540, 85, 640, 130);
                    }
                    
                }
                else ifin[3][0] = 0;
            }
        }
        else person_restore(190, 75, 520, 115);
        if (MouseX>190&&MouseX<520&&MouseY>135&&MouseY<175)//职位名称
        {
            if (mouse_press(190, 135, 520, 175) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 135, 520, 175);
            }
            if(mouse_press(190, 135, 520, 175)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,135,520, 175);
                memset(temp.postition,'\0',25);
                j[1] = hz_input(190,145,520,175,temp.postition,0,WHITE,BLACK,16);
                if (j[1] > 0)
                {
                    if (j[1]<=18)
                    {
                        ifin[3][1] = 4;
                    }
                    else
                    {
                        ifin[3][1] = 0;
                        memset(temp.postition,'\0',25);
                        j[1] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,145,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(190,135,520,175);
                        bar(540,145,640,190);
                    }
                    if (cheek_legal(temp.postition,j[1]))
                    {
                        ifin[3][1] = 0;
                        memset(temp.postition,'\0',25);
                        j[1] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540, 145, "请输入中文", 16, 24, BLACK);
                        delay(1000);
                        bar(190,135,520,175);
                        bar(540,145,640,190);
                    }
                }
                else ifin[3][1] = 0;
            }
        }
        else person_restore(190, 135, 520, 175);
        if (MouseX>190&&MouseX<520&&MouseY>195&&MouseY<235)//开始时间
        {
            if (mouse_press(190, 195, 520, 235) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 195, 520, 235);
            }
            if(mouse_press(190, 195,520, 235)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,195,520, 235);
                log_inputaccount(temp.start,190,200,10,WHITE,2);
                if (*(temp.start) >= '0'&&*(temp.start) <= '9')
                {
                    if (strlen(temp.start)<=10)
                    {
                        ifin[3][2] = 4;
                    }
                }
                else if(*(temp.start)<'0'&&*(temp.start)>'9'&&*(temp.start)!=' '&&*(temp.start)!='\n')
                {
                    ifin[3][2] = 0;
                    memset(temp.start,'\0',11);
                    setfillstyle(1,WHITE);
                    puthz(540,200,"不合法日期",16,24,BLACK);
                    delay(1000);
                    bar(190,195,520,235);
                    bar(540,200,640,245);
                }
            }
        }
        else person_restore(190, 195,520, 235);
        if (MouseX>190&&MouseX<520&&MouseY>255&&MouseY<295)//结束时间
        {
            if (mouse_press(190, 255,520, 295) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 255,520, 295);
            }
            if(mouse_press(190, 255,520, 295)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,255,520, 295);
                log_inputaccount(temp.end,190,260,10,WHITE,2);
                if (*(temp.end) >= '0'&&*(temp.end) <= '9')
                {
                     if (strlen(temp.end)<=10)
                    {
                        ifin[3][3] = 4;
                    }

                }
                else if(*(temp.end)<'0'&&*(temp.end)>'9'&&*(temp.end)!=' '&&*(temp.end)!='\n')
                {
                    ifin[3][3] = 0;
                    memset(temp.end,'\0',11);
                    setfillstyle(1,WHITE);
                    puthz(540,260,"不合法日期",16,24,BLACK);
                    delay(1000);
                    bar(190,255,520,295);
                    bar(540,260,640,305);
                }
            }
        }
        else person_restore(190, 255,520, 295);
        if (MouseX>190&&MouseX<620&&MouseY>315&&MouseY<400)//工作事迹
        {
            if (mouse_press(190, 315,620, 400) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 315,620, 400);
            }
            if(mouse_press(190, 315,620, 400)== 1)
            {
				clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,315,620, 400);
                memset(temp.deed,'\0',151);
                j[2] = hz_input(190,325,575,400,temp.deed,0,WHITE,BLACK,16);
                if (j[2] > 0)
                {
                    if (j[2]<=150)
                    {
                        ifin[3][4] = 4;
                    }
                    else
                    {
                        ifin[3][4] = 0;
                        j[2] = 0;
                        memset(temp.deed,'\0',151);
                        setfillstyle(1,WHITE);
                        puthz(70,370,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(190,315,620,400);
                        bar(70,370,180,410);
                    }
                    if (cheek_legal(temp.deed,j[2]))
                    {
                        ifin[3][4] = 0;
                        memset(temp.deed,'\0',151);
                        j[1] = 0;
                        setfillstyle(1,WHITE);
                        puthz(70,370, "请输入中文", 16, 24, BLACK);
                        delay(1000);
                        bar(190,315,620,400);
                        bar(70,370,180,410);
                    }
                }
                else ifin[3][4] = 0;
            }
        }
        else person_restore(190, 315,620, 400);
        if (MouseX > 150 && MouseX < 250 && MouseY > 420 && MouseY < 470) // 退出框
        {
            if (mouse_press(150,420,250,470) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(150,420,250,470) == 1)
            {
                clrmous(MouseX,MouseY);
                switch (template_page)
                {
                    case 1 : delay(200);
                             return 6;
                    case 2 : delay(200);
                             return 7;         
                    case 3 : delay(200);
                             return 8;   
                    case 4 : delay(200);
                             return 9;   
                    case 5 : delay(200);
                             return 15;                   
                }
            }
        }
        if (MouseX > 430 && MouseX < 530 && MouseY > 420 && MouseY < 470) // 保存
        {
            if (mouse_press(430,420,530,470) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(430,420,530,470) == 1)
            {
                *exp = temp;
                experience_info_save(exp,psave);
                 
            }
        }
    }
}
/*********************************************
FUNCTION:experience_info_save
DESCRIPTION:save the experience info
INPUT:exp,psave
RETURN:void
***********************************************/
void experience_info_save(EXPERIENCE *exp,int psave[])
{
    FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\exper.dat", "rb+")) == NULL)
    {
        perror("Can't open exper.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
	fwrite(exp, sizeof(EXPERIENCE), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close exper.dat.");
		delay(3000);
		exit(1);
	} 
    else
    {
        puthz(0,0,"保存成功",32,48,RED);
        delay(1000);
        setfillstyle(1, WHITE);
        bar(0,0,200,40);
        psave[3] = 1; 
    }
}
/*********************************************
FUNCTION:put_experience_info
DESCRIPTION:put out the experience info
INPUT:x
RETURN:void
***********************************************/
void put_experience_info(int x,int ifin[][6])
{
    int len = 0;
    EXPERIENCE exp;  
	FILE *fp;
	memset(&exp,'\0',sizeof(EXPERIENCE));
    if ((fp = fopen("C:\\CODE\\database\\exper.dat", "rb+")) == NULL)
    {
        perror("Can't open exper.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(EXPERIENCE);
    fseek(fp,(len-1)*sizeof(EXPERIENCE),SEEK_SET);
	fread(&exp, sizeof(EXPERIENCE), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close exper.");
		delay(3000);
		exit(1);
	}
    setcolor(BLACK);
	settextstyle(2, HORIZ_DIR, 5);
	settextjustify(LEFT_TEXT, TOP_TEXT);
    setfillstyle(1,WHITE);
    //bar(0,346+x,90,390+x);
    if (ifin[3][0] > 0)
    {
        bar(0,x,80,24+x);
        puthz(0,x,exp.company,16,18,BLACK);
    }
    if (ifin[3][1] > 0)
    {
        bar(0,25+x,80,44+x);
        puthz(0,25+x,exp.postition,16,18,BLACK);     
    }
    if (ifin[3][2] > 0)
    {
       bar(400,25+x,470,44+x);
       outtextxy(400,25+x,exp.start);
    }
    if (ifin[3][3] > 0)
    {
        bar(500,25+x,570,44+x);
        outtextxy(497,25+x,exp.end);
    }
    if (ifin[3][4] > 0)
    {
         puthz(0,47+x,exp.deed,16,18,BLACK);
    }
}
/*********************************************
FUNCTION:skill_info
DESCRIPTION:put the commment info
INPUT:ski,psave
RETURN:
***********************************************/
int skill_info(SKILL *ski,int psave[],int ifin[][6],int template_page)
{
    int len = 0;
    SKILL temp2;
    SKILL temp;
	int pos = 0;
    int j[4] = {0};
    FILE *fp;
    puthz(200, 15, "技能证书", 48, 64, BLACK);
	setlinestyle(0, 0, 1);
    puthz(70, 75, "技能", 24, 64, BLACK);
	person_restore(190, 75, 520, 115);
    home_draw(535,75,575,115,BLACK);//增加
    line(555,80,555,110);
    line(540,95,570,95);
    setfillstyle(1,LIGHTGRAY);
    bar(150,370,250,420);
    puthz(150,375,"返回",24,64,BLACK);
    bar(430,370,530,420);
    puthz(430,375,"保存",24,64,BLACK);
    if (psave[4] == 1)
    {
        if ((fp = fopen("C:\\CODE\\database\\skill.dat", "rb+")) == NULL)
        {
            perror("Can't open skill.dat");
            delay(3000);
            exit(1);
        }
        fseek(fp, 0, SEEK_END);
        len = ftell(fp) / sizeof(SKILL);
        fseek(fp, (len - 1) * sizeof(SKILL), SEEK_SET);
        fread(&temp2, sizeof(SKILL), 1, fp);
        if (fclose(fp) != 0)
        {
            perror("Can't close ski.");
            delay(3000);
            exit(1);
        }
        if (ifin[4][0] > 0)
        {
            puthz(192,85,temp2.skill1,16,18,BLACK);
            strcpy(temp.skill1,temp2.skill1);
            ifin[4][0] = 6;
        }
        if (ifin[4][1] > 0)
        {
            puthz(192,145,temp2.skill2,16,18,BLACK);
            strcpy(temp.skill2,temp2.skill2);
            ifin[4][1] = 6;
            pos = 30;
            person_restore(190, 75 + 2 * pos, 520, 115 + 2 * pos);
            puthz(70, 75 + 2 * pos, "技能", 24, 64, BLACK);
        }
        if (ifin[4][2] > 0)
        {
            puthz(192,205,temp2.skill3,16,18,BLACK);
            strcpy(temp.skill3,temp2.skill3);
            ifin[4][2] = 6;
            pos = 60;
            person_restore(190, 75 + 2 * pos, 520, 115 + 2 * pos);
            puthz(70, 75 + 2 * pos, "技能", 24, 64, BLACK);
        }
        if (ifin[4][3] > 0)
        {
            puthz(192,265,temp2.skill4,16,18,BLACK);
            strcpy(temp.skill4,temp2.skill4);
            ifin[4][3] = 6;
            pos = 90;
            person_restore(190, 75 + 2 * pos, 520, 115 + 2 * pos);
            puthz(70, 75 + 2 * pos, "技能", 24, 64, BLACK);
        }
    }
	while(1)
	{
        if (MouseS != 0
        &&mouse_press(540,80,570,110) == 0
        &&mouse_press(190, 75, 520, 115) == 0
        &&mouse_press(190, 135, 520, 175) == 0
        &&mouse_press(190, 195, 520, 235) == 0
        &&mouse_press(190, 255,520, 295) == 0 
        &&mouse_press(150,370,250,420) == 0
        &&mouse_press(430,370,530,420) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>540&&MouseX<570&&MouseY>80&&MouseY<110)//增加
        {
            if (mouse_press(540,80,570,110) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(540,80,570,110,RED);
				setfillstyle(1,BLACK);
                bar(540,50,575,70);
                puthz(540,50,"增加",16,18,WHITE);
            }
            if (mouse_press(540,80,570,110) == 1)
            {
                if (pos < 90)
                {
                    pos = pos + 30;
                    delay(200);
                    person_restore(190, 75 + 2 * pos, 520, 115 + 2 * pos);
                    puthz(70, 75 + 2 * pos, "技能", 24, 64, BLACK);
                }
                else 
                {
                    puthz(250, 440, "已达上限", 32, 48, RED);
                    delay(1000);
                    setfillstyle(1, WHITE);
                    bar(250, 440, 600, 480);
                }
            }    
        }
        else 
        {
            setfillstyle(1,WHITE);
            bar(540,50,575,70);
            home_draw(540,80,570,110,WHITE);
        }           
        if (MouseX>190&&MouseX<520&&MouseY>75&&MouseY<115)//技能1
        {
            if (mouse_press(190, 75, 520, 115) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 75, 520, 115);
            }
            if(mouse_press(190, 75, 520, 115)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,75,520, 115);
                memset(temp.skill1,'\0',53);
                j[0] = hz_input(190,85,495,115,temp.skill1,0,WHITE,BLACK,16);
                if (j[0] > 0)
                {
                    if (j[0]<=52)
                    {
                        ifin[4][0] = 5;
                    }
                    else
                    {
                        ifin[4][0] = 0;
                        memset(temp.skill1,'\0',53);
                        j[0] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,85,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(540,85,640,130);
                        bar(190,75,520,115);
                    }
                    if (cheek_legal(temp.skill1,j[0]))
                    {
                        ifin[4][0] = 0;
                        memset(temp.skill1,'\0',53);
                        j[0] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,28,"请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,28,640,73);
                        bar(190,75,520,115);
                    }     
                }
                else ifin[4][0] = 0;
            }
        }
        else person_restore(190, 75, 520, 115);

        if (pos > 0)
        {
            if (MouseX > 190 && MouseX < 520 && MouseY > 135 && MouseY < 175) // 技能2
            {
                if (mouse_press(190, 135, 520, 175) == 2)
                {
                    MouseS = 2;
                    newmouse(&MouseX, &MouseY, &press);
                    person_change(190, 135, 520, 175);
                }
                if (mouse_press(190, 135, 520, 175) == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1, WHITE);
                    bar(190,135,520, 175);
                    memset(temp.skill2,'\0',53);
                    j[1] = hz_input(190,145,495,175,temp.skill2,0,WHITE,BLACK,16);
                    if (j[1] > 0)
                    {
                        if (j[1] <= 52)
                        {
                            ifin[4][1] = 5;
                        }
                        else
                        {
                            ifin[4][1] = 0;
                            memset(temp.skill2, '\0', 53);
                            j[1] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 145, "超出限制", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 145, 640, 190);
                            bar(190, 135, 520, 175);
                        }
                        if (cheek_legal(temp.skill2,j[1]))
                        {
                            
                            ifin[4][1] = 0;
                            memset(temp.skill2, '\0', 53);
                            j[1] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 145, "请输入中文", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 145, 640, 190);
                            bar(190, 135, 520, 175);
                        }
                        
                    }
                    else ifin[4][1] = 0;
                }
            }
            else person_restore(190, 135, 520, 175);
        }
        if (pos >30)
        {
            if (MouseX > 190 && MouseX < 520 && MouseY > 195 && MouseY < 235) // 技能3
            {
                if (mouse_press(190, 195, 520, 235) == 2)
                {
                    MouseS = 2;
                    newmouse(&MouseX, &MouseY, &press);
                    person_change(190, 195, 520, 235);
                }
                if (mouse_press(190, 195, 520, 235) == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1, WHITE);
                    bar(190,195,520, 235);
                    memset(temp.skill3,'\0',53);
                    j[2] = hz_input(190,205,495,235,temp.skill3,0,WHITE,BLACK,16);
                    if (j[2] > 0)
                    {
                        if (j[2] <= 52)
                        {
                            ifin[4][2] = 5;
                        }
                        else
                        {
                            ifin[4][2] = 0;
                            memset(temp.skill3, '\0', 53);
                            j[2] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 205, "超出限制", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 205, 640, 250);
                            bar(190, 195, 520, 235);
                        }
                        if (cheek_legal(temp.skill3,j[2]))
                        {
                            
                            ifin[4][2] = 0;
                            memset(temp.skill3, '\0', 53);
                            j[2] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 205, "请输入中文", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 205, 640, 250);
                            bar(190, 195, 520, 235);
                        }
                        
                    }
                    else ifin[4][2] = 0;
                }
            }
            else person_restore(190, 195,520, 235);
        }
        if (pos > 60)
        {
            if (MouseX > 190 && MouseX < 520 && MouseY > 255 && MouseY < 295) // 技能4
            {
                if (mouse_press(190, 255, 520, 295) == 2)
                {
                    MouseS = 2;
                    newmouse(&MouseX, &MouseY, &press);
                    person_change(190, 255, 520, 295);
                }
                if (mouse_press(190, 255, 520, 295) == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1, WHITE);
                    bar(190,255,520, 295);
                    memset(temp.skill4,'\0',53);
                    j[3] = hz_input(190,265,495,295,temp.skill4,0,WHITE,BLACK,16);
                    if (j[3] > 0)
                    {
                        if (j[3] <= 52)
                        {
                            ifin[4][3] = 5;
                        }
                        else
                        {
                            ifin[4][3] = 0;
                            memset(temp.skill4, '\0', 53);
                            j[3] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 265, "超出限制", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 265, 640, 310);
                            bar(190, 255, 520, 295);
                        }
                        if (cheek_legal(temp.skill4,j[3]))
                        {
                            
                            ifin[4][3] = 0;
                            memset(temp.skill4, '\0', 53);
                            j[3] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 265, "请输入中文", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 265, 640, 310);
                            bar(190, 255, 520, 295);
                        }
                        
                    }
                    else ifin[4][3] = 0;
                }
            }
            else person_restore(190, 255,520, 295);
        }       
        if (MouseX > 150 && MouseX < 250 && MouseY > 370 && MouseY < 420) // 退出框
        {
            if (mouse_press(150,370,250,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(150,370,250,420) == 1)
            {
                clrmous(MouseX,MouseY);
                switch (template_page)
                {
                    case 1 : delay(200);
                             return 6;
                    case 2 : delay(200);
                             return 7;         
                    case 3 : delay(200);
                             return 8;   
                    case 4 : delay(200);
                             return 9;   
                    case 5 : delay(200);
                             return 15;                   
                }
            }
        }
        if (MouseX > 430 && MouseX < 530 && MouseY > 370 && MouseY < 420) // 保存
        {
            if (mouse_press(430,370,530,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(430,370,530,420) == 1)
            {
                *ski = temp;
                 skill_info_save(ski,psave);          
            }
        }
    }
}
/*********************************************
FUNCTION:skill_info_save
DESCRIPTION:save the skill info
INPUT:ski,psave
RETURN:void
***********************************************/
void skill_info_save(SKILL *ski,int psave[])
{
    FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\skill.dat", "rb+")) == NULL)
    {
        perror("Can't open ski.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
	fwrite(ski, sizeof(SKILL), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close skill.dat.");
		delay(3000);
		exit(1);
	} 
    else
    {
        puthz(250,440,"保存成功",32,48,RED);
        delay(1000);
        setfillstyle(1, WHITE);
        bar(250,440,600,480);
        psave[4] = 1; 
    }
}
/*********************************************
FUNCTION:put_skill_info
DESCRIPTION:put out the skill info
INPUT:x
RETURN:void
***********************************************/
void put_skill_info(int x,int ifin[][6])
{
    int len = 0;
    SKILL ski;  
	FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\skill.dat", "rb+")) == NULL)
    {
        perror("Can't open skill.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(SKILL);
    fseek(fp,(len-1)*sizeof(SKILL),SEEK_SET);
	fread(&ski, sizeof(SKILL), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close ski.");
		delay(3000);
		exit(1);
	}
   setlinestyle(0,0,1);
   if (ifin[4][0] > 0)
   {
       line(0, 5 + x, 10, 5 + x);
       puthz(15,  x, ski.skill1, 16, 18, BLACK);
   }
   if (ifin[4][1] > 0)
   {
        line(0,20+x,10,20+x);
		puthz(15,15+x,ski.skill2,16,18,BLACK);
   }
   if (ifin[4][2] > 0)
   {
        line(0,35+x,10,35+x);
        puthz(15,30+x,ski.skill3,16,18,BLACK);
   }
   if (ifin[4][3] > 0)
   {
        line(0,50+x,10,50+x);
        puthz(15,45+x,ski.skill4,16,18,BLACK);
   }
}
/*********************************************
FUNCTION:commment_info
DESCRIPTION:put the commment info
INPUT:com,psave,ifin
RETURN:
***********************************************/
int comment_info(COMMENT *com,int psave[],int ifin[][6],int template_page)
{
    int len = 0;
    COMMENT temp2;
    COMMENT temp;
	int pos = 0;
    int j[4] = {0};
    FILE *fp;
    puthz(200, 15, "自我评价", 48, 64, BLACK);
	setlinestyle(0, 0, 1);
    puthz(70, 75, "评价", 24, 64, BLACK);
	person_restore(190, 75, 520, 115);
    home_draw(535,75,575,115,BLACK);//增加
    line(555,80,555,110);
    line(540,95,570,95);
    setfillstyle(1,LIGHTGRAY);
    bar(150,370,250,420);
    puthz(150,375,"返回",24,64,BLACK);
    bar(430,370,530,420);
    puthz(430,375,"保存",24,64,BLACK);
    if (psave[5] == 1)
    {
        if ((fp = fopen("C:\\CODE\\database\\comment.dat", "rb+")) == NULL)
        {
            perror("Can't open comment.dat");
            delay(3000);
            exit(1);
        }
        fseek(fp, 0, SEEK_END);
        len = ftell(fp) / sizeof(COMMENT);
        fseek(fp, (len - 1) * sizeof(COMMENT), SEEK_SET);
        fread(&temp2, sizeof(COMMENT), 1, fp);
        if (fclose(fp) != 0)
        {
            perror("Can't close comment.");
            delay(3000);
            exit(1);
        }
        if (ifin[5][0] > 0)
        {
            puthz(192,85,temp2.com1,16,18,BLACK);
            strcpy(temp.com1,temp2.com1);
            ifin[5][0] = 7;
        }
        if (ifin[5][1] > 0)
        {
            puthz(192,145,temp2.com2,16,18,BLACK);
            strcpy(temp.com2,temp2.com2);
            ifin[5][1] = 7;
            pos = 30;
            person_restore(190, 75 + 2 * pos, 520, 115 + 2 * pos);
            puthz(70, 75 + 2 * pos, "评价", 24, 64, BLACK);
        }
        if (ifin[5][2] > 0)
        {
            puthz(192,205,temp2.com3,16,18,BLACK);
            strcpy(temp.com3,temp2.com3);
            ifin[5][2] = 7;
            pos = 60;
            person_restore(190, 75 + 2 * pos, 520, 115 + 2 * pos);
            puthz(70, 75 + 2 * pos, "评价", 24, 64, BLACK);
        }
        if (ifin[5][3] > 0)
        {
            puthz(192,145,temp2.com4,16,18,BLACK);
            strcpy(temp.com4,temp2.com4);
            ifin[5][3] = 7;
            pos = 90;
            person_restore(190, 75 + 2 * pos, 520, 115 + 2 * pos);
            puthz(70, 75 + 2 * pos, "评价", 24, 64, BLACK);
        }
    }
    
	while(1)
	{
        if (MouseS != 0
        &&mouse_press(540,80,570,110) == 0
        &&mouse_press(190, 75, 520, 115) == 0
        &&mouse_press(190, 135, 520, 175) == 0
        &&mouse_press(190, 195, 520, 235) == 0
        &&mouse_press(190, 255,520, 295) == 0 
        &&mouse_press(150,370,250,420) == 0
        &&mouse_press(430,370,530,420) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>540&&MouseX<570&&MouseY>80&&MouseY<110)//增加
        {
            if (mouse_press(540,80,570,110) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(540,80,570,110,RED);
                setfillstyle(1,BLACK);
                bar(540,50,575,70);
                puthz(540,50,"增加",16,18,WHITE);
            }
            if (mouse_press(540,80,570,110) == 1)
            {
                if (pos < 90)
                {
                    pos = pos + 30;
                    delay(200);
                    person_restore(190, 75 + 2 * pos, 520, 115 + 2 * pos);
                    puthz(70, 75 + 2 * pos, "评价", 24, 64, BLACK);
                }
                else 
                {
                    puthz(250, 440, "已达上限", 32, 48, RED);
                    delay(1000);
                    setfillstyle(1, WHITE);
                    bar(250, 440, 600, 480);
                }
            }    
        }
        else 
        {
            setfillstyle(1,WHITE);
            bar(540,50,575,70);
            home_draw(540,80,570,110,WHITE);
        }    
        if (MouseX>190&&MouseX<520&&MouseY>75&&MouseY<115)//评价1
        {
            if (mouse_press(190, 75, 520, 115) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 75, 520, 115);
            }
            if(mouse_press(190, 75, 520, 115)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,75,520, 115);
                memset(temp.com1,'\0',211);
                j[0] = hz_input(190,85,495,115,temp.com1,0,WHITE,BLACK,16);
                if (j[0] > 0)
                {
                    if (j[0] <= 210)
                    {
                        ifin[5][0] = 6;
                    }
                    else
                    {
                        ifin[5][0] = 0;
                        memset(temp.com1, '\0', 211);
                        j[0] = 0;
                        setfillstyle(1, WHITE);
                        puthz(540, 85, "超出限制", 16, 24, BLACK);
                        delay(1000);
                        bar(540, 85, 640, 130);
                        bar(190, 75, 520, 115);
                    }
                    if (cheek_legal(temp.com1,j[0]))
                    {
                        
                        ifin[5][0] = 0;
                        memset(temp.com1, '\0', 211);
                        j[0] = 0;
                        setfillstyle(1, WHITE);
                        puthz(540,28,"请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,28,640,73);
                        bar(190,75,520,115);
                    }
                    
                }
                else ifin[5][0] = 0;
            }
        }
        else person_restore(190, 75, 520, 115);

        if (pos > 0)
        {
            if (MouseX > 190 && MouseX < 520 && MouseY > 135 && MouseY < 175) //评价2
            {
                if (mouse_press(190, 135, 520, 175) == 2)
                {
                    MouseS = 2;
                    newmouse(&MouseX, &MouseY, &press);
                    person_change(190, 135, 520, 175);
                }
                if (mouse_press(190, 135, 520, 175) == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1, WHITE);
                    bar(190,135,520, 175);
                    memset(temp.com2,'\0',211);
                    j[1] = hz_input(190,145,495,175,temp.com2,0,WHITE,BLACK,16);
                    if (j[1] > 0)
                    {
                        if (j[1] <= 210)
                        {
                            ifin[5][1] = 6;
                        }
                        else
                        {
                            ifin[5][1] = 0;
                            memset(temp.com2, '\0', 211);
                            j[1] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 145, "超出限制", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 145, 640, 190);
                            bar(190, 135, 520, 175);
                        }
                        if (cheek_legal(temp.com2,j[1]))
                        {
                            
                            ifin[5][1] = 0;
                            memset(temp.com2, '\0', 211);
                            j[1] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 145, "请输入中文", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 145, 640, 190);
                            bar(190, 135, 520, 175);
                        }
                        
                    }
                    else ifin[5][1] = 0;
                }
            }
            else person_restore(190, 135, 520, 175);
        }
        if (pos >30)
        {
            if (MouseX > 190 && MouseX < 520 && MouseY > 195 && MouseY < 235) //评价3
            {
                if (mouse_press(190, 195, 520, 235) == 2)
                {
                    MouseS = 2;
                    newmouse(&MouseX, &MouseY, &press);
                    person_change(190, 195, 520, 235);
                }
                if (mouse_press(190, 195, 520, 235) == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1, WHITE);
                    bar(190,195,520, 235);
                    memset(temp.com3,'\0',211);
                    j[2] = hz_input(190,205,495,235,temp.com3,0,WHITE,BLACK,16);
                    if (j[2] > 0)
                    {
                        if (j[2] <= 210)
                        {
                            ifin[5][2] = 6;
                        }
                        else
                        {
                            ifin[5][2] = 0;
                            memset(temp.com3, '\0', 211);
                            j[2] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 205, "超出限制", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 205, 640, 250);
                            bar(190, 195, 520, 235);
                        }
                        if (cheek_legal(temp.com3,j[2]))
                        {
                            
                            ifin[5][2] = 0;
                            memset(temp.com3, '\0', 211);
                            j[2] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 205, "请输入中文", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 205, 640, 250);
                            bar(190, 195, 520, 235);
                        }
                        
                    }
                    else ifin[5][2] = 0;
                }
            }
            else person_restore(190, 195,520, 235);
        }
        if (pos > 60)
        {
            if (MouseX > 190 && MouseX < 520 && MouseY > 255 && MouseY < 295) // 评价4
            {
                if (mouse_press(190, 255, 520, 295) == 2)
                {
                    MouseS = 2;
                    newmouse(&MouseX, &MouseY, &press);
                    person_change(190, 255, 520, 295);
                }
                if (mouse_press(190, 255, 520, 295) == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1, WHITE);
                    bar(190,255,520, 295);
                    memset(temp.com4,'\0',211);
                    j[3] = hz_input(190,265,495,295,temp.com4,0,WHITE,BLACK,16);
                    if (j[3] > 0)
                    {
                        if (j[3] <= 210)
                        {
                            ifin[5][3] = 6;
                        }
                        else
                        {
                            ifin[5][3] = 0;
                            memset(temp.com4, '\0', 211);
                            j[3] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 265, "超出限制", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 265, 640, 310);
                            bar(190, 255, 520, 295);
                        }
                        if (cheek_legal(temp.com4,j[3]))
                        {
                            
                            ifin[5][3] = 0;
                            memset(temp.com4, '\0', 211);
                            j[3] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 265, "请输入中文", 16, 24, BLACK);
                            delay(1000);
                            bar(540, 265, 640, 310);
                            bar(190, 255, 520, 295);
                        }
                        
                    }
                    else ifin[5][3] = 0;
                }
            }
            else person_restore(190, 255,520, 295);
        }       
        if (MouseX > 150 && MouseX < 250 && MouseY > 370 && MouseY < 420) // 退出框
        {
            if (mouse_press(150,370,250,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(150,370,250,420) == 1)
            {
                clrmous(MouseX,MouseY);
                switch (template_page)
                {
                    case 1 : delay(200);
                             return 6;
                    case 2 : delay(200);
                             return 7;         
                    case 3 : delay(200);
                             return 8;   
                    case 4 : delay(200);
                             return 9;   
                    case 5 : delay(200);
                             return 15;               
                }
            }
        }
        if (MouseX > 430 && MouseX < 530 && MouseY > 370 && MouseY < 420) // 保存
        {
            if (mouse_press(430,370,530,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(430,370,530,420) == 1)
            {
                *com = temp;
                comment_info_save(com,psave);          
            }
        }
    }
}
/*********************************************
FUNCTION:comment_info_save
DESCRIPTION:save the comment info
INPUT:com,psave
RETURN:void
***********************************************/
void comment_info_save(COMMENT *com,int psave[])
{
    FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\comment.dat", "rb+")) == NULL)
    {
        perror("Can't open commment.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
	fwrite(com, sizeof(COMMENT), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close comment.dat.");
		delay(3000);
		exit(1);
	} 
    else
    {
        puthz(250,440,"保存成功",32,48,RED);
        delay(1000);
        setfillstyle(1, WHITE);
        bar(250,440,600,480);
        psave[5] = 1; 
    }
}
/*********************************************
FUNCTION:put_comment_info
DESCRIPTION:put out the comment info
INPUT:x,ifin
RETURN:void
***********************************************/
void put_comment_info(int x,int ifin[][6])
{
    int len = 0;
    COMMENT com;  
	FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\comment.dat", "rb+")) == NULL)
    {
        perror("Can't open comment.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(COMMENT);
    fseek(fp,(len-1)*sizeof(COMMENT),SEEK_SET);
	fread(&com, sizeof(COMMENT), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close comment.");
		delay(3000);
		exit(1);
	}
   setlinestyle(0,0,3);
   if (ifin[5][0] > 0)
   {
       line(0, 5 + x, 10, 5 + x);
       puthz(15, x, com.com1, 16, 18, BLACK);
   }
   if (ifin[5][1] > 0)
   {
        line(0,40+x,10,40+x);
		puthz(15,35+x,com.com2,16,18,BLACK);
   }
   if (ifin[5][2] > 0)
   {
        line(0,75+x,10,75+x);
        puthz(15,70+x,com.com3,16,18,BLACK);
   }
   if (ifin[5][3] > 0)
   {
        line(0,110+x,10,110+x);
        puthz(15,105+x,com.com4,16,18,BLACK);
   }
}
/*********************************************
FUNCTION:undergo_info
DESCRIPTION:put the undergo info
INPUT:und,psave,ifin
RETURN:
***********************************************/
int undergo_info(UNDERGO *und,int psave[],int ifin[][6],int template_page)
{
    int len = 0;
    UNDERGO temp;
    UNDERGO temp2; 
	int pos = 0;
    int j[4] = {0};
    FILE *fp;
    puthz(200, 15, "在校经历", 48, 64, BLACK);
	setlinestyle(0, 0, 1);
    puthz(70, 75, "社团", 24, 64, BLACK);
	person_restore(190, 75, 520, 115);
    puthz(70,155,"经历",24,64,BLACK);
    person_restore(190,135,620,215);
    home_draw(535,75,575,115,BLACK);//增加
    line(555,80,555,110);
    line(540,95,570,95);
    setfillstyle(1,LIGHTGRAY);
    bar(150,385,250,435);
    puthz(150,390,"返回",24,64,BLACK);
    bar(430,385,530,435);
    puthz(430,390,"保存",24,64,BLACK);
    if (psave[6] == 1)
    {
        //printf("%d,%d,%d,%d",ifin[6][0],ifin[6][1],ifin[6][2],ifin[6][3]);
        if ((fp = fopen("C:\\CODE\\database\\undergo.dat", "rb+")) == NULL)
        {
            perror("Can't open undergo.dat");
            delay(3000);
            exit(1);
        }
        fseek(fp, 0, SEEK_END);
        len = ftell(fp) / sizeof(UNDERGO);
        fseek(fp, (len - 1) * sizeof(UNDERGO), SEEK_SET);
        fread(&temp2, sizeof(UNDERGO), 1, fp);
        if (fclose(fp) != 0)
        {
            perror("Can't close undergo.");
            delay(3000);
            exit(1);
        }
        if (ifin[6][0] > 0)
        {
            puthz(192,85,temp2.club1,16,18,BLACK);
            strcpy(temp.club1,temp2.club1);
            ifin[6][0] = 8;
        }
        if (ifin[6][1] > 0)
        {
            puthz(192,145,temp2.detail1,16,18,BLACK);
            strcpy(temp.detail1,temp2.detail1);
            ifin[6][1] = 8;
        }
        if (ifin[6][2] >0)
        {
            
            puthz(192,245,temp2.club2,16,18,BLACK);
            strcpy(temp.club2,temp2.club2);
            ifin[6][2] = 8;
            pos = 1;
            puthz(70, 235, "社团", 24, 64, BLACK);
            person_restore(190, 235, 520, 275);
            puthz(70,315,"经历",24,64,BLACK);
            person_restore(190,295,620,375);
            
        }
        if (ifin[6][3] >0)
        {
            puthz(192,305,temp2.detail2,16,18,BLACK);
            strcpy(temp.detail2,temp2.detail2);
            ifin[6][3] = 8;
            pos = 1;
            puthz(70, 235, "社团", 24, 64, BLACK);
            person_restore(190, 235, 520, 275);
            puthz(70,315,"经历",24,64,BLACK);
            person_restore(190,295,620,375);
        }
        
    }
    
	while(1)
	{
        if (MouseS != 0
        &&mouse_press(540,80,570,110) == 0
        &&mouse_press(190, 75, 520, 115) == 0
        &&mouse_press(190, 135, 620, 215) == 0
        &&mouse_press(190, 235, 520, 275) == 0
        &&mouse_press(190, 295,620, 375) == 0 
        &&mouse_press(150,385,250,435) == 0
        &&mouse_press(430,385,530,435) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>540&&MouseX<570&&MouseY>80&&MouseY<110)//增加
        {
            if (mouse_press(540,80,570,110) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX,&MouseY,&press);
                home_draw(540,80,570,110,RED);
                setfillstyle(1,BLACK);
                bar(540,50,575,70);
                puthz(540,50,"增加",16,18,WHITE);
            }
            if (mouse_press(540,80,570,110) == 1)
            {
                if (pos == 0)
                {
                    pos = 1;
                    delay(200);
                    puthz(70, 235, "社团", 24, 64, BLACK);
                    person_restore(190, 235, 520, 275);
                    puthz(70,315,"经历",24,64,BLACK);
                    person_restore(190,295,620,375);
                }
                else 
                {
                    puthz(250, 440, "已达上限", 32, 48, RED);
                    delay(1000);
                    setfillstyle(1, WHITE);
                    bar(250, 440, 600, 480);
                }
            }    
        }
        else 
        {
            home_draw(540,80,570,110,WHITE);
            setfillstyle(1,WHITE);
            bar(540,50,575,70);
        }    
        if (MouseX>190&&MouseX<520&&MouseY>75&&MouseY<115)//社团1
        {
            if (mouse_press(190, 75, 520, 115) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 75, 520, 115);
            }
            if(mouse_press(190, 75, 520, 115)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,75,520, 115);
                memset(temp.club1,'\0',21);
                j[0] = hz_input(190,85,495,115,temp.club1,0,WHITE,BLACK,16);
                if (j[0] > 0)
                {
                    if (j[0]<=20)
                    {
                        ifin[6][0] = 7;
                    }
                    else
                    {
                        ifin[6][0] = 0;
                        memset(temp.club1,'\0',21);
                        j[0] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,85,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(190,75,520,115);
                        bar(540,85,640,130);
                    }
                    if (cheek_legal(temp.club1,j[0]))
                    {
                        
                        ifin[6][0] = 0;
                        memset(temp.club1,'\0',21);
                        j[0] = 0;
                        setfillstyle(1,WHITE);
                        puthz(540,28,"请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(540,28,640,73);
                        bar(190,75,520,115);
                    }
                    
                }
                else ifin[6][0] = 0;
            }
        }
        else person_restore(190, 75, 520, 115);
        if (MouseX > 190 && MouseX < 620 && MouseY > 135 && MouseY < 215) //经历1
        {
             if (mouse_press(190, 135, 620, 215) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX, &MouseY, &press);
                person_change(190, 135, 620, 215);
            }
            if (mouse_press(190, 135, 620, 215) == 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,135,620, 215);
                memset(temp.detail1,'\0',71);
                j[1] = hz_input(190,145,575,215,temp.detail1,0,WHITE,BLACK,16);
                if (j[1] > 0) 
                {
                    if (j[1]<=70)
                    {
                        ifin[6][1] = 7;
                    }
                    else
                    {
                        ifin[6][1] = 0;
                        memset(temp.detail1,'\0',71);
                        j[1] = 0;
                        setfillstyle(1,WHITE);
                        puthz(70,180,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(190,135,620,215);
                        bar(70,180,180,230);
                    }
                    if (cheek_legal(temp.detail1,j[1]))
                    {
                        
                        ifin[6][1] = 0;
                        memset(temp.detail1,'\0',71);
                        j[1] = 0;
                        setfillstyle(1,WHITE);
                        puthz(70,180,"请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(190,135,620,215);
                        bar(70,180,180,230);
                    }
                    
                }
                else ifin[6][1] = 0;
            }
        }
        else person_restore(190, 135, 620, 215);
        if (pos > 0)
        {
            if (MouseX > 190 && MouseX < 520 && MouseY > 235 && MouseY < 275) //社团2
            {
                if (mouse_press(190, 235, 520, 275) == 2)
                {
                    MouseS = 2;
                    newmouse(&MouseX, &MouseY, &press);
                    person_change(190, 235, 520, 275);
                }
                if (mouse_press(190, 235, 520, 275) == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1, WHITE);
                    bar(190,235,520, 275);
                    memset(temp.club2,'\0',21);
                    j[2] = hz_input(190,245,495,275,temp.club2,0,WHITE,BLACK,16);
                    if (j[2] > 0)
                    {
                        if (j[2] <= 20)
                        {
                            ifin[6][2] = 7;
                        }
                        else
                        {
                            ifin[6][2] = 0;
                            memset(temp.club2, '\0', 21);
                            j[2] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 245, "超出限制", 16, 24, BLACK);
                            delay(1000);
                            bar(190, 235, 520, 275);
                            bar(540, 245, 640, 290);
                        }
                        if (cheek_legal(temp.club2,j[2]))
                        {
                            
                            ifin[6][2] = 0;
                            memset(temp.club2, '\0', 21);
                            j[2] = 0;
                            setfillstyle(1, WHITE);
                            puthz(540, 245, "请输入中文", 16, 24, BLACK);
                            delay(1000);
                            bar(190, 235, 520, 275);
                            bar(540, 245, 640, 290);
                        }
                        
                    }
                    else ifin[6][2] = 0;
                }
            }
            else person_restore(190, 235,520, 275);
            if (MouseX > 190 && MouseX < 620 && MouseY > 295 && MouseY < 375) // 经历2
            {
                if (mouse_press(190, 295, 620, 375) == 2)
                {
                    MouseS = 2;
                    newmouse(&MouseX, &MouseY, &press);
                    person_change(190, 295, 620, 375);
                }
                if (mouse_press(190, 295, 620, 375) == 1)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1, WHITE);
                    bar(190,295,520, 375);
                    memset(temp.detail2,'\0',71);
                    j[3] = hz_input(190,305,575,375,temp.detail2,0,WHITE,BLACK,16);
                    if (j[3] > 0)
                    {
                        if (j[3] <= 70)
                        {
                            ifin[6][3] = 7;
                        }
                        else
                        {
                            ifin[6][3] = 0;
                            memset(temp.detail2, '\0', 71);
                            j[3] = 0;
                            setfillstyle(1, WHITE);
                            puthz(70,345, "超出限制", 16, 24, BLACK);
                            delay(1000);
                            bar(190, 295, 620, 375);
                            bar(70,345,180,380);
                        }
                        if (cheek_legal(temp.detail2,j[3]))
                        {
                            
                            ifin[6][3] = 0;
                            memset(temp.detail2, '\0', 71);
                            j[3] = 0;
                            setfillstyle(1, WHITE);
                            puthz(70,345, "请输入中文", 16, 24, BLACK);
                            delay(1000);
                            bar(190, 295, 620, 375);
                            bar(70,345,180,380);
                        }
                        
                    }
                    else ifin[6][3] = 0;
                }
            }
            else person_restore(190, 295, 620, 375);
        }     
        if (MouseX > 150 && MouseX < 250 && MouseY > 385 && MouseY < 435) // 退出框
        {
            if (mouse_press(150,385,250,435) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(150,385,250,435) == 1)
            {
                printf("%d",template_page);
                clrmous(MouseX,MouseY);
                switch (template_page)
                {
                    case 1 : delay(200);
                             return 6;
                    case 2 : delay(200);
                             return 7;         
                    case 3 : delay(200);
                             return 8;   
                    case 4 : delay(200);
                             return 9;   
                    case 5 : delay(200);
                             return 15;                   
                }
            }
        }
        if (MouseX > 430 && MouseX < 530 && MouseY > 385 && MouseY < 435) // 保存
        {
            if (mouse_press(430,385,530,435) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(430,385,530,435) == 1)
            {
                *und = temp;
                undergo_info_save(und,psave);        
            }
        }
    }
}
/*********************************************
FUNCTION:undergo_info_save
DESCRIPTION:save the undergo info
INPUT:und,psave
RETURN:void
***********************************************/
void undergo_info_save(UNDERGO *und,int psave[])
{
    FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\undergo.dat", "rb+")) == NULL)
    {
        perror("Can't open undergo.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
	fwrite(und, sizeof(UNDERGO), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close undergo.dat.");
		delay(3000);
		exit(1);
	} 
    else
    {
        puthz(250,445,"保存成功",32,48,RED);
        delay(1000);
        setfillstyle(1, WHITE);
        bar(250,445,600,480);
        psave[6] = 1; 
    }
}
/*********************************************
FUNCTION:put_undergo_info
DESCRIPTION:put out the undergo info
INPUT:x,ifin
RETURN:void
***********************************************/
void put_undergo_info(int x,int ifin[][6])
{
    int len = 0;
    UNDERGO und;  
	FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\undergo.dat", "rb+")) == NULL)
    {
        perror("Can't open undergo.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(UNDERGO);
    fseek(fp,(len-1)*sizeof(UNDERGO),SEEK_SET);
	fread(&und, sizeof(UNDERGO), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close undergo.");
		delay(3000);
		exit(1);
	}
   setlinestyle(0,0,3);
   if (ifin[6][0] > 0)
   {
       line(0, 5 + x, 10, 5 + x);
       setfillstyle(1,WHITE);
       bar(15,x,30,x+30);
       puthz(15, x, und.club1, 16, 18, BLACK);
   }
   if (ifin[6][1] > 0)
   {
		puthz(15,30+x,und.detail1,16,18,BLACK);
   }
   if (ifin[6][2] > 0)
   {
        line(0,65+x,10,65+x);
        puthz(15,60+x,und.club2,16,18,BLACK);
   }
   if (ifin[6][3] > 0)
   {
        puthz(15,90+x,und.detail2,16,18,BLACK);
   }
}
/*********************************************
FUNCTION:honor_info
DESCRIPTION:put the honor info
INPUT:hon,psave
RETURN:
***********************************************/
int intern_info(INTERN *hon,int psave[],int ifin[][6],int template_page)
{
    int len = 0;
    INTERN temp2;
    INTERN temp;
    int j[4] = {0};
    FILE *fp;
    puthz(200, 15, "实习经历", 48, 64, BLACK);
	setlinestyle(0, 0, 1);
    puthz(70, 75, "公司名称", 24, 32, BLACK);
	person_restore(190, 75, 520, 115);
    puthz(70,135,"职位",24,64,BLACK);
    person_restore(190,135,520,175);
    puthz(70,195,"经历",24,64,BLACK);
    person_restore(190,195,620,355);
    setfillstyle(1,LIGHTGRAY);
    bar(150,370,250,420);
    puthz(150,375,"返回",24,64,BLACK);
    bar(430,370,530,420);
    puthz(430,375,"保存",24,64,BLACK);
    if (psave[7] == 1)
    {
        if ((fp = fopen("C:\\CODE\\database\\intern.dat", "rb+")) == NULL)
        {
            perror("Can't open intern.dat");
            delay(3000);
            exit(1);
        }
        fseek(fp, 0, SEEK_END);
        len = ftell(fp) / sizeof(INTERN);
        fseek(fp, (len - 1) * sizeof(INTERN), SEEK_SET);
        fread(&temp2, sizeof(INTERN), 1, fp);
        if (fclose(fp) != 0)
        {
            perror("Can't close intern.");
            delay(3000);
            exit(1);
        }
        if (ifin[7][0] > 0)
        {
            puthz(192,85,temp2.company,16,18,BLACK);
            strcpy(temp.company,temp2.company);
            ifin[7][0] = 9;
        }
        if (ifin[7][1] > 0)
        {
            puthz(192,145,temp2.job,16,18,BLACK);
            strcpy(temp.job,temp2.job);
            ifin[7][1] = 9;
        }
        if (ifin[7][2] > 0)
        {
            puthz(192,205,temp2.experience,16,18,BLACK);
            strcpy(temp.experience,temp2.experience);
            ifin[7][2] = 9;
        }
    }
    
	while(1)
	{
        if (MouseS != 0
        &&mouse_press(540,80,570,110) == 0
        &&mouse_press(190, 75, 520, 115) == 0
        &&mouse_press(190, 135, 520, 175) == 0
        &&mouse_press(190, 195, 620, 355) == 0
        &&mouse_press(150,370,250,420) == 0
        &&mouse_press(430,370,530,420) == 0)
        {
            MouseS = 0;
        }
        newmouse(&MouseX,&MouseY,&press);
        delay(40);
        if (MouseX>190&&MouseX<520&&MouseY>75&&MouseY<115)//公司名称
        {
            if (mouse_press(190, 75, 520, 115) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX,&MouseY,&press);
                person_change(190, 75, 520, 115);
            }
            if(mouse_press(190, 75, 520, 115)== 1)
            {
                clrmous(MouseX,MouseY);
                setfillstyle(1, WHITE);
                bar(190,75,520, 115);
                memset(temp.company,'\0',41);
                j[0] = hz_input(190,85,495,115,temp.company,0,WHITE,BLACK,16);
                if (j[0] > 0)
                {
                    if (j[0]<=48)
                    {
                        ifin[7][0] = 8;
                    }
                    else
                    {
                        ifin[7][0] = 0;
                        j[0] = 0;
                        memset(temp.company,'\0',41);
                        setfillstyle(1,WHITE);
                        puthz(540,85,"超出限制",16,24,BLACK);
                        delay(1000);
                        bar(190,75,520,115);
                        bar(540,85,640,130);
                    }
                    if (cheek_legal(temp.company,j[0]))
                    {
                        
                        ifin[7][0] = 0;
                        j[0] = 0;
                        memset(temp.company,'\0',41);
                        setfillstyle(1,WHITE);
                        puthz(540,85,"请输入中文",16,24,BLACK);
                        delay(1000);
                        bar(190,75,520,115);
                        bar(540,85,640,130);
                    }
                    
                }
                else ifin[7][0] = 0;
            }
        }
        else person_restore(190, 75, 520, 115);
        if (MouseX > 190 && MouseX < 520 && MouseY > 135 && MouseY < 175) //职位
        {
            if (mouse_press(190, 135, 520, 175) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX, &MouseY, &press);
                person_change(190, 135, 520, 175);
            }
            if (mouse_press(190, 135, 520, 175) == 1)
            {
                clrmous(MouseX, MouseY);
                setfillstyle(1, WHITE);
                bar(190, 135, 520, 175);
                memset(temp.job, '\0', 41);
                j[1] = hz_input(190, 145, 495, 175, temp.job, 0, WHITE, BLACK, 16);
                if (j[1] > 0)
                {
                    if (j[1] <= 40)
                    {
                        ifin[7][1] = 8;
                    }
                    else
                    {
                        ifin[7][1] = 0;
                        j[1] = 0;
                        memset(temp.job, '\0', 41);
                        setfillstyle(1, WHITE);
                        puthz(540, 145, "超出限制", 16, 24, BLACK);
                        delay(1000);
                        bar(190, 135, 520, 175);
                        bar(540, 145, 640, 190);
                    }
                    if (cheek_legal(temp.job,j[1]))
                    {
                       
                        ifin[7][1] = 0;
                        j[1] = 0;
                        memset(temp.job, '\0', 41);
                        setfillstyle(1, WHITE);
                        puthz(540, 145,  "请输入中文", 16, 24, BLACK);
                        delay(1000);
                        bar(190, 135, 520, 175);
                        bar(540, 145, 640, 190);
                    }
                    
                }
                else
                    ifin[7][1] = 0;
            }
        }
        else
            person_restore(190, 135, 520, 175);

        if (MouseX > 190 && MouseX < 620 && MouseY > 195 && MouseY < 355) // 经历
        {
            if (mouse_press(190, 195, 620, 355) == 2)
            {
                MouseS = 2;
                newmouse(&MouseX, &MouseY, &press);
                person_change(190, 195, 620, 355);
            }
            if (mouse_press(190, 195, 620, 355) == 1)
            {
                clrmous(MouseX, MouseY);
                setfillstyle(1, WHITE);
                bar(190, 195, 520, 235);
                memset(temp.experience, '\0', 41);
                j[2] = hz_input(190, 205, 575, 355, temp.experience, 0, WHITE, BLACK, 16);
                if (j[2] > 0)
                {
                    if (j[2] <= 150)
                    {
                        ifin[7][2] = 8;
                    }
                    else
                    {
                        ifin[7][2] = 0;
                        j[2] = 0;
                        memset(temp.experience, '\0', 41);
                        setfillstyle(1, WHITE);
                        puthz(70, 225, "超出限制", 16, 24, BLACK);
                        delay(1000);
                        bar(190, 195, 620, 355);
                        bar(70, 225, 180, 260);
                    }
                    if (cheek_legal(temp.experience,j[2]))
                    {

                        ifin[7][2] = 0;
                        j[2] = 0;
                        memset(temp.experience, '\0', 41);
                        setfillstyle(1, WHITE);
                        puthz(70, 225, "请输入中文", 16, 24, BLACK);
                        delay(1000);
                        bar(190, 195, 620, 355);
                        bar(70, 225, 180, 260);
                    }
                    
                }
                else
                    ifin[7][2] = 0;
            }
        }
        else
            person_restore(190, 195, 620, 355);

        if (MouseX > 150 && MouseX < 250 && MouseY > 370 && MouseY < 420) // 退出框
        {
            if (mouse_press(150,370,250,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(150,370,250,420) == 1)
            {
                clrmous(MouseX,MouseY);
                switch (template_page)
                {
                    case 1 : delay(200);
                             return 6;
                    case 2 : delay(200);
                             return 7;         
                    case 3 : delay(200);
                             return 8;   
                    case 4 : delay(200);
                             return 9;   
                    case 5 : delay(200);
                             return 15;               
                }
            }
        }
        if (MouseX > 430 && MouseX < 530 && MouseY > 370 && MouseY < 420) // 保存
        {
            if (mouse_press(430,370,530,420) == 2)
            {
                MouseS = 1;
                newmouse(&MouseX, &MouseY, &press);
            }
            if (mouse_press(430,370,530,420) == 1)
            {
                *hon = temp;
                intern_info_save(hon,psave);          
            }
        }
    }
}
/*********************************************
FUNCTION:honor_info_save
DESCRIPTION:save the honor info
INPUT:hon,psave
RETURN:void
***********************************************/
void intern_info_save(INTERN *hon,int psave[])
{
    FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\intern.dat", "rb+")) == NULL)
    {
        perror("Can't open intern.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
	fwrite(hon, sizeof(INTERN), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close intern.dat.");
		delay(3000);
		exit(1);
	} 
    else
    {
        puthz(250,440,"保存成功",32,48,RED);
        delay(1000);
        setfillstyle(1, WHITE);
        bar(250,440,600,480);
        psave[7] = 1; 
    }
}
/*********************************************
FUNCTION:put_honor_info
DESCRIPTION:put out the honor info
INPUT:x,ifin
RETURN:void
***********************************************/
void put_intern_info(int x,int ifin[][6])
{
    int len = 0;
    INTERN hon;  
	FILE *fp;
    if ((fp = fopen("C:\\CODE\\database\\intern.dat", "rb+")) == NULL)
    {
        perror("Can't open intern.dat");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(INTERN);
    fseek(fp,(len-1)*sizeof(INTERN),SEEK_SET);
	fread(&hon, sizeof(INTERN), 1, fp);
    if (fclose(fp) != 0)
	{
		perror("Can't close intern.");
		delay(3000);
		exit(1);
	}
   setlinestyle(0,0,1);
   if (ifin[7][0] > 0)
   {
       line(0, 5 + x, 10, 5 + x);
       puthz(15, x, hon.company, 16, 18, BLACK);
   }
   if (ifin[7][1] > 0)
   {
		puthz(15,35+x,hon.job,16,18,BLACK);
   }
   if (ifin[7][2] > 0)
   {
        line(0,75+x,10,75+x);
        puthz(15,70+x,hon.experience,16,18,BLACK);
   }
}
/*********************************************
FUNCTION:cheek_legal
DESCRIPTION:cheek whether the input is legal
INPUT:s,x
RETURN:
***********************************************/
int cheek_legal(char *s,int x)
{
    int i = 0;
    for(i=0;i<x;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            return 1;
        }
    }
    return 0;
}