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
    //rectangle(0, 75, 120, 125);  // 更改密码
    //rectangle(0, 175, 120, 225); // 个人信息
    //rectangle(0, 275, 120, 325); // 我的简历
    /*puthz(20, 80, "更改密码", 24, 25, BLACK);*/
    puthz(20, 180, "使用信息", 24, 25, BLACK);
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
     //   if(MouseX>0&&MouseX<120&&MouseY>75&&MouseY<125)//更改密码

     //   {
     //       if (mouse_press(0,75,125,125) == 2)
     //       {
     //           MouseS = 1;
     //           newmouse(&MouseX,&MouseY,&press);
     //           person_change(0,75,120,125);
     //       } 
     //       if(mouse_press(0,75,120,125) == 1)
     //       {
				 //return 10;
     //       } 
     //   }
        //else person_restore(0,75,120,125);//
        if(MouseX>0&&MouseX<120&&MouseY>175&&MouseY<225)//个人信息

        {
            if (mouse_press(0,175,120,225) == 2)
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
FUNCTION:person_changecode
DESCRIPTION：change the code
INPUT:void
RETURN:void
***********************************************/
//int page_person_changecode(char usernum)
//{    
//    int len = 0;
//    int i = 0;
//    FILE* fp;
//    USER *temp = NULL;
//    char code[11] = {'\0'};
//    char newcode[11] = {'\0'};
//    char confirm[11] = {'\0'};
//    //cleardevice();
//    clrmous(MouseX,MouseY);
//    setfillstyle(SOLID_FILL,WHITE);
//    bar(0, 0, 640, 480);
//    setfillstyle(SOLID_FILL, LIGHTCYAN);
//    bar(0, 0, 120, 480);
//    setfillstyle(SOLID_FILL, LIGHTBLUE);
//    bar(0, 0, 640, 70);
//    puthz(220, 15, "个人中心", 48, 48, YELLOW);
//    setcolor(BLACK);
//    setlinestyle(0, 0, 3); // 粗线
//    line(0, 70, 640, 70);
//    setlinestyle(0, 0, 1);       // 细线
//    //rectangle(0, 75, 120, 125);  // 更改密码
//    //rectangle(0, 175, 120, 225); // 个人信息
//    //rectangle(0, 275, 120, 325); // 我的简历
//    puthz(20, 80, "更改密码", 24, 25, BLACK);
//    puthz(20, 280, "使用信息", 24, 25, BLACK);
//    setfillstyle(1, RED);
//    bar(550, 30, 630, 61); // 返回框
//    puthz(565, 33, "返回", 24, 30, WHITE);
//
//    setfillstyle(SOLID_FILL,WHITE);
//    bar(121,71,640,480);
//    setlinestyle(0,0,3);
//    setcolor(BLACK);
//	person_restore(310, 130, 550, 175);
//    person_restore(310,210,550,255);
//	person_restore(310,290,550,335);
//	puthz(185,136,"原密码",24,42,BLACK);
//	puthz(185,216,"新密码",24,42,BLACK);
//	puthz(185,296,"确认密码",24,30,BLACK);
//    setfillstyle(SOLID_FILL,BLUE);
//	bar(350,380,470,410);
//	puthz(355,383,"更改密码",24,30,WHITE);
//    person_restore(350,380,470,410);
//
//    if (temp = (USER*)malloc(sizeof(USER)) == NULL)
//    {
//        perror("memory wrong");
//        delay(3000);
//        exit(1);
//    }
//    if ((fp = fopen("C:\\CODE\\database\\userdata.dat", "rb+")) == NULL)
//    {
//        perror("Can't open userdata.dat");
//        delay(3000);
//        exit(1);
//    }
//    
//    fseek(fp, (usernum-1)*sizeof(USER), SEEK_SET);
//    fread(temp,sizeof(USER),1,fp);
//    fclose(fp);
//    while (1)
//    {
//        if (MouseS != 0
//        &&mouse_press(310, 130, 550, 175) == 0
//        &&mouse_press(310, 210, 550, 255) == 0
//        &&mouse_press(310,290,550,335) == 0
//        &&mouse_press(550,30,630,61) == 0
//        &&mouse_press(0,75,125,125) == 0
//        &&mouse_press(0,175,120,225) == 0
//        &&mouse_press(0,275,120,325) == 0
//        &&mouse_press(350,380,470,410) == 0)
//        {
//            MouseS = 0;
//        }
//        newmouse(&MouseX,&MouseY,&press);
//        if (MouseX > 310 && MouseX < 550 && MouseY > 130 && MouseY < 175)//原密码
//        {
//            if (mouse_press(310, 130, 550, 175) == 2)
//            {
//                MouseS = 2;
//                newmouse(&MouseX, &MouseY, &press);
//                person_change(310, 130, 550, 175);
//            }
//            if (mouse_press(310, 130, 550, 175) == 1)
//            {
//                clrmous(MouseX,MouseY);
//                setfillstyle(SOLID_FILL,WHITE);
//                bar(310, 130, 550, 175);
//                log_inputcode(code,312,140,10,WHITE);
//                if (strcmp(temp->password,code) != 0)
//                {
//                    outtextxy(10,0,temp->password);
//                    outtextxy(0,50,code);
//                    printf("%d\t",temp->usernum);
//                    printf("%d",usernum);
//                    puthz(320, 187, "密码错误", 16, 17, RED);
//                    delay(1000);
//                    return 10;
//                }
//            }
//        }
//        else person_restore(310, 130, 550, 175);
//        if (MouseX > 310 && MouseX < 550 && MouseY > 210 && MouseY < 255)//新密码
//        {
//            if (mouse_press(310, 210, 550, 255) == 2)
//            {
//                MouseS = 2;
//                newmouse(&MouseX, &MouseY, &press);
//                person_change(310, 210, 550, 255);
//            }
//            if (mouse_press(310, 210, 550, 255) == 1)
//            {
//                clrmous(MouseX,MouseY);
//                setfillstyle(SOLID_FILL,WHITE);
//                bar(310, 210, 550, 255);
//                log_inputcode(newcode,312,220,10,WHITE);
//
//                if (strcmp(newcode, temp->password) == 0)
//                {
//                    puthz(320, 263, "密码重复", 16, 17, RED);
//                    delay(1000);
//                    return 10;
//                }
//            }
//        }
//        else person_restore(310, 210, 550, 255);
//        if (MouseX > 310 && MouseX < 550 && MouseY > 290 && MouseY < 335)//确认密码
//        {
//            if (mouse_press(310,290,550,335) == 2)
//            {
//                MouseS = 2;
//                newmouse(&MouseX, &MouseY, &press);
//                person_change(310,290,550,335);
//            }
//            if (mouse_press(310,290,550,335) == 1)
//            {
//                clrmous(MouseX,MouseY);
//                setfillstyle(SOLID_FILL,WHITE);
//                bar(310,290,550,335);
//                log_inputcode(confirm,312,300,10,WHITE);
//                if (strcmp(confirm, newcode) != 0)
//                {
//                    puthz(320, 350, "密码不一致", 16, 17, RED);
//                    delay(1000);
//                    return 10;
//                }
//            }
//        }
//        else person_restore(310, 290, 550, 335);
//        if(MouseX>550&&MouseX<630&&MouseY>30&&MouseY<61)//退出框
//
//        {
//            if (mouse_press(550,30,630,61) == 2)
//            {
//                MouseS = 1;
//                newmouse(&MouseX,&MouseY,&press);
//            } 
//            if(mouse_press(550,30,630,61) == 1)
//            {
//                return 5;
//            } 
//        }  
//        if(MouseX>0&&MouseX<120&&MouseY>75&&MouseY<125)//更改密码
//        {
//            if (mouse_press(0,75,125,125) == 2)
//            {
//                MouseS = 1;
//                newmouse(&MouseX,&MouseY,&press);
//                person_change(0,75,120,125);
//            } 
//            if(mouse_press(0,75,120,125) == 1)
//            {
//				 return 10;
//            } 
//        }
//        else person_restore(0,75,120,125);
//        if(MouseX>0&&MouseX<120&&MouseY>275&&MouseY<325)//使用信息
//        {
//            if (mouse_press(0,275,120,325) == 2)
//            {
//                MouseS = 1;
//                newmouse(&MouseX,&MouseY,&press);
//                person_change(0,275,120,325);
//            } 
//            if(mouse_press(0,275,120,325) == 1)
//            {
//                
//            } 
//        }
//        else person_restore(0,275,120,325);
//        if(MouseX>350&&MouseX<470&&MouseY>380&&MouseY<410)//确认修改
//        {
//            if (mouse_press(350,380,470,410) == 2)
//            {
//                MouseS = 1;
//                newmouse(&MouseX,&MouseY,&press);
//                person_change(350,380,470,410);
//            } 
//            if(mouse_press(350,380,470,410) == 1)
//            {
//                if ((fp = fopen("C:\\CODE\\database\\userdata.dat", "rb+")) == NULL)
//                {
//                    perror("Can't open userdata.dat");
//                    delay(3000);
//                    exit(1);
//                }
//                strcpy(temp->password,newcode);
//                fseek(fp,(usernum-1)*sizeof(USER),SEEK_SET);
//                fwrite(temp,sizeof(USER),1,fp);
//                free(temp);
//                fclose(fp);
                // if ((fp = fopen("C:\\CODE\\database\\userdata.dat", "rb+")) == NULL)
                // {
                //     perror("Can't open userdata.dat");
                //     delay(3000);
                //     exit(1);
                // }
                // fseek(fp, 0, SEEK_END);
                // len = ftell(fp) / sizeof(USER);
                // printf("%d",len);
                // u = (USER*)malloc(len * sizeof(USER));
                // for (i = 0; i < *usernum - 1; i++)
                // { 
                //     fseek(fp, i * sizeof(USER), SEEK_SET);
                //     fread(u+i, sizeof(USER), 1, fp);
                // }
                // for(i= *usernum;i<len;i++)
                // {
                //     fseek(fp, i * sizeof(USER), SEEK_SET);
                //     fread(u + i - 1, sizeof(USER), 1, fp);
                // }
                // if (fclose(fp) != 0)
                // {
                //     perror("Can't close userdata.dat");
                //     delay(3000);
                //     exit(1);
                // }
                // if ((fp = fopen("C:\\CODE\\database\\userdata.dat", "wb+")) == NULL) //打开文件
                // {
                //     perror("Can't open userdata.dat");
                //     delay(3000);
                //     exit(1);
                // }
                // for (i = 0; i < len - 1; i++)
                // {
                //     fseek(fp, i * sizeof(USER), 0);
                //     fwrite(u + i, sizeof(USER), 1, fp);
                // }
                // fseek(fp,0,SEEK_END);
                // fwrite(temp,sizeof(USER),1,fp);
                // if (fclose(fp) != 0)
                // {
                //     perror("Can't close userdata.dat");
                //     delay(3000);
                //     exit(1);
                // }
                // free(u);
//                // free(temp);
//            } 
//        }
//        else person_restore(350,380,470,410);
//    }
//}

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
    
    /* puthz(20, 80, "更改密码", 24, 25, BLACK);*/
     /*puthz(20, 180, "使用信息", 24, 25, BLACK);*/
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

     /*if ((fp = fopen("C:\\CODE\\database\\userdata.dat", "rb+")) == NULL)
     {
         perror("Can't open userdata.dat");
         delay(3000);
         exit(1);
     }*/
     //fseek(fp, 0, SEEK_END);
     //len = ftell(fp) / sizeof(USER);
     //u = (USER *)malloc(len * sizeof(USER));
     //for (i = 0; i < *usernum - 1; i++)
     //{
     //    fseek(fp, i * sizeof(USER), SEEK_SET);
     //    fread(u + i, sizeof(USER), 1, fp);
     //}
     //for (i = *usernum; i < len; i++)
     //{
     //    fseek(fp, i * sizeof(USER), 0);
     //    fread(u + i - 1, sizeof(USER), 1, fp);
     //}
     //if (fclose(fp) != 0)
     //{
     //    perror("Can't close userdata.dat");
     //    delay(3000);
     //    exit(1);
     //}
     //if ((fp = fopen("C:\\CODE\\database\\userdata.dat", "wb+")) == NULL) // 打开文件
     //{
     //    perror("Can't open userdata.dat");
     //    delay(3000);
     //    exit(1);
     //}
     //for (i = 0; i < len - 1; i++)
     //{
     //    fseek(fp, i * sizeof(USER), 0);
     //    fwrite(u + i, sizeof(USER), 1, fp);
     //}
     //if (fclose(fp) != 0)
     //{
     //    perror("Can't close userdata.dat");
     //    delay(3000);
     //    exit(1);
     //}
     //free(u);

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