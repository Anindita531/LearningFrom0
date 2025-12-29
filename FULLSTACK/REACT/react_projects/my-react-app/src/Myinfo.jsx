import React from 'react'
import { FaSmile, FaSchool } from 'react-icons/fa'
import Subject from './Subject'
import Teacher from './Teacher'
import InterestLevel from './InterestLevel'
import SubjectDetails from './SubjectDetails'

function Myinfo() {
    return (
        <div>
            <h2>
                <FaSmile color="orange" size="1.5em" style={{ marginRight: '8px' }} />
                Hi, I am Anindita Ghosh
            </h2>
            <h2>
                <FaSchool color='skyblue' size="1.6em" style={{ marginLeft: '5px' }} /> Studying at St.Thomas' College of Engineering & Technology
            </h2>
            <Subject />
            {/* props পাঠানো হলো */}
            <Subject favSubject="Neural Networks & Deep Learning" />
            <Teacher teachername="Prof. S. ch" />
            <InterestLevel interestLevel=
                "high" />
            <SubjectDetails subjectName={"Operation Research"}
                TeacherName={"Prof. S. Ch."}
                InterestLevel={"High"}
            />
        </div>
    )
}

export default Myinfo
