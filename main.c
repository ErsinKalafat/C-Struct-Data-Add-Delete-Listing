#include <stdio.h>
#include <stdlib.h>

struct rehber
{
    char ad[10];
    char soyad[10];
    char tel[10];
};

void kayitEkle(struct rehber kayit)
{
    FILE * dosya;
    if((dosya = fopen("D:/rehber.txt" , "a")) == NULL)
    {
        printf("dosya bulunamadi");
        exit(1);
    }
    fprintf(dosya, "\n%s %s %s", kayit.ad, kayit.soyad, kayit.tel);
    fclose(dosya);
}

void listele()
{
    FILE * dosya = fopen("D:/rehber.txt" , "r");
    if(dosya == NULL)
    {
        printf("dosya bulunamadi");
        exit(1);
    }
    while(1)
    {
        struct rehber listelenen;
        size_t sayi = fread(&listelenen, sizeof(struct rehber), 1, dosya);
        if (sayi<1){ break; }
        printf("%s %s %s\n", listelenen.ad, listelenen.soyad, listelenen.tel);
    }
    fclose(dosya);
}

void kayitSil()
{
    FILE * dosya = fopen("D:/rehber.txt" , "w");
    if(dosya == NULL)
    {
        printf("dosya bulunamadi");
        exit(1);
    }

    fclose(dosya);
}

int main()
{
    int secim;
    while(1)
    {
        printf("Lutfen islem seciniz : ");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:
        {
            struct rehber kayit;
            printf("ad, soyad, tel ? :");
            scanf("%s %s %s", kayit.ad, kayit.soyad, kayit.tel);
            kayitEkle(kayit);
            break;
        }
        case 2:
        {
            listele();
            break;
        }
        case 3:
        {
            kayitSil();
            break;
        }
        default:
            printf("yanlis secim");

        };
    }

    return 0;
}
