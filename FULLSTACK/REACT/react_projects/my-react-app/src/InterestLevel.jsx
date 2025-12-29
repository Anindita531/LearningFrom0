import React from 'react'
import { FaBookOpen } from 'react-icons/fa6'

function InterestLevel({interestLevel}) {
  return (
    <div><h2><FaBookOpen color='blue'/>
    Interest Level: {interestLevel}    
    </h2></div>
  )
}

export default InterestLevel