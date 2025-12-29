import React from 'react';

function TeacherMessage({ teacher }) {
  return (
    <div>
      {teacher ? (
        <h2>Your Teacher: {teacher}</h2>
      ) : (
        <h2>No teacher assigned yet!</h2>
      )}
    </div>
  );
}

export default TeacherMessage;
