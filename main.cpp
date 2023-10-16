#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    //
    // Your code goes here
    //
     // Map Scenario 1: Search based on UserName
    // Create a new std::map
    map<string, TwitterData> userNameMap;

    // Insert all Twitter data into the std::map.
    for (int i = 0; i < 5; ++i)
    {
        userNameMap[twitter_data[i].getUserName()] = twitter_data[i];
    }

    // Iterate through the std::map and print the key-value pairs line by line
    for (const auto& entry : userNameMap)
    {
        cout << entry.first << ": " << entry.second.print() << endl;
    }

    // Find the person whose username is savage1 and print out the entire record
    auto it = userNameMap.find("savage1");
    if (it != userNameMap.end())
    {
        cout << "Found savage1: " << it->second.print() << endl;
    }

    //Remove this person from the map
    userNameMap.erase("savage1");

    // Map Scenario 2: Search based on EmailAddress
    // Create a new std::map
    map<string, TwitterData> emailMap;

    // Insert all Twitter data into the std::map.
    for (int i = 0; i < 5; ++i)
    {
        emailMap[twitter_data[i].getEmail()] = twitter_data[i];
    }

    //Iterate through the std::map and print the key-value pairs line by line
    for (const auto& entry : emailMap)
    {
        cout << entry.first << ": " << entry.second.print() << endl;
    }

    //Find the person whose email is kat@gmail.com and print out the entire record
    it = emailMap.find("kat@gmail.com");
    if (it != emailMap.end())
    {
        cout << "Found kat@gmail.com: " << it->second.print() << endl;
    }

    //Remove this person from the map
    emailMap.erase("kat@gmail.com");

    return 0;
}