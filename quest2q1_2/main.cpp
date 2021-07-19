#include <iostream>
#include <vector>

class Person
{
protected:
    std::string name;
    int age;
    std::string gender;
    int weight;
public:
    void setname(std::string name);
    void setage(int new_age);
    void setweight(int new_weight);
};

void Person::setname(std::string new_name)
{
    this->name = new_name;
}
void Person::setage(int new_age)
{
    this->age = new_age;
}
void Person::setweight(int new_weight)
{
    this->weight = new_weight;
}

class Student: public Person
{
    int study_year;
public:
    void set_study_year(int year);
    void inc_study_year();
    void print_student();
};

void Student::set_study_year(int year)
{
    this->study_year = year;
}
void Student::inc_study_year()
{
    this->study_year++;
}
void Student::print_student()
{
    std::cout<<"Name: "<<this->name<<std::endl
            <<"Age: "<<this->age<<std::endl
            <<"Gender: "<<this->gender<<std::endl
            <<"Weight: "<<this->weight<<std::endl
            <<"Year of education: "<<this->study_year<<std::endl;
}

void task1()
{
    std::cout<<"Task 1"<<std::endl;
    Student smas[10];
    int student_count = 0;
    Student a,b;
    a.setname("Nikolay");
    a.setage(18);
    a.setweight(88);
    a.set_study_year(3);
    b.setname("Olga");
    b.setage(19);
    b.setweight(99);
    b.set_study_year(4);
    smas[0] = a;
    student_count++;
    smas[0].print_student();
    smas[1] = b;
    student_count++;
    smas[1].print_student();
    smas[1].inc_study_year();
    smas[1].print_student();
}

class Fruit
{
public:
    std::string name;
    std::string color;
    std::string getColor()
    {
        return this->color;
    }
    std::string getName()
    {
        return this->name;
    }
};
class Apple:public Fruit
{
public:
    Apple(){name = "apple"; color ="green";}
    Apple(std::string col){name = "apple"; color = col;}

};
class Banana:public Fruit
{
public:
    Banana(){name = "banana"; color ="yellow";}
    Banana(std::string col){name = "banana"; color = col;}
};
class GrannySmith:public Apple
{
public:
    GrannySmith(){name = "grannySmith";}
};

void task2()
{
    std::cout<<"Task 2"<<std::endl;
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}
class Card
{
public:
    char name;
    int points;
    Card(char c):name{c},points{0}{};
};

class Player
{
public:
    int current;
    std::vector<Card> hand;
    int count_cards();
    void clear(){hand.clear();current = 0;}
    void get_card();
    void print_cards();
};

void Player::print_cards()
{
    for (int i=0;i<hand.size();i++)
    {
        std::cout<<hand[i].name;
    }
}

void Player::get_card()
{
    char n[12] = {'2','3','4','5','6','7','8','9','J','Q','K','T'};
    char k = n[std::rand()%12];
    Card c(k);
    if(c.name<='9')
        c.points = c.name-'0';
    else
    {
        if (c.name!='T') c.points = 10;
        else
            c.points=11;
    }
    hand.push_back(c);
}

class Human:public Player
{
public:
    std::string name;
    int bet;
    int money;
    Human(std::string new_name){name = new_name;money = 2000;current =0;}
    void make_bet(int n){bet = n;}
    void lose(){money -=bet;bet =0;}
    void win(){money +=bet;bet =0;}
};

int Player::count_cards()
{
    int T=0;
    int sum=0;
    for (int i=0; i<hand.size();i++)
    {
        if (hand[i].name!='T') sum+=hand[i].points;
        else
            T++;
    }
    while(T>0)
    {
        //if (sum+T*1<=21)
        {
            if (sum+11+(T-1)*1>21)
            {
                sum+=T;
                T=0;
            }
            else
            {
                sum+=11;
                T--;
            }
        }
    }
    return sum;
}

void task3()
{

    std::cout<<"Task 3"<<std::endl;
    Human pl("Igor");
    Player dieler;
    while (pl.money>0)
    {
        do
        {
            std::cout<<"Your money "<<pl.money<<". Make bet:";
            std::cin>>pl.bet;
            if (pl.bet>pl.money)
            {
                std::cout<<"Bet is too much"<<std::endl;
            }
        }
        while (pl.bet>pl.money);
        dieler.get_card();
        dieler.get_card();
        std::cout<<"Dieler have:";
        dieler.print_cards();
        std::cout<<std::endl;
        pl.get_card();
        char flag = 1;
        while(flag)
        {
            pl.get_card();
            std::cout<<"Your cards:";
            pl.print_cards();
            pl.current = pl.count_cards();
            std::cout<<" ,total points: "<<pl.current;
            std::cout<<"More card?Y/N"<<std::endl;
            std::cin>>flag;
            if (flag=='N')flag =0;
        }
        if (pl.current>21)
        {
            std::cout<<"Lose"<<std::endl;
            pl.lose();
        }
        else
        {
            if(pl.current>dieler.count_cards())
            {
                std::cout<<"Win"<<std::endl;
                pl.win();
            }
            else {
                std::cout<<"Lose"<<std::endl;
                pl.lose();
            }
        }
        pl.clear();
        pl.bet = 0;
        dieler.clear();
    }
}

int main()
{
    task1();
    task2();
    task3();
    return 0;
}
