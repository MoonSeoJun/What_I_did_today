#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

//--------캐릭터 생성--------
class Character {
protected:
	int attribute;
	int HP;
	int MP;
	int AD;
	int AP;
public:
	Character();
};
	
Character::Character() {
	attribute = 1;
	HP = 0;
	MP = 0;
	AD = 0;
	AP = 0;
}
//----------------------------------

//--------------자캐 생성--------------
class Main_Character : public Character {
private:
	int weapon;
	int skill;
	int ammor;
	int skill_ammor;

public:
	Main_Character();
	void setMain_Character(int h,int m, int ad, int ap, int w, int s, int a, int sa);

};

Main_Character::Main_Character() {
	weapon = 0;
	skill = 0;
	ammor = 0;
	skill_ammor = 0;
}

void Main_Character::setMain_Character(int h,int m, int ad, int ap, int w, int s, int a, int sa) {
	HP = h;
	MP = m;
	AD = ad;
	AP = ap;
	weapon = w;
	skill = s;
	ammor = a;
	skill_ammor = sa;

	cout << "공격력 : " << AD << " +"<< weapon << "\t" << "마력 : " << AP << " +" << skill << "\t" << "마나 : " << MP << endl;
	cout << "무기 : " << weapon << "\t" << "주문 : " << skill << endl;
	cout << "방어력 : " << ammor << "\t" << "주문 저항력 : " << skill_ammor << endl;
}

//---------고블린 몬스터 생성-----------
class Goblin : public Character {
private:
	int type;
public:
	Goblin();
	void setGoblin(int h, int m, int ad, int ap);
};

Goblin::Goblin() {
	type = 0;
}

void Goblin::setGoblin(int h, int m, int ad, int ap) {
	HP = h;
	MP = m;
	AD = ad;
	AP = ap;
	cout << "\n------------------------<적 출현>--------------------\n" << endl;
	cout << "체력     " << HP << "\t" << "마나 : " << MP << "		<<Goblin>>" << endl;
	cout << "공격력   " << AD << "\t" << "마력 : " << AP << endl;
	cout << "유닛 종류 : " << type << "			<<고블린 몬스터>>" << endl;
	cout << "유닛 정보 : " << attribute << endl;
}
//---------오크 몬스터 생성------------
class Ork : public Character {
private:
	int type;
public:
	Ork();
	void setOrk(int h, int m, int ad, int ap);
};

Ork::Ork() {
	type = 0;
}

void Ork::setOrk(int h, int m, int ad, int ap) {
	HP = h;
	MP = m;
	AD = ad;
	AP = ap;
	type = 2;
	cout << "\n------------------------<적 출현>--------------------\n" << endl;
	cout << "체력     " << HP << "\t" << "마나 : " << MP << "		<<Ork>>" << endl;
	cout << "공격력   " << AD << "\t" << "마력 : " << AP << endl;
	cout << "유닛 종류 : " << type << "			<<오크 몬스터>>" << endl;
	cout << "유닛 정보 : " << attribute << endl;
}
//---------용 몬스터 생성-----------
class Dragon : public Character {
private:
	int type;
public:
	Dragon();
	void setDragon(int h, int m, int ad, int ap);
};

Dragon::Dragon() {
	type = 0;
}

void Dragon::setDragon(int h, int m, int ad, int ap) {
	HP = h;
	MP = m;
	AD = ad;
	AP = ap;
	type = 1;
	cout << "\n------------------------<적 출현>--------------------\n" << endl;
	cout << "체력     " << HP << "\t" << "마나 : " << MP << "		<<Dragon>>" << endl;
	cout << "공격력   " << AD << "\t" << "마력 : " << AP << endl;
	cout << "유닛 종류 : " << type << "			<<용 몬스터>>" << endl;
	cout << "유닛 정보 : " << attribute << endl;
}

//------------------------------------

//----------유령 몬스터 생성----------
class Ghost : public Character {
private:
	int type;
public:
	Ghost();
	void setGhost(int h, int m, int ad, int ap);
};

Ghost::Ghost() {
	type = 0;
}

void Ghost::setGhost(int h, int m, int ad, int ap) {
	HP = h;
	MP = m;
	AD = ad;
	AP = ap;
	type = 3;
	cout << "\n------------------------<적 출현>--------------------\n" << endl;
	cout << "체력     " << HP << "\t" << "마나 : " << MP << "		<<Ghost>>" << endl;
	cout << "공격력   " << AD << "\t" << "마력 : " << AP << endl;
	cout << "유닛 종류 : " << type << "			<<유령 몬스터>>" << endl;
	cout << "유닛 정보 : " << attribute << endl;
}

//-----------------------------------------

//-----------------<함수 모음>-----------------

//---------------전투 함수---------------------------
void battle_skill(int* bm, int* sc, int* m_HP, int* m_MP, int *m_AD, int *m_AP, int *m_ammor, int *m_skill_ammor, int HP, int MP, int AD, int AP) {
	int choice;

	srand((unsigned int)time(0));

	int randdom_damage = rand() % 50 + 20;

	AD -= *m_ammor;
	AP -= *m_skill_ammor;

	if (AD <= 0) {
		AD = 1;
	}
	if (AP <= 0) {
		AP = 1;
	}

	while (1) {
		cout << "\n---------<< 상대방 >>----------\n" << endl;
		cout << "|| 체력 : " << HP << "\t마나 : " << MP << "\t||" << endl;
		cout << "|| 공격력 : " << AD << "\t마력 : " << AP << "\t||" << endl;

		cout << "\n---------<< 자신 >>----------\n" << endl;
		cout << "|| 체력 : " << *m_HP << "\t마나 : " << *m_MP << "\t||" << endl;
		cout << "|| 공격력 : " << *m_AD << "\t마력 : " << *m_AP << "\t||" << endl;

		cout << "\n------------------<기술>-----------------\n" << endl;
		cout << "1. 뺨 때리기          (물리)    MP - 0      AD + 0" << endl;
		cout << "2. 딱밤               (물리)    MP - 10     AD + 15" << endl;
		cout << "3. 지건               (마법)    MP - 30     AP + 20" << endl;
		cout << "4. 드릴지건           (마법)    MP - 100    AP + 60"<< endl;
		cout << "5. 대마고 피바라기    (물리)    HP - 150    AD + 25" << endl;
		cout << "\n사용할 기술을 선택하세요 : ";
		cin >> choice;

		Sleep(1000);

		cout << "\n------------------<결과>-----------------\n" << endl;

		switch (choice)
		{
		case 1:
			if (*m_AD > AD) {
				cout << "@ 뺨을 시원하게 떄렸다" << endl;
				cout << *m_AD << " 만큼 피해를 주었다" << endl;
				HP  -= *m_AD - AD;

				Sleep(800);

				if (HP <= 0) {
					HP = 0;
				}
				else if (HP <= 10) {
					cout << "@ 위기에 빠진 상대가 능력치가 극대화됩니다." << endl;
					AP += AP;
					AD += AD;
				}

				cout << "남의 상대 체력 : " << HP << endl;

				Sleep(800);

			}
			else if (*m_AD == AD) {
				cout << "@ 무승부!" << endl;
				cout << "@ 상대의 승부욕이 불타오릅니다!" << endl;

				Sleep(800);

				AD += 5;
				AP += 5;
				cout << "@ 상대의 공격력이 상승하였습니다 : " << AD << endl;
				cout << "@ 상대의 마력이 상승하였습니다 : " << AP << endl;

				Sleep(800);

			}
			else {
				cout << "@ 오히려 내 뺨을 맞았다" << endl;
				cout << AD << " 만큼의 피해를 입었다!" << endl;

				Sleep(800);

				*m_HP -= AD - *m_AD;
				if (*m_HP <= 0) {
					*m_HP = 0;
				}
				cout << "남은 나의 체력 : " << *m_HP << endl;

				Sleep(800);
			}

			*m_AD -= 3;

			if (*m_AD <= 0) {
				*m_AD = 1;
			}
			break;

		case 2:
			*m_AD += 15;
			if (*m_MP < 10) {
				cout << "@ 마나가 부족합니다" << endl;

				Sleep(800);

				*m_AD -= 15;
				break;
			}
			*m_MP -= 10;
			if (*m_AD > AD) {
				cout << "@ 딱밤을 정확하게 떄렸다" << endl;
				cout << *m_AD << " 만큼 피해를 주었다" << endl;

				Sleep(800);

				HP -= *m_AD - AD;
				if (HP <= 0) {
					HP = 0;
				}
				else if (HP <= 10) {
					cout << "@ 위기에 빠진 상대가 능력치가 극대화됩니다." << endl;

					Sleep(800);

					AP += AP;
					AD += AD;
				}
				cout << "남은 상대 체력 : " << HP << endl;

				Sleep(800);


			}
			else if (*m_AD == AD) {
				cout << "@ 무승부!" << endl;
				cout << "@ 상대의 승부욕이 불타오릅니다!" << endl;

				Sleep(800);

				AD += 5;
				AP += 5;
				cout << "@ 상대의 공격력이 상승하였습니다 : " << AD << endl;
				cout << "@ 상대의 마력이 상승하였습니다 : " << AP << endl;

				Sleep(800);

			}
			else {
				cout << "@ 오히려 내가 딱밤을 맞았다" << endl;
				cout << AD << " 만큼의 피해를 입었다!" << endl;

				Sleep(800);

				*m_HP -= AD - *m_AD;
				if (*m_HP <= 0) {
					*m_HP = 0;
				}
				cout << "남은 나의 체력 : " << *m_HP << endl;

				Sleep(800);

			}
			*m_AD -= 17;

			if (*m_AD <= 0) {
				*m_AD = 1;
			}
			break;

		case 3:
			*m_AP += 20;
			if (*m_MP < 30) {
				cout << "@ 마나가 부족합니다" << endl;

				Sleep(800);

				*m_AP -= 20;
				break;
			}
			*m_MP -= 30;
			if (*m_AP > AP) {
				cout << "@ 지건을 명치에 정확하게 맞췄다!" << endl;
				cout << *m_AP << " 만큼 피해를 주었다" << endl;

				Sleep(800);

				HP -= *m_AP - AP;
				if (HP <= 0) {
					HP = 0;
				}
				else if (HP <= 10) {
					cout << "@ 위기에 빠진 상대가 능력치가 극대화됩니다." << endl;

					Sleep(800);

					AP += AP;
					AD += AD;
				}

				cout << "남은 상대 체력 : " << HP << endl;

				Sleep(800);
			}
			else if (*m_AP == AP) {
				cout << "@ 무승부!" << endl;
				cout << "@ 상대의 승부욕이 불타오릅니다!" << endl;

				Sleep(800);

				AD += 5;
				AP += 5;
				cout << "@ 상대의 공격력이 상승하였습니다 : " << AD << endl;
				cout << "@ 상대의 마력이 상승하였습니다 : " << AP << endl;

				Sleep(800);
			}
			else {
				cout << "@ 오히려 내 뺨을 맞았다" << endl;
				cout << AP << " 만큼의 피해를 입었다!" << endl;

				Sleep(800);

				*m_HP -= AP - *m_AP;
				if (*m_HP <= 0) {
					*m_HP = 0;
				}
				cout << "남은 나의 체력 : " << *m_HP << endl;

				Sleep(800);
			}
			*m_AP -= 22;

			if (*m_AP <= 0) {
				*m_AP = 1;
			}
			break;

		case 4:

			*m_AP += 60;
			if (*m_MP < 100) {
				cout << "@ 마나가 부족합니다" << endl;

				Sleep(800);

				*m_AP -= 60;
				break;
			}
			*m_MP -= 100;
			if (*m_AP > AP) {
				cout << "@ 지건을 명치에 정확하게 맞췄다!" << endl;
				cout << m_AP << " 만큼 피해를 주었다" << endl;

				Sleep(800);

				HP -= *m_AP - AP;
				if (HP <= 0) {
					HP = 0;
				}
				else if (HP <= 10) {
					cout << "@ 위기에 빠진 상대가 능력치가 극대화됩니다." << endl;

					Sleep(800);

					AP += AP;
					AD += AD;
				}
				cout << "남은 상대 체력 : " << HP << endl;

				Sleep(800);
			}
			else if (*m_AP == AP) {
				cout << "@ 무승부!" << endl;
				cout << "@ 상대의 승부욕이 불타오릅니다!" << endl;

				Sleep(800);

				AD += 5;
				AP += 5;
				cout << "@ 상대의 공격력이 상승하였습니다 : " << AD << endl;
				cout << "@ 상대의 마력이 상승하였습니다 : " << AP << endl;


				Sleep(800);
			}
			else {
				cout << "@ 오히려 내 뺨을 맞았다" << endl;
				cout << AP << " 만큼의 피해를 입었다!" << endl;

				Sleep(800);

				*m_HP -= AP - *m_AP;
				if (*m_HP <= 0) {
					*m_HP = 0;
				}
				cout << "남은 나의 체력 : " << *m_HP << endl;

				Sleep(800);
			}
			*m_AP -= 63;
			if (*m_AP <= 0) {
				*m_AP = 1;
			}
			break;

		case 5:
			*m_AD += 25;
			if (*m_HP < 100) {
				cout << "@ 체력이 부족합니다" << endl;

				Sleep(800);

				*m_AD -= 25;
				break;
			}
			*m_HP -= 100;
			if (*m_AD > AD) {
				cout << "@ 딱밤을 정확하게 떄렸다" << endl;
				cout << *m_AD << " 만큼 피해를 주었다" << endl;

				Sleep(800);

				HP -= *m_AD - AD;
				if (HP <= 0) {
					HP = 0;
				}
				else if (HP <= 10) {
					cout << "@ 위기에 빠진 상대가 능력치가 극대화됩니다." << endl;

					Sleep(800);

					AP += AP;
					AD += AD;
				}
				cout << "남은 상대 체력 : " << HP << endl;

				Sleep(800);

			}
			else if (*m_AD == AD) {
				cout << "@ 무승부!" << endl;
				cout << "@ 상대의 승부욕이 불타오릅니다!" << endl;

				Sleep(800);

				AD += 5;
				AP += 5;
				cout << "@ 상대의 공격력이 상승하였습니다 : " << AD << endl;
				cout << "@ 상대의 마력이 상승하였습니다 : " << AP << endl;

				Sleep(800);
			}
			else {
				cout << "@ 오히려 내가 딱밤을 맞았다" << endl;
				cout << AD << " 만큼의 피해를 입었다!" << endl;

				Sleep(800);

				*m_HP -= AD - *m_AD;
				if (*m_HP <= 0) {
					*m_HP = 0;
				}
				cout << "남은 나의 체력 : " << *m_HP << endl;

				Sleep(800);
			}
			*m_AD -= 25;

			break;

		default:
			cout << "@ 빗나감!" << endl;
			cout << "@ 상대의 카운터 펀치!" << endl;

			Sleep(800);

			cout << randdom_damage << " 만큼의 피해를 입었다!" << endl;
			*m_HP -= randdom_damage;

			Sleep(800);

			break;
		}
		if (HP <= 0) {
			cout << "\n@ 전투에서 승리하였습니다.\n" << endl;
			cout << "@ 공격력, 마력, 체력, 마력이 상승하였습니다." << endl;

			Sleep(800);

			*m_AD += AD / 2;
			*m_AP += AP / 2;
			*m_HP += 50;
			*m_MP += 25;
			*bm += 150;
			*sc += 200;
			break;
		}
		if (*m_HP <= 0) {
			cout << "\n@ 전투에서 패배하였습니다.\n" << endl;
			cout << "@ 자산과 점수가 감소하였습니다." << endl;

			Sleep(800);

			*bm -= 700;
			*sc -= 500;
			*m_HP += 20;
			break;
		}
	}
}
//----------------bad trap-----------------------
void bad_trap(int* money, int* HP, int* MP, int* AD, int* AP, int* weapon, int* skill, int* ammor, int* skill_ammor) {
	int choice;

	cout << "@ 왠지 모르게 오싹한 기분이 든다...\n" << endl;

	Sleep(800);

	cout << "@ ??? : 1부터 4까지 숫자 중에 하나를 고르게..\n" << endl;

	Sleep(800);

	cout << "@ 선택하심시오.. : ";

	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "@ 어깨에서 피가 세어나오기 시작합니다..\n" << endl;
		cout << "@ 체력이 100 만큼 감소하였습니다.\n" << endl;

		Sleep(800);

		*HP -= 100;
		if (*HP <= 0) {
			cout << "@ ??? : 목숨은 살려주지.." << endl;

			Sleep(800);

			*HP += 50;
		}
			
		break;

	case 2:
		cout << "@ 몸이 파란 연기를 내뿜습니다..\n" << endl;
		cout << "@ 마나가 100 만큼 감소하였습니다..\n" << endl;

		Sleep(800);

		*MP -= 100;
		if (*MP <= 0) {
			*MP = 0;
		}
		break;

	case 3:
		cout << "@ 몸에 힘이 들어가지 않습니다..\n" << endl;
		cout << "@ 공격력이 100 만큼 감소하였습니다..\n" << endl;

		Sleep(800);

		*AD -= 100;
		if (*AD <= 0) {
			*AD = 10;
		}
		break;

	case 4:
		cout << "@ 주문이 제대로 발동하지 않습니다..\n" << endl;
		cout << "@ 마력이 100만큼 감소하였습니다..\n" << endl;

		Sleep(800);

		*AP -= 100;
		if(*AP <= 0) {
			*AP = 10;
		}
		break;

	default:
		cout << "@ ??? : 손은 눈보다 빠른 법\n" << endl;
		cout << "@ 가지고 있던 돈 주머니의 일부를 가져갔습니다..\n" << endl;

		Sleep(800);

		*money /= 2;
		break;
	}
}
//----------------gold goost---------------------
void gold_boost(int* money, int* HP, int* MP, int* AD, int* AP, int* weapon, int* skill, int* ammor, int* skill_ammor) {
	int choice;

	cout << "@ 길가에 앉아있는 현자를 발견하였습니다.\n" << endl;

	Sleep(800);

	cout << "@ 현자 : 자네의 잠재력을 끌어내줄테니 500 $ 를 줄수 있겠나?\n" << endl;

	Sleep(800);

	cout << "@ 골드 500 $ 를 지불하여 잠재력을 끌어내겠습니까?\n" << endl;

	Sleep(800);

	cout << "현재 보유 자산 : " << *money << endl;
	cout << "@ 선택하세요(yes (1) or no (2)) : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "@ 현자 : 잘 선택했네" << endl;

		Sleep(800);

		*money -= 500;
		*HP += 100;
		*MP += 100;
		*AD += 10;
		*AP += 10;
		*ammor += 10;
		*skill_ammor += 10;

		cout << "# 모든 능력치가 상승하였습니다." << endl;
		break;

	case 2:
		cout << "@ 현자 : 아쉽구만..." << endl;

		Sleep(800);

		break;

	default:
		cout << "@ 현자가 알아듣지 못하고 떠나갔습니다." << endl;

		Sleep(800);

		break;
	}
}
//----------------패널티----------------------
void chicken_man(int* money, int* score, int* m_HP, int* m_MP, int* m_AD, int* m_AP, int* m_weapon, int* m_skill, int* m_ammor, int* m_skill_ammor) {

	srand((unsigned int)time(0));

	*m_HP -= rand() % 7 + 1;
	*m_MP -= rand() % 7 + 1;
	*m_AD -= rand() % 3 + 1;
	*m_AP -= rand() % 3 + 1;
	*m_ammor -= rand() % 7 + 1;
	*m_skill_ammor -= rand() % 7 + 1;

	if (*m_HP <= 0) {
		*m_HP = 5;
	}
	else if (*m_MP <= 0) {
		*m_MP = 5;
	}
	else if (*m_AD <= 0) {
		*m_AD = 5;
	}
	else if (*m_AP <= 0) {
		*m_AP = 5;
	}
	else if (*m_ammor <= 0) {
		*m_ammor = 5;
	}
	else if (*m_skill_ammor <= 0) {
		*m_skill_ammor = 5;
	}

}

//----------------절반----------------------
void big_chicken_man(int* money, int* m_HP, int* m_MP, int* m_AD, int* m_AP, int* m_ammor, int* m_skill_ammor) {
	*m_HP /= 2;
	*m_MP /= 2;
	*m_AD /= 2;
	*m_AP /= 2;
	*m_ammor /= 2;
	*m_skill_ammor /= 2;
}

void sweet_fruit(int* m_HP) {
	int choice;
	int fruit;

	srand((unsigned int)time(0));

	fruit = rand() % 50 + 1;

	cout << "@ 열매를 먹겠습니까? yes (1) or no (2) : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "@ 열매를 먹고 체력을 회복하였습니다." << endl;

		Sleep(800);

		*m_HP += 100;
		break;

	case 2:
		cout << "@ 열매를 먹지않고 지나갔습니다." << endl;

		Sleep(800);

		break;

	default:
		cout << "@ 잘못보고 옆에 있는 열매를 먹었습니다." << endl;

		Sleep(800);

		cout << "@ 상한 열매를 먹고 배가 아파옵니다." << endl;

		Sleep(800);

		cout << "@ 체력이 " << fruit << " 만큼 줄었습니다." << endl;
		*m_HP -= fruit;
		break;
	}
}

//----------------선택지----------------------
void chose(int* money, int *score, int* m_HP, int* m_MP, int *m_AD, int *m_AP,int *m_weapon, int *m_skill, int *m_ammor, int *m_skill_ammor, int HP, int MP, int AD, int AP) {
	int choice;
	int trap;

	srand((unsigned int)time(0));

	while (1) {
		cout << "선택하세요 : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			battle_skill(money, score, m_HP, m_MP, m_AD, m_AP, m_ammor, m_skill_ammor, HP, MP, AD, AP);
			break;

		case 2:

			trap = rand() % 15 + 1;

			cout << "\n------------------<결과>-----------------\n" << endl;

			cout << "<< 겁쟁이 패널티가 발생합니다. >>" << endl;

			cout << "\n@ 모든 능력치가 무작위로 감소합니다\n" << endl;

			Sleep(800);

			chicken_man(money, score, m_HP, m_MP, m_AD, m_AP, m_weapon, m_skill_ammor, m_ammor, m_skill_ammor);

			if (trap == 2 || trap == 4 || trap == 8) {
				cout << "<< 함정 발동 >>" << endl;
				cout << "@ 100 $ 를 잃었습니다" << endl;

				Sleep(800);

				*score -= 100;
				*money -= 100;
			}
			else if (trap == 7) {
				cout << "<< 심봤다! >>" << endl;
				cout << "@ 200 $ 를 획득했습니다." << endl;

				Sleep(800);

				*score += 100;
				*money += 200;
			}
			else if (trap == 0 || trap == 1) {
				cout << "@ 흥미로운 인물을 발견했습니다\n" << endl;
				gold_boost(money, m_HP, m_MP, m_AD, m_AP, m_weapon, m_skill, m_ammor, m_skill_ammor);
				*score += 100;
			}
			else if (trap == 6) {
				cout << "@ 불길한 기운이 주변을 감쌉니다\n" << endl;
				bad_trap(money, m_HP, m_MP, m_AD, m_AP, m_weapon, m_skill, m_ammor, m_skill_ammor);
			}
			else if (trap == 3 || trap == 9) {
				cout << "@ 땅에 박힌 돌에 걸려 넘어졌다!\n" << endl;

				Sleep(800);

				cout << "@ 체력이 50 만큼 감소합니다\n" << endl;
				*m_HP -= 50;
				if (*m_HP <= 0) {
					*m_HP = 10;
				}
			}
			else if (trap == 11) {
				cout << "@ 절반의 길에 들어섰습니다\n" << endl;
				cout << "@ 모든 능력치가 절반이 됩니다\n" << endl;

				Sleep(800);

				big_chicken_man(money, m_HP, m_MP, m_AD, m_AP,m_ammor, m_skill_ammor);
			}
			else if (trap == 13) {
				cout << "@ 맛있어 보이는 열매가 보입니다.\n" << endl;
				sweet_fruit(m_HP);

			}
			else {
				cout << "@ 흥미로운 것을 찾지 못했습니다.\n" << endl;
				*score -= 100;
			}
			break;

		default:
			cout << "@ 다시 입력해주세요" << endl;
			break;
		}
		if (choice == 1 || choice == 2) break;
	}
}
//----------------random ablilty-----------------
void random_ablilty_easy_monster(int* h, int* m, int* ad, int* ap) {

	srand((unsigned int)time(0));

	*h = rand() % ((100 - 10 + 1) + 10);
	*m = rand() % ((50 - 5 + 1) + 5);
	*ad = rand() % ((25 - 3 + 1) + 3);
	*ap = rand() % ((25 - 3 + 1) + 3);

}
void random_ablilty_common_monster(int *h, int *m, int *ad, int *ap) {

	srand((unsigned int)time(0));

	*h = rand() % ((300 - 75 + 1) + 75);
	*m = rand() % ((150 - 50 + 1) + 50);
	*ad = rand() % ((100 - 50 + 1) + 50);
	*ap = rand() % ((100 - 50 + 1) + 50);

}

void random_ablilty_boss_monster(int* h, int* m, int* ad, int* ap) {

	srand((unsigned int)time(0));

	*h = rand() % ((3500 - 1500 + 1) + 1500);
	*m = rand() % ((5000 - 1800 + 1) + 1800);
	*ad = rand() % ((3000 - 1500 + 1) + 1500);
	*ap = rand() % ((4000 - 2000 + 1) + 2000);

}

void random_ablilty_nomal_monster(int* h, int* m, int* ad, int* ap) {

	srand((unsigned int)time(0));

	*h = rand() % ((1250 - 300 + 1) + 300);
	*m = rand() % ((800 - 200 + 1) + 200);
	*ad = rand() % ((650 - 300 + 1) + 300);
	*ap = rand() % ((650 - 200 + 1) + 200);

}


//--------------battle motion---------------------
void battle(int dice_result, int* money, int* score, int* m_HP, int* m_MP, int* m_AD, int* m_AP, int* m_weapon, int* m_skill, int *m_ammor, int *m_skill_ammor) {
	int HP, MP, AD, AP;

	if (dice_result % 2 == 0) {
		random_ablilty_common_monster(&HP, &MP, &AD, &AP);

		cout << "\n<< 일반 몬스터 출현 >>\n" << endl;

		Sleep(800);

		Ghost ghost1;
		ghost1.setGhost(HP, MP, AD, AP);

		Sleep(800);

		cout << "\n------------<< 자신 >>-------------\n" << endl;
		cout << "|| 체력 : " << *m_HP << "\t마나 : " << *m_MP << " ||" << endl;
		cout << "|| 공격력 : " << *m_AD << "\t마력 : " << *m_AP << " ||" << endl;

		Sleep(800);

		cout << "\n-------------------<적과 대치>-----------------\n" << endl;
		cout << "1. 전투" << endl;
		cout << "2. 다른 길을 찾아보자" << endl;

		chose(money, score, m_HP, m_MP, m_AD, m_AP, m_weapon, m_skill,m_ammor, m_skill_ammor, HP, MP, AD, AP);

		Sleep(800);

		cout << "\n현재 보유 자산 " << *money << " $" << endl;
		cout << "현재 점수 : " << *score << endl;
	}
	else if(dice_result % 7 == 0){
		random_ablilty_boss_monster(&HP, &MP, &AD, &AP);

		cout << "\n<< 보스 출현 >>\n" << endl;

		Sleep(800);

		Dragon dragon1;
		dragon1.setDragon(HP, MP, AD, AP);

		Sleep(800);

		cout << "\n------------<< 자신 >>-------------\n" << endl;
		cout << "|| 체력 : " << *m_HP << "\t마나 : " << *m_MP << " ||" << endl;
		cout << "|| 공격력 : " << *m_AD << "\t마력 : " << *m_AP << " ||" << endl;

		Sleep(800);

		cout << "\n------------------<적과 대치>-----------------\n" << endl;
		cout << "1. 전투" << endl;
		cout << "2. 다른 길을 찾아보자" << endl;

		chose(money, score, m_HP, m_MP, m_AD, m_AP, m_weapon, m_skill, m_ammor, m_skill_ammor, HP, MP, AD, AP);

		Sleep(800);

		cout << "\n현재 보유 자산 " << *money << " $" << endl;
		cout << "현재 점수 : " << *score << endl;
	}
	else if (dice_result % 5 == 0) {
		random_ablilty_nomal_monster(&HP, &MP, &AD, &AP);

		cout << "\n<< 중간 보스 출현 >>\n" << endl;

		Sleep(800);

		Ork ork;
		ork.setOrk(HP, MP, AD, AP);

		Sleep(800);

		cout << "\n------------<< 자신 >>-------------\n" << endl;
		cout << "|| 체력 : " << *m_HP << "\t마나 : " << *m_MP << " ||" << endl;
		cout << "|| 공격력 : " << *m_AD << "\t마력 : " << *m_AP << " ||" << endl;

		Sleep(800);

		cout << "\n-------------------<적과 대치>-----------------\n" << endl;
		cout << "1. 전투" << endl;
		cout << "2. 다른 길을 찾아보자" << endl;

		chose(money, score, m_HP, m_MP, m_AD, m_AP, m_weapon, m_skill, m_ammor, m_skill_ammor, HP, MP, AD, AP);

		Sleep(800);

		cout << "\n현재 보유 자산 " << *money << " $" << endl;
		cout << "현재 점수 : " << *score << endl;
	}
	else {
		random_ablilty_easy_monster(&HP, &MP, &AD, &AP);

		cout << "\n<< 초보 출현 >>\n" << endl;

		Sleep(800);

		Goblin goblin;
		goblin.setGoblin(HP, MP, AD, AP);

		Sleep(800);

		cout << "\n------------<< 자신 >>-------------\n" << endl;
		cout << "|| 체력 : " << *m_HP << "\t마나 : " << *m_MP << " ||" << endl;
		cout << "|| 공격력 : " << *m_AD << "\t마력 : " << *m_AP << " ||" << endl;

		Sleep(800);

		cout << "\n-------------------<적과 대치>-----------------\n" << endl;
		cout << "1. 전투" << endl;
		cout << "2. 다른 길을 찾아보자" << endl;

		chose(money, score, m_HP, m_MP, m_AD, m_AP, m_weapon, m_skill, m_ammor, m_skill_ammor, HP, MP, AD, AP);

		Sleep(800);

		cout << "\n현재 보유 자산 " << *money << " $" << endl;
		cout << "현재 점수 : " << *score << endl;
	}
}

//-----------------------------------------

//--------------캐릭터 만들기--------------
void character_making(int *HP, int *MP, int *AD, int *AP, int *weapon, int *skill, int *ammor, int *skill_ammor) {

	srand((unsigned int)time(0));

	cout << "\n-----------<< 캐릭터의 능력치를 설정합니다 >>-----------\n" << endl;

	*HP = rand() % ((200 - 50 - 1) - 50);

	*MP = rand() % ((200 - 75 - 1) - 75);

	*AD = rand() % ((100 - 25 - 1) - 25);
	
	*AP = rand() % ((100 - 25 - 1) - 25);
	
	*weapon = rand() % 50 + 1;
	
	*skill = rand() % 50 + 1;
	
	*ammor = rand() % 35 + 1;
	
	*skill_ammor = rand() % 35 + 1; 

	Main_Character main_character;
	main_character.setMain_Character(*HP ,*MP, *AD, *AP, *weapon, *skill, *ammor, *skill_ammor);
}
void title() {
	cout << "\n========================================================================================================" << endl;
	cout << "||   #########   ########  #          #####               ######       #       #   ######    #    #   ||" << endl;
	cout << "||   #           #      #  #          #     #             #      #     #       #   #         #    #   ||" << endl;
	cout << "||   #           #      #  #          #      #            #      #     #       #   #         #    #   ||" << endl;
	cout << "||   #    #####  #      #  #          #      #            ######       #       #    #####    ######   ||" << endl;
	cout << "||   #       #   #      #  #          #     #             #     #      #       #         #   #    #   ||" << endl;
	cout << "||   #       #   #      #  #          #    #              #       #    #       #         #   #    #   ||" << endl;
	cout << "||   #########   ########  ########   #####               #        #    ######     ######    #    #   ||" << endl;
	cout << "========================================================================================================" << endl;

	Sleep(1000);

}
//----------------main menu----------------------
void main_menu() {
	cout << "\n--------------------<게임 방법>--------------------\n" << endl;
	cout << "@ 주사위를 굴려 여러 이벤트가 발생합니다" << endl;
	cout << "@ 몬스터를 처치하거나 특정 이벤트를 달성하면 점수가 상승하고 돈을 획득합니다" << endl;
	cout << "@ 특정 이벤트가 발생하거나 전투에서 패배하면 점수가 감소합니다" << endl;
	cout << "@ 기본 자산은 1000$입니다." << endl;
	cout << "@ 자산이 0 $ 이하로 내려가면 게임 종료" << endl;

	Sleep(3500);
}

void play_way() {
	cout << "\n--------------------<전투 방법>--------------------\n" << endl;
	cout << "@ 전투 시 공격력 또는 마력이 높은 캐릭터가 데미지를 입힙니다." << endl;
	cout << "@ 방어력과 주문 저항력은 상대방의 공격력 또는 마력을 줄입니다." << endl;
	cout << "@ 공격을 할 때마다 공격력 또는 마력이 감소합니다" << endl;
	cout << "@ 무기와 주문은 공격력 또는 마력을 상승시킵니다." << endl;
	cout << "@ 체력이 전부 닳게 되면 전투에서 패배합니다." << endl;
	cout << "@ 패배 시 점수와 자산을 잃고 체력 10을 보충해줍니다." << endl;

	Sleep(3500);
}

void game_over(int* score) {
	cout << "\n-------------GAME OVER--------------\n" << endl;
	cout << "<< GAME OVER >>" << endl;
	cout << "\n<< FINAL SCORE >>\n" << endl;
	cout << "FINAL SCORE : " << *score << endl;
}

//---------------메인 메뉴-----------------
int main() {
	int dice;
	int dice_result;
	int money(1000);
	int score(500);
	int m_HP, m_MP, m_AD, m_AP, m_weapon, m_skill, m_ammor, m_skill_ammor;
	

	srand((unsigned int)time(0));

	title();

	main_menu();

	play_way();

	character_making(&m_HP, &m_MP, &m_AD, &m_AP, &m_weapon, &m_skill, &m_ammor, &m_skill_ammor);

	m_AD += m_weapon;
	m_AP += m_skill;

	while (1) {
		//-----------GAME OVER-----------
		if (money <= 0) break;
		//-------------------------------

		cout << "\n----------------<주사위 던지기>---------------\n" << endl;
		cout << "몇 개의 주사위를 던질지 선택하세요  < !경고! > 0을 입력하면 종료됩니다" << endl;

		Sleep(800);

		cout << "주사위의 합이 높을 수록 강한 적이 등장합니다." << endl;
		cin >> dice;

		//--------게임 종료------------
		if (dice == 0) break;
		//------------------------------

		dice_result = rand() % (((6 * dice) - (1 * dice) + 1) - (1 * dice));

		cout << "주사위 값 : " << dice_result << endl;

		battle(dice_result,&money, &score, &m_HP, &m_MP, &m_AD, &m_AP, &m_weapon, &m_skill, &m_ammor, &m_skill_ammor);
	}

	game_over(&score);

	return 0;
}
