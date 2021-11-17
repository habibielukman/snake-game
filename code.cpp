#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
char block=219;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
#define color(x) SetConsoleTextAttribute(hStdOut, x)
#define printl(x); cout << x;
char upLeft=201;
char upRight=187;
char horizontal=205;
char vertical=186;
char downLeft=200;
char downRight=188;
int bestPoint=0;
int times=0;
void loading(){
	string loadingChar[5]={"S","N","A","K","E"};
	string lo="";
	for(int i=0;i<10;i++){
		printl(i*10 << "%\n");
		printl(loadingChar[i%5] << "\n");
		printl(lo);
		lo+=block;
		Sleep(250);
		system("cls");
	}
}
void runGame2(){
	int num=250;
	int x=0,y=0,tx=(rand() % 10),ty=(rand() % 10);
	srand(time(0));
	string key="";
	system("Title Snake Game");
	int point=0;
	color(1);
	int colorB=1;
	while(1) {
		color(14);
		printl(" _____   _____     ___     _   _   ___       ___     ___       ____  ____     ___  Your place is the character []\n");
		printl("/ __ /  |  _  |   / _ \\   | |_/ / | __|     /       / _ \\     /  _ \\/__  \\   | __| The Apple is the yellow\n");
		printl("\\__  \\  | | | |  / /_\\ \\  |  _  | | __|    |  --|  / /_\\ \\   /  / \\ /  \\  \\  | __|\n");
		printl("/____/  |_| |_| /_/   \\_\\ |_| \\_\\ |___|     \\___| /_/   \\_\\ |__|  |_|   |__| |___| Habibie Lukmanul Hakim\n");
		printl("POINT " << point << endl);
		if(x%4==1 && y%4==1){
			break;
		}
		if(ty%4==1&&tx%4==1){
			ty=rand()%10;
			tx=rand()%10;
		}
		if(x==tx && y==ty){
			point++;
			colorB=((colorB+1)%15)+1;
			tx=(rand() % 10);ty=(rand() % 10);
		}
		if(x<0 || y<0 || x>9 || y>9) break;
		color(8);
		printl(upLeft);
		for(int i=0; i<10;i++){
			color(8);
			printl(horizontal << horizontal);
		}
		printl(upRight);
		printl(endl);
		for(int i=0;i<10;i++){
			color(8)
			printl(vertical);
			for(int j=0;j<10;j++){
				if(i==y && j==x){
					color(75);
					printl ("[]");
				}else if(i==ty && j==tx){
					color(6);
					printl (block << block);
				}else if(i%4==1 && j%4==1){
					color(79);
					printl("/\\");
				}else{
					color(4);
					printl (block << block);
				}
			}
			color(8);
			printl(vertical);
			printl ("\n");
		}
		printl(downLeft);
		for(int i=0; i<10;i++){
			color(8);
			printl(horizontal << horizontal);
		}
		printl(downRight);
		printl("\n");
		if(_kbhit()){
			
			char c=getch();
			if(c==KEY_UP){
				y--;
				key="KEY_UP";
			}else if(c==KEY_DOWN){
				y++;
				key="KEY_DOWN";
			}else if(c==KEY_LEFT){
				x--;
				key="KEY_LEFT";
			}else if(c==KEY_RIGHT){
				x++;
				key="KEY_RIGHT";
			}else if(c==27){
				printl("Your game is Paused\nPress any key to continue ...");
				getch();
			}
		}else{
			if(key=="KEY_UP"){
				y--;
			}else if(key=="KEY_DOWN"){
				y++;
			}else if(key=="KEY_LEFT"){
				x--;
			}else if(key=="KEY_RIGHT"){
				x++;
			}
		}
		Sleep(num);
		system("cls");
	}
	color(4);
	system("cls");
	bestPoint=max(bestPoint,point);
	cout   << "     POINT:"<< point <<"         "   << endl;
	cout   << "BEST POINT:"<< bestPoint << "         "   << endl;
	cout   << "       You lose      "   << endl;
	cout   << " [ R ] for retry     "   << endl;
	cout   << " [ Alt ] + [ F4 ] or [ F4 ]\n";
	char cget=getch();
	if(cget=='r'){
		runGame2();
	}
	while(cget!='r'){
		cget=getch();
		if(cget=='r'){
			runGame2();
			break;
		}
	}
}
void runGame(){
	int num=250;
	int x=0,y=0,tx=(rand() % 10),ty=(rand() % 10);
	srand(time(0));
	string key="";
	system("Title Snake Game");
	int point=0;
	color(1);
	int colorB=1;
	string password="";
	char ch;
	string upass="";
	ch=getch();
	string keyIn="Up";
	printl(" _____   _____     ___     _   _   ___       ___     ___       ____  ____     ___\n");
	printl("/ __ /  |  _  |   / _ \\   | |_/ / | __|     /       / _ \\     /  _ \\/__  \\   | __|\n");
	printl("\\__  \\  | | | |  / /_\\ \\  |  _  | | __|    |  --|  / /_\\ \\   /  / \\ /  \\  \\  | __|\n");
	printl("/____/  |_| |_| /_/   \\_\\ |_| \\_\\ |___|     \\___| /_/   \\_\\ |__|  |_|   |__| |___| Habibie Lukmanul Hakim\n");
	printl("-> Choose Speed <-\n");
	printl("    Continue\n");
	while((ch=getch())!='\r'){
		system("cls");
		if(ch==KEY_UP){
			keyIn="Up";
		}else if(ch==KEY_DOWN){
			keyIn="Down";
		}
		printl(" _____   _____     ___     _   _   ___       ___     ___       ____  ____     ___\n");
		printl("/ __ /  |  _  |   / _ \\   | |_/ / | __|     /       / _ \\     /  _ \\/__  \\   | __|\n");
		printl("\\__  \\  | | | |  / /_\\ \\  |  _  | | __|    |  --|  / /_\\ \\   /  / \\ /  \\  \\  | __|\n");
		printl("/____/  |_| |_| /_/   \\_\\ |_| \\_\\ |___|     \\___| /_/   \\_\\ |__|  |_|   |__| |___| Habibie Lukmanul Hakim\n");
		if(keyIn=="Up"){
			printl("-> Choose Speed <-\n");
			printl("    Continue\n");
		}else{
			printl("   Choose Speed\n");
			printl("->  Continue    <-\n");
		}

	}
	system("cls");
	if(keyIn=="Up"){
		float speed;
		cout << "Enter Speed [ In decimal ]: ";
		cin >> speed;
		num=speed*1000;
	}
	printl("\n");
	printl("Press" << " [ SPACE ] " << "to continue");
	if(getch()==32){

	}else{
		printl("goodBY");
		return;
	}
	while(1) {
		color(14);
		printl(" _____   _____     ___     _   _   ___       ___     ___       ____  ____     ___  Your place is the character []\n");
	printl("/ __ /  |  _  |   / _ \\   | |_/ / | __|     /       / _ \\     /  _ \\/__  \\   | __| The Apple is the yellow\n");
	printl("\\__  \\  | | | |  / /_\\ \\  |  _  | | __|    |  --|  / /_\\ \\   /  / \\ /  \\  \\  | __|\n");
	printl("/____/  |_| |_| /_/   \\_\\ |_| \\_\\ |___|     \\___| /_/   \\_\\ |__|  |_|   |__| |___| Habibie Lukmanul Hakim\n");
		printl("POINT " << point << endl);
		if(x%4==1 && y%4==1){
			break;
		}
		if(x==tx && y==ty){
			point++;
			colorB=((colorB+1)%15)+1;
			tx=(rand() % 10);ty=(rand() % 10);
		}
		if(x<0 || y<0 || x>9 || y>9) break;
		color(8);
		printl(upLeft);
		for(int i=0; i<10;i++){
			color(8);
			printl(horizontal << horizontal);
		}
		if(ty%4==1&&tx%4==1){
			ty=rand()%10;
			tx=rand()%10;
		}
		printl(upRight);
		printl(endl);
		for(int i=0;i<10;i++){
			color(8)
			printl(vertical);
			for(int j=0;j<10;j++){
				if(i==y && j==x){
					color(75);
					printl ("[]");
				}else if(i==ty && j==tx){
					color(6);
					printl (block << block);
				}else if(i%4==1 && j%4==1){
					color(79);
					printl("/\\");
				}else{
					color(4);
					printl (block << block);
				}
			}
			color(8);
			printl(vertical);
			printl ("\n");
		}
		printl(downLeft);
		for(int i=0; i<10;i++){
			color(8);
			printl(horizontal << horizontal);
		}
		printl(downRight);
		printl("\n");
		if(_kbhit()){
			
			char c=getch();
			if(c==KEY_UP){
				y--;
				key="KEY_UP";
			}else if(c==KEY_DOWN){
				y++;
				key="KEY_DOWN";
			}else if(c==KEY_LEFT){
				x--;
				key="KEY_LEFT";
			}else if(c==KEY_RIGHT){
				x++;
				key="KEY_RIGHT";
			}else if(c==27){
				printl("Your game is Paused\nPress any key to continue ...");
				getch();
			}
		}else{
			if(key=="KEY_UP"){
				y--;
			}else if(key=="KEY_DOWN"){
				y++;
			}else if(key=="KEY_LEFT"){
				x--;
			}else if(key=="KEY_RIGHT"){
				x++;
			}
		}
		Sleep(num);
		system("cls");
	}
	color(4);
	system("cls");
	bestPoint=max(bestPoint,point);
	cout   << "     POINT:"<< point <<"         "   << endl;
	cout   << "BEST POINT:"<< bestPoint << "         "   << endl;
	cout   << "       You lose      "   << endl;
	cout   << " [ R ] for retry     "   << endl;
	cout   << " [ Alt ] + [ F4 ] or [ F4 ]\n";
	char cget=getch();
	if(cget=='r'){
		runGame2();
	}
	while(cget!='r'){
		char cc=getch();
		if(cc=='r'){
			runGame2();
			break;
		}
	}
	Sleep(num*100);
	getch();
	getch();
}
int main(){
	runGame();
	return 0;
}
