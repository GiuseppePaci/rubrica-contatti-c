# 📇 Rubrica Contatti in C

Una semplice applicazione da terminale per gestire contatti (Nome, Cognome, Telefono) con salvataggio su file.  
Progetto realizzato da zero per esercitazione e pubblicazione su GitHub.

---

## 🔧 Funzionalità

- ✏ Aggiunta contatti
- 📄 Visualizzazione rubrica
- 💾 Salvataggio automatico su `rubrica.txt`
- 🔁 Caricamento contatti all’avvio
- 🔐 Nessun limite finché non si raggiungono 100 elementi

---

## 📌 Obiettivi didattici

Questo progetto serve per imparare e consolidare:

| Concetto | Dove viene usato |
|--------|----------------|
| `struct` | modello del contatto |
| file I/O (`fopen`, `fprintf`, `fscanf`) | salvataggio e lettura della rubrica |
| array dinamico di contatti | gestione lista |
| `fgets` e pulizia input | lettura stringhe in C |
| separazione in funzioni | codice più chiaro e modulare |

---

## ▶ Compilazione ed esecuzione

```bash
gcc rubrica.c -o rubrica
./rubrica
