import { useState} from  'react';
import './App.css';

function tournamentWinner(competitions, results){

    let round = 0;
    const participants = new Map();
    let maxScore = 0;
    let winner;

    for(let i = 0; i < results.length; i++){
        if(results[i] === 0) {
            participants.set(competittions[i][1],
                (participants.get(competititons[i][1]) || 0) + 1);
        }
        else {
            participants.set(competitions[i][0], 
                (participants.get(competitions[i][0]) || 0) + 1);
        }
    }

    return winner;
}

export default function App(){
    const competitions = [
        ['TeamA', 'TeamB'],
        ['TeamC', 'TeamA'],
        ['TeamB', 'TeamC'],
    ];
    const results = [1, 0, 0];

    const winner = tournamentWinner(competitions, results);

    return(
        <main>
            <p> The winner is {winner}</p>
        </main>
    );
}

