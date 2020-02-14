#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h> 
#include<time.h>
//设置颜色
void color(short x) //自定义函根据参数改变颜色   
{
	if (x >= 0 && x <= 15) 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);   
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	/*　　
	0=黑色                8=灰色　　 
  　1=蓝色                9=淡蓝色               　　                         
　　2=绿色                10=淡绿色              　　 
　　3=湖蓝色              11=淡浅绿色     　 
　　4=红色                12=淡红色       　　 
　　5=紫色                13=淡紫色               　　 
　　6=黄色                14=淡黄色             　　 
　　7=白色                15=亮白色
	*/
}
//设置光标位置
void SetPos(int x, int y)

{

	COORD pos;

	HANDLE handle;

	pos.X = x;

	pos.Y = y;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(handle, pos);

}
//产生随机数
int Rand() 

{
	srand((unsigned int)time(NULL));//随机种子
	int i;
	i=rand() % 6 + 1;
	return i;
}
//打印框架
void Print() 

{
	/*━┃┓┗┏┛*/
	
	color(7);

	printf("┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓\n");
	printf("┃  开始  ┃┃  前进  ┃┃  金币- ┃┃  金币+ ┃┃  后退  ┃┃  金币- ┃\n");
	printf("┃        ┃┃        ┃┃        ┃┃        ┃┃        ┃┃        ┃\n");
	printf("┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛\n");
	printf("                                                  ┏━━━━━━━━┓\n");
	printf("                                                  ┃  前进  ┃\n");
	printf("                                                  ┃        ┃\n");
	printf("                                                  ┗━━━━━━━━┛\n");
	printf("┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓\n");
	printf("┃ 金币-  ┃┃  飞跃  ┃┃  后退  ┃┃  金币+ ┃┃ 命运点 ┃┃  金币+ ┃\n");
	printf("┃        ┃┃        ┃┃        ┃┃        ┃┃        ┃┃        ┃\n");
	printf("┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛\n");
	printf("┏━━━━━━━━┓\n");
	printf("┃ 金币+  ┃\n");
	printf("┃        ┃\n");
	printf("┗━━━━━━━━┛\n");
	printf("┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓┏━━━━━━━━┓\n");
	printf("┃ 赌博点 ┃┃  金币- ┃┃  飞跃  ┃┃  金币+ ┃┃  商店  ┃┃  结束  ┃\n");
	printf("┃        ┃┃        ┃┃        ┃┃        ┃┃        ┃┃        ┃\n");
	printf("┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛┗━━━━━━━━┛\n");
}
//打印点
void Print2(int *pot,int skin) {

	SetPos(pot[0], pot[1]);
	printf(" ");
	SetPos(pot[2], pot[3]);
	color(skin);
	printf("■");

}
//打印回馈
void Print3(char *str) {
	SetPos(0, 20);
	color(7);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃%s\n",str);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	system("pause");
}
//文件读写
int File(int *Ftemp,int type) {
	FILE *fr;
	char e[100]= "data.dll";
	int n1[3];
	if ((fr = fopen(e, "r")) == NULL)
	{
		fr = fopen(e, "w+");
		Ftemp[0] = 10;
		Ftemp[1] = 7;
		Ftemp[2] = 1;
		fprintf(fr,"%d %d %d", Ftemp[0], Ftemp[1], Ftemp[2]);
	}
	else if (type==1) {
		fr = fopen(e, "w+");
		fprintf(fr, "%d %d %d", Ftemp[0], Ftemp[1], Ftemp[2]);
	}
	else {
		while ( fscanf(fr,"%d%d%d", &n1[0],&n1[1],&n1[2])!= EOF)
		{
			Ftemp[0] = n1[0];
			Ftemp[1] = n1[1];
			Ftemp[2] = n1[2];
		}	
	}

	fclose(fr);
	return(*Ftemp);
}
//终点函数
void success(int *Ftemp) 
{
	int t = 1;
	SetPos(0, 20);
	color(7);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃到达终点，此次你获得%d\n",Ftemp[0]);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	File(Ftemp,t);
	system("pause");
	system("cls");

	while (1) {
		int i = 0;
		for (i;i < 15;i++) {
			color(i);
			SetPos(45, 13);
			printf("┏━━━━━━━━━━━━━┓\n");
			SetPos(45, 14);
			printf("┃             ┃\n");
			SetPos(45, 15);
			printf("┃   GameOver  ┃");
			SetPos(45, 16);
			printf("┃             ┃\n");
			SetPos(45, 17);
			printf("┗━━━━━━━━━━━━━┛\n");

			system("cls");
		}

		i = 0;
	}
}
//计算点坐标
void PosSet(int *pot,int totStep) 

{	
	pot[0]=pot[2];
	pot[1]=pot[3];

	if (totStep <= 5) {
		pot[2] = 10 * totStep + 3;
		pot[3] = 2;
	}
	else if (totStep == 6) {
		pot[2] = 53;
		pot[3] = 6;
	}
	else if (totStep>6&&totStep<=12) {
		pot[2] = 53-10*(totStep-7);
		pot[3] = 10;
	}
	else if (totStep == 13) {
		pot[2] = 3;
		pot[3] = 14;
	}
	else if (totStep>13 && totStep <= 19) {
		pot[2] = 10 * (totStep-14) + 3;
		pot[3] = 18;
	}
	else if (totStep > 19) {
		pot[2] = 53 -(totStep - 19)*10 ;
		pot[3] = 18;
	}

}
//步数产生
int Step(int totStep,int step) {
	int truestep;

	if((totStep+step)<=19)
		truestep = totStep + step;
	else {
		if ((totStep + step) > 19) {
			truestep = 19 - (totStep + step - 19);
		}
	}
	return truestep;
}
//步数判断
void ToStep(int totStep, int step, int *pot, int temp, int skin) {
	if (temp <= totStep && (temp + step) <= 19) {
		for (;temp <= totStep;temp++) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot,skin);
		}
	}

	else  {
		for (int i = temp; i <= 19;i++) {

			Sleep(500);
			PosSet(pot, i);
			Print2(pot, skin);
		}
		for (int i = 19;i >= totStep;i--) {

			Sleep(500);
			PosSet(pot, i);
			Print2(pot,skin);
		}
	}
}
//特殊点
int Trick(int totStep, int *pot, int temp,int step, int skin) {
	//更改提示语，修改str即可
	//1格前进
	if (totStep == 1) {
		char str[] = "前进两格";
		
		PosSet(pot, totStep);
		Print2(pot, skin);
		Print3(str);

		temp = totStep;
		totStep += 2;

		for (;temp <= totStep;temp++) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}

	}
	//6格前进
	else if (totStep == 6) {
		char str[] = "前进三格";

		for (;temp <= totStep;temp++) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}

		Print3(str);

		temp = totStep;
		totStep += 3;

		for (;temp <= totStep;temp++) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}
	}
	//4格倒退
	else if (totStep == 4) {
		char str[] = "后退两格";
		for (;temp <= totStep;temp++) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}

		Print3(str);

		temp = totStep;
		totStep -= 2;

		for (;temp >= totStep;temp--) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}
	}
	//10格倒退
	else if (totStep == 10) {
		char str[] = "倒退三格";
		for (;temp <= totStep;temp++) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}

		Print3(str);

		temp = totStep;
		totStep -= 3;

		for (;temp >= totStep;temp--) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}
	}
	//11格飞跃
	else if (totStep ==11) {
		char str[] = "奖励：到达最后一格";
		for (;temp <= totStep;temp++) {
			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}
		
		totStep = 18;
		PosSet(pot, totStep);
		Print3(str);
		Print2(pot,skin);
		
	}
	//16格飞跃
	else if (totStep == 16) {

		ToStep(totStep, step, pot, temp, skin);
		char str[] = "奖励：回到原点";
		Print3(str);
		totStep = 0;
		PosSet(pot, totStep);
	}
	//8命运点
	else if (totStep == 8) {
		int i;
		char str[] = "请继续掷色子，若为偶数则前进5格，若为奇数则返回原点";
		for (;temp <= totStep;temp++) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}

		Print3(str);

		i = Rand();

		if (i%2==1) {
			SetPos(1, 21);
			printf("                很不幸您掷到了%d            \n\n",i);
			system("pause");

			totStep = 0;
			PosSet(pot, totStep);
		}
		else {

			SetPos(1, 21);
			printf("             恭喜您掷到了%d，前进5步                 \n\n", i);
			system("pause");

			temp = totStep;
			totStep += 5;

			for (;temp <= totStep;temp++) {

				Sleep(500);
				PosSet(pot, temp);
				Print2(pot, skin);
			}
		}		
	}
	//其余
	else {
		ToStep(totStep, step, pot, temp, skin);
		SetPos(0, 20);
		color(7);
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	}
	return totStep;
}
//金币点
int Money(int totStep,int totmomey) {

	if (totStep == 2) {
		totmomey -= 5;
		SetPos(1, 21);
		color(4);
		printf("                         $-5                     \n\n");
		color(7);
		system("pause");
		
	}
	else if (totStep==3) {
		totmomey += 20;
		SetPos(1, 21);
		color(2);
		printf("                         $+20                    \n\n");
		color(7);
		system("pause");
	}
	else if (totStep == 5) {
		totmomey -= 10;
		SetPos(1, 21);
		color(4);
		printf("                         $-10                    \n\n");
		color(7);
		system("pause");
	}
	else if (totStep == 7) {
		totmomey += 15;
		SetPos(1, 21);
		color(2);
		printf("                         $+15                    \n\n");
		color(7);
		system("pause");
	}
	else if (totStep == 9) {
		totmomey += 25;
		SetPos(1, 21);
		color(2);
		printf("                         $+25                    \n\n");
		color(7);
		system("pause");
	}
	else if (totStep == 12) {
		totmomey -= 10;
		SetPos(1, 21);
		color(4);
		printf("                         $-10                    \n\n");
		color(7);
		system("pause");
	}
	else if (totStep == 13) {
		totmomey += 25;
		SetPos(1, 21);
		color(2);
		printf("                         $+15                    \n\n");
		color(7);
		system("pause");
	}
	else if (totStep == 15) {
		totmomey -= 15;
		SetPos(1, 21);
		color(4);
		printf("                         $-15                    \n\n");
		color(7);
		system("pause");
	}
	else if (totStep == 17) {
		totmomey += 25;
		SetPos(1, 21);
		color(2);
		printf("                         $+25                    \n\n");
		color(7);
		system("pause");
	}
	else if (totStep == 14) {
		int i = Rand();

		SetPos(1, 21);
		color(7);
		printf("欢迎！您得到的金币=10*色子点数\n\n");
		system("pause");

		SetPos(1, 21);
		printf("您掷到了%d点，得到%d个金币\n\n", i, 10 * i);
		system("pause");

		totmomey += 10 * i;
	}
	return (totmomey);
}
//皮肤购买
int SkinShop(int totmony, int skin, int *Stemp, int i) {
	if (totmony >= 100 * i && i == 1 && skin!=1)
		{
			skin = 1;
			totmony -= 100 * i;
			Stemp[0] = totmony;
			Stemp[1] = skin;
			printf("\n购买成功！\n\n");
			system("pause");
		}
	else if (totmony >= 100 * i && i ==7 && skin != 15 && skin == 6)
	{
		skin = 15;
		totmony -= 100 * i;
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n购买成功！\n\n");
		system("pause");
	}
	else if ( i == 7 && skin != 6)
	{
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n您无权购买！\n\n");
		system("pause");
	}
	else if (totmony >= 100 * i && i==skin+1 && skin != 7) {
		skin = i;
		totmony -= 100 * i;
		Stemp[0]=totmony;
		Stemp[1]=skin;
		printf("\n购买成功！\n\n");
		system("pause");
	}
	else if ( i > skin + 1 && skin != 7)
	{
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n您无权购买！\n\n");
		system("pause");
	}
	else if (i >1 && skin == 7)
	{
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n您无权购买！\n\n");
		system("pause");
	}
	else if ( i <= skin && skin != 7)
	{
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n您已经拥有！\n\n");
		system("pause");
	}

	else {
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n您余额不足！\n\n");
		system("pause");
	}
	return(*Stemp);
}
//商店
int Shop(int totmony,int skin,int *Stemp) {

	SetPos(1, 21);
	color(7);
	printf("                        到达商店！\n\n");
	system("pause");
	system("cls");
	int i;
	printf("┏━━━━━━━━━━━━━━━━━━━━━ 商店━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃━━━━━━━━━ 皮肤━━━━━━━━━┃━━━━━━━━━ 称号━━━━━━━━━┃\n");
	printf("┃");printf("                       ┃                       ┃\n");
	printf("┃1.");color(1);printf("■");color(7);printf("----------蓝色,$100┃        尽情期待       ┃\n");
	printf("┃");printf("                       ┃                       ┃\n");
	printf("┃2.");color(2);printf("■");color(7);printf("----------绿色,$200┃                       ┃\n");
	printf("┃");printf("                       ┃                       ┃\n");
	printf("┃3.");color(3);printf("■");color(7);printf("----------湖蓝,$300┃                       ┃\n");
	printf("┃");printf("                       ┃                       ┃\n");
	printf("┃4.");color(4);printf("■");color(7);printf("----------红色,$400┃                       ┃\n");
	printf("┃");printf("                       ┃                       ┃\n");
	printf("┃5.");color(5);printf("■");color(7);printf("----------紫色,$500┃                       ┃\n");
	printf("┃");printf("                       ┃                       ┃\n");
	printf("┃6.");color(6);printf("■");color(7);printf("----------黄色,$600┃                       ┃\n");
	printf("┃");printf("                       ┃                       ┃\n");
	printf("┃7.");color(15);printf("■");color(7);printf("----------亮白,$700┃                       ┃\n");
	printf("┃");printf("                       ┃                       ┃\n");
	printf("┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
	printf("┃");printf(" 你现在有金币%d，注：不能越级购买\n",totmony);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("请输入序号购买,输入9退出：");
	scanf("%d",&i);
	switch (i)
	{
	case 1: SkinShop(totmony,skin,Stemp,i);return(*Stemp);
	case 2: SkinShop(totmony, skin, Stemp,i);return(*Stemp);
	case 3: SkinShop(totmony, skin, Stemp,i);return(*Stemp);
	case 4: SkinShop(totmony, skin, Stemp,i);return(*Stemp);
	case 5: SkinShop(totmony, skin, Stemp,i);return(*Stemp);
	case 6: SkinShop(totmony, skin, Stemp,i);return(*Stemp);
	case 7: SkinShop(totmony, skin, Stemp,i);return(*Stemp);
	default: {Stemp[0] = totmony;Stemp[1] = skin;}return(*Stemp);
	}
	return(*Stemp);
}

int main() {
	int rand,skin,totplay;
	int totStep = 0, step=0, temp=0,totmomey;
	int pot[4] = { 3,2,3,2 }, Stemp[2] = { 0 }, Ftemp[3] = {0};

	File(Ftemp, 2);
	totmomey = Ftemp[0];
	skin = Ftemp[1];
	totplay = Ftemp[2];

	Print();

	//初始方块
	Print2(pot,skin);

	SetPos(1,22);
	color(7);
	system("pause");

	while (1) {
		system("cls");
		Print();
		Print2(pot,skin);

		SetPos(3, 5);
		color(15);
		printf("你走到%d格", totStep);

		SetPos(33, 5);
		printf("你现在有%d元", totmomey);

		SetPos(12, 13);
		printf("你在进行第%d次游戏，直接关闭将不保存任何数据", totplay);

		SetPos(1, 21);
		color(7);
		printf("\n请输入1继续,2结束游戏：");
		scanf("%d", &rand);

		if (rand == 1) {

			step = Rand();
			temp = totStep;
			totStep = Step(totStep, step);
		
			SetPos(3, 5);
			color(15);
			printf("你掷了%d步", step);

			totStep=Trick(totStep,pot,temp,step,skin);

			totmomey=Money(totStep,totmomey);

			if (totStep==18) {

				Shop(totmomey,skin,Stemp);
				totmomey = Stemp[0];
				skin = Stemp[1];
				
			}

			//终点

			if (totStep == 19) {
				Ftemp[0] = totmomey;
				Ftemp[1] = skin;
				Ftemp[2] = totplay+1;
				success(Ftemp);
			}
		}
		else if(rand==2) {
			int t = 1;
			SetPos(0, 20);
			color(7);
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("┃退出，此次你获得%d\n", totmomey);
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			Ftemp[0] = totmomey;
			Ftemp[1] = skin;
			Ftemp[2] = totplay+1  ;
			File(Ftemp, t);
			system("pause");
			exit(0);
		}
		else{
			SetPos(0, 23);
			printf("输入错误，请重新输入\n");
			system("pause");
		}

	}

	return(0);
}