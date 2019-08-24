/* Customer.re */
[@bs.val] external pathname: string = "window.location.pathname";

type mode =
  | Create
  | Update;

type state = {
  mode,
  customer: CustomerType.t,
};

type action =
  | Save(ReactEvent.Form.t);

module Styles = {
  open Css;

  let form =
    style([
      width(pct(100.)),
      maxWidth(px(800)),
      margin2(~v=px(10), ~h=auto),
      selector(
        "label",
        [
          display(block),
          margin2(~v=px(20), ~h=zero),
          selector(
            "input",
            [
              fontSize(px(14)),
              lineHeight(px(40)),
              display(block),
              width(pct(100.)),
              height(px(40)),
              padding(px(10)),
              boxSizing(borderBox),
            ],
          ),
        ],
      ),
      selector(
        "input[type=submit]",
        [
          display(block),
          width(px(200)),
          height(px(40)),
          backgroundColor(firebrick),
          borderStyle(none),
          cursor(`pointer),
          color(white),
        ],
      ),
    ]);
};

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

let getId = pathname =>
  try (Js.String.replaceByRe([%bs.re "/\\D/g"], "", pathname)->int_of_string) {
  | _ => (-1)
  };

let getCustomer = customers => {
  let id = getId(pathname);
  customers |> Js.Array.find(customer => customer.CustomerType.id == id);
};

let getDefault = (customers): CustomerType.t => {
  id: Belt.Array.length(customers) + 1,
  name: "",
  address: {
    street: "",
    city: "",
    state: "",
    zip: "",
  },
  phone: "",
  email: "",
};

[@react.component];
let make = () => {
  let (mode, _) =
    React.useState(() =>
      Js.String.includes("create", pathname) ? Create : Update
    );
  let (customer, _) =
    React.useState(() =>
      switch (mode) {
      | Create => getDefault(customers)
      | Update =>
        Belt.Option.getWithDefault(
          getCustomer(customers),
          getDefault(customers),
        )
      }
    );
  <form className=Styles.form>
    <label>
      {React.string("Name")}
      <input type_="text" defaultValue={customer.name} />
    </label>
    <label>
      {React.string("Street Address")}
      <input type_="text" defaultValue={customer.address.street} />
    </label>
    <label>
      {React.string("City")}
      <input type_="text" defaultValue={customer.address.city} />
    </label>
    <label>
      {React.string("State")}
      <input type_="text" defaultValue={customer.address.state} />
    </label>
    <label>
      {React.string("Zip")}
      <input type_="text" defaultValue={customer.address.zip} />
    </label>
    <label>
      {React.string("Phone")}
      <input type_="text" defaultValue={customer.phone} />
    </label>
    <label>
      {React.string("Email")}
      <input type_="text" defaultValue={customer.email} />
    </label>
    <input
      type_="submit"
      value={
        switch (mode) {
        | Create => "Create"
        | Update => "Update"
        }
      }
    />
  </form>;
};
