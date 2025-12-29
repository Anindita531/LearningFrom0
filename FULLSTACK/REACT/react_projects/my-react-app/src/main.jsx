import React from "react";
import ReactDOM from "react-dom/client";
import App from "./App";
import './style.css'
import Myinfo from "./Myinfo";
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import App1 from "./App1";
ReactDOM.createRoot(document.getElementById("root")).render(
  <React.StrictMode>
    <App />
    <Myinfo/>
    <App1/>
  </React.StrictMode>
);
