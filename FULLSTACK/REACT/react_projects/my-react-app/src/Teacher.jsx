import React from 'react'
import { FaChalkboardTeacher } from 'react-icons/fa'
function Teacher({teachername}) {
  return (
    <div>
        <h1><FaChalkboardTeacher/>Teacher:{teachername}</h1>
    </div>
  )
}

export default Teacher