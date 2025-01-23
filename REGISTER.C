#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"REGISTER.H"
#include<string.h>
#include"hz.h"
#include"mouse.h"
#include<graphics.h>
#include"LOG.H"
#include"COMMON.H"
/*********************************************
FUNCTION: page_register
DESCRIPTION: draw the register page
INPUT:void
RETURN:0,1,
***********************************************/
void page_register()
{
    char name[15] = {'\0'};
    char code[15] = {'\0'};
	char confirm[15] = {'\0'};
	char phone[12] = {'\0'};
    char pin[6] = {'\0'};
	char random[6] = {'\0'};
	int ran = 0;
	srand(time(NULL)); 
	cleardevice();
	setfillstyle(SOLID_FILL,LIGHTCYAN);
    bar(0,0,648,480);
    puthz(230,60,"注册",48,64,LIGHTRED);
	setcolor(WHITE);
	line(160,160,420,160);//用户线
	line(160,202,420,202);//密码线
	line(160,244,420,244);//确认线
	line(160,286,420,286);//手机号线
	line(160,328,420,328);//验证码线
	puthz(40,130,"用户名", 24, 45,WHITE);
	puthz(40,172,"密码", 24, 85, WHITE);
	puthz(40,213,"确认密码", 24, 30,WHITE);
	puthz(40,259,"手机号码", 24, 30, WHITE);
	puthz(40,301,"验证码", 24, 45,WHITE);
    setfillstyle(1,WHITE);
	bar(440,260,545,286);//获取验证码框
	log_restore(440,260,545,286);
	puthz(450,263,"获取验证码", 16, 17, BLACK);
	setfillstyle(1, WHITE);
	bar(143, 370, 237, 400);//重置框
	log_restore(143,370,237,400);
	puthz(161, 373, "重置", 24, 34,BLACK);
	setfillstyle(1, WHITE);
	bar(273, 370, 367, 400);//注册框
	log_restore(273,370,367,400);
	puthz(291, 373, "注册", 24, 34, BLACK);
	setfillstyle(1, WHITE);
	bar(403, 370, 497, 400);//返回框
	log_restore(403,370,497,400);
	puthz(421, 373, "返回", 24, 34, BLACK);
	while(1)
    {
        if (MouseS != 0
		&&mouse_press(160,130,420,160) == 0
		&&mouse_press(160,165,420,202) == 0
		&&mouse_press(160,207,420,244) == 0)
		{
			MouseS = 0;
		}
		newmouse(&MouseX,&MouseY,&press);
        delay(40);
		if (MouseX>160&&MouseX<420&&MouseY>130&&MouseY<160)//用户名线
		{
			if (mouse_press(160,130,420,160) == 2)
			{
				MouseS = 2;
				newmouse(&MouseX,&MouseY,&press);
			}
			if (mouse_press(160,130,420,160) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(SOLID_FILL,11);
                bar(160,130,420,159);
				log_inputaccount(name,160,130,12,11,1);
			}			 
		}
	    if (MouseX>160&&MouseX<420&&MouseY>165&&MouseY<202)//密码线
		{
			if (mouse_press(160,165,420,202) == 2)
			{
				MouseS = 2;
				newmouse(&MouseX,&MouseY,&press);
			}
			if (mouse_press(160,165,420,202) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(SOLID_FILL,11);
                bar(160,165,420,201);
				log_inputcode(code,160,165,12,11);
			}			 
		}
		if (MouseX>160&&MouseX<420&&MouseY>207&&MouseY<244)//确认线
		{
			if (mouse_press(160,207,420,244) == 2)
			{
				MouseS = 2;
				newmouse(&MouseX,&MouseY,&press);
			}
			if (mouse_press(160,207,420,244) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(SOLID_FILL,11);
                bar(160,207,420,243);
				log_inputcode(confirm,160,207,12,11);
			}			 
		}
		if (MouseX>160&&MouseX<420&&MouseY>249&&MouseY<286)//手机号线
		{
			if (mouse_press(160,249,420,286) == 2)
			{
				MouseS = 2;
				newmouse(&MouseX,&MouseY,&press);
			}
			if (mouse_press(160,249,420,286) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(SOLID_FILL,11);
				bar(160,249,420,285);
				log_inputaccount(phone,160,249,11,11,1);
			}		
		}	
        if (MouseX>160&&MouseX<420&&MouseY>291&&MouseY<328)//验证码线
		{
			if (mouse_press(160,291,420,328) == 2)
			{
				MouseS = 2;
				newmouse(&MouseX,&MouseY,&press);
			}
			if (mouse_press(160,291,420,328) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(SOLID_FILL,11);
				bar(160,291,420,327);
				log_inputaccount(pin,160,291,4,11,1);
				
			}		
		}
		if(MouseX>403&&MouseX<497&&MouseY>370&&MouseY<400)//返回框
		{
            if (mouse_press(403,370,497,400) == 2)
			{
				log_change(403,370,497,400);
			}
			if (mouse_press(403,370,497,400) == 1)
			{
				return 0;
			}			 
		}
		else log_restore(403,370,497,400);
		if (MouseX>440&&MouseX<545&&MouseY>260&&MouseY<286)//获取验证码框
		{
			if (mouse_press(440,260,545,286) == 2)
			{
				log_change(440,260,545,286);
			}
			if (mouse_press(440,260,545,286) == 1)
			{
				if(register_checkphonenumber(phone) == 2)
                {
					ran = 1000 + rand()%8999;//确保是四位数
				    itoa(ran,random,10);
					setfillstyle(SOLID_FILL,11);
	                bar(160,291,420,327);
	                setcolor(BLACK);
	                settextstyle( SMALL_FONT,HORIZ_DIR,8);
	                outtextxy(310,15,random);
					delay(1500);
					bar(310,10,430,50);
					//outtextxy(300,460,random);
				}
				else 
				{
					clrmous(MouseX,MouseY);
	                puthz(390,300,"请先输入合法手机号码", 16, 18, DARKGRAY);
	                delay(1500);
	                setfillstyle(SOLID_FILL,11);
	                bar(380,291,580,327);
					newmouse(&MouseX,&MouseY,&press);
				}
			}
		}
		else log_restore(440,260,545,286);
		if (MouseX>143&&MouseX<237&&MouseY>370&&MouseY<400)//重置框
		{
			if (mouse_press(143,370,237,400) == 2)
			{
				log_change(143,370,237,400);
			}
			
			if (mouse_press(143,370,237,400) == 1)
			{
				return 1;
			}
		}
	    else log_restore(143,370,237,400);
	    if (MouseX>273&&MouseX<367&&MouseY>370&&MouseY<400)//注册框
		{
			if (mouse_press(273,370,367,400) == 2)
			{
				log_change(273,370,367,400);
			}
			
			if (mouse_press(273,370,367,400) == 1)
			{
				//outtextxy(300,460,random);
				if(register_complete(name,code,confirm,phone,pin,random) == 0)
				{
					return 0;//返回登录界面
				}
			}
		}
	    else log_restore(273,370,367,400);
    }
}
/*********************************************
FUNCTION:register_input_database
DESCRIPTION：input the userinfo into the database
INPUT:name,phone,code
RETURN:void
***********************************************/
void register_input_database(char* name, char* phone, char* code)
{
    FILE* fp;
	USER * u;
	int len = 0;
	u->usecount = 0;
	u->usernum = 0;

	if ((fp = fopen("C:\\CODE\\database\\userdata.dat", "rb+")) == NULL)
	{
	    perror("Can't open userdata.dat");
		delay(3000);
		exit(1);
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
	    perror("memoryallocation runs wrong");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	memset(u,'\0',sizeof(USER));
	strcpy(u->user, name);
	strcpy(u->phonenumber, phone);
	strcpy(u->password, code);
	u->usernum=len+1;
	fseek(fp, 0, SEEK_END);
	fwrite(u, sizeof(USER), 1, fp);
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
}
/*********************************************               
FUNCTION:register_judge_user
DESCRIPTION：check whether the account exits.1 for not
INPUT:
RETURN:1/0
***********************************************/
int register_judge_user(char *name)
{
    int len = 0;
	int i = 0;
	FILE *fp;
	USER* u = NULL;
	if ((fp = fopen("C:\\CODE\\database\\userdata.dat", "rb+")) == NULL)
	{
	    perror("Can't open userdata.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for ( i = 0; i < len; i++)
	{
		if ((u = (USER *)malloc(sizeof(USER))) == NULL)
		{
			perror("memoryallocation runs wrong");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->user, name) == 0)
		{
			puthz(160, 135, "用户已被注册", 16, 17, RED);
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
			return 0; // 重复为0
		}
		free(u);
		u = NULL;
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
	return 1;//未重复
}
/*********************************************
FUNCTION:register_checkcode
DESCRIPTION：check whether the confirmation codes are consistent.0 for same
INPUT:code,confirm
RETURN:1/0
***********************************************/
int register_checkcode(char *code,char *confirm)
{
    if (strcmp(code, confirm) != 0)
	{
		puthz(160, 221, "两次不一致", 16, 17, RED);
		return 1;//不一致
	}
	else if (strcmp(code, confirm) == 0)
	{
		return 0;
	}
}
/*********************************************
FUNCTION:register_checkphonenumber
DESCRIPTION：check the digits and format of the mobile phone number.2 for legal
INPUT:phone
RETURN:1,0,2
***********************************************/
int  register_checkphonenumber(char *phone)
{
	int i = 0;
    if (strlen(phone) != 11)
	{
		puthz(180, 263, "手机号码为", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 1);
		outtextxy(265, 263-5, "11");
		puthz(283, 263, "位", 16, 17, RED);//长度不符合
		return 1;//位数不合要求
	}
    else if (strlen(phone) == 11)
	{
		for (i = 0; i < 11; i++)
		{
			if (phone[i] >= '0' && phone[i] <= '9')
			{
				continue;
			}
			else
			{
				puthz(70, 263, "格式不正确", 16, 17, RED);
				return 0;//格式不合要求
			}		
		}	
	}
	return 2;
}
/*********************************************
FUNCTION:register_checkpin
DESCRIPTION：check whether the pin is right.0 for same
INPUT:pin,random
RETURN:1/0
***********************************************/
int register_checkpin(char *pin,char *random)
{
    pin[4] = '\0';
	random[4] = '\0';
	if (strcmp(pin,random) != 0)
	{
		puthz(173, 300, "验证码错误", 16, 17, RED);
		//outtextxy(0,0,pin);
		//outtextxy(300,0,random);
		return 1;
	}
	else if (strcmp(pin,random) == 0)
	{
		return 0;
	}
}
/*********************************************
FUNCTION:register_judgeinput
DESCRIPTION：check whether input something.0 for not
INPUT:str,x,y
RETURN:1,0
***********************************************/
int register_judgeinput(char *str ,int x,int y)
{
    if (strlen(str) == 0)
	{
		puthz(x+10, y+10, "未输入", 16, 17, RED);
		return 0;
	}
	else
	{
		return 1;
	}
}
/*********************************************
FUNCTION:register_complete
DESCRIPTION：complete registration.0 for success
INPUT:name,code,confirm,phone,pin,random
RETURN:1,0
***********************************************/
int register_complete(char *name,char *code,char *confirm,char *phone,char *pin,char *random)
{
	
	int state[5] = {0, 0, 0, 0, 0};
	state[0] = register_judgeinput(name, 160, 127);
	state[1] = register_judgeinput(code, 160, 170);
	state[2] = register_judgeinput(confirm, 160, 210);
	state[3] = register_judgeinput(phone, 160, 255);
	state[4] = register_judgeinput(pin, 160, 300);
	

	if(state[0] == 0||state[1] == 0||state[2] == 0||state[3] == 0||state[4] == 0)
	{
		return 1;
	}
    else
	{
       
	    //outtextxy(0,440,random);
	    if (register_judge_user(name) == 1
		&&register_checkcode(code,confirm) == 0
		&&register_checkpin(pin,random) == 0)
		{
			register_input_database(name,phone,code);
			puthz(280,420, "注册成功", 24, 30, 13);
		    delay(2000);
		    return 0;//返回
		}
		else return 1;
	}
}