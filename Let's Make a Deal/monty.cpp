/* Name: Devin Moure
 Date: 10/17/17
 Section: 21
 Assignment: 4
 Due Date: 10/20/17
 About this project: Let's Make a Deal game.
 
 All work below was performed by Devin Moure */



#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


int startGame();


int main()
{
    
    
    startGame();
    
    return 0;
}


int startGame(){
    // declare variables and initiliaze loop variable
    double winningP;
    double losingP;
    double total;
    bool done = true;
    
    srand(time(NULL));
    //decide winning door
    int winningDoor = (rand() % 3) + 1;
    int num;
    //welcomes
    cout << "Welcome to the Monty Hall Let's Make a Deal Simulator!" << endl;
    while (done){
        cout << "Choose one of the Following: " << endl << "1 Play the Game" << endl << "2 See Stats" << endl << "3 Reset Stats" << endl << "4 Quit" << endl;
        
        cin >> num;
        
        //game switch
        
        switch(num){
                
            case 1 :
            {
                done = true;
                int i;
                cout << "Pick a Door, 1, 2, or 3!" << endl;
                
                cout << "---------    ---------    ---------- \n";
                cout << "|       |    |  ____ |    |  _____ | \n";
                cout << "|   |   |    |     | |    |      | | \n";
                cout << "|   |   |    |  ___| |    |   ___| | \n";
                cout << "|   |   |    | |     |    |      | | \n";
                cout << "|   |   |    | |____ |    |  ____| | \n";
                cout << "---------    ---------    ---------- \n";
                cin >> i;
                total = total + 1;
                
                cout << "You chose door #" << i << endl;
                cout << "I'll now open a door for you randomly that you didn't choose!" << endl;
                
                
                int firstDoor = (rand() % 3) + 1;
                //if it randomly picks your door as the door to open, randomize again.
                while (firstDoor==i){
                    int firstDoor = (rand() % 3) + 1;
                }
                
                //opens winning door on first try.
                if (firstDoor==winningDoor){
                    cout << "Opening door #" << firstDoor << " and it's a BRAND NEW CAR!" << endl;
                    cout << "YOU LOSE." << endl;
                    losingP = losingP + 1;
                }
                //gives chance to switch
                else{
                    cout << "Opening door #" << firstDoor << " and it's a GOAT!" << endl;
                    cout << "Now, I'll be a kind host and give you the chance to switch your door!" << endl;
                    
                    cout << "Would you like door #" << winningDoor << " or door #" << i << endl;
                    cin >> i;
                    
                    cout << "Opening door #" << i << endl;
                    
                    if (i==winningDoor){
                        cout << "It's a BRAND NEW CAR!!!!" << endl;
                        winningP = winningP + 1;
                    }
                    else{
                        cout << "baaaaaaaaaaaaa.... it's a GOAT!!!! You LOSE!" << endl;
                        losingP = losingP + 1;
                    }
                }
                
                
                
                
                
                
                
                
                
                break;
            }
                // stats
            case 2 :
                done = true;
                cout << "Results after " << total << " games: " << endl;
                cout << "Wins: " << winningP << "                    " << "Losses: " << losingP << endl;
                cout << fixed << setprecision(2) << "Win %: " << (winningP / total) * 100 << "                    " << "Loss %: " << (losingP / total) * 100 << endl;
                
                break;
                
                //reset stats
            case 3 :
                done = true;
                winningP = 0;
                losingP = 0;
                total = 0;
                break;
                // exits
            case 4 :
                done=false;
                cout << "Goodbye!" << endl;
                break;
        }
        
        
    }
    return winningDoor;
}
