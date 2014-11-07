#include "stdafx.h"
#include "Item.h"

Item::Item()
{
	itemtype = " ";
}


Item::~Item()
{
}

//string Item::setItemType(int type)
//{
//	switch (type)
//	{
//		case 0: itemtype = "sword"; break;
//		case 1: itemtype = "magic potion"; break;
//		case 2: itemtype = "holy grenade"; break;
//
//		case 3: itemtype = "item3"; break;
//		case 4: itemtype = "item4"; break;
//		case 5: itemtype = "item5"; break;
//		case 6: itemtype = "item6"; break;
//		case 7: itemtype = "item7"; break;
//		case 8: itemtype = "item8"; break;
//		case 9: itemtype = "item9"; break;
//
//		case 10: itemtype = "item10"; break;
//		case 11: itemtype = "item11"; break;
//		case 12: itemtype = "item12"; break;
//		case 13: itemtype = "item13"; break;
//		case 14: itemtype = "item14"; break;
//		case 15: itemtype = "item15"; break;
//		case 16: itemtype = "item16"; break;
//		case 17: itemtype = "item17"; break;
//		case 18: itemtype = "item18"; break;
//		case 19: itemtype = "item19"; break;
//
//		case 20: itemtype = "item20"; break;
//		case 21: itemtype = "item21"; break;
//		case 22: itemtype = "item22"; break;
//		case 23: itemtype = "item23"; break;
//		case 24: itemtype = "item24"; break;
//		case 25: itemtype = "item25"; break;
//		case 26: itemtype = "item26"; break;
//		case 27: itemtype = "item27"; break;
//		case 28: itemtype = "item28"; break;
//		case 29: itemtype = "item29"; break;
//
//		case 30: itemtype = "item30"; break;
//		case 31: itemtype = "item31"; break;
//		case 32: itemtype = "item32"; break;
//		case 33: itemtype = "item33"; break;
//		case 34: itemtype = "item34"; break;
//		case 35: itemtype = "item35"; break;
//		case 36: itemtype = "item36"; break;
//		case 37: itemtype = "item37"; break;
//		case 38: itemtype = "item38"; break;
//		case 39: itemtype = "item39"; break;
//
//		case 40: itemtype = "item40"; break;
//		case 41: itemtype = "item41"; break;
//		case 42: itemtype = "item42"; break;
//		case 43: itemtype = "item43"; break;
//		case 44: itemtype = "item44"; break;
//		case 45: itemtype = "item45"; break;
//		case 46: itemtype = "item46"; break;
//		case 47: itemtype = "item47"; break;
//		case 48: itemtype = "item48"; break;
//		case 49: itemtype = "item49"; break;
//
//	default:
//		//nothing at the moment
//		break;
//	}
//	return itemtype;
//}


string Item::setItemType(int type)
{
	switch (type)
	{

	// Power:
	case 0: itemtype = " flaming"; break;
	case 1: itemtype = " magical "; break;
	case 2: itemtype = " holy"; break;
	case 3: itemtype = " poisonous"; break;
	case 4: itemtype = " sharp "; break;
	case 5: itemtype = " glass"; break;
	case 6: itemtype = " green"; break;
	case 7: itemtype = " yellow "; break;
	case 8: itemtype = " red"; break;
	case 9: itemtype = " blue"; break;

	//Item:
	case 10: itemtype = " potion"; break;
	case 11: itemtype = " grenade"; break;
	case 12: itemtype = " sword"; break;
	case 13: itemtype = " watch"; break;
	case 14: itemtype = " bomb"; break;
	case 15: itemtype = " iPad"; break;
	case 16: itemtype = " iPhone"; break;
	case 17: itemtype = " brick"; break;
	case 18: itemtype = " lollipop"; break;
	case 19: itemtype = " pizza"; break;


	case 20: itemtype = "item20"; break;
	case 21: itemtype = "item21"; break;
	case 22: itemtype = "item22"; break;
	case 23: itemtype = "item23"; break;
	case 24: itemtype = "item24"; break;
	case 25: itemtype = "item25"; break;
	case 26: itemtype = "item26"; break;
	case 27: itemtype = "item27"; break;
	case 28: itemtype = "item28"; break;
	case 29: itemtype = "item29"; break;
		
	case 30: itemtype = "item30"; break;
	case 31: itemtype = "item31"; break;
	case 32: itemtype = "item32"; break;
	case 33: itemtype = "item33"; break;
	case 34: itemtype = "item34"; break;
	case 35: itemtype = "item35"; break;
	case 36: itemtype = "item36"; break;
	case 37: itemtype = "item37"; break;
	case 38: itemtype = "item38"; break;
	case 39: itemtype = "item39"; break;
		
	case 40: itemtype = "item40"; break;
	case 41: itemtype = "item41"; break;
	case 42: itemtype = "item42"; break;
	case 43: itemtype = "item43"; break;
	case 44: itemtype = "item44"; break;
	case 45: itemtype = "item45"; break;
	case 46: itemtype = "item46"; break;
	case 47: itemtype = "item47"; break;
	case 48: itemtype = "item48"; break;
	case 49: itemtype = "item49"; break;

	default:
		//nothing at the moment
		break;
	}
	return itemtype;
}


std::string Item::getItemType()
{
	return itemtype;
}
