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
     int count = 0;//��¼�û�ʹ�ô���
	 int ifadd = 0;
	 int x = 0;//��������
	 char usernum = 0;//��¼�û�����
	 int page=0;
	 int info_page = 0;
	 int template_page = 0;
	 int gd=VGA,gm=VGAHI;
	 int psave[9] = {0};//�ж��Ƿ񱣴棬0Ϊδ����
	 int ifin[8][6] = {{0},{0},{0},{0},{0},{0},{0},{0}};//�ж��Ƿ����룬0Ϊδ����
	 int pos[8] = {0};//�ж��Ƿ�ɾ����0Ϊδɾ��
	 int pchoose[8] = {0};//�ж��Ƿ�ѡ��0Ϊδ��ѡ
	 int turn[9] = {0};//��¼��Ԥ��˳�����ʵ��˳��0Ϊδѡ��
	 
	 
	 initgraph(&gd,&gm,"C:\\BORLANDC\\BGI");
	 page_welcome();
	 mouseinit();
	 while(1)
	 {
         switch(page)
		 {
			case -1: return 0;
			case 0: page = page_log(&usernum);//��¼����
			        break;
			case 1: page = page_register();//ע�����
			        break;
			case 2: page = page_home(usernum,&count);//������
			        break;
			case 3: page = page_choose();//ѡ��ģ��	
			        break;
			case 4: page = page_make();//����ģ��
			        break;
			case 5: page = page_person();//��������		 
			        break;	
			case 6: page = page_classic(&x,&info_page,psave, ifin,pos,&template_page,&ifadd,&count,turn);//����ģ��
					break;	
			case 7: page = page_virgin(&x,&info_page,psave,ifin,pos,&template_page,&ifadd,&count,turn);//�㾭��ģ��
			        break;
			case 8: page = page_graduate(&x,&info_page,psave,ifin,pos,&template_page,&ifadd,&count,turn);//ѧ��ģ��
			        break;	
			case 9: page = page_award(&x,&info_page,psave,ifin,pos,&template_page,&ifadd,&count,turn);//����ģ��
			        break;		
			//case 10: page = page_person_changecode(usernum);//������
			//        break;
			case 11: page = page_info(info_page,psave,ifin,template_page);//������Ϣ
			         break;		
			case 12: page = page_add(pos,template_page,&ifadd);
			         break;
			case 13 : page = make_list(pchoose,turn);
			          break;	
			case 14 : page = turn_list(pchoose,turn);
			          break;	
			case 15 : page = my_template(&x,pchoose,turn,&info_page,&template_page,ifin,psave,&count);
			          break;	
		     case 16 : page = page_useinfo(&usernum,count);	
			           break;		  	  	  	 					
		 }
	 }
	return 0;
}
