/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

/* 
	function iDraw() is called again and again by the system.
*/
int ballDirection = 1,db,rn;

int timer1, timer2, timer3, timer4;

int display = 0;

int xp,yp;


char str[100], str2[100];
int len;
int mode;
char p[2000];

int I = 0,J = 0;

int xCord=290,yCord=16,xAxis=236,yAxis=0;

int seconds = 120;

int i=0,j,k,x,y,dx1;

int flagA = 0;

bool showA = true,showB = true,showC = true,showD = true,showE = true,showF = true;
bool showG = true,showH = true,showI = true,showJ = true,showK = true,showL = true;
bool showM = true,showN = true,showO = true,showP = true,showQ = true,showR = true;
bool showS = true,showT = true,showU = true,showV = true,showW = true,showX = true;
bool showz1 = false,showz2 = false,showz3 = false,showz4 = false,showz5 = false,showz6 = false;
bool show31 = true,show32 = true,show33 = true,show34 = true,show35 = true,show36 = true;
bool showbonA1 = true,showbonA2 = true;


bool paddle = true;

char s[1000] = "0", t[500] = "120",L[10] = "0";




int g,num;

struct player{
	char name[50];
	int score;
};
struct player plr[10000],temp;

void topscore(){
	FILE *fp,*fp2;
	int a,y=700;
	char name[500];
	char score[10];
	int u=0;
	
	fp2 = fopen("record2.txt","r");
	fscanf(fp2,"%d",&num);
	fclose(fp2);
	fp = fopen("scoreList.txt","r");
	iSetColor(255,255,255);
	if(num>10){
		for(a=0;a<10;a++){
			fscanf(fp,"%s %d",&name,&u);
			sprintf(score,"%d",u);
			iText(50,y,name);
			iText(500,y,score);
			y-=30;
		}
	}
	else{
		for(a=0;a<num;a++){
			fscanf(fp,"%s %d",&name,&u);
			sprintf(score,"%d",u);
			iText(50,y,name);
			iText(500,y,score);
			y-=30;
		}
	}
	fclose(fp);
	fclose(fp2);
}

void afterSort(int x){
	int j;
	FILE *fp;
	fp = fopen("scoreList.txt","w");
	if(x>10){
		for(j=0;j<10;j++){
			fprintf(fp,"\n%s\t%d",plr[j].name,plr[j].score);
		}
	}
	else{
		for(j=0;j<x;j++){
			fprintf(fp,"\n%s\t%d",plr[j].name,plr[j].score);
		}
	}
	fclose(fp);
}

 void sort(){
    FILE *fp;
	int x=0,y,z;
	fp = fopen("record.txt","r");
	while((fscanf(fp,"%s %d", &plr[x].name,&plr[x].score))!=EOF)
		x++;
	fclose(fp);
	fp = fopen("record2.txt","w");
	fprintf(fp,"%d",num);
	fclose(fp);

	for(y=0;y<(x-1);y++){
		for(z=y+1;z<x;z++){
			if(plr[z].score>plr[y].score){
				temp = plr[y];
				plr[y] = plr[z];
				plr[z] = temp;
			}
		}
	}
	afterSort(x);
}


/*void fileWrite(){
	FILE *fw;
	fw = fopen("record.txt","w+");
	fprintf(fw,"%s %d",str2,i);
}

/*void fileRead(){
	FILE *fr;
	fr = fopen("record.txt","r");
	fscanf(fr,"%s %d",&str2,&i);
	if(display ==5)
		sprintf(p,"%s",str2);
	iText(40,700,p);
}*/


void iDraw()
{
	//place your drawing codes here	
	iClear();

	if(display == 80){
		iShowBMP(0,0,"Ins.bmp");
	}
		
	//bonus display
	if(display == 50){
		iShowBMP(0,0,"bonus.bmp");
	}
	//bonus Level
	if(display == 51){

		if(showbonA1 == true){
			J++;
			if(J == 1)
				iShowBMP(200,672,"Ball1.bmp");
			else if(J ==2)
				iShowBMP(200,672,"Ball2.bmp");
			else if(J == 3)
				iShowBMP(200,672,"Ball3.bmp");
			else if(J == 4)
				iShowBMP(200,672,"Ball4.bmp");
			else if(J == 5)
				iShowBMP(200,672,"Ball5.bmp");
			else if(J == 6)
				iShowBMP(200,672,"Ball6.bmp");
			else if(J == 7)
				iShowBMP(200,672,"Ball7.bmp");
			else if(J == 8)
				iShowBMP(200,672,"Ball8.bmp");
			else if(J == 9)
				iShowBMP(200,672,"Ball9.bmp");
			else if(J == 10)
				iShowBMP(200,672,"Ball10.bmp");
			else if(J == 11)
				iShowBMP(200,672,"Ball11.bmp");

			if(J>=12){
				J = 0;
			}
		}
		

		iShowBMP(635,50,"BonusImage.bmp");
		
		iSetColor(255,255,255);
		iLine(600,0,600,800);
		iLine(601,0,601,800);
		iLine(602,0,602,800);
		iLine(603,0,603,800);
		iLine(604,0,604,800);
		iLine(605,0,605,800);

		
		iSetColor(255,255,255);
		iText(700,20 ,"press [P] to pause");
		iText(700,10 ,"press [R] to resume");

		iSetColor(255,255,255);
		iShowBMP(xCord,yCord,"ball.bmp");

		iText(650,750 ,"SCORE: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(s,"%d",i);
		iText(760,750 ,s, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(650,350 ,"PLAYER: " , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(236,36,36);
		sprintf(p,"%s\n", str2);
		iText(750,350,p, GLUT_BITMAP_TIMES_ROMAN_24);

		//paddle
		iSetColor(255,255,255);
		iFilledRectangle(xAxis,yAxis,dx1,16); 

		if(xAxis >= 472){
			xAxis = 472;
		}
		if(xAxis <= 0){
			xAxis = 0;
		}

		iSetColor(255,20,170); //paddle design
		iLine(xAxis,yAxis,xAxis+dx1,yAxis); //paddle design
		iLine(xAxis,yAxis+4,xAxis+dx1,yAxis+4); //paddle design
		iLine(xAxis,yAxis+8,xAxis+dx1,yAxis+8); //paddle design
		iLine(xAxis,yAxis+12,xAxis+dx1,yAxis+12); //paddle design
		iLine(xAxis,yAxis+16,xAxis+dx1,yAxis+16); //paddle design

		iFilledRectangle(xAxis,yAxis,8,16); //paddle design
		iFilledRectangle(xAxis+120,yAxis,8,16); //paddle design

	}

	//Well Done
	if(display == 40){
		iShowBMP(0,0,"WellDone.bmp");

		iSetColor(236,36,36);
		iText(520,570 ,"PLAYER NAME: " , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		sprintf(p,"%s\n", str2);
		iText(705,570,p, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(236,36,36);
		iText(520,540 ,"SCORE: " , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		sprintf(s,"%d",i);
		iText(615,540 ,s, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//Game Over
	if(display == 30){
		iShowBMP(0,0,"GameOver.bmp");
		
		iSetColor(236,36,36);
		iText(250,680 ,"PLAYER NAME: " , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		sprintf(p,"%s\n", str2);
		iText(435,680,p, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(236,36,36);
		iText(250,650 ,"SCORE: " , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		sprintf(s,"%d",i);
		iText(345,650 ,s, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//next Level
	if(display == 20){
		yCord = 16;
		xCord=290;	
		seconds = 120;
		ballDirection = 1;
		iShowBMP(20,150,"thumbsUp.bmp");
		iShowBMP(350,130,"Bravo.bmp");
		iText(500,500, "LEVEL 2",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,480, "press [N] to continue");
	}
	//next Level2
	if(display == 21){
		iShowBMP(20,150,"thumbsUp.bmp");
		iShowBMP(350,130,"Bravo.bmp");
		iText(500,500, "LEVEL 3",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,480, "press [N] to continue");
	}

	//MENU
	if(display == 0){
		iShowBMP(0,0,"start.bmp");
		iShowBMP(350,450,"startGame.bmp");
		iShowBMP(350,250,"TopScore.bmp");
		iShowBMP(350,50,"Instruct.bmp");

		if(xp >= 350 && xp <= 862){
			if(yp >= 450 && yp <= 578){
				iRectangle(350, 450, 512, 128);
				iRectangle(348, 448, 512, 128);
				iRectangle(346, 446, 512, 128);
			}

		}

		if(xp >= 350 && xp <= 862){
			if(yp >= 250 && yp <= 378){
				iRectangle(350, 250, 512, 128);
				iRectangle(348, 248, 512, 128);
				iRectangle(346, 246, 512, 128);
			}
		}
		if(xp >= 350 && xp <= 862){
			if(yp >= 50 && yp <= 178){
				iRectangle(350, 50, 512, 128);
				iRectangle(348, 48, 512, 128);
				iRectangle(346, 46, 512, 128);
			}
		}
	}

	//TOP SCORE LIST
	if(display == 10){
		iText(20,750 ,"LIST OF TOP SCORES" , GLUT_BITMAP_TIMES_ROMAN_24);
		iLine(18,745,275,745);
		iLine(18,742,275,742);
		iText(750,20 ,"Press B to BACK");
		
		topscore();
	}

	//Name input Menu
	if(display == 5){
		
		iShowBMP(0,0,"input.bmp");
	
		
		iSetColor(150, 150, 150);
		iRectangle(50, 250, 250, 30);
		if(mode == 1)
		{
			iSetColor(255, 255, 255);
			iText(55, 260, str);
		}

		iText(20, 400, "Click into the box to Enter Name",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 10, "Press C to START",GLUT_BITMAP_TIMES_ROMAN_24);

			I++;
			if(I==1)
				iShowBMP(550,520,"1.bmp");
			if(I==2)	
				iShowBMP(550,530,"2.bmp");
			if(I==3)
				iShowBMP(550,530,"3.bmp");
			if(I==4)
				iShowBMP(550,530,"4.bmp");
			if(I==5)
				iShowBMP(550,530,"5.bmp");
			if(I==6)
				iShowBMP(550,530,"6.bmp");
			if(I==7)
				iShowBMP(550,530,"7.bmp");
			if(I==8)
				iShowBMP(550,530,"8.bmp");
			if(I==9)
				iShowBMP(550,530,"9.bmp");
			if(I==10)
				iShowBMP(550,530,"10.bmp");
			if(I>=10)
				I = 0;
			
	}



	//LEVEL 1010101010101010101010101010101010101010101010101010100101010100101010101010101010101010101010010101010101010101010101111111111111111111
	if(display == 1){
		//fileWrite();
		//fileRead();

		iSetColor(255,255,255);
		
		//1st row................................................................................................
		if(showA == true){
			//iShowBMP(30,760,"untitled.bmp");
			iFilledRectangle(30,760,90,30);
			iSetColor(0,0,0);
			iRectangle(30,760,90,30);
			iSetColor(255,255,255);

		}
		if(showB == true){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(236,36,36);
			iFilledRectangle(120,760,90,30);
			iSetColor(0,0,0);
			iRectangle(120,760,90,30);
			iSetColor(255,255,255);
		}
		if(showC == true){
			//iShowBMP(210,760,"untitled.bmp");
			iFilledRectangle(210,760,90,30);
			iSetColor(0,0,0);
			iRectangle(210,760,90,30);
			iSetColor(255,255,255);
		}
		if(showD == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,760,90,30);
			iSetColor(0,0,0);
			iRectangle(300,760,90,30);
			iSetColor(255,255,255);
		}
		if(showE == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,760,90,30);
			iSetColor(0,0,0);
			iRectangle(390,760,90,30);
			iSetColor(255,255,255);
		}
		if(showF == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,760,90,30);
			iSetColor(0,0,0);
			iRectangle(480,760,90,30);
			iSetColor(255,255,255);
		}

		//2nd row................................................................................................
		if(showG == true){
			//iShowBMP(30,760,"untitled.bmp");
			iSetColor(236,36,36);
			iFilledRectangle(30,720,90,30);
			iSetColor(0,0,0);
			iRectangle(30,720,90,30);
			iSetColor(255,255,255);

		}
		if(showH == true){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(236,36,36);
			iFilledRectangle(120,720,90,30);
			iSetColor(0,0,0);
			iRectangle(120,720,90,30);
			iSetColor(255,255,255);
		}
		if(showI == true){
			//iShowBMP(210,760,"untitled.bmp");
			iFilledRectangle(210,720,90,30);
			iSetColor(0,0,0);
			iRectangle(210,720,90,30);
			iSetColor(255,255,255);
		}
		if(showJ == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,720,90,30);
			iSetColor(0,0,0);
			iRectangle(300,720,90,30);
			iSetColor(255,255,255);
		}
		if(showK == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,720,90,30);
			iSetColor(0,0,0);
			iRectangle(390,720,90,30);
			iSetColor(255,255,255);
		}
		if(showL == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,720,90,30);
			iSetColor(0,0,0);
			iRectangle(480,720,90,30);
			iSetColor(255,255,255);
		}

		//3rd row...................................................................................................
		if(showM == true){
			//iShowBMP(30,760,"untitled.bmp");
			iFilledRectangle(30,680,90,30);
			iSetColor(0,0,0);
			iRectangle(30,680,90,30);
			iSetColor(255,255,255);

		}
		if(showN == true){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(236,36,36);
			iFilledRectangle(120,680,90,30);
			iSetColor(0,0,0);
			iRectangle(120,680,90,30);
			iSetColor(255,255,255);
		}
		if(showO == true){
			//iShowBMP(210,760,"untitled.bmp");
			iFilledRectangle(210,680,90,30);
			iSetColor(0,0,0);
			iRectangle(210,680,90,30);
			iSetColor(255,255,255);
		}
		if(showP == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,680,90,30);
			iSetColor(0,0,0);
			iRectangle(300,680,90,30);
			iSetColor(255,255,255);
		}
		if(showQ == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,680,90,30);
			iSetColor(0,0,0);
			iRectangle(390,680,90,30);
			iSetColor(255,255,255);
		}
		if(showR == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,680,90,30);
			iSetColor(0,0,0);
			iRectangle(480,680,90,30);
			iSetColor(255,255,255);
		}

		//4th row..............................................................................................
		if(showS == true){
			//iShowBMP(30,760,"untitled.bmp");
			iSetColor(236,36,36);
			iFilledRectangle(30,640,90,30);
			iSetColor(0,0,0);
			iRectangle(30,640,90,30);
			iSetColor(255,255,255);

		}
		if(showT == true){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(236,36,36);
			iFilledRectangle(120,640,90,30);
			iSetColor(0,0,0);
			iRectangle(120,640,90,30);
			iSetColor(255,255,255);
		}
		if(showU == true){
			//iShowBMP(210,760,"untitled.bmp");
			iSetColor(236,36,36);
			iFilledRectangle(210,640,90,30);
			iSetColor(0,0,0);
			iRectangle(210,640,90,30);
			iSetColor(255,255,255);
		}
		if(showV == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,640,90,30);
			iSetColor(0,0,0);
			iRectangle(300,640,90,30);
			iSetColor(255,255,255);
		}
		if(showW == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,640,90,30);
			iSetColor(0,0,0);
			iRectangle(390,640,90,30);
			iSetColor(255,255,255);
		}
		if(showX == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,640,90,30);
			iSetColor(0,0,0);
			iRectangle(480,640,90,30);
			iSetColor(255,255,255);
		}
		else
			//void

		iSetColor(255,255,255);
		iLine(600,0,600,800);
		iLine(601,0,601,800);
		iLine(602,0,602,800);
		iLine(603,0,603,800);
		iLine(604,0,604,800);
		iLine(605,0,605,800);

		iText(650,750 ,"SCORE: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(s,"%d",i);
		iText(760,750 ,s, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(650,650 ,"LEVEL: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(L,"%d",display);
		iText(750,650 ,L, GLUT_BITMAP_TIMES_ROMAN_24);

	
		iText(650,550 ,"TIME: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(t,"%d",seconds);
		iText(750,550 ,t, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(650,350 ,"PLAYER: " , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(236,36,36);
		sprintf(p,"%s\n", str2);
		iText(750,350,p, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255,255,255);
		iText(700,20 ,"press [P] to pause");
		iText(700,10 ,"press [R] to resume");

		iSetColor(255,255,255);
		iShowBMP(xCord,yCord,"ball.bmp");
		//iShowBMP(xAxis,yAxis,"paddle.bmp");

		//paddle
		iFilledRectangle(xAxis,yAxis,dx1,16); 

		if(xAxis >= 472){
			xAxis = 472;
		}
		if(xAxis <= 0){
			xAxis = 0;
		}

		iSetColor(255,20,170); //paddle design
		iLine(xAxis,yAxis,xAxis+dx1,yAxis); //paddle design
		iLine(xAxis,yAxis+4,xAxis+dx1,yAxis+4); //paddle design
		iLine(xAxis,yAxis+8,xAxis+dx1,yAxis+8); //paddle design
		iLine(xAxis,yAxis+12,xAxis+dx1,yAxis+12); //paddle design
		iLine(xAxis,yAxis+16,xAxis+dx1,yAxis+16); //paddle design

		iFilledRectangle(xAxis,yAxis,8,16); //paddle design
		iFilledRectangle(xAxis+120,yAxis,8,16); //paddle design

		if(showA == false && showB == false && showC == false && showD == false && showE == false && showF == false && showG == false && showH == false && showI == false && showJ == false && showK == false && showL == false && showM == false && showN == false && showO == false && showP == false && showQ == false && showR == false && showS == false && showT == false && showU == false && showV == false && showW == false && showX == false){
			if(seconds>=30){
				display = 50;
				seconds = 120;
				xCord=290;
				yCord=16;
				ballDirection = 1;
			}
			else{
				display = 20;
				seconds = 120;
				xCord=290;
				yCord=16;
				ballDirection = 1;
			}
		}
	}

	//Level 2020202202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202022222222222222222222222222222222222222222222222222222222222
	if(display == 2){
		iSetColor(255,255,255);
		
		//1st row................................................................................................
		if(showA == false){
			//iShowBMP(30,760,"untitled.bmp");
			iFilledRectangle(30,760,90,30);
			iSetColor(0,0,0);
			iRectangle(30,760,90,30);
			iSetColor(255,255,255);

		}
		if(showB == false){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(60,70,200);
			iFilledRectangle(120,760,90,30);
			iSetColor(0,0,0);
			iRectangle(120,760,90,30);
			iSetColor(255,255,255);
		}
		if(showC == false){
			//iShowBMP(210,760,"untitled.bmp");
			iFilledRectangle(210,760,90,30);
			iSetColor(0,0,0);
			iRectangle(210,760,90,30);
			iSetColor(255,255,255);
		}
		if(showD == false){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,760,90,30);
			iSetColor(0,0,0);
			iRectangle(300,760,90,30);
			iSetColor(255,255,255);
		}
		if(showE == false){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,760,90,30);
			iSetColor(0,0,0);
			iRectangle(390,760,90,30);
			iSetColor(255,255,255);
		}
		if(showF == false){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,760,90,30);
			iSetColor(0,0,0);
			iRectangle(480,760,90,30);
			iSetColor(255,255,255);
		}

		//2nd row................................................................................................
		if(showG == false){
			//iShowBMP(30,760,"untitled.bmp");
			iSetColor(60,70,200);
			iFilledRectangle(30,720,90,30);
			iSetColor(0,0,0);
			iRectangle(30,720,90,30);
			iSetColor(255,255,255);

		}
		if(showH == false){
			//iShowBMP(120,760,"untitled.bmp");
			iFilledRectangle(120,720,90,30);
			iSetColor(0,0,0);
			iRectangle(120,720,90,30);
			iSetColor(255,255,255);
		}
		if(showI == false){
			//iShowBMP(210,760,"untitled.bmp");
			iSetColor(60,70,200);
			iFilledRectangle(210,720,90,30);
			iSetColor(0,0,0);
			iRectangle(210,720,90,30);
			iSetColor(255,255,255);
		}
		if(showJ == false){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,720,90,30);
			iSetColor(0,0,0);
			iRectangle(300,720,90,30);
			iSetColor(255,255,255);
		}
		if(showK == false){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,720,90,30);
			iSetColor(0,0,0);
			iRectangle(390,720,90,30);
			iSetColor(255,255,255);
		}
		if(showL == false){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,720,90,30);
			iSetColor(0,0,0);
			iRectangle(480,720,90,30);
			iSetColor(255,255,255);
		}

		//3rd row...................................................................................................
		if(showM == false){
			//iShowBMP(30,760,"untitled.bmp");
			iFilledRectangle(30,680,90,30);
			iSetColor(0,0,0);
			iRectangle(30,680,90,30);
			iSetColor(255,255,255);

		}
		if(showN == false){
			//iShowBMP(120,760,"untitled.bmp");
			iFilledRectangle(120,680,90,30);
			iSetColor(0,0,0);
			iRectangle(120,680,90,30);
			iSetColor(255,255,255);
		}
		if(showO == false){
			//iShowBMP(210,760,"untitled.bmp");
			iFilledRectangle(210,680,90,30);
			iSetColor(60,70,200);
			iFilledRectangle(210,680,75,30);
			iSetColor(0,0,0);
			iRectangle(210,680,90,30);
			iSetColor(255,255,255);
		}
		if(showP == false){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,680,90,30);
			iSetColor(0,0,0);
			iRectangle(300,680,90,30);
			iSetColor(255,255,255);
		}
		if(showQ == false){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,680,90,30);
			iSetColor(0,0,0);
			iRectangle(390,680,90,30);
			iSetColor(255,255,255);
		}
		if(showR == false){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,680,90,30);
			iSetColor(0,0,0);
			iRectangle(480,680,90,30);
			iSetColor(255,255,255);
		}

		//4th row..............................................................................................
		if(showS == false){
			//iShowBMP(30,760,"untitled.bmp");
			iFilledRectangle(30,640,90,30);
			iSetColor(0,0,0);
			iRectangle(30,640,90,30);
			iSetColor(255,255,255);

		}
		if(showT == false){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(60,70,200);
			iFilledRectangle(120,640,90,30);
			iSetColor(0,0,0);
			iRectangle(120,640,90,30);
			iSetColor(255,255,255);
		}
		if(showU == false){
			//iShowBMP(210,760,"untitled.bmp");
			iFilledRectangle(210,640,90,30);
			iSetColor(0,0,0);
			iRectangle(210,640,90,30);
			iSetColor(255,255,255);
		}
		if(showV == false){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,640,90,30);
			iSetColor(0,0,0);
			iRectangle(300,640,90,30);
			iSetColor(255,255,255);
		}
		if(showW == false){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,640,90,30);
			iSetColor(0,0,0);
			iRectangle(390,640,90,30);
			iSetColor(255,255,255);
		}
		if(showX == false){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,640,90,30);
			iSetColor(0,0,0);
			iRectangle(480,640,90,30);
			iSetColor(255,255,255);
		}

		//5th Row...................................................................................................................
		if(showz1 == false){
			//iShowBMP(30,760,"untitled.bmp");
			iSetColor(60,70,200);
			iFilledRectangle(30,600,90,30);
			iSetColor(0,0,0);
			iRectangle(30,600,90,30);
			iSetColor(255,255,255);

		}
		if(showz2 == false){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(60,70,200);
			iFilledRectangle(120,600,90,30);
			iSetColor(0,0,0);
			iRectangle(120,600,90,30);
			iSetColor(255,255,255);
		}
		if(showz3 == false){
			//iShowBMP(210,760,"untitled.bmp");
			iSetColor(60,70,200);
			iFilledRectangle(210,600,90,30);
			iSetColor(0,0,0);
			iRectangle(210,600,90,30);
			iSetColor(255,255,255);
		}
		if(showz4 == false){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,600,90,30);
			iSetColor(0,0,0);
			iRectangle(300,600,90,30);
			iSetColor(255,255,255);
		}
		if(showz5 == false){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,600,90,30);
			iSetColor(0,0,0);
			iRectangle(390,600,90,30);
			iSetColor(255,255,255);
		}
		if(showz6 == false){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,600,90,30);
			iSetColor(0,0,0);
			iRectangle(480,600,90,30);
			iSetColor(255,255,255);
		}


		else
			//void

		iSetColor(255,255,255);
		iLine(600,0,600,800);
		iLine(601,0,601,800);
		iLine(602,0,602,800);
		iLine(603,0,603,800);
		iLine(604,0,604,800);
		iLine(605,0,605,800);

		iText(650,750 ,"SCORE: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(s,"%d",i);
		iText(760,750 ,s, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(650,650 ,"LEVEL: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(L,"%d",display);
		iText(750,650 ,L, GLUT_BITMAP_TIMES_ROMAN_24);

	
		iText(650,550 ,"TIME: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(t,"%d",seconds);
		iText(750,550 ,t, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(650,350 ,"PLAYER: " , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(60,70,200);
		sprintf(p,"%s\n", str2);
		iText(750,350,p, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255,255,255);
		iText(700,20 ,"press [P] to pause");
		iText(700,10 ,"press [R] to resume");

		iSetColor(255,255,255);
		iShowBMP(xCord,yCord,"ball.bmp");
		//iShowBMP(xAxis,yAxis,"paddle.bmp");

		//paddle
		iFilledRectangle(xAxis,yAxis,dx1,16); 

		if(xAxis >= 472){
			xAxis = 472;
		}
		if(xAxis <= 0){
			xAxis = 0;
		}

		iSetColor(30,180,255); //paddle design
		iLine(xAxis,yAxis,xAxis+dx1,yAxis); //paddle design
		iLine(xAxis,yAxis+4,xAxis+dx1,yAxis+4); //paddle design
		iLine(xAxis,yAxis+8,xAxis+dx1,yAxis+8); //paddle design
		iLine(xAxis,yAxis+12,xAxis+dx1,yAxis+12); //paddle design
		iLine(xAxis,yAxis+16,xAxis+dx1,yAxis+16); //paddle design

		iFilledRectangle(xAxis,yAxis,8,16); //paddle design
		iFilledRectangle(xAxis+120,yAxis,8,16); //paddle design

		if(showA == true && showB == true && showC == true && showD == true && showE == true && showF == true && showG == true && showH == true && showI == true && showJ == true && showK == true && showL == true && showM == true && showN == true && showO == true && showP == true && showQ == true && showR == true && showS == true && showT == true && showU == true && showV == true && showW == true && showX == true && showz1 == true && showz2 == true && showz3 == true && showz4 == true && showz5 == true && showz6 == true){
			display = 21;
			seconds = 120;
			xCord=290;
			yCord=16;
			ballDirection = 1;
		}
	
	}

	//LEVEL 3030303030303030303030303303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030
	if(display == 3){
		iSetColor(255,255,255);
		
		//1st row................................................................................................
		if(showA == true){
			//iShowBMP(30,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(30,760,90,30);
			iSetColor(0,0,0);
			iRectangle(30,760,90,30);
			iSetColor(255,255,255);

		}
		if(showB == true){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(120,760,90,30);
			iSetColor(0,0,0);
			iRectangle(120,760,90,30);
			iSetColor(255,255,255);
		}
		if(showC == true){
			//iShowBMP(210,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(210,760,90,30);
			iSetColor(0,0,0);
			iRectangle(210,760,90,30);
			iSetColor(255,255,255);
		}
		if(showD == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,760,90,30);
			iSetColor(0,0,0);
			iRectangle(300,760,90,30);
			iSetColor(255,255,255);
		}
		if(showE == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,760,90,30);
			iSetColor(0,0,0);
			iRectangle(390,760,90,30);
			iSetColor(255,255,255);
		}
		if(showF == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,760,90,30);
			iSetColor(0,0,0);
			iRectangle(480,760,90,30);
			iSetColor(255,255,255);
		}

		//2nd row................................................................................................
		if(showG == true){
			//iShowBMP(30,760,"untitled.bmp");
			iFilledRectangle(30,720,90,30);
			iSetColor(0,0,0);
			iRectangle(30,720,90,30);
			iSetColor(255,255,255);

		}
		if(showH == true){
			//iShowBMP(120,760,"untitled.bmp");
			iFilledRectangle(120,720,90,30);
			iSetColor(0,0,0);
			iRectangle(120,720,90,30);
			iSetColor(255,255,255);
		}
		if(showI == true){
			//iShowBMP(210,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(210,720,90,30);
			iSetColor(0,0,0);
			iRectangle(210,720,90,30);
			iSetColor(255,255,255);
		}
		if(showJ == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,720,90,30);
			iSetColor(0,0,0);
			iRectangle(300,720,90,30);
			iSetColor(255,255,255);
		}
		if(showK == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,720,90,30);
			iSetColor(0,0,0);
			iRectangle(390,720,90,30);
			iSetColor(255,255,255);
		}
		if(showL == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,720,90,30);
			iSetColor(0,0,0);
			iRectangle(480,720,90,30);
			iSetColor(255,255,255);
		}

		//3rd row...................................................................................................
		if(showM == true){
			//iShowBMP(30,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(30,680,90,30);
			iSetColor(0,0,0);
			iRectangle(30,680,90,30);
			iSetColor(255,255,255);

		}
		if(showN == true){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(120,680,90,30);
			iSetColor(0,0,0);
			iRectangle(120,680,90,30);
			iSetColor(255,255,255);
		}
		if(showO == true){
			//iShowBMP(210,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(210,680,90,30);
			iSetColor(0,0,0);
			iRectangle(210,680,90,30);
			iSetColor(255,255,255);
		}
		if(showP == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,680,90,30);
			iSetColor(0,0,0);
			iRectangle(300,680,90,30);
			iSetColor(255,255,255);
		}
		if(showQ == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,680,90,30);
			iSetColor(0,0,0);
			iRectangle(390,680,90,30);
			iSetColor(255,255,255);
		}
		if(showR == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,680,90,30);
			iSetColor(0,0,0);
			iRectangle(480,680,90,30);
			iSetColor(255,255,255);
		}

		//4th row..............................................................................................
		if(showS == true){
			//iShowBMP(30,760,"untitled.bmp");
			iFilledRectangle(30,640,90,30);
			iSetColor(0,0,0);
			iRectangle(30,640,90,30);
			iSetColor(255,255,255);

		}
		if(showT == true){
			//iShowBMP(120,760,"untitled.bmp");
			iFilledRectangle(120,640,90,30);
			iSetColor(0,0,0);
			iRectangle(120,640,90,30);
			iSetColor(255,255,255);
		}
		if(showU == true){
			//iShowBMP(210,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(210,640,90,30);
			iSetColor(0,0,0);
			iRectangle(210,640,90,30);
			iSetColor(255,255,255);
		}
		if(showV == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,640,90,30);
			iSetColor(0,0,0);
			iRectangle(300,640,90,30);
			iSetColor(255,255,255);
		}
		if(showW == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,640,90,30);
			iSetColor(0,0,0);
			iRectangle(390,640,90,30);
			iSetColor(255,255,255);
		}
		if(showX == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,640,90,30);
			iSetColor(0,0,0);
			iRectangle(480,640,90,30);
			iSetColor(255,255,255);
		}

		//5th Row...................................................................................................................
		if(showz1 == true){
			//iShowBMP(30,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(30,600,90,30);
			iSetColor(0,0,0);
			iRectangle(30,600,90,30);
			iSetColor(255,255,255);

		}
		if(showz2 == true){
			//iShowBMP(120,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(120,600,90,30);
			iSetColor(0,0,0);
			iRectangle(120,600,90,30);
			iSetColor(255,255,255);
		}
		if(showz3 == true){
			//iShowBMP(210,760,"untitled.bmp");
			iSetColor(34,177,76);
			iFilledRectangle(210,600,90,30);
			iSetColor(0,0,0);
			iRectangle(210,600,90,30);
			iSetColor(255,255,255);
		}
		if(showz4 == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,600,90,30);
			iSetColor(0,0,0);
			iRectangle(300,600,90,30);
			iSetColor(255,255,255);
		}
		if(showz5 == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,600,90,30);
			iSetColor(0,0,0);
			iRectangle(390,600,90,30);
			iSetColor(255,255,255);
		}
		if(showz6 == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,600,90,30);
			iSetColor(0,0,0);
			iRectangle(480,600,90,30);
			iSetColor(255,255,255);
		}

		//6th Row........................................................
		if(show31 == true){
			//iShowBMP(30,760,"untitled.bmp");
			iFilledRectangle(30,560,90,30);
			iSetColor(0,0,0);
			iRectangle(30,560,90,30);
			iSetColor(255,255,255);

		}
		if(show32 == true){
			//iShowBMP(120,760,"untitled.bmp");
			iFilledRectangle(120,560,90,30);
			iSetColor(0,0,0);
			iRectangle(120,560,90,30);
			iSetColor(255,255,255);
		}
		if(show33 == true){
			//iShowBMP(210,760,"untitled.bmp");
			iFilledRectangle(210,560,90,30);
			iSetColor(0,0,0);
			iRectangle(210,560,90,30);
			iSetColor(255,255,255);
		}
		if(show34 == true){
			//iShowBMP(300,760,"untitled.bmp");
			iFilledRectangle(300,560,90,30);
			iSetColor(0,0,0);
			iRectangle(300,560,90,30);
			iSetColor(255,255,255);
		}
		if(show35 == true){
			//iShowBMP(390,760,"untitled.bmp");
			iFilledRectangle(390,560,90,30);
			iSetColor(0,0,0);
			iRectangle(390,560,90,30);
			iSetColor(255,255,255);
		}
		if(show36 == true){
			//iShowBMP(480,760,"untitled.bmp");
			iFilledRectangle(480,560,90,30);
			iSetColor(0,0,0);
			iRectangle(480,560,90,30);
			iSetColor(255,255,255);
		}


		else
			//void

		iSetColor(255,255,255);
		iLine(600,0,600,800);
		iLine(601,0,601,800);
		iLine(602,0,602,800);
		iLine(603,0,603,800);
		iLine(604,0,604,800);
		iLine(605,0,605,800);

		iText(650,750 ,"SCORE: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(s,"%d",i);
		iText(760,750 ,s, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(650,650 ,"LEVEL: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(L,"%d",display);
		iText(750,650 ,L, GLUT_BITMAP_TIMES_ROMAN_24);

	
		iText(650,550 ,"TIME: " , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(t,"%d",seconds);
		iText(750,550 ,t, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(650,350 ,"PLAYER: " , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(34,177,76);
		sprintf(p,"%s\n", str2);
		iText(750,350,p, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255,255,255);
		iText(700,20 ,"press [P] to pause");
		iText(700,10 ,"press [R] to resume");

		iSetColor(255,255,255);
		iShowBMP(xCord,yCord,"ball.bmp");
		//iShowBMP(xAxis,yAxis,"paddle.bmp");

		//paddle
		iFilledRectangle(xAxis,yAxis,dx1,16); 

		if(xAxis >= 472){
			xAxis = 472;
		}
		if(xAxis <= 0){
			xAxis = 0;
		}

		iSetColor(180,230,30); //paddle design
		iLine(xAxis,yAxis,xAxis+dx1,yAxis); //paddle design
		iLine(xAxis,yAxis+4,xAxis+dx1,yAxis+4); //paddle design
		iLine(xAxis,yAxis+8,xAxis+dx1,yAxis+8); //paddle design
		iLine(xAxis,yAxis+12,xAxis+dx1,yAxis+12); //paddle design
		iLine(xAxis,yAxis+16,xAxis+dx1,yAxis+16); //paddle design

		iFilledRectangle(xAxis,yAxis,8,16); //paddle design
		iFilledRectangle(xAxis+120,yAxis,8,16); //paddle design

		if(showA == false && showB == false && showC == false && showD == false && showE == false && showF == false && showG == false && showH == false && showI == false && showJ == false && showK == false && showL == false && showM == false && showN == false && showO == false && showP == false && showQ == false && showR == false && showS == false && showT == false && showU == false && showV == false && showW == false && showX == false){
			display = 40;
		}
	
	}
	
}


/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	/*printf("MOVING \n x = %d and y = %d\n",mx,my);
	xCord = mx;
	yCord = my;*/
	
		
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(display == 0){
			if(mx >= 350 && mx <= 862){
				if(my >= 450 && my <= 578){
					display=5 ; 
				}
			}
			if(mx >= 350 && mx <= 862){
				if(my >= 250 && my <= 378){	
					display = 10;
				}
			}
			
			if(xp >= 350 && xp <= 862){
				if(yp >= 50 && yp <= 178){
					display = 80;
				}
			}
		}

		if(display == 5){
			if(mx >= 50 && mx <= 300 && my >= 250 && my <= 280 && mode == 0){
				mode = 1;
			}
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
			/*printf("Right \n x = %d and y = %d\n",mx,my);
			xAxis=mx;
			yAxis=my;*/
			//place your codes here	
	}
}
/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	if(display == 0){
		xp = mx;
		yp = my;
	}

	if(display == 1){
		if(paddle == true)
			xAxis = mx;
		else
			xAxis = xAxis;
	}
	
	if(display == 2){
		if(paddle == true)
			xAxis = mx;
		else
			xAxis = xAxis;
	}

	if(display == 3){
		if(paddle == true)
			xAxis = mx;
		else
			xAxis = xAxis;
	}

	
	if(display == 51){
		if(paddle == true)
			xAxis = mx;
		else
			xAxis = xAxis;
	}
 //if(mx== 2){}        /*Something to do with mx*/
 //else if(my== 2){}   /*Something to do with my*/
 
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iPauseTimer(timer1);
		iPauseTimer(timer2);
		paddle = false;
	}
	if(key == 'r'){
		iResumeTimer(timer1);
		iResumeTimer(timer2);
		paddle = true;
	}

	if(display == 10){
		if(key == 'b'){
			display = 0;
		}
	}

	if(display == 30){
		if(key == 'b')
			display = 0;
	}

	if(display ==5){
		FILE *fp;
		int c;
		if(mode == 1)
		{
			if(key == '\r'){

				mode = 0;
				strcpy(str2, str);
				for(c = 0; c < len; c++)
				str[c] = 0;
				len = 0;
				num++;
			}
			else{
				str[len] = key;
				len++;
			}
		}
	}
	if(display == 5){
		if(key == 'c'){
			display = 1;
		}	
	}
	if(display == 20){
		if(key == 'n')
			display = 2;
	}
	if(display == 21){
		if(key == 'n')
			display = 3;
	}

	if(display == 80){
		if(key == 'b'){
			display = 0;
		}
	}

	if(display == 50){
		if(key == 'n')
			display = 51;
			seconds = 120;
			xCord=290;
			yCord=16;
			ballDirection = 1;
	}
	/*if(display == 51){
		if(key == 'n')
			display = 20;
	}*/
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{
	
	/*if(key == GLUT_KEY_UP){
		yCord += 4;
	}
	if(key == GLUT_KEY_DOWN){
		yCord -= 4;
	}
	if(key == GLUT_KEY_LEFT){
		xAxis -= 4;
	}
	if(key == GLUT_KEY_RIGHT){
		xAxis += 4;
	}*/
	
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}



void ballMovement(){
	FILE *fp;
	if(yCord == 0){
			display = 30;
			yCord=16;
			fp = fopen("record.txt","a");
				fprintf(fp,"%s\t%d\n",str2,i);
				fclose(fp);
				sort();
		}
	//LEVEL-1 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
	if(display==1){
		//row 1,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16 == 760){
			if(xCord+8 >= 30 && xCord+8 <=120 && showA == true){
				if(seconds>0)
					i++;
				showA = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showB == true){
				if(seconds>0)
					i=i+2;
				showB = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showC == true){
				if(seconds>0)
					i++;
				showC = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showD == true){
				if(seconds>0)
					i++;
				showD = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showE == true){
				if(seconds>0)
					i++;
				showE = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=578 && showF == true){
				if(seconds>0)
					i++;
				showF = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}
		if(yCord>760 && yCord<790){
			//LHS...
			if(xCord+16 == 34 && showA == true){
				if(seconds>0)
					i++;
				showA = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showB == true){
				if(seconds>0)
					i=i+2;
				showB = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showC == true){
				if(seconds>0)
					i++;
				showC = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showD == true){
				if(seconds>0)
					i++;
				showD = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 386&& showE == true){
				if(seconds>0)
					i++;
				showE = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 482 && showF == true){
				if(seconds>0)
					i++;
				showF = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
		//RHS...
			if((xCord == 122 || xCord == 114) && showA == true){
				if(seconds>0)
					i++;
				showA = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showB == true){
				if(seconds>0)
					i=i+2;
				showB = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showC == true){
				if(seconds>0)
					i++;
				showD = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showD == true){
				if(seconds>0)
					i++;
				showD = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showE == true){
				if(seconds>0)
					i++;
				showE = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showF == true){
				if(seconds>0)
					i++;
				showF = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		} 

		//printf("%d\n",xCord);

		//row 2,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16 == 720){
			if(xCord+8 >= 30 && xCord+8 <=120 && showG == true){
				if(seconds>0)
					i=i+2;
				showG = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showH == true){
				if(seconds>0)
					i=i+2;
				showH = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showI == true){
				if(seconds>0)
					i++;
				showI = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showJ == true){
				if(seconds>0)
					i++;
				showJ = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showK == true){
				if(seconds>0)
					i++;
				showK = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showL == true){
				if(seconds>0)
					i++;
				showL = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}

		if(yCord+8>720 && yCord<750){
			//LHS...
			if(xCord+16 == 34 && showG == true){
				if(seconds>0)
					i=i+2;
				showG = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showH == true){
				if(seconds>0)
					i=i+2;
				showH = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showI == true){
				if(seconds>0)
					i++;
				showI = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showJ == true){
				if(seconds>0)
					i++;
				showJ = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 386&& showK == true){
				if(seconds>0)
					i++;
				showK = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 482 && showL == true){
				if(seconds>0)
					i++;
				showL = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
		//RHS...
			if((xCord == 122 || xCord == 114) && showG == true){
				if(seconds>0)
					i=i+2;
				showG = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showH == true){
				if(seconds>0)
					i=i+2;
				showH = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showI == true){
				if(seconds>0)
					i++;
				showI = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showJ == true){
				if(seconds>0)
					i++;
				showJ = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showK == true){
				if(seconds>0)
					i++;
				showK = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showL == true){
				if(seconds>0)
					i++;
				showL = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		}

		//UP...
		if(yCord == 750){
			if(xCord+8 >= 30 && xCord+8 <=120 && showG == true){
				if(seconds>0)
					i=i+2;
				showG = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showH == true){
				if(seconds>0)
					i=i+2;
				showH = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showI == true){
				if(seconds>0)
					i++;
				showI = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showJ == true){
				if(seconds>0)
					i++;
				showJ = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showK == true){
				if(seconds>0)
					i++;
				showK = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showL == true){
				if(seconds>0)
					i++;
				showL = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
		}

		//row 3,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16==680){
			if(xCord+8 >= 30 && xCord+8 <=120 && showM == true){
				if(seconds>0)
					i++;
				showM = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showN == true){
				if(seconds>0)
					i=i+2;
				showN = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showO == true){
				if(seconds>0)
					i++;
				showO = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showP == true){
				if(seconds>0)
					i++;
				showP = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showQ == true){
				if(seconds>0)
					i++;
				showQ = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showR == true){
				if(seconds>0)
					i++;
				showR = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}
		//printf("%d\n",yCord+8);
		if(yCord+8>= 680 && yCord+8<= 712){
		//LHS...
			if(xCord+16 == 34 && showM == true){
				if(seconds>0)
					i++;
				showM = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showN == true){
				if(seconds>0)
					i=i+2;
				showN = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showO == true){
				if(seconds>0)
					i++;
				showO = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showP == true){
				if(seconds>0)
					i++;
				showP = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 386&& showQ == true){
				if(seconds>0)
					i++;
				showQ = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 482 && showR == true){
				if(seconds>0)
					i++;
				showR = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
		//RHS...
			if((xCord == 122 || xCord == 114) && showM == true){
				if(seconds>0)
					i++;
				showM = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showN == true){
				if(seconds>0)
					i=i+2;
				showN = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showO == true){
				if(seconds>0)
					i++;
				showO = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showP == true){
				if(seconds>0)
					i++;
				showP = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showQ == true){
				if(seconds>0)
					i++;
				showQ = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showR == true){
				if(seconds>0)
					i++;
				showR = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		} 
		//UP...
		if(yCord == 712){
			if(xCord+8 >= 30 && xCord+8 <=120 && showM == true){
				if(seconds>0)
					i=i+2;
				showM = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showN == true){
				if(seconds>0)
					i++;
				showN = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showO == true){
				if(seconds>0)
					i++;
				showO = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showP == true){
				if(seconds>0)
					i++;
				showP = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showQ == true){
				if(seconds>0)
					i++;
				showQ = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showR == true){
				if(seconds>0)
					i++;
				showR = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
		}



		//row 4,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16 == 640){
			if(xCord+8 >= 30 && xCord+8 <=120 && showS == true){
				if(seconds>0)
					i=i+2;
				showS = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showT == true){
				if(seconds>0)
					i=i+2;
				showT = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showU == true){
				if(seconds>0)
					i=i+2;
				showU = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showV == true){
				if(seconds>0)
					i++;
				showV = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showW == true){
				if(seconds>0)
					i++;
				showW = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showX == true){
				if(seconds>0)
					i++;
				showX = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}
		//printf("%d\n",yCord+8);
		//printf("%d\n",xCord);
		//printf("%d\n",xCord+16);
		if(yCord+8>=640 && yCord+8<=669){
			//LHS...
			if(xCord+16 == 34 && showS == true){
				if(seconds>0)
					i=i+2;
				showS = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showT == true){
				if(seconds>0)
					i=i+2;
				showT = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showU == true){
				if(seconds>0)
					i=i+2;
				showU = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showV == true){
				if(seconds>0)
					i++;
				showV = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if((xCord+16 == 386 || xCord+16 == 378) && showW == true){
				if(seconds>0)
					i++;
				showW = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 474 && showX == true){
				if(seconds>0)
					i++;
				showX = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			//RHS...
			
			if((xCord == 114 || xCord == 122) && showS == true){
				if(seconds>0)
					i=i+2;
				showS = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showT == true){
				if(seconds>0)
					i=i+2;
				showT = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showU == true){
				if(seconds>0)
					i=i+2;
				showU = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showV == true){
				if(seconds>0)
					i++;
				showV = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showW == true){
				if(seconds>0)
					i++;
				showW = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showX == true){
				if(seconds>0)
					i++;
				showX = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		}
		//up...
		if(yCord == 672){
			if(xCord+8 >= 30 && xCord+8 <=120 && showS == true){
				if(seconds>0)
					i=i+2;
				showS = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showT == true){
				if(seconds>0)
					i=i+2;
				showT = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showU == true){
				if(seconds>0)
					i=i+2;
				showU = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showV == true){
				if(seconds>0)
					i++;
				showV = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showW == true){
				if(seconds>0)
					i++;
				showW = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showX == true){
				if(seconds>0)
					i++;
				showX = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}	
		}
		

		if(yCord == 16){
			if(xCord + 8 >= xAxis && xCord + 8 <= xAxis+50)
				ballDirection = 1;
			
			else if(xCord + 8 >= xAxis+50 && xCord + 8 <=xAxis+78)
				ballDirection = 5;
			
			else if(xCord + 8 >= xAxis+78 && xCord + 8 <= xAxis+128)
				ballDirection = 2;
			
		}


		if(xCord <= 0){
			if(ballDirection == 1)
				ballDirection = 2;

			else if(ballDirection == 3)
				ballDirection = 4;
		}

		else if(xCord >= 600-16){
			if(ballDirection == 2)
				ballDirection = 1;
	
			else if(ballDirection == 4)
				ballDirection = 3;
		}

		if(yCord == 800-16){
		
			/*rn = rand()%3+1;

			if(rn == 1){
				ballDirection = 3;
			}
			else if(rn == 2){
				ballDirection = 4;
			}
			else{
				ballDirection = 6;
			}*/
		
			if(ballDirection == 2)
				ballDirection = 4;
			else if(ballDirection == 1)
				ballDirection = 3;
			else if(ballDirection == 5)
				ballDirection = 6;
		}

	
		if(ballDirection == 1){
			xCord -=db;
			yCord +=db;
		}

		if(ballDirection == 2){
			xCord +=db;
			yCord +=db;
		}

		if(ballDirection == 3){
			xCord -=db;
			yCord -=db;
		}

		if(ballDirection == 4){
			xCord +=db;
			yCord -=db;
		}

		if(ballDirection == 5){
			yCord +=db;
		}

		if(ballDirection == 6){
			yCord -=db;
		}
		//printf("%d\n",yCord);

	}


//LEVEL 222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
	if(display == 2){
		if(yCord+16 == 760){
			if(xCord+8 >= 30 && xCord+8 <=120 && showA == false){
				if(seconds>0)
					i++;
				showA = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showB == false){
				if(seconds>0)
					i=i+4;
				showB = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showC == false){
				if(seconds>0)
					i++;
				showC = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showD == false){
				if(seconds>0)
					i++;
				showD = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showE == false){
				if(seconds>0)
					i++;
				showE = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=578 && showF == false){
				if(seconds>0)
					i++;
				showF = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}
		if(yCord>760 && yCord<790){
			//LHS...
			if(xCord+16 == 34 && showA == false){
				if(seconds>0)
					i++;
				showA = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showB == false){
				if(seconds>0)
					i=i+4;
				showB = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showC == false){
				if(seconds>0)
					i++;
				showC = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showD == false){
				if(seconds>0)
					i++;
				showD = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 386&& showE == false){
				if(seconds>0)
					i++;
				showE = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 482 && showF == false){
				if(seconds>0)
					i++;
				showF = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
		//RHS...
			if((xCord == 122 || xCord == 114) && showA == false){
				if(seconds>0)
					i++;
				showA = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showB == false){
				if(seconds>0)
					i=i+4;
				showB = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showC == false){
				if(seconds>0)
					i++;
				showD = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showD == false){
				if(seconds>0)
					i++;
				showD = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showE == false){
				if(seconds>0)
					i++;
				showE = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showF == false){
				if(seconds>0)
					i++;
				showF = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		} 

		printf("%d\n",xCord);

		//row 2,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16 == 720){
			if(xCord+8 >= 30 && xCord+8 <=120 && showG == false){
				if(seconds>0)
					i=i+4;
				showG = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showH == false){
				if(seconds>0)
					i++;
				showH = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showI == false){
				if(seconds>0)
					i=i+4;
				showI = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showJ == false){
				if(seconds>0)
					i++;
				showJ = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showK == false){
				if(seconds>0)
					i++;
				showK = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showL == false){
				if(seconds>0)
					i++;
				showL = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}

		if(yCord+8>720 && yCord<750){
			//LHS...
			if(xCord+16 == 34 && showG == false){
				if(seconds>0)
					i=i+4;
				showG = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showH == false){
				if(seconds>0)
					i++;
				showH = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showI == false){
				if(seconds>0)
					i=i+4;
				showI = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showJ == false){
				if(seconds>0)
					i++;
				showJ = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 386&& showK == false){
				if(seconds>0)
					i++;
				showK = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 482 && showL == false){
				if(seconds>0)
					i++;
				showL = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
		//RHS...
			if((xCord == 122 || xCord == 114) && showG == false){
				if(seconds>0)
					i=i+4;
				showG = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showH == false){
				if(seconds>0)
					i++;
				showH = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showI == false){
				if(seconds>0)
					i=i+4;
				showI = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showJ == false){
				if(seconds>0)
					i++;
				showJ = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showK == false){
				if(seconds>0)
					i++;
				showK = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showL == false){
				if(seconds>0)
					i++;
				showL = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		}

		
		//UP...
		if(yCord == 750){
			if(xCord+8 >= 30 && xCord+8 <=120 && showG == false){
				if(seconds>0)
					i=i+4;
				showG = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showH == false){
				if(seconds>0)
					i++;
				showH = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showI == false){
				if(seconds>0)
					i=i+4;
				showI = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showJ == false){
				if(seconds>0)
					i++;
				showJ = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showK == false){
				if(seconds>0)
					i++;
				showK = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showL == false){
				if(seconds>0)
					i++;
				showL = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
		}

		//row 3,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16==680){
			if(xCord+8 >= 30 && xCord+8 <=120 && showM == false){
				if(seconds>0)
					i++;
				showM = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showN == false){
				if(seconds>0)
					i++;
				showN = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showO == false){
				if(seconds>0)
					i=i+4;
				showO = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showP == false){
				if(seconds>0)
					i++;
				showP = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showQ == false){
				if(seconds>0)
					i++;
				showQ = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showR == false){
				if(seconds>0)
					i++;
				showR = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}
		//printf("%d\n",yCord+8);
		if(yCord+8>= 680 && yCord+8<= 712){
		//LHS...
			if(xCord+16 == 34 && showM == false){
				if(seconds>0)
					i++;
				showM = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showN == false){
				if(seconds>0)
					i++;
				showN = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showO == false){
				if(seconds>0)
					i=i+4;
				showO = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showP == false){
				if(seconds>0)
					i++;
				showP = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 386&& showQ == false){
				if(seconds>0)
					i++;
				showQ = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 482 && showR == false){
				if(seconds>0)
					i++;
				showR = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
		//RHS...
			if((xCord == 122 || xCord == 114) && showM == false){
				if(seconds>0)
					i++;
				showM = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showN == false){
				if(seconds>0)
					i++;
				showN = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showO == false){
				if(seconds>0)
					i=i+4;
				showO = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showP == false){
				if(seconds>0)
					i++;
				showP = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showQ == false){
				if(seconds>0)
					i++;
				showQ = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showR == false){
				if(seconds>0)
					i++;
				showR = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		} 
		//UP...
		if(yCord == 712){
			if(xCord+8 >= 30 && xCord+8 <=120 && showM == false){
				if(seconds>0)
					i++;
				showM = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showN == false){
				if(seconds>0)
					i++;
				showN = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showO == false){
				if(seconds>0)
					i=i+4;
				showO = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showP == false){
				if(seconds>0)
					i++;
				showP = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showQ == false){
				if(seconds>0)
					i++;
				showQ = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showR == false){
				if(seconds>0)
					i++;
				showR = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
		}



		//row 4,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16 == 640){
			if(xCord+8 >= 30 && xCord+8 <=120 && showS == false){
				if(seconds>0)
					i++;
				showS = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showT == false){
				if(seconds>0)
					i=i+4;
				showT = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showU == false){
				if(seconds>0)
					i++;
				showU = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showV == false){
				if(seconds>0)
					i++;
				showV = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showW == false){
				if(seconds>0)
					i++;
				showW = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showX == false){
				if(seconds>0)
					i++;
				showX = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}
		//printf("%d\n",yCord+8);
		//printf("%d\n",xCord);
		//printf("%d\n",xCord+16);
		
		if(yCord+8>=640 && yCord+8<=669){
			//LHS...
			if(xCord+16 == 34 && showS == false){
				if(seconds>0)
					i++;
				showS = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showT == false){
				if(seconds>0)
					i=i+4;
				showT = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showU == false){
				if(seconds>0)
					i++;
				showU = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showV == false){
				if(seconds>0)
					i++;
				showV = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if((xCord+16 == 386 || xCord+16 == 378) && showW == false){
				if(seconds>0)
					i++;
				showW = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 474 && showX == false){
				if(seconds>0)
					i++;
				showX = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			//RHS...
			
			if((xCord == 114 || xCord == 122) && showS == false){
				if(seconds>0)
					i++;
				showS = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showT == false){
				if(seconds>0)
					i=i+4;
				showT = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showU == false){
				if(seconds>0)
					i++;
				showU = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showV == false){
				if(seconds>0)
					i++;
				showV = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showW == false){
				if(seconds>0)
					i++;
				showW = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showX == false){
				if(seconds>0)
					i++;
				showX = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		}
		//up...
		if(yCord == 672){
			if(xCord+8 >= 30 && xCord+8 <=120 && showS == false){
				if(seconds>0)
					i++;
				showS = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showT == false){
				if(seconds>0)
					i=i+4;
				showT = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showU == false){
				if(seconds>0)
					i++;
				showU = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showV == false){
				if(seconds>0)
					i++;
				showV = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showW == false){
				if(seconds>0)
					i++;
				showW = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showX == false){
				if(seconds>0)
					i++;
				showX = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}	
		}

		//Row 5..........................................................
		if(yCord+ 16 == 600){
			if(xCord+8 >= 30 && xCord+8 <=120 && showz1 == false){
				if(seconds>0)
					i=i+4;
				showz1 = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showz2 == false){
				if(seconds>0)
					i=i+4;
				showz2 = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showz3 == false){
				if(seconds>0)
					i=i+4;
				showz3 = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showz4 == false){
				if(seconds>0)
					i++;
				showz4 = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showz5 == false){
				if(seconds>0)
					i++;
				showz5 = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showz6 == false){
				if(seconds>0)
					i++;
				showz6 = true;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}	
		}
		if(yCord+8>600 && yCord+8 <632){
			//LHS...
			if(xCord+16 == 34 && showz1 == false){
				if(seconds>0)
					i=i+4;
				showz1 = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showz2 == false){
				if(seconds>0)
					i=i+4;
				showz2 = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showz3 == false){
				if(seconds>0)
					i=i+4;
				showz3 = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showz4 == false){
				if(seconds>0)
					i++;
				showz4 = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if((xCord+16 == 386 || xCord+16 == 378) && showz5 == false){
				if(seconds>0)
					i++;
				showz5 = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 474 && showz6 == false){
				if(seconds>0)
					i++;
				showz6 = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			//RHS...
			
			if((xCord == 114 || xCord == 122) && showz1 == false){
				if(seconds>0)
					i=i+4;
				showz1 = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showz2 == false){
				if(seconds>0)
					i=i+4;
				showz2 = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showz3 == false){
				if(seconds>0)
					i=i+4;
				showz3 = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showz4 == false){
				if(seconds>0)
					i++;
				showz4 = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showz5 == false){
				if(seconds>0)
					i++;
				showz5 = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showz6 == false){
				if(seconds>0)
					i++;
				showz6 = true;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		}
		//UP...

		if(yCord == 632){
			if(xCord+8 >= 30 && xCord+8 <=120 && showz1 == false){
				if(seconds>0)
					i=i+4;
				showz1 = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showz2 == false){
				if(seconds>0)
					i=i+4;
				showz2 = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showz3 == false){
				if(seconds>0)
					i=i+4;
				showz3 = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showz4 == false){
				if(seconds>0)
					i++;
				showz4 = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showz5 == false){
				if(seconds>0)
					i++;
				showz5 = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showz6 == false){
				if(seconds>0)
					i++;
				showz6 = true;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
		}

		if(yCord == 16){
			if(xCord + 8 >= xAxis && xCord + 8 <= xAxis+50)
				ballDirection = 1;
			
			else if(xCord + 8 >= xAxis+50 && xCord + 8 <=xAxis+78)
				ballDirection = 5;
			
			else if(xCord + 8 >= xAxis+78 && xCord + 8 <= xAxis+128)
				ballDirection = 2;
			
		}


		if(xCord <= 0){
			if(ballDirection == 1)
				ballDirection = 2;

			else if(ballDirection == 3)
				ballDirection = 4;
		}

		else if(xCord >= 600-16){
			if(ballDirection == 2)
				ballDirection = 1;
	
			else if(ballDirection == 4)
				ballDirection = 3;
		}

		if(yCord == 800-16){
		
			/*rn = rand()%3+1;

			if(rn == 1){
				ballDirection = 3;
			}
			else if(rn == 2){
				ballDirection = 4;
			}
			else{
				ballDirection = 6;
			}*/
		
			if(ballDirection == 2)
				ballDirection = 4;
			else if(ballDirection == 1)
				ballDirection = 3;
			else if(ballDirection == 5)
				ballDirection = 6;
		}

	
		if(ballDirection == 1){
			xCord -=db;
			yCord +=db;
		}

		if(ballDirection == 2){
			xCord +=db;
			yCord +=db;
		}

		if(ballDirection == 3){
			xCord -=db;
			yCord -=db;
		}

		if(ballDirection == 4){
			xCord +=db;
			yCord -=db;
		}

		if(ballDirection == 5){
			yCord +=db;
		}

		if(ballDirection == 6){
			yCord -=db;
		}
	}

	//LEVEL 3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
	if(display == 3){
		if(yCord+16 == 760){
			if(xCord+8 >= 30 && xCord+8 <=120 && showA == true){
				if(seconds>0)
					i=i+6;
				showA = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showB == true){
				if(seconds>0)
					i=i+6;
				showB = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showC == true){
				if(seconds>0)
					i=i+6;
				showC = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showD == true){
				if(seconds>0)
					i++;
				showD = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showE == true){
				if(seconds>0)
					i++;
				showE = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=578 && showF == true){
				if(seconds>0)
					i++;
				showF = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}
		if(yCord>760 && yCord<790){
			//LHS...
			if(xCord+16 == 34 && showA == true){
				if(seconds>0)
					i=i+6;
				showA = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showB == true){
				if(seconds>0)
					i=i+6;
				showB = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showC == true){
				if(seconds>0)
					i=i+6;
				showC = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showD == true){
				if(seconds>0)
					i++;
				showD = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 386&& showE == true){
				if(seconds>0)
					i++;
				showE = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 482 && showF == true){
				if(seconds>0)
					i++;
				showF = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
		//RHS...
			if((xCord == 122 || xCord == 114) && showA == true){
				if(seconds>0)
					i=i+6;
				showA = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showB == true){
				if(seconds>0)
					i=i+6;
				showB = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showC == true){
				if(seconds>0)
					i=i+6;
				showD = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showD == true){
				if(seconds>0)
					i++;
				showD = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showE == true){
				if(seconds>0)
					i++;
				showE = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showF == true){
				if(seconds>0)
					i++;
				showF = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		} 

		//printf("%d\n",xCord);

		//row 2,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16 == 720){
			if(xCord+8 >= 30 && xCord+8 <=120 && showG == true){
				if(seconds>0)
					i++;
				showG = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showH == true){
				if(seconds>0)
					i++;
				showH = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showI == true){
				if(seconds>0)
					i=i+6;
				showI = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showJ == true){
				if(seconds>0)
					i++;
				showJ = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showK == true){
				if(seconds>0)
					i++;
				showK = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=585 && showL == true){
				if(seconds>0)
					i++;
				showL = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}

		if(yCord+8>720 && yCord<750){
			//LHS...
			if(xCord+16 == 34 && showG == true){
				if(seconds>0)
					i++;
				showG = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showH == true){
				if(seconds>0)
					i++;
				showH = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showI == true){
				if(seconds>0)
					i=i+6;
				showI = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showJ == true){
				if(seconds>0)
					i++;
				showJ = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 386&& showK == true){
				if(seconds>0)
					i++;
				showK = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 482 && showL == true){
				if(seconds>0)
					i++;
				showL = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
		//RHS...
			if((xCord == 122 || xCord == 114) && showG == true){
				if(seconds>0)
					i++;
				showG = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showH == true){
				if(seconds>0)
					i++;
				showH = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showI == true){
				if(seconds>0)
					i=i+6;
				showI = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showJ == true){
				if(seconds>0)
					i++;
				showJ = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showK == true){
				if(seconds>0)
					i++;
				showK = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showL == true){
				if(seconds>0)
					i++;
				showL = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		}

		//UP...
		if(yCord == 750){
			if(xCord+8 >= 30 && xCord+8 <=120 && showG == true){
				if(seconds>0)
					i++;
				showG = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showH == true){
				if(seconds>0)
					i++;
				showH = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showI == true){
				if(seconds>0)
					i=i+6;
				showI = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showJ == true){
				if(seconds>0)
					i++;
				showJ = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showK == true){
				if(seconds>0)
					i++;
				showK = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showL == true){
				if(seconds>0)
					i++;
				showL = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
		}

		//row 3,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16==680){
			if(xCord+8 >= 30 && xCord+8 <=120 && showM == true){
				if(seconds>0)
					i=i+6;
				showM = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showN == true){
				if(seconds>0)
					i=i+6;
				showN = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showO == true){
				if(seconds>0)
					i=i+6;
				showO = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showP == true){
				if(seconds>0)
					i++;
				showP = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showQ == true){
				if(seconds>0)
					i++;
				showQ = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showR == true){
				if(seconds>0)
					i++;
				showR = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}
		//printf("%d\n",yCord+8);
		if(yCord+8>= 680 && yCord+8<= 712){
		//LHS...
			if(xCord+16 == 34 && showM == true){
				if(seconds>0)
					i=i+6;
				showM = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showN == true){
				if(seconds>0)
					i=i+6;
				showN = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showO == true){
				if(seconds>0)
					i=i+6;
				showO = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showP == true){
				if(seconds>0)
					i++;
				showP = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 386&& showQ == true){
				if(seconds>0)
					i++;
				showQ = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 482 && showR == true){
				if(seconds>0)
					i++;
				showR = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
		//RHS...
			if((xCord == 122 || xCord == 114) && showM == true){
				if(seconds>0)
					i=i+6;
				showM = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showN == true){
				if(seconds>0)
					i=i+6;
				showN = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showO == true){
				if(seconds>0)
					i=i+6;
				showO = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showP == true){
				if(seconds>0)
					i++;
				showP = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showQ == true){
				if(seconds>0)
					i++;
				showQ = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showR == true){
				if(seconds>0)
					i++;
				showR = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		} 
		//UP...
		if(yCord == 712){
			if(xCord+8 >= 30 && xCord+8 <=120 && showM == true){
				if(seconds>0)
					i=i+6;
				showM = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showN == true){
				if(seconds>0)
					i=i+6;
				showN = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showO == true){
				if(seconds>0)
					i=i+6;
				showO = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showP == true){
				if(seconds>0)
					i++;
				showP = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showQ == true){
				if(seconds>0)
					i++;
				showQ = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showR == true){
				if(seconds>0)
					i++;
				showR = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
		}



		//row 4,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		if(yCord+16 == 640){
			if(xCord+8 >= 30 && xCord+8 <=120 && showS == true){
				if(seconds>0)
					i++;
				showS = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showT == true){
				if(seconds>0)
					i++;
				showT = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showU == true){
				if(seconds>0)
					i=i+6;
				showU = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showV == true){
				if(seconds>0)
					i++;
				showV = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showW == true){
				if(seconds>0)
					i++;
				showW = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showX == true){
				if(seconds>0)
					i++;
				showX = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
		}
		//printf("%d\n",yCord+8);
		//printf("%d\n",xCord);
		//printf("%d\n",xCord+16);
		if(yCord+8>=640 && yCord+8<=669){
			//LHS...
			if(xCord+16 == 34 && showS == true){
				if(seconds>0)
					i++;
				showS = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showT == true){
				if(seconds>0)
					i++;
				showT = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showU == true){
				if(seconds>0)
					i=i+6;
				showU = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showV == true){
				if(seconds>0)
					i++;
				showV = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if((xCord+16 == 386 || xCord+16 == 378) && showW == true){
				if(seconds>0)
					i++;
				showW = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 474 && showX == true){
				if(seconds>0)
					i++;
				showX = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			//RHS...
			
			if((xCord == 114 || xCord == 122) && showS == true){
				if(seconds>0)
					i++;
				showS = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showT == true){
				if(seconds>0)
					i++;
				showT = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showU == true){
				if(seconds>0)
					i=i+6;
				showU = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showV == true){
				if(seconds>0)
					i++;
				showV = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showW == true){
				if(seconds>0)
					i++;
				showW = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showX == true){
				if(seconds>0)
					i++;
				showX = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		}
		//up...
		if(yCord == 672){
			if(xCord+8 >= 30 && xCord+8 <=120 && showS == true){
				if(seconds>0)
					i++;
				showS = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showT == true){
				if(seconds>0)
					i++;
				showT = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showU == true){
				if(seconds>0)
					i=i+6;
				showU = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showV == true){
				if(seconds>0)
					i++;
				showV = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showW == true){
				if(seconds>0)
					i++;
				showW = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showX == true){
				if(seconds>0)
					i++;
				showX = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}	
		}

		//Row 5.....................................................................
		if(yCord+ 16 == 600){
			if(xCord+8 >= 30 && xCord+8 <=120 && showz1 == true){
				if(seconds>0)
					i=i+6;
				showz1 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showz2 == true){
				if(seconds>0)
					i=i+6;
				showz2 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && showz3 == true){
				if(seconds>0)
					i=i+6;
				showz3 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showz4 == true){
				if(seconds>0)
					i++;
				showz4 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showz5 == true){
				if(seconds>0)
					i++;
				showz5 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showz6 == true){
				if(seconds>0)
					i++;
				showz6 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}	
		}
		if(yCord+8>600 && yCord+8 <632){
			//LHS...
			if(xCord+16 == 34 && showz1 == true){
				if(seconds>0)
					i=i+6;
				showz1 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && showz2 == true){
				if(seconds>0)
					i=i+6;
				showz2 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && showz3 == true){
				if(seconds>0)
					i=i+6;
				showz3 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && showz4 == true){
				if(seconds>0)
					i++;
				showz4 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if((xCord+16 == 386 || xCord+16 == 378) && showz5 == true){
				if(seconds>0)
					i++;
				showz5 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 474 && showz6 == true){
				if(seconds>0)
					i++;
				showz6 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			//RHS...
			
			if((xCord == 114 || xCord == 122) && showz1 == true){
				if(seconds>0)
					i=i+6;
				showz1 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && showz2 == true){
				if(seconds>0)
					i=i+6;
				showz2 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && showz3 == true){
				if(seconds>0)
					i=i+6;
				showz3 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && showz4 == true){
				if(seconds>0)
					i++;
				showz4 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && showz5 == true){
				if(seconds>0)
					i++;
				showz5 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && showz6 == true){
				if(seconds>0)
					i++;
				showz6 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		}
		//UP...

		if(yCord == 632){
			if(xCord+8 >= 30 && xCord+8 <=120 && showz1 == true){
				if(seconds>0)
					i=i+6;
				showz1 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && showz2 == true){
				if(seconds>0)
					i=i+6;
				showz2 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && showz3 == true){
				if(seconds>0)
					i=i+6;
				showz3 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && showz4 == true){
				if(seconds>0)
					i++;
				showz4 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && showz5 == true){
				if(seconds>0)
					i++;
				showz5 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && showz6 == true){
				if(seconds>0)
					i++;
				showz6 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
		}

		//Row 6....................................................
		
		if(yCord+ 16 == 560){
			if(xCord+8 >= 30 && xCord+8 <=120 && show31 == true){
				if(seconds>0)
					i++;
				show31 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && show32 == true){
				if(seconds>0)
					i++;
				show32 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 210 && xCord+8 <=300 && show33 == true){
				if(seconds>0)
					i++;
				show33 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && show34 == true){
				if(seconds>0)
					i++;
				show34 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && show35 == true){
				if(seconds>0)
					i++;
				show35 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && show36 == true){
				if(seconds>0)
					i++;
				show36 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}	
		}
		if(yCord+8>560 && yCord+8 <590){
			//LHS...
			if(xCord+16 == 34 && show31 == true){
				if(seconds>0)
					i++;
				show31 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 122 && show32 == true){
				if(seconds>0)
					i++;
				show32 = true;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 210 && show33 == true){
				if(seconds>0)
					i++;
				show33 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 298 && show34 == true){
				if(seconds>0)
					i++;
				show34 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if((xCord+16 == 386 || xCord+16 == 378) && show35 == true){
				if(seconds>0)
					i++;
				show35 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			if(xCord+16 == 474 && show36 == true){
				if(seconds>0)
					i++;
				show36 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;
			}
			//RHS...
			
			if((xCord == 114 || xCord == 122) && show31 == true){
				if(seconds>0)
					i++;
				show31 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 210 && show32 == true){
				if(seconds>0)
					i++;
				show32 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 298 && show33 == true){
				if(seconds>0)
					i++;
				show33 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 386 && show34 == true){
				if(seconds>0)
					i++;
				show34 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 482 && show35 == true){
				if(seconds>0)
					i++;
				show35 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
			if(xCord == 570 && show36 == true){
				if(seconds>0)
					i++;
				show36 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;
			}
		}
		//UP...

		if(yCord == 592){
			if(xCord+8 >= 30 && xCord+8 <=120 && show31 == true){
				if(seconds>0)
					i++;
				show31 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 120 && xCord+8 <=210 && show32 == true){
				if(seconds>0)
					i++;
				show32 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
				}			
			if(xCord+8 >= 210 && xCord+8 <=300 && show33 == true){
				if(seconds>0)
					i++;
				show33 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 295 && xCord+8 <=390 && show34 == true){
				if(seconds>0)
					i++;
				show34 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 390 && xCord+8 <=480 && show35 == true){
				if(seconds>0)
					i++;
				show35 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
			if(xCord+8 >= 480 && xCord+8 <=570 && show36 == true){
				if(seconds>0)
					i++;
				show36 = false;
				if(ballDirection == 3)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 2;
			}
		}


		if(yCord == 16){
			if(xCord + 8 >= xAxis && xCord + 8 <= xAxis+50)
				ballDirection = 1;
			
			else if(xCord + 8 >= xAxis+50 && xCord + 8 <=xAxis+78)
				ballDirection = 5;
			
			else if(xCord + 8 >= xAxis+78 && xCord + 8 <= xAxis+128)
				ballDirection = 2;
			
		}


		if(xCord <= 0){
			if(ballDirection == 1)
				ballDirection = 2;

			else if(ballDirection == 3)
				ballDirection = 4;
		}

		else if(xCord >= 600-16){
			if(ballDirection == 2)
				ballDirection = 1;
	
			else if(ballDirection == 4)
				ballDirection = 3;
		}

		if(yCord == 800-16){
		
			/*rn = rand()%3+1;

			if(rn == 1){
				ballDirection = 3;
			}
			else if(rn == 2){
				ballDirection = 4;
			}
			else{
				ballDirection = 6;
			}*/
		
			if(ballDirection == 2)
				ballDirection = 4;
			else if(ballDirection == 1)
				ballDirection = 3;
			else if(ballDirection == 5)
				ballDirection = 6;
		}

	
		if(ballDirection == 1){
			xCord -=db;
			yCord +=db;
		}

		if(ballDirection == 2){
			xCord +=db;
			yCord +=db;
		}

		if(ballDirection == 3){
			xCord -=db;
			yCord -=db;
		}

		if(ballDirection == 4){
			xCord +=db;
			yCord -=db;
		}

		if(ballDirection == 5){
			yCord +=db;
		}

		if(ballDirection == 6){
			yCord -=db;
		}
	}

		//Bonus L1...... L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..L1..
		if(display == 51){
			
		if(yCord+ 16 >= 672){
			if(xCord+8 >= 200 && xCord+8 <=328 && showbonA1 == true){
					i=i+15;
				showbonA1 = false;
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;

				display = 20;
			}
		}
			
			if(yCord+8>672 && yCord+8 <800){
			//LHS...
			if(xCord+16 >= 200 && xCord <212 && showbonA1 == true){
					i=i+15;
				showbonA1 = false;
				if(ballDirection == 2)
					ballDirection = 1;
				else if(ballDirection == 4)
					ballDirection = 3;

				display = 20;
			}
			//RHS...
			if((xCord <= 328 && xCord >= 320) && showbonA1 == true){
					i=i+15;
				showbonA1 = false;
				if(ballDirection == 1)
					ballDirection = 2;
				else if(ballDirection == 3)
					ballDirection = 4;

				display = 20;
			}
		}

			if(yCord == 16){
				if(xCord + 8 >= xAxis && xCord + 8 <= xAxis+50)
					ballDirection = 1;
			
				else if(xCord + 8 >= xAxis+50 && xCord + 8 <=xAxis+78)
					ballDirection = 5;
			
				else if(xCord + 8 >= xAxis+78 && xCord + 8 <= xAxis+128)
					ballDirection = 2;
			
			}


			if(xCord <= 0){
				if(ballDirection == 1)
					ballDirection = 2;

				else if(ballDirection == 3)
					ballDirection = 4;
			}

			else if(xCord >= 600-16){
				if(ballDirection == 2)
					ballDirection = 1;
	
				else if(ballDirection == 4)
					ballDirection = 3;
			}

			if(yCord == 800-16){
		
				/*rn = rand()%3+1;

				if(rn == 1){
					ballDirection = 3;
				}
				else if(rn == 2){
					ballDirection = 4;
				}
				else{
					ballDirection = 6;
				}*/
		
				if(ballDirection == 2)
					ballDirection = 4;
				else if(ballDirection == 1)
					ballDirection = 3;
				else if(ballDirection == 5)
					ballDirection = 6;
			}

	
			if(ballDirection == 1){
				xCord -=db;
				yCord +=db;
			}

			if(ballDirection == 2){
				xCord +=db;
				yCord +=db;
			}

			if(ballDirection == 3){
				xCord -=db;
				yCord -=db;
			}

			if(ballDirection == 4){
				xCord +=db;
				yCord -=db;
			}

			if(ballDirection == 5){
				yCord +=db;
			}

			if(ballDirection == 6){
				yCord -=db;
			}
		}
}


void second(){ 
	if(display == 1){
		seconds--;
		if(seconds <= 0){
			seconds = 0;
		}
	}
	if(display == 2){
		seconds--;
		if(seconds <= 0){
			seconds = 0;
		}
	}
	if(display == 3){
		seconds--;
		if(seconds <= 0){
			seconds = 0;
		}
	}
}
//int beg;
int main()
{
	timer1 = iSetTimer(20, ballMovement);
	timer2 = iSetTimer(1000,second);
	//srand(time(NULL));
	//if(display == 1)
		//beg = 1000;
	dx1 = 128;
	db = 8;
	len = 0;
	mode = 0;
	str[0]= 0;

	iInitialize(900, 800, "DXball");  //game display == 600;

	return 0;
}	