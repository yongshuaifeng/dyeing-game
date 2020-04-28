#ifndef TABLE_H
#define TABLE_H

#include<iostream>
#include<vector>


//using namespace std;
class Table{
private:
    std::vector<std::vector<char>> tab,res;
public:
    Table(){}
    ~Table(){}
    void initial(int x,int y);
    void find_beg(int& x,int& y);
    int next_step(std::vector<std::vector<int>>& path);
    bool find_path(const std::vector<std::vector<int>>& path,int x,int y);
    void print(char num,int x,int y){res[x][y] = num;return;}
    void display_res();
    void display_tab();

};
void Table::initial(int x,int y)
{
    for(int i =0;i<x;i++){
        std::vector<char> vi;
        //std::cout<<"input line: ";
        for(int j =0;j<y;j++){
            char c;
            std::cin>>c;
            vi.push_back(c);
        }
        tab.push_back(vi);
    }

    for(int i =0;i<x;i++){
        std::vector<char> vi;
        for(int j =0;j<y;j++)
            vi.push_back('.');
        res.push_back(vi);
    }
    return;
}

void Table::find_beg(int& x,int& y)
{
    for(int i =0;i<tab.size();i++)
        for(int j =0;j<tab[0].size();j++)
         if(tab[i][j] == 'S'){
             x = i; y = j;
         }
    return;
}

int Table::next_step(std::vector<std::vector<int>>& path)
{
    int pos  = 0; 
    int x = path[path.size()-1][0];
    int y = path[path.size()-1][1];
    if((x-1)>=0 && (tab[x-1][y] == '#' || tab[x-1][y] == 'E') && !find_path(path,x-1,y) ){//front
        std::vector<int> xy;
        xy.push_back(x-1);
        xy.push_back(y);
        path.push_back(xy);
        pos  = 1;
    }else if((x+1)<tab.size() && (tab[x+1][y] == '#' || tab[x+1][y] == 'E') && !find_path(path,x+1,y)){//back
        std::vector<int> xy;
        xy.push_back(x+1);
        xy.push_back(y);
        path.push_back(xy);
        pos  = 2;
    }else if((y-1)>=0 && (tab[x][y-1] == '#' || tab[x][y-1] == 'E') && !find_path(path,x,y-1)){//left
        std::vector<int> xy;
        xy.push_back(x);
        xy.push_back(y-1);
        path.push_back(xy);
        pos  = 3;
    }else if((y+1)<tab[0].size() && (tab[x][y+1] == '#' || tab[x][y+1] == 'E') && !find_path(path,x,y+1)){//right
        std::vector<int> xy;
        xy.push_back(x);
        xy.push_back(y+1);
        path.push_back(xy);
        pos  = 4;
    }
   
    return pos;

}
bool Table::find_path(const std::vector<std::vector<int>>& path,int x,int y)
{
    bool exi =false;
    for(int i =0;i<path.size();i++){
        if(path[i][0] == x && path[i][1] == y)
            exi = true;
    }
    return exi;
}

void Table::display_res(){
    for(int i =0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++)
            std::cout<<res[i][j];
        std::cout<<std::endl;
    }
    return;
}

void Table::display_tab(){
    for(int i =0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++)
            std::cout<<tab[i][j];
        std::cout<<std::endl;
    }
    return;
}

#endif//TABLE_H