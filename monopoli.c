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
	char nama[8];
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
void printPapan(int dadu){
	
	papan[dadu] = 'P1';
	
//	system("cls");
    printf("\tMonopoli\n");

	printf("______________________________________________________\n");
    printf("|  PB |     |     |     |     |     |     |     |  P  |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[16], papan[17], papan[18],papan[19], papan[20], papan[21],papan[22], papan[23], papan[24]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |                                         |     |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[15], papan[25]);
    printf("|_____|                                         |_____|\n");
    printf("|     |                                         |     |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[14], papan[26]);
    printf("|_____|                                         |_____|\n");
    printf("|     |                                         |     |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[13], papan[27]);
    printf("|_____|                                         |_____|\n");
    printf("|     |            Monopoli Gan                 |     |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[12], papan[28]);
    printf("|_____|                                         |_____|\n");
    printf("|     |                                         |     |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[11], papan[29]);
    printf("|_____|                                         |_____|\n");
    printf("|     |                                         |     |\n");
    printf("|  %c  |                                         |  %c  |\n", papan[10], papan[30]);
    printf("|_____|                                         |_____|\n");
    printf("|     |                                         |     |\n");
    printf("|  %c  |                                         | #%c  |\n", papan[9], papan[31]);
    printf("|_____|_________________________________________|_____|\n");
    printf("| (P) |     |     |     |     |     |     |     |START|\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[8], papan[7], papan[6],papan[5], papan[4], papan[3],papan[2], papan[1], papan[0]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
	//end of papan//
		papan[dadu] = '0';
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

void giliran(){
	int dice1=0,dice2=0,dobel=0,totaldadu;
	char lagi;
	Sleep(1000);
	printf("\n\n");
	kocokdadu(&dice1, &dice2, &dobel);
	totaldadu = dice1 + dice2;
	printPapan(totaldadu);
	if(dobel==1){
		printf("Lagi?");scanf(" %c", &lagi);
		giliran();
	}
	return;
}

void mainmenu(){
	int pilihan;
	printf("==================================================\n");
	printf("                     Ciwapoli                     \n");
	printf("==================================================\n");
	printf("1. Play\n");
	printf("2. Load\n");
	printf("3. Highschore\n");
	printf("4. Credit\n");
	printf("5. Exit\n");
	printf("\nMasukkan angka : ");
	scanf("%d", &pilihan);
}

int main(){
	mainmenu();
}
