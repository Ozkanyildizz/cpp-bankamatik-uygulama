
#include <iostream>
#include <string>
#include <unordered_map> // map icin gerekli

using namespace std; // std::time icin gerekli


class Bankamatik {
public:
    // Kullanici veri yapisi
    struct Kullanici {
        string isim;
        int bakiye;
        int ekHesap;
    };

    void bamkamatik_uygulama2() {
        unordered_map<string, Kullanici> kullanicilar; // Kullan�c�lar� depolamak i�in harita
        char anaIslem;

        while (true) {
            cout << "\n*** Bankamatik Uygulamasi ***\n";
            cout << "1) Kullanici ekle\n";
            cout << "2) Kullanici sil\n";
            cout << "3) Kullanici islemleri\n";
            cout << "q) Cikis\n";
            cout << "Isleminiz: ";
            cin >> anaIslem;

            if (anaIslem == 'q' || anaIslem == 'Q') {
                cout << "Uygulamadan cikiliyor...\n";
                break;
            }

            switch (anaIslem) {
            case '1': { // Kullan�c� ekleme
                string kullaniciAdi;
                int bakiye, ekHesap;
                cout << "Yeni kullanici adi: ";
                cin >> kullaniciAdi;
                cout << "Ana bakiye: ";
                cin >> bakiye;
                cout << "Ek hesap: ";
                cin >> ekHesap;

                if (kullanicilar.find(kullaniciAdi) == kullanicilar.end()) { // Eger kullan�c� bulunmad�ysa ekle 
                    kullanicilar[kullaniciAdi] = { kullaniciAdi, bakiye, ekHesap };
                    cout << kullaniciAdi << " isimli kullanici basariyla eklendi.\n";
                }
                else {
                    cout << "Bu kullanici zaten mevcut.\n";
                }
                break;
            }

            case '2': { // Kullan�c� silme
                string kullaniciAdi;
                cout << "Silmek istediginiz kullanici adi: ";
                cin >> kullaniciAdi;

                if (kullanicilar.erase(kullaniciAdi)) {
                    cout << kullaniciAdi << " isimli kullanici basariyla silindi.\n";
                }
                else {
                    cout << "Bu kullanici bulunamadi.\n";
                }
                break;
            }

            case '3': { // Kullan�c� i�lemleri
                string kullaniciAdi;
                cout << "Islem yapmak istediginiz kullanici adi: ";
                cin >> kullaniciAdi;

                if (kullanicilar.find(kullaniciAdi) == kullanicilar.end()) {
                    cout << "Bu kullanici bulunamadi.\n";
                    break;
                }

                Kullanici& kullanici = kullanicilar[kullaniciAdi];
                char islem;

                while (true) {
                    cout << "\n*** " << kullanici.isim << " Islemleri ***\n";
                    cout << "1) Bakiye goruntule\n";
                    cout << "2) Para cek\n";
                    cout << "3) Para yatir\n";
                    cout << "q) Geri don\n";
                    cout << "Isleminiz: ";
                    cin >> islem;

                    if (islem == 'q' || islem == 'Q') {
                        break;
                    }

                    switch (islem) {
                    case '1': // Bakiye g�r�nt�leme
                        cout << "Ana bakiye: " << kullanici.bakiye << endl;
                        cout << "Ek hesap: " << kullanici.ekHesap << endl;
                        break;

                    case '2': { // Para �ekme
                        int para;
                        cout << "Cekmek istediginiz miktar: ";
                        cin >> para;

                        if (para <= kullanici.bakiye) {
                            kullanici.bakiye -= para;
                            cout << "Paraniz cekildi. Yeni bakiye: " << kullanici.bakiye << endl;
                        }
                        else if (para <= kullanici.bakiye + kullanici.ekHesap) {
                            char onay;
                            cout << "Ana bakiyeniz yetersiz. Ek hesap kullanilsin mi? (e/h): ";
                            cin >> onay;

                            if (onay == 'e' || onay == 'E') {
                                int kalan = para - kullanici.bakiye;
                                kullanici.bakiye = 0;
                                kullanici.ekHesap -= kalan;
                                cout << "Paraniz cekildi. Yeni ana bakiye: " << kullanici.bakiye
                                    << ", Yeni ek hesap: " << kullanici.ekHesap << endl;
                            }
                            else {
                                cout << "Islem iptal edildi.\n";
                            }
                        }
                        else {
                            cout << "Iki hesapta da yeterli bakiye yok.\n";
                        }
                        break;
                    }

                    case '3': { // Para yat�rma
                        int para;
                        cout << "Yatirmak istediginiz miktar: ";
                        cin >> para;
                        kullanici.bakiye += para;
                        cout << "Paraniz yatirildi. Yeni bakiye: " << kullanici.bakiye << endl;
                        break;
                    }

                    default:
                        cout << "Bilinmeyen islem.\n";
                    }
                }
                break;
            }

            default:
                cout << "Bilinmeyen islem. Lutfen tekrar deneyin.\n";
            }
        }
    }
};

int main()
{
    Bankamatik uygulama;
    uygulama.bamkamatik_uygulama2();
}
