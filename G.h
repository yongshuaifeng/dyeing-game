#ifndef G_H
#define G_H

#include<iostream>

class G{
    private:
        char up,down,left,right,front,back;
    public:
        G(char a = '1',char b ='6',char c='5',char d='2',char e='4',char f='3'):up(a),down(b),left(c),right(d),front(e),back(f){}
        ~G(){}
        void initial();
        void turn_left();
        void turn_right();
        void turn_front();
        void turn_back();
        char get_up(){return up;}
        char get_down(){return down;}
        char get_left(){return left;}
        char get_right(){return right;}
        char get_front(){return front;}
        char get_back(){return back;}
        void display_plane();
        void display_cube();
};
void G::initial()
{
    std::cout<<"Please enter the six face: "<<std::endl;
    std::cout<<"up: ";
    std::cin>>up;

    std::cout<<"down: ";
    std::cin>>down;

    std::cout<<"left: ";
    std::cin>>left;

    std::cout<<"right: ";
    std::cin>>right;

    std::cout<<"front: ";
    std::cin>>front;

    std::cout<<"back: ";
    std::cin>>back;

    return;
}
void G::turn_left()
{
    char x;
    x = down;
    down = left;
    left = up;
    up = right;
    right = x;
    return;
}

void G::turn_right()
{
    char x;
    x = down;
    down = right;
    right = up;
    up = left;
    left = x;
    return;
}

void G::turn_front()
{
    char x;
    x = down;
    down = front;
    front = up;
    up = back;
    back = x;
    return;
}

void G::turn_back()
{
    char  x;
    x = down;
    down = back;
    back = up;
    up = front;
    front = x;
    return;
}

void G::display_plane()
{
    std::cout<<"-----------------"<<std::endl;
    std::cout<<std::endl;
    std::cout<<" "<<" "<<" "<<" "<<front<<" "<<" "<<" "<<" "<<std::endl;
    std::cout<<" "<<left<<" "<<" "<<down<<" "<<" "<<right<<" "<<std::endl;
    std::cout<<" "<<" "<<" "<<" "<<back<<" "<<" "<<" "<<" "<<std::endl;
    std::cout<<" "<<" "<<" "<<" "<<up<<" "<<" "<<" "<<" "<<std::endl;
    std::cout<<std::endl;
    std::cout<<"-----------------"<<std::endl;
    return;
}

void G::display_cube()
{
    std::cout<<"-----------------"<<std::endl;

    std::cout<<std::endl;
    std::cout<<" "<<" "<<" "<<"*"<<"*"<<"*"<<std::endl;
    std::cout<<" "<<"/"<<" "<<up<<" "<<"/"<<"|"<<std::endl;
    std::cout<<" "<<"*"<<"*"<<"*"<<" "<<right<<"*"<<std::endl;
    std::cout<<"|"<<" "<<back<<" "<<"|"<<"/"<<std::endl;
    std::cout<<" "<<"*"<<"*"<<"*"<<" "<<" "<<" "<<std::endl;
    //std::cout<<" "<<" "<<" "<<"__"<<"__"<<"__"<<" "<<std::endl;
    //std::cout<<" "<<" "<<"/"<<" "<<" "<<" "<<"/"<<std::endl;
    //std::cout<<" "<<" "<<"/"<<up<<" "<<" "<<"/"<<std::endl;
    //std::cout<<" "<<"/"<<up<<"/"<<"|"<<std::endl;
    //std::cout<<"/"<<"——"<<"/"<<right<<"|"<<std::endl;
    std::cout<<std::endl;

    std::cout<<"-----------------"<<std::endl;

    return;
}

#endif// G_H