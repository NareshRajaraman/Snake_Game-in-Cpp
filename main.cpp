#include <iostream>
#include<vector>
#include <windows.h>
#include <Snake.h>
#include<conio.h>
#include<food.h>
#include<SFML/Graphics.hpp>
using namespace std;
#define WIDTH 50
#define HEIGHT 30

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
Snake snake({WIDTH/2,HEIGHT/2});
Food food;
//int x=5,y=20;
void board()
{
    vector<COORD> snakeBody=snake.getSnakeBody();
    for(int i=0;i<=HEIGHT;i++)
 {
     cout<<"\t\t";
    // COORD snake_pos=snake.getpos();
    for(int j=0;j<=WIDTH;j++)
    {
        if(i==0 || i==HEIGHT||j==0||j==WIDTH)
        {
            cout<<"#";
        }
        else if(i==food.getFoodPos().Y && j==food.getFoodPos().X)
        {
            cout<<"*";
        }
        else
        {
            bool snakePos=false;
            for(int k=0;k< snakeBody.size();k++)
            {
             if(i==snakeBody[k].Y && j==snakeBody[k].X)
             {
                 cout<<"o";
                 snakePos=true;
                 break;
             }
            }
            if(!snakePos)
            {
                 cout<<" ";
            }
        }
    }

    cout<<endl;
 }
}


 int main()
 {
     while(true)
     {
         Sleep(150);
         board();
         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
         if(kbhit())
         {
             switch(getch())
             {
             case UP_KEY: snake.setDir('u');break;
             case DOWN_KEY:snake.setDir('d');break;
             case LEFT_KEY:snake.setDir('r');break;
             case RIGHT_KEY:snake.setDir('l');break;
             }

         }
         snake.moveSnake();
         if(snake.collided())
         {
             cout<<"GAME_OVER !!!";
         }
         if(snake.eaten(food))
         {
             snake.grow();
             food.genFood();
         }
     }
 }


