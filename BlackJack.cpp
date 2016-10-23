#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0 );
    
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

enum CardRank
{
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_ACE,
  MAX_RANK
};

enum CardSuit
{
    SUIT_SPADE,
    SUIT_CLUB,
    SUIT_DIAMONDS,
    SUIT_HART,
    MAX_SUIT
};

struct Card
{
    CardRank rank;
    CardSuit suit;
};

void printCard(const Card &card)
{
    switch(card.rank)
    {
        case RANK_2:     std::cout<<"2"; break;
        case RANK_3:     std::cout<<"3"; break;
        case RANK_4:     std::cout<<"4"; break;
        case RANK_5:     std::cout<<"5"; break;
        case RANK_6:     std::cout<<"6"; break;
        case RANK_7:     std::cout<<"7"; break;
        case RANK_8:     std::cout<<"8"; break;
        case RANK_9:     std::cout<<"9"; break;
        case RANK_10:    std::cout<<"10"; break;
        case RANK_JACK:  std::cout<<"J"; break;
        case RANK_QUEEN: std::cout<<"Q"; break;
        case RANK_KING:  std::cout<<"K"; break;
        case RANK_ACE:   std::cout<<"A"; break;
    };
    
    switch(card.suit)
    {
      case SUIT_CLUB:     std::cout<<"C"; break; 
      case SUIT_DIAMONDS: std::cout<<"D"; break;
      case SUIT_SPADE:    std::cout<<"S"; break;
      case SUIT_HART:     std::cout<<"H"; break;
    };
}

void printDeck(const std::array<Card, 52> &deck)
{
    //int step = 0; 
    
    for(const auto &card : deck)
    {
        printCard(card);
        std::cout<<" ";
        //++step;
        //std::cout<<'\n'<<"Step: "<<step<<'\n';
    };
    
    //std::cout<<"End of the line"<<'\n';
}

void swapCard(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}

void shuffleDeck(std::array<Card, 52> &deck)
{
    for (int index = 0; index < 52; ++index)
    {
      int swapIndex = getRandomNumber(0,51);
      swapCard(deck[index], deck[swapIndex]);
    };
}

int getCardValue(const Card &card)
{
    switch(card.rank)
    {
        case RANK_2:     return 2;
        case RANK_3:     return 3;
        case RANK_4:     return 4;
        case RANK_5:     return 5;
        case RANK_6:     return 6;
        case RANK_7:     return 7;
        case RANK_8:     return 8;
        case RANK_9:     return 9;
        case RANK_10:    return 10;
        case RANK_JACK:  return 10;
        case RANK_QUEEN: return 10;
        case RANK_KING:  return 10;
        case RANK_ACE:   return 11;
        
    };
}

char playerChoice()
{
    std::cout<<"Enter (h) to recive a card or (s) to stay: ";
    char choice;
    std::cin>>choice;
    
    return choice;
}

bool playBlackJack(const std::array<Card, 52> &deck)
{
    const Card *cardPtr = &deck[0];
    
    int playerScore = 0;
    int dealerScore = 0;
    
    dealerScore = dealerScore + getCardValue(*cardPtr++);
    
    std::cout<<"The dealer is showing: "<<dealerScore<<'\n';
    
    playerScore = playerScore + getCardValue(*cardPtr++);
    playerScore = playerScore + getCardValue(*cardPtr++);
    
    bool play = true;
    
    while (play == true)
    {
        std::cout<<"You have: "<<playerScore<<'\n';
        
        if (playerScore > 21)
        {
            std::cout<<"You are bust"<<'\n';
            return false;
        };
        
         if (playerScore == 21)
        {
            return true;
        };
        
        char choice = playerChoice();
        
        if (choice == 's')
        {
            break;
        };
        
         std::cout<<'\n';
        
        playerScore = playerScore + getCardValue(*cardPtr++);
    };
   
   while (dealerScore < 18)
   {
       dealerScore = dealerScore + getCardValue(*cardPtr++);
   };
   
   if (dealerScore > 21)
   {
     std::cout<<"The dealer has: "<<dealerScore<<", as such they are bust"<<'\n'; 
     return true;
    };
  
  std::cout<<"The dealer has: "<<dealerScore<<'\n'; 
  
  return (playerScore > dealerScore);
    
};

int main()
{
    srand(static_cast<int>(time(0)));
    
    std::array<Card, 52> deck;
    
    int card = 0;
    
    for(int suit = 0; suit < MAX_SUIT; ++suit)
    for(int rank = 0; rank < MAX_RANK; ++rank)
    {    
        deck[card].suit = static_cast<CardSuit>(suit);
        deck[card].rank = static_cast<CardRank>(rank);
        ++card;
        //std::cout<<'\n'<<"Step: "<<card<<'\n';
    }
    
    printDeck(deck);
    
    shuffleDeck(deck);
    
    std::cout<<'\n';
    
    printDeck(deck);
    
    std::cout<<'\n';
    
    bool play = true;
    
    while (play == true)
    {
        std::cout<<"Do you want to play a game of Black Jack, enter (y) to play or (n) to exit: ";
        char choice;
        std::cin>>choice;
        
        if (choice == 'y')
        {
            shuffleDeck(deck);
            
            if ( playBlackJack(deck) == true)
            {
                std::cout<<"You Win!"<<'\n';
            }
            else
            {
                std::cout <<"You Lose :("<<'\n';
            }
        }
        else 
        {
            play = false;
        };
    };
    
    return 0;
}