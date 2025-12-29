import React from 'react';

function Dashboard() {
  const subjects = ["AI", "NNDL", "Cloud Computing"];
  const teachers = ["Prof. S. Ch", "", "Dr. A. Roy"];

  return (
    <div>
      <h1>Student Dashboard</h1>

      <h2>Subjects & Teachers:</h2>
      <ul>
        {subjects.map((sub, idx) => (
          <li key={idx}>
            {sub} - {teachers[idx] ? teachers[idx] : "Teacher not assigned"}
          </li>
        ))}
      </ul>
    </div>
  );
}

export default Dashboard;
