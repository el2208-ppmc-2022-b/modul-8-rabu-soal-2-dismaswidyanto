/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 8 - Advanced Algorithms
*Percobaan        : -
*Hari dan Tanggal : Rabu, 13 April 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	// Inisialisasi stream open
	FILE *fp;
	char namafile[20];
	char content[1000];
	char* token;

	// Inisialisasi matriks
	int mat[10][10];
	int x; int z;
	for (x = 0; x < 10; x++) {
		for (z = 0; z < 10; z++) {
			mat[x][z] = 0;
		}
	}

	// Buka file
	printf("Masukkan nama file: ");
	scanf("%s", ...);
	fp = fopen(..., "r");

	// Ekstraksi informasi dari file
	x = 0; z = 0;
	while(fgets(content,1000,fp) != NULL) {
		while (z<10) {
			// End of line
			if (z == 9) {
				token = strtok(NULL,"\n");
			}
			// Beginning of line
			else if (z == 0) {
				token = strtok(content,",");
			}
			else {
				token = strtok(NULL,",");
			}
			// Pengisian matriks
			mat[x][z] = atoi(token);
			++z;
			}
		z = 0;
		x++;
	}

	// Di tahap ini, matriks sudah selesai dibuat

	/**
	 * 
	 * Kamu bisa mengisi bagian ini untuk algoritma pencarian jalur makanan terbanyak
	 * Semangat modul terakhirnya :D Mudah2an templatenya membantu (y)
	 * 
	 * */

	printf("Makanan terbanyak: %d",...);

	return 0;
}
