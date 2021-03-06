#include <iostream>
#include <Windows.h>
#include "GameRound.h"
#include "GameAgents.h"
#include "Agent.h"
#include "Game.h"
#include "Mission.h"
#include "AllEnum.h"
#include "Player.h"

#define _CRTDBG_MAP_ALLOC

using namespace std;

int menu_select()
{
	int c;
	cout << endl << "Выберите цифру : " << endl;
	cout << "1. Показать состояние раундов" << endl;
	cout << "2. Предложить команду" << endl;
	cout << "3. Выбрать игрока" << endl;
	cout << "4. Проголосовать за создание" << endl;
	cout << "5. Проголосовать за выполнение" << endl;
	cout << "6. Показать результаты предыдущих голосований" << endl;
	cout << "0. Выйти" << endl;
	do
	{
		cin >> c;
	} while (c < 0 || c > 10);
	return c;
}

void roundState(Game* gm)
{
	cout << endl;
	cout << "Состояние раундов" << endl;
	for (size_t i = 0; i < gm->GetGameRounds().size(); i++)
	{
		GameRound* gr = gm->GetGameRounds()[i];
		cout << "Раунд " << gr->GetRoundNumber() << " активный " << gr->GetIsActiveRound() << " результат " << gr->GetResult() << endl;
	}
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SetConsoleOutputCP(1251);
	Game* gm = new Game();

	//GameAgents ga = GameAgents(gm);
	//Agent* ag2 = ga.GetAgents().at(1);
	//(*ag2).SetStatus(SpyAgentStatus::Spy);
	//Agent* ag3 = ga.GetAgents().at(1);
	//ga.~GameAgents();

#pragma region InitRegion
	char first0[] = "Папа";
	char sec0[] = "Ф";
	char code0[] = "К";
	int rate0 = 100;
	int age0 = 48;
	Player pl0 = Player(first0, sec0, code0, rate0, age0);
	gm->GetGameAgents()->RegistryAgent(pl0);

	char first1[] = "Мама";
	char sec1[] = "Ф";
	char code1[] = "К";
	int rate1 = 100;
	int age1 = 45;
	Player pl1 = Player(first1, sec1, code1, rate1, age1);
	gm->GetGameAgents()->RegistryAgent(pl1);

	char first2[] = "Маша";
	char sec2[] = "Ф";
	char code2[] = "К";
	int rate2 = 100;
	int age2 = 18;
	Player pl2 = Player(first2, sec2, code2, rate2, age2);
	gm->GetGameAgents()->RegistryAgent(pl2);


	char first3[] = "Аня";
	char sec3[] = "Ф";
	char code3[] = "К";
	int rate3 = 100;
	int age3 = 15;
	Player pl3 = Player(first3, sec3, code3, rate3, age3);
	gm->GetGameAgents()->RegistryAgent(pl3);
	if (!gm->CanStartGame())
		cout << "Игроков недостаточно\n";
	else
		cout << "Игроков достаточно\n";

	char first4[] = "Бабушка";
	char sec4[] = "Ф";
	char code4[] = "К";
	int rate4 = 100;
	int age4 = 65;
	Player pl4 = Player(first4, sec4, code4, rate4, age4);
	gm->GetGameAgents()->RegistryAgent(pl4);

#pragma endregion

	if (!gm->CanStartGame())
		cout << "Игроков недостаточно\n";
	else
		cout << "Игроков достаточно\n";

	gm->ExecuteStart();

	int choice;
	while (true)
	{
		choice = menu_select();
		switch (choice)
		{
		case 1:
			roundState(gm);
			break;
		case 2:
			roundState(gm);
			break;
		case 3:
			roundState(gm);
			break;
		case 4:
			roundState(gm);
			break;
		case 5:
			roundState(gm);
			break;
		case 6:
			roundState(gm);
			break;
		case 7:
			roundState(gm);
			break;
		case 8:
			roundState(gm);
			break;
		case 9:
			break;
		}
		if (choice == 0)
			break;
	}

	delete(gm);
	_CrtDumpMemoryLeaks();


}

Player ReadPlayerDataFromConsole()
{
	int rate0;
	int age0;
	char first0[80];
	char sec0[] = "Фамилия";
	char* code0;
	code0 = sec0;

	cout << "Введите имя";
	cin >> first0;
	cout << "Введите фамилию";
	cin.getline(sec0, 80);
	cout << "Введите код";
	cin >> code0;
	//scanf("%s", code0);
	cout << "Введите рейтинг";
	cin >> rate0;
	cout << "Введите возраст";
	cin >> age0;

	Player pl = Player(first0, sec0, code0, rate0, age0);

	return pl;

}