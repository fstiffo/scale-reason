[@react.component]
let make = (~href, ~className="", ~children) =>
  <a
    href
    className
    onClick={event => {
      ReactEvent.Mouse.preventDefault(event);
      ReasonReact.Router.push(href);
    }}>
    children
  </a>;
