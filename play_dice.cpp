/* Add your name here */
    
#include <iostream>
#include <cstdlib>  // contains the rand() and srand() function 
#include <ctime>    // time() function
using namespace std;


int main()
{
    srand(time(0)); // initialize random seed generator to current time: 
					// needed to generate a different sequence of random numbers
					// each time you run your program

    // Add your code to play the dice game here

    cout << "Welcome to our Dice Game!" << endl;
    
    int die1;
    int die2;
    int die_sum; // stores the sum of die1 and die2
    int player_point; // holds the player's points, is set to the die sum if the roll
                      // isn't equal to 7, 11, 2, 3, or 12

    char start_game;
    cout << "Do you want to play? (Y/N)"; // asks user if they want to play
    cin >> start_game; // receives user input

    while(start_game == 'Y' || start_game == 'y') // play game loop
    {

        die1 = rand() % 6 + 1; // init die1 and die2 to random integer values
        die2 = rand() % 6 + 1; // between 1 and 6
        
        die_sum = die1 + die2;
        
        if (die_sum == 7 || die_sum == 11)
        {
            cout << "The sum of your roll is " << die_sum << ". Congratulations! You win!" << endl;
            start_game = 'N'; // temporarily ends the game
            cout << "Do you want to play again? (Y/N)" << endl;
            cin >> start_game;
        }
        else if (die_sum == 2 || die_sum == 3 || die_sum == 12)
        {
            cout << "The sum of your roll is " << die_sum << ". Sorry, you lose." << endl;
            start_game = 'N';
            cout << "Do you want to play again? (Y/N)" << endl;
            cin >> start_game;
        }
        else
        {
            cout << "The sum of your roll is " << die_sum << endl;
            char new_roll; // init a new variable which allows for a new roll
            cout << "Press S to roll again!" << endl;
            cin >> new_roll; // receives input from user to start new roll

            while (new_roll == 'S' || new_roll == 's') // new roll loop
            {
                player_point = die_sum; // player's points are set to the original dice roll

                die1 = rand() % 6 + 1; // re-init die1 and die2 to random int values
                die2 = rand() % 6 + 1; // between 1 and 6
                
                int new_die_sum = die1 + die2; // stores the sum of the new role within
                                               // the new dice sum variable

                if (new_die_sum == player_point)
                {
                    cout << "The player's points are " << player_point << endl; // display's players
                    cout << "The sum of your roll is " << new_die_sum << endl;  // points and roll
                    cout << "Congratulations, You Win!" << endl;
                    cout << "Do you want to play again? (Y/N)" << endl;
                    cin >> start_game; // allows user to enter Y to play again, N to exit game
                }
                else if (new_die_sum == 7)
                {
                    cout << "The player's points are " << player_point << endl;
                    cout << "The sum of your roll is " << new_die_sum << endl;
                    cout << "Sorry, you lose." << endl;
                    cout << "Do you want to play again (Y/N)?" << endl;
                    cin >> start_game;
                }
                else
                {
                    cout << "The player's points are " << player_point << endl;
                    cout << "The sum of your roll is " << new_die_sum << endl;
                    cout << "Press S to roll again!" << endl;
                    cin >> new_roll;
                }
            }
        }
    }
}


