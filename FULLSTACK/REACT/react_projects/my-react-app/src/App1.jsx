import React from 'react'
import FavoriteSubject from './FavoriteSubject'
import './style.css'
import InterestChanger from './InterestChanger'
import NameUpdater from './NameUpdater'
import Dashboard from './Dashboard'
import SubjectList from './SubjectList'
import TeacherMessage from './TeacherMessage'
import Game from './TicTacToe'
function App1() {
  return (
    <div className='container'>
        <FavoriteSubject/>
        <Game/>
        <InterestChanger/>
       <NameUpdater/>
       <Dashboard/>
       <SubjectList/>
       <TeacherMessage/>
    </div>
  )
}
 

export default App1