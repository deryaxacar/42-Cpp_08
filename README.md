<div align="center">
  <h1>C++ Module 08</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>
</div>

<p align="center">
  Bu proje, STL (Standard Template Library) kullanımı üzerine üç temel egzersiz içermektedir. İlk bölümde STL kapsayıcılarda arama yapan generic bir <code>easyfind</code> fonksiyonu, ikinci bölümde sayılar arasındaki farkları hesaplayan <code>Span</code> sınıfı, üçüncü bölümde ise iterator destekli <code>MutantStack</code> sınıfı geliştirilmiştir. Proje, C++’ta şablonlar, kapsayıcılar ve algoritmalara hakimiyeti artırmayı hedefler.
</p>



### İçindekiler 📚
  - [Ex00 - Easy find](#ex00---easy-find)
    - [Container (kapsayıcı) Nedir?](#container-kapsayici-nedir)
    - [Iterator (yineleyici) Nedir?](#iterator-yineleyici-nedir)
    - [Vector Nedir?](#vector-nedir)
  - [Ex01 - Span](#ex01---span)
    - [Span Nedir?](#span-nedir)
    - [Span ile İlgili Kavramlar](#span-ile-ilgili-kavramlar)
    - [STL Fonksiyonları](#stl-fonksiyonlari-stdsort-stddistance)
    - [Performanslı Yaklaşım](#performansli-yaklasim)
    - [addRange Fonksiyonu](#addrange-fonksiyonu)
  - [Ex02 - Mutated Abomination](#ex02---mutated-abomination)
    - [Stack Nedir?](#stack-nedir)
    - [std::stack ve Iterator Sorunu](#stdstack-ve-iterator-sorunu)
    - [MutantStack Nedir?](#mutantstack-nedir)
    - [deque ve container_type](#deque-ve-container_type)
    - [Avantajlar](#avantajlar)

---

### <a name="ex00---easy-find"></a>Ex00 - Easy find

### <a name="container-kapsayici-nedir"></a>Container (kapsayıcı) Nedir?

**Container**, belirli bir türdeki verileri belirli bir bellek düzeninde tutan yapılardır. C++ dilindeki Standart Kütüphane’de (STL — Standard Template Library), sıkça kullanılan birçok container çeşidi vardır (örneğin, `vector`, `list`, `deque`, `map`, `set` vb.). Kapsayıcılar şu işlevleri gerçekleştirir:

- Verileri bellek üzerinde saklarlar.
- Sakladıkları verilere erişimi belirli kurallar çerçevesinde düzenlerler (örneğin, dizi gibi sıralı erişim veya harita gibi anahtar-değer erişimi).
- Eleman ekleme, silme ve sıralama gibi temel işlemleri kolay ve performanslı şekilde sunarlar.

Kapsayıcıların avantajları şunlardır:

1. **Güvenlik**: Ham pointer veya ham bellek yönetimi yerine kapsayıcılar kullanmak, veri yönetimini kolaylaştırır ve hata yapma olasılığını azaltır.  
2. **Verimlilik**: Standart Kütüphane’deki kapsayıcılar çoğu kullanım senaryosu için optimize edilmiştir.  
3. **Kolaylık**: Aynı kapsayıcı yapısı farklı veri türlerinde kullanılabilir (templateler aracılığıyla).

---

### <a name="iterator-yineleyici-nedir"></a>Iterator (yineleyici) Nedir?

**Iterator (yineleyici)**, kapsayıcılardaki veriler arasında gezinmeyi ve onlara erişimi sağlayan bir yapıdır. Genellikle, C++’ta dizilerde veya STL kapsayıcılarında kullanılabilen `pointer` benzeri nesnelerdir. Örneğin:

- Bir `vector<int>` üzerinden yineleyici (iterator) kullanarak elemanları sırasıyla okuyabilir veya değiştirebilirsiniz.
- İteratörler, C++ algoritmalarının (örn. `std::sort`, `std::find`) kapsayıcılarla birlikte sorunsuz çalışmasını sağlar.

İteratörlerin bazı önemli noktaları:

1. **Abstraction (Soyutlama)**: Gerçek bellek adresi ile uğraşmadan elemanlara erişim sağlanır.  
2. **Taşınabilirlik**: Aynı kodu, farklı kapsayıcı tiplerinde yineleyicilerle kullanabilirsiniz.  
3. **Çeşitlilik**: C++’ta birden çok iterator kategorisi vardır (örneğin, `input_iterator`, `forward_iterator`, `bidirectional_iterator`, `random_access_iterator` gibi). Bu kategoriler, hangi operasyonları destekleyebileceklerini belirler.

---

### <a name="vector-nedir"></a>Vector Nedir?

**Vector**, C++ dilinde en sık kullanılan kapsayıcılardan biridir. Dinamik boyutlu bir dizi (array) gibi davranır; yani bellek alanı yetmediğinde kendine ayrılan alanı otomatik olarak genişletir. Başlıca özellikleri:

1. **Sıralı (Sequential) Erişim**: Elemanlar bellek içinde arka arkaya saklanır, bu da rastgele erişim (`random access`) işlemlerini çok hızlı hale getirir (`O(1)` zaman karmaşıklığı).  
2. **Dinamik Boyut Değiştirme**: `push_back()` ile vektörün sonuna eleman ekleyebilir, `pop_back()` ile son elemanı silebilirsiniz. Boyutu esnek bir şekilde artıp azalır.  
3. **İteratör Kullanımı**: `begin()`, `end()`, `rbegin()`, `rend()` gibi fonksiyonlar ile vektör içindeki elemanlar üzerinde dolaşmak için yineleyiciler (iterator) alınabilir.  
4. **Avantaj / Dezavantaj**:
    - **Avantaj**: Rastgele erişimin (örn. `v[5]`) çok hızlı olması, ekleme/çıkarma işlemlerinin (özellikle sondan ekleme/çıkarma) pratik olması.  
    - **Dezavantaj**: Ortalardan ekleme veya silme yapıldığında elemanların kaydırılması gerektiği için bu işlemlerin maliyeti artar.

**Örnek**

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

### <a name="ex01---span"></a>Ex01 - Span

#### Span Nedir?

**Span**, belli sayıda tamsayıyı saklayabilen bir kapsayıcı sınıftır ve bu tamsayılar arasındaki en kısa ve en uzun mesafeyi (span) hesaplamak amacıyla kullanılır.

---

### <a name="span-ile-ilgili-kavramlar"></a>Span ile İlgili Kavramlar

#### Sayılar Arasındaki Mesafe (Span)

İki tamsayı arasındaki mesafe, mutlak farkları ile hesaplanır:

- Örnek: `|3 - 9| = 6`

**Shortest Span**, birbiri ardına gelen iki sayı arasındaki en küçük farktır.

**Longest Span**, en küçük ve en büyük sayı arasındaki farktır.

---

### <a name="stl-fonksiyonlari-stdsort-stddistance"></a>STL Fonksiyonları (std::sort, std::distance)

- `std::sort`: Vektörü sıralamak için kullanılır, çünkü shortest span hesaplamak için sıralama gerekir.

  ```cpp
  std::sort(vec.begin(), vec.end());
   ```
- `std::distance`: İki iterator arasındaki eleman sayısını verir. Span hesaplamasında dolaylı kullanılır.

### <a name="performansli-yaklasim"></a>Performanslı Yaklaşım

- Kısa span: Vektörü sırala, ardından ardışık farkların minimumunu bul.
- Uzun span: Min ve max değerlerin farkını al.

#### addRange() Fonksiyonu

`std::vector`, `std::list`, `std::set` gibi kapsayıcılardan Span nesnesine toplu şekilde eleman eklemek için iterator aralığı alan bir `addRange()` fonksiyonu yazılmalıdır:

```cpp
template <typename Iterator>
void addRange(Iterator begin, Iterator end);
```

---

### <a name="ex02---mutated-abomination"></a>Ex02 - Mutated Abomination

#### Stack Nedir?

**Stack**, LIFO (Last-In First-Out) mantığıyla çalışan bir veri yapısıdır. `std::stack`, `push`, `pop`, `top`, `empty`, `size` gibi temel işlemleri destekler. Ancak STL’de `std::stack` iterable değildir.

---

#### std::stack ve Iterator Sorunu

`std::stack`, iterator desteklemez çünkü `begin()` ve `end()` metodları yoktur. Bu, `for` döngüsü ile gezinmeyi imkansız hale getirir. Örneğin:

```cpp
std::stack<int> s;
// s.begin() -> derleme hatası
```

#### MutantStack Nedir?

MutantStack, `std::stack`’i kalıtım yoluyla genişletip iterator desteği ekleyen özel bir sınıftır. Böylece stack içeriği üzerinde `begin()` / `end()` kullanarak gezinmek mümkün hale gelir.

```cpp
template<typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
};

```

#### deque ve container_type

`std::stack`, aslında `std::deque`'i temel alır. `container_type`, `stack`’in kullandığı bu yapıya erişmeyi sağlar. Bu sayede `stack`’in elemanlarına direkt olarak iterator ile ulaşabiliriz.

```cpp
int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}
```

#### Avantajlar

- `std::stack`’in tüm özellikleri korunur.

- Iterator desteği ile kolay `test`, `debug` ve `algoritma` işlemleri yapılabilir.

- `std::list` ile aynı çıktıyı verecek şekilde test edilebilir.

---

<p align="center">2025 This project was created by Derya ACAR.</p>
