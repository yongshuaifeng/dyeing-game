#include<iostream>

#include "G.h"
#include "Table.h"

using namespace std;


void play_one_time()
{
    //初始化骰子
    G g;
    //g.initial();
    //骰子初始状态
    cout<<"The initial state of the cube: "<<endl;
    g.display_cube();
    g.display_plane();

    //初始化地图
    Table table;
    int xy = 0;
    cout<<"Please enter the numer of row(line): ";
    cin>>xy;
    cout<<"Please enter the map: "<<endl;
    table.initial(xy,xy);

    //建立一个路径记录
    vector<vector<int>> path;

    //寻找地图的起点
    int x = -1,y = -1;
    vector<int> vi;
    table.find_beg(x,y);
    vi.push_back(x);
    vi.push_back(y);
    path.push_back(vi);
    
    //计算当前骰子的下节点
    char c = g.get_down();
    table.print(c,x,y);
    

    int direction = 0;
     
    while(true){
        //显示骰子状态
        /*
        cout<<"----------------------"<<endl;
        g.display_cube();
        cout<<"----------------------"<<endl;
        */
       //显示染色过程
       /*
       cout<<"----------------------"<<endl;
       table.display_res();
       cout<<"----------------------"<<endl;
       */
        direction = table.next_step(path);
        switch (direction)
        {
        case 1:
            g.turn_front();
            table.print(g.get_down(),path[path.size()-1][0],path[path.size()-1][1]);
            break;
        case 2:
            g.turn_back();
            table.print(g.get_down(),path[path.size()-1][0],path[path.size()-1][1]);
            break;
        case 3:
            g.turn_left();
            table.print(g.get_down(),path[path.size()-1][0],path[path.size()-1][1]);
            break;
        case 4:
            g.turn_right();
            table.print(g.get_down(),path[path.size()-1][0],path[path.size()-1][1]);
            break;
        default:
            break;
        }
        if(direction == 0) break;

    }

    //显示打印结果
    cout<<"The result is: "<<endl;
    cout<<"--------------------------"<<endl;
    cout<<endl;
    table.display_res();
    cout<<endl;
    cout<<"---------------------------"<<endl;

    return;
}


int main()
{
    int T = 0;
    cout<<"Please enter the times: ";
    cin>>T;
    for(int i =0;i<T;i++)
    play_one_time();
    return 0;
}

