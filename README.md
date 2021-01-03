Ogni ricetta è caratterizzata da:
- il nome (stringa di massimo 255 caratteri, senza spazi)
- il tempo di preparazione, espresso in minuti
- l’elenco di ingredienti, ognuno in una certa quantità espressa in grammi.

Ogni ingrediente è caratterizzato da:
- il nome (stringa di massimo 255 caratteri, senza spazi)
- il costo al chilo (numero reale positivo)
- l’apporto calorico al grammo (numero reale positivo).

Le informazioni relative agli ingredienti sono memorizzate in un file (ingredienti.txt), organizzato come segue:
- sulla prima riga è presente il numero I di ingredienti
- sulle I righe successive sono riportati i dettagli di ogni ingrediente, in ragione di una terna <nome> <costo> <calorie> per riga.

Le informazioni relative alle ricette sono memorizzate in un file (ricette.txt), organizzato come segue:
- sulla prima riga è presente il numero R di ricette
- seguono R blocchi di righe in cui sono riportati i dettagli di ogni ricetta. Ogni blocco ha il seguente formato:
  - sulla prima riga è presente una terna <nome> <tempo> <num_ingredienti>
  - seguono num_ingredienti righe, ognuna riportante una coppia <nome_ingrediente> <grammi>.
  
Opzioni disponibili:
- stampa dei dettagli di una ricetta
- stampa dei dettagli di un ingrediente
- calcolo del costo di una ricetta
- calcolo dell’apporto calorico di una ricetta
- stampa dell’intero elenco di ricette
- stampa dell’intero elenco di ingredienti
- stampa dell’elenco di ricette in cui sia presente un dato ingrediente
- introduzione (e memorizzazione) di una nuova ricetta (usando solo ingredienti già disponibili in elenco).
