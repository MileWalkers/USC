//
//  main.cpp
//  Lab07
//
//  Created by Tracy on 15/9/22.
//  Copyright © 2015年 Jingwen. All rights reserved.
//

// Gong Jingwen
// ITP 165, Fall 2015
// Lab practical 7
// gongjing@usc.edu

#include "Sound.h"
#include <iostream>


int main()
{
    std::cout<<"Enter the beats per minute: ";
    int beatsPmin;
    std::cin>>beatsPmin;
    initSound();
    setBPM(beatsPmin);
    std::cout<<"Now playing “Mary Had a Little Lamb”"<<std::endl;
  

    addA(1);
    addB(1);
    addHighC(3);
    addB(1);
    addHighC(2);
   
         
	playSound();
    
    return 0;
}
