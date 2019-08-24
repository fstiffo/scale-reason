let customers: array(CustomerType.t) = [|
  {
    id: 1,
    name: "Christina Langworth",
    address: {
      street: "81 Casey Stravenue",
      city: "Beattyview",
      state: "TX",
      zip: "57918",
    },
    phone: "877-549-1362",
    email: "Christina.Langworth@gmail.com",
  },
  {
    id: 2,
    name: "Victor Tillman",
    address: {
      street: "2811 Toby Gardens",
      city: "West Enrique",
      state: "NV",
      zip: "40465",
    },
    phone: "(502) 091-2292",
    email: "Victor.Tillman30@gmail.com",
  },
  {
    id: 3,
    name: "Annabell Pouros",
    address: {
      street: "1550 Hodkiewicz Squares",
      city: "New Mireyaland",
      state: "CA",
      zip: "10212",
    },
    phone: "(495) 084-7687",
    email: "Annabell.Pouros@yahoo.com",
  },
  {
    id: 4,
    name: "Laurence Skiles",
    address: {
      street: "4131 Alena Light",
      city: "Lake Ashtynmouth",
      state: "ND",
      zip: "68071",
    },
    phone: "(687) 543-0380",
    email: "Laurence6@yahoo.com",
  },
  {
    id: 5,
    name: "Retta Terry",
    address: {
      street: "409 Frida Heights",
      city: "South Pearl",
      state: "NH",
      zip: "04200",
    },
    phone: "(710) 751-3763",
    email: "Retta_Terry@gmail.com",
  },
|];

let customers1 = DataPureReason.(parse(getItem("customers")));

module Styles = {
  open Css;

  let list =
    style([
      listStyleType(none),
      padding(zero),
      margin2(~v=px(50), ~h=auto),
      width(px(700)),
      selector(
        "li",
        [
          backgroundColor(rgba(150, 123, 182, 0.1)),
          margin2(~v=px(15), ~h=zero),
          selector(
            "a",
            [
              display(flexBox),
              flexWrap(wrap),
              textDecoration(none),
              padding(px(20)),
              selector(
                "p",
                [
                  flex(`num(1.)),
                  flexBasis(pct(50.)),
                  margin(zero),
                  color(black),
                ],
              ),
            ],
          ),
        ],
      ),
    ]);
};

[@react.component]
let make = () => {
  let cs =
    Belt.Array.map(customers1, customer =>
      <li key={string_of_int(customer.id)}>
        <Link href={"/customers/" ++ string_of_int(customer.id)}>
          <p> {React.string(customer.name)} </p>
          <p> {React.string(customer.address.street)} </p>
          <p> {React.string(customer.phone)} </p>
          <p> {React.string(customer.email)} </p>
        </Link>
      </li>
    );

  <div> <ul className=Styles.list> {ReasonReact.array(cs)} </ul> </div>;
};
