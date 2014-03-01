#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Game_Object.h"
#include "Person.h"
#include "View.h"
#include "Model.h"


using namespace std;

void do_move_command(Model *, int, double, double ,View *view);
void do_work_command(Model *, int ID1, int ID2, int ID3 ,View *view);
void do_stop_command(Model *, int sID ,View *view );
void do_go_command(Model *,View *view);
void do_run_command(Model *model, View *view);
void do_list_command(Model *model, View *view);
void do_attack_command(Model *model, View *view, int ID1, int ID2);


#endif
