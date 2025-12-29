import { useState } from 'react'
import ThemeToggle from './components/ThemeToggle.jsx'
import './App.css'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <ThemeToggle />
    </>
  )
}

export default App
