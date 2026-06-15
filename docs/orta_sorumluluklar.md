# Ortak Sorumluluklar

## ‼️Katı Kurallar‼️

#### 1. Tüm Mümkün Leakler Not Edilmeli

Malloc kullanılan veya üzerinde leak oluşabilecek (static vs.) her türlü değişkenler/fonksiyonlar not edilecek. Nerede hangi durumda nasıl free edildiği raporlanacak.

Örnek olarak,
`t_data window` değişkeni `init_window()` fonksiyonuyla main.c dosyasında çağırılıyor. En son hata yine main.c dosyasında `free_window()` fonksiyonu ile free ediliyor.

#### 2. Özel Ortak Hata Kodları Dönülecek

Malloc hatalarında üzerinde ortak anlaştığımız hata kodları ve hata mesajları kullanılarak işlenecek.

Örnek olarak, mesela kendi yazdığımız `int create_window()` fonksiyonunda malloc hatası oldu bir şekilde. return olarak 1001 dönmeli. 

1. malloc() -> 1001 ya da NULL
2. ft_calloc() -> 1002 ya da NULL
3. byaprak özel fonksiyonlar -> 400'den başlıyor. {401, 402, ...}
3. yuak özel fonksiyonlar -> 500'den başlıyor. {501, 502, ...}

#### 3. Fonksiyon İsimleri

Fonksiyon isimlerinde uzlaşma sağlanmalı.

1.	"ft_" ön eki sadece ve sadece zaten kütüphanede hazır olan bir fonksiyon varsa ve onun benzerini uyguluyorsak kullanılmalı. Aksi takdirde ön ek olmadan anlamlı bir isim verilmeli.

2. Bir sorgu yapılacaksa "is_" ile başlamalı.

3.	Eğer yine malloc ile sıfırdan açılıp doldurulan ancak return olarak adres dönmeyip başka bir şey döndürenlere "create_" ön eki eklenmeli.
(Burada philosophers projesindeki `create_thread()` fonksiyonundaki isim gibi)

4.	Eğer malloc ile sıfırdan açılıp doldurulan ve fonksiyonda return olarak dönülen bir data varsa onun için "init_" ön eki eklenmeli.

## Genel Sorular

- Nasıl bir oyun yapılacağına dair karar verilmeli.
- Gerekli grafikler, mekanikler not edilmeli.
- Bonus yapılacak mı karar verilmeli.
