import React, { useState } from 'react';
import './style.css'
function FavoriteSubject() {
  // useState: state variable + updater function
  const [subject, setSubject] = useState("Neural Networks & Deep Learning");

  return (
    <div>
      <h2>My Favourite Subject: {subject}</h2>
      <button onClick={() => setSubject("Artificial Intelligence")}>
        Change Subject
      </button>
    </div>
  );
}

export default FavoriteSubject;
