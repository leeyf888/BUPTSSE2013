#include<iostream>
#include <graphics.h>
#include <stdio.h>
#include<fstream>
#include"circle.h"
#include"color.h"
#include"opengraph.h"
#include"point.h"
#include"squareness.h"
#include"delta.h"
#include"draw.h"
#include <math.h>
#include"draw anything.h"
using namespace std;

void draw(Draw *shap){shap -> draw();}

int main(){
	Opengraph();
	setfont(30,15,"����");
	setcolor(BLACK);
	setbkcolor(WHITE);
	ofstream write;
	int menu = 0;
	int fu = 0,ser = 0,serv = 0;//��긨��
	int type;//Ĭ��ͼ������ָ��
	double cx = 0,cy = 0,cr = 0;Color ci;int cxc,cyc,cdr,ccolor=0;ci.fill = 0;ci.color = BLACK;//Բ��Ϣ
	double dx1 = 0,dy1 = 0,dx2 = 0,dy2 = 0,dx3 = 0,dy3 = 0;Color de;int dcolor=0;de.fill = 0;de.color = BLACK;//��������Ϣ
	double sx1 = 0,sy1 = 0,sx2 = 0,sy2 = 0;Color sq;int sxs,sys,scolor=0;sq.fill = 0;sq.color = BLACK;//������Ϣ
	
	for ( ; is_run(); delay_fps(60))
	{
		mouse_msg msg = {0};
		mousepos(&msg.x,&msg.y);
		cleardevice();
		while (mousemsg()){msg = getmouse();}
		if(menu==0){//���˵�
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 80 && msg.y >= 40 )
			{
				line(30,75,120,75);
				if(msg.is_left() && msg.is_down()){menu = 1;}
			}
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 120 && msg.y >= 80 )
			{
				line(30,115,120,115);
				if(msg.is_left() && msg.is_down()){menu = 2;}
			}
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 160 && msg.y >= 120)
			{
				line(30,155,120,155);
				if(msg.is_left() && msg.is_down()){menu = 3;}
			}
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 200 && msg.y >= 160 )
			{
				line(30,195,120,195);
				if(msg.is_left() && msg.is_down()){menu = 4;}
			}
		    outtextxy(0,0,"��ӭ�������׻��壺");
			outtextxy(0,40,"1������");
			outtextxy(0,80,"2������");
			outtextxy(0,120,"3������");
			outtextxy(0,160,"4���˳�");
			
		}
		if(menu==1){//�˵�-����
			outtextxy(0,0,"��ѡ�����ͼ��");
			outtextxy(0,40,"1��Բ");
			outtextxy(0,80,"2��������");
			outtextxy(0,120,"3������");
			outtextxy(0,160,"4���Զ���");
			outtextxy(0,200,"5����ȡ�ļ�");
			outtextxy(0,240,"6���˳�");
			if(msg.x <= 90 && msg.x >= 0 && msg.y <= 80 && msg.y >= 40 )//�˵�-����-ָ��ѯ�ʻ滭��ʽmemu8����ָ��Բ
			{
				line(30,75,90,75);
				if(fu==0 ){
					if(msg.is_left()  && msg.is_up()){fu = 1;}
				}
				if(fu==1 || ser==1){
					if(msg.is_left()  && msg.is_down()){fu = 0;ser = 0;type = 1;menu = 8;}
				}
			}
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 120 && msg.y >= 80 )//�˵�-����-ָ��ѯ�ʻ滭��ʽmemu8����ָ��������
			{
				line(30,115,150,115);
				if(msg.is_left()  && msg.is_down()){type = 2;menu = 8;fu = 0;}
			}
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 160 && msg.y >= 120 )//�˵�-����-ָ��ѯ�ʻ滭��ʽmemu8����ָ�򻭾���
			{
				line(30,155,120,155);
				if(msg.is_left()  && msg.is_down()){type = 3;menu = 8;fu = 0;}
			}
			if(msg.x <= 150 && msg.x >= 0 && msg.y <= 200 && msg.y >= 160 )//�˵�-����-�Զ���
			{
				line(30,195,150,195);
				if(msg.is_left()  && msg.is_down()){menu = 12;fu = 0;}
			}
			if(msg.x <= 180 && msg.x >= 0 && msg.y <= 240 && msg.y >= 200 )//�˵�-����-��ȡ�ļ�
			{
				line(30,235,180,235);
				if(msg.is_left()  && msg.is_down())
				{
					menu = 13;fu=0;
				}
			}
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 280 && msg.y >= 240 )//�˵�-����-���ز˵�
			{
				line(30,275,120,275);
				if(msg.is_left()  && msg.is_down()){menu = 0;fu = 0;ser = 0;}
			}
		}
		
		if(menu==2){//�˵�-����
			if(msg.x <= 570 && msg.x >= 0 && msg.y <= 40 && msg.y >= 0 )
			{
				line(30,35,540,35);
			}
			if(msg.x <= 840 && msg.x >= 0 && msg.y <= 80 && msg.y >= 40 )
			{
				line(30,75,840,75);
			}
			if(msg.x <= 810 && msg.x >= 0 && msg.y <= 160 && msg.y >= 80 )
			{
				line(30,115,780,115);
				line(30,155,660,155);
			}
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 200 && msg.y >= 160 )
			{
				line(30,195,120,195);
				if(msg.is_left()){menu = 0;}
			}
			outtextxy(0,0,"1��������������ṹ��������������");
			outtextxy(0,40,"2����ͼ����������ʽ:��Ĭ��ͼ�΢��Զ����ͼ(�ɱ�����Ϣ)��");
			outtextxy(0,80,"3���Զ����ͼʱ�밴ס���������϶���꣬�ó���Ӧͼ��");
			outtextxy(30,120,"����������ʱֻ�谴��������ȷ���������㣩��");
			outtextxy(0,160,"4���˳�");
		}
		if(menu==3){//�˵�-����
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 40 && msg.y >= 0 )
			{
				line(30,35,170,35);
			}
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 80 && msg.y >= 40 )
			{
				line(30,75,120,75);
				if(msg.is_left()){menu = 0;}
			}
			outtextxy(0,0,"1���ݲ�֧��");
			outtextxy(0,40,"2���˳�");
		}
		if(menu==4){//�˵�-�˳�����
			break;
		}
		if(menu==5){//��Ĭ��Բ
			Circle *circle1 = new Circle();
			draw(circle1);
			ser = 1;
			outtextxy(0,0,"�˳�");
			if(msg.x <= 60 && msg.x >= 0 && msg.y <= 40 && msg.y >= 0 )
			{
				line(0,35,60,35);
				if(msg.is_left() && msg.is_down()){
					delete circle1;
					menu = 1;
				}
			}
		}
		if(menu==6){//��Ĭ��������
		    Delta *delta=new Delta();
			draw(delta);
			outtextxy(0,0,"�˳�");
			if(msg.x <= 60 && msg.x >= 0 && msg.y <= 40 && msg.y >= 0 )
			{
				line(0,35,60,35);
				if(msg.is_left() && msg.is_down()){
					delete delta;
					menu = 1;
				}
			}
		}
		if(menu==7){//��Ĭ�Ͼ���
			Squareness *squ = new Squareness();
			draw(squ);
			outtextxy(0,0,"�˳�");
			if(msg.x <= 60 && msg.x >= 0 && msg.y <= 40 && msg.y >= 0 )
			{
				line(0,35,60,35);
				if(msg.is_left() && msg.is_down()){
					delete squ;
					menu = 1;
				}
			}
		}
		
		if(menu==8){//�˵�-����-ѯ�ʻ滭��ʽ
			outtextxy(0,0,"��ѡ��滭��ʽ��");
		    outtextxy(0,40,"1��Ĭ��ͼ��");
			outtextxy(0,80,"2���Զ�������");
			outtextxy(0,120,"3���˳�");
			if(msg.x <= 180 && msg.x >= 0 && msg.y <= 80 && msg.y >= 40 )//�˵�-����-ѯ�ʻ滭��ʽ-Ĭ��ͼ��
			{
				line(30,75,180,75);
				if(fu==0){
					if(msg.is_left()  && msg.is_up()){fu = 1;}
				}
				if(fu==1){
					if(msg.is_left()  && msg.is_down()){
						fu = 0;
						if(type==1){menu = 5;}
						if(type==2){menu = 6;}
						if(type==3){menu = 7;}
					}
				}
			}
			if(msg.x <= 210 && msg.x >= 0 && msg.y <= 120 && msg.y >= 80 )//�˵�-����-ѯ�ʻ滭��ʽ-�Զ�������
			{
				line(30,115,210,115);
				if(fu==0){
					if(msg.is_left()  && msg.is_up()){fu = 1;}
				}
				if(fu==1){
				    if(msg.is_left()  && msg.is_down()){
						fu = 0;
					    if(type==1){menu = 9;}
						if(type==2){menu = 10;}
						if(type==3){menu = 11;}
				    }
				}
			}
			if(msg.x <= 120 && msg.x >= 0 && msg.y <= 160 && msg.y >= 120 )//�˵�-����-ѯ�ʻ滭��ʽ-��������
			{
				line(30,155,120,155);
				if(fu==0){
					if(msg.is_left()  && msg.is_up()){fu = 1;}
				}
				if(fu==1){
					if(msg.is_left()  && msg.is_down()){ser = 1;fu = 0;menu = 1;}
				}
			}
		}
		if(menu==9){//�Զ��廭Բ
			outtextxy(0,0,"��ס������,�϶����ó�ͼ��");
			outtextxy(0,40,"1�������ػ�");
			outtextxy(0,80,"2���˳�");
			setfillcolor(BLACK);
			bar(0,116,90,155);
			outtextxy(15,120,"��ɫ");
			rectangle(0,155,90,195);
			outtextxy(15,160,"��ɫ");
			setfillcolor(RED);
			bar(0,195,90,235);
			outtextxy(15,200,"��ɫ");
			setfillcolor(BLUE);
			bar(0,235,90,275);
			outtextxy(15,240,"��ɫ");
			setfillcolor(YELLOW);
			bar(0,275,90,315);
			outtextxy(15,280,"��ɫ");
			rectangle(0,315,92,355);
			outtextxy(0,320,"�����");
			outtextxy(0,360,"��ѡ��");
			outtextxy(0,400,"������");
		    outtextxy(0,440,"ɫ���");
			if(fu==0&&serv==0){if(msg.is_left()  && msg.is_up()){serv = 1;}}
			if(fu==0&&serv==1){if(msg.is_down()){cx = msg.x;cy = msg.y;fu = 1;}}
			if(fu==1){
			    cleardevice();
			    mousepos(&cxc,&cyc);
				cr = sqrt((cxc-cx)*(cxc-cx) + (cyc-cy)*(cyc-cy));
				Circle *cia = new Circle(cx,cy,cr,0,BLACK);
				draw(cia);
				delete cia;
				outtextxy(0,0,"��ס������,�϶����ó�ͼ��");
			    outtextxy(0,40,"1�������ػ�");
			    outtextxy(0,80,"2���˳�");
				setfillcolor(BLACK);
			    bar(0,116,90,155);
			    outtextxy(15,120,"��ɫ");
			    rectangle(0,155,90,195);
		    	outtextxy(15,160,"��ɫ");
		    	setfillcolor(RED);
		    	bar(0,195,90,235);
		    	outtextxy(15,200,"��ɫ");
		    	setfillcolor(BLUE);
		    	bar(0,235,90,275);
		    	outtextxy(15,240,"��ɫ");
		    	setfillcolor(YELLOW);
			    bar(0,275,90,315);
			    outtextxy(15,280,"��ɫ");
				rectangle(0,315,92,355);
				outtextxy(0,320,"�����");
			    outtextxy(0,360,"��ѡ��");
			    outtextxy(0,400,"������");
		    	outtextxy(0,440,"ɫ���");
				if(msg.is_up()){fu=0;serv=2;}
			}
			Circle *cib = new Circle(cx,cy,cr,ci.fill,ci.color);
			if(serv==2){draw(cib);}
			if (msg.x <= 180 && msg.x >= 0 && msg.y <= 80 && msg.y >= 40)
			{
				line(30,75,180,75);
				if(msg.is_left() && msg.is_down()){
				fu = 0;
				serv = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 155 && msg.y >= 115)
			{
				line(20,148,70,148);
				if(msg.is_left() && msg.is_down()){
				ccolor = 1;
				ci.color = BLACK;
				ci.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 195 && msg.y >= 155)
			{
				line(20,188,70,188);
				if(msg.is_left() && msg.is_down()){
				ccolor = 2;
				ci.color = WHITE;
				ci.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 235 && msg.y >= 195)
			{
				line(20,228,70,228);
				if(msg.is_left() && msg.is_down()){
				ccolor = 3;
				ci.color = RED;
				ci.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 275 && msg.y >= 235)
			{
				line(20,268,70,268);
				if(msg.is_left() && msg.is_down()){
				ccolor = 4;
				ci.color = BLUE;
				ci.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 315 && msg.y >= 275)
			{
				line(20,308,70,308);
				if(msg.is_left() && msg.is_down()){
				ccolor = 5;
				ci.color = YELLOW;
				ci.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 355 && msg.y >= 315)
			{
				line(5,348,85,348);
				if(msg.is_left() && msg.is_down()){
				ccolor = 0;
				ci.color = BLACK;
				ci.fill = 0;
				}
			}
			if(serv == 1 || serv == 2){
			    if(msg.x <= 120 && msg.x >= 0 && msg.y <= 120 && msg.y >= 80 )
			    {
				    line(30,114,120,114);
				    if(msg.is_left() && msg.is_down()){
					menu=1;
					serv=0;
					ser=1;
					write.open("message2.txt",ios::app);
					write<<"1"<<endl;
					write<<cx<<" "<<cy<<" "<<cr<<endl;
					write<<ccolor<<" "<<ci.fill<<endl;
					write.close();
					cx = cy = cr = 0;
					delete cib;
				    }
			     }
			}
		}
		if(menu==10){//�Զ��廭������
			outtextxy(0,0,"������������ȷ����������");
			outtextxy(0,40,"1�������ػ�");
			outtextxy(0,80,"2���˳�");
			setfillcolor(BLACK);
			bar(0,116,90,155);
			outtextxy(15,120,"��ɫ");
			rectangle(0,155,90,195);
			outtextxy(15,160,"��ɫ");
			setfillcolor(RED);
			bar(0,195,90,235);
			outtextxy(15,200,"��ɫ");
			setfillcolor(BLUE);
			bar(0,235,90,275);
			outtextxy(15,240,"��ɫ");
			setfillcolor(YELLOW);
			bar(0,275,90,315);
			outtextxy(15,280,"��ɫ");
			rectangle(0,315,92,355);
			outtextxy(0,320,"�����");
			outtextxy(0,360,"��ѡ��");
			outtextxy(0,400,"������");
		    outtextxy(0,440,"ɫ���");
			setfillcolor(BLACK);
		    fillellipse(dx1,dy1,2,2);
			fillellipse(dx2,dy2,2,2);
			fillellipse(dx3,dy3,2,2);
			if(fu==0&&serv==0){if(msg.is_left()  && msg.is_up()){serv=1;}}
			if(fu==0&&serv==1){if(msg.is_down()){dx1 = msg.x;dy1 = msg.y;fu = 1;}}
			if(fu==1&&serv==1){if(msg.is_up()){serv=2;}}
			if(fu==1&&serv==2){if(msg.is_down()){dx2 = msg.x;dy2 = msg.y;serv = 3;}}
			if(fu==1&&serv==3){if(msg.is_up()){serv = 4;}}
			if(fu==1&&serv==4){if(msg.is_down()){dx3 = msg.x;dy3 = msg.y;serv = 5;}}
			Delta *delta = new Delta(dx1,dy1,dx2,dy2,dx3,dy3,de.fill,de.color);
			if(serv==5){draw(delta);}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 155 && msg.y >= 115)
			{
				line(20,148,70,148);
				if(msg.is_left() && msg.is_down()){
				dcolor = 1;
				de.color = BLACK;
				de.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 195 && msg.y >= 155)
			{
				line(20,188,70,188);
				if(msg.is_left() && msg.is_down()){
				dcolor = 2;
				de.color = WHITE;
				de.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 235 && msg.y >= 195)
			{
				line(20,228,70,228);
				if(msg.is_left() && msg.is_down()){
				dcolor = 3;
				de.color = RED;
				de.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 275 && msg.y >= 235)
			{
				line(20,268,70,268);
				if(msg.is_left() && msg.is_down()){
				dcolor = 4;
				de.color = BLUE;
				de.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 315 && msg.y >= 275)
			{
				line(20,308,70,308);
				if(msg.is_left() && msg.is_down()){
				dcolor = 5;
				de.color = YELLOW;
				de.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 355 && msg.y >= 315)
			{
				line(5,348,85,348);
				if(msg.is_left() && msg.is_down()){
				dcolor = 0;
				de.color = BLACK;
				de.fill = 0;
				}
			}
			if (msg.x <= 180 && msg.x >= 0 && msg.y <= 80 && msg.y >= 40)
			{
				line(30,75,180,75);
				if(msg.is_left() && msg.is_down())
				{
				    dx1 = dy1 = dx2 = dy2 = dx3 = dy3 = 0;
				    fu = 0;
				    serv = 1;
				}
			}
			if(serv == 1 || serv == 2 || serv == 3 || serv == 4 || serv == 5){
			    if(msg.x <= 120 && msg.x >= 0 && msg.y <= 120 && msg.y >= 80 )
			    {
				    line(30,115,120,115);
				    if(msg.is_left() && msg.is_down()){
					menu = 1;
					serv = 0;
					ser = 1;
					write.open("message2.txt",ios::app);
					write<<"2"<<endl;
					write<<dx1<<" "<<dy1<<" "<<dx2<<" "<<dy2<<" "<<dx3<<" "<<dy3<<endl;
					write<<dcolor<<" "<<de.fill<<endl;
					write.close();
					dx1 = dy1 = dx2 = dy2 = dx3 = dy3 = 0;
					delete delta;
				    }
			     }
			}
		}
		if(menu==11){//�Զ��廭����
			outtextxy(0,0,"��ס������,�϶����ó�ͼ��");
			outtextxy(0,40,"1�������ػ�");
			outtextxy(0,80,"2���˳�");
			setfillcolor(BLACK);
			bar(0,116,90,155);
			outtextxy(15,120,"��ɫ");
			rectangle(0,155,90,195);
		    outtextxy(15,160,"��ɫ");
		    setfillcolor(RED);
		    bar(0,195,90,235);
		    outtextxy(15,200,"��ɫ");
		    setfillcolor(BLUE);
		    bar(0,235,90,275);
		    outtextxy(15,240,"��ɫ");
		    setfillcolor(YELLOW);
			bar(0,275,90,315);
			outtextxy(15,280,"��ɫ");
			rectangle(0,315,92,355);
			outtextxy(0,320,"�����");
			outtextxy(0,360,"��ѡ��");
			outtextxy(0,400,"������");
		    outtextxy(0,440,"ɫ���");
			if(fu==0&&serv==0){if(msg.is_left()  && msg.is_up()){serv = 1;}}
			if(fu==0&&serv==1){if(msg.is_down()){sx1 = msg.x;sy1 = msg.y;fu = 1;}}
			if(fu==1){
			    cleardevice();
			    mousepos(&sxs,&sys);
				sx2 = sxs;
				sy2 = sys;
				Squareness *squa = new Squareness(sx1,sy1,sx2,sy2,0,BLACK);
				draw(squa);
				delete squa;
				outtextxy(0,0,"��ס������,�϶����ó�ͼ��");
			    outtextxy(0,40,"1�������ػ�");
			    outtextxy(0,80,"2���˳�");
				setfillcolor(BLACK);
			    bar(0,116,90,155);
			    outtextxy(15,120,"��ɫ");
			    rectangle(0,155,90,195);
		    	outtextxy(15,160,"��ɫ");
		    	setfillcolor(RED);
		    	bar(0,195,90,235);
		    	outtextxy(15,200,"��ɫ");
		    	setfillcolor(BLUE);
		    	bar(0,235,90,275);
		    	outtextxy(15,240,"��ɫ");
		    	setfillcolor(YELLOW);
			    bar(0,275,90,315);
			    outtextxy(15,280,"��ɫ");
				rectangle(0,315,92,355);
				outtextxy(0,320,"�����");
			    outtextxy(0,360,"��ѡ��");
			    outtextxy(0,400,"������");
		    	outtextxy(0,440,"ɫ���");
				if(msg.is_up()){fu=0;serv=2;}
			}
			Squareness *squb = new Squareness(sx1,sy1,sx2,sy2,sq.fill,sq.color);
			if(serv==2){draw(squb);}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 155 && msg.y >= 115)
			{
				line(20,148,70,148);
				if(msg.is_left() && msg.is_down()){
				scolor = 1;
				sq.color = BLACK;
				sq.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 195 && msg.y >= 155)
			{
				line(20,188,70,188);
				if(msg.is_left() && msg.is_down()){
				scolor = 2;
				sq.color = WHITE;
				sq.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 235 && msg.y >= 195)
			{
				line(20,228,70,228);
				if(msg.is_left() && msg.is_down()){
				scolor = 3;
				sq.color = RED;
				sq.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 275 && msg.y >= 235)
			{
				line(20,268,70,268);
				if(msg.is_left() && msg.is_down()){
				scolor = 4;
				sq.color = BLUE;
				sq.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 315 && msg.y >= 275)
			{
				line(20,308,70,308);
				if(msg.is_left() && msg.is_down()){
				scolor = 5;
				sq.color = YELLOW;
				sq.fill = 1;
				}
			}
			if (msg.x <= 90 && msg.x >= 0 && msg.y <= 355 && msg.y >= 315)
			{
				line(5,348,85,348);
				if(msg.is_left() && msg.is_down()){
				scolor = 0;
				sq.color = BLACK;
				sq.fill = 0;
				}
			}
			if (msg.x <= 180 && msg.x >= 0 && msg.y <= 80 && msg.y >= 40)
			{
				line(30,75,180,75);
				if(msg.is_left() && msg.is_down()){
				    fu = 0;
				    serv = 1;
				}
			}
			if(serv == 1 || serv == 2){
			    if(msg.x <= 120 && msg.x >= 0 && msg.y <= 120 && msg.y >= 80 )
			    {
				    line(30,115,120,115);
				    if(msg.is_left() && msg.is_down()){
					menu=1;
					serv=0;
					ser=1;
					write.open("message2.txt",ios::app);
					write<<"3"<<endl;
					write<<sx1<<" "<<sy1<<" "<<sx2<<" "<<sy2<<endl;
					write<<scolor<<" "<<sq.fill<<endl;
					write.close();
					sx1 = sx2 = sy1 = sy2 = 0;
					delete squb;
				    }
			     }
			}
		}
		if(menu == 12){
			menu = drawany();
			setfont(30,15,"����");
		}
		if(menu == 13)//�˵�-����-��ȡ�ļ�
		{
			ifstream read;
			read.open("message.txt");
			if(read.fail())//�˵�-����-��ȡ�ļ�-�鿴�ļ��Ƿ����
			{
				cleardevice();
				outtextxy(0,0,"�ļ�������");
				delay_ms(2000);
				menu = 1;
			}
			else{
				while(!read.eof()){
					read >> type;
					if(type > 3 || type <=0)
					{
						cleardevice();
						outtextxy(0,0,"ͼ��������Ϣ�����޷���ȡ");
						delay_ms(2000);
						type = 0;
						menu = 1;
					}
					else
					{
						if(type==1)//�˵�-����-��ȡ�ļ�-��ȡԲ��Ϣ
						{
							read>>cx>>cy>>cr;
							if(cx == 0 || cy == 0){
								cleardevice();
								outtextxy(0,0,"Բ�������ȡ����Ĭ��Ϊ��100,100��");
								delay_ms(2000);
								cx=cy=100;
							}
							if(cr == 0){
								cleardevice();
								outtextxy(0,0,"Բ�뾶��ȡ����Ĭ��Ϊ50");
								delay_ms(2000);
								cr = 50;
							}
							read>>ccolor>>ci.fill;
							if(ccolor > 5 || ccolor <= 0){
								cleardevice();
								outtextxy(0,0,"Բ�����ɫ��ȡ����Ĭ��ΪBLACK");
								delay_ms(2000);
								ci.color = BLACK;
							}
							else{
								if(ccolor==1)ci.color=BLACK;
								if(ccolor==2)ci.color=WHITE;
								if(ccolor==3)ci.color=RED;
								if(ccolor==4)ci.color=BLUE;
								if(ccolor==5)ci.color=YELLOW;
							}
							if(ci.fill > 1 || ci.fill < 0){
								cleardevice();
								outtextxy(0,0,"Բ�Ƿ�����ȡ����Ĭ��Ϊ��");
								delay_ms(2000);
								ci.fill=0;
							}
						}
						if(type==2)//�˵�-����-��ȡ�ļ�-��ȡ��������Ϣ
						{
							read>>dx1>>dy1>>dx2>>dy2>>dx3>>dy3;
							if(dx1 == 0 || dy1 == 0){
								cleardevice();
								outtextxy(0,0,"�����ε�һ���������ȡ����Ĭ��Ϊ��500,100��");
								delay_ms(2000);
								dx1 = 500;
								dy1 = 100;
							}
							if(dx2 == 0 || dy2 == 0){
								cleardevice();
								outtextxy(0,0,"�����εڶ����������ȡ����Ĭ��Ϊ��600,200��");
								delay_ms(2000);
								dx2 = 600;
								dy2 = 200;
							}
							if(dx3 == 0 || dy3 == 0){
								cleardevice();
								outtextxy(0,0,"�����ε������������ȡ����Ĭ��Ϊ��400,200��");
								delay_ms(2000);
								dx3 = 400;
								dy3 = 200;
							}
							read>>dcolor>>de.fill;
							if(dcolor > 5 || dcolor <=0){
								cleardevice();
								outtextxy(0,0,"�����������ɫ��ȡ����Ĭ��ΪBLACK");
								delay_ms(2000);
								de.color = BLACK;
							}
							else{
								if(dcolor==1)de.color=BLACK;
								if(dcolor==2)de.color=WHITE;
								if(dcolor==3)de.color=RED;
								if(dcolor==4)de.color=BLUE;
								if(dcolor==5)de.color=YELLOW;
							}
							if(de.fill > 1 || de.fill < 0){
								cleardevice();
								outtextxy(0,0,"�������Ƿ�����ȡ����Ĭ��Ϊ��");
								delay_ms(2000);
								de.fill=0;
							}
						}
						if(type==3)//�˵�-����-��ȡ�ļ�-��ȡ������Ϣ
						{
							read>>sx1>>sy1>>sx2>>sy2;
							if(sx1 == 0 || sy1 == 0){
								cleardevice();
								outtextxy(0,0,"���ε�һ���������ȡ����Ĭ��Ϊ��300,300��");
								delay_ms(2000);
								sx1=sy1=300;
							}
							if(sx2 == 0 || sy2 == 0){
								cleardevice();
								outtextxy(0,0,"���εڶ����������ȡ����Ĭ��Ϊ��500,700��");
								delay_ms(2000);
								sx2=500;
								sy2=700;
							}
							read>>scolor>>sq.fill;
							if(scolor > 5 || scolor <= 0){
								cleardevice();
								outtextxy(0,0,"���������ɫ��ȡ����Ĭ��ΪBLACK");
								delay_ms(2000);
								sq.color = BLACK;
							}
							else{
								if(scolor==1)sq.color=BLACK;
								if(scolor==2)sq.color=WHITE;
								if(scolor==3)sq.color=RED;
								if(scolor==4)sq.color=BLUE;
								if(scolor==5)sq.color=YELLOW;
							}
							if(sq.fill > 1 || sq.fill < 0){
								cleardevice();
								outtextxy(0,0,"�����Ƿ�����ȡ����Ĭ��Ϊ��");
								delay_ms(2000);
								sq.fill=0;
							}
						}
					}
				}
			}
			read.close();
			menu=14;
		}
		if(menu == 14)//�˵�-����-��ȡ�ļ�-���ͼ��
		{
			Circle *ciacleb = new Circle(cx,cy,cr,ci.fill,ci.color);
			draw(ciacleb);
			Delta *deltaa = new Delta(dx1,dy1,dx2,dy2,dx3,dy3,de.fill,de.color);
			draw(deltaa);
			Squareness *squaa = new Squareness(sx1,sy1,sx2,sy2,sq.fill,sq.color);
			draw(squaa);
			outtextxy(0,0,"�˳�");
			if(msg.x <= 60 && msg.x >= 0 && msg.y <= 40 && msg.y >= 0 )
			{
				line(0,35,60,35);
				if(msg.is_left()){
					menu = 1;
					ser=1;
					delete ciacleb;
					delete deltaa;
					delete squaa;
					cx = cy = cr = 0;ci.color = BLACK;ci.fill = 0;
					dx1= dy1 = dx2 = dy2 = dx3 = dy3 = 0;de.color = BLACK;de.fill = 0;
					sx1= sy1 = sx2 = sy2 = 0;sq.color = BLACK;sq.fill = 0;
				} 
			}
			
		}
}

	 return 0;	
}