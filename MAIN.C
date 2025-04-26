#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<bios.h>
#include<string.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include"mouse.h"
#include"welcome.h"
#include"REGISTER.H"
#include"HOME.H"
#include"CHOOSE.H"
#include"MAKE.H"
#include"PERSON.H"	
#include"INFO.H"
#include"ADD.H"
#include"CLASSIC.H"
#include"VIRGIN.H"
#include"GRADUATE.H"
#include"AWARD.H"
#include"LOG.H"
int main()
{
     int count = 0;//记录使用简历生成系统的次数
	 int ifadd = 0;//标记是否是新增的模式，即不是0~3，而是其他
	 int x = 0;//记录当前滚轮的位置
	 char usernum = 0;//记录当前用户的账号
	 int page=0;//记录当前页面
	 int info_page = 0;//记录简历的第几个板块
	 int template_page = 0;//当前使用的模板编号，1表示经典模板，2表示零经验求职，3表示毕业生求职，4表示评奖评优，5表示自定义
	 int gd=VGA,gm=VGAHI;//设置显示模式
	 int psave[9] = {0};//是否保存，0表示未保存，1表示已经保存
	 int ifin[8][6] = {{0},{0},{0},{0},{0},{0},{0},{0}};//每个模块的每个子信息是否保存
	 int pos[8] = {0};//每个板块是否显示，为0时表示显示，
	 int pchoose[8] = {0};//是否选中板块，为0表示未被选中，为1表示被选中
	 int turn[9] = {0};//记录板块的顺序
	 //注意：pos[]和turn[]里面的数据定义的不一样，pos[]里面没有基本信息一栏，而turn[]里面有基本信息一栏
	 
	 initgraph(&gd,&gm,"C:\\BORLANDC\\BGI");
	 page_welcome();
	 mouseinit();
	 while(1)
	 {
         switch(page)
		 {
			case -1: return 0;
			case 0: page = page_log(&usernum);//登陆界面
			        break;
			case 1: page = page_register();//注册界面
			        break;
			case 2: page = page_home(usernum,&count);//首页
			        break;
			case 3: page = page_choose();//选择界面
			        break;
			case 4: page = page_make();//制作简历界面
			        break;
			case 5: page = page_person();//个人信息界面
			        break;	
			case 6: page = page_classic(&x,&info_page,psave, ifin,pos,&template_page,&ifadd,&count,turn);//经典模板
					break;	
			case 7: page = page_virgin(&x,&info_page,psave,ifin,pos,&template_page,&ifadd,&count,turn);//零经验求职
			        break;
			case 8: page = page_graduate(&x,&info_page,psave,ifin,pos,&template_page,&ifadd,&count,turn);//毕业生求职
			        break;	
			case 9: page = page_award(&x,&info_page,psave,ifin,pos,&template_page,&ifadd,&count,turn);//评奖评优
			        break;		
			//case 10: page = page_person_changecode(usernum);//修改密码界面
			//        break;
			case 11: page = page_info(info_page,psave,ifin,template_page);//录入个人信息
			         break;		
			case 12: page = page_add(pos,template_page,&ifadd);//添加简历的版块
			         break;
			case 13 : page = make_list(pchoose,turn);//创建模板选择内容界面
			          break;	
			case 14 : page = turn_list(pchoose,turn);//创建模板顺序预览界面
			          break;	
			case 15 : page = my_template(&x,pchoose,turn,&info_page,&template_page,ifin,psave,&count);//我的自建模板界面
			          break;	
		    case 16 : page = page_useinfo(&usernum,count);	//查看个人信息页面
			           break;		  	  	  	 					
		 }
	 }
	return 0;
}
