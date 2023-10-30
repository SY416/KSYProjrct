#include <iostream>
//#include "TStatus.h"
#include "TPlayer.h"
#include "TNPC.h"
#include "TLinkedList.h"


int main()
{
    TStatus a;
    //std::cout << a;
    /*TNPC b;
    TPlayer c;
    c.SetCriDamage(100);
    std::cout << b;
    std::cout << c;*/

    /*TStatus* list[2];
    list[0] = new TNPC;
    list[1] = new TPlayer;
    std::cout << *list[0];
    std::cout << *list[1];
    for (int i = 0; i < 2; i++)
        delete list[i];*/

    TLinkedList<TStatus*> g_StatusList;
    TStatus* list0 = new TStatus;
    g_StatusList.Add(&list0);

    TStatus* list1 = new TPlayer;
    g_StatusList.Add(&list1);
    //list1-> SetEXP(int s);
    int GetEXP();

    list1->SetStr(a.GetStr());
    list1->SetDex(a.GetDex());
    list1->SetInt(a.GetInt());
    list1->SetLuk(a.GetLuk());

    list1->SetHP(a.GetHP());
    list1->SetMP(a.GetMP());

    list1->SetAttack(a.GetAttack());
    list1->SetDefence(a.GetDefence());

    list1->SetCriChance(a.GetCriChance());
    list1->SetCriDamage(a.GetCriDamage());
    std::cout << *list1;
    std::cout << "Hello World!\n";
}
