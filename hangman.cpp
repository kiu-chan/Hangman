#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
const int number_of_times_played = 7;
string WORD_LIST[] = {
 "angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry", "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
 };
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
string chooseWord()
{
    srand(time(0));
 int randomIndex = rand() % WORD_COUNT;
 return WORD_LIST[randomIndex];
}
const string FIGURE[] = {
 " ------------- \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | O \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | O \n"
 " | | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | O \n"
 " | /| \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | O \n"
 " | /|\\ \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | O \n"
 " | /|\\ \n"
 " | / \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | O \n"
 " | /|\\ \n"
 " | / \\ \n"
 " | \n"
 " ----- \n",
};
string hideWord(string Word)
{
    for (int i = 0; i < Word.size(); i++){
        char s = '-';
        swap(Word[i], s);
    }

    return Word;
}
string update(char Word, string& guessedWord, string& tickWord)
{
    for (int i = 0; i < tickWord.size(); i++)
        if(tickWord[i] == Word)
            guessedWord[i] = Word;
    return guessedWord;
}
void renderGame(string guessedWord, int badGuessCount)
{
    cout << guessedWord  << endl;
    cout << "Number of wrong guesses: " << badGuessCount;
}
void runGame(string guessedWord, string tickWord)
{
    char Word;
    int badGuessCount = 0;
    int count_turns = number_of_times_played;
    int i = 0;
    while (guessedWord != tickWord && count_turns != badGuessCount)
    {
    cout << "Your guess: ";
    cin >> Word;
    if (tickWord.find(Word) != -1)
    {
        update(Word, guessedWord, tickWord);
        for (int j = 0;j < 30; j++)
            cout << endl;
        cout << FIGURE[i];
    }
    else
    {
        badGuessCount++;
        for (int j = 0;j < 30; j++)
            cout << endl;
        cout << FIGURE[i+1];
        i++;
    }
    if (guessedWord == tickWord)
    {
        cout << "You win";
        break;
    }
    if (badGuessCount == count_turns)
    {
        cout << "you lose";
        break;
    }
    renderGame(guessedWord, badGuessCount);
    cout << endl;
    }
}
int main()
{
    string guessedWord, tickWord;
    tickWord = chooseWord();
    guessedWord = hideWord(tickWord);
    runGame(guessedWord, tickWord);
    return 0;
}
