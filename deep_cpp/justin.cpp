#include <iostream>
#include <string>

int main () {
    std::string user_input; //hold iinput

    std::cout << "did you go to class today?" << std::endl; //user prompt
    std::getline(std::cin, user_input);

    if (user_input != "yes" && user_input != "y") return 0; //quits on non-yes

    //continutes
    std::cout << "what class did you go to?" << std::endl; 

    std::getline(std::cin, user_input);

    std::cout << user_input << " sucks ass, sorry dude" << std::endl;

    return 0; 
}

