/*
________________________________________________
		PROGRAM INPUT DATABASE MAHASISWA
		CREATED BY FAKHRUL & SULAIMAN
------------------------------------------------		

*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define LEN_LINE 80
#define MAX_LINE 30
#define LEN_NAME 30
#define MAX_MAHASISWA 40

typedef struct
{
		int head;
		int tail;
		int data[50];
		int data1[50][25];
		int data2[50][25];
		int data3[50][25];
		
		struct database{
			char nama[LEN_NAME + 1];
			int NPM;
			float IPK;
		};
	}database;

database antrian;
database nama;
database NPM;
database IPK;
int data, i, j;
char data1[25], data2[25], data3[25];

void header();//header
void menu();//menu
void inputan();//pilihan menu
void clearbuffer();//
int data_baru();//memasukkan data baru ke notepad
int data_lama();//menambahkan data lama ke notepad
int baca_file();//membaca file dari notepad
int search();//mencari data dari notepad
void displayData();//menampilkan data dari notepad
int mulai();//menu mulai program
int help();//petunjuk
void close();//exit
void salah();//default salah inputan
int konsultasi();//modular konsultasi skripsi
int main();//menu utama
int enqueue();//membuat antrian
int dequeue();//memanggil antrian

//modular untuk header
void header() 
{
	system("cls");
	printf("========================================================================================\n");
	printf("|                                    DATABASE MAHASISWA                                |\n");
	printf("|                                Created by Fakhrul & Sulaiman                         |\n");
	printf("========================================================================================\n");
}

//pilihan menu utama
void menu() 
{
	char pilihan;

	header();
	printf("MENU PILIHAN\t: \n");
	printf("1. Start Program\n2. Help\n3. Exit\n\n");
	printf("Masukkan Pilihan : ");

}

//inputan menu mulai
void inputan()
{
	char input;
	printf("1. INPUT DATA BARU\n2. INPUT DATA LAMA\n3. MEMBACA FILE\n4. SEARCH\n5. KONSULTASI SKRIPSI\n0. KEMBALI\n");
	printf("\nMASUKKAN PILIHAN : ");
}

//membaca inputan user
void clearbuffer() {
	char gf;
	while ((gf = getchar()) != '\n' && gf != EOF);
}

int kosong()
{
	if(antrian.tail==-1)
		return 1;
	else
		return 0;
}

int penuh()
{
	if(antrian.tail == 50)
		return 1;
	else
		return 0;
}

//membuat antrian
int enqueue(int data, char data1[25], char data2[25], char data3[25])
{
	if(kosong() == 1)
	{
		//mendefinisikan antrian, nama, npm, dan ipk = 0
		antrian.head = antrian.tail = 0;
		nama.head = nama.tail = 0;
		NPM.head = NPM.tail = 0;
		IPK.head = IPK.tail = 0;
		
		antrian.data[antrian.tail] = data;
		
		//memasukkan antrian nama, npm, ipk
		for(i=0; i<25; i++)
		{
			nama.data1[nama.tail][i] = data1[i];
		}
		for(i=0; i<25; i++)
		{
			NPM.data2[NPM.tail][i] = data2[i];
		}
		for(i=0; i<25; i++)
		{
			IPK.data3[IPK.tail][i] = data3[i];
		}
		
		printf("SILAKAN MENUNGGU GILIRAN\n\n");
	}
	//menambahkan antrian
	else if(penuh()==0)
	{
		antrian.tail++;
		nama.tail++;
		NPM.tail++;
		IPK.tail++;
		
		antrian.data[antrian.tail] = data;
		
		for(i=0; i<25; i++)
		{
			nama.data1[nama.tail][i] = data1[i];
		}
		for(i=0; i<25; i++)
		{
			NPM.data2[NPM.tail][i] = data2[i];
		}
		for(i=0; i<25; i++)
		{
			IPK.data3[IPK.tail][i] = data3[i];
		}
		
		printf("SILAKAN MENUNGGU GILIRAN\n\n");
	}
}

//menampilkan antrian
int dequeue()
{
	int i, j, e;
	char a[25], b[25];
	
	//menampilkan antrian
	if(kosong() == 0)
	{
		e = antrian.data[antrian.head];
		for(i=0; i<25; i++)
		{
			a[i] = nama.data1[nama.head][i];
		}
		for(i=0; i<25; i++)
		{
			b[i] = NPM.data2[NPM.head][i];
		}
		for(i=antrian.head; i<antrian.tail; i++)
		{
			antrian.data[i] = antrian.data[i+1];
			
			for(j=0; j<25; j++)
			{
				nama.data1[i][j] = nama.data1[i+1][j];
			}
			for(j=0; j<25; j++)
			{
				NPM.data2[i][j] = NPM.data2[i+1][j];
			}
			for(j=0; j<25; j++)
			{
				IPK.data3[i][j] = IPK.data3[i+1][j];
			}
		}
		
		//mengurangin antrian
			antrian.tail--;
			nama.tail--;
			NPM.tail--;
			IPK.tail--;
			
			//memanggil nama npm
			printf("Antrian no %i dengan Nama %s NPM %s dipersilakan memasuki ruangan\n\n", e, a, b);
		
			return e;
			return a[25];
			return b[25];
		
	}
	//jika tidak ada antrian
	else
	{
		printf("ANTRIAN KOSONG\n\n");
		system("pause");
		return konsultasi();
	}
}

//deklarasi antrian
void buat()
{
	antrian.head = antrian.tail = -1;
	nama.head = nama.tail = -1;
	NPM.head = NPM.tail = -1;
	IPK.head = IPK.tail = -1;
}
//USER INPUT DATA YG BARU
int data_baru()
{
	header();
	
	int i, j, k, Ndata;
	FILE *DATABASE;//inisialisasi file yaitu DATABASE.txt
	
	/*MENGGUNAKAN DATA STRUCT UNTUK MEMBANDINGKAN DAN SORTING IPK*/
	struct database {
		char nama[25];
		int NPM[25];
		float IPK[25];
	} temp;
	
	struct database mahasiswa[100];
	
	/*BANYAK DATA YANG AKAN DIINPUT*/
	printf("BANYAK DATA YANG AKAN DIMASUKKAN : ");
	scanf("%d", &Ndata);

	/*INPUT DATA NAMA, NPM, IPK*/
	for(i=0; i<Ndata; i++) {
		printf("Data ke-%d\n", i+1);
		printf("NAMA\t\t: ");
		scanf("%s", mahasiswa[i].nama);
		clearbuffer();

		printf("NPM\t\t: ");
		scanf("%s", &mahasiswa[i].NPM);
		clearbuffer();

		printf("IPK\t\t: ");
		scanf("%s", &mahasiswa[i].IPK);
		clearbuffer();

		printf("\n");
	}

	/*SORTING STRUCT DESCENDING*/
	for(i=0; i<Ndata-1; i++) {
		for(j=0; j<Ndata-i-1; j++) {
			if(strcmp(mahasiswa[j].IPK, mahasiswa[j+1].IPK)>0) {
				temp=mahasiswa[j];
				mahasiswa[j]= mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}

	//MENGAHAPUS DATA LAMA
	DATABASE=fopen("DATABASE.txt","w");
		if(DATABASE == NULL) {
			printf("file tidak ditemukan");
		} 
		else
		{
			fprintf(DATABASE, "=============================================================================================================\n");
			fprintf(DATABASE, "|                                         DATABASE MAHASISWA                                                |\n");
			fprintf(DATABASE, "=============================================================================================================\n");
			fprintf(DATABASE, "|\t\tNAMA\t\t |\t\tNPM\t\t\t |\t\tIPK\t\t    |\n");
			fprintf(DATABASE, "-------------------------------------------------------------------------------------------------------------\n");
		}
	fclose(DATABASE);
	
	//MEMASUKKAN DATA KE NOTEPAD DAN TERURUT
	printf("Urutan Data Mahasiswa dari IPK Tertinggi ke Terendah :\n");
	for(i=Ndata; i>-1; i--) {
		//print hasil output dalam program yang dijalankan
		printf("%s %s %s\n", mahasiswa[i].nama, mahasiswa[i].NPM, mahasiswa[i].IPK);

		DATABASE = fopen("DATABASE.txt","a");//menambahkan database yg sudah ada dalam file
		if(DATABASE == NULL) 
		{
			printf("file tidak ditemukan");
		} 
		else 
		{
			fprintf(DATABASE, "\t\t%s\t\t \t\t%s\t\t \t\t%s\t\t \n", mahasiswa[i].nama, mahasiswa[i].NPM, mahasiswa[i].IPK);
		}
		fclose(DATABASE);
	}

	printf("\n\nDATA BERHASIL DISIMPAN\n\n");
}

//USER MELANJUTKAN INPUT DATA LAMA
int data_lama()
{
	header();
	
	int i, j, k, Ndata;
	FILE *DATABASE;//inisialisasi file yaitu DATABASE.txt
	/*MENGGUNAKAN DATA STRUCT UNTUK MEMBANDINGKAN DAN SORTING IPK*/
	struct database {
		char nama[25];
		int NPM[25];
		float IPK[25];
	} temp;
	
	struct database mahasiswa[100];

	/*BANYAK DATA YANG AKAN DIINPUT*/
	printf("BANYAK DATA YANG AKAN DIMASUKKAN : ");
	scanf("%d", &Ndata);
	printf("\n");
	
	/*INPUT DATA NAMA, NPM, IPK*/
	for(i=0; i<Ndata; i++) {
		printf("Data ke-%d\n", i+1);
		printf("NAMA\t\t: ");
		scanf("%s", mahasiswa[i].nama);
		clearbuffer();

		printf("NPM\t\t: ");
		scanf("%s", &mahasiswa[i].NPM);
		clearbuffer();

		printf("IPK\t\t: ");
		scanf("%s", &mahasiswa[i].IPK);
		clearbuffer();

		printf("\n");
	}

	/*SORTING STRUCT ASCENDING*/
	for(i=0; i<Ndata-1; i++) {
		for(j=0; j<Ndata-i-1; j++) {
			if(strcmp(mahasiswa[j].IPK, mahasiswa[j+1].IPK)>0) {
				temp=mahasiswa[j];
				mahasiswa[j]= mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	//MEMASUKKAN DATA KE NOTEPAD DAN TERURUT
	printf("\nUrutan Data Mahasiswa dari IPK Tertinggi ke Terendah : \n");
	for(i=Ndata; i>-1; i--) {
		//print hasil output dalam program yang dijalankan
		printf("%s %s %s\n", mahasiswa[i].nama, mahasiswa[i].NPM, mahasiswa[i].IPK);

		DATABASE=fopen("DATABASE.txt", "a");//menambahkan database yg sudah ada dalam file
		if(DATABASE==NULL) {
			printf("file tidak ditemukan\n");
		} 
		else 
		{
			fprintf(DATABASE, "\t\t%s\t\t \t\t%s\t\t \t\t%s\t\t \n", mahasiswa[i].nama, mahasiswa[i].NPM, mahasiswa[i].IPK);
		}
		fclose(DATABASE);
	}

	printf("\n\nDATA BERHASIL DISIMPAN\n\n");
}

//membaca file pada Notepad
int baca_file()
{
	header();
	FILE *DATABASE;//inisialisasi file yaitu DATABASE.txt
	int ch;
	
	DATABASE=fopen("DATABASE.txt","r");
	if(DATABASE==NULL) 
	{
		puts("Can't open that file!");
		exit;
	}
	while((ch=fgetc(DATABASE))!=EOF)
	putchar(ch);//menampilkan data dari notepad
	printf("\n");
	fclose(DATABASE);
	
}

void displayData(database *mahasiswaptr);//void unutk menampilkan data ke program dari notepad

int search(void)
{
	header();

	FILE *DATABASE;
	int index, count;
	char line[LEN_LINE + 1];
	database mahasiswa[MAX_LINE];
	DATABASE = fopen("DATABASE.txt", "r");
	
	if(DATABASE == NULL)
	{
		printf("FILE TIDAK DITEMUKAN\n");	
	} 
	else
	{
		index=0, count;
		while(index < MAX_LINE && fgets(line, LEN_LINE, DATABASE))
		{
			if(3 == sscanf(line, "%s %i %f", &mahasiswa[index].nama, &mahasiswa[index].NPM, &mahasiswa[index].IPK))//scanf dari notepad untuk dimasukkan ke program sesuai data
			{
				index++;
			}
		}
	
		fclose(DATABASE);
		count = index;
	
		for(index = 0; index < count; index = index + 1)
    	{
     	   displayData(&mahasiswa[index]);//menampilkan data
     	   printf("\n");
   		}
   		printf("\n");
   		int NPM, i;
		printf("MASUKKAN NPM YANG INGIN DICARI : ");//scanf npm yang ingin dicari
		scanf("%d", &NPM);
	
		//searching sesuai NPM
		for(i=0; i<=MAX_MAHASISWA; i++)
		{
			if(NPM == mahasiswa[i].NPM)
			{
				printf("\n--------------------------------------------------------------\n");
				printf("  MAHASISWA DENGAN NPM %d ADALAH %s DENGAN IPK %.2f", mahasiswa[i].NPM, mahasiswa[i].nama, mahasiswa[i].IPK);	//hasil pencarian dari npm
				printf("\n--------------------------------------------------------------\n\n\n");
			}
			
		}
		
	}
	return 0;

}

int konsultasi()
{
	header();
	buat();
	int n=1;
	char N;
	
	do{
		//menu untuk antrian konsultasi
		printf("1. MASUKKAN ANTRIAN\n2. PANGGIL ANTRIAN\n0. MENU SEBELUMNYA\n");
		printf("\nPILIHAN : ");
	
		switch(getch())
		{
			
			case '1':
				header();
				printf("No Antrian %i\n", n);
				data = n;
				printf("Masukkan nama : "); scanf("%s", &data1);//input nama
				printf("Masukkan NPM : "); scanf("%s", &data2);//input NPM
				printf("Masukkan IPK : "); scanf("%s", &data3);//input IPK
				
				enqueue(data, data1, data2, data3);//membuat antrian
				n++;
				
				system("pause");
				header();

			break;	
							
			case '2':
				header();
				printf("\n\n");
				dequeue();//memanggl antrian
				system("pause");
				header();
		
			break;
		
			case '0':
				header();
				return mulai();//menu sebelumnya
			
			default:
				header();
				salah();
				return konsultasi();
			break;
			
		}
	getch();
	}while(N != 4);  
	
}
//menggunakan linked list
void displayData(database *mahasiswaptr)
{
	printf("NAMA\t: %s \nNPM\t: %i \nIPK\t: %.2f\n", mahasiswaptr->nama, mahasiswaptr->NPM, mahasiswaptr->IPK);
}

//program input data
int mulai() {

	header();
	inputan();
	switch(getch())
	{
		case '1':
			data_baru();//modular data_baru()
			system("pause");
			return 0;
		case '2':
			data_lama();//modular data_lama()
			system("pause");
			return 0;
		case '3':	
			baca_file();//modular baca_file()
			system("pause");
			return 0;
		case '4':
			search();//modular seacrh
			system("pause");
			return 0;
		case '5':
			header();
			konsultasi();
			system("pause");
			return 0;
		case '0':
			menu();
			system("pause");
			return 0;	
		default:
			salah();//modular salah()
	}
	
	system("pause");
	system("cls");
}

//menu help
int help() {
	header();
	printf("Program ini dibuat untuk mempermudah user dalam memasukkan data\n\n");
	printf("Cara Memasukkan Data : \n");
	printf("1. Masukkan jumlah data yang ingin diinput lalu klik enter\n2. Masukkan Nama lalu klik enter\n3. Masukkan NPM lalu klik enter\n4. Masukkan IPK lalu klik enter\n\n");
	printf("PRESS ANY KEY TO CONTINUE\n\n");

	system("pause");
	system("cls");
	return 0;
}

//modular terima kasih
void close() {
	header();
	printf("       ooooooooooo  ooooooo     oooo        o     oo          oo         o               \n");
	printf("            o       o           o   o       o     o  o       o o        o o              \n");
	printf("            o       o           o    o      o     o    o   o   o       o   o             \n");
	printf("            o       ooooooo     oooo        o     o      o     o      o     o            \n");
	printf("            o       o           oo          o     o            o     ooooooooo           \n");
	printf("            o       o           o  o        o     o            o    o         o          \n");
	printf("            o       ooooooo     o    o      o     o            o   o           o         \n");
	printf("                                                                                         \n\n");
	printf("                  o   o           o           oooooo    o       o      o                 \n");
	printf("                  o  o           o o          o         o       o      o                 \n");
	printf("                  o o           o   o         o         o       o      o                 \n");
	printf("                  oo           ooooooo        oooooo    o       oooooooo                 \n");
	printf("                  o o         o       o            o    o       o      o                 \n");
	printf("                  o  o       o         o           o    o       o      o                 \n");
	printf("                  o   o     o           o     oooooo    o       o      o                 \n");

	system("pause");
	system("cls");
}

//modular unutk default
void salah() {
	system("cls");
	header();
	printf("DATA YANG ANDA MASUKKAN SALAH, SILAKAN ULANGI LAGI\n\n");
	system("pause");
	system("cls");
}

int main() {
	menu();
	//pilihan menu utama
	switch(getch()) { //langsung berjalan tanpa menekan enter
		case '1':
			mulai();//modular program database
			return main();

		case '2':
			help();//program modular menu help
			return main();

		case '3':
			close();//modular close
			return 0;

		default:
			salah();//modular salah input
			return main();
	}
}

/*
	REFERENSI:
	1. https://stackoverflow.com/questions/45192223/how-to-search-through-an-array-of-struct-c-programming
	2. http://www.cplusplus.com/reference/cstdio/sscanf/
	3. https://www.dummies.com/programming/c/basics-of-sequential-file-access-in-c-programming/
	
	AHMAD FAKHRUL FAUZI (1706985855)
	SULAIMAN IVAN ACHMADI ()
*/
