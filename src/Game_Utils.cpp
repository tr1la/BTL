#include "Game_Utils.h"

bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    if(object1.x+object1.w>=object2.x && object2.x+object2.w>=object1.x
       && object1.y+object1.h>=object2.y && object2.y+object2.h>=object1.y)
    {
        return true;
    }
    return false;
}

string number_to_string(int number)
{
    stringstream ss;
    ss << setw(6) << setfill('0') << number;
    string val_score;
    ss >> val_score;
    return val_score;
}

string number_to_string_1(int number)
{
    stringstream ss;
    ss << setw(1) << setfill('0') << number;
    string val_score;
    ss >> val_score;
    return val_score;
}

void UpdateHighScore(int score)
{
    ofstream file("highscore.txt");
    if (!file.is_open())
    {
        cout << "Error, file is not opened.\n";
    }
    if(file.is_open())
    {
    	file << score;
	}
	file.close();
}

int HighScore()
{
    int highscore;
    ifstream file("highscore.txt");
    if (!file.is_open())
    {
        cout << "Error, file is not opened.\n";
    }
    if(file.is_open())
    {
    	int n;
    	file >> n;
    	highscore=n;
	}
	file.close();
	return highscore;

}

int RandomNumber(int min, int max)
{
   int randomNumber = rand() % (max - min + 1)+min ;
    return randomNumber;

}

