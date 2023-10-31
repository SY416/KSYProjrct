#include <iostream>
#include<Vector>
#include "TPlayer.h"
#include "TNPC.h"


int main()
{
    std::vector<TStatus*> Stat_Vector;
    TStatus* list0 = new TStatus;
    Stat_Vector.push_back(list0);
    //---------------------------------------------------------------
    TStatus* list1 = new TNPC;
    list1->SetStr(list0->GetStr());
    list1->SetDex(list0->GetDex());
    list1->SetInt(list0->GetInt());
    list1->SetLuk(list0->GetLuk());

    list1->SetHP(list0->GetHP());
    list1->SetMP(list0->GetMP());

    list1->SetAttack(list0->GetAttack());
    list1->SetDefence(list0->GetDefence());

    list1->SetCriChance(list0->GetCriChance());
    list1->SetCriDamage(list0->GetCriDamage());
    Stat_Vector.push_back(list1);
    //----------------------------------------------------------------
    TStatus* list2 = new TPlayer;
    list2->SetStr(list0->GetStr());
    list2->SetDex(list0->GetDex());
    list2->SetInt(list0->GetInt());
    list2->SetLuk(list0->GetLuk());

    list2->SetHP(list0->GetHP());
    list2->SetMP(list0->GetMP());

    list2->SetAttack(list0->GetAttack());
    list2->SetDefence(list0->GetDefence());

    list2->SetCriChance(list0->GetCriChance());
    list2->SetCriDamage(list0->GetCriDamage());
    Stat_Vector.push_back(list2);

    for (int i = 0; i < Stat_Vector.size(); i++) {
        std::cout << *Stat_Vector[i];
    }
    for (int i = 0; i < Stat_Vector.size(); i++) {
        delete Stat_Vector[i];
    }

    Stat_Vector.clear();
    std::cout << "Hello World!\n";
}

