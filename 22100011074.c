#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//AD: SUDE
//SOYAD: OZSOY
//OGRENCİ NO: 22100011074

/*Siprais otomasyonudur. Iki tane menu vardir, ikinci menuye kullanici giris kismindan sonra ulasilir.
-Ekleme fonksiyonu: yeniMusteri, siparisEkle olmak uzere iki tanedir.
-Listele fonksiyonu: kullanıcıBilgi, bilgilerim ,urunler olmak uzere uc tanedir.
-Guncelleme fonksiyonu: bilgiGuncelle olmak uzere bir tanedir.
-Silme fonksiyonu: musteriSil olmak uzere bir tanedir.
-Ek fonksiyon olarak musteriGiris ve kampanyaUygula kullandim.*/
struct urun
{
    char ad[20];
    float fiyat;
    float hesap;
};
struct urun *purun;
struct mAdres
{
    char il[10];
    char ilce[15];
    char mah[30];
    int no;
    int kat;
};
struct musteri
{
    char ad[15];
    char soyad[15];
    char eposta[30];
    struct mAdres adr;
    int tel;
    char id[10];
    char parola[15];
};
struct musteri *ptr;
int menu()                          //Ana menudur.
{
    int secim;
    printf("------------SIPARIS OTOMASYONU-----------\n");
    printf("\t(1)-Musteri giris     \n");
    printf("\t(2)-Urunleri listele  \n");
    printf("\t(3)-Yeni musteri ekle \n");
    printf("\t(4)-Musterilerin bilgisi \n");
    printf("\t(0)-Programi kapat    \n");
    printf("\tSecim yapin: ");
    scanf("%d",&secim);
    system("cls");
    return secim;
}
void menu2()                       //Musteri giris yaptiktan sonra ekranda yazacak menudur.
{
    int secim;
    printf("-------KULLANICI ISLEM EKRANI------\n");
    printf("\t(1)-Siparis ekle          \n");
    printf("\t(2)-Bilgilerimi guncelle  \n");
    printf("\t(3)-Bilgilerimi goruntule \n");
    printf("\t(4)-Musteri kaydimi sil   \n");
    printf("\t(0)-Ana menuye don        \n");
    printf("\tSecim yapin: ");
    scanf("%d",&secim);

    switch(secim)
    {
    case 1:
        siparisEkle();
        break;
    case 2:
        bilgiGuncelle();
        break;
    case 3:
        bilgilerim();
        break;
    case 4:
        musteriSil();
        break;
    case 0:
        main();
        break;
    default:
        system("cls");
        printf("Yanlis sayi girisi!");
        break;
    }
   system("cls");
}
int art=0;                   //Kac musteri oldugunu hesaplamasi icin.
void musteriGiris()          //Musterinin giris bilgileri dogru oldugunda bi sonraki menuye yonlendirir.
{
    char parola[15],id[15];
    int secim,i;
    if(art==0)              //Art degeri kac musteri oldugunu gosterir.Musteri yoksa ana menuye yonlendirir.
    {
        system("cls");
        printf("**Hic kullanici bilgisi bulunamadi, once kayit olunuz!\n\n");
        main();
    }
    else
    {
        printf("\n-------GIRIS EKRANI-------\n");
        printf("Kullanici adi: ");
        scanf("%s",id);
        printf("Parola: ");
        scanf("%s",parola);
        for(i=0; i<art; i++)    //Kaydedilmis kullanicilarin bilgilerini gezmesi icin.
        {
            if(strcmp((ptr+i)->parola,parola)==0 && strcmp((ptr+i)->id,id)==0) //Girilen bilgilerle kayitli bilgilerin eslesip eslesmedigini kontrol eder.
            {
                system("cls");
                printf("\nGiris yapildi, hosgeldiniz:)\n\n");
                menu2();
            }
        }
        system("cls");
        printf("Yanlis sifre veya kullanici adi!!\n");
        musteriGiris();
    }
}
void urunler()
{
    purun =(struct urun *)malloc(10*sizeof(struct urun));     //Urun bilgileri icin bellekte yer ayirir.
    if(purun==NULL)                      //Bellekte yer acilip acilmadigini kontrol eder.
    {
        printf("Bellekte yer ayrilamiyor!!\n");
    }
    printf("---------------URUNLER---------------\n");
    strcpy(purun->ad,"Kucuk Boy Pizza\t");
    purun->fiyat=55;
    strcpy((purun+1)->ad,"Orta Boy Pizza     ");
    (purun+1)->fiyat=85;
    strcpy((purun+2)->ad,"Buyuk Boy Pizza    ");
    (purun+2)->fiyat=105;
    strcpy((purun+3)->ad,"Hamburger Menu     ");
    (purun+3)->fiyat=57;
    strcpy((purun+4)->ad,"CheeseBurger Menu  ");
    (purun+4)->fiyat=55;
    strcpy((purun+5)->ad,"Kofte[1 prs.+pilav]");
    (purun+5)->fiyat=70;
    strcpy((purun+6)->ad,"Patates            ");
    (purun+6)->fiyat=30;
    strcpy((purun+7)->ad,"Lahmacun           ");
    (purun+7)->fiyat=22;
    strcpy((purun+8)->ad,"Iskender Menu      ");
    (purun+8)->fiyat=80;
    strcpy((purun+9)->ad,"Etli Ekmek         ");
    (purun+9)->fiyat=50;

    printf("\t     URUN:                FIYAT:\n");
    for(int i=0; i<10; i++)                         //Kaydedilen urun bilgilerini yazdirir.
    {
        printf("\t(%d) %s  ->%.0fTL \n",i+1,(purun+i)->ad,(purun+i)->fiyat);
    }
    printf("\n");

}
void kullaniciBilgi()             //Tum kullanicilarin ad-soyad bilgisi goruntulenir.
{
    int i;
    printf("----Kullanicilarin ad-soyad bilgisi.----\n");
    for(i=0; i<art; i++)         //Toplam kullanici sayisina ulasana kadar kullanici bilgilerini yazdirmak icin.
    {
        printf("(%d) Ad:%s  Soyad:%s \n",i,(ptr+i)->ad,(ptr+i)->soyad);
    }
    printf("----------------------------------------\n\n");
    main();
}
int yeniMusteri()
{
    if(art==0)
    {
        ptr =(struct musteri *)malloc(1*sizeof(struct musteri));      //Hic kullanici kaydedilmemisse 1 kisilik yer acar.
    }
    else
    {
        ptr=(struct musteri *)realloc(ptr,sizeof(struct musteri)*(art+1));   //Yeni kullanici eklemek için bellegi 1 kisilik genisletir.
    }
    if(ptr==NULL)                       //Bellekte yer acilip acilmadigini kontrol eder.
    {
        printf("Bellekte yer ayrilamiyor!!\n");
    }
    printf("\t--Yeni musteri bilgi girisi:\n");
    printf("\tAd: ");
    scanf("%s",(ptr+art)->ad);
    printf("\tSoyad: ");
    scanf("%s",(ptr+art)->soyad);
    printf("\tEposta: ");
    scanf("%s",(ptr+art)->eposta);
    printf("\t--Adres Bilgileri--\n");
    printf("\tIl: ");
    scanf("%s",(ptr+art)->adr.il);
    printf("\tIlce: ");
    scanf("%s",(ptr+art)->adr.ilce);
    printf("\tMah:");
    scanf("%s",(ptr+art)->adr.mah);
    printf("\tNo: ");
    scanf("%d",&(ptr+art)->adr.no);
    printf("\tKat: ");
    scanf("%d",&(ptr+art)->adr.kat);
    printf("\tTelefon: ");
    scanf("%d",&(ptr+art)->tel);

tekrar:
    printf("\tKullanici adi:");
    scanf("%s",(ptr+art)->id);
    printf("\tParola(En az 8 karakter):    ");
    scanf("%s",(ptr+art)->parola);

    if(strlen((ptr+art)->parola)>=8)        //Sifrenin uzunlugunun 8den buyuk olup olmadıgını kontrol eder.
    {
        if(art!=0)                          //Daha once kullanici girisi olup olmadıgını kontrol eder.
        {
            for(int i=0; i<=art; i++)       //Kayitli kullanici bilgilerini gezmek icin.
            {
                if(strcmp((ptr+art)->id,(ptr+i)->id)==0)     //Kayitli kullanicilarla aynı kullanici adini kullanmamasi icin.
                {
                    system("cls");
                    printf("\nBu kullanici adi kullaniliyor.Tekrar deneyin.\n\n");
                    goto tekrar;                  //Tekrar kullanici adi ve sifre almak icin geri doner.
                }
                else
                {
                    system("cls");
                    printf("*Musteri eklendi!*\n\n");
                    art++;                  //Yeni eklenen kullaniciyla kullanici sayisini artirir.
                    main();
                }
            }
        }
        else
        {
            system("cls");
            printf("*Musteri eklendi!*\n\n");
            art++;
            main();
        }

    }
    else
    {
        system("cls");
        printf("\nParolanin en az 8 karakater olmasina dikkat edin!\n\n");
        goto tekrar;
    }

    return art;
}
float hesap=0;
struct urun *sip;
void siparisEkle()
{
    int secim,tkr=0,n;
    float fiyat=0;
    hesap=0;

    urunler();         //Urunleri ekrana yazdirmasi icin.
    printf("\t(0) Onceki ekrana don.\n");
tekrar:
    printf("Secim yapiniz:");
    scanf("%d",&secim);

    switch(secim)
    {
    case 1:
        fiyat=purun->fiyat;       //Bellege kaydedilmis fiyat degiskenini hesaplada kullanmasi icin yeni degiskene atar.
        printf("->Kac tane istiyorsunuz?");
        scanf("%d",&n);
        fiyat*=n;                 //Urunun fiyatiyla istenen adedi carpar ve toplam fiyati hesaplar.
        break;
    case 2:
        fiyat=(purun+1)->fiyat;
        printf("->Kac tane istiyorsunuz?");
        scanf("%d",&n);
        fiyat*=n;
        break;
    case 3:
        fiyat=(purun+2)->fiyat;
        printf("->Kac tane istiyorsunuz?");
        scanf("%d",&n);
        fiyat*=n;
        break;
    case 4:
        fiyat=(purun+3)->fiyat;
        printf("->Kac tane istiyorsunuz?");
        scanf("%d",&n);
        fiyat*=n;
        break;
    case 5:
        fiyat=(purun+4)->fiyat;
        printf("->Kac tane istiyorsunuz?");
        scanf("%d",&n);
        fiyat*=n;
        break;
    case 6:
        fiyat=(purun+5)->fiyat;
        printf("->Kac tane istiyorsunuz?");
        scanf("%d",&n);
        fiyat*=n;
        break;
    case 7:
        fiyat=(purun+6)->fiyat;
        printf("->Kac tane istiyorsunuz?");
        scanf("%d",&n);
        fiyat*=n;
        break;
    case 8:
        fiyat=(purun+7)->fiyat;
        printf("->Kac tane istiyorsunuz?");
        scanf("%d",&n);
        fiyat*=n;
        break;
    case 9:
        fiyat=(purun+8)->fiyat;
        printf("->Kac tane istiyorsunuz?");
        scanf("%d",&n);
        fiyat*=n;
        break;
    case 0:
        menu2();
        break;
    default:
        printf("*Yanlis sayi girisi!*");
        break;
    }
    hesap+=fiyat;                          //Yeni eklenen her urunu toplam hesaba eklemek icin.
    printf("Extra urun eklemek icin 1'e tiklayiniz:");
    scanf("%d",&tkr);
    switch(tkr)                            //Eklenen urunun yanina yeni urunler eklemek icin kullanilir.
    {
    case 1:
        goto tekrar;
        break;
    default:
        printf("\n**Kampanyasiz tutar: %.2f\n",hesap);
        kampanyaUygula();                   //Hesabin ustune kampanya eklemek icin fonksiyon cagirilir.
        break;
    }
}
void bilgiGuncelle()             //Kullanici sadece kendi bilgilerini gunceller.
{
    int i,sira;
    char sifre[15];
    for(i=0; i<art; i++)        //Kayitli kullanicilari yazdirir.
    {
        printf("(%d) %s %s \n",i,(ptr+i)->ad,(ptr+i)->soyad);
    }
    printf("Kacinci kullanici oldugunuzu seciniz:");
    scanf("%d",&sira);
    if(sira<=art)              //Dogru secim yapip yapmadigini kontrol eder.
    {
        printf("Sifrenizi giriniz:");
        scanf("%s",sifre);
        if(strcmp((ptr+sira)->parola,sifre)==0)   //Bilgileri degistirme izni icin sifre girilir. Girilen sifrenin eslesip eslesmedigini kontrol eder.  zj
        {
            system("cls");
            printf("--Bilgi guncelleme ekrani:\n");
            printf("\tAd: ");                     //Yeni bilgileri alir.
            scanf("%s",(ptr+sira)->ad);
            printf("\tSoyad: ");
            scanf("%s",(ptr+sira)->soyad);
            printf("\tEposta: ");
            scanf("%s",(ptr+sira)->eposta);
            printf("\t--Adres Bilgileri--\n");
            printf("\tIl: ");
            scanf("%s",(ptr+sira)->adr.il);
            printf("\tIlce: ");
            scanf("%s",(ptr+sira)->adr.ilce);
            printf("\tMah:");
            scanf("%s",(ptr+sira)->adr.mah);
            printf("\tNo: ");
            scanf("%d",&(ptr+sira)->adr.no);
            printf("\tKat: ");
            scanf("%d",&(ptr+sira)->adr.kat);
            printf("\tTelefon: ");
            scanf("%d",&(ptr+sira)->tel);
tekrar:
            printf("\tKullanici adi:");
            scanf("%s",(ptr+sira)->id);
            printf("\tParola(En az 8 karakter):    ");
            scanf("%s",(ptr+sira)->parola);

            if(strlen((ptr+sira)->parola)>=8)        //parolanin uzunlugunu kontrol eder.
            {
                if(sira!=0)                          //Eger tek kullanici degilse diger kullaniciların kullanici adini almamasi icin kontrol.
                {
                    for(int i=0; i<=sira; i++)       //Kullanicilarin bilgilerini gezer.
                    {
                        if(sira!=i)                  //Kendi degistirmek uzere oldugu bilgileriyle karsilastirmamasi icin.
                        {
                            if(strcmp((ptr+sira)->id,(ptr+i)->id)==0)     //Eger girilen kullanici adi baskasina aitse yeni bilgi girilir.
                            {
                                system("cls");
                                printf("\nBu kullanici adi kullaniliyor.Tekrar deneyin.\n");
                                goto tekrar;                            //Yeni bilgi girilmesi icin geri doner.
                            }
                            else
                            {
                                system("cls");
                                printf("*Yaptiginiz degisiklikler kaydedilmistir.*\n\n");
                                menu2();
                            }
                        }
                        else
                        {
                            system("cls");
                            printf("*Yaptiginiz degisiklikler kaydedilmistir.*\n\n");
                            menu2();
                        }
                    }
                }
                else
                {
                    system("cls");
                    printf("*Yaptiginiz degisiklikler kaydedilmistir.*\n\n");
                    menu2();
                }
            }
            system("cls");
            printf("*Yaptiginiz degisiklikler kaydedilmistir.*\n\n");
            menu2();
        }
        else
        {
            system("cls");
            printf("\n*Yanlis sifre veya kullanici girisi!*\n\n");
            menu2();
        }
    }
    else
    {
        system("cls");
        printf("\n*Yanlis sayi girisi!*\n\n");
        menu2();
    }

}
void bilgilerim()            //Kullanici kendi bilgilerini goruntuler.
{
    int i,sira;
    char sifre[15];
    for(i=0; i<art; i++)
    {
        printf("%d.kullanici: %s %s \n",i,(ptr+i)->ad,(ptr+i)->soyad);
    }
    printf("Kacinci kullanici oldugunuzu seciniz:");
    scanf("%d",&sira);
    printf("Sifrenizi giriniz:");
    scanf("%s",sifre);
    if(sira<=art)                 //Girilen sayinin dogrulugunu kontrol eder.
    {
        if(strcmp((ptr+sira)->parola,sifre)==0)        //Islemler icin sifreyi kontrol eder.
        {
            system("cls");
            printf("\n\t****BILGILERIM****\n");    //Bilgileri yazdirir.
            printf("\t *Ad:%s  *Soyad:%s \n",(ptr+sira)->ad,(ptr+sira)->soyad);
            printf("\t *Eposta:%s  *Telefon:%d  *Kullanici  Adi:%s\n",(ptr+sira)->eposta,(ptr+sira)->tel,(ptr+sira)->id);
            printf("\t *Adres: %s %s %s no:%d kat:%d \n\n",(ptr+sira)->adr.il,(ptr+sira)->adr.ilce,(ptr+sira)->adr.mah,(ptr+sira)->adr.no,(ptr+sira)->adr.kat);
            menu2();
        }
        else
        {
            system("cls");
            printf("*Yanlis sifre veya kullanici girisi!*\n\n");
            menu2();
        }
    }
    else
    {
        system("cls");
        printf("\n*Yanlis sayi girisi!*\n\n");
        menu2();
    }
}
void musteriSil()
{
    int i,sira,cvp;
    char sifre[15];
    for(i=0; i<art; i++)
    {
        printf("(%d) %s %s \n",i,(ptr+i)->ad,(ptr+i)->soyad);
    }
    printf("Kacinci kullanici oldugunuzu seciniz:");
    scanf("%d",&sira);
    printf("Sifrenizi giriniz:");
    scanf("%s",sifre);
    if(sira<art)
    {

        if(strcmp((ptr+sira)->parola,sifre)==0)         //Islem icin sifre bilgisini kontrol eder.
        {
            printf("Kayitli musteriyi silmek istediginizden emin misiniz?(Evet->1)");
            scanf("%d",&cvp);
            if(cvp==1)
            {
                for(i=sira; i<art-1; i++)                      //Bellekteki silinen kisinin yerine alttaki diger kisileri kaydirmak icin.
                {
                    strcpy((ptr+i)->ad,(ptr+i+1)->ad);        //Her bilgiyi bi önceki yere tasıyor
                    strcpy((ptr+i)->soyad,(ptr+i+1)->soyad);
                    strcpy((ptr+i)->eposta,(ptr+i+1)->eposta);
                    strcpy((ptr+i)->adr.il,(ptr+i+1)->adr.il);
                    strcpy((ptr+i)->adr.ilce,(ptr+i+1)->adr.ilce);
                    strcpy((ptr+i)->adr.mah,(ptr+i+1)->adr.mah);
                    (ptr+i)->adr.no=(ptr+i+1)->adr.no;
                    (ptr+i)->adr.kat=(ptr+i+1)->adr.kat;
                    (ptr+i)->tel=(ptr+i+1)->tel;
                    strcpy((ptr+i)->id,(ptr+i+1)->id);
                    strcpy((ptr+i)->parola,(ptr+i+1)->parola);
                }
                art--;                                          //Toplam kullanici sayisini bir azaltmak icin.
                ptr=(struct musteri *)realloc(ptr,sizeof(struct musteri)*art);      //Bellegin sonunda bos yer acildigi icin o yeri siliyoruz.
                system("cls");
                printf("\n*Musteri silindi ana menuye yonlendirildiniz.*\n");
                main();
            }
            else
            {
                menu2();
            }
        }
        else
        {
            system("cls");
            printf("\n*Yanlis sifre veya kullanici girisi!*\n");
            menu2();
        }
    }
    else
    {
        system("cls");
        printf("\n*Yanlis sayi girisi!*\n\n");
        menu2();
    }
}

void kampanyaUygula()
{
    int secim,dgr;
    printf("\n-----------------KAMPANYALAR-------------------\n");
    printf("*Sadece bir kapmanya secme hakkiniz vardir.*\n\n");
    printf("(1)-Ilk siparise 50Tl ustune 25Tl indirim!\n");
    printf("(2)-Ogrenciye YUZDE15 indirim!\n");
    printf("(3)-Carsamba gunlerine ozel YUZDE5 indirim!\n\n");
    printf("--------------------------------------------------\n");

    printf("Secim yapin:");
    scanf("%d",&secim);
    switch(secim)                          //Secilen kampanyayi uygulamak icin.
    {
    case 1:
        printf("->Ilk siparinizse 1'e basiniz:");
        scanf("%d",&dgr);
        if(dgr==1)
        {
            if(hesap>=50)
            {
                hesap-=25;
                system("cls");
                printf("\n**Odemeniz gereken tutar: %.2f\n",hesap);
                printf("Siparisiniz alinmistir,adresinize teslim edilecektir:)\n\n");
                menu2();
            }
            else
            {
                system("cls");
                printf("Hesap tutari 50Tl'yi gecmis olmali!\n\n");
                kampanyaUygula();
            }
        }
        else
        {
            system("cls");
            printf("Bu kampanyadan yalnizca ilk sipariste yararlanilir.\n\n");
            kampanyaUygula();
        }
        break;
    case 2:
        printf("->Ogrenci iseniz 1'e basiniz:");
        scanf("%d",&dgr);
        if(dgr==1)
        {
            system("cls");
            printf("\n**Odemeniz gereken tutar: %.2f\n",hesap*85/100);
            printf("Siparisiniz alinmistir,adresinize teslim edilecektir:)\n\n");
            menu2();
        }
        else
        {
            system("cls");
            printf("Bu kampanyadan yalnizca ogrenciyseniz yararlanabilirsiniz.\n\n");
            kampanyaUygula();
        }
        break;
    case 3:
        printf("->Gunlerden carsambaysa 1'e basiniz:");
        scanf("%d",&dgr);
        if(dgr==1)
        {
            system("cls");
            printf("\n**Odemeniz gereken tutar: %.2f\n",hesap*95/100);
            printf("Siparisiniz alinmistir,adresinize teslim edilecektir:)\n\n");
            menu2();
        }
        else
        {
            system("cls");
            printf("Bu kampanyadan yalnizca gunlerden carsambaysa yararlanabilirsiniz.\n\n");
            kampanyaUygula();
        }
        break;
    default:
        system("cls");
        printf("Kampanya kullanilmadi ve siparisiniz alindi.\n **Odemeniz gereken tutar: %.2f\n",hesap);
        menu2();
    }
}
int main()
{
    int secim=menu();
    switch(secim)              //Ana menude secilen degere gore fonksiyonu cagirir.
    {
    case 1:
        musteriGiris();
        break;
    case 2:
        urunler();
        menu();
        break;
    case 3:
        yeniMusteri();
        break;
    case 4:
        kullaniciBilgi();
        break;
    case 0:
        return 0;
    default:
        printf("Yanlis sayi girisi!");
        main();
        break;
    }
    return 0;
}
