### Tehtävä 10.2: Printer (25 pts)

**Tavoite**: Harjoitellaan vaihtuvan mittaisten parametrilistojen
  käyttöä.

Toteuta funktio `int myprint(const char *str, ...)` joka tulostaa vaihtuvan määrän
kokonaislukuja standarditulostevirtaan noudatten parametrinaan
saamaansa muotoilumäärittelyä. Funktio voi siis saada vaihtuvan määrän
parametreja: **ensimmäinen parametri on aina (muuttumaton)
merkkijono**, joka määrittelee tulosteen ulkoasun, kuten *printf*:kin
tekee. Sitä seuraa kokonaislukuja (int), joiden määrä riippuu
muotoilumerkkijonosta, ja siinä olevien '&' - merkkien
määrästä. Funktiossamme '&' toimii muotoilumääreenä, ja se tulee
korvata kyseisellä kohdalla parametrilistassa olevalla
kokonaisluvulla. Toteutamme siis yksinkertaistetun version
*printf*-funktiosta. Koska tulostamme vain kokonaislukuja, mitään
lisämääreitä korvattavaan merkkiin ei tarvita.

Esimerkiksi tämä on yksi hyväksyttävä tapa kutsua funktiota:
`myprint("Number one: &, number two: &\n", 120, 1345);`

**Funktion tulee palauttaa kokonaisluku**, joka kertoo kuinka monta
  muotoilumäärettä funktiossa oli.

Jos toteutuksesi toimii oikein, zip paketissa oleva main-funktio
tulostaa seuraavaa:

    Hello!
    Number: 5
    Number one: 120, number two: 1345
    Three numbers: 12 444 5555
    I just printed 3 integers

**Vinkki:** Muistutuksena, että
*[strchr](http://www.cplusplus.com/reference/cstring/strchr/?kw=strchr)*
palauttaa osoittimen
seuraavaan kohtaan merkkijonossa, jossa annettu merkki
esiintyy. *[fputc](http://www.cplusplus.com/reference/cstdio/fputc/?kw=fputc)*:n
avulla voit tulostaa yhden merkin kerrallaan,
myös standarditulostevirtaan. Näistä funktioista saattaa olla hyötyä.
