// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var Component1$Scale = require("./Component1.bs.js");
var Component2$Scale = require("./Component2.bs.js");
var CustomerList$Scale = require("./customers/CustomerList.bs.js");

ReactDOMRe.renderToElementWithId(React.createElement(Component1$Scale.make, {
          message: "Hello! Click this text."
        }), "index1");

ReactDOMRe.renderToElementWithId(React.createElement(Component2$Scale.make, {
          greeting: "Hello!"
        }), "index2");

ReactDOMRe.renderToElementWithId(React.createElement(CustomerList$Scale.make, { }), "index3");

/*  Not a pure module */
