import React from 'react';

function SubjectList() {
  const subjects = ["AI", "NNDL", "Cloud Computing", "Operational Research"];

  return (
    <div>
      <h2>My Subjects:</h2>
      <ul>
        {subjects.map((subject, index) => (
          <li key={index}>{subject}</li>
        ))}
      </ul>
    </div>
  );
}

export default SubjectList;
