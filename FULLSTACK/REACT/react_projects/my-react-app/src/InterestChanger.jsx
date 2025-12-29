import React, { useState } from 'react'

function InterestChanger() {
    const [InterestLevel, setInterestlevel] = useState("High");
    return (


        <div>
            <h2>My Interest Level: {InterestLevel}</h2>
            <button onClick={() => {
                (InterestLevel=="High")? setInterestlevel("Very High") : setInterestlevel("High");
            }}>   Change Interest</button>
        </div>
    )
}

export default InterestChanger