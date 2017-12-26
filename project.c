#include <stdio.h>

void kasir();
void tambah();

int main(){
    int menu;
    printf("++---------------------------------------------------++\n");
    printf("   1.Kasir    2.Tambah data\n");
    printf("++---------------------------------------------------++\n\n");
    printf("Pilih menu : ");
    scanf("%d",&menu);

    if(menu == 1){
        kasir();
    }else if(menu == 2){
        tambah();
    }
}

void tambah(){
    char nama[100], jwbn;
	int harga;

	do{
        printf("Masukkan nama : "); scanf("%s", &nama);
        printf("Masukkan harga : "); scanf("%d", &harga);
        FILE *out=fopen("test.txt","a");
        fprintf(out,"%s#%d\n",nama, harga);
        printf("Sukses menambah data.\n\n");fflush(stdin);
        printf("Ada lagi [Y/T]	? ");
		scanf("%c", &jwbn);
	}while(jwbn == 'Y' || jwbn == 'y');
}

void kasir(){
	char nama[100],jwbn;
        int harga,harga2,jml,bayar,kembali,kode2,kode = 1, total=0;
    printf("++***************************************************++\n");
    printf("                    MENU MAKANAN\n");
    printf("++***************************************************++\n");
    printf("         - Masukkan kode makanan <spasi> jumlahnya\n");
    printf("         - Contoh 1 2\n");
    printf("++-------------------------------------------------------------------++\n");
    printf("|| Kode       || Nama Makanan    \t\t|| Harga           ||\n");
    printf("++-------------------------------------------------------------------++\n");
    FILE *in=fopen("test.txt","r");
    while(!feof(in)){
    fscanf(in,"%[^#]#%d\n", &nama, &harga);fflush(stdin);
           // %[^#] artinya kita menyimpan bagian dari string dalam file sampai tanda #.
           // Kita tidak menggunnakan %s karena nama mengandung spasi

    printf("|| %d             %s                    Rp. %d          ||\n", kode, nama, harga);
    kode++;
    }
    printf("++-------------------------------------------------------------------++\n");

	do{
        printf("\t\t\t\t\tPesanan : ");
        scanf("%d %d",&kode2, &jml);fflush(stdin);
        printf("\t\t\t\t\tHarga : ");
        scanf("%d",&harga2);fflush(stdin);
        total = total+(harga2 * jml);

        printf("\t\t\t\t\tAda pesanan lagi [Y/T]	? ");
		scanf("%c", &jwbn);

		if(jwbn == 't' || jwbn == 'T'){
            printf("\t\t\t\t\tBayar : ");
            scanf("%d",&bayar);fflush(stdin);
		}
	}while(jwbn == 'Y' || jwbn == 'y');

	printf("\n\t\t\t\t\tTOTAL HARGA : %d", total);
	kembali = bayar - total;
	printf("\n\t\t\t\t\tKEMBALIAN : %d\n\n",kembali);
	system("pause");
	fclose(in);
	getchar();
        return 0;
}

