#include"mouse.h"
#include"hz.h"
#include<graphics.h>
#include"CHOOSE.H"
#include"save.H"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"INFO.H"
//用法：将存入.dat函数中的信息存入.txt文件中
//参数：psave[]：保存的选项，ifin[][]：输入的选项，template_page：模板页码，turn[]：自定义模块排列顺序
int saveout(int psave[], int ifin[][6], int *template_page,int turn[])
{
	FILE *fp;
	FILE* fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8;
	//文件指针
	BASIC* b = (BASIC*)malloc(sizeof(BASIC));
	INTENTION* intent = (INTENTION*)malloc(sizeof(INTENTION));
	EDUCATION* edu = (EDUCATION*)malloc(sizeof(EDUCATION));
	EXPERIENCE* exp = (EXPERIENCE*)malloc(sizeof(EXPERIENCE));
	SKILL* ski = (SKILL*)malloc(sizeof(SKILL));
	COMMENT* com = (COMMENT*)malloc(sizeof(COMMENT));
	UNDERGO* und = (UNDERGO*)malloc(sizeof(UNDERGO));
	INTERN* hon = (INTERN*)malloc(sizeof(INTERN));
	int len = 0,i=0;
	fp = fopen("C:\\CODE\\RESUME.txt","w");
	fp1 = fopen("C:\\CODE\\database\\basic.dat", "r");
	fp2 = fopen("C:\\CODE\\database\\intent.dat", "r");
	fp3 = fopen("C:\\CODE\\database\\edu.dat", "r");
	fp4 = fopen("C:\\CODE\\database\\comment.dat", "r");
	fp5 = fopen("C:\\CODE\\database\\exper.dat", "r");
	fp6 = fopen("C:\\CODE\\database\\skill.dat", "r");
	fp7 = fopen("C:\\CODE\\database\\intern.dat", "r");
	fp8 = fopen("C:\\CODE\\database\\undergo.dat", "r");
	fseek(fp1, 0, SEEK_END);
	len = ftell(fp1) / sizeof(BASIC);
	//计算有几个用户的数据
	fseek(fp1, (len - 1) * sizeof(BASIC), SEEK_SET);
	fread(b, sizeof(BASIC), 1, fp1);
	fclose(fp1);
	//个人信息
	fseek(fp2, 0, SEEK_END);
	len = ftell(fp2) / sizeof(INTENTION);
	fseek(fp2, (len - 1) * sizeof(INTENTION), SEEK_SET);
	fread(intent, sizeof(INTENTION), 1, fp2);
	fclose(fp2);
	//求职意向
	fseek(fp3, 0, SEEK_END);
	len = ftell(fp3) / sizeof(EDUCATION);
	fseek(fp3, (len - 1) * sizeof(EDUCATION), SEEK_SET);
	fread(edu, sizeof(EDUCATION), 1, fp3);
	fclose(fp3);
	//教育经历
	fseek(fp4, 0, SEEK_END);
	len = ftell(fp4) / sizeof(COMMENT);
	fseek(fp4, (len - 1) * sizeof(COMMENT), SEEK_SET);
	fread(com, sizeof(COMMENT), 1, fp4);
	fclose(fp4);
	//自我评价
	fseek(fp5, 0, SEEK_END);
	len = ftell(fp5) / sizeof(EXPERIENCE);
	fseek(fp5, (len - 1) * sizeof(EXPERIENCE), SEEK_SET);
	fread(exp, sizeof(EXPERIENCE), 1, fp5);
	fclose(fp5);
	//工作经历
	fseek(fp6, 0, SEEK_END);
	len = ftell(fp6) / sizeof(SKILL);
	fseek(fp6, (len - 1) * sizeof(SKILL), SEEK_SET);
	fread(ski, sizeof(SKILL), 1, fp6);
	fclose(fp6);
	//技能证书
	fseek(fp7, 0, SEEK_END);
	len = ftell(fp7) / sizeof(INTERN);
	fseek(fp7, (len - 1) * sizeof(INTERN), SEEK_SET);
	fread(hon, sizeof(INTERN), 1, fp7);
	fclose(fp7);
	//实习经历
	fseek(fp8, 0, SEEK_END);
	len = ftell(fp8) / sizeof(UNDERGO);
	fseek(fp8, (len - 1) * sizeof(UNDERGO), SEEK_SET);
	fread(und, sizeof(UNDERGO), 1, fp8);
	fclose(fp8);
	//在校经历
	if (fp == NULL)
	{
		exit(1);
	}
	if (*template_page != 5)//不是自己创建模板
	{
		if (psave[0] == 1)//未保存
		{
			if (ifin[0][0] > 0)
			{
				fprintf(fp, "姓名:%s\n", b->name);//将信息写入文件
			}
			if (ifin[0][1] > 0)
			{
				fprintf(fp, "手机:%s\t", b->phone);//后面赋值给前面
			}
			if (ifin[0][2] > 0)
			{
				fprintf(fp, "邮箱:%s\n", b->email);
			}
			if (ifin[0][3] > 0)
			{
				fprintf(fp, "微信:%s\t", b->wechat);
			}
			if (ifin[0][4] > 0)
			{
				fprintf(fp, "生日:%s\n", b->birth);
			}
			fputs("\n---------------------------------------------------------------------\t\n", fp);
		}
		if (psave[1] == 1)
		{
			if (ifin[1][0] > 0)
			{
				fprintf(fp, "求职岗位:%s\t", intent->job);
			}
			if (ifin[1][1] > 0)
			{
				fprintf(fp, "求职类型:%s\t", intent->sort);
			}
			if (ifin[1][2] > 0)
			{
				fprintf(fp, "期望薪资:%s\t", intent->wage);
			}
			if (ifin[1][3] > 0)
			{
				fprintf(fp, "期望城市:%s\n", intent->city);
			}
			fputs("\n---------------------------------------------------------------------\t\n", fp);
		}
		if (psave[2] == 1)
		{
			if (ifin[2][0] > 0)
			{
				fprintf(fp, "学校名称:%s\t", edu->school);
			}
			if (ifin[2][1] > 0)
			{
				fprintf(fp, "专业学历:%s\t", edu->degree);
			}
			if (ifin[2][2] > 0)
			{
				fprintf(fp, "专业成绩:%s\t", edu->score);
			}
			if (ifin[2][3] > 0)
			{
				fprintf(fp, "专业课程:%s\t", edu->course);
			}
			if (ifin[2][4] > 0)
			{
				fprintf(fp, "荣誉奖项:%s\t\n", edu->honor);
			}
			fputs("\n---------------------------------------------------------------------\t\n", fp);
		}

		if (psave[6] == 1)
		{
			if (ifin[6][0] > 0)
			{
				fprintf(fp, "在校经历\n%s\n", und->club1);
			}
			if (ifin[6][1] > 0)
			{
				fprintf(fp, "%s\n", und->club2);
			}
			if (ifin[6][2] > 0)
			{
				fprintf(fp, "%s\n", und->detail1);
			}
			if (ifin[6][3] > 0)
			{
				fprintf(fp, "%s\n", und->detail2);
			}
			fputs("\n---------------------------------------------------------------------\t\n", fp);
		}

		if (psave[7] == 1)
		{
			if (ifin[7][0] > 0)
			{
				fprintf(fp, "实习经历\n%s\n", hon->company);
			}
			if (ifin[7][1] > 0)
			{
				fprintf(fp, "%s\n", hon->job);
			}
			if (ifin[7][2] > 0)
			{
				fprintf(fp, "%s\n", hon->experience);
			}
			fputs("\n---------------------------------------------------------------------\t\n", fp);
		}

		if (psave[3] == 1)
		{
			fputs("工作经历\n", fp);
			if (ifin[3][0] > 0)
			{
				fprintf(fp, "公司:%s\n", exp->company);
			}
			if (ifin[3][1] > 0)
			{
				fprintf(fp, "职位:%s\t", exp->postition);
			}
			if (ifin[3][2] > 0)
			{
				fprintf(fp, "%s\t", exp->start);
			}
			if (ifin[3][3] > 0)
			{
				fprintf(fp, "%s\n", exp->end);
			}
			if (ifin[3][4] > 0)
			{
				fprintf(fp, "工作事迹%s\n", exp->deed);
			}
			fputs("\n---------------------------------------------------------------------\t\n", fp);//用于将一个字符串保存进文档
		}

		if (psave[4] == 1)
		{
			if (ifin[4][0] > 0)
			{
				fprintf(fp, "技能证书\n%s\n", ski->skill1);
			}
			if (ifin[4][1] > 0)
			{
				fprintf(fp, "%s\n", ski->skill2);
			}
			if (ifin[4][2] > 0)
			{
				fprintf(fp, "%s\n", ski->skill3);
			}
			if (ifin[4][3] > 0)
			{
				fprintf(fp, "%s\n", ski->skill4);
			}
			fputs("\n---------------------------------------------------------------------\t\n", fp);
		}

		if (psave[5] == 1)
		{
			if (ifin[5][0] > 0)
			{
				fprintf(fp, "自我评价\n%s\n", com->com1);
			}
			if (ifin[5][1] > 0)
			{
				fprintf(fp, "%s\n", com->com2);
			}
			if (ifin[5][2] > 0)
			{
				fprintf(fp, "%s\n", com->com3);
			}
			if (ifin[5][3] > 0)
			{
				fprintf(fp, "%s\n", com->com4);
			}
			fputs("\n---------------------------------------------------------------------\t\n", fp);
		}
	}
	if (*template_page == 5)//如果是自己创建模板，顺序会有变化，使用需要先遍历出模块之间的顺序
	{
		for (i = 0; i < 8; i++)
		{
			if (turn[0] == i && psave[0] == 1)
			{
				if (ifin[0][0] > 0)
				{
					fprintf(fp, "姓名:%s\n", b->name);
				}
				if (ifin[0][1] > 0)
				{
					fprintf(fp, "手机:%s\t", b->phone);
				}
				if (ifin[0][2] > 0)
				{
					fprintf(fp, "邮箱:%s\n", b->email);
				}
				if (ifin[0][3] > 0)
				{
					fprintf(fp, "微信:%s\t", b->wechat);
				}
				if (ifin[0][4] > 0)
				{
					fprintf(fp, "生日:%s\n", b->birth);
				}
				fputs("\n---------------------------------------------------------------------\t\n", fp);
			}
			if (turn[1] == i && psave[1] == 1)
			{
				if (ifin[1][0] > 0)
				{
					fprintf(fp, "求职岗位:%s\t", intent->job);
				}
				if (ifin[1][1] > 0)
				{
					fprintf(fp, "求职类型:%s\t", intent->sort);
				}
				if (ifin[1][2] > 0)
				{
					fprintf(fp, "期望薪资:%s\t", intent->wage);
				}
				if (ifin[1][3] > 0)
				{
					fprintf(fp, "期望城市:%s\n", intent->city);
				}
				fputs("\n---------------------------------------------------------------------\t\n", fp);
			}
			if (turn[2] == i && psave[2] == 1)
			{
				if (ifin[2][0] > 0)
				{
					fprintf(fp, "学校名称:%s\t", edu->school);
				}
				if (ifin[2][1] > 0)
				{
					fprintf(fp, "专业学历:%s\t", edu->degree);
				}
				if (ifin[2][2] > 0)
				{
					fprintf(fp, "专业成绩:%s\t", edu->score);
				}
				if (ifin[2][3] > 0)
				{
					fprintf(fp, "专业课程:%s\t", edu->course);
				}
				if (ifin[2][4] > 0)
				{
					fprintf(fp, "荣誉奖项:%s\t\n", edu->honor);
				}
				fputs("\n---------------------------------------------------------------------\t\n", fp);
			}
			if (turn[3] == i && psave[3] == 1)
			{
				fputs("工作经历\n", fp);
				if (ifin[3][0] > 0)
				{
					fprintf(fp, "公司:%s\n", exp->company);
				}
				if (ifin[3][1] > 0)
				{
					fprintf(fp, "职位:%s\t", exp->postition);
				}
				if (ifin[3][2] > 0)
				{
					fprintf(fp, "%s\t", exp->start);
				}
				if (ifin[3][3] > 0)
				{
					fprintf(fp, "%s\n", exp->end);
				}
				if (ifin[3][4] > 0)
				{
					fprintf(fp, "工作事迹%s\n", exp->deed);
				}
				fputs("\n---------------------------------------------------------------------\t\n", fp);
			}
			if (turn[4] == i && psave[4] == 1)
			{
				if (ifin[4][0] > 0)
				{
					fprintf(fp, "技能证书\n%s\n", ski->skill1);
				}
				if (ifin[4][1] > 0)
				{
					fprintf(fp, "%s\n", ski->skill2);
				}
				if (ifin[4][2] > 0)
				{
					fprintf(fp, "%s\n", ski->skill3);
				}
				if (ifin[4][3] > 0)
				{
					fprintf(fp, "%s\n", ski->skill4);
				}
				fputs("\n---------------------------------------------------------------------\t\n", fp);
			}
			if (turn[5] == i && psave[5] == 1)
			{
				if (ifin[5][0] > 0)
				{
					fprintf(fp, "自我评价\n%s\n", com->com1);
				}
				if (ifin[5][1] > 0)
				{
					fprintf(fp, "%s\n", com->com2);
				}
				if (ifin[5][2] > 0)
				{
					fprintf(fp, "%s\n", com->com3);
				}
				if (ifin[5][3] > 0)
				{
					fprintf(fp, "%s\n", com->com4);
				}
				fputs("\n---------------------------------------------------------------------\t\n", fp);
			}
			if (turn[6] == i && psave[6] == 1)
			{
				if (ifin[6][0] > 0)
				{
					fprintf(fp, "在校经历\n%s\n", und->club1);
				}
				if (ifin[6][1] > 0)
				{
					fprintf(fp, "%s\n", und->club2);
				}
				if (ifin[6][2] > 0)
				{
					fprintf(fp, "%s\n", und->detail1);
				}
				if (ifin[6][3] > 0)
				{
					fprintf(fp, "%s\n", und->detail2);
				}
				fputs("\n---------------------------------------------------------------------\t\n", fp);
			}
			if (turn[7] == i && psave[7] == 1)
			{
				if (ifin[7][0] > 0)
				{
					fprintf(fp, "实习经历\n%s\n", hon->company);
				}
				if (ifin[7][1] > 0)
				{
					fprintf(fp, "%s\n", hon->job);
				}
				if (ifin[7][2] > 0)
				{
					fprintf(fp, "%s\n", hon->experience);
				}
				fputs("\n---------------------------------------------------------------------\t\n", fp);
			}
		}
	}
	free(b);
	free(intent);
	free(edu);
	free(exp);
	free(ski);
	free(com);
	free(und);
	free(hon);
	fclose(fp);
	return 1;
}