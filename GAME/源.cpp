#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h> 
#include<time.h>
//������ɫ
void color(short x) //�Զ��庯���ݲ����ı���ɫ   
{
	if (x >= 0 && x <= 15) 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);   
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	/*����
	0=��ɫ                8=��ɫ���� 
  ��1=��ɫ                9=����ɫ               ����                         
����2=��ɫ                10=����ɫ              ���� 
����3=����ɫ              11=��ǳ��ɫ     �� 
����4=��ɫ                12=����ɫ       ���� 
����5=��ɫ                13=����ɫ               ���� 
����6=��ɫ                14=����ɫ             ���� 
����7=��ɫ                15=����ɫ
	*/
}
//���ù��λ��
void SetPos(int x, int y)

{

	COORD pos;

	HANDLE handle;

	pos.X = x;

	pos.Y = y;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(handle, pos);

}
//���������
int Rand() 

{
	srand((unsigned int)time(NULL));//�������
	int i;
	i=rand() % 6 + 1;
	return i;
}
//��ӡ���
void Print() 

{
	/*������������*/
	
	color(7);

	printf("������������������������������������������������������������������������������������������������������������������������\n");
	printf("��  ��ʼ  ����  ǰ��  ����  ���- ����  ���+ ����  ����  ����  ���- ��\n");
	printf("��        ����        ����        ����        ����        ����        ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������\n");
	printf("                                                  ��������������������\n");
	printf("                                                  ��  ǰ��  ��\n");
	printf("                                                  ��        ��\n");
	printf("                                                  ��������������������\n");
	printf("������������������������������������������������������������������������������������������������������������������������\n");
	printf("�� ���-  ����  ��Ծ  ����  ����  ����  ���+ ���� ���˵� ����  ���+ ��\n");
	printf("��        ����        ����        ����        ����        ����        ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������\n");
	printf("��������������������\n");
	printf("�� ���+  ��\n");
	printf("��        ��\n");
	printf("��������������������\n");
	printf("������������������������������������������������������������������������������������������������������������������������\n");
	printf("�� �Ĳ��� ����  ���- ����  ��Ծ  ����  ���+ ����  �̵�  ����  ����  ��\n");
	printf("��        ����        ����        ����        ����        ����        ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������\n");
}
//��ӡ��
void Print2(int *pot,int skin) {

	SetPos(pot[0], pot[1]);
	printf(" ");
	SetPos(pot[2], pot[3]);
	color(skin);
	printf("��");

}
//��ӡ����
void Print3(char *str) {
	SetPos(0, 20);
	color(7);
	printf("������������������������������������������������������������������������������������������������������������������������\n");
	printf("��%s\n",str);
	printf("������������������������������������������������������������������������������������������������������������������������\n");
	system("pause");
}
//�ļ���д
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
//�յ㺯��
void success(int *Ftemp) 
{
	int t = 1;
	SetPos(0, 20);
	color(7);
	printf("������������������������������������������������������������������������������������������������������������������������\n");
	printf("�������յ㣬�˴�����%d\n",Ftemp[0]);
	printf("������������������������������������������������������������������������������������������������������������������������\n");
	File(Ftemp,t);
	system("pause");
	system("cls");

	while (1) {
		int i = 0;
		for (i;i < 15;i++) {
			color(i);
			SetPos(45, 13);
			printf("������������������������������\n");
			SetPos(45, 14);
			printf("��             ��\n");
			SetPos(45, 15);
			printf("��   GameOver  ��");
			SetPos(45, 16);
			printf("��             ��\n");
			SetPos(45, 17);
			printf("������������������������������\n");

			system("cls");
		}

		i = 0;
	}
}
//���������
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
//��������
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
//�����ж�
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
//�����
int Trick(int totStep, int *pot, int temp,int step, int skin) {
	//������ʾ��޸�str����
	//1��ǰ��
	if (totStep == 1) {
		char str[] = "ǰ������";
		
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
	//6��ǰ��
	else if (totStep == 6) {
		char str[] = "ǰ������";

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
	//4����
	else if (totStep == 4) {
		char str[] = "��������";
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
	//10����
	else if (totStep == 10) {
		char str[] = "��������";
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
	//11���Ծ
	else if (totStep ==11) {
		char str[] = "�������������һ��";
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
	//16���Ծ
	else if (totStep == 16) {

		ToStep(totStep, step, pot, temp, skin);
		char str[] = "�������ص�ԭ��";
		Print3(str);
		totStep = 0;
		PosSet(pot, totStep);
	}
	//8���˵�
	else if (totStep == 8) {
		int i;
		char str[] = "�������ɫ�ӣ���Ϊż����ǰ��5����Ϊ�����򷵻�ԭ��";
		for (;temp <= totStep;temp++) {

			Sleep(500);
			PosSet(pot, temp);
			Print2(pot, skin);
		}

		Print3(str);

		i = Rand();

		if (i%2==1) {
			SetPos(1, 21);
			printf("                �ܲ�����������%d            \n\n",i);
			system("pause");

			totStep = 0;
			PosSet(pot, totStep);
		}
		else {

			SetPos(1, 21);
			printf("             ��ϲ��������%d��ǰ��5��                 \n\n", i);
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
	//����
	else {
		ToStep(totStep, step, pot, temp, skin);
		SetPos(0, 20);
		color(7);
		printf("������������������������������������������������������������������������������������������������������������������������\n");
		printf("��\n");
		printf("������������������������������������������������������������������������������������������������������������������������\n");
	}
	return totStep;
}
//��ҵ�
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
		printf("��ӭ�����õ��Ľ��=10*ɫ�ӵ���\n\n");
		system("pause");

		SetPos(1, 21);
		printf("��������%d�㣬�õ�%d�����\n\n", i, 10 * i);
		system("pause");

		totmomey += 10 * i;
	}
	return (totmomey);
}
//Ƥ������
int SkinShop(int totmony, int skin, int *Stemp, int i) {
	if (totmony >= 100 * i && i == 1 && skin!=1)
		{
			skin = 1;
			totmony -= 100 * i;
			Stemp[0] = totmony;
			Stemp[1] = skin;
			printf("\n����ɹ���\n\n");
			system("pause");
		}
	else if (totmony >= 100 * i && i ==7 && skin != 15 && skin == 6)
	{
		skin = 15;
		totmony -= 100 * i;
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n����ɹ���\n\n");
		system("pause");
	}
	else if ( i == 7 && skin != 6)
	{
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n����Ȩ����\n\n");
		system("pause");
	}
	else if (totmony >= 100 * i && i==skin+1 && skin != 7) {
		skin = i;
		totmony -= 100 * i;
		Stemp[0]=totmony;
		Stemp[1]=skin;
		printf("\n����ɹ���\n\n");
		system("pause");
	}
	else if ( i > skin + 1 && skin != 7)
	{
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n����Ȩ����\n\n");
		system("pause");
	}
	else if (i >1 && skin == 7)
	{
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n����Ȩ����\n\n");
		system("pause");
	}
	else if ( i <= skin && skin != 7)
	{
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n���Ѿ�ӵ�У�\n\n");
		system("pause");
	}

	else {
		Stemp[0] = totmony;
		Stemp[1] = skin;
		printf("\n�����㣡\n\n");
		system("pause");
	}
	return(*Stemp);
}
//�̵�
int Shop(int totmony,int skin,int *Stemp) {

	SetPos(1, 21);
	color(7);
	printf("                        �����̵꣡\n\n");
	system("pause");
	system("cls");
	int i;
	printf("�������������������������������������������� �̵ꩥ������������������������������������������\n");
	printf("�������������������� Ƥ���������������������������������������� �ƺũ�������������������\n");
	printf("��");printf("                       ��                       ��\n");
	printf("��1.");color(1);printf("��");color(7);printf("----------��ɫ,$100��        �����ڴ�       ��\n");
	printf("��");printf("                       ��                       ��\n");
	printf("��2.");color(2);printf("��");color(7);printf("----------��ɫ,$200��                       ��\n");
	printf("��");printf("                       ��                       ��\n");
	printf("��3.");color(3);printf("��");color(7);printf("----------����,$300��                       ��\n");
	printf("��");printf("                       ��                       ��\n");
	printf("��4.");color(4);printf("��");color(7);printf("----------��ɫ,$400��                       ��\n");
	printf("��");printf("                       ��                       ��\n");
	printf("��5.");color(5);printf("��");color(7);printf("----------��ɫ,$500��                       ��\n");
	printf("��");printf("                       ��                       ��\n");
	printf("��6.");color(6);printf("��");color(7);printf("----------��ɫ,$600��                       ��\n");
	printf("��");printf("                       ��                       ��\n");
	printf("��7.");color(15);printf("��");color(7);printf("----------����,$700��                       ��\n");
	printf("��");printf("                       ��                       ��\n");
	printf("��������������������������������������������������������������������������������������������������\n");
	printf("��");printf(" �������н��%d��ע������Խ������\n",totmony);
	printf("��������������������������������������������������������������������������������������������������\n");
	printf("��������Ź���,����9�˳���");
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

	//��ʼ����
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
		printf("���ߵ�%d��", totStep);

		SetPos(33, 5);
		printf("��������%dԪ", totmomey);

		SetPos(12, 13);
		printf("���ڽ��е�%d����Ϸ��ֱ�ӹرս��������κ�����", totplay);

		SetPos(1, 21);
		color(7);
		printf("\n������1����,2������Ϸ��");
		scanf("%d", &rand);

		if (rand == 1) {

			step = Rand();
			temp = totStep;
			totStep = Step(totStep, step);
		
			SetPos(3, 5);
			color(15);
			printf("������%d��", step);

			totStep=Trick(totStep,pot,temp,step,skin);

			totmomey=Money(totStep,totmomey);

			if (totStep==18) {

				Shop(totmomey,skin,Stemp);
				totmomey = Stemp[0];
				skin = Stemp[1];
				
			}

			//�յ�

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
			printf("������������������������������������������������������������������������������������������������������������������������\n");
			printf("���˳����˴�����%d\n", totmomey);
			printf("������������������������������������������������������������������������������������������������������������������������\n");
			Ftemp[0] = totmomey;
			Ftemp[1] = skin;
			Ftemp[2] = totplay+1  ;
			File(Ftemp, t);
			system("pause");
			exit(0);
		}
		else{
			SetPos(0, 23);
			printf("�����������������\n");
			system("pause");
		}

	}

	return(0);
}