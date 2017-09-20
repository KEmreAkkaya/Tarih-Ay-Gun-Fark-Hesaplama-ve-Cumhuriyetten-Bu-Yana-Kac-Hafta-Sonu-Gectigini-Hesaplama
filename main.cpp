

#include "stdafx.h"
#include <iostream>

using namespace std;
int deger = 0;
int deger2 = 0;
enum aylar { Ocak = 1, Şubat, Mart, Nisan, Mayıs, Haziran, Temmuz, Ağustos, Eylül, Ekim, Kasım, Aralık };
enum gunler {  Pazartesi=1, Salı, Çarşamba, Perşembe, Cuma , Cumartesi, Pazar};
int gunhesapla(int gun1, int ay1, int yıl1, int gun2, int ay2, int yıl2) {

	int gun = 0;
	if (gun2 >= gun1)
	{
		gun = gun2 - gun1;
	}
	if (gun2 < gun1)
	{
		if (yıl2 % 4 == 0 && yıl2 % 100 != 0 || yıl2 % 400 == 0 && ay2 == Şubat)
		{
			gun2 += 29;
			deger = 1;//eğer değer =1 olursa ay da 1 eksilteceğiz. 
			gun = gun2 - gun1;
		}

		if (yıl2 % 4 != 0 && yıl2 % 100 == 0 && yıl2 % 400 != 0 && ay2 == Şubat)
		{
			gun2 += 28;
			deger = 1;
			gun = gun2 - gun1;
		}
		if (ay2 == Ocak || ay2 == Mart || ay2 == Mayıs || ay2 == Temmuz || ay2 == Ağustos || ay2 == Ekim || ay2 == Aralık)
		{
			gun2 += 31;
			deger = 1;
			gun = gun2 - gun1;
		}
		if (ay2 == Nisan || ay2 == Haziran || ay2 == Eylül || ay2 == Kasım) {
			gun2 += 30;
			deger = 1;
			gun = gun2 - gun1;

		}
	}
	return gun;
}


int ayhesapla(int ay1, int yıl1, int ay2, int yıl2)
{
	int ay = 0;
	if (deger == 1)
	{
		ay2 -= 1;
	}


	if (ay2 >= ay1)
	{

		ay = ay2 - ay1;
	}

	else
	{
		ay2 += 12;
		deger2 = 1;//yıldan bir eksilme yapabilmek için deger2 ile kontrol ettim.Yıl hesaplama fonksiyonunda deger2==1 ise yıl2 den 1 eksilme yaptım.
		ay = ay2 - ay1;
	}



	return ay;
}

int yılhesapla(int yıl1, int yıl2)
{
	int yıl = 0;
	if (deger2 == 1)
	{
		yıl2 -= 1;

	}
	if (yıl2 >= yıl1) {
		yıl = yıl2 - yıl1;

	}
	else
	{
		cout << "Yanlış veri girdiniz." << endl;

	}

	return yıl;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int gun1, gun2, ay1, ay2, yıl1, yıl2;

	gun1 = 29;
	ay1 = Ekim;
	yıl1 = 1923;



	cout << "Sırasıyla gün, ay, yıl giriniz" << endl;
	cout << "Gün2 giriniz";
	cin >> gun2;
	if (gun2 < 1 || gun2>31) {
		cout << "Yanlış değer girdiniz." << endl;

	}
	cout << "Ay2 giriniz";
	cin >> ay2;
	if (ay2 < 1 || ay2>12) {
		cout << "Yanlış değer girdiniz." << endl;

	}

	cout << "Yıl2 giriniz.";
	cin >> yıl2;
	if (yıl2 < 1923) {
		cout << " 1923 yılından küçük bir değer girdiniz." << endl;

	}

	if (yıl2 % 4 != 0 && yıl2 % 100 == 0 && yıl2 % 400 != 0 && ay2 == Şubat) {

		if (gun2 < 1 || gun2 >28) {

			cout << "28 günden fazla veya 1 günden az değer girdiniz." << endl;

		}
	}
	if (yıl2 % 4 == 0 && yıl2 % 100 != 0 || yıl2 % 400 == 0 && ay2 == Şubat) {
		if (gun2 < 1 || gun2 >29) {

			cout << "29 günden fazla veya 1 günden az değer girdiniz." << endl;

		}
	}




	// isterseniz herhangi bir tarihten itibaren hesaplama yapabilirsiniz

	/*
	cout << "Çıkarılacak gün, ay, yıl giriniz" << endl;
	cout << "Gün1 giriniz";
	cin >> gun1;
	if (gun1 < 1 || gun1>31) {
		cout << "Yanlış değer girdiniz." << endl;

	}
	cout << "Ay1 giriniz";
	cin >> ay1;
	if (ay1 < 1 || ay1>12) {
		cout << "Yanlış değer girdiniz." << endl;

	}
	cout << "Yıl1 giriniz.";
	cin >> yıl1;

	*/

	int a = gunhesapla(gun1, ay1, yıl1, gun2, ay2, yıl2);// gün dönderen fonksiyonu  a değişkenine atadım.

	int b = ayhesapla(ay1, yıl1, ay2, yıl2);// gün dönderen fonksiyonu  b değişkenine atadım.

	int c = yılhesapla(yıl1, yıl2);// yıl dönderen fonksiyonu  c değişkenine atadım.



	cout << "Cumhuriyetimizden bu yana aradan " << a << " gun , " << b << " ay , " << c << " yıl geçti" << endl;

	int k = 0;

	int yılhesap = 0;

	int ayhesap = 0;







	//Eğer aydan gün , yıldan  da ay alınmışsa bunları 1 eksilt.



	if (gun2 - gun1 < 0)
	{
		ay2 -= 1;
		if (ay2 - ay1 < 0)
		{
			yıl2 -= 1;
		}


	}


	//yıl için güne çevirme .artık yıl varsa 366 gün olarak hesapla,değilse 365.
	for (int i = yıl1; i < yıl2; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
		{

			k = 366;//artık yıldır.
			yılhesap = yılhesap + k;
		}
		else
		{

			k = 365; //artık yıl değildir.
			yılhesap = yılhesap + k;
		}


	}
	cout << c << " yıl gün olarak " << yılhesap << "gün eder." << endl;

	//1 Aylık hesap için standart 30 gün aldım .Normalde Şubat'ı içerip içermediğini kontrol etmem gerekiyordu ve diğer ayların 30 veya 31 gün olmasını hesaba katmam lazımdı.

	ayhesap = b * 30;

	cout << b << " ay gün olarak " << ayhesap << "gün eder." << endl << endl;

	int toplam = yılhesap + ayhesap + a;

	cout << "Tüm yıl,ay,gün toplam = " << toplam << " gün eder." << endl;


	int say = 0;
	int haftaningunu;
	if (gun1 == 29 && ay1 == Ekim && yıl1 == 1923) {
	
		haftaningunu = Pazartesi;
	
	}
	//Cumartesi ve pazar günü için geçen her gün için say degeri arttır.

	for (haftaningunu = Pazartesi; haftaningunu <= toplam; haftaningunu++) {
		if (haftaningunu % 6 == 0 || haftaningunu % 7== 0 ) {


			say++;
		}
	
	}
	//Önemli not girilen tarihi hesaba katmıyor. ayları standart 30 gün üzerinden hesaplıyor.
	cout << "1923 den bu yana " << say << " kadar haftasonu geçti.";


	system("pause");
	return 0;
}




