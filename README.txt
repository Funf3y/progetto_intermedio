STRUTTURA E NOTE 

\classe InertialDriver
  - array stile C di dim 17 per le 17 letture 
  - buffer di tipo MyVector di dim costante --> circolare +> contiene le misure fatte 
  
  FUNZIONI 
  - La funzione push_back che accetta un array stile C contenente una misura e la\
  memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno);
  - La funzione pop_front che fornisce in output un array stile C contenente la misura più
vecchia e la rimuove dal buffer;

  - La funzione clear_buffer che elimina (senza restituirle) tutte le misure salvate;
  
  - La funzione get_reading che accetta un numero tra 0 e 16 e ritorna la corrispondente
lettura della misura più recente, senza cancellarla dal buffer;

  - L’overloading dell’operator<< che stampa a schermo l’ultima misura salvata (ma non la
rimuove dal buffer).

\classe MyVector per le misure 


Giulia B.
- 

Sara G.
- Aggiunto MyVector dal lab04
- Improntata classe InertialDriveri
- Improntato main (verificato che includesse)

Sara Z.
- creazione della struct per