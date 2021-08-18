### Tehtävä 10.3: Function pointers (20 pts)

**Tavoite**: Harjoitellaan funktio-osoittimien käyttöä.

Tämän tehtävän tarkoituksena on harjoitella funktiopointtereiden ja bsearch-funktion
käyttöä. Apuna käytetään viime kierrokselta tuttua
kaupparakennetta. Tällä kertaa kauppiaan tulisi toteuttaa järjestelmä, joka
järjestää tuotteet aakkosjärjestykseen tai siihen järjestykseen, mitä tuotteita
kaupan varastosta löytyy eniten. Tuotteiden tietorakenne on toteutettu samalla
tavoin kuin viime kierroksella, eli tuotelistan viimeisen alkion tunnistaa siitä,
että sen nimen ensimmäinen merkki on nollamerkki (\'\\0\').

Tässä tehtävässä sinun täytyy
toteuttaa kaksi vertailufunktiota; funktiot compareAlpha ja compareNum.
Tämän lisäksi sinun tulee toteuttaa etsimisfunktio findProduct.

**int compareAlpha(const void* a, const void* b)** -funktio vertaa parametrina
saatujen muuttujien **a** ja **b** Product-tietuen **name**-kenttien mukaan. Vertailu
tapahtuu ASCII-arvojen mukaan eli voit käyttää strcmp-funktiota apuna. Funktio
palauttaa strcmp-funktiokutsun paluuarvon. Huomaa,
että muuttujat annetaan tyyppinä **const void ***.

**int compareNum(const void* a, const void* b)** -funktion olisi taas tarkoitus
verrata **in_stock**-kentän arvoja. Numeerisesti suurempi arvo pitäisi olla järjestyksessä ensimmäisenä.
Funktio palauttaa negatiivisen arvon, jos **b**:n pitäisi olla järjestyksessä **a**:n
jälkeen. Ja päinvastaisessa tilanteessa taas positiivisen arvon. Jos arvot ovat
samat, järjestys määrätään edellisen kohdan mukaan.

**const Product* findProduct(const Product* p_array, const char* searchkey, int (\*cmp)(const void\*, const void\*))** -funktion
etsii yhden tuotteen järjestetystä **Product***-taulukosta. Tässä funktiossa on tarkoitus
käyttää bsearch-funktiota. Funktio palauttaa bsearch-funktiokutsun paluuarvon. Annettu
**searchkey** on etsittävän tuotteen nimi. Tätä ei voi siis suoraan antaa bsearch-funktiolle,
koska bsearch vaatii, että etsittävä alkio on samaa tyyppiä kuin taulukko, josta
sitä etsitään.

Funktioiden toiminta ja rajapinnat on selvitetty myös otsaketiedostossa.
Pieni testiohjelma on mukana **main.c**:ssä
ja funktioiden kuvaukset löytyvät **shopfunctions.h**-tiedostosta.

Bsearch-funktiosta lisää esimerkiksi täällä:
**[bsearch](http://www.cplusplus.com/reference/cstdlib/bsearch/)**

Kun tehtävä on koodattu oikein, mainin tuloste näyttää seuraavalta.

    sorted lexically:
    product: bread price: 2.700000 in stock: 12
    product: butter price: 4.200000 in stock: 5
    product: cereals price: 3.200000 in stock: 12
    product: cookies price: 12.300000 in stock: 23
    product: peanut butter price: 1.200000 in stock: 5
    Found product:
    cookies
    Product not found!
    sorted by in stock:
    product: cookies price: 12.300000 in stock: 23
    product: bread price: 2.700000 in stock: 12
    product: cereals price: 3.200000 in stock: 12
    product: butter price: 4.200000 in stock: 5
    product: peanut butter price: 1.200000 in stock: 5


**Vinkkejä**

- Muista, että bsearch ottaa ensimmäisenä parametrinaan yhden tietotyyppialkion
(pointterin tällaiseen alkioon),
toisena parametrinaan listan, joka koostuu täsmälleen samantyyppisistä alkioista.
- Muista myös, että taulukon kokoa ei voi selvittää pelkällä sizeof():illa, koska
sizeof(taulukko-osoitin) palauttaa vain itse osoittimen koon, ei taulukon alkioiden
määrää.
