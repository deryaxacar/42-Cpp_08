<div align="center">
  <h1>C++ Module 08</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>
</div>

<p align="center">
</p>


### İçindekiler 📚
  - [Ex00 - Easy find](#ex00)
    - [Container (kapsayıcı) Nedir?](#container-nedir)
    - [Iteratör (yineleyici) Nedir?](#iterator-nedir)
    - [Vector Nedir?](#vector-nedir)
  - [Ex01 - Span](#ex01)
  - [Ex02 - Mutated abomination](#ex02)

---

### Container (kapsayıcı) Nedir?

**Container**, belirli bir türdeki verileri belirli bir bellek düzeninde tutan yapılardır. C++ dilindeki Standart Kütüphane’de (STL — Standard Template Library), sıkça kullanılan birçok container çeşidi vardır (örneğin, `vector`, `list`, `deque`, `map`, `set` vb.). Kapsayıcılar şu işlevleri gerçekleştirir:

- Verileri bellek üzerinde saklarlar.
- Sakladıkları verilere erişimi belirli kurallar çerçevesinde düzenlerler (örneğin, dizi gibi sıralı erişim veya harita gibi anahtar-değer erişimi).
- Eleman ekleme, silme ve sıralama gibi temel işlemleri kolay ve performanslı şekilde sunarlar.

Kapsayıcıların avantajları şunlardır:

1. **Güvenlik**: Ham pointer veya ham bellek yönetimi yerine kapsayıcılar kullanmak, veri yönetimini kolaylaştırır ve hata yapma olasılığını azaltır.  
2. **Verimlilik**: Standart Kütüphane’deki kapsayıcılar çoğu kullanım senaryosu için optimize edilmiştir.  
3. **Kolaylık**: Aynı kapsayıcı yapısı farklı veri türlerinde kullanılabilir (templateler aracılığıyla).

### Iterator (yineleyici) Nedir?

**Iterator (yineleyici)**, kapsayıcılardaki veriler arasında gezinmeyi ve onlara erişimi sağlayan bir yapıdır. Genellikle, C++’ta dizilerde veya STL kapsayıcılarında kullanılabilen `pointer` benzeri nesnelerdir. Örneğin:

- Bir `vector<int>` üzerinden yineleyici (iterator) kullanarak elemanları sırasıyla okuyabilir veya değiştirebilirsiniz.
- İteratörler, C++ algoritmalarının (örn. `std::sort`, `std::find`) kapsayıcılarla birlikte sorunsuz çalışmasını sağlar.

İteratörlerin bazı önemli noktaları:

1. **Abstraction (Soyutlama)**: Gerçek bellek adresi ile uğraşmadan elemanlara erişim sağlanır.  
2. **Taşınabilirlik**: Aynı kodu, farklı kapsayıcı tiplerinde yineleyicilerle kullanabilirsiniz.  
3. **Çeşitlilik**: C++’ta birden çok iterator kategorisi vardır (örneğin, `input_iterator`, `forward_iterator`, `bidirectional_iterator`, `random_access_iterator` gibi). Bu kategoriler, hangi operasyonları destekleyebileceklerini belirler.

### Vector Nedir?

**Vector**, C++ dilinde en sık kullanılan kapsayıcılardan biridir. Dinamik boyutlu bir dizi (array) gibi davranır; yani bellek alanı yetmediğinde kendine ayrılan alanı otomatik olarak genişletir. Başlıca özellikleri:

1. **Sıralı (Sequential) Erişim**: Elemanlar bellek içinde arka arkaya saklanır, bu da rastgele erişim (`random access`) işlemlerini çok hızlı hale getirir (`O(1)` zaman karmaşıklığı).  
2. **Dinamik Boyut Değiştirme**: `push_back()` ile vektörün sonuna eleman ekleyebilir, `pop_back()` ile son elemanı silebilirsiniz. Boyutu esnek bir şekilde artıp azalır.  
3. **İteratör Kullanımı**: `begin()`, `end()`, `rbegin()`, `rend()` gibi fonksiyonlar ile vektör içindeki elemanlar üzerinde dolaşmak için yineleyiciler (iterator) alınabilir.  
4. **Avantaj / Dezavantaj**:
    - **Avantaj**: Rastgele erişimin (örn. `v[5]`) çok hızlı olması, ekleme/çıkarma işlemlerinin (özellikle sondan ekleme/çıkarma) pratik olması.  
    - **Dezavantaj**: Ortalardan ekleme veya silme yapıldığında elemanların kaydırılması gerektiği için bu işlemlerin maliyeti artar.

### Örnek Kullanım

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers; // Boş bir vector

    // Eleman ekleme
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // İteratör ile okuma
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    // Çıktı: 10 20 30

    return 0;
}

```

---

---

<p align="center">2025 This project was created by Derya ACAR.</p>
