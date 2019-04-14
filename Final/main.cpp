#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Person.h"
#include "HealthBar.h"
#include "FightMoves.h"
using namespace std;
 
//Functions
    void startup_menu();
    void create_person();
    void existing_player();
    void choose_second_fighter();
    void fight();
    int fight_moves(int st, int sp, int num);
    void won_round();
    void player_lost();
    void use_bar();
    void newlines();
    void change_case(string &convert);
    
    // The exissting people
    Person existing_person[4] = 
    {
        Person("Bruno", 100, 150, 150), 
        Person("Victor", 120, 140, 135), 
        Person("Dr.Specter", 110, 145, 155), 
        Person("Machiavelli", 100, 110, 110)
    };

    //
    Person chosen_person[2] = 
    {Person(), Person()};// Two selected fighters
    
    Person chosen_person_save("none" , 100, 0, 0); // Saves player 1's health
    Item bars(0, 0, 0);
    int times_won = 0;
    int purpose_ignore = 0;
    char repeat = 'y';
 
int main()
{
    startup_menu();
 
    while(repeat == 'y' || repeat == 'Y') 
    {
        fight();
 
        if(repeat == 'y' || repeat == 'Y')
            choose_second_fighter();
    }
 
    cout << "\n\n\t\t";
    system("PAUSE"); 
 
    return 0;
}
 
void startup_menu() 
{
    int choose_player;
    cout << "\n\t\t<<<Welcome>>>";
    cout << "\n\n\t\t<Starting menu>" << endl;
 
    cout << "\n\t\tWould you like to create a new person," << "\n\t\tor choose an exsisting player? ";
    cout << "\n\n\t\t1: New Person";
    cout << "\n\t\t2: Existing Player";
 
    do{
        cout << "\n\n\t\tI would like: ";
        cin >> choose_player;
    }while(choose_player <= 0 || choose_player >= 3);
 
    if(choose_player == 1)
        create_person();
    
    else if(choose_player == 2)
        existing_player();
 
    return;
}
 
void create_person() 
{
    newlines();
    string name;
    int h, st, sp;
 
    cout << "\t\t<Create new player>";
 
    cout << "\n\n\t\tWhat is your players name?";
    cout << "\n\t\tNew player name: ";
    cin >> name;
 
    change_case(name);
 
    cout << "\n\t\tHow much strength does " << name << " have?";
    cout << "\n\t\tYou can't have more than 120 strength.";
 
    do{
        cout << "\n\n\t\t";
        cout << name << "'s strength is: ";
        cin >> st;
    }while(st <= 0 || st >= 121);
 
    cout << "\n\t\tNow we need to know " << name << "'s speed.";
    cout << "\n\t\tThe speed can not be more than 120.";
 
    do{
        cout << "\n\n\t\t";
        cout << name << "'s speed is: ";
        cin >> sp;
    }while(sp <= 0 || sp >= 121);
 
    h = 100;
 
    cout << "\n\t\tIn time " << name << " will gain more health with experience" << "\n\t\tCurrently " << name << "'s health is: " << h;
 
    cout << "\n\n\t\t";
    system("PAUSE"); // give time to read 
 
    chosen_person[0] = Person(name, h, st, sp);
 
    cin.ignore(); 
 
    choose_second_fighter();
 
    return;
}
 
void existing_player() 
{
    string existing_player_choice;
 
    newlines();
 
    cout << "\t\t<Existing Player>";
 
    cout << "\n\n\t\tChoose your Player!";
 
    for(int i = 0, j = 1; i >= 0 && i <= 3; i++, j++) 
    {
        cout << "\n\n\t\t" << j <<": " << existing_person[i].get_name();    //getting the attributes of the existing people 
        cout << "\n\t\t  Health: " << existing_person[i].get_health();
        cout << "\n\t\t  Strength: " << existing_person[i].get_strength();
        cout << "\n\t\t  Speed: " << existing_person[i].get_strength();
    }
 
    cout << "\n\n\t\tI Choose: ";
 
    cin.ignore();
    getline(cin, existing_player_choice);
 
    change_case(existing_player_choice);
 
    // easy enough, if they chose a number or type in the name it has the same result
    if(existing_player_choice == "1" || existing_player_choice == "Bruno")
        {chosen_person[0] = existing_person[0]; chosen_person_save.set_health(existing_person[0].get_health());}
 
    else if(existing_player_choice == "2" || existing_player_choice == "Victor")
        {chosen_person[0] = existing_person[1]; chosen_person_save.set_health(existing_person[1].get_health());}
 
    else if(existing_player_choice == "3" || existing_player_choice == "Dr.Specter" || existing_player_choice == "Dr.Specter")
        {chosen_person[0] = existing_person[2]; chosen_person_save.set_health(existing_person[2].get_health());}
 
    else if(existing_player_choice == "4" || existing_player_choice == "Machiavelli")
        {chosen_person[0] = existing_person[3]; chosen_person_save.set_health(existing_person[3].get_health());}
 
    else
        {cout << "\n\n\t\tInvalid Input! Program Failure... Please close and restart---"; system("PAUSE");} // safe gaurd for people who cant follow directions
 
    choose_second_fighter();
 
    return;
}
 
void choose_second_fighter() 
{
    string choose_fighter;
 
    newlines();
 
    cout << "\t\t<Second Fighter>";
 
    cout << "\n\n\t\tChoose the person you want to fight.";
 
    for(int i = 0, j = 1; i >= 0 && i <= 3; i++, j++) 
    {
        cout << "\n\n\t\t" << j <<": " << existing_person[i].get_name();    // getting attributes for the second fighter 
        cout << "\n\t\t  Health: " << existing_person[i].get_health();
        cout << "\n\t\t  Strength: " << existing_person[i].get_strength();
        cout << "\n\t\t  Speed: " << existing_person[i].get_speed();
    }
 
    cout << "\n\n\t\tI want to fight: ";
 
    if (purpose_ignore >= 1)
        cin.ignore();
 
    getline(cin, choose_fighter);
 
    change_case(choose_fighter);
 
    if(choose_fighter == "1" || choose_fighter == "Bruno")
        chosen_person[1] = existing_person[0];
 
    else if(choose_fighter == "2" || choose_fighter == "Victor")
        chosen_person[1] = existing_person[1];
 
    else if(choose_fighter == "3" || choose_fighter == "Dr.Specter" || choose_fighter == "Dr.Specter")
        chosen_person[1] = existing_person[2];
 
    else if(choose_fighter == "4" || choose_fighter == "Machiavelli")
        chosen_person[1] = existing_person[3];
 
    else {cout << "\n\n\t\tInvalid Input! Program Failure... Please close and restart---"; system("PAUSE");}
 
    return;
}
 
void fight() 
// pretty straight forward if each move gets printed and attack strength/health drop, bars are rewards if you win 
// then you get extra health for a stronger enimies. randomly generated enemies moves.
{
    int fight_choice;
    int i = 0;
    int j = 5;
    bool win;
 
    if(times_won >= 1)
        j = 6;
 
    while(chosen_person[0].get_health() > 0 && chosen_person[1].get_health() > 0) 
    {
        newlines();
 
        cout << "\t\t" << chosen_person[0].get_name() << " choose ";
 
        if(i == 0)
            cout << "an attack.";
 
        else
            cout << "another attack.";
 
        do{
            cout << "\n\n\t\t<1. Punch / 2. Kick>\n\t\t<3. Slam / 4. Drop kick>";
 
            if(j == 6)
                cout << "\n\t\t<5. Items>";
 
            cout << endl << "\t\t";
            cin >> fight_choice;

        }while(fight_choice <= 0 || fight_choice >= j);
 
        if(fight_choice == 1) 
        {
            chosen_person[1].set_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 1));
            cout << "\n\t\tYou Punched " << chosen_person[1].get_name() << ", his health is now: ";
 
            if (chosen_person[1].get_health() <= 0)
                {cout << "0" << endl << endl; chosen_person[1].set_health(-1);}
 
            else
                cout << chosen_person[1].get_health() << endl << endl;
        }
 
        else if(fight_choice == 2) 
        {
            chosen_person[1].set_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 2));
            cout << "\n\t\tYou Kicked " << chosen_person[1].get_name() << ", his health is now: ";
 
            if (chosen_person[1].get_health() <= 0)
                {cout << "0" << endl << endl; chosen_person[1].set_health(-1);}
 
            else
                cout << chosen_person[1].get_health() << endl << endl;
        }
 
        else if(fight_choice == 3) 
        {
            chosen_person[1].set_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 3));
            cout << "\n\t\tYou Slamed " << chosen_person[1].get_name() << " on the ground, his health is now: ";
 
            if (chosen_person[1].get_health() <= 0)
                {cout << "0" << endl << endl; chosen_person[1].set_health(-1);}
 
            else
                cout << chosen_person[1].get_health() << endl << endl;
        }
 
        else if(fight_choice == 4) 
        {
            chosen_person[1].set_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 4));
            cout << "\n\t\tYou Drop Kicked " << chosen_person[1].get_name() << ", his health is now: ";
 
            if (chosen_person[1].get_health() <= 0)
                {cout << "0" << endl << endl; chosen_person[1].set_health(-1);}
 
            else
                cout << chosen_person[1].get_health() << endl << endl;
        }
 
        else if(times_won >= 1 && fight_choice == 5) 
        { // Bars
            use_bar();
        }
 
        // Second fighter attack
 
        srand(time(NULL));
        int ran_pick = rand() % 5 + 1;
 
        if(chosen_person[1].get_health() < 0) 
        {
            ran_pick = 0;
            win = 1;
        }
 
        else if(chosen_person[1].get_health() > 0) 
        {
            cout << "\n\t\t<" << chosen_person[1].get_name() << "'s turn>" << endl;
            win = 0;
        }
 
        if(ran_pick == 0)
            continue;
 
        else if(ran_pick == 1) 
        {
            chosen_person[0].set_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 1));
            cout << "\n\t\t" << chosen_person[1].get_name() << " punched you! Your health is now: ";
 
            if (chosen_person[0].get_health() <= 0)
                {cout << "0" << endl << endl; chosen_person[0].set_health(-1);}
 
            else
                cout << chosen_person[0].get_health() << endl << endl;
        }
 
        else if(ran_pick == 2) 
        {
            chosen_person[0].set_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 2));
            cout << "\n\t\t" << chosen_person[1].get_name() << " kicked you! Your health is now: ";
 
            if (chosen_person[0].get_health() <= 0)
                {cout << "0" << endl << endl; chosen_person[0].set_health(-1);}
 
            else
                cout << chosen_person[0].get_health() << endl << endl;
        }
 
        else if(ran_pick == 3) 
        {
            chosen_person[0].set_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 3));
            cout << "\n\t\t" << chosen_person[1].get_name() << " slammed you on the ground! Your health is now: ";
 
            if (chosen_person[0].get_health() <= 0)
                {cout << "0" << endl << endl; chosen_person[0].set_health(-1);}
 
            else
                cout << chosen_person[0].get_health() << endl << endl;
        }
 
        else if(ran_pick == 4) 
        {
            chosen_person[0].set_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 4));
            cout << "\n\t\t" << chosen_person[1].get_name() << " drop kicked you! Your health is now: ";
 
            if (chosen_person[0].get_health() <= 0)
                {cout << "0" << endl << endl; chosen_person[0].set_health(-1);}
 
            else
                cout << chosen_person[0].get_health() << endl << endl;
        }
 
        else if(ran_pick == 5)
            cout << "\t\t" << chosen_person[1].get_name() << " missed you! Your health is still: " << chosen_person[0].get_health() << endl << endl;
 
        if(chosen_person[0].get_health() > 0)
        {
            cout << "\n\t\t";
            system("PAUSE"); // Lets them read the attacks
        }
 
        i++; // Increases i to change some wording
    }
 
    if(win == 1)
        won_round();
 
    else
        player_lost();
 
    return;
}
 
 
void won_round() 
{
    srand(time(NULL));
    times_won++;
    purpose_ignore++;
    chosen_person[0].set_health(chosen_person_save.get_health());
    chosen_person[1].set_health(100);
    int item_won = rand() % 3 + 1;
 
    cout << "\t\tYou won!";
    cout << "\n\n\t\tYou have been rewarded ";
 
    if(item_won == 1)
    {
        cout << "a small protein bar! (+20 health)";
        bars.small_bar++;
    }
 
    else if(item_won == 2)
    {
        cout << "a medium protein bar! (+30 health)";
        bars.medium_bar++;
    }
 
    else if(item_won == 3)
    {
        cout << "a large protein bar! (+40 health)";
        bars.large_bar++;
    }
 
    cout << "\n\n\t\tItems can be used in game at the cost of a turn.";
 
    cout << "\n\n\t\t";
    system("PAUSE"); // Lets them read
 
    int ability_gain[3] = {rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1};
 
    chosen_person[0].set_health(ability_gain[0] += chosen_person[0].get_health());
    chosen_person_save.set_health(chosen_person[0].get_health());
    chosen_person[0].set_strength(ability_gain[1] += chosen_person[0].get_strength());
    chosen_person[0].set_speed(ability_gain[2] += chosen_person[0].get_speed());
 
    cout << "\n\t\tYour health is now: " << chosen_person[0].get_health();
    cout << "\n\t\tYour strength is now: " << chosen_person[0].get_strength();
    cout << "\n\t\tYour speed is now: " << chosen_person[0].get_speed();
 
    cout << "\n\n\t\tWould you like to fight another person? (y/n) ";
    cin >> repeat;
 
    return;
}
 
void player_lost() 
{
    chosen_person[0].set_health(chosen_person_save.get_health());
    chosen_person[1].set_health(100);
    purpose_ignore++;
 
    cout << "\n\n\t\tYou have lost.";
    cout << "\n\t\tWould you like to fight another person? (y/n) ";
    cin >> repeat;
 
    return;
}
 
void use_bar()
{
    int choose_bar;
    char another_bar;
 
    do{
        cout << "\n\n\t\tWhich bar would you like to use? ";
        cout << "\n\t\t 1: Small Bar: " << bars.small_bar;
        cout << "\n\t\t 2: Medium Bar: " << bars.medium_bar;
        cout << "\n\t\t 3: Large bar: " << bars.large_bar;
 
        do{
            cout << "\n\n\t\tI choose: ";
            cin >> choose_bar;
        }while(choose_bar <= 0 || choose_bar >= 4);
 
        if(choose_bar == 1 && bars.small_bar >= 1)
        {
            chosen_person[0].set_health(chosen_person[0].get_health() + 20);
            bars.small_bar--;
            cout << "\n\n\t\tYour health is now: " << chosen_person[0].get_health();
        }
 
        else if(choose_bar == 2 && bars.medium_bar >= 1)
        {
            chosen_person[0].set_health(chosen_person[0].get_health() + 30);
            bars.medium_bar--;
            cout << "\n\n\t\tYour health is now: " << chosen_person[0].get_health();
        }
 
        else if(choose_bar == 3 && bars.large_bar >= 1)
        {
            chosen_person[0].set_health(chosen_person[0].get_health() + 40);
            bars.large_bar--;
            cout << "\n\n\t\tYour health is now: " << chosen_person[0].get_health();
        }
 
        else
            cout << "\n\t\tNot enough bars!";
 
        cout << "\n\n\t\tWould you like to use another bar? (y/n) ";
        cin >> another_bar;
    }while(another_bar == 'y' || another_bar == 'Y');
 
    return;
}
 
void newlines() 
{
    cout << "\n\n\n\n\n\n\n\n";
}
 
void change_case(string &convert) 
{
    for(int i = 0; convert[i]; i++) 
    {
        if(isupper(convert[i]))
            convert[i] = tolower(convert[i]);
        else
            continue;
    }
 
    convert.at(0) = toupper(convert.at(0));
 
    return;
}