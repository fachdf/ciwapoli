#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* deklarasi variable global */

struct harga_jual{
	int tanah;
	int rumah;
	int hotel;
};
struct harga_beli{
	int tanah;
	int rumah;
	int hotel;
};
struct properti{
	char nama[8];
	int id;
	struct harga_beli hargabeliproperti;
	struct harga_jual hargajualproperti;
	int status;
};
struct player{
	char nama[10];
	int uang;
	struct properti properti_player[20];
	int giliran;
	int posisi;
};
char papan[32]={
				'0','0','0','0','0','0','0','0','0','0',
				'0','0','0','0','0','0','0','0','0','0',
				'0','0','0','0','0','0','0','0','0','0',
				'0','1'};
struct player pemain[4];
int tingkatkesulitan;


/* Modules */

void printpapan(){
	
//	papan[dadu] = 'P';
	
//	system("cls");
    printf("\tMonopoli\n");

	printf("______________________________________________________\n");
    printf("|PB   |1E   |K    |2E   |PL   |1F   |2F   |3F   |P    |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[16], papan[17], papan[18],papan[19], papan[20], papan[21],papan[22], papan[23], papan[24]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|2D   |                                         |1G   |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[15], papan[25]);
    printf("|_____|                                         |_____|\n");
    printf("|DU   |                                         |K    |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[14], papan[26]);
    printf("|_____|                                         |_____|\n");
    printf("|1D   |                                         |2G   |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[13], papan[27]);
    printf("|_____|                                         |_____|\n");
    printf("|B    |               Ciwapoli                  |T    |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[12], papan[28]);
    printf("|_____|                                         |_____|\n");
    printf("|3C   |                                         |1H   |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[11], papan[29]);
    printf("|_____|                                         |_____|\n");
    printf("|2C   |                                         |PJ   |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[10], papan[30]);
    printf("|_____|                                         |_____|\n");
    printf("|1C   |                                         |2H   |\n");
    printf("|  %c  |                                         | #%c  |\n", papan[9], papan[31]);
    printf("|_____|_________________________________________|_____|\n");
    printf("|(P)  |3B   |2B   |1B   |S    |2A   |DU   |1A    |START|\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[8], papan[7], papan[6],papan[5], papan[4], papan[3],papan[2], papan[1], papan[0]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
	//end of papan//
//		papan[dadu] = '0';

	return;
}

void inputnama(){
	system("cls");
	printf("Masukkan Nama : ");
	scanf(" %s", pemain[1].nama);
	system("cls");
}

void settingbot(){
	
	pemain[2].nama[10] = "COMPUTER1";
	pemain[2].uang = 50000;
	
	pemain[3].nama[10] = "COMPUTER2";
	pemain[3].uang = 50000;
	
	pemain[4].nama[10] = "COMPUTER3";
	pemain[4].uang = 50000;
}

void difficulty(){
	system("cls");
	printf("Pilih Tingkat Kesulitan\n1. Easy\n2. Medium\n3. Hard\nPilih : ");
	scanf("%d", &tingkatkesulitan);
	switch(tingkatkesulitan){
		case 1 : pemain[1].uang = 100000;
				 break;
		case 2 : pemain[1].uang = 50000;
				 break;
		case 3 : pemain[1].uang = 25000;
				 break;
		default: difficulty();
				 break;
	}
}

void kocokdadu(int *dice1, int *dice2, int *dobel){
	
	srand(time(NULL));
	*dice1 = rand() % 6 + 1;
	*dice2 = rand() % 6 + 1;
	
	if( *dice1 == *dice2 ){
		*dobel = 1;
	}
	else{
		*dobel = 0;
	}
	if(*dobel==1){
		printf("%d and %d you got double\n", *dice1, *dice2);
	}
	else{
		printf("%d and %d\n", *dice1, *dice2);
	}
	
	return;
}

void kocokgiliran(){ //OK//
	int p1,c1,c2,c3;
	
	srand(time(NULL));
	
	Sleep(1000);
	p1 = rand()% 4 + 1; printf("Player 1 = %d\n", p1); 
	pemain[1].giliran = p1;
	
	c1 = rand()% 4 + 1;
	while(c1 == p1){
		Sleep(1000);
		c1 = rand()% 4 + 1;
	}
	pemain[2].giliran = c1;
	printf("Computer 1 = %d\n", c1);
	
	Sleep(1000);
	c2 = rand()% 4 + 1;
	while(c2 == c1 || c2 == p1){
		Sleep(1000);
		c2 = rand()% 4 + 1;
	}
	printf("Computer 2 = %d\n", c2);
	pemain[3].giliran = c2;
	
	Sleep(1000);
	c3 = rand()% 4 + 1;
	while(c3 == p1 || c3 == c1 || c3 == c2){
		Sleep(1000);
		c3 = rand()% 4 + 1;
	}
	printf("Computer 3 = %d\n", c3);
	pemain[4].giliran = c3;
	
}

void prepare(){
	
	printpapan();
	
	printf("\nAkan dilakukan penentuan giliran..\n");
	kocokgiliran();
	
	printf("Uang pertama anda sebesar %d", pemain[1].uang);
	return;
}

void play(){
	/* Input Nama Player */
	inputnama();
	difficulty();
	settingbot();
	prepare();
//	giliran();
}

void load(){
	char lanjut;
	
	system("cls");
	printf("\nTBA");
	
	printf("\n\nLanjut?(Y/N)");
	scanf(" %c", &lanjut);
	system("cls");
	if(lanjut == 'Y' || lanjut == 'y'){
		mainmenu();
	}else{
		exit(0);
	}	
}

void highscore(){
	char lanjut;
	
	system("cls");
	printf("\nTBA");
	
	printf("\n\nLanjut?(Y/N)");
	scanf(" %c", &lanjut);
	system("cls");
	if(lanjut == 'Y' || lanjut == 'y'){
		mainmenu();
	}else{
		exit(0);
	}	
}

void credit(){
	char lanjut;
	
	system("cls");
	printf("\nTBA");
	
	printf("\n\nLanjut?(Y/N)");
	scanf(" %c", &lanjut);
	system("cls");
	if(lanjut == 'Y' || lanjut == 'y'){
		mainmenu();
	}else{
		exit(0);
	}
}

void rules(){
	char lanjut;
	system("cls");
	printf("=======================RULES=======================\n\n");
	printf("A. Deskripsi Game\n");
	printf("TBA\n");
	printf("B. Rules\n");
	printf("TBA\n");
	printf("C. Kondisi Menang\n");
	printf("TBA\n");
	printf("D. Harga Komplek\n");
	printf("TBA\n");
	
	printf("\n\nLanjut?(Y/N)");
	scanf(" %c", &lanjut);
	if(lanjut == 'Y' || lanjut == 'y'){
		mainmenu();
	}else{
		exit(0);
	}
}

void mainmenu(){
	int pilihan;
	
	/* Tampilan Menu */
	printf("===================================================\n");
	printf("                      Ciwapoli                     \n");
	printf("===================================================\n");
	printf("1. Play\n");
	printf("2. Load\n");
	printf("3. Highschore\n");
	printf("4. Credit\n");
	printf("5. Rules\n");
	printf("6. Exit\n");
	
	/* Input Pilihan Menu */
	printf("\nMasukkan angka : ");
	scanf("%d", &pilihan);
	
	/* Aksi Pilihan */
	switch(pilihan){
		case 1 : play();		// Panggil Modul Play//
				 break;	
		case 2 : load();		// Panggil Modul Load//
				 break;
		case 3 : highscore();	// Panggil Modul High Score//
				 break;
		case 4 : credit();		// Panggil Modul Credit//
				 break;
		case 5 : rules();		// Panggil Modul Rules //
				 break;
		case 6 : exit(0);		// Exit Program //
				 break;
		default: mainmenu();
	}
}

int main(){
	mainmenu();
}
