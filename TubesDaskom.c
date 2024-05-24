#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char username[50], pass[50];

struct
{
    char username[50], pass[50];
    int saldo;
} pengurus;

struct
{
    char nama[50], no[50], username[50], pass[50];
    int tb, bb, usia, saldo;
} pelanggan;

// funsi pengurus start
int loginpengurus();
int menupengurus();
int daftaralat();
int lihatsaldo();
int riwayatsewa();
int datapelanggan();
int hapuspelanggan();
// funsi pengurus end

// fungsi pelanggan start
int mainpelanggan();
int registrasipelanggan();
int loginpelanggan();
int menupelanggan();
// fungsi pelanggan end

int main()
{
    system("cls");
    int i;
    printf("Selamat Datang Di NgeGYM kuy\n\npress eny key to continue...\n\n");
    getchar();

    printf("Anda adalah...\n1. Pengurus\n2. Pelanggan\n3. Keluar\n");
    printf("Pilih : ");
    scanf("%d", &i);
    getchar();

    switch (i)
    {
    case 1:
        loginpengurus();
        break;

    case 2:
        mainpelanggan();
        break;

    case 3:
        printf("Terimakasih telah menggunakan aplikasi kami...\n\n");
        exit(0);
        break;

    default:
        printf("Mohon maaf pilihan tidak ada\n\n");
        main();
        break;
    }
}

// start program pengurus
int loginpengurus()
{
    int i = 3, a = 1;
    printf("\n\nSelamat datang...\nsilahkan login...\n\n");

    while (i > 0)
    {
        printf("Masukan Username : ");
        gets(username);
        printf("Masukan Password : ");
        gets(pass);

        // if (strcmp(username, "admin") == 0 && strcmp(pass, "123") == 0)
        if (a == 1)
        {
            menupengurus();
            break;
        }
        else
        {
            printf("username atau password salah...\n\n");
            i--;
        }
    }
    if (i <= 0)
    {
        printf("kesempatan anda telah habis...\n");
    }
}

int menupengurus()
{
    system("cls");
    int i;
    printf("Selamat datang...\n\n");
    printf("Menu Pengurus :\n1. Melihat Data Pelanggan\n2. Menghapus Data Pelanggan\n3. Daftar Alat\n4. Melihat Saldo\n5. Riwayat Penyewaan\n6. Log Out");
    printf("\nPilih Menu : ");
    scanf("%d", &i);
    getchar();

    switch (i)
    {
    case 1:
        datapelanggan();
        break;
    case 2:
        hapuspelanggan();
        break;
    case 3:
        daftaralat();
        break;
    case 4:
        lihatsaldo();
        break;
    case 5:
        riwayatsewa();
        break;
    case 6:
        main();
        break;
    default:
        printf("Mohon maaf pilihan tidak ada");
        menupengurus();
        break;
    }
}

int datapelanggan()
{
    FILE *daftarpelanggan;
    daftarpelanggan = fopen("daftarpelanggan.dat", "rb");
    if (daftarpelanggan == NULL)
    {
        printf("Gagal membuka file.");
        return -1;
    }
    if (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan) == 0)
    {
        printf("\ndata tidak tersedia...");
    }
    else
    {
        while (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan))
        {
            printf("\nNama : %s", pelanggan.nama);
            printf("\nNo Telpon : %s", pelanggan.no);
            printf("\nUsia (tahun): %d", pelanggan.usia);
            printf("\nBerat Badan (kg): %d", pelanggan.bb);
            printf("\nTinggi Badan (cm): %d", pelanggan.tb);
            printf("\nUsername : %s", pelanggan.username);
        }
        fclose(daftarpelanggan);
    }
    printf("\n\npress eny key to back...");
    getchar();
    menupengurus();
}

int hapuspelanggan()
{

    FILE *daftarpelanggan;
    FILE *daftarpelanggan2;
    daftarpelanggan = fopen("daftarpelanggan.dat", "rb");
    daftarpelanggan2 = fopen("daftarpelanggan2.dat", "wb");

    if (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan) == 0)
    {
        printf("\nTidak ada data yanng bisa dihapus...");
        printf("\n\npress eny key to back...");
        getchar();
        menupengurus();
    }
    else
    {
        char hapus[100];
        printf("Nama yang di hapus : ");
        gets(hapus);

        while (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan) == 1)
        {
            if (strcmp(pelanggan.nama, hapus) != 0)
            {
                fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan2);
                printf("data pelanggan telah terhapus...");
                menupengurus();
                break;
            }
            else
            {
                printf("gagal menghapus...");
                menupengurus();
                break;
            }
        }
        fclose(daftarpelanggan);
        fclose(daftarpelanggan2);
        remove("daftarpelanggan.dat");
        rename("daftarpelanggan2.dat", "daftarpelanggan.dat");
    }
}

int daftaralat(){}

int lihatsaldo() {}

int riwayatsewa() {}

// end program pengurus

// start program pelanggan
int mainpelanggan()
{
    int i;
    printf("\n\n\nSelamat datang...\n\n");

    printf("Anda ingin...\n1. Registrasi\n2. Login\n");
    printf("Pilih : ");
    scanf("%d", &i);
    getchar();

    switch (i)
    {
    case 1:
        registrasipelanggan();
        break;
    case 2:
        loginpelanggan();
        break;

    default:
        printf("Mohon maaf pilihan tidak ada");
        mainpelanggan();
        break;
    }
}

int registrasipelanggan()
{
    FILE *daftarpelanggan;
    daftarpelanggan = fopen("daftarPelanggan.dat", "ab");

    printf("Nama : ");
    gets(pelanggan.nama);

    printf("Telp : ");
    gets(pelanggan.no);

    printf("Usia (tahun): ");
    scanf("%d", &pelanggan.usia);
    printf("Berat badan (kg): ");
    scanf("%d", &pelanggan.bb);
    printf("Tinggi badan (cm): ");
    scanf("%d", &pelanggan.tb);

    getchar();
    pelanggan.saldo = 0;

    printf("Username : ");
    gets(pelanggan.username);

    printf("Password : ");
    gets(pelanggan.pass);

    fwrite(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan);
    fclose(daftarpelanggan);

    loginpelanggan();
}

int loginpelanggan()
{
    FILE *daftarpelanggan;
    daftarpelanggan = fopen("daftarPelanggan.dat", "rb");

    int i = 3;
    printf("\n\nSelamat datang...\nsilahkan login...\n\n");

    while (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan))
    {
        while (i > 0)
        {
            printf("Masukan Username : ");
            gets(username);
            printf("Masukan Password : ");
            gets(pass);
            if (strcmp(username, pelanggan.username) == 0 && strcmp(pass, pelanggan.pass) == 0)
            {
                printf("\nSelamat datang...\n\n");
                menupelanggan();
                break;
            }
            else
            {
                printf("\nusername atau password salah...\n\n");
            }
            i--;
            if (i <= 0)
            {
                printf("kesempatan anda telah habis...\n");
                main();
                break;
            }
        }
    }
}

int menupelanggan()
{
    printf("Menu :");
}

// end program pelanggan
