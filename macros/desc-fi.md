### Tehtävä 10.1: Macros (20 pts)

**Tavoite:** Harjoittele makrojen käyttöä.

Tässä tehtävässä ei ole varsinaista .c - päätteistä tiedostoa
työstettäväksi perinteisen **main.c**:n lisäksi,
vaan tehtävä tehdään **macros.h** -otsakkeeseen, jonka toteutat. Sinne sinun
tulee toteuttaa seuraavat makrot:

**(a): EQ3(a,b,c)** joka ottaa kolme parametria ja tutkii niiden
  yhtäsuuruuden. Makro evaluoituu arvoksi 1, jos kaikki parametrit
  ovat yhtäsuuria (==), muutoin arvoksi tulee 0.

**(b): MIN3(a,b,c)** joka evaluoi kolme arvoa ja palauttaa niistä pienemmän.

**Vihje:** Käytä *[ehto](https://en.wikipedia.org/wiki/%3F:#C)*-operaattoria if-else:n sijaan.
