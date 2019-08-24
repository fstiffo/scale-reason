[@bs.val] [@bs.scope "localStorage"] external getItem: string => string = "";
[@bs.val] [@bs.scope "localStorage"]
external setItem: (string, string) => unit = "";

let condominoToJson = (condomino: ScaleType.condomino) => {
  switch (condomino) {
  | ScaleType.Michela => "Michela"
  | ScaleType.Elena => "Elena"
  | ScaleType.Gerardo => "Gerardo"
  | ScaleType.Giulia => "Giulia"
  };
};

let movimentoToJson = ((data, operazione): ScaleType.movimento) => {
  let ScaleType.Data(y, m, d) = data;
  let (opType, condomino, causale, importo) =
    switch (operazione) {
    | ScaleType.VersamentoQuote(condomino, importo) => (
        "VersamentoQuote",
        condominoToJson(condomino),
        "",
        importo,
      )
    | ScaleType.PagamentoScale => ("PagamentoScale", "", "", (-1))
    | ScaleType.AltraSpesa(causale, importo) => (
        "AltraSpesa",
        "",
        causale,
        importo,
      )
    | ScaleType.AltroVersamento(causale, importo) => (
        "AltroVersamento",
        "",
        causale,
        importo,
      )
    | ScaleType.Prestito(importo) => ("Prestito", "", "", importo)
    | ScaleType.Restituzione(importo) => ("Restituzione", "", "", importo)
    };

  {j|
    [
      {
        "y": $y,
        "m": $m,
        "d": $d
      },
      {
        "opType": "$opType",
        "condomino": "$condomino",
        "causale": "$causale",
        "importo": $importo
      }
    ]
    |j};
};
