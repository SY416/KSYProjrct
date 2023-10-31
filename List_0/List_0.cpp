#include <iostream>
#include<list>
#include "Player.h"
#include "NPC.h"


int main()
{
    std::list<Status*> Stat_list;
    for (int i = 0; i < 3; i++) {
        Status* st = new Status();
        Stat_list.push_back(st);
    }
    
    for (std::list<Status*>::iterator iter = Stat_list.begin(); iter != Stat_list.end(); iter++) {
        Status* value = *iter;
        std::cout << *value;
    }
    for (std::list<Status*>::iterator iter = Stat_list.begin(); iter != Stat_list.end(); iter++) {
        Status* value = *iter;
        delete value;
    }
    Stat_list.clear();
    //---------------------------------------------------------------
    //
    //list1->SetStr(list0->GetStr());
    //list1->SetDex(list0->GetDex());
    //list1->SetInt(list0->GetInt());
    //list1->SetLuk(list0->GetLuk());

    //list1->SetHP(list0->GetHP());
    //list1->SetMP(list0->GetMP());

    //list1->SetAttack(list0->GetAttack());
    //list1->SetDefence(list0->GetDefence());

    //list1->SetCriChance(list0->GetCriChance());
    //list1->SetCriDamage(list0->GetCriDamage());
    ////----------------------------------------------------------------
    //
    //list2->SetStr(list0->GetStr());
    //list2->SetDex(list0->GetDex());
    //list2->SetInt(list0->GetInt());
    //list2->SetLuk(list0->GetLuk());

    //list2->SetHP(list0->GetHP());
    //list2->SetMP(list0->GetMP());

    //list2->SetAttack(list0->GetAttack());
    //list2->SetDefence(list0->GetDefence());

    //list2->SetCriChance(list0->GetCriChance());
    //list2->SetCriDamage(list0->GetCriDamage());
    //Stat_list.push_back(list2);

   
    std::cout << "Hello World!\n";
}