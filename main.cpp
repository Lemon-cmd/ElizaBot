#include "bot.hpp"
#include <iostream>

using namespace bot;

int main()
{
    eliza el = eliza("Lisa");
    add_responses(el);

    string input;

    cout << "Hello. I'm " << el.bot_name() << ". How are you feeling today?" << endl;

    while (getline(cin, input) && (boost::algorithm::to_lower_copy(input) != "quit" || input != "q")) 
    {
        cout << el.respond(input) << "\n";
    }
}