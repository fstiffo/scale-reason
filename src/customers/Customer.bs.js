// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var React = require("react");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");

var form = Css.style(/* :: */[
      Css.width(Css.pct(100)),
      /* :: */[
        Css.maxWidth(Css.px(800)),
        /* :: */[
          Css.margin2(Css.px(10), Css.auto),
          /* :: */[
            Css.selector("label", /* :: */[
                  Css.display(Css.block),
                  /* :: */[
                    Css.margin2(Css.px(20), Css.zero),
                    /* :: */[
                      Css.selector("input", /* :: */[
                            Css.fontSize(Css.px(14)),
                            /* :: */[
                              Css.lineHeight(Css.px(40)),
                              /* :: */[
                                Css.display(Css.block),
                                /* :: */[
                                  Css.width(Css.pct(100)),
                                  /* :: */[
                                    Css.height(Css.px(40)),
                                    /* :: */[
                                      Css.padding(Css.px(10)),
                                      /* :: */[
                                        Css.boxSizing(Css.borderBox),
                                        /* [] */0
                                      ]
                                    ]
                                  ]
                                ]
                              ]
                            ]
                          ]),
                      /* [] */0
                    ]
                  ]
                ]),
            /* :: */[
              Css.selector("input[type=submit]", /* :: */[
                    Css.display(Css.block),
                    /* :: */[
                      Css.width(Css.px(200)),
                      /* :: */[
                        Css.height(Css.px(40)),
                        /* :: */[
                          Css.backgroundColor(Css.firebrick),
                          /* :: */[
                            Css.borderStyle(Css.none),
                            /* :: */[
                              Css.cursor(/* pointer */-786317123),
                              /* :: */[
                                Css.color(Css.white),
                                /* [] */0
                              ]
                            ]
                          ]
                        ]
                      ]
                    ]
                  ]),
              /* [] */0
            ]
          ]
        ]
      ]
    ]);

var Styles = /* module */[/* form */form];

var customers = /* array */[
  /* record */[
    /* id */1,
    /* name */"Christina Langworth",
    /* address : record */[
      /* street */"81 Casey Stravenue",
      /* city */"Beattyview",
      /* state */"TX",
      /* zip */"57918"
    ],
    /* phone */"877-549-1362",
    /* email */"Christina.Langworth@gmail.com"
  ],
  /* record */[
    /* id */2,
    /* name */"Victor Tillman",
    /* address : record */[
      /* street */"2811 Toby Gardens",
      /* city */"West Enrique",
      /* state */"NV",
      /* zip */"40465"
    ],
    /* phone */"(502) 091-2292",
    /* email */"Victor.Tillman30@gmail.com"
  ],
  /* record */[
    /* id */3,
    /* name */"Annabell Pouros",
    /* address : record */[
      /* street */"1550 Hodkiewicz Squares",
      /* city */"New Mireyaland",
      /* state */"CA",
      /* zip */"10212"
    ],
    /* phone */"(495) 084-7687",
    /* email */"Annabell.Pouros@yahoo.com"
  ],
  /* record */[
    /* id */4,
    /* name */"Laurence Skiles",
    /* address : record */[
      /* street */"4131 Alena Light",
      /* city */"Lake Ashtynmouth",
      /* state */"ND",
      /* zip */"68071"
    ],
    /* phone */"(687) 543-0380",
    /* email */"Laurence6@yahoo.com"
  ],
  /* record */[
    /* id */5,
    /* name */"Retta Terry",
    /* address : record */[
      /* street */"409 Frida Heights",
      /* city */"South Pearl",
      /* state */"NH",
      /* zip */"04200"
    ],
    /* phone */"(710) 751-3763",
    /* email */"Retta_Terry@gmail.com"
  ]
];

function getId(pathname) {
  try {
    return Caml_format.caml_int_of_string(pathname.replace((/\D/g), ""));
  }
  catch (exn){
    return -1;
  }
}

function getCustomer(customers) {
  var id = getId(window.location.pathname);
  return Caml_option.undefined_to_opt(customers.find((function (customer) {
                    return customer[/* id */0] === id;
                  })));
}

function getDefault(customers) {
  return /* record */[
          /* id */customers.length + 1 | 0,
          /* name */"",
          /* address : record */[
            /* street */"",
            /* city */"",
            /* state */"",
            /* zip */""
          ],
          /* phone */"",
          /* email */""
        ];
}

function make(param) {
  var match = React.useState((function () {
          var match = window.location.pathname.includes("create");
          if (match) {
            return /* Create */0;
          } else {
            return /* Update */1;
          }
        }));
  var mode = match[0];
  var match$1 = React.useState((function () {
          if (mode) {
            return Belt_Option.getWithDefault(getCustomer(customers), getDefault(customers));
          } else {
            return getDefault(customers);
          }
        }));
  var customer = match$1[0];
  return React.createElement("form", {
              className: form
            }, React.createElement("label", undefined, "Name", React.createElement("input", {
                      defaultValue: customer[/* name */1],
                      type: "text"
                    })), React.createElement("label", undefined, "Street Address", React.createElement("input", {
                      defaultValue: customer[/* address */2][/* street */0],
                      type: "text"
                    })), React.createElement("label", undefined, "City", React.createElement("input", {
                      defaultValue: customer[/* address */2][/* city */1],
                      type: "text"
                    })), React.createElement("label", undefined, "State", React.createElement("input", {
                      defaultValue: customer[/* address */2][/* state */2],
                      type: "text"
                    })), React.createElement("label", undefined, "Zip", React.createElement("input", {
                      defaultValue: customer[/* address */2][/* zip */3],
                      type: "text"
                    })), React.createElement("label", undefined, "Phone", React.createElement("input", {
                      defaultValue: customer[/* phone */3],
                      type: "text"
                    })), React.createElement("label", undefined, "Email", React.createElement("input", {
                      defaultValue: customer[/* email */4],
                      type: "text"
                    })), React.createElement("input", {
                  type: "submit",
                  value: mode ? "Update" : "Create"
                }));
}

exports.Styles = Styles;
exports.customers = customers;
exports.getId = getId;
exports.getCustomer = getCustomer;
exports.getDefault = getDefault;
exports.make = make;
/* form Not a pure module */
