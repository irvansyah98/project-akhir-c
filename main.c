#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inputData();
void opsi();
void tampildata();
void caridata();
void appen();
void urutkandata();
struct{
    char nama_makanan[50],urutno[1000];
    int harga;
}data[50];
FILE *kel,*nomor,*anyar;
int temp;
float tukar;
char sort[100];
char pilihan,ulang,jeneng[30],nama[100];
int juml,i=0,j,k,pil,harga1,n,harga,jmldatabaru;
float total;
int main()
{
    printf("\t\t   PROJECT AKHIR \n");
    printf("\t\t\tAPLIKASI KASIR RESTORAN\n");
    inputData();
    opsi();
}
void inputData()
{
    printf("Restoran");
    printf("===============================================================================\n");
    printf("NO\t NAMA MAKANAN\t HARGA\t\t\n");
    printf("===============================================================================\n");
    {
        kel=fopen("nama.txt","r");
        nomor=fopen("harga.txt","r");
        for(i=0;i<7+jmldatabaru;i++)
        {
            fgets(data[i].nama_makanan,50,kel);
            n=strlen(data[i].nama_makanan);
            data[i].nama_makanan[n-1]='\0';
            fscanf(nomor,"%d",&data[i].harga);
            printf("%d  %d\t %s\t\t \n",i+1,data[i].harga,data[i].nama_makanan);
        }
        fclose(kel);
        fclose(nomor);
    }
    printf("==========================================================================================================================================================================================\n");
}
void opsi()
{
   do{ printf("\nMenu: \n");
    printf("1. Cari Data\n");
    printf("2. Tambah Data Baru\n");
    printf("3. Urutkan Data\n");
    printf("4. Tampilkan Data\n");
    do{printf("\nMasukkan Pilihan: ");fflush(stdin);scanf("%c",&pilihan);
    if(pilihan=='1')
    {caridata();}
    else if(pilihan=='2')
    {appen();}
    else if(pilihan=='3')
    {urutkandata();}
    else if(pilihan=='4')
    {tampildata();}
    else
        {printf("Pilihan anda tidak ada! ulang?(y/t): ");fflush(stdin);scanf("%c",&ulang);}
    }
    while(ulang=='Y' || ulang=='y');
    printf("kembali Ke Menu?(Y/T): ");fflush(stdin);scanf("%c",&ulang);}
    while(ulang=='Y' || ulang=='y');
}

void caridata()
{
    printf("Data yang dicari berdasarkan: \n 1.HARGA\n 2.MAKANAN\n");scanf("%d",&pil);
        if(pil==1)
        {
            printf("Masukkan HARGA: ");scanf("%d",&harga1);
            system("cls");
            for(i=0;i<7+jmldatabaru;i++)
            {if(harga1==data[i].harga)
                {
                    printf("Makanan");
                    printf("==============================================================================================\n");
                    printf("NO\t HARGA\t NAMA MAKANAN\t\t\n");
                    printf("==============================================================================================\n");
                    printf("%d  %d\t %s\t\n",i+1,data[i].harga,data[i].nama_makanan);
                }
            }

        }
        if(pil==2)
        {
            printf("Masukkan Nama: ");fflush(stdin);gets(jeneng);

             for(i=0;i<7+jmldatabaru;i++)
            {   j=strstr(data[i].nama_makanan,jeneng);
                if(j!=0)
                {
                    system("cls");
                    printf("Makanan");
                    printf("==============================================================================================\n");
                    printf("NO\t HARGA\t NAMA MAKANAN\t\t\t\n");
                    printf("==============================================================================================\n");
                    printf("%d  %d\t %s\t\n",i+1,data[i].harga,data[i].nama_makanan);
                }
            }
        }
        opsi();
}
void appen()
{
    printf("Jumlah Data Makanan: ");scanf("%d",&jmldatabaru);
    kel=fopen("nama.txt","a");
    nomor=fopen("harga.txt","a");
        for(i=0;i<jmldatabaru;i++)
            {printf("%d.Masukkan Nama Makanan\n  (max 22 karakter & min 15 karakter,jika kurang dri 15 tambahkan tab!): ",i+1);fflush(stdin);gets(nama);
             fprintf(kel,"\n%s\t\t",nama);
             printf("%d.Masukkan Harga: ",i+1);scanf("%d",&harga);
             fprintf(nomor,"\n%d",harga);}
    fclose(nomor);
    fclose(kel);
    opsi();
}
void urutkandata()
{
    printf("Urutkan Berdasarkan:\n1.Harga Makanan\n");
    printf("Masukkan Pilihan: ");scanf("%d",&pil);
    anyar=fopen("baru.txt","r");
    for(i=0;i<7+jmldatabaru;i++)
        {
            fgets(data[i].urutno,100,anyar);
            n=strlen(data[i].urutno);
            data[i].urutno[n-1]='\0';
        }
        fclose(anyar);
    if(pil==1)
    {

        for(i=1;i<=7+jmldatabaru-1;i++)
     {
         for(j=i;j<7+jmldatabaru;j++)
         {
             if(data[i-1].harga<data[j].harga)
             {
                 printf("Masuk");
                 strcpy(sort,data[i-1].urutno);
                 strcpy(data[i-1].urutno,data[j].urutno);
                 strcpy(data[j].urutno,sort);
             }
         }
     }
        system("cls");
        printf("Restoran\n");
        printf("==============================================================================================\n");
        printf("NO\t HARGA\t NAMA MAKANAN\t\t\t\n");
        printf("==============================================================================================\n");
        for(i=0;i<7+jmldatabaru;i++)
        {
            printf("%d  %s\n\n\n\n",i+1,data[i].urutno);
        }
        printf("===============================================================================================\n");
        opsi();
    }
    else
    {
        printf("Pilihan Tidak Ada! kembali ke menu!");
        opsi();
    }
}
void tampildata()
{
    system("cls");
    printf("Restoran");
    printf("==============================================================================================\n");
    printf("NO\t HARGA\t NAMA MAKANAN\t\t\t\n");
    printf("==============================================================================================\n");

        kel=fopen("nama.txt","r");
        nomor=fopen("harga.txt","r");
        anyar=fopen("baru.txt","w");
        for(i=0;i<7+jmldatabaru;i++)
        {
            fgets(nama,100,kel);
            n=strlen(nama);
            nama[n-1]='\0';
            fscanf(nomor,"%d",&data[i].harga);
            fprintf(anyar,"%d\t",data[i].harga);
            fprintf(anyar," %s\t",nama);
            printf("%d  %d\t %s\t\n",i+1,data[i].harga,nama);
        }
        fclose(kel);
        fclose(nomor);
        fclose(anyar);

    printf("===============================================================================================\n");
    opsi();
}
