import React from 'react'
import { FaSchoolCircleCheck, FaHighlighter, FaClover } from 'react-icons/fa6'
import { FaChalkboardTeacher } from 'react-icons/fa'
function SubjectDetails({ subjectName ,  TeacherName , InterestLevel }) {
    return (
        <div><h2><FaSchoolCircleCheck />SubjectDetails:</h2>
            <h2> <FaHighlighter color='black' />Favourite Subject: {subjectName}</h2>

            <h1><FaChalkboardTeacher />Taught by:{TeacherName}</h1>
            <h2><FaClover/>
               Interest Level:{InterestLevel } </h2>
        </div>
    )
}

export default SubjectDetails