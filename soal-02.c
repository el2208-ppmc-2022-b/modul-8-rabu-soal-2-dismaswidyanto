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

/**
 * @brief Fungsi untuk memroses matriks
 * 
 * @param mat matriks yang ditinjau
 * @param col indeks untuk kolom yang sedang ditinjau
 * @param row indeks untuk baris yang sedang ditinjau
 * @return (int) dikembalikan dengan nilai integer
 */
int process(int mat[10][10], int col, int row);

/**
 * @brief Fungsi untuk menentukan input mana yang lebih besar
 * 
 * @param a input 1
 * @param b input 2
 * @return (int) bilangan yang lebih besar
 */
int max(int a, int b);

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
	scanf("%s", namafile);
	fp = fopen(namafile, "r");

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

	int res = process(mat,0,0);
	printf("Makanan terbanyak: %d",res);
}

int process(int mat[10][10], int col, int row) {
	// Inisialisasi hasil komputasi untuk 4 cabang
	int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
	// Kurangi makanan pada node yang sedang dipijak
	mat[row][col] -= 1;

	// Evaluasi kiri dan kanan node yang dipijak
	if (row == 0 && col == 0) {
		if (mat[row+1][col] <= 0) {
			// do nothing 
		}
		else {
			res1 = process(mat, col, row+1);
		}
		if (mat[row][col+1] <= 0) {
			// do nothing
		}
		else {
			res2 = process(mat, col+1, row);
		}
	}
	else if (row == 9 && col == 0) {
		if (mat[row][col+1] <= 0) {
			// do nothing
		}
		else {
			res1 = process(mat, col+1, row);
		}
		if (mat[row-1][col] <= 0) {
			// do nothing
		}
		else {
			res2 = process(mat, col, row-1);
		}
	}
	else if (row == 0 && col == 9) {
		if (mat[row][col-1] <= 0) {
			// do nothing
		}
		else {
			res1 = process(mat, col-1, row);
		}
		if (mat[row+1][col] <= 0) {
			// do nothing
		}
		else {
			res2 = process(mat, col, row+1);
		}
	}
	else if (row == 9 && col == 9) {
		if (mat[row][col-1] <= 0) {
			// do nothing
		}
		else {
			res1 = process(mat, col-1, row);
		}
		if (mat[row-1][col] <= 0) {
			// do nothing
		}
		else {
			res2 = process(mat, col, row-1);
		}
	}
	else if (row == 0 && col != 0 && col != 9) {
		if (mat[row][col-1] <= 0) {
			// do nothing
		}
		else {
			res1 = process(mat, col-1, row);
		}
		if (mat[row][col+1] <= 0) {
			// do nothing
		}
		else {
			res2 = process(mat, col+1, row);
		}
		if (mat[row+1][col] <= 0) {
			// do nothing
		}
		else {
			res3 = process(mat, col, row+1);
		}
	}
	else if (row == 9 && col != 0 && col != 9) {
		if (mat[row][col-1] <= 0) {
			// do nothing
		}
		else {
			res1 = process(mat, col-1, row);
		}
		if (mat[row][col+1] <= 0) {
			// do nothing
		}
		else {
			res2 = process(mat, col+1, row);
		}
		if (mat[row-1][col] <= 0) {
			// do nothing
		}
		else {
			res3 = process(mat, col, row-1);
		}
	}
	else if (col == 0 && row != 0 && row != 9) {
		if (mat[row-1][col] <= 0) {
			// do nothing
		}
		else {
			res1 = process(mat, col, row-1);
		}
		if (mat[row+1][col] <= 0) {
			// do nothing
		}
		else {
			res2 = process(mat, col, row+1);
		}
		if (mat[row][col+1] <= 0) {
			// do nothing
		}
		else {
			res3 = process(mat, col+1, row);
		}
	}
	else if (col == 9 && row != 0 && row != 9) {
		if (mat[row-1][col] <= 0) {
			// do nothing
		}
		else {
			res1 = process(mat, col, row-1);
		}
		if (mat[row+1][col] <= 0) {
			// do nothing
		}
		else {
			res2 = process(mat, col, row+1);
		}
		if (mat[row][col-1] <= 0) {
			// do nothing
		}
		else {
			res3 = process(mat, col-1, row);
		}
	}
	else {
		if (mat[row-1][col] <= 0) {
			// do nothing
		}
		else {
			res1 = process(mat, col, row-1);
		}
		if (mat[row+1][col] <= 0) {
			// do nothing
		}
		else {
			res2 = process(mat, col, row+1);
		}
		if (mat[row][col-1] <= 0) {
			// do nothing
		}
		else {
			res3 = process(mat, col-1, row);
		}
		if (mat[row][col+1] <= 0) {
			// do nothing
		}
		else {
			res4 = process(mat, col+1, row);
		}
	}

	// Kembalikan nilai makanan yang sudah dipijak untuk rekursi cabang lain
	mat[row][col] += 1;

	// Kembalikan nilai tertinggi
	return(1+max(max(res1, res2), max(res3, res4)));
}

int max(int a, int b) {
	if (a>b) {
		return a;
	}
	else {
		return b;
	}
}
