int arti[3] = {13,12,11};
int eksi[9] = {10,9,8,7,6,5,4,3,2};
int sure = 100;

void setup() {
  // for (başlangıç; koşul; adım) {
  // Tekrarlanacak kod bloğu
  // }
  for(int i = 13; i>1; i--){
    pinMode(i,OUTPUT);  
    }
  for(int i = 0; i<9; i++){
    digitalWrite(eksi[i],HIGH);
    }

    
}

void loop() {

   // ledleri teker teker yakıp söndürme
   for(int i = 0; i<3; i++){
    digitalWrite(arti[i],HIGH);
    for(int a = 0; a<9; a++){
    digitalWrite(eksi[a],LOW);
    delay(sure);
    digitalWrite(eksi[a],HIGH);
    delay(sure);
    }
    digitalWrite(arti[i],LOW);
    }

   // ledleri gurup gurup yakıp söndürme
   for(int i = 0; i<3; i++){
   digitalWrite(arti[i],HIGH);
   for(int b = 0; b<9; b++){
    digitalWrite(eksi[b],LOW);
    }
    delay(sure);
    digitalWrite(arti[i],LOW);
   for(int b = 0; b<9; b++){
    digitalWrite(eksi[b],HIGH);
    }
    delay(sure);
    }

   //Bütün ledler yanıp sönme
   for (int i = 0; i < 3; i++) {
    digitalWrite(arti[i], HIGH);
  }
  for (int i = 0; i < 9; i++) {
    digitalWrite(eksi[i], LOW);
  }
  delay(sure);
  for (int i = 0; i < 3; i++) {
    digitalWrite(arti[i], LOW);
  }
  for (int i = 0; i < 9; i++) {
    digitalWrite(eksi[i], HIGH);
  }
  delay(sure);

  // Yağmur Efekti (Yukarıdan Aşağıya)
for (int a = 0; a < 9; a++) { // Her sütun için
  for (int i = 0; i < 3; i++) { // Katmanları yukarıdan aşağıya dolaş
    digitalWrite(arti[i], HIGH);    // Katmanı aç
    digitalWrite(eksi[a], LOW);     // İlgili sütundaki LED'i yak
    delay(sure);
    digitalWrite(eksi[a], HIGH);    // İlgili sütundaki LED'i söndür
    digitalWrite(arti[i], LOW);     // Katmanı kapat
  }
}

// Dıştan İçe Doğru Yanma Efekti (Her Katmanda)
int dis_sutunlar[] = {0, 1, 2, 3, 5, 6, 7, 8}; // Köşe ve kenar sütunları
int orta_sutun = 4; // Orta sütun

for (int i = 0; i < 3; i++) { // Her katman için
  digitalWrite(arti[i], HIGH); // Katmanı aç

  // Dış sütunları yakıp söndür
  for (int j = 0; j < 8; j++) {
    digitalWrite(eksi[dis_sutunlar[j]], LOW); // Dış sütun LED'ini yak
  }
  delay(sure);
  for (int j = 0; j < 8; j++) {
    digitalWrite(eksi[dis_sutunlar[j]], HIGH); // Dış sütun LED'ini söndür
  }
  delay(sure);

  // Orta sütunu yakıp söndür
  digitalWrite(eksi[orta_sutun], LOW); // Orta sütun LED'ini yak
  delay(sure);
  digitalWrite(eksi[orta_sutun], HIGH); // Orta sütun LED'ini söndür
  delay(sure);

  digitalWrite(arti[i], LOW); // Katmanı kapat
}


// Yılan Efekti (Her Katmanda Kayarak İlerleme)
for (int i = 0; i < 3; i++) { // Her katman için
  digitalWrite(arti[i], HIGH); // Katmanı aç

  for (int a = 0; a < 9; a++) { // Sütunları sırayla gez
    digitalWrite(eksi[a], LOW); // LED'i yak
    delay(sure / 2);           // Kısa bekleme
    digitalWrite(eksi[a], HIGH); // LED'i söndür
  }
  digitalWrite(arti[i], LOW); // Katmanı kapat
}

// Merkezden Dışa Yayılma Efekti (Her Katmanda)
int merkez_ve_capraz[] = {4, 0, 2, 6, 8, 1, 3, 5, 7}; // Orta ve sonra çapraz/köşeler
// Alternatif: Sadece Merkez ve Yanlar: int merkez_ve_yanlar[] = {4, 1, 3, 5, 7};

for (int i = 0; i < 3; i++) { // Her katman için
  digitalWrite(arti[i], HIGH); // Katmanı aç

  for (int j = 0; j < 9; j++) { // Dizideki sıraya göre LED'leri yak
    digitalWrite(eksi[merkez_ve_capraz[j]], LOW); // LED'i yak
    delay(sure / 2);
  }
  delay(sure); // Tüm LED'ler yandıktan sonra biraz bekle

  for (int j = 8; j >= 0; j--) { // Ters sırayla LED'leri söndür
    digitalWrite(eksi[merkez_ve_capraz[j]], HIGH); // LED'i söndür
    delay(sure / 2);
  }
  digitalWrite(arti[i], LOW); // Katmanı kapat
}

// Katmanlar Arası Geçiş Efekti (Tüm Sütunlar Aynı Anda)
for (int i = 0; i < 3; i++) { // Katmanları yukarıdan aşağıya gez
  // Önceki katmanı kapat (varsa)
  if (i > 0) {
    digitalWrite(arti[i-1], LOW);
  }

  digitalWrite(arti[i], HIGH); // Geçerli katmanı aç
  for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], LOW); // Tüm sütunları yak
  }
  delay(sure * 2); // Katmanın belirli bir süre yanık kalmasını sağla
  
  // Katmanı kapatmadan önce bir sonraki adıma geçiş için hazırla
}

// Son katmanı da kapatalım
digitalWrite(arti[2], LOW); 
for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], HIGH); // Tüm sütunları söndür
}

// Aşağıdan yukarıya geçiş
for (int i = 2; i >= 0; i--) { // Katmanları aşağıdan yukarıya gez
  if (i < 2) {
    digitalWrite(arti[i+1], LOW);
  }
  digitalWrite(arti[i], HIGH); // Geçerli katmanı aç
  for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], LOW); // Tüm sütunları yak
  }
  delay(sure * 2); 
}
// İlk katmanı da kapatalım
digitalWrite(arti[0], LOW);
for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], HIGH);
}

// Sekme Efekti (Her Sütunda Yukarı Aşağı Zıplama)
for (int a = 0; a < 9; a++) { // Her sütun için
  // Aşağıdan yukarıya
  for (int i = 2; i >= 0; i--) { // Katmanları aşağıdan yukarıya gez (indeks 2, 1, 0)
    digitalWrite(arti[i], HIGH);    // Katmanı aç
    digitalWrite(eksi[a], LOW);     // İlgili sütundaki LED'i yak
    delay(sure / 3);
    digitalWrite(eksi[a], HIGH);    // LED'i söndür
    digitalWrite(arti[i], LOW);     // Katmanı kapat
  }

  // Yukarıdan aşağıya
  for (int i = 0; i < 3; i++) { // Katmanları yukarıdan aşağıya gez (indeks 0, 1, 2)
    digitalWrite(arti[i], HIGH);    // Katmanı aç
    digitalWrite(eksi[a], LOW);     // İlgili sütundaki LED'i yak
    delay(sure / 3);
    digitalWrite(eksi[a], HIGH);    // LED'i söndür
    digitalWrite(arti[i], LOW);     // Katmanı kapat
  }
}

// Katmanlara Odaklanma Efekti (Ortadan Kenarlara)
// Ortadan dışarı
for (int i = 1; i >= 0; i--) { // Ortadan (1) yukarıya (0) doğru
  digitalWrite(arti[i], HIGH); // Katmanı aç
  for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], LOW); // Tüm sütunları yak
  }
  delay(sure);
  for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], HIGH); // Tüm sütunları söndür
  }
  digitalWrite(arti[i], LOW); // Katmanı kapat
}
for (int i = 1; i < 3; i++) { // Ortadan (1) aşağıya (2) doğru
  digitalWrite(arti[i], HIGH); // Katmanı aç
  for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], LOW); // Tüm sütunları yak
  }
  delay(sure);
  for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], HIGH); // Tüm sütunları söndür
  }
  digitalWrite(arti[i], LOW); // Katmanı kapat
}

// Kenarlardan ortaya
for (int i = 0; i < 3; i+=2) { // En üst (0) ve en alt (2) katmanlar
  digitalWrite(arti[i], HIGH); // Katmanı aç
  for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], LOW); // Tüm sütunları yak
  }
  delay(sure);
  for (int a = 0; a < 9; a++) {
    digitalWrite(eksi[a], HIGH); // Tüm sütunları söndür
  }
  digitalWrite(arti[i], LOW); // Katmanı kapat
}
digitalWrite(arti[1], HIGH); // Orta katman
for (int a = 0; a < 9; a++) {
  digitalWrite(eksi[a], LOW); // Tüm sütunları yak
}
delay(sure);
for (int a = 0; a < 9; a++) {
  digitalWrite(eksi[a], HIGH); // Tüm sütunları söndür
}
digitalWrite(arti[1], LOW); // Orta katman kapat

// Çapraz Yanma Efekti (Her Katmanda)
int capraz1[] = {0, 4, 8}; // Köşeden köşeye (ana çapraz)
int capraz2[] = {2, 4, 6}; // Diğer köşeden köşeye

for (int i = 0; i < 3; i++) { // Her katman için
  digitalWrite(arti[i], HIGH); // Katmanı aç

  // Birinci çaprazı yak
  for (int j = 0; j < 3; j++) {
    digitalWrite(eksi[capraz1[j]], LOW);
  }
  delay(sure);
  // Birinci çaprazı söndür
  for (int j = 0; j < 3; j++) {
    digitalWrite(eksi[capraz1[j]], HIGH);
  }
  delay(sure);

  // İkinci çaprazı yak
  for (int j = 0; j < 3; j++) {
    digitalWrite(eksi[capraz2[j]], LOW);
  }
  delay(sure);
  // İkinci çaprazı söndür
  for (int j = 0; j < 3; j++) {
    digitalWrite(eksi[capraz2[j]], HIGH);
  }
  delay(sure);

  digitalWrite(arti[i], LOW); // Katmanı kapat
}

// Dönen Kare Efekti (Her Katmanda)
int kare_sutunlari_sira[] = {0, 1, 2, 5, 8, 7, 6, 3}; // Dış kenarları oluşturan sütunlar
                                                   // (sol üst, üst orta, sağ üst, sağ orta, sağ alt, alt orta, sol alt, sol orta)

for (int i = 0; i < 3; i++) { // Her katman için
  digitalWrite(arti[i], HIGH); // Katmanı aç

  for (int j = 0; j < 8; j++) { // Kare sütunları sırayla yakıp söndür
    digitalWrite(eksi[kare_sutunlari_sira[j]], LOW); // LED'i yak
    delay(sure / 3);
    digitalWrite(eksi[kare_sutunlari_sira[j]], HIGH); // LED'i söndür
  }
  digitalWrite(arti[i], LOW); // Katmanı kapat
}

// Zikzak Efekti (Katmanlar Arası)
for (int a = 0; a < 9; a++) { // Her sütun için
  // Sütunu yukarı doğru zikzak çiz
  for (int i = 2; i >= 0; i--) { // Aşağıdan yukarıya
    digitalWrite(arti[i], HIGH);
    digitalWrite(eksi[a], LOW);
    delay(sure / 3);
    digitalWrite(eksi[a], HIGH);
    digitalWrite(arti[i], LOW);
  }
  
  // Sütunu aşağı doğru zikzak çiz (bir sonraki sütuna geçmeden önce)
  if (a < 8) { // Son sütunda aşağı inmeye gerek yok
    for (int i = 0; i < 3; i++) { // Yukarıdan aşağıya
      digitalWrite(arti[i], HIGH);
      digitalWrite(eksi[a+1], LOW); // Bir sonraki sütunu kullan
      delay(sure / 3);
      digitalWrite(eksi[a+1], HIGH);
      digitalWrite(arti[i], LOW);
    }
    a++; // Bir sonraki sütuna geçtiğimiz için 'a' değerini artır
  }
}

// İçten Dışa Patlama Efekti (Nokta Halinde, Her Katmanda)
int patlama_sirasi[] = {4, 1, 3, 5, 7, 0, 2, 6, 8}; // Merkezden dışa doğru sütun indeksleri

for (int i = 0; i < 3; i++) { // Her katman için
  digitalWrite(arti[i], HIGH); // Katmanı aç

  for (int j = 0; j < 9; j++) { // Patlama sırasına göre LED'leri yak
    digitalWrite(eksi[patlama_sirasi[j]], LOW); // LED'i yak
    delay(sure / 5); // Çok kısa bekleme
    digitalWrite(eksi[patlama_sirasi[j]], HIGH); // LED'i hemen söndür
  }
  digitalWrite(arti[i], LOW); // Katmanı kapat
  delay(sure / 2); // Katmanlar arası bekleme
}

// Rastgele Yağmur Damlaları (Arka Plan Efekti)
for (int k = 0; k < 5; k++) { // Belirli sayıda rastgele damla oluştur
  int rastgeleKatman = random(0, 3); // 0, 1 veya 2
  int rastgeleSutun = random(0, 9);  // 0'dan 8'e kadar

  digitalWrite(arti[rastgeleKatman], HIGH); // Rastgele katmanı aç
  digitalWrite(eksi[rastgeleSutun], LOW);   // Rastgele sütundaki LED'i yak
  delay(sure / 8); // Çok kısa yanıp kalma süresi
  digitalWrite(eksi[rastgeleSutun], HIGH);  // LED'i söndür
  digitalWrite(arti[rastgeleKatman], LOW);  // Katmanı kapat
}
delay(sure / 4); // Efektler arası kısa bekleme

// Titreşim Efekti
for (int k = 0; k < 20; k++) { // 20 adet rastgele titreşim noktası
  int rastgeleKatman = random(0, 3);
  int rastgeleSutun = random(0, 9);

  digitalWrite(arti[rastgeleKatman], HIGH); // Rastgele katmanı aç
  digitalWrite(eksi[rastgeleSutun], LOW);   // Rastgele sütundaki LED'i yak
  delay(20); // Çok kısa yanık kalma süresi (20 ms)
  digitalWrite(eksi[rastgeleSutun], HIGH);  // LED'i söndür
  digitalWrite(arti[rastgeleKatman], LOW);  // Katmanı kapat
}
delay(100); // Titreşim setleri arası bekleme



}
