#include <stdio.h>
#include <stdlib.h>


//23100011055
//ELIF SULTAN TURKYILMAZ

struct kitap
{   int barkod;
    char  kitapadi[50];
    char yazaradi[50];
    char yayineviadi[50];
    char kitapturu[25];
    char temintarihi[30];
    int stoksayisi;
    struct kitap*yeni;
};
struct kitap *kutuphane = NULL;//kitaplari tutan yer
struct uye
{ int uyekayitno;
  char tc[15];
  char adi[20];
  char soyadi[30];
  char cinsiyet[1];
  char dogumtarihi[20];
  char telefon[30];
  char mail [50];
  char uyeliktarihi[20];
  char adres[100];
  struct uye *yeni2 ;
};
struct uye *uyeler = NULL;//uyeleri tutan yer
 struct emanet{
  int uyekayitno;
  char adsoyadi[50];
  int barkod;
  char kitapadi[50];
  struct emanet*euye;
 };
struct emanet*emanetler=NULL;//emanet kitaplari tutan yer

int menu();
void kitapislemleri();
void kitapekle();
void kitapsilme();
void kitaplistele();
void kguncelleme();
void kitapara();
void uyeislemleri();
void uyeekle();
void uyesilme();
void uyelistele();
void uguncelleme();
void uyeara();
void emanetkitapislemleri();
void ekitapkayit();
void ekitaplistele();
void ekitapiade();



int main()
{
    menu();

    return 0;
}
int menu ()
{   system("cls");
    int secim;
    printf ("\t***HALK KUTUPHANESINE HOSGELDINIZ***\n\n");
    printf ("1-KITAP ISLEMLERI\n");
    printf ("2-UYE ISLEMLERI\n");
    printf ("3-EMANET KITAP ISLEMLERI\n");
    printf ("0-PROGRAMI KAPAT\n\n");
    printf ("SECIMINIZ:");
    scanf("%d",&secim);
    switch(secim)
    {
    case 1:
        kitapislemleri();
        break;
    case 2 :
        uyeislemleri();
        break;
    case 3 :
        emanetkitapislemleri();
        break;
    case 0:
        printf ("PROGRAMI KAPATTINIZ.");
        break;
    default :
        printf("HATALI SECIM YAPTINIZ!\n");
        return menu();
    }

}
void kitapislemleri()
{
    system ("cls");
    printf ("**KITAP ISLEMLERI MENUSUNE GELDINIZ **\n");
    int secim;
    printf("1-Kitap Ekleme\n");
    printf("2-Kitap Silme\n");
    printf("3-Kitaplari Listele\n");
    printf ("4-Guncelleme\n");
    printf ("5-Kitap Ara\n");
    printf ("0-Menuye don\n");
    printf ("Seciminiz:");
    scanf ("%d",&secim);

    switch (secim)
    {
    case 1 :
        kitapekle();
        break;
    case 2:
        kitapsilme();
        break;
    case 3:
        kitaplistele();
        break;
    case 4:
        kguncelleme();
        break;
    case 5:
        kitapara();
        break;
    case 0:
        menu();
        break;
    default :
        printf("HATALI SECIM YAPTINIZ!");
        return menu();
    }
}

void kitapekle()
{
    system("cls");
    struct kitap *yenikitap = (struct kitap *)malloc(sizeof(struct kitap));//mallocla yer actım

    printf("Barkod No: ");
    scanf("%d",&yenikitap->barkod);
    printf("Kitap Adi: ");
    gets (yenikitap->kitapadi);
    scanf("%s", yenikitap->kitapadi);
    printf("Kitap Yazari: ");
    gets (yenikitap->yazaradi);
    scanf("%s", yenikitap->yazaradi);
    printf("Kitap Yayinevi: ");
    gets (yenikitap->yayineviadi);
    scanf("%s", yenikitap->yayineviadi);
    printf("Kitap Turu: ");
    gets (yenikitap->kitapturu);
    scanf("%s", yenikitap->kitapturu);
    printf("Temin Tarihi: ");
    scanf("%s", yenikitap->temintarihi);
    printf("Stok Sayisi: ");
    scanf("%d",&yenikitap->stoksayisi);

    yenikitap->yeni = kutuphane; //kitabi kutuphaneye kaydediyor
    kutuphane = yenikitap;

    printf("Kitap basariyla eklendi.\n");
    int secim;
        printf ("Tekrar kitap eklemek istermisiniz (evet[1]/hayir[0])?\n");
        scanf("%d",&secim);
        if (secim==1){
            kitapekle();
        }
       if (secim==0){
        kitapislemleri();
       }
       if (secim!=0 && secim!=1) {
        printf ("Yanlis deger girdiniz!!!");
       }
}

void kitapsilme()
{
    system("cls");
    int barkodno;
    struct kitap *gecici, *eski;//kitaplari kaydirmak icin iki pointer oluşturdum.

    if (kutuphane == NULL)
    {
        printf("Kutuphane bos. Silinecek kitap yok.\n");
        return;
    }

    printf("Silinecek kitabin Barkod No'sunu giriniz: ");
    scanf("%d", &barkodno);
    gecici = kutuphane;
    eski = NULL;

    if(gecici!= NULL && gecici->barkod != barkodno)
    {
        eski = gecici;
        gecici = gecici->yeni;
    }

    if (gecici == NULL)
    {
        printf("Kitap bulunamadi. Silme islemi iptal edildi.\n");
        return;
    }

    if (eski == NULL)
    {
        kutuphane = gecici->yeni;
    }
    else
    {
        eski->yeni = gecici->yeni;
    }

    free(gecici);//realloc ile silemedim o yuzden free kullandim.
    printf("Kitap basariyla silindi.\n");
    kitapislemleri();
}
void kitaplistele()
{   system("cls");
    struct kitap *gecici = kutuphane;

    if (gecici == NULL)
    {
        printf("Kutuphane bos. Listelenecek kitap yok.\n");
        return;
    }

    printf("Kutuphanedeki Kitaplar:\n");
    while (gecici != NULL)
    {
        printf("Barkod No: %d\n", gecici->barkod);
        printf("Kitap Adi: %s\n", gecici->kitapadi);
        printf("Kitap Yazari: %s\n", gecici->yazaradi);
        printf("Kitap Yayinevi: %s\n", gecici->yayineviadi);
        printf("Kitap Turu: %s\n", gecici->kitapturu);
        printf("Temin Tarihi: %s\n", gecici->temintarihi);
        printf("Stok Sayisi: %d\n", gecici->stoksayisi);
        printf("----------------------\n");

        gecici = gecici->yeni;
    }

}
void kguncelleme()
{   system ("cls");
    int barkodno;
    struct kitap *gecici;

    if (kutuphane == NULL)
    {
        printf("Kutuphane bos. Guncellenecek kitap yok.\n");
        return;
    }

    printf("Guncellenecek kitabin Barkod No'sunu giriniz: ");
    scanf("%d", &barkodno);

    gecici = kutuphane;

    if(gecici != NULL && gecici->barkod!= barkodno)
    {
        gecici = gecici->yeni;
    }

    if (gecici == NULL)
    {
        printf("Kitap bulunamadi. Guncelleme islemi iptal edildi.\n");
        return kitapislemleri();
    }
    printf("Barkod No: ");
    scanf("%d", gecici->barkod);
    printf("Kitap Adi: ");
    gets (gecici->kitapadi);
    scanf("%s", gecici->kitapadi);
    printf("Kitap Yazari: ");
    gets (gecici->yazaradi);
    scanf("%s",gecici->yazaradi);
    printf("Kitap Yayinevi: ");
    gets (gecici->yayineviadi);
    scanf("%s",gecici->yayineviadi);
    printf("Kitap Turu: ");
    gets (gecici->kitapturu);
    scanf("%s",gecici->kitapturu);
    printf("Temin Tarihi: ");
    scanf("%s",gecici->temintarihi);
    printf("Stok Sayisi: ");
    scanf("%d",gecici->stoksayisi);

    printf("Kitap basariyla guncellendi.\n");
    kitapislemleri();

}
void kitapara()
{   system ("cls");
    int aranankitap;
    struct kitap *gecici = kutuphane;
    int bulundu = 0;

    if (gecici == NULL)
    {
        printf("Kutuphane bos. Aranacak kitap yok.\n");
        return;
    }

    printf("Aranacak kitabin barkodunu giriniz: ");
    scanf("%s", aranankitap);

    printf("Aranan Kitap:\n");
    while (gecici!=NULL)
    {
        if (gecici->barkod==aranankitap)
        {
            printf("Barkod No: %d\n", gecici->barkod);
            printf("Kitap Adi: %s\n", gecici->kitapadi);
            printf("Kitap Yazari: %s\n", gecici->yazaradi);
            printf("Kitap Yayinevi: %s\n", gecici->yayineviadi);
            printf("Kitap Turu: %s\n", gecici->kitapturu);
            printf("Temin Tarihi: %s\n", gecici->temintarihi);
            printf("Stok Sayisi: %d\n", gecici->stoksayisi);
            printf("----------------------\n");

            bulundu = 1;
            gecici = gecici->yeni;

        }

        else
        {
            printf("Kitap bulunamadi.\n");
        }
    }
    kitapislemleri();

}

void uyeislemleri()
{   system("cls");

    printf ("**UYE ISLEMLERI MENUSUNE GELDINIZ **\n");
    int secim;
    printf("1-Uye Ekleme\n");
    printf("2-Uye Silme\n");
    printf("3-Uyeleri Listele\n");
    printf ("4-Guncelleme\n");
    printf ("5-Uye Ara\n");
    printf ("0-Menuye don\n");
    printf ("Seciminiz:");
    scanf ("%d",&secim);

    switch (secim)
    {
    case 1 :
        uyeekle();
        break;
    case 2:
        uyesilme();
        break;
    case 3:
       uyelistele();
        break;
    case 4:
        uguncelleme();
        break;
    case 5:
        uyeara();
        break;
    case 0:
        menu();
        break;
    default :
        printf("HATALI SECIM YAPTINIZ!");
        return menu();
    }
}


void uyeekle()
{
    system ("cls");

    struct uye *yeniuye = (struct uye*)malloc(sizeof(struct uye));//mallocla yer ayirdim.

    printf("Uye Kayit No:");
    scanf("%d", yeniuye->uyekayitno);
    printf("Tc Kimlik: ");
    scanf("%s",yeniuye->tc);
    printf("Uye Adi: ");
    gets (yeniuye->adi);
    scanf("%s",yeniuye->adi);
    printf ("Uye Soyadi:");
    gets (yeniuye->soyadi);
    scanf("%s",yeniuye->soyadi);
    printf("Cinsiyet (K/E): ");
    scanf("%s",yeniuye->cinsiyet);
    printf("Dogum Tarihi: ");
    gets (yeniuye->dogumtarihi);
    scanf("%s",yeniuye->dogumtarihi);
    printf("Telefon:");
    scanf("%s",yeniuye->telefon);
    printf("E Mail: ");
    gets(yeniuye->mail);
    scanf("%d",yeniuye->mail);
    printf ("Uyelik Tarihi:");
    gets(yeniuye->uyeliktarihi);
    scanf("%s",yeniuye->uyeliktarihi);
    printf("Adres:");
    gets(yeniuye->adres);
    scanf("%s",yeniuye->adres);

    yeniuye->yeni2=uyeler;//kitabi uylere kaydediyor.
    uyeler = yeniuye;

    printf("Uye basariyla eklendi.\n");
    int secim;
        printf ("Tekrar uye eklemek istermisiniz (evet[1]/hayir[0])?\n");
        scanf("%d",&secim);
        if (secim==1){
            uyeekle();
        }
       if (secim==0){
        uyeislemleri();
       }
       if (secim!=0 && secim!=1) {
        printf ("Yanlis deger girdiniz!!!");
       }
}

void uyesilme()
{
    system("cls");
    int barkodno;
    struct uye *gecici, *eski;//kitaplari kaydirmak icin iki pointer oluşturdum.

    if (kutuphane == NULL)
    {
        printf("Silinecek uye yok.\n");
        return;
    }
   int uyeno;
    printf("Silinecek uyenin uye nosunu giriniz: ");
    scanf("%d", &uyeno);
    gecici = uyeler;
    eski = NULL;

    if(gecici!= NULL && gecici->uyekayitno!= uyeno)
    {
        eski = gecici;
        gecici = gecici->yeni2;
    }

    if (gecici == NULL)
    {
        printf("Uye bulunamadi. Silme islemi iptal edildi.\n");
        return;
    }

    if (eski == NULL)
    {
        uyeler= gecici->yeni2;
    }
    else
    {
        eski->yeni2 = gecici->yeni2;
    }

    free(gecici);//realloc ile silemedim o yuzden free kullandim.
    printf ("Uye basariyla silindi.\n");
    uyeislemleri();
}


void uyelistele()
{
    system ("cls");

    struct uye*gecici = uyeler;

    if (gecici == NULL)
    {
        printf("liste bos. Listelenecek uye yok.\n");
        return;
    }

    printf("Kutuphanedeki Uyeler:\n");
    if (gecici != NULL)
    {
        printf("Uye Kayit No: %d\n", gecici->uyekayitno);
        printf("Tc Kimlik: %s\n", gecici->tc);
        printf("Uye Adi %s\n", gecici->adi);
        printf("Uye Soyadi: %s\n", gecici->soyadi);
        printf("Cinsiyet: %s\n", gecici->cinsiyet);
        printf("Dogum Tarihi: %s\n", gecici->dogumtarihi);
        printf("Telefon No: %s\n", gecici->telefon);
        printf ("E Mail:%s\n",gecici->mail);
        printf ("Uyelik Tarihi:%s\n",gecici->uyeliktarihi);
        printf ("Adres:%s\n",gecici->adres);
        printf("----------------------\n");

        gecici = gecici->yeni2;
    }

}


void uguncelleme()
{   system ("cls");
    int uyekayitnosu;
    struct uye*gecici;

    if (uyeler == NULL)
    {
        printf("Guncellenecek uye yok.\n");
        return;
    }

    printf("Guncellenecek uyenin kayit nosunu giriniz: ");
    scanf("%d", &uyekayitnosu);

    gecici = uyeler;

    if (gecici != NULL && gecici->uyekayitno!= uyekayitnosu)
    {
        gecici = gecici->yeni2;
    }

    if (gecici == NULL)
    {
        printf("Uye bulunamadi. Guncelleme islemi iptal edildi.\n");
        return uyeislemleri();
    }
    printf("Uye Kayit No: ");
    scanf("%d", gecici->uyekayitno);
    printf("Uye Adi: ");
    gets (gecici->adi);
    scanf("%s", gecici->adi);
    printf("Uye Soyadi: ");
    gets (gecici->soyadi);
    scanf("%s",gecici->soyadi);
    printf("Cinsiyet ");
    scanf("%s",gecici->cinsiyet);
    printf("Dogum Tarihi: ");
    gets (gecici->dogumtarihi);
    scanf("%s",gecici->dogumtarihi);
    printf("Telefon: ");
    scanf("%s",gecici->telefon);
    printf("E Mail: ");
    gets(gecici->mail);
    scanf("%s",gecici->mail);
    printf("Uyelik Tarihi:");
    scanf ("%s",gecici->uyeliktarihi);
    printf ("Adres:");
    gets(gecici->uyeliktarihi);
    scanf ("%s",gecici->adres);

    printf("Uye basariyla guncellendi.\n");
    uyeislemleri();

}

void uyeara()
{system ("cls");
    int arananuye;
    struct uye *gecici = uyeler;
    int bulundu = 0;

    if (gecici == NULL)
    {
        printf(" Aranacak uye yok.\n");
        return;
    }

    printf("Aranacak uyenin uye nosunu  giriniz: ");
    scanf("%s", arananuye);

    printf("Aranan Uye:\n");
    while (gecici!=NULL)
    {
        if (gecici->uyekayitno==arananuye)
        {
            printf("Uye Kayit No : %d\n", gecici->uyekayitno);
            printf("TC: %s\n", gecici->tc);
            printf("Uye Adi: %s\n", gecici->adi);
            printf ("Uye Soyadi:%s\n",gecici->soyadi);
            printf("Cinsiyet: %s\n", gecici->cinsiyet);
            printf("Dogum Tarihi: %s\n", gecici->dogumtarihi);
            printf("Telefon: %s\n", gecici->telefon);
            printf("E Mail %d\n", gecici->mail);
            printf ("Uyelik Tarihi:%s\n",gecici->uyeliktarihi);
            printf ("Adres:%s\n",gecici->adres);
            printf("----------------------\n");

            bulundu = 1;
            gecici = gecici->yeni2;

        }

        else
        {
            printf("Uye bulunamadi.\n");
        }
    }
}



void emanetkitapislemleri()
{ system("cls");
  int secim;
  printf ("**EMANET KITAP ISLEMLERI MENUSUNE GELDINIZ**\n");
  printf ("1-Emanet Kitap Kayit\n");
  printf ("2-Emanet Kitap Alma-Iade\n");
  printf ("3-Emanet Kitap Listele \n");
  printf ("0-Menuye don\n");
  printf ("Seciminiz:");
  scanf("%d",&secim);
  switch (secim)
  { case 1:
       ekitapkayit();
       break;
   case 2:
      ekitapiade();
       break;
    case 3:
       ekitaplistele();
       break;
    case 0 :
        menu();
        break;
    default :
        printf("HATALI SECIM YAPTINIZ!");
        return menu();
    }

}

void ekitapkayit()
{ system ("cls");
    struct emanet*yeniemanet = (struct emanet *)malloc(sizeof(struct emanet));
    printf ("Uye Kayit No:");
    scanf ("%d",&yeniemanet->uyekayitno);
    printf ("Uye Ad Soyadi:");
    gets(yeniemanet->adsoyadi);
    scanf("%s",yeniemanet->adsoyadi);
    printf ("Kitap Barkod:");
    scanf ("%d",&yeniemanet->uyekayitno);
    printf("Kitap Adi:");
    gets(yeniemanet->kitapadi);
    scanf("%s",yeniemanet->kitapadi);
    yeniemanet->euye= emanetler;
    emanetler=yeniemanet;
    int secim;
    printf ("Tekrar emanet kitap kaydetmek istermisiniz (evet[1]/hayir[0])?\n");
        scanf("%d",&secim);
        if (secim==1){
           ekitapkayit();
        }
       if (secim==0){
        emanetkitapislemleri();
       }
       if (secim!=0 && secim!=1) {
        printf ("Yanlis deger girdiniz!!!");
       }

}
//girilrn alıs ve veriş tarihini hesap edip geciken gun sayisina gore fiyat hesaplayan fonksiyon
void ekitapiade()
 { system("cls");
  struct iade{
  int gun;
  int ay;
  int yil;
  }alma,iade,fark;
    fark.gun=0;
    fark.ay=0;
    fark.yil=0;

   printf("Kitap Alma Tarihi(GG-AA-YYYY): ");
   scanf("%d-%d-%d",&alma.gun, &alma.ay, &alma.yil);
   printf("Kitap Iade Tarihi(GG-AA-YYYY): ");
   scanf ("%d-%d-%d",&iade.gun, &iade.ay, &iade.yil);
    fark.gun=iade.gun - alma.gun;
    if (fark.gun<0)
    {
        fark.gun+=30;
        iade.ay--;
    }
    fark.ay=iade.ay - alma.ay;
    if (fark.ay<0)
    {
        fark.ay+=12;
        iade.yil--;
    }
    fark.yil=iade.yil - alma.yil;
    int gun_sayisi;
    gun_sayisi=((fark.yil)*365 ) +((fark.ay)*30)+ (fark.gun);
    if (gun_sayisi<=15){
        printf("Kitabi zamaninda teslim ettiniz");
    }
    else {
        gun_sayisi=gun_sayisi-15;
        printf("%d gun gec verdiniz.",gun_sayisi);
        int gec_ucreti=2;//gec getirdigi hergun icin 2 tl
        gec_ucreti = (gec_ucreti)*(gun_sayisi);
        printf("Gec iade ettiginiz icin %d tl vermeniz gerekiyor.",gec_ucreti);
    }

}


void ekitaplistele()
{system ("cls");

    struct emanet*gecici = emanetler;

    if (gecici == NULL)
    {
        printf("liste bos. Listelenecek emanet kitap yok.\n");
        return;
    }

    printf("Kutuphanedeki emanet kitaplar ve kitabi alan uyeler:\n");
    if (gecici != NULL)
    {
        printf("Uye Kayit No: %d\n", gecici->uyekayitno);
        printf("Adi Soyadi: %s\n", gecici->adsoyadi);
        printf("Kitap Barkod No: %s\n", gecici->barkod);
        printf("Kitap Adi: %s\n", gecici->kitapadi);
        printf("----------------------\n");

        gecici = gecici->euye;
    }


}

