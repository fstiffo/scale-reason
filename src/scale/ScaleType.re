/* ScaleType.re */

type condomino =
  | Michela
  | Gerardo
  | Elena
  | Giulia;

type operazione =
  | VersamentoQuote(condomino, int)
  | PagamentoScale
  | AltraSpesa(string, int)
  | AltroVersamento(string, int)
  | Prestito(int)
  | Restituzione(int);

type data =
  | Data(int, int, int);

type movimento = (data, operazione);

type param = {
  costoScale: int,
  numPulizieMese: int,
  quotaMensile: int,
};

type attuale = (data, param);

type t = {
  tempoZero: data,
  attuale,
  condomini: list(condomino),
  movimenti: list(movimento),
};
