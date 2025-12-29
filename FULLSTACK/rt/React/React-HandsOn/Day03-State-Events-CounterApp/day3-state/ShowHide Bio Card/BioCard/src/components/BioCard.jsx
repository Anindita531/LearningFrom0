import { useState } from "react";

function BioCard() {
  const [visible, setVisible] = useState(false);

  return (
    <div style={{ textAlign: "center" }}>
      <button onClick={() => setVisible(!visible)}>
        {visible ? "Hide Bio" : "Show Bio"}
      </button>
      {visible && <p>I’m Anindita, exploring UI-UX through React 💜</p>}
    </div>
  );
}

export default BioCard;
