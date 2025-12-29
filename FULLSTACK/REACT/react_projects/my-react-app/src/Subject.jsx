import React from 'react'
import { FaHighlighter } from 'react-icons/fa'
//props
function Subject({favSubject}) {
  return (
    <h2> <FaHighlighter color='black'/>Favourite Subject: {favSubject}
    
    </h2>
  )
}

export default Subject